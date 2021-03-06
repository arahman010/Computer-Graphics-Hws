// ===============================================================
// Computer Graphics Homework Solutions
// Copyright (C) 2017 by George Wolberg
//
// HW1a.cpp - HW1a class
//
// Written by: George Wolberg, 2017
// ===============================================================

#include "HW1a.h"

// init array of 16 vertices for letter 'P'
float Vertices[] = {
	-0.5f , -0.75f,
	-0.5f , -0.5f,
	-0.5f , -0.25f,
	-0.5f ,  0.0f,
	-0.5f ,  0.25f,
	-0.5f ,  0.5f,
	-0.25f,  0.75f,
	 0.0f ,  0.75f,
	 0.25f,  0.75f,
	 0.5f ,  0.75f,
	 0.75f,  0.5f,
	 0.75f,  0.25f,
	 0.5f ,  0.0f,
	 0.25f,  0.0f,
	 0.0f ,  0.0f,
	-0.25f,  0.0f
};

static int DrawModes[] = {
	GL_POINTS,
	GL_LINES,
	GL_LINE_STRIP,
	GL_LINE_LOOP,
	GL_TRIANGLES,
	GL_TRIANGLE_STRIP,
	GL_TRIANGLE_FAN,
	GL_QUADS,
	GL_POLYGON
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::HW1a:
//
// HW1a constructor.
//
HW1a::HW1a(const QGLFormat &glf, QWidget *parent)
	: HW(glf, parent)
{
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::initializeGL:
//
// Initialization routine before display loop.
// Gets called once before the first time resizeGL() or paintGL() is called.
//
void
HW1a::initializeGL()
{
	// PUT YOUR CODE HERE
    
    // State Variables
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::resizeGL:
//
// Resize event handler.
// The input parameters are the window width (w) and height (h).
//
void
HW1a::resizeGL(int w, int h)
{
	// PUT YOUR CODE HERE
    // Save window dimension
    m_winH = h;
    m_winW = w;
 
    // compute aspect ratio
    float xmax, ymax;
    float ar = (float) w / h;
    if(ar > 1.0) {		// wide screen
        xmax = ar;
        ymax = 1.;
    } else {		// tall screen
        xmax = 1.;
        ymax = 1/ar;
    }
  

    
    // Load Identity Matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-xmax, xmax, -ymax, ymax, -1.0, 1.0);
  
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::paintGL:
//
// Update GL scene.
//
void
HW1a::paintGL()
{
	// PUT YOUR CODE HERE
    // Clear canvas with background color
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Create 9 view ports to project different P
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            glViewport(j * m_winW/3, i * m_winH/3, m_winW/3 , m_winH/3);
            
            glBegin(DrawModes[j+(i*3)]);
            for ( int k = 0; k < 16*2; k += 2){
               glVertex2f(Vertices[k], Vertices[k+1]);
            }
            glEnd();
            //glFlush();
            
        }
    }
}




// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::controlPanel:
//
// Create control panel groupbox.
//
QGroupBox*
HW1a::controlPanel()
{
	// init group box
	QGroupBox *groupBox = new QGroupBox("Homework 1a");
	groupBox->setStyleSheet(GroupBoxStyle);

	return(groupBox);
}
