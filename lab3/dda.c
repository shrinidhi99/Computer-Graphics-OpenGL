#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#define m 2

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
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
    for (i = 0; i <= steps; i = i + 0.001)
    {
        glVertex2f(0.001*X, 0.001*Y);
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

// C program to demonstrate
// drawing a circle using
// OpenGL
// #include<stdio.h>
// #include<GL/glut.h>
// #include<math.h>
// #define pi 3.142857

// void display ()
// {
//     glClear(GL_COLOR_BUFFER_BIT);
//     glBegin(GL_POINTS);
//     float x, y, i;

//     // iterate y up to 2*pi, i.e., 360 degree
//     // with small increment in angle as
//     // glVertex2i just draws a point on specified co-ordinate
//     for ( i = 0; i < (2 * pi); i += 0.001)
//     {
//         // let 200 is radius of circle and as,
//         // circle is defined as x=r*cos(i) and y=r*sin(i)
//         x = 0.1 + i;
//         y = 0.1 + i;

//         glVertex2f(x, y);
//     }
//     glEnd();
//     glFlush();
// }

// int main (int argc, char** argv)
// {
//     glutInit(&argc, argv);
//     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

//     // giving window size in X- and Y- direction
//     glutInitWindowSize(500, 500);
//     glutInitWindowPosition(0, 0);

//     // Giving name to window
//     glutCreateWindow("Circle Drawing");

//     glutDisplayFunc(display);
//     glutMainLoop();
// }