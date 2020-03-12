#include <stdio.h>
#include <GL/glut.h>

int n;

GLfloat v[4][2] = {{0.5, 0.5},
                   {0.5, -0.5},
                   {-0.5, -0.5},
                   {-0.5, 0.5}};

void square(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d)

/* display one square */
{
    glVertex2fv(a);
    glVertex2fv(b);
    glVertex2fv(c);
    glVertex2fv(d);
}

void divide_square(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d, int m)
{
    /* triangle subdivision using vertex numbers */
    GLfloat V[16][2];
    int j;
    if (m > 0)
    {
        GLfloat a1[2], a2[2], a3[2], b1[2], b2[2], b3[2];
        GLfloat c1[2], c2[2], c3[2], d1[2], d2[2], d3[2];
        a1[0] = (2 * a[0] + b[0]) / 3;
        a1[1] = (2 * a[1] + b[1]) / 3;

        b3[0] = (2 * b[0] + a[0]) / 3;
        b3[1] = (2 * b[1] + a[1]) / 3;

        b1[0] = (2 * b[0] + c[0]) / 3;
        b1[1] = (2 * b[1] + c[1]) / 3;

        c3[0] = (2 * c[0] + b[0]) / 3;
        c3[1] = (2 * c[1] + b[1]) / 3;

        c1[0] = (2 * c[0] + d[0]) / 3;
        c1[1] = (2 * c[1] + d[1]) / 3;

        d3[0] = (2 * d[0] + c[0]) / 3;
        d3[1] = (2 * d[1] + c[1]) / 3;

        d1[0] = (2 * d[0] + a[0]) / 3;
        d1[1] = (2 * d[1] + a[1]) / 3;

        a3[0] = (2 * a[0] + d[0]) / 3;
        a3[1] = (2 * a[1] + d[1]) / 3;

        a2[0] = (2 * a1[0] + d3[0]) / 3;
        a2[1] = (2 * a1[1] + d3[1]) / 3;

        b2[0] = (2 * b3[0] + c1[0]) / 3;
        b2[1] = (2 * b3[1] + c1[1]) / 3;

        c2[0] = (2 * c1[0] + b3[0]) / 3;
        c2[1] = (2 * c1[1] + b3[1]) / 3;

        d2[0] = (2 * d3[0] + a1[0]) / 3;
        d2[1] = (2 * d3[1] + a1[1]) / 3;

        divide_square(a, a1, a2, a3, m - 1);
        divide_square(a1, b3, b2, a2, m - 1);
        divide_square(b3, b, b1, b2, m - 1);
        divide_square(b1, c3, c2, b2, m - 1);
        divide_square(c, c1, c2, c3, m - 1);
        divide_square(c1, d3, d2, c2, m - 1);
        divide_square(d3, d, d1, d2, m - 1);
        divide_square(d1, a3, a2, d2, m - 1);
    }
    else
    {
        glVertex2fv(a);
        glVertex2fv(b);
        glVertex2fv(c);
        glVertex2fv(d);
    }
}
void display()
{
    // printf("Enter the number of steps: ");
    // scanf("%d", &n);
    glClear(GL_COLOR_BUFFER_BIT);
    n = 6;
    glBegin(GL_QUADS);
    divide_square(v[0], v[1], v[2], v[3], n);
    glEnd();
    glFlush();
}
void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Sierpinski");
    glutDisplayFunc(display);
    glutMainLoop();
}