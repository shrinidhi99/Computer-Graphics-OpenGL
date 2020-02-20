#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

void reflectX(int *x, int *y)
{
    *x = *x;
    *y = -*y;
}

void reflectY(int *x, int *y)
{
    *x = -*x;
    *y = *y;
}

// bresenham's line drawing
void draw_line(int x1, int y1, int x2, int y2)
{
    // int dx = x2 - x1;
    // int dy = y2 - y1;
    // int p = 2 * dy - dx;
    // int X = x1, Y = y1;
    // int i;
    // glBegin(GL_POINTS);
    // for (; X <= x2; X++)
    // {
    //     glVertex2d(X, Y);
    //     if (p >= 0)
    //     {
    //         Y++;
    //         p = p + 2 * dy - 2 * dx;
    //     }
    //     else
    //     {
    //         p = p + 2 * dy;
    //     }
    // }
    glBegin(GL_LINES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glEnd();
}

// bresenham's circle
void draw_circle(int X, int Y, int r)
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
        glVertex2d(x + X, y + Y);
        glVertex2d(y + X, x + Y);
        glVertex2d(x + X, -y + Y);
        glVertex2d(y + X, -x + Y);
        glVertex2d(-x + X, -y + Y);
        glVertex2d(-y + X, -x + Y);
        glVertex2d(-x + X, y + Y);
        glVertex2d(-y + X, x + Y);
    }
}

void draw_polygon(int x[], int y[], int n, int color)
{
    glColor3f(color, 1 - color, 1 - color);
    glBegin(GL_POLYGON); // in-built function to draw polygons given n vertices

    for (int i = 0; i < n; i++)
    {
        glVertex2d(x[i], y[i]);
    }
    glEnd();
    // glDisable(GL_DEPTH_TEST);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    int ch, CH, x1, y1, x2, y2, Sx, Sy, x, y, r, n;
    printf("Enter your choice\n1. Line\n2. Circle\n3.Polygon\n");
    scanf("%d", &ch);
    // line
    if (ch == 1)
    {
        printf("Enter two end points of line (x1, y1) and (x2, y2): \n");
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("Enter\n1. X-axis reflection\n2. Y-axis reflection: \n");
        scanf("%d", &CH);
        printf("x1 = %d y1 = %d x2 = %d y2 = %d\n", x1, y1, x2, y2);
        draw_line(x1, y1, x2, y2);
        if (CH == 1)
        {
            reflectX(&x1, &y1);
            reflectX(&x2, &y2);
        }
        if (CH == 2)
        {
            reflectY(&x1, &y1);
            reflectY(&x2, &y2);
        }
        printf("x1 = %d y1 = %d x2 = %d y2 = %d\n", x1, y1, x2, y2);
        draw_line(x1, y1, x2, y2);
    }
    // circle
    if (ch == 2)
    {
        printf("Enter centre (x, y) and radius of the circle: \n");
        scanf("%d%d%d", &x, &y, &r);
        printf("Enter\n1. X-axis reflection\n2. Y-axis reflection: \n");
        scanf("%d", &CH);
        printf("x = %d y = %d r = %d\n", x, y, r);
        draw_circle(x, y, r);
        if (CH == 1)
        {
            reflectX(&x, &y);
        }
        if (CH == 2)
            reflectY(&x, &y);
        printf("x = %d y = %d r = %d\n", x, y, r);
        draw_circle(x, y, r);
    }
    // polygon
    if (ch == 3)
    {
        printf("Enter number of coordinates: \n");
        scanf("%d", &n);
        int x_c[10], y_c[10];
        printf("Enter the coordinates: \n");
        for (int i = 0; i < n; i++)
            scanf("%d%d", &x_c[i], &y_c[i]);
        printf("Enter\n1. X-axis reflection\n2. Y-axis reflection: \n");
        scanf("%d", &CH);
        draw_polygon(x_c, y_c, n, 0);
        for (int i = 0; i < n; i++)
        {
            if (CH == 1)
            {
                reflectX(&x_c[i], &y_c[i]);
            }
            if (CH == 2)
            {
                reflectY(&x_c[i], &y_c[i]);
            }
        }
        draw_polygon(x_c, y_c, n, 1);
    }

    glEnd();
    glFlush();
}

void Init()
{
    gluOrtho2D(-320, 320, -320, 320);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(640, 640);
    glutCreateWindow("Reflection of line, circle and polygon");
    Init();
    glutDisplayFunc(display);
    glutMainLoop();
}