#include <stdio.h>
    #include <math.h>
#include <GL/glut.h>
#define pi 0.0174533

void rotateX(float P[], float angleX)
{
    P[0] = P[0];
    P[1] = (float)((double)P[1] * cos(angleX * pi) - (double)P[2] * sin(angleX * pi));
    P[2] = (float)((double)P[1] * sin(angleX * pi) + (double)P[2] * cos(angleX * pi));
}

void rotateY(float P[], float angleY)
{
    P[0] = (float)((double)P[2] * sin(angleY * pi) + (double)P[0] * cos(angleY * pi));
    P[1] = P[1];
    P[2] = (float)((double)P[2] * cos(angleY * pi) - (double)P[0] * sin(angleY * pi));
}

void rotateZ(float P[], float angleZ)
{
    P[0] = (float)((double)P[0] * cos(angleZ * pi) - (double)P[1] * sin(angleZ * pi));
    P[1] = (float)((double)P[0] * sin(angleZ * pi) + (double)P[1] * cos(angleZ * pi));
    P[2] = P[2];
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

    float angleX, angleY, angleZ;
    // printf("Enter : ");
    // scanf("%f %f %f", &angleX, &angleY, &angleZ);

    angleX = 45;
    angleY = 45;
    angleZ = 45;

    // draw a cube with some fixed vertices and later rotate it
    // glBegin(GL_QUADS); // top
    // glColor3ub(255, 255, 255);
    // glPlot(A);
    // glPlot(B);
    // glPlot(C);
    // glPlot(D);
    // glEnd();

    // glBegin(GL_QUADS); // bottom
    // glColor3ub(255, 255, 255);
    // glPlot(E);
    // glPlot(F);
    // glPlot(G);
    // glPlot(H);
    // glEnd();

    // glBegin(GL_QUADS); // right
    // glColor3ub(255, 255, 255);
    // glPlot(A);
    // glPlot(B);
    // glPlot(F);
    // glPlot(E);
    // glEnd();

    // glBegin(GL_QUADS); // rear
    // glColor3ub(255, 255, 255);
    // glPlot(B);
    // glPlot(C);
    // glPlot(G);
    // glPlot(F);
    // glEnd();

    // glBegin(GL_QUADS); // left
    // glColor3ub(255, 255, 255);
    // glPlot(C);
    // glPlot(D);
    // glPlot(H);
    // glPlot(G);
    // glEnd();

    // glBegin(GL_QUADS); // front
    // glColor3ub(255, 255, 255);
    // glPlot(A);
    // glPlot(D);
    // glPlot(H);
    // glPlot(E);
    // glEnd();

    rotateX(A, angleX);
    rotateX(B, angleX);
    rotateX(C, angleX);
    rotateX(D, angleX);
    rotateX(E, angleX);
    rotateX(F, angleX);
    rotateX(G, angleX);
    rotateX(H, angleX);

    rotateY(A, angleY);
    rotateY(B, angleY);
    rotateY(C, angleY);
    rotateY(D, angleY);
    rotateY(E, angleY);
    rotateY(F, angleY);
    rotateY(G, angleY);
    rotateY(H, angleY);

    rotateZ(A, angleZ);
    printf("A: (%f ,%f ,%f)\n", A[0], A[1], A[2]);
    rotateZ(B, angleZ);
    printf("B: (%f ,%f ,%f)\n", B[0], B[1], B[2]);
    rotateZ(C, angleZ);
    printf("C: (%f ,%f ,%f)\n", C[0], C[1], C[2]);
    rotateZ(D, angleZ);
    printf("D: (%f ,%f ,%f)\n", D[0], D[1], D[2]);
    rotateZ(E, angleZ);
    printf("E: (%f ,%f ,%f)\n", E[0], E[1], E[2]);
    rotateZ(F, angleZ);
    printf("F: (%f ,%f ,%f)\n", F[0], F[1], F[2]);
    rotateZ(G, angleZ);
    printf("G: (%f ,%f ,%f)\n", G[0], G[1], G[2]);
    rotateZ(H, angleZ);
    printf("H: (%f ,%f ,%f)\n", H[0], H[1], H[2]);

    glBegin(GL_QUADS); // top
    glColor3ub(0, 0, 255);
    glPlot(A);
    glPlot(B);
    glPlot(C);
    glPlot(D);
    glEnd();

    glBegin(GL_QUADS); // bottom
    glColor3ub(0, 255, 0);
    glPlot(E);
    glPlot(F);
    glPlot(G);
    glPlot(H);
    glEnd();

    glBegin(GL_QUADS); // right
    glColor3ub(255, 0, 0);
    glPlot(A);
    glPlot(B);
    glPlot(F);
    glPlot(E);
    glEnd();

    glBegin(GL_QUADS); // rear
    glColor3ub(100, 100, 100);
    glPlot(B);
    glPlot(C);
    glPlot(G);
    glPlot(F);
    glEnd();

    glBegin(GL_QUADS); // left
    glColor3ub(150, 110, 55);
    glPlot(C);
    glPlot(D);
    glPlot(H);
    glPlot(G);
    glEnd();

    glBegin(GL_QUADS); // front
    glColor3ub(30, 110, 25);
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