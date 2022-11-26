
#pragma once

#include <memory>

#include "actor.h"

enum RoomType
{
    CAMP_ROOM = 0,
    COMMON_ROOM = 1,
    TRAP_ROOM = 2,
    HEADER_ROOM = 3,
    WEAPON_ROOM = 4,
    TOTAL_NUM,
};

class Room
{
  public:
    explicit Room(std::shared_ptr<Explorer> explorer) : explorer_(explorer) {}
    ~Room() {}
    void SecretRoomExplore()
    {
        room_count_++;
        EnterEvent(explorer_);
        FightingEvent(explorer_);
        SettleEvent(explorer_);
    };
    void ActiveAttack(std::shared_ptr<Explorer> exp, Actor *npc);
    void PassiveAttack(std::shared_ptr<Explorer> exp, Actor *npc);
    void CheckExperience(std::shared_ptr<Explorer> explorer);
    int RoomCount() const { return room_count_; }


  private:
    virtual void EnterEvent(std::shared_ptr<Explorer> explorer){};
    virtual void FightingEvent(std::shared_ptr<Explorer> explorer){};
    void SettleEvent(std::shared_ptr<Explorer> explorer);

  private:
    std::shared_ptr<Explorer> explorer_;
    int room_count_ = 0;
};

void Room::ActiveAttack(std::shared_ptr<Explorer> exp, Actor *npc)
{
    if (!npc->status)
        return;
    std::cout << "探险值攻击NPC, 造成伤害点数:" << exp->attack;
    npc->health -= exp->attack;
    npc->LogHealth();
    if (npc->health <= 0)
    {
        std::cout << "NPC死亡" << std::endl;
        npc->status = false;
    }
}

void Room::PassiveAttack(std::shared_ptr<Explorer> exp, Actor *npc)
{
    if (!exp->status)
        return;
    std::cout << "NPC攻击探险者, 造成伤害点数:" << npc->attack;
    exp->health -= npc->attack;
    exp->LogHealth();
    if (exp->health <= 0)
    {
        std::cout << "探险值死亡" << std::endl;
        exp->status = false;
    }
}

void Room::CheckExperience(std::shared_ptr<Explorer> explorer) {
    if (explorer->experience >= explorer->max_experience) {
        explorer->experience = explorer->experience - explorer->max_experience;
        explorer->health = explorer->max_health;
        std::cout << "经验值满，恢复所有生命值" << std::endl;
    }
}

void Room::SettleEvent(std::shared_ptr<Explorer> explorer)
{
    CheckExperience(explorer);
    explorer->LogExperience();
}