#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

int Xmin = 10, Ymin = 10, Xmax = 50, Ymax = 50;

int X, Y, r;

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

void Bresenham(int x11, int y111, int x12, int y112)
{
    int dx = x12 - x11;
    int dy = y112 - y111;

    int p = 2 * dy - dx;

    int X = x11, Y = y111;
    int i;
    glBegin(GL_POINTS);
    for (; X <= x12; X++)
    {
        glVertex2d(X, Y);
        if (p >= 0)
        {
            Y++;
            p = p + 2 * dy - 2 * dx;
        }
        else
        {
            p = p + 2 * dy;
        }
    }
    glEnd();
}

int computeCode(int x, int y)
{
    int code = 0;
    if (x < Xmin)
        code = code | 1;
    else if (x > Xmax)
        code = code | 2;
    if (y < Ymin)
        code = code | 4;
    else if (y > Ymax)
        code = code | 8;
    return code;
}

void clip(int x11, int y11, int x12, int y12)
{
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2d(x11, y11);
    glVertex2d(x12, y12);
    glEnd();
    // Bresenham(Xmin, Ymin, Xmax, Ymin);
    glBegin(GL_LINES);
    glVertex2d(Xmin, Ymin);
    glVertex2d(Xmax, Ymin);
    glEnd();
    // Bresenham(Xmin, Ymin, Xmin, Ymax);
    glBegin(GL_LINES);
    glVertex2d(Xmin, Ymin);
    glVertex2d(Xmin, Ymax);
    glEnd();
    // Bresenham(Xmax, Ymin, Xmax, Ymax);
    glBegin(GL_LINES);
    glVertex2d(Xmax, Ymin);
    glVertex2d(Xmax, Ymax);
    glEnd();
    // Bresenham(Xmax, Ymax, Xmin, Ymax);
    glBegin(GL_LINES);
    glVertex2d(Xmin, Ymax);
    glVertex2d(Xmax, Ymax);
    glEnd();
    int code1 = computeCode(x11, y11);
    int code2 = computeCode(x12, y12);
    // bool accept = false;
    int accept = 0;
    while (1)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            accept = 1;
            glColor3ub(255, 0, 0);
            glBegin(GL_LINES);
            glVertex2d(x11, y11);
            glVertex2d(x12, y12);
            glEnd();
            break;
        }
        else if (code1 & code2)
        {
            break;
        }
        else
        {
            int code_out;
            int x, y;
            if (code1 != 0)
            {
                code_out = code1;
            }
            else
            {
                code_out = code2;
            }

            if (code_out & 8)
            {
                x = x11 + (x12 - x11) * (Ymax - y11) / (y12 - y11);
                y = Ymax;
            }

            else if (code_out & 4)
            {
                x = x11 + (x12 - x11) * (Ymin - y11) / (y12 - y11);
                y = Ymin;
            }

            else if (code_out & 2)
            {
                y = y11 + (y12 - y11) * (Xmax - x11) / (x12 - x11);
                x = Xmax;
            }

            else if (code_out & 1)
            {
                y = y11 + (y12 - y11) * (Xmin - x11) / (x12 - x11);
                x = Xmin;
            }

            if (code_out == code1)
            {
                x11 = x;
                y11 = y;
                code1 = computeCode(x11, y11);
            }

            else
            {
                x12 = x;
                y12 = y;
                code2 = computeCode(x12, y12);
            }
        }
    }
}

void circle(int x1, int y1, int x2, int y2)
{
    float m = (float)(y2 - y1) / (float)(x2 - x1);
    float c = (float)(y1)-m * (float)(x1);
    float D = (2 * m * c) * (2 * m * c) - 4 * (1 + m * m) * (c * c - r * r);
    float X, X1;
    float Y, Y1;

    if (D > 0)
    {
        // two points of intersection
        X = (-2 * m * c + sqrt((double)(D))) / (2 * (1 + m * m));
        X1 = (-2 * m * c - sqrt((double)(D))) / (2 * (1 + m * m));

        Y = m * X + c;
        Y1 = m * X1 + c;

        glBegin(GL_LINES);
        glVertex2f(X, Y);
        glVertex2f(X1, Y1);
        glEnd();
    }
    if (D == 0)
    {
        // single point of intersection
        glBegin(GL_POINTS);
        X = -(m * c) / (1 + m * m);
        Y = m * X + c;
        glVertex2f(1, 1);
        glEnd();
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    X = 0;
    Y = 0;
    r = 50;
    draw_circle();

    int x11, y11, x12, y12;
    int x21, y21, x22, y22;
    int x31, y31, x32, y32;

    // triangle completely inside
    x11 = 30, y11 = 15;
    x12 = 45, y12 = 15;

    circle(x11, y11, x12, y12);

    x21 = 45, y21 = 15;
    x22 = 35, y22 = 30;

    circle(x21, y21, x22, y22);

    x31 = 35, y31 = 30;
    x32 = 30, y32 = 15;

    circle(x31, y31, x32, y32);

    // // triangle partially inside
    // x11 = 0, y11 = 20;
    // x12 = 20, y12 = 20;

    // circle(x11, y11, x12, y12);

    // x21 = 20, y21 = 20;
    // x22 = 15, y22 = 60;

    // circle(x21, y21, x22, y22);

    // x31 = 15, y31 = 60;
    // x32 = 0, y32 = 20;

    // circle(x31, y31, x32, y32);

    // // triangle completely outside
    // x11 = 30, y11 = -30;
    // x12 = 60, y12 = -30;

    // circle(x11, y11, x12, y12);

    // x21 = 60, y21 = -30;
    // x22 = 40, y22 = 0;

    // circle(x21, y21, x22, y22);

    // x31 = 40, y31 = 0;
    // x32 = 30, y32 = -30;

    // circle(x31, y31, x32, y32);

    glFlush();
}

void Init()
{
    glClearColor(1.0, 1.0, 1.0, 0);
    glColor3f(0.0, 0.0, 0.0);
    gluOrtho2D(-320, 320, -320, 320);
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(640, 640);
    glutCreateWindow("sutherland");
    Init();
    glutDisplayFunc(display);
    glutMainLoop();
}