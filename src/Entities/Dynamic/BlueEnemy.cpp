#include "BlueEnemy.h"



void BlueEnemy::update(){
    if(link){
        double x1=getPlayer()->getX();
        double y1=getPlayer()->getY();
        double dx=x1-getBlueEnemyX();
        double dy=y1-getBlueEnemyY();
        // Reset movement directions
        movingDir[UP] = false;
        movingDir[DOWN] = false;
        movingDir[LEFT] = false;
        movingDir[RIGHT] = false;
        Direction direction;
        movingDir[direction]=false;

        // Calculate the direction towards Link
        if (abs(dx) > abs(dy)) {
            // Move horizontally
            if (dx > 0) {
                movingDir[RIGHT] = true;
                movingDir[direction]=true;
            } else {
                movingDir[LEFT] = true;
                movingDir[direction]=true;
            }
        } else {
            // Move vertically
            if (dy > 0) {
                movingDir[DOWN] = true;
                movingDir[direction]=true;
            } else {
                movingDir[UP] = true;
                movingDir[direction]=true;
            }
        }
    }
    
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