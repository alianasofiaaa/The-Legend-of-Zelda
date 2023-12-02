#include "BlueEnemy.h"



void BlueEnemy::update(){
    DynamicEntity::update();
}

void BlueEnemy::damage(int damage){
    if (dead) return;
    // Play the damage sound if we're about to take damage
    if (invincibilityFrames == 0)
        handler->getSoundEffectManager()->playSoundEffect("enemy_hurt");
        
    DynamicEntity::damage(damage);
}

void BlueEnemy::onDeath(){
    handler->getSoundEffectManager()->playSoundEffect("enemy_death");
}