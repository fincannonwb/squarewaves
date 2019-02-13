#include "ofApp.h"

void ofApp::setup(){
    ofBackground(0);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
 
	ofx::piMapper::VideoSource::enableAudio = true;
	ofx::piMapper::VideoSource::useHDMIForAudio = false;
    
    overlay1 = new Overlay1();
    overlay1->setup();
    piMapper.registerFboSource(overlay1);
    
    highlights1 = new Highlights1();
    highlights1->setup();
    piMapper.registerFboSource(highlights1);
    
    overlay2 = new Overlay2();
    overlay2->setup();
    piMapper.registerFboSource(overlay2);
    
    innerRing = new InnerRing();
    innerRing->setup();
    piMapper.registerFboSource(innerRing);
    
    squares = new Squares();
    squares->setup();
    piMapper.registerFboSource(squares);
    
    piMapper.setup();
	
	ofSetFullscreen(Settings::instance()->getFullscreen());
	ofSetEscapeQuitsApp(false);

    //dummyObjects.load("nestedRendered.png");

    sceneManager.setup("scenes.json", &piMapper);
    
}
//-----------------------------------------------------------
void ofApp::update(){
    //code for triggering next project during popup
//    if(ofGetElapsedTimeMillis() > 10000){
//        ofExit();
//    }
    ofEnableAlphaBlending();
	piMapper.update();
    sceneManager.update();
    square.sequencer();
   
    
}
//-----------------------------------------------------------
void ofApp::draw(){
    
    ofEnableAlphaBlending();
    //dummyObjects.draw(100,100);
    piMapper.draw();
}
//-----------------------------------------------------------
void ofApp::keyPressed(int key){
   
    if (key=='5') {
        if (piMapper.getNumPresets()>1){
            int targetScene = piMapper.getActivePresetIndex() - 1;
            if (targetScene<0) targetScene = piMapper.getNumPresets()-1;
            piMapper.setPreset(targetScene);
            cout << "Switched to preset: " << piMapper.getActivePresetIndex() << endl;
        } else cout << "only one preset available" << endl;
    }
    
    else if (key=='6') {
        if (piMapper.getNumPresets()>1){
            piMapper.setNextPreset();
            cout << "Switched to preset: " << piMapper.getActivePresetIndex() << endl;
        } else cout << "only one preset available" << endl;
    }
    else if (key == '7'){
        piMapper.cloneActivePreset();
        piMapper.setPreset(piMapper.getNumPresets()-1);
        cout << "Cloned and switched to preset: " << piMapper.getActivePresetIndex() << endl;
    }
    
    //keys for triggering the next/previous loop for debugging purposes
    else if (key == 'n'){
        squares->loop++;
    }
    else if (key == 'b'){
        squares->loop--;
    }

	piMapper.keyPressed(key);
}
//-----------------------------------------------------------
void ofApp::keyReleased(int key){
	piMapper.keyReleased(key);
}
//-----------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	piMapper.mousePressed(x, y, button);
}
//-----------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	piMapper.mouseReleased(x, y, button);
}
//-----------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	piMapper.mouseDragged(x, y, button);
}
