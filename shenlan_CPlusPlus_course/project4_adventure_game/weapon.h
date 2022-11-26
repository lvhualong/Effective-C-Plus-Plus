
#pragma once

#include <iostream>

struct Weapon
{
    Weapon() {}
    Weapon(int a, int b):attack(a),durability(b) {}
    int attack = 0;
    int durability = 0;
    bool active = true;
    int UseWeapon();
};


int Weapon::UseWeapon() {
    if (active == false) {
        return 0;
    }
    // std::cout << "武器攻击力: " << attack << "  磨损值: " << durability << std::endl;
    durability--;
    if (durability <= 0) {
        active = false;
        std::cout << "  当前武器使用后失效" << std::endl;
    }
    return attack;
}

struct WeaponOne : public Weapon
{
    WeaponOne() : Weapon(4, 6){ std::cout << "发现武器1 " << std::endl; }
};

struct WeaponTwo : public Weapon
{
    WeaponTwo() : Weapon(6, 6){ std::cout << "发现武器2 " << std::endl; }
};

struct WeaponThree : public Weapon
{
    WeaponThree() : Weapon(1, 6){ std::cout << "发现武器3 " << std::endl; }
    int UseWeapon();
};

int WeaponThree::UseWeapon() {
    if (active == false) {
        return 0;
    }
    int use_double_attack = std::rand() % 2; // 0~1
    if (use_double_attack)
        attack *= 2;
    std::cout << "武器攻击力: " << attack << "  磨损值: " << durability << std::endl;
    durability--;
    if (durability <= 0) {
        active = false;
        std::cout << "当前武器使用后失效" << std::endl;
    }
    return attack;
}