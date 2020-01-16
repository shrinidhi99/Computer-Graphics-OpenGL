#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#define m 2

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-10, 10, -10, 10);
    float i, X1, Y1, X2, Y2, dX, dY, steps, X, Y;
    float Xinc, Yinc;
    X1 = 2, Y1 = 1, X2 = 7, Y2 = 6;
    X = X1;
    Y = Y1;
    dX = X2 - X1;
    dY = Y2 - Y1;
    // choosing the number of steps
    steps = abs(dX) > abs(dY) ? dX : dY;
    // calculate the increment in x and y for each steps
    Xinc = dX / (float)steps;
    Yinc = dY / (float)steps;
    printf("dX = %f, dY = %f, Steps = %f, Xinc = %f, Yinc = %f\n.", dX, dY, steps, Xinc, Yinc);

    glBegin(GL_POINTS);
    for (i = 0; i <= steps; i = i + 1)
    {
        glVertex2f(X, Y);
        X = X + Xinc;
        Y = Y + Yinc;
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
    glutCreateWindow("Drawing line using DDA");

    glutDisplayFunc(display);
    glutMainLoop();
}