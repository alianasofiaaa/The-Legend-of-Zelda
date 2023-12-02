#pragma once

#include "StaticEntity.h"
#include <memory>


class UpRecursiveTile : public StaticEntity {

    public:
        UpRecursiveTile(int x, int y, shared_ptr<Handler> handler) : StaticEntity(x, y, handler) {}
        ~UpRecursiveTile(){};
        void onCollision(shared_ptr<DynamicEntity> e){
            shared_ptr<Entity> link = dynamic_pointer_cast<Entity>(e);
            if(link->getY()<getY()){
                return;
            }
            if(link->getY()>=getY()){
                link->setY(link->getY()-5);
                return onCollision(e);
            }
        }
};