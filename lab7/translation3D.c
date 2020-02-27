#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#define pi 0.0174533

void rotateY(float P[], float angleY)
{
    P[0] = (float)((double)P[2] * sin(angleY * pi) + (double)P[0] * cos(angleY * pi));
    P[1] = P[1];
    P[2] = (float)((double)P[2] * cos(angleY * pi) - (double)P[0] * sin(angleY * pi));
}

void translate(float P[], float Tx, float Ty, float Tz)
{
    P[0] = P[0] + Tx;
    P[1] = P[1] + Ty;
    P[2] = P[2] + Tz;
}
void glPlot(float A[])
{
    glVertex3f(A[0], A[1], A[2]);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    float A[] = {0.1f, 0.1f, 0.1f};
    float B[] = {0.1f, 0.1f, -0.1f};
    float C[] = {-0.1f, 0.1f, -0.1f};
    float D[] = {-0.1f, 0.1f, 0.1f};
    float E[] = {0.1f, -0.1f, 0.1f};
    float F[] = {0.1f, -0.1f, -0.1f};
    float G[] = {-0.1f, -0.1f, -0.1f};
    float H[] = {-0.1f, -0.1f, 0.1f};

    float Tx, Ty, Tz;
    float angleY = 45;

    // printf("Enter translation factor (Tx, Ty, Tz): ");
    // scanf("%d %d %d", &Tx, &Ty, &Tz);

    Tx = 0.5;
    Ty = 0.5;
    Tz = -0.5;

    // rotate the cube before showing the original and the translated one
    rotateY(A, angleY);
    rotateY(B, angleY);
    rotateY(C, angleY);
    rotateY(D, angleY);
    rotateY(E, angleY);
    rotateY(F, angleY);
    rotateY(G, angleY);
    rotateY(H, angleY);

    // draw a cube with some fixed vertices and later translate it
    glBegin(GL_QUADS); // top
    glColor3ub(255, 255, 25);
    glPlot(A);
    glPlot(B);
    glPlot(C);
    glPlot(D);
    glEnd();

    glBegin(GL_QUADS); // bottom
    glColor3ub(255, 25, 255);
    glPlot(E);
    glPlot(F);
    glPlot(G);
    glPlot(H);
    glEnd();

    glBegin(GL_QUADS); // right
    glColor3ub(25, 255, 255);
    glPlot(A);
    glPlot(B);
    glPlot(F);
    glPlot(E);
    glEnd();

    glBegin(GL_QUADS); // rear
    glColor3ub(55, 255, 255);
    glPlot(B);
    glPlot(C);
    glPlot(G);
    glPlot(F);
    glEnd();

    glBegin(GL_QUADS); // left
    glColor3ub(255, 55, 255);
    glPlot(C);
    glPlot(D);
    glPlot(H);
    glPlot(G);
    glEnd();

    glBegin(GL_QUADS); // front
    glColor3ub(255, 255, 55);
    glPlot(A);
    glPlot(D);
    glPlot(H);
    glPlot(E);
    glEnd();

    translate(A, Tx, Ty, Tz);
    translate(B, Tx, Ty, Tz);
    translate(C, Tx, Ty, Tz);
    translate(D, Tx, Ty, Tz);
    translate(E, Tx, Ty, Tz);
    translate(F, Tx, Ty, Tz);
    translate(G, Tx, Ty, Tz);
    translate(H, Tx, Ty, Tz);

    glBegin(GL_QUADS); // top
    glColor3ub(255, 255, 25);
    glPlot(A);
    glPlot(B);
    glPlot(C);
    glPlot(D);
    glEnd();

    glBegin(GL_QUADS); // bottom
    glColor3ub(255, 25, 255);
    glPlot(E);
    glPlot(F);
    glPlot(G);
    glPlot(H);
    glEnd();

    glBegin(GL_QUADS); // right
    glColor3ub(25, 255, 255);
    glPlot(A);
    glPlot(B);
    glPlot(F);
    glPlot(E);
    glEnd();

    glBegin(GL_QUADS); // rear
    glColor3ub(55, 255, 255);
    glPlot(B);
    glPlot(C);
    glPlot(G);
    glPlot(F);
    glEnd();

    glBegin(GL_QUADS); // left
    glColor3ub(255, 55, 255);
    glPlot(C);
    glPlot(D);
    glPlot(H);
    glPlot(G);
    glEnd();

    glBegin(GL_QUADS); // front
    glColor3ub(255, 255, 55);
    glPlot(A);
    glPlot(D);
    glPlot(H);
    glPlot(E);
    glEnd();

    glFlush();
}

void Init()
{
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(800, 800);
    glutCreateWindow("3D translation of a cube");
    Init();
    glutDisplayFunc(display);
    glutMainLoop();
}