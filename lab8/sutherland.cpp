#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

int Xmin = 10, Ymin = 10, Xmax = 50, Ymax = 50;

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

void chessboard()
{
    glClear(GL_COLOR_BUFFER_BIT);
    int x11, y11, x12, y12;
    x11 = 20, y11 = 60;
    x12 = 60, y12 = 60;
    // printf("Enter Xmin, Ymin, Xmax, Ymax\n");
    // scanf("%d%d%d%d", &Xmin, &Ymin, &Xmax, &Ymax);
    // printf("Enter line coordinates (x11,y111), (x12,y112):\n");
    // scanf("%d%d%d%d", &x11, &y111, &x12, &y112);
    // Bresenham(x11, y111, x12, y112);
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

    // if (accept)
    // {
    //     printf("Line accepted\n");
    // }
    // else
    // {
    //     printf("Line rejected\n");
    // }
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
    glutDisplayFunc(chessboard);
    glutMainLoop();
}