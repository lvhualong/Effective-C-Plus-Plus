
#pragma once

#include <memory>

#include "actor.h"
#include "room_base.h"

class CampRoom : public Room
{
  public:
    explicit CampRoom(std::shared_ptr<Explorer> explorer) : Room(explorer) {}
    ~CampRoom() {}

  private:
    void EnterEvent(std::shared_ptr<Explorer> explorer) override;
    void FightingEvent(std::shared_ptr<Explorer> explorer) override;
    // void SettleEvent(std::shared_ptr<Explorer> explorer) override;
};

void CampRoom::EnterEvent(std::shared_ptr<Explorer> explorer)
{
    explorer->health = 100;
    explorer->LogHealth();
}
void CampRoom::FightingEvent(std::shared_ptr<Explorer> explorer)
{
    return;
}
