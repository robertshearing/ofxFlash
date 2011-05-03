/*
 *  Arrow.h
 *  ofxFlashTest
 *
 *  Created by Rob Shearing on 3/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

#include "ofMain.h"
#include "ofxFlash.h"

class Arrow : public ofxFlashMovieClip
{
public:
	
	Arrow( )
	{
		ofxFlashLibrary* library = ofxFlashLibrary :: getInstance();
		ofxFlashXFLBuilder* builder = new ofxFlashXFLBuilder();
		
		string path = library->getSymbol("arrow_asset");
		builder->build( path, this );
		this->update();
		
		delete builder;
		builder = NULL;
	}

	
};