#pragma once

#include "ofMain.h"
#include "FboSource.h"

class InnerRing : public ofx::piMapper::FboSource {
public:
    void setup();
    void draw();
    void drawBox();
    
    float fboW;
    float fboH;
    
};

