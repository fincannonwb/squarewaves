#pragma once

#include "ofMain.h"
#include "FboSource.h"

class Overlay1 : public ofx::piMapper::FboSource {
public:
    void setup();
    void draw();
   
    float fboW;
    float fboH;
};

