
#pragma once

#include <memory>

#include "actor.h"
#include "room_base.h"

class WeaponRoom : public Room
{
  public:
    explicit WeaponRoom(std::shared_ptr<Explorer> explorer) : Room(explorer) {}
    ~WeaponRoom() {}

  private:
    void EnterEvent(std::shared_ptr<Explorer> explorer) override;
    void FightingEvent(std::shared_ptr<Explorer> explorer) override;
    void ActiveAttack(std::shared_ptr<Explorer> exp, Monster *npc);
    void PassiveAttack(std::shared_ptr<Explorer> exp, Monster *npc);

  private:
    int enter_health = 0;
    std::shared_ptr<Weapon> weapon;
};

void WeaponRoom::EnterEvent(std::shared_ptr<Explorer> explorer)
{
    enter_health = explorer->health;
    explorer->LogHealth();
}
void WeaponRoom::FightingEvent(std::shared_ptr<Explorer> explorer)
{
    Monster monster(0.4);
    int weapon_type =  (std::rand() % 3);
    if (weapon_type == 0) {
      weapon = std::make_shared<WeaponOne>();
    } else if (weapon_type == 1) {
      weapon = std::make_shared<WeaponTwo>();
    } else {
      weapon = std::make_shared<WeaponThree>();
    }
    monster.AddWeapon(weapon);

    std::cout << "战斗开始..." << std::endl;
    while (explorer->status && monster.status)
    {
        ActiveAttack(explorer, &(monster));
        if (monster.status)
        PassiveAttack(explorer, &(monster));
    }
}

void WeaponRoom::ActiveAttack(std::shared_ptr<Explorer> exp, Monster *npc)
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
        exp->experience += 2;
        std::cout << "获得2点经验, ";
        exp->LogExperience();
        exp->LogHealth();
        exp->AddWeapon(weapon);
    }
}

void WeaponRoom::PassiveAttack(std::shared_ptr<Explorer> exp, Monster *npc)
{
    if (!exp->status)
        return;
    std::cout << "NPC攻击探险者, 造成伤害点数:" << npc->attack + npc->UpdateWeapon();
    exp->health -= npc->attack;
    std::cout << "   ";
    exp->LogHealth();
    if (exp->health <= 0)
    {
        std::cout << "探险值死亡" << std::endl;
        exp->status = false;
    }
}