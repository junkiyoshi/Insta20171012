#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(255);
	ofSetWindowTitle("Insta");

}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw() {
	this->cam.setPosition(ofVec3f(0, -1024, 768));
	this->cam.setTarget(ofVec3f(0, 0, 0));
	this->cam.begin();

	float radius = 300;
	float x, y, z;
	float noise_value;
	ofVec3f point, prev_point;
	for (int i = 0; i < 30; i++) {
		for (int deg = 0; deg <= 360; deg += 1) {
			x = radius * cos(deg * DEG_TO_RAD);
			y = radius * sin(deg * DEG_TO_RAD);

			noise_value = ofNoise(x * 0.01, y * 0.01, (ofGetFrameNum() - i) * 0.015);
			if (noise_value > 0.5) {
				z = 512 * round(noise_value * 10) / 10.f;
			}
			else {
				z = 512 * 0.5;
			}

			x = (radius + i * 30) * cos(deg * DEG_TO_RAD);
			y = (radius + i * 30) * sin(deg * DEG_TO_RAD);

			point = ofVec3f(x, y, z);
			if (deg != 0) {
				ofSetColor(0, 255 - i * 8.5);
				ofDrawLine(point, prev_point);
			}

			prev_point = point;
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
