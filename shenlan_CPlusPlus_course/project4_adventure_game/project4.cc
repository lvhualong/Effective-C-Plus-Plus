
#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>
#include <memory>
#include <chrono>
#include <thread>
#include <unordered_map>
#include <map>



#include "actor.h"
#include "room_base.h"
#include "camp_room.h"
#include "common_room.h"
#include "trap_room.h"
#include "header_room.h"
#include "weapon_room.h"

namespace
{
constexpr int kSrandNumber = 789;

} // namespace

RoomType GenetareRoomWithWeightedRandom()
{
    int random_num = 1 + std::rand() % 100;
    if (random_num <= 10)
    {
        std::cout << "\r\n进入营地-----------" << std::endl;
        return RoomType::CAMP_ROOM;
    }
    else if (random_num <= 65)
    {
        std::cout << "\r\n进入普通房间-----------" << std::endl;
        return RoomType::COMMON_ROOM;
    }
    else if (random_num <= 80)
    {
        std::cout << "\r\n进入陷阱房间-----------" << std::endl;
        return RoomType::TRAP_ROOM;
    }
    else if (random_num <= 90)
    {
        std::cout << "\r\n进入首领房间-----------" << std::endl;
        return RoomType::HEADER_ROOM;
    }
    else
    {
        std::cout << "\r\n进入武器房间-----------" << std::endl;
        return RoomType::WEAPON_ROOM;
    }
}

int main()
{
    std::srand(kSrandNumber);
    auto explorer = std::make_shared<Explorer>();
    auto room = std::make_shared<Room>(explorer);
    auto camp_room = std::make_shared<CampRoom>(explorer);
    auto common_room = std::make_shared<CommonRoom>(explorer);
    auto trap_room = std::make_shared<TrapRoom>(explorer);
    auto header_room = std::make_shared<HeaderRoom>(explorer);
    auto weapon_room = std::make_shared<WeaponRoom>(explorer);
    while (explorer->health > 0)
    {
        RoomType room_type = GenetareRoomWithWeightedRandom();
        switch (room_type)
        {
        case RoomType::CAMP_ROOM:
            room = camp_room;
            break;
        case RoomType::COMMON_ROOM:
            room = common_room;
            break;
        case RoomType::TRAP_ROOM:
            room = trap_room; // trap_room
            break;
        case RoomType::HEADER_ROOM:
            room = header_room; // header_room
            break;
        case RoomType::WEAPON_ROOM:
            room = weapon_room;
            break;
        default:
            break;
        }
        room->SecretRoomExplore();
        // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    std::cout << "进入营地房间次数: " << camp_room->RoomCount() << std::endl;
    std::cout << "进入普通房间次数: " << common_room->RoomCount() << std::endl;
    std::cout << "进入陷阱房间次数: " << trap_room->RoomCount() << std::endl;
    std::cout << "进入首领房间次数: " << header_room->RoomCount() << std::endl;
    std::cout << "进入武器房间次数: " << weapon_room->RoomCount() << std::endl;

    return 0;
}