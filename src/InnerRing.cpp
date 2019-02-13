#include "InnerRing.hpp"

//draws black boxes for the inner ring
//not used in final version

void InnerRing::setup() {
    name = "InnerRing";
    allocate(200, 200);
    fboW = fbo->getWidth();
    fboH = fbo->getHeight();
}

void InnerRing::drawBox(){
    
    for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 2; y++) {
            ofPushMatrix();
            ofPushStyle();
            ofTranslate(fboW/2 * x, fboH/2 * y);
            ofSetColor(0, 0, 0, 255);
            ofClearAlpha();
            ofDrawRectangle(0, 0, fboW/2, fboH/2);
            ofPopStyle();
            ofPopMatrix();
        }
    }
}

void InnerRing::draw() {
    drawBox();
}
