#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#define m 2

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    int x1, x2, y1, y2;
    gluOrtho2D(-20, 20, -20, 20);
    x1 = -15,  y1 = -10, x2 = 16, y2 = 15;
    glBegin(GL_POINTS);
    // logic
    int m_new = 2 * (y2 - y1); 
    int slope_error_new = m_new - (x2 - x1); 
    for (int x = x1, y = y1; x <= x2; x++) 
    { 
        // printf("( %d, %d)\n", x, y); 
        glVertex2f(1*x, 1*y);
        // Add slope to increment angle formed 
        slope_error_new += m_new; 

        // Slope error reached limit, time to 
        // increment y and update slope error. 
        if (slope_error_new >= 0) 
        { 
            y++; 
            slope_error_new  -= 2 * (x2 - x1); 
        } 
    }
    glEnd();
    glFlush();
}
int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(1000, 800);
glutInitWindowPosition(0, 0);

// Giving name to window
glutCreateWindow("Bresenham’s Line Generation Algorithm");
glutDisplayFunc(display);
glutMainLoop();
}