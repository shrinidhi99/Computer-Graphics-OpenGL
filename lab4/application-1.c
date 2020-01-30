#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

int X, Y, iR, oR;

void draw_circle(int r)
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

void circle()
{
    // printf("Enter centre (x,y) and radius of the circle\n");
    // scanf("%d%d%d", &X, &Y, &r);
    X = 0;
    Y = 0;
    iR = 30;
    glClear(GL_COLOR_BUFFER_BIT);
    draw_circle(iR);
    glEnd();
    X = 0;
    Y = 0;
    oR = 80;
    draw_circle(oR);
    glEnd();
    glBegin(GL_LINE);
    
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(640, 640);
    glutCreateWindow("Rotating Wheel");
    gluOrtho2D(-320, 320, -320, 320);
    glutDisplayFunc(circle);
    glutMainLoop();
}