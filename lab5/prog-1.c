#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>

int X, Y, r, p = 0, P = 0;

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

void MyKeyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'I':
        glPushMatrix();
        X = x - 320;
        Y = y - 320;
        r = 70 + p;
        printf("X = %d, Y = %d\n", X, Y);
        draw_circle();
        r = 50 + p;
        draw_circle();
        glEnd();
        p = p + 5;
        glPopMatrix();
        break;
    case 'i':
        glPushMatrix();
        X = x - 320;
        Y = y - 320;
        r = 70 + p;
        printf("X = %d, Y = %d\n", X, Y);
        draw_circle();
        r = 50 + p;
        draw_circle();
        glEnd();
        p = p + 5;
        glPopMatrix();
        break;
    case 'D':
        glPushMatrix();
        X = x - 320;
        Y = y - 320;
        r = 15 - P;
        printf("X = %d, Y = %d\n", X, Y);
        draw_circle();
        r = 25 - P;
        draw_circle();
        glEnd();
        P = P - 1;
        glPopMatrix();
        break;
    case 'd':
        glPushMatrix();
        X = x - 320;
        Y = y - 320;
        r = 15 - P;
        printf("X = %d, Y = %d\n", X, Y);
        draw_circle();
        r = 10 - P;
        draw_circle();
        glEnd();
        p = p - 1;
        glPopMatrix();
        break;
    case 'C':
        glClear(GL_COLOR_BUFFER_BIT);
        break;
    case 'c':
        glClear(GL_COLOR_BUFFER_BIT);
        break;
    default:
        break;
    }
}

void MyMouse(int button, int state, int x, int y)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    // glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        X = x - 320;
        Y = y - 320;
        r = 50;
        printf("X = %d, Y = %d\n", X, Y);
        draw_circle();
        r = 30;
        draw_circle();
        glEnd();

        // left wheel
        // X = x;
        // Y = y;
        // r = 10;
        // // iR = 10;
        // draw_circle();
        // glEnd();
        // X = x;
        // Y = y;
        // r = 40;
        // draw_circle();
        // glEnd();
        // glBegin(GL_POINTS);
        // int i;
        // for (i = 10; i <= 40; i++)
        // {
        //     glVertex2i(i, 0);
        //     glVertex2i(0, i);
        //     glVertex2i(-i, 0);
        //     glVertex2i(0, -i);
        // }
        // glEnd();
        // // glPopMatrix();

        // glBegin(GL_POINTS);
        // for (i = -320; i <= 320; i++)
        //     glVertex2i(i, -40);
        // glEnd();
        glFlush();
        break;
    case GLUT_RIGHT_BUTTON:
        exit(0);
        break;
    default:
        break;
    }
    glFlush(); // Render now
}

void circle()
{
    // printf("Enter centre (x,y) and radius of the circle\n");
    // scanf("%d%d%d", &X, &Y, &r);
    glClear(GL_COLOR_BUFFER_BIT);
    // draw_circle();

    glFlush();
}

void idle()
{
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(640, 640);
    glutCreateWindow("Program 1");
    gluOrtho2D(-320, 320, -320, 320);
    glutDisplayFunc(circle);
    glutMouseFunc(MyMouse);
    glutKeyboardFunc(MyKeyboard);
    // glutIdleFunc(idle);
    glutMainLoop();
}