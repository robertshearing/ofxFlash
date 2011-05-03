#include "testApp.h"
#include "Arrow.h"

///////////////////////////////////////////
//	INIT.
///////////////////////////////////////////

void testApp::setup()
{
	ofSetFrameRate( 30 );							// OF setup.
	ofSetVerticalSync( true );
	ofSetCircleResolution( 100 );
	ofEnableSmoothing();
	ofBackground( 255, 255, 255 );
	
	runOnce = false;
	frame = 0;
	count = 0;
	
	framerate = ofGetElapsedTimeMillis();
	
	stage = ofxFlashStage :: getInstance();			// ofxFlash setup.
	stage->addListeners();
	stage->showRedrawRegions( bShowRedrawRegions = false );

	
	xfl.loadFile( "assets/DOMDocument.xml" );		// load XFL flash file.
	//xfl.build();
	
	
}

///////////////////////////////////////////
//	UPDATE.
///////////////////////////////////////////

void testApp::update()
{
	if(frame < 40){
	for(int i = 0; i< 100; i++){
		Arrow* a = new Arrow();
		a->x( (int)( 800*ofRandomuf() ) );
		a->y( (int)( 600*ofRandomuf() ) );
		stage = ofxFlashStage :: getInstance();
		stage->addChild( a );
		count++;
	}
	}
	int delay = ofGetElapsedTimeMillis() - framerate;
	framerate = ofGetElapsedTimeMillis();
	printf("Speed: %i : %i\n", delay, count);
	frame++;
	
}

///////////////////////////////////////////
//	DRAW.
///////////////////////////////////////////

void testApp::draw()
{
	//
}

///////////////////////////////////////////
//	HANDLERS.
///////////////////////////////////////////

void testApp::keyPressed(int key)
{
	if( key == 'd' )
	{
		stage->showRedrawRegions( bShowRedrawRegions = !bShowRedrawRegions );
	}
}

void testApp::keyReleased(int key)
{

}

void testApp::mouseMoved(int x, int y )
{

}

void testApp::mouseDragged(int x, int y, int button)
{
}

void testApp::mousePressed(int x, int y, int button)
{
	Arrow* a = new Arrow();
	a->x( (int)( x ) );
	a->y( (int)( y ) );
	stage = ofxFlashStage :: getInstance();
	stage->addChild( a ); 
	
}

void testApp::mouseReleased(int x, int y, int button)
{

}

void testApp::windowResized(int w, int h)
{

}

