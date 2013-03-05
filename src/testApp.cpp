#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(0); 
    ofSetFrameRate(60);
    
    
    seedX = targX = 100;
    seedY = targY = 500;
}

//--------------------------------------------------------------
void testApp::update(){
    
    float incr = 0.005000;
    
    if( seedX != targX ){
        if( seedX < targX ){
            seedX += incr;
        } else {
            seedX -= incr;
        }
    }
    
    if( seedY != targY ){
        if( seedY < targY ){
            seedY += incr;
        } else {
            seedY -= incr;
        }
    }
    
    // cout << seedX - targX << " -- " << std::abs(seedX - targX ) << endl;
    
    if( std::abs(seedX - targX) < incr ) seedX = targX;
    if( std::abs(seedY - targY) < incr ) seedY = targY;
    
    //    seedX -= ( seedX - targX ) * 0.01;
    //    seedY -= ( seedY - targY ) * 0.01;
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    cam.begin();
    
    
    ofNoFill();
  //  ofSetColor( 200,200,200);
    
    ofTranslate( 0,0,-500);
    ofRotateY( ofGetFrameNum()/4.0f );
    
    float radius = 500.f;
    float xPct, yPct, nx, ny, nz;
    
    float offset = ofGetFrameNum() * 0.25;
    
    float incr = 500.f/PI;
    ofColor clr = ofColor( 255,255,255);
    
    for( int i = 0; i < 500 ; i++ ){
        
        xPct = ( (((float)i*incr) + offset) * seedX ) * 0.0001;
        yPct = ( (((float)i*incr) + offset) * seedY ) * 0.0001;
        
        nx = radius * sin(xPct) * sin(yPct);
        ny = radius * cos(yPct) * sin(xPct);
        nz = radius * cos(xPct);
        
        clr.setHsb( ((float)i/500.f)*360.f , 200, 225 );
        ofSetColor( clr );
        ofBox( nx, ny, nz , 10.f );
    }
    
    
    cam.end();
    
    
    
    ofSetColor(255, 255, 255);
	stringstream reportStream;
	reportStream << "Radius = number of objects = 500" << endl
    << "target X :  " << ofToString( targX ) << "  actual: " << seedX << endl
	<< "target Y :  " << ofToString( targY ) << "  actual: " << seedY << endl
    << endl 
    << "adjust X   -1 = 1 | -10 = (shift+1) | -0.1 = q" << endl
    << "           +1 = 2 | +10 = (shift+2) | +0.1 = w" << endl
    << "adjust Y   -1 = 3 | -10 = (shift+3) | -0.1 = e" << endl
    << "           +1 = 4 | +10 = (shift+4) | +0.1 = r" << endl;
	ofDrawBitmapString(reportStream.str(), 20, ofGetHeight() - 120);
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    switch( key ){
            
        case 'q':
            targX -= 0.10;
            break;
        case 'w':
            targX += 0.10;
            break;
            
        case '1':
            targX --;
            break;
            
        case '2':
            targX ++;
            break;
            
        case '!':
            targX -= 10;
            break;
            
        case '@':
            targX += 10;
            break; 
            
            
            
            
        case 'e':
            targY -= 0.10;
            break;
            
        case 'r':
            targY += 0.10;
            break;
            
        case '3':
            targY --;
            break;
            
        case '4':
            targY ++;
            break;
            
        case '#':
            targY -= 10;
            break;
            
        case '$':
            targY += 10;
            break;
            
            
            
    }
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
    
}