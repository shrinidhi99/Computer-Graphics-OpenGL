#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>
#define pi 3.142857

GLfloat angle = 0.0f;
int X, Y, r, p = 0, P = 0;
int i = 0;
GLfloat speed = 0;
void android();
void face();
void body();
void hand();
void blank();
void draw_circle()
{

    glBegin(GL_POINTS);
    int x = 0, y = r;
    int p = 3 - 2 * r;
    while (x < y)
    {
        x++;
        if (p < 0)
            p = p + 4 * x + 6;
        else
        {
            p = p + 4 * (x - y) + 10;
            y--;
        }

        glVertex2i(x + X, y + Y);
        glVertex2i(y + X, x + Y);
        glVertex2i(x + X, -y + Y);
        glVertex2i(y + X, -x + Y);
        glVertex2i(-x + X, -y + Y);
        glVertex2i(-y + X, -x + Y);
        glVertex2i(-x + X, y + Y);
        glVertex2i(-y + X, x + Y);
    }
}

void hand()
{
    glBegin(GL_LINES);
    glVertex2i(50, 40);
    glVertex2i(50, -40);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(50, 40);
    glVertex2i(70, 40);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(70, 40);
    glVertex2i(70, -40);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(70, -40);
    glVertex2i(50, -40);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(-50, 40);
    glVertex2i(-50, -40);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(-50, 40);
    glVertex2i(-70, 40);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(-70, 40);
    glVertex2i(-70, -40);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(-70, -40);
    glVertex2i(-50, -40);
    glEnd();
}
void body()
{
    glBegin(GL_LINES);
    glVertex2i(40, 40);
    glVertex2i(40, -40);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(-40, 40);
    glVertex2i(-40, -40);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(40, 40);
    glVertex2i(-40, 40);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(40, -40);
    glVertex2i(-40, -40);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(10, -60);
    glVertex2i(20, -60);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(10, -40);
    glVertex2i(10, -60);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(20, -40);
    glVertex2i(20, -60);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(-10, -60);
    glVertex2i(-20, -60);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(-10, -40);
    glVertex2i(-10, -60);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(-20, -40);
    glVertex2i(-20, -60);
    glEnd();
}
void face()
{
    glBegin(GL_POINTS);
    float x, y, i;

    for (i = 0; i < (pi); i += 0.001)
    {
        x = 40 * cos(i);
        y = 40 * sin(i) + 50;
        glVertex2f(x, y);
    }
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(-40, 50);
    glVertex2i(40, 50);
    glEnd();

    glBegin(GL_POINTS);
    for (i = 0; i < 2 * (pi); i += 0.001)
    {
        x = 5 * cos(i) + 15;
        y = 5 * sin(i) + 70;
        glVertex2f(x, y);
    }
    glEnd();

    glBegin(GL_POINTS);
    for (i = 0; i < 2 * (pi); i += 0.001)
    {
        x = 5 * cos(i) - 15;
        y = 5 * sin(i) + 70;
        glVertex2f(x, y);
    }
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(15, 90);
    glVertex2i(20, 110);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(-15, 90);
    glVertex2i(-20, 110);
    glEnd();
}
void android()
{
    // printf("Enter centre (x,y) and radius of the circle\n");
    // scanf("%d%d%d", &X, &Y, &r);
    glClear(GL_COLOR_BUFFER_BIT);
    // draw_circle();

    // face
    face();

    // body
    body();

    // hands
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    glRotatef(angle, 0, 0, 1);
    hand();
    glPopMatrix();
    angle += 0.1;

    glFlush();
}
void blank()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}
void idle()
{
    glutPostRedisplay();
}
GLuint view;
void MyKeyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'r':
        // printf("R\n");
        // glutPostWindowRedisplay(view);
        // glutPostRedisplay();
        glPushMatrix();
        face();
        body();
        glTranslatef(0.0, 0.0, 0.0);
        glRotatef(angle, 0, 0, 1);
        // glClear(GL_COLOR_BUFFER_BIT);
        hand();
        glPopMatrix();
        angle += 0.1;
        break;
    case 's':
        printf("Scale down\n");
        glPushMatrix();
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0, 0, 0, 0);
        blank();
        android();
        glFlush();
        glPopMatrix();
        break;
    case 'i':
        printf("Scale up\n");
        glPushMatrix();
        glScalef(2, 2, 0);
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0, 0, 0, 0);
        blank();
        android();
        glFlush();
        glPopMatrix();
        break;
    case 'd':
        glPushMatrix();
        glScalef(0.5, 0.5, 0);
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0, 0, 0, 0);
        blank();
        android();
        glFlush();
        glPopMatrix();
        break;
    case 't':
        speed = 0;
        glPushMatrix();
        glTranslatef(speed++, 0, 0);
        android();
        glPopMatrix();
        break;
    case 'h':
        speed = 0;
        glPushMatrix();
        glTranslatef(speed--, 0, 0);
        android();
        glPopMatrix();
        break;
    case 'c':
        printf("Clear\n");
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0, 0, 0, 0);
        blank();
        glFlush();
        break;
    case 'e':
        printf("Exit");
        exit(0);
        break;
    default:
        break;
    }
    // glutPostRedisplay();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(640, 640);
    glutCreateWindow("Program 1");
    gluOrtho2D(-320, 320, -320, 320);
    glutDisplayFunc(android);
    glutKeyboardFunc(MyKeyboard);
    glutIdleFunc(idle);
    glutMainLoop();
}