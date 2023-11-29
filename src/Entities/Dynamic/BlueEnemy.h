#pragma once

#include "DynamicEntity.h"
#include "Link.h"
#include <memory>



class BlueEnemy : public DynamicEntity {
    private:
        shared_ptr<Link> link;
        shared_ptr<BlueEnemy> blueenemy;

    public: 
        BlueEnemy(int x, int y, shared_ptr<Handler> handler, shared_ptr<DynamicEntityAnimations> animations) : DynamicEntity(x, y, handler, animations) {
            this->x=x;
            this->y=y;
            this->MAX_HEALTH = 4;
            this->health = MAX_HEALTH;
        };
        
        int getBlueEnemyX(){return x;}
        int getBlueEnemyY(){return y;}
        shared_ptr<Link> getPlayer(){return link;}
        shared_ptr<BlueEnemy> getblueEnemy(){return blueenemy;}
        void update();
        void damage(int damage);
        void onDeath();
        void onCollision(shared_ptr<DynamicEntity> entity){};
};