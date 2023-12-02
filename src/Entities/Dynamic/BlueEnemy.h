#pragma once

#include "DynamicEntity.h"
#include <memory>



class BlueEnemy : public DynamicEntity {

    public: 
        BlueEnemy(int x, int y, shared_ptr<Handler> handler, shared_ptr<DynamicEntityAnimations> animations) : DynamicEntity(x, y, handler, animations) {
            this->x=x;
            this->y=y;
            this->MAX_HEALTH = 4;
            this->health = MAX_HEALTH;
        };
        
        //getters for Blue Enemy position
        int getBlueEnemyX(){return x;}
        int getBlueEnemyY(){return y;}

        void update();
        void damage(int damage);
        void onDeath();
        void onCollision(shared_ptr<DynamicEntity> entity){};
};