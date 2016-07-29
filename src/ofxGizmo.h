//
//  ofxGizmo.h
//  TerrainTest
//
//  Created by Nick Hardeman on 10/5/14.
//

#pragma once
#include "ofMain.h"
#include "IGizmo.h"

class ofxGizmo {
public:
    ofxGizmo();
    ~ofxGizmo();
    
    enum ofxGizmoType {
        OFX_GIZMO_MOVE = 0,
        OFX_GIZMO_SCALE,
        OFX_GIZMO_ROTATE
    };
    
    void setMatrix( const ofMatrix4x4& aMat );
	bool setMatrix(const std::string& aString);
    void setNode( const ofNode& aNode );
    
    void draw( const ofCamera& aCam );
    
    void setDisplayScale( const float aScale );
    void setType( ofxGizmoType aType );
    ofMatrix4x4& getMatrix();
    
    void hide();
    void show();
    void toggleVisible();
    bool isVisible();
    
    // is the gizmo using the mouse?
    bool isInteracting();
    
    void setViewDimensions( float aw, float ah );
    
    string getMatrixAsString();
    bool save( const std::string& aFileName );
    bool load( const std::string& aFileName );
    
    void enableMouseInput();
    void disableMouseInput();
    
    void mouseMoved( ofMouseEventArgs& args );
    void mouseDragged( ofMouseEventArgs& args );
    void mousePressed( ofMouseEventArgs& args );
    void mouseReleased( ofMouseEventArgs& args );
    
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    bool mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    
protected:
    bool _bHasMouseEvents;
    bool _bInteracting;
    bool _bVisible;
    
    float _windowW, _windowH;
    bool bNodeSet;
    ofRectangle viewPort;
    ofMatrix4x4 objectMatrix;
    IGizmo *gizmo       = NULL;
    IGizmo *gizmoMove   = NULL;
    IGizmo *gizmoRotate = NULL;
    IGizmo *gizmoScale  = NULL;
};
