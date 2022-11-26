
#pragma once

#include <algorithm>
#include <map>
#include <memory>
#include <vector>

#include "actor.h"
#include "room_base.h"

class TrapRoom : public Room
{
  public:
    explicit TrapRoom(std::shared_ptr<Explorer> explorer) : Room(explorer) {}
    ~TrapRoom() {}
    void ActiveAttack(std::shared_ptr<Explorer> exp, Monster *npc);
    void PassiveAttack(std::shared_ptr<Explorer> exp, Monster *npc);

  private:
    void EnterEvent(std::shared_ptr<Explorer> explorer) override;
    void FightingEvent(std::shared_ptr<Explorer> explorer) override;
    bool CheckDeath(std::shared_ptr<Explorer> explorer);

  private:
    int continue_recover = 0;
};

void TrapRoom::EnterEvent(std::shared_ptr<Explorer> explorer)
{
    continue_recover++;
    int loss_health = static_cast<int>(explorer->health * 0.1);
    std::cout << "进入陷阱房间，损失生命值" << loss_health;
    explorer->health -= loss_health;
    explorer->LogHealth();
    if (CheckDeath(explorer)) return;
    if (continue_recover <= 5)
    {
        explorer->health -= 2;
        std::cout << "进入陷阱房间，持续损失2点生命 ";
        explorer->LogHealth();
        if (CheckDeath(explorer)) return;
    }
}

void TrapRoom::FightingEvent(std::shared_ptr<Explorer> explorer)
{
    std::cout << "当前房间大怪物数量1个 ";
    Monster big_monster(2.0);
    big_monster.LogHealth();

    std::cout << "战斗开始..." << std::endl;
    while (explorer->status && big_monster.status)
    {
        ActiveAttack(explorer, &(big_monster));
        if (big_monster.status)
        PassiveAttack(explorer, &(big_monster));
    }
}

void TrapRoom::ActiveAttack(std::shared_ptr<Explorer> exp, Monster *npc)
{
    if (!npc->status)
        return;
    int attack = exp->attack + exp->UpdateWeapon();
    std::cout << "探险值攻击怪物, 造成伤害点数:" << attack;
    if (exp->WeaponAttack()>0) std::cout << "  包含武器攻击点数:" << exp->WeaponAttack();
    npc->health -= attack;
    npc->LogHealth();
    if (npc->health <= 0)
    {
        std::cout << "怪物死亡" << std::endl;
        npc->status = false;
        exp->experience += 1;
        std::cout << "获得１点经验, ";
        exp->LogExperience();
    }
}

void TrapRoom::PassiveAttack(std::shared_ptr<Explorer> exp, Monster *npc)
{
    if (!exp->status)
        return;
    std::cout << "怪物攻击探险者, 造成伤害点数:" << npc->attack;
    exp->health -= npc->attack;
    std::cout << "   ";
    exp->LogHealth();
    if (exp->health <= 0)
    {
        std::cout << "探险值死亡" << std::endl;
        exp->status = false;
    }
}

bool TrapRoom::CheckDeath(std::shared_ptr<Explorer> explorer) {
    return explorer->health <= 0;
}