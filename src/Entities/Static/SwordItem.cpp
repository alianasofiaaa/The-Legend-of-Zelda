#include "SwordItem.h"


void SwordItem::applyEffect(shared_ptr<Link> link){
 // link->getIsSwordCollected();// Set the sword as collected for the link
}
void SwordItem::onCollision(shared_ptr<DynamicEntity> e) {
    shared_ptr<Link> link = dynamic_pointer_cast<Link>(e);
    if (link){
        isCollected = true;
        // Set the item's position to be above link
        this->x = link->getX();
        this->y = link->getY() - link->getHeight();

        // Apply the effect of the item
        applyEffect(link);
                // link->getIsSwordCollected();// Set the sword as collected for the link

        

        // Pick up the item
        link->pickup();

        // Play the sound effect
        handler->getSoundEffectManager()->playSoundEffect("item_get");
    }            
};