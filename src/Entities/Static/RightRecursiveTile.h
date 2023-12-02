#pragma once

#include "StaticEntity.h"
#include <memory>


class RightRecursiveTile : public StaticEntity {

    public:
        RightRecursiveTile(int x, int y, shared_ptr<Handler> handler) : StaticEntity(x, y, handler) {}
        ~RightRecursiveTile(){};
        void onCollision(shared_ptr<DynamicEntity> e){
            shared_ptr<Entity> link = dynamic_pointer_cast<Entity>(e);
            if(link->getX()>getX()){
                return;
            }
            if(link->getX()<=getX()){
                link->setX(link->getX()+5);
                return onCollision(e);
            }
        }
};