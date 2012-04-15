#include <iostream>

#include "HealthComponent.h"

HealthComponent::HealthComponent(ObjectId id) : id_(id)
{

}



void HealthComponent::setMaxHealth(int maxHealth)
{
    std::cout << "Setting max health to " << maxHealth << std::endl;
    maxHealth_ = maxHealth;
}



void HealthComponent::setHealth(int health)
{
    std::cout << "Setting health to " << health << std::endl;
    currentHealth_ = health;
}



int HealthComponent::getMaxHealth()
{
    return maxHealth_;
}



int HealthComponent::getHealth()
{
    return currentHealth_;
}


ObjectId HealthComponent::getId()
{
    return id_;
}

