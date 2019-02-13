#include "Highlights1.hpp"

//highlight overlay

void Highlights1::setup() {
    name = "Highlights1";
    allocate(400, 400);
}
void Highlights1::draw() {
    ofBackground(255,255,255,50);
    ofDrawRectangle(0, 0, fboW, fboH);
    
}
