
#pragma once

#include <algorithm>
#include <map>
#include <memory>
#include <vector>

#include "actor.h"
#include "room_base.h"

class HeaderRoom : public Room
{
  public:
    explicit HeaderRoom(std::shared_ptr<Explorer> explorer) : Room(explorer) {}
    ~HeaderRoom() {}

  private:
    void EnterEvent(std::shared_ptr<Explorer> explorer) override;
    void FightingEvent(std::shared_ptr<Explorer> explorer) override;
    bool CheckDeath(std::shared_ptr<Explorer> explorer);
    void ActiveAttack(std::shared_ptr<Explorer> exp, MonsterHead *npc);
    void PassiveAttack(std::shared_ptr<Explorer> exp, MonsterHead *npc);

private:
    bool regain_health = false;

};

void HeaderRoom::EnterEvent(std::shared_ptr<Explorer> explorer)
{
    int loss_health = static_cast<int>(explorer->health * 0.1);
    std::cout << "进入首领房间，恢复20点生命值";
    explorer->health += 20;
    if (explorer->health > explorer->max_health)
        explorer->health = explorer->max_health;
    explorer->LogHealth();
}

void HeaderRoom::FightingEvent(std::shared_ptr<Explorer> explorer)
{
    std::cout << "当前房间一个怪物首领 ";
    MonsterHead head_monster;
    head_monster.LogHealth();

    std::cout << "战斗开始..." << std::endl;
    while (explorer->status && head_monster.status)
    {
        ActiveAttack(explorer, &(head_monster));
        if (head_monster.status)
        PassiveAttack(explorer, &(head_monster));
    }
}

void HeaderRoom::ActiveAttack(std::shared_ptr<Explorer> exp, MonsterHead *npc)
{
    if (!npc->status)
        return;
    int attack = exp->attack + exp->UpdateWeapon();
    std::cout << "探险值攻击首领, 造成伤害点数:" << attack;
    if (exp->WeaponAttack()>0) std::cout << "  包含武器攻击点数:" << exp->WeaponAttack();
    npc->health -= attack;
    npc->LogHealth();
    if (npc->health <= 0)
    {
        std::cout << "怪物首领死亡" << std::endl;
        npc->status = false;
        exp->experience += 5;
        std::cout << "获得5点经验, ";
        exp->LogExperience();
    }
}

void HeaderRoom::PassiveAttack(std::shared_ptr<Explorer> exp, MonsterHead *npc)
{
    if (!exp->status)
        return;
    if (npc->health <= 10 && !regain_health) {
        std::cout << "怪物首领生命值低, 放弃攻击，回血20点.  ";
        npc->health += 20;
        regain_health = true;
        npc->LogHealth();
        return;
    }
    npc->attack += 1;
    std::cout << "首领攻击探险者, 造成伤害点数:" << npc->attack;
    exp->health -= npc->attack;
    std::cout << "   ";
    exp->LogHealth();
    if (exp->health <= 0)
    {
        std::cout << "探险值死亡" << std::endl;
        exp->status = false;
    }
}

bool HeaderRoom::CheckDeath(std::shared_ptr<Explorer> explorer) {
    return explorer->health <= 0;
}