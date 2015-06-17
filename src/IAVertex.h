//
//  IAVertex.h
//  MeshMapper
//
//  Created by plutots on 17/06/15.
//
//

#ifndef __MeshMapper__IAVertex__
#define __MeshMapper__IAVertex__

#include "ofxMSAInteractiveObject.h"
#include "ofMain.h"

#define		IDLE_COLOR		0x2aa198
#define		OVER_COLOR		0xcb4b16
#define		DOWN_COLOR		0xdc322f


class IAVertex : public ofxMSAInteractiveObject {
public:
    
    float size;
    
    float mouse_anchorX;
    float mouse_anchorY;
    
    bool drag;
    bool active;
    
    void set(float ix, float iy, float d){
        size = d;
        x = ix;
        y = iy;
    }
    
    bool hitTest(int tx, int ty) const {
        return (((x-tx)*(x-tx)+(y-ty)*(y-ty)) < size*size*0.25);
    }
    
    
    void setup() {
        enableMouseEvents();
        enableKeyEvents();
    }
    
    
    void exit() {

    }
    
    
    void update() {
        
        if(drag){
            x = getMouseX() + mouse_anchorX;
            y = getMouseY() + mouse_anchorY;
            ofHideCursor();
        }
        else ofShowCursor();

    }
    
    
    void draw() {
        
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
    
    
    virtual void onDragOver(int x, int y, int button) {
        if (active) drag = true;
    }
    
    virtual void onPress(int x, int y, int button) {
        active = true;
        mouse_anchorX = IAVertex::x - x;
        mouse_anchorY = IAVertex::y - y;;
    }
    
    virtual void onPressOutside(int x, int y, int button) {
        active = false;
    }
    
    virtual void onRelease(int x, int y, int button) {
        if (drag) drag = false;
    }
    
    
};


#endif /* defined(__MeshMapper__IAVertex__) */
