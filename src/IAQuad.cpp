//
//  IAQuad.cpp
//  MeshMapper
//
//  Created by plutots on 18/06/15.
//
//

#include "IAQuad.h"

IAQuad::IAQuad(){
    
    enableAllEvents();
    polygon = new ofPolyline;
    vertactive = false;
    active = false;
    enabled = true;
    
    float cx = ofGetWidth()*0.5;
    float cy = ofGetHeight()*0.5;
    
    addVertex(cx-100, cy-100);
    addVertex(cx-100, cy+100);
    addVertex(cx+100, cy+100);
    addVertex(cx+100, cy-100);
    
}

IAQuad::~IAQuad(){
    
    disableAllEvents();
    polygon->clear();
    delete polygon;
    while(!iaverts.empty()) delete iaverts.back(), iaverts.pop_back();
    iaverts.clear();
}