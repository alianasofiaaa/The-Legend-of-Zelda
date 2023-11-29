#pragma once

#include "Animation.h"
#include "Link.h"
#include "Tektike.h"
#include "BlueEnemy.h"
#include "MapBuilder.h"
#include "State.h"
#include "SwordItem.h"
#include <memory>

class GameState : public State {

private:
    shared_ptr<Map> currentMap;
    shared_ptr<Map> overWorldMap;
    shared_ptr<Map> oldManCaveMap;
    shared_ptr<Map> NewDungeonMap;
    shared_ptr<SwordItem> Sword;
    shared_ptr<Link> link;
    unique_ptr<MapBuilder> mapBuilder;
   
public:
    GameState(shared_ptr<Handler> handler) : State(handler) { this->reset(); }
    void update();
    void draw();
    void reset();
    void keyPressed(int key);
    void keyReleased(int key);
    ofImage menuHUD;
    bool paused;
    int hudY;
    int hudH;
    int hudHeight;
    int changeState;
    int SwordImageX=8;
    int SwordImageY=5;
 
   
    shared_ptr<Tektike> createTektike();
    shared_ptr<BlueEnemy> createBlueEnemy();
    shared_ptr<SwordItem> createSword();
};