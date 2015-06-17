//
//  IAVertex.cpp
//  MeshMapper
//
//  Created by plutots on 17/06/15.
//
//

#include "IAVertex.h"
#include "constants.h"

IAVertex::IAVertex(){
    size = 20;
    active = false;
    drag = false;
    enabled = true;
    enableAllEvents();
}

IAVertex::~IAVertex(){
    disableAllEvents();
}


void IAVertex::set(float ix, float iy){
    x = ix;
    y = iy;
}

bool IAVertex::hitTest(int tx, int ty) const {
    return (((x-tx)*(x-tx)+(y-ty)*(y-ty)) < size*size*0.25);
}

void IAVertex::setup() {
    enableMouseEvents();
    enableKeyEvents();
}

void IAVertex::update() {
    if(drag){
        x = getMouseX() + mouse_anchorX;
        y = getMouseY() + mouse_anchorY;
        ofHideCursor();
    }
    else ofShowCursor();
}

void IAVertex::draw() {
    ofPushStyle();
    ofSetLineWidth(2);
    if(active){
        ofSetHexColor(DOWN_COLOR);
        ofLine(x, 0, x, ofGetHeight());
        ofLine(0, y, ofGetWidth(), y);
        ofNoFill();
    }
    else if(isMouseOver()) ofSetHexColor(OVER_COLOR);
    else ofSetHexColor(IDLE_COLOR);
    ofCircle(x,y,size*0.5);
    ofPopStyle();
}


void IAVertex::onDragOver(int x, int y, int button) {
    if (active) drag = true;
}

void IAVertex::onPress(int x, int y, int button) {
    active = true;
    mouse_anchorX = IAVertex::x - x;
    mouse_anchorY = IAVertex::y - y;;
}

void IAVertex::onPressOutside(int x, int y, int button) {
    active = false;
}

void IAVertex::onRelease(int x, int y, int button) {
    if (drag) drag = false;
}