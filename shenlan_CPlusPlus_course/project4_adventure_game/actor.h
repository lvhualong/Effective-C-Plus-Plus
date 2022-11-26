
#pragma once

#include <utility>
#include <iostream>

#include "weapon.h"

namespace
{
constexpr int kMaxExplorerHealth = 100;
constexpr int kMinExplorerHealth = 0;
constexpr int kMaxExplorerAttack = 10;
constexpr int kMaxExplorerExperience = 10;
constexpr int kMaxMonsterHealth = 10;
constexpr int kMaxMonsterAttack = 5;
constexpr int kMaxMonsterHeaderHealth = 40;
constexpr int kMaxMonsterHeaderAttack = 15;

} // namespace

struct Actor
{
    int health = 0;
    int attack = 0;
    int max_health = 0;
    int max_attack = 0;
    bool status = true;
    Actor(){}
    Actor(int health_t, int attack_t, int max_health_t, int max_attack_t) : health(health_t),
                                                                            attack(attack_t),
                                                                            max_health(max_health_t),
                                                                            max_attack(max_attack_t){}
    void LogHealth() { std::cout << "当前生命值: " << health << "/" << max_health << std::endl; }
    void LogAttack() { std::cout << "当前攻击力: " << attack << "/" << max_attack << std::endl; }
};

struct Explorer : public Actor
{
    Explorer() : Actor(kMaxExplorerHealth, kMaxExplorerAttack, kMaxExplorerHealth, kMaxExplorerAttack),
                 max_experience(kMaxExplorerExperience) {}
    int experience = 0;
    int max_experience = 0;
    void LogHealth() { std::cout << "探索者生命值: " << health << "/" << max_health << std::endl; }
    void LogAttack() { std::cout << "探索者攻击力: " << attack << "/" << max_attack << std::endl; }
    void LogExperience() { std::cout << "探索者经验值: " << experience << "/" << max_experience << std::endl; }
    void AddWeapon(std::shared_ptr<Weapon> weapon)
    {
        weapon_ = weapon;
        std::cout << "探索者装备武器, 攻击力: " << weapon_->attack << "  磨损值: " << weapon_->durability << std::endl;
    }
    int UpdateWeapon() {
        if (weapon_ == nullptr || weapon_->active == false)
            return 0;
        return weapon_->UseWeapon();
    }
    int WeaponAttack()
    {
        if (weapon_ == nullptr || weapon_->active == false)
            return 0;
        return weapon_->attack;
    }

  private:
    std::shared_ptr<Weapon> weapon_;
};

struct Monster : public Actor
{
    Monster(float param_rate = 1.0) : health(static_cast<int>(kMaxMonsterHealth * param_rate)),
                                      attack(static_cast<int>(kMaxMonsterAttack * param_rate)),
                                      max_health(static_cast<int>(kMaxMonsterHealth * param_rate)) {}
    int health = 0;
    int attack = 0;
    int max_health = 0;
    void LogHealth()
    {
        std::cout << "  怪物生命值: " << health << "/" << max_health << std::endl;
    }

    bool operator<(const Monster &monster) const
    {
        return (health < monster.health);
    }
    void AddWeapon(std::shared_ptr<Weapon> weapon)
    {
        weapon_ = weapon;
        std::cout << "怪物装备武器, 攻击力: " << weapon_->attack << "  磨损值: " << weapon_->durability << std::endl;
    }
    int UpdateWeapon()
    {
        if (weapon_ == nullptr)
            return 0;
        return weapon_->UseWeapon();
    }

  private:
    std::shared_ptr<Weapon> weapon_;
};

typedef std::pair<int, Monster> MONSTER_PAIR;
bool operator<(const MONSTER_PAIR &lhs, const MONSTER_PAIR &rhs)
{
    return lhs.second < rhs.second;
}

struct MonsterHead : public Actor
{
    int health = kMaxMonsterHeaderHealth;
    int attack = kMaxMonsterHeaderAttack;
    int max_health = kMaxMonsterHeaderHealth;
    void LogHealth()
    {
        std::cout << "   怪物首领生命值: " << health << "/" << max_health << std::endl;
    }
};
