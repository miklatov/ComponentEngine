#ifndef HEALTHCOMPONENT_H_INCLUDED
#define HEALTHCOMPONENT_H_INCLUDED

#include "TypeDefs.h"
class HealthComponent
{
    public:
        HealthComponent(ObjectId id);
        void setMaxHealth(int maxHealth);
        void setHealth(int health);
        int getMaxHealth();
        int getHealth();

        ObjectId getId();
    private:
        ObjectId id_;
        int maxHealth_;
        int currentHealth_;
};


#endif // HEALTHCOMPONENT_H_INCLUDED
