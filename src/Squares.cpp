#include "Squares.hpp"

void Squares::setup(){
    name = "Squares";
    allocate(400, 400);
    fboW = fbo->getWidth();
    fboH = fbo->getHeight();
    
    // sequencer initialization
    // 1 second == 990 millis
    // 1 beat == second x 1
    // 1 measure == beat x 4
    // 1 loop == measure x 4
    beat = 1;
    measure = 1;
    loop = 1;
    startTime = 0;
    second = 990; //for some reason, 990 millis was more acurate than 1000
    measureLength = 4;
    loopLength = 4;
    on = false; //bool for triggering additional patterns
    
}

void Squares::update(){
    
    // sequencer initialization cont.
    timef = ofGetElapsedTimef();
    timeMillis = ofGetElapsedTimeMillis();
    timer = timeMillis - startTime;
    
    // if statement for second
    if(timer >= second/2){
        startTime = ofGetElapsedTimeMillis();
        randomB = ofRandom(10);
        noiseB = ofNoise(timef);
        noiseMappedB = ofMap(noiseB, 0, 1, 0, 255, true);
        beat++; //adds 1 to beat every second
        // outputs sequencer info
        if(beat <= 4){
            cout<<"L"<<loop<< " - "
            <<"M"<<measure<<" - "
            <<"B"<<beat<<" - "
            <<ofGetElapsedTimef()<<" - "
            <<endl;
        }
    }
    // if statement for beat
    if(beat > measureLength) {
        beat = 1;
        measure++; //adds 1 to measure every 4 beats
        randomM = ofRandom(10);
        noiseM = ofNoise(timef);
        noiseMappedM = ofMap(noiseM, 0, 1, 0, 255, true);
        //triggers a random loop every 4 measures
        if(measure > loopLength) {
            startTime=ofGetElapsedTimeMillis();
            loop = ofRandom(1,5);
            measure = 1;
        }
        cout<<"L"<<loop<< " - "<<"M"<<measure<<" - "<<"B"<<beat<<" - "<<ofGetElapsedTimef()<<" - "<< sinWaveM2<<endl;
    }
    
    // Stops loops after specified time
    if(ofGetElapsedTimef() >= 150) {
       // loop = 11; //end
    }
    
}

void Squares::strobe(float freq, float offset){
    //sine wave initialization, mapping, and variations
    sinWave = 60 * (sin(((timef*TWO_PI*freq)+offset-(PI/4))+1)*0.5);
    sinWaveM = ofMap(sinWave, -15, 30, 0, 255, true);
    sinWaveMInv = ofMap(sinWave, 0, 30, 255, 0, true);
    sinWaveM2 = ofMap(sinWave, -15, 30, 0, 1, true);
    sinWaveM2Inv = ofMap(sinWave, 0, 50, 1, 0, true);
}

void Squares::background(){
    //background color
    ofSetColor(0, 0, 0, 255);
    ofDrawRectangle(0, 0, fboW, fboH);
}

void Squares::boxes(float scale, float strobeFreq, float strobeOffset, bool on){
    //creating the squares
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    for (int b = 0; b < 7; b++) {
        for (int c = 0; c < 7; c++) {
            ofPushMatrix();
            ofPushStyle();
            ofTranslate((fboW/7 * b)+((fboW/7)/2), (fboH/7 * c)+((fboH/7)/2));
            strobe(strobeFreq, strobeOffset * b * TWO_PI);
            if(on){
                ofSetColor(255, 255, 255, sinWaveM * b);
            } else {
                ofSetColor(255, 255, 255, sinWaveM);}
            ofScale(scale);
            ofDrawRectangle(0, 0, fboW/7, fboH/7);
            ofClearAlpha();
            ofPopStyle();
            ofPopMatrix();
        }
    }
}

void Squares::grid(float r, float g, float b, float a){
    //creating the grid
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    for (int x = 0; x < 7; x++) {
        for (int y = 0; y < 7; y++) {
            ofPushMatrix();
            ofPushStyle();
            ofTranslate((fboW/7 * x)+((fboW/7)/2), (fboH/7 * y)+((fboH/7)/2));
            ofNoFill();
            ofSetLineWidth(7);
            ofSetColor(r, g, b, a);
            ofDrawRectangle(0, 0, fboW/7, fboH/7);
            ofPopStyle();
            ofPopMatrix();
        }
    }
}

void Squares::sequencer(){
    //sequencer controlling the timing and patterns
    if(loop == 1){
        if(measure >= 1 && measure <= 4){
            boxes(1, 1, PI, false);
            grid(0,0,0,255);
        }
    }
    
    if(loop == 2){
        if(measure >= 1 && measure <= 4) {
            if(beat == 1 || beat == 2){
                boxes(1, 1, PI, false);
                grid(0,0,0,255);}
            if(beat == 3 || beat == 4){
                boxes(sinWaveM2Inv, 1, PI, false);
                grid(0,0,0,255);
                grid(255,255,255,sinWaveM);
                
            }
        }
    }
    if(loop == 3){
        if(measure >= 1 && measure <= 4) {
            if(beat == 1 || beat == 2){
                boxes(1, 1, randomM*PI,  false);
                grid(0,0,0,255);}
            if(beat == 3 || beat == 4){
                boxes(sinWaveM2Inv, 1, randomM*PI,  false);
                grid(0,0,0,255);
                grid(255,255,255,sinWaveM);}
        }
    }
    if(loop == 4){
        if(measure >= 1 && measure <= 4) {
            if(beat == 1){
                boxes(1, 1, randomM*PI,  true);
                grid(0,0,0,255);}
            if(beat == 2){
                boxes(1, 1, randomM*PI, true);
                grid(0,0,0,255);}
            if(beat == 3){
                boxes(sinWaveM2Inv, 1, randomM*PI,  true);
                grid(0,0,0,255);
                grid(255,255,255,sinWaveM);}
            if(beat == 4){
                boxes(sinWaveM2Inv, 1, randomM*PI,  true);
                grid(0,0,0,255);
                grid(255,255,255,sinWaveM);
            }
        }
    }
    
    if(loop == 5){
        if(measure >= 1 && measure <= 4) {
            if(beat == 1){
                boxes(1, 1, noiseM*PI,false);
                grid(0,0,0,255);}
            if(beat == 2){
                boxes(1, 1, noiseM*PI,false);
                grid(0,0,0,255);}
            if(beat == 3){
                boxes(sinWaveM2Inv, 1, noiseM*PI,false);
                grid(0,0,0,255);
                grid(255,255,255,sinWaveM);}
            if(beat == 4){
                boxes(sinWaveM2Inv, 1, noiseM*PI,false);
                grid(0,0,0,255);
                grid(255,255,255,sinWaveM);
            }
        }
    }
}

void Squares::draw(){
    //drawing the background and the sequencer
    background();
    sequencer();
}

//changes were also made to the ofxPiMapper addon:
//ofxPiMapper/src/Surfaces/SurfaceStack.cpp
//added ofEnableAlphaBlending(); to the if statement inside of the draw function
//this allows for transparent fbo sources


//All borrowed code used in the final version was derived from the projects within the examples folder and from the openFrameworks book and website.

//Specifically:
//periodicSignalsExample
//https://openframeworks.cc/ofBook/chapters/animation.html
