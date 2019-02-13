#pragma once

#include "ofMain.h"
#include "FboSource.h"

class Squares : public ofx::piMapper::FboSource {
public:
    
    void setup();
    void update();
    void draw();
    void strobe(float freq, float offset);
    void background();
    void boxes(float scale, float strobeFreq, float strobeOffset,
               bool on);
    void grid(float r, float g, float b, float a);
    void sequencer();
    
    float fboW;
    float fboH;
    
    float startTime, timeMillis, timer, second, timef;;
    int beatLength, measureLength, loopLength;
    int beat, measure, loop;
    
    float sinWave, sinWaveM, sinWaveMInv;
    float sinWave2, sinWaveM2, sinWaveM2Inv;
    
    float noiseB, noiseMappedB;
    float noiseM, noiseMappedM;
    float randomB, randomM;
    
    bool on;
    
};

