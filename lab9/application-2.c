#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

int window;
int value;

void display()
{

    /* clear window */
    glClear(GL_COLOR_BUFFER_BIT);

    /* draw scene */
    if (value == 1)
    {
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glColor3f(0.0, 1.0, 0.0);
        glutWireTeapot(.5);
        glEnd();
    }
    else if (value == 2)
    {

        glClearColor(0.0, 0.0, 0.0, 0.0);
        glColor3f(0.0, 1.0, 0.0);
        glutSolidTeapot(.5);
    }
    else if (value == 3)
    {
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glColor3f(0.0, 0.0, 1.0);
        glutWireTeapot(.5);
    }
    else if (value == 4)
    {
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glColor3f(0.0, 0.0, 1.0);
        glutSolidTeapot(.5);
    }
    /* flush drawing routines to the window */
    glFlush();
}

void menu(int num)
{
    if (num == 0)
    {
        glutDestroyWindow(window);
        exit(0);
    }
    value = num;
    glutPostRedisplay();
}
void createMenu(void)
{
    int sub1 = glutCreateMenu(menu);
    glutAddMenuEntry("Wired Teapot", 1);
    glutAddMenuEntry("Solid Teapot", 2);

    int sub2 = glutCreateMenu(menu);
    glutAddMenuEntry("Wired Teapot", 3);
    glutAddMenuEntry("Solid Teapot", 4);

    glutCreateMenu(menu);
    glutAddSubMenu("Green Wired Teapot", sub1);
    glutAddSubMenu("Blue Wired Teapot", sub2);
    glutAddMenuEntry("Quit", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char *argv[])
{

    /* initialize GLUT, using any commandline parameters passed to the 
       program */
    glutInit(&argc, argv);

    /* setup the size, position, and display mode for new windows */
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_RGB);

    /* create and set up a window */
    window = glutCreateWindow("hello, teapot!");
    // glutDisplayFunc(display);
    createMenu();
    glutDisplayFunc(display);
    /* tell GLUT to wait for events */
    glutMainLoop();
}