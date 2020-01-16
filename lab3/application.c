#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    float i, X1, Y1, X2, Y2, dX, dY, steps, X, Y;
    float Xinc, Yinc;
    gluOrtho2D(-5, 5, -5, 5);
    // inner square
    // X = X1;
    // Y = Y1;
    // dX = X2 - X1;
    // dY = Y2 - Y1;
    // // choosing the number of steps
    // steps = abs(dX) > abs(dY) ? dX : dY;
    // // calculate the increment in x and y for each steps
    // Xinc = dX / (float)steps;
    // Yinc = dY / (float)steps;
    // printf("dX = %f, dY = %f, Steps = %f, Xinc = %f, Yinc = %f\n.", dX, dY, steps, Xinc, Yinc);

    glBegin(GL_POINTS);
    X1 = 1, Y1 = 1, X2 = 1, Y2 = -1;
    X = 1;
    for(Y = Y1; Y >= Y2; Y = Y - 0.01)
    {
        glVertex2f(X, Y);
    }
    X1 = 1, Y1 = -1, X2 = -1, Y2 = -1;
    Y = -1;
    for(X = X1; X >= X2; X = X - 0.01)
    {
        glVertex2f(X, Y);
    }
    X1 = -1, Y1 = -1, X2 = -1, Y2 = 1;
    X = -1;
    for(Y = Y1; Y <= Y2; Y = Y + 0.01)
    {
        glVertex2f(X, Y);
    }
    X1 = -1, Y1 = 1, X2 = 1, Y2 = 1;
    Y = 1;
    for(X = X1; X <= X2; X = X + 0.01)
    {
        glVertex2f(X, Y);
    }
    glEnd();

    // outer square
    glBegin(GL_POINTS);
    X1 = 2, Y1 = 2, X2 = 2, Y2 = -2;
    X = 2;
    for(Y = Y1; Y >= Y2; Y = Y - 0.01)
    {
        glVertex2f(X, Y);
    }
    X1 = 2, Y1 = -2, X2 = -2, Y2 = -2;
    Y = -2;
    for(X = X1; X >= X2; X = X - 0.01)
    {
        glVertex2f(X, Y);
    }
    X1 = -2, Y1 = -2, X2 = -2, Y2 = 2;
    X = -2;
    for(Y = Y1; Y <= Y2; Y = Y + 0.01)
    {
        glVertex2f(X, Y);
    }
    X1 = -2, Y1 = 2, X2 = 2, Y2 = 2;
    Y = 2;
    for(X = X1; X <= X2; X = X + 0.01)
    {
        glVertex2f(X, Y);
    }
    glEnd();
    // tilted quadrilateral
    glBegin(GL_POINTS);
    X1 = 0, Y1 = 2, X2 = 2, Y2 = 0;
    // X = 0, Y = 2;
    for(X = X1; X <= X2; X = X + 0.01)
    {
        Y = -X + 2;
        glVertex2f(X, Y);
    }
    glEnd();
    glBegin(GL_POINTS);
    X1 = 2, Y1 = 0, X2 = 0, Y2 = -2;
    
    for(X = X1; X >= X2; X = X - 0.01)
    {
        Y = X - 2;
        glVertex2f(X, Y);
    }
    glEnd();
    glBegin(GL_POINTS);
    X1 = 0, Y1 = -2, X2 = -2, Y2 = 0;
    // X = 0, Y = 2;
    for(X = X1; X >= X2; X = X - 0.01)
    {
        Y = -X - 2;
        glVertex2f(X, Y);
    }
    glEnd();
    glBegin(GL_POINTS);
    X1 = -2, Y1 = 0, X2 = 0, Y2 = 2;
    
    for(X = X1; X <= X2; X = X + 0.01)
    {
        Y = X + 2;
        glVertex2f(X, Y);
    }
    glEnd();
    glFlush();
}
int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(1000, 1000);
glutInitWindowPosition(0, 0);

// Giving name to window
glutCreateWindow("Figure");
glutDisplayFunc(display);
glutMainLoop();
}