#pragma once

#include "ofMain.h"
#include "Settings.h"
#include "ofxPiMapper.h"
#include "VideoSource.h"
#include "SceneManager.h"
#include "Overlay1.hpp"
#include "Highlights1.hpp"
#include "Overlay2.hpp"
#include "Squares.hpp"
#include "InnerRing.hpp"

class ofApp : public ofBaseApp {
	public:
		void setup();
		void update();
		void draw();
	
		void keyPressed(int key);
		void keyReleased(int key);
	
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseDragged(int x, int y, int button);

		ofxPiMapper piMapper;

        InnerRing * innerRing;
        Overlay1 * overlay1;
        Highlights1 * highlights1;
        Overlay2 * overlay2;
        Squares * squares;
    
        ofImage dummyObjects;

        SceneManager sceneManager;
    
        Squares square;
};
