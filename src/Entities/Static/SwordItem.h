#pragma once
#include "Item.h"

class SwordItem : public Item {

    protected:
        bool isCollected;


    public:
        SwordItem(int x, int y, shared_ptr<Handler> handler,ofImage sprite) : Item(x, y, handler,sprite) {
            this->currentSprite = sprite;
            isCollected = false;
            
        }
        ~SwordItem(){};
        void onCollision(shared_ptr<DynamicEntity> e);
        void applyEffect(shared_ptr<Link> link) = 0;
        bool getIsCollected(){return isCollected;}

};