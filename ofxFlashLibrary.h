/*
 *  ofxFlashLibrary.h
 *  emptyExample
 *
 *  Created by lukasz karluk on 1/11/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

#include "ofMain.h"
#include "ofxFlashLibraryLoader.h"
#include "ofxFlashLibraryLoaderIOS.h"
#include "ofxFlashDisplayObject.h"

#define OFX_FLASH_LIBRARY_TYPE_IMAGE	0
#define OFX_FLASH_LIBRARY_TYPE_VIDEO	1
#define OFX_FLASH_LIBRARY_TYPE_SOUND	2

////////////////////////////////////////////////////////
//	OFX_FLASH_LIBRARY_ITEM
////////////////////////////////////////////////////////

class ofxFlashLibraryItem
{
	
public:
	
	string			assetID;
	string			assetPath;
	int				assetType;
	ofBaseDraws*	imageAsset;
	ofSoundPlayer*	soundAsset;
	
};

////////////////////////////////////////////////////////
//	OFX_FLASH_LIBRARY
////////////////////////////////////////////////////////

class ofxFlashLibrary
{
	
private: 
	
	static ofxFlashLibrary* _instance;
	
	 ofxFlashLibrary() {};
	~ofxFlashLibrary() {};

	vector<ofxFlashLibraryItem*> items;
	vector<ofxFlashLibraryItem*> imageItems;
	vector<ofxFlashLibraryItem*> videoItems;
	vector<ofxFlashLibraryItem*> soundItems;
	vector<ofxFlashLibraryItem*> symbolItems;
	vector<ofxFlashDisplayObject*> displayObjects;
	
public:
	
	static ofxFlashLibrary* getInstance()
	{
		if( !_instance )
		{
			_instance = new ofxFlashLibrary();
		}
		
        return _instance;
	}
	
	void addAsset	( string assetID, string assetPath, int assetType );
	void addImage	( string assetID, string assetPath );	
	void addImage	( string assetID, ofBaseDraws& image );
	void addVideo	( string assetID, string assetPath );
	void addVideo	( string assetID, ofBaseDraws& video );
	void addSound	( string assetID, string assetPath );
	void addSound	( string assetID, ofSoundPlayer& sound );
	
	ofBaseDraws* loadImage( string imagePath );
	ofBaseDraws* loadVideo( string videoPath );
	
	ofSoundPlayer* getSound				( string assetID );
	ofSoundPlayer* getSoundByFileName	( string fileName );
	ofBaseDraws* getAsset				( string assetID );
	ofBaseDraws* getAssetByFileName		( string fileName );
	
	void	addSymbol	( string assetID, string assetPath );
	string	getSymbol	( string assetID );
	bool	hasSymbol	( string assetID );
	
	ofxFlashDisplayObject*	addDisplayObject	( string libraryItemName, ofxFlashDisplayObject* displayObject );
	ofxFlashDisplayObject*	getDisplayObject	( string libraryItemName );
	bool					hasDisplayObject	( string libraryItemName );
};