#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

int Xmin = 10, Ymin = 10, Xmax = 50, Ymax = 50;

void Bresenham(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int p = 2 * dy - dx;

    int X = x1, Y = y1;
    int i;
    glBegin(GL_POINTS);
    for (; X <= x2; X++)
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
    int x1, y1, x2, y2;
    x1 = 20, y1 = 60;
    x2 = 60, y2 = 60;
    // printf("Enter Xmin, Ymin, Xmax, Ymax\n");
    // scanf("%d%d%d%d", &Xmin, &Ymin, &Xmax, &Ymax);
    // printf("Enter line coordinates (x1,y1), (x2,y2):\n");
    // scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    // Bresenham(x1, y1, x2, y2);
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2d(x1, y1);
    glVertex2d(x2, y2);
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
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    // bool accept = false;
    int accept = 0;
    while (1)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            accept = 1;
            glColor3ub(255, 0, 0);
            glBegin(GL_LINES);
            glVertex2d(x1, y1);
            glVertex2d(x2, y2);
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
                x = x1 + (x2 - x1) * (Ymax - y1) / (y2 - y1);
                y = Ymax;
            }

            else if (code_out & 4)
            {
                x = x1 + (x2 - x1) * (Ymin - y1) / (y2 - y1);
                y = Ymin;
            }

            else if (code_out & 2)
            {
                y = y1 + (y2 - y1) * (Xmax - x1) / (x2 - x1);
                x = Xmax;
            }

            else if (code_out & 1)
            {
                y = y1 + (y2 - y1) * (Xmin - x1) / (x2 - x1);
                x = Xmin;
            }

            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }

            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
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