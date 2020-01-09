// C program to demonstrate 
// drawing a circle using 
// OpenGL 
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 
    
void display ()  
{ 
    glClear(GL_COLOR_BUFFER_BIT); 
    glBegin(GL_POINTS); 
    float x, y, i; 

    // round face
    for ( i = 0; i < (2 * pi); i += 0.001) 
    { 
        // let 200 is radius of circle and as, 
        // circle is defined as x=r*cos(i) and y=r*sin(i) 
        x = 1 * cos(i); 
        y = 1 * sin(i); 
          
        glVertex2f(x, y); 
    } 
    glEnd();

    // right eye 
    glBegin(GL_POINTS);   
    for ( i = 0; i < (2 * pi); i += 0.001) 
    { 
        // let 200 is radius of circle and as, 
        // circle is defined as x=r*cos(i) and y=r*sin(i) 
        x = 0.4 + 0.2 * cos(i); 
        y = 0.3 + 0.1 * sin(i); 
          
        glVertex2f(x, y); 
    } 
    glEnd();

    // left eye
    glBegin(GL_POINTS);   
    for ( i = 0; i < (2 * pi); i += 0.001) 
    { 
        // let 200 is radius of circle and as, 
        // circle is defined as x=r*cos(i) and y=r*sin(i) 
        x = -0.4 + 0.2 * cos(i); 
        y = 0.3 + 0.1 * sin(i); 
          
        glVertex2f(x, y); 
    } 
    glEnd();

    // nose
    glBegin(GL_LINES);              // Line
      glVertex2f(0.0f, 0.1f);    // x, y
      glVertex2f( 0.0f, -0.1f);
    glEnd();
    
    // mouth
    glBegin(GL_POINTS);   
    for ( i = 200; i < 340; i += 0.001) 
    { 
        // let 200 is radius of circle and as, 
        // circle is defined as x=r*cos(i) and y=r*sin(i) 
        x =  0.5 * cos(2*pi*i/360); 
        y =  0.5 * sin(2*pi*i/360); 
          
        glVertex2f(x, y); 
    } 
    glEnd();

    glFlush(); 
} 
  
int main (int argc, char** argv) 
{ 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
      
    // giving window size in X- and Y- direction 
    glutInitWindowSize(500, 500); 
    glutInitWindowPosition(0, 0); 
      
    // Giving name to window 
    glutCreateWindow("Circle Drawing"); 
      
    glutDisplayFunc(display); 
    glutMainLoop(); 
} 