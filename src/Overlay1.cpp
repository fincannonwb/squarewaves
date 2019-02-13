#include "Overlay1.hpp"

//shadow overlay
//not used in final version

void Overlay1::setup() {
    name = "Overlay1";
    allocate(400, 400);
}

void Overlay1::draw() {
    ofBackground(0,0,0,140);
    ofDrawRectangle(0, 0, fboW, fboH);
}
