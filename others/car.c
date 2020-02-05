#include <GL/glut.h>
#include <stdio.h>
// #include <graphics.h>

float yrot = 0.0f;
float yLocation = 0.0f;
float movingB = 0;
void myInit()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-100, 100, -100, 100);
}

void draw_pixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void draw_circle(int xc, int yc, int x, int y)
{
    draw_pixel(xc + x, yc + y);
    draw_pixel(xc - x, yc + y);
    draw_pixel(xc + x, yc - y);
    draw_pixel(xc - x, yc - y);
    draw_pixel(xc + y, yc - x);
    draw_pixel(xc + y, yc + x);
    draw_pixel(xc - y, yc - x);
    draw_pixel(xc - y, yc + x);
}

void draw_semicircle(int xc, int yc, int x, int y)
{
    draw_pixel(xc + x, yc + y);
    draw_pixel(xc - x, yc + y);
    draw_pixel(xc + y, yc + x);
    draw_pixel(xc - y, yc + x);
}

void circle(int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;
    int i = 100;
    while (y >= x)
    {
        x++;
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
        {
            d = d + 4 * x + 6;
        }
        draw_circle(xc, yc, x, y);
    }
}

void linex(int x1, int x2, int y1, int y2)
{
    int dx, dy, i, e;
    int incx, incy, inc1, inc2;
    int x, y;

    dx = x2 - x1;
    dy = y2 - y1;

    if (dx < 0)
        dx = -dx;
    if (dy < 0)
        dy = -dy;
    incx = 1;
    if (x2 < x1)
        incx = -1;
    incy = 1;
    if (y2 < y1)
        incy = -1;
    x = x1;
    y = y1;
    if (dx > dy)
    {
        draw_pixel(x, y);
        e = 2 * dy - dx;
        inc1 = 2 * (dy - dx);
        inc2 = 2 * dy;
        for (i = 0; i < dx; i++)
        {
            if (e >= 0)
            {
                y += incy;
                e += inc1;
            }
            else
                e += inc2;
            x += incx;
            draw_pixel(x, y);
        }
    }
    else
    {
        draw_pixel(x, y);
        e = 2 * dx - dy;
        inc1 = 2 * (dx - dy);
        inc2 = 2 * dx;
        for (i = 0; i < dy; i++)
        {
            if (e >= 0)
            {
                x += incx;
                e += inc1;
            }
            else
                e += inc2;
            y += incy;
            draw_pixel(x, y);
        }
    }
}

void semicircle(int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;
    int i = 100;
    while (y >= x)
    {
        x++;
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
        {
            d = d + 4 * x + 6;
        }
        draw_semicircle(xc, yc, x, y);
    }
}

void myDisplay()
{

    glPushMatrix();
    glTranslatef(-20, 0, 0);
    glTranslatef(yLocation, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 0.0f, 1.0f);
    glTranslatef(0, 0, 0);
    circle(0, 0, 10);
    circle(0, 0, 5);
    linex(5 / 1.414, 10 / 1.414, 5 / 1.414, 10 / 1.414);
    linex(-(5 / 1.414), -(10 / 1.414), 5 / 1.414, 10 / 1.414);
    linex(5 / 1.414, 10 / 1.414, -(5 / 1.414), -(10 / 1.414));
    linex(-(5 / 1.414), -(10 / 1.414), -(5 / 1.414), -(10 / 1.414));
    linex(0, 0, 5, 10);
    linex(0, 0, -5, -10);
    linex(-5, -10, 0, 0);
    linex(5, 10, 0, 0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(yLocation, 0.0f, 0.0f);
    glTranslatef(20, 0, 0);
    glRotatef(yrot, 0.0f, 0.0f, 1.0f);
    glTranslatef(0, 0, 0);
    circle(0, 0, 10);
    circle(0, 0, 5);
    linex(5 / 1.414, 10 / 1.414, 5 / 1.414, 10 / 1.414);
    linex(-(5 / 1.414), -(10 / 1.414), 5 / 1.414, 10 / 1.414);
    linex(5 / 1.414, 10 / 1.414, -(5 / 1.414), -(10 / 1.414));
    linex(-(5 / 1.414), -(10 / 1.414), -(5 / 1.414), -(10 / 1.414));
    linex(0, 0, 5, 10);
    linex(0, 0, -5, -10);
    linex(-5, -10, 0, 0);
    linex(5, 10, 0, 0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(yLocation, 0.0f, 0.0f);
    glTranslatef(-10, 0, 0);
    linex(0, 20, 0, 0);
    linex(0, 0, 0, 10);
    linex(20, 20, 0, 10);
    semicircle(30, 10, 10);
    semicircle(-10, 10, 10);
    linex(-20, -30, 10, 10);
    linex(40, 50, 10, 10);
    linex(50, 50, 10, 40);
    linex(-30, -30, 10, 40);
    linex(-30, -10, 40, 40);
    linex(50, 30, 40, 40);
    linex(-10, -10, 60, 40);
    linex(30, 30, 60, 40);
    linex(30, -10, 60, 60);
    glPopMatrix();
    linex(-100, 100, -10, -10);
    glFlush();
}
void reshape(int width, int height)
{
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

void rotate()
{
    yrot -= 1.0;
    if (yrot >= 360)
    {
        yrot -= 360;
    }

    if (yLocation >= 100)
    {
        movingB = 1;
    }
    else if (yLocation <= -100)
    {
        movingB = 0;
    }
    if (movingB == 0)
    {
        yLocation += 1;
    }
    else
    {
        yLocation--;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glutPostRedisplay();
    glutTimerFunc(25, rotate, 0);
    glFlush();
}

void main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham's circle Drawing");
    myInit();
    glutDisplayFunc(myDisplay);
    glutTimerFunc(25, rotate, 0);
    glutMainLoop();
}