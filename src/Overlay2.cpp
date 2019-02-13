#include "Overlay2.hpp"

//shadow overlay

void Overlay2::setup() {
    name = "Overlay2";
    allocate(400, 400);
}
void Overlay2::draw() {
    ofBackground(0,0,0,140);
    ofDrawRectangle(0, 0, fboW, fboH);
    
}
