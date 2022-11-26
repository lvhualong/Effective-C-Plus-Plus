
#pragma once

#include <algorithm>
#include <map>
#include <memory>
#include <vector>

#include "actor.h"
#include "room_base.h"

class CommonRoom : public Room
{
  public:
    explicit CommonRoom(std::shared_ptr<Explorer> explorer) : Room(explorer) {}
    ~CommonRoom() {}
    void ActiveAttack(std::shared_ptr<Explorer> exp, Monster *npc);
    void PassiveAttack(std::shared_ptr<Explorer> exp, Monster *npc);

  private:
    void EnterEvent(std::shared_ptr<Explorer> explorer) override;
    void FightingEvent(std::shared_ptr<Explorer> explorer) override;
    void CheckMaxHealth(std::shared_ptr<Explorer> explorer);

  private:
    int continue_recover = 0;
};

void CommonRoom::EnterEvent(std::shared_ptr<Explorer> explorer)
{
    continue_recover++;
    int random = 1 + std::rand() % 99;
    if (random <= 10)
    {
        explorer->health += 10;
        std::cout << "进入房间，恢复10点生命，";
        CheckMaxHealth(explorer);
        explorer->LogHealth();
    }
    if (continue_recover <= 2)
    {
        explorer->health += 5;
        std::cout << "持续恢复5点生命，";
        CheckMaxHealth(explorer);
        explorer->LogHealth();
    }
}

void CommonRoom::FightingEvent(std::shared_ptr<Explorer> explorer)
{
    int monster_count = 1 + std::rand() % 3; // 1~3
    std::map<int, Monster> monsters;
    std::cout << "当前房间怪物数量: " << monster_count << std::endl;
    for (int i = 0; i < monster_count; ++i)
    {
        float monster_param_rate = (std::rand() % 2) ? 1 + 0.4 : 1 - 0.4;
        Monster monster(monster_param_rate);
        std::cout << "怪物: " << i + 1;
        monsters.insert(std::pair<int, Monster>(i + 1, monster));
        monster.LogHealth();
    }
    std::vector<MONSTER_PAIR> monsters_vec(monsters.begin(), monsters.end());
    std::sort(monsters_vec.rbegin(), monsters_vec.rend());
    std::cout << "战斗开始..." << std::endl;

    while (explorer->status && monsters_vec.back().second.status)
    {
        for (auto &monster : monsters_vec)
        {
            if (monster.second.status)
            {
                ActiveAttack(explorer, &(monster.second));
                break;
            }
        }
        for (auto &monster : monsters_vec)
        {
            if (explorer->status && monster.second.status)
                PassiveAttack(explorer, &(monster.second));
        }
    }
}

void CommonRoom::ActiveAttack(std::shared_ptr<Explorer> exp, Monster *npc)
{
    if (!npc->status)
        return;
    int attack = exp->attack + exp->UpdateWeapon();
    std::cout << "探险值攻击NPC, 造成伤害点数:" << attack;
    if (exp->WeaponAttack()>0) std::cout << "  包含武器攻击点数:" << exp->WeaponAttack();
    npc->health -= attack;
    npc->LogHealth();
    if (npc->health <= 0)
    {
        std::cout << "NPC死亡" << std::endl;
        npc->status = false;
        exp->experience += 1;
        std::cout << "获得１点经验, ";
        exp->LogExperience();
        exp->LogHealth();
    }
}

void CommonRoom::PassiveAttack(std::shared_ptr<Explorer> exp, Monster *npc)
{
    if (!exp->status)
        return;
    std::cout << "NPC攻击探险者, 造成伤害点数:" << npc->attack + npc->UpdateWeapon();
    exp->health -= npc->attack + npc->UpdateWeapon();
    std::cout << "   ";
    exp->LogHealth();
    if (exp->health <= 0)
    {
        std::cout << "探险值死亡" << std::endl;
        exp->status = false;
    }
}

void CommonRoom::CheckMaxHealth(std::shared_ptr<Explorer> explorer)
{
    if (explorer->health > explorer->max_health)
    {
        explorer->health = explorer->max_health;
    }
}
