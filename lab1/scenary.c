// C program to demonstrate
// drawing a circle using
// OpenGL
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#define pi 3.142857

void display()
{
  // house - square
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
  glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

  glBegin(GL_LINES);      // Each set of 4 vertices form a quad
                          //   glColor3f(0.0f, 1.0f, 0.0f); // Red
  glVertex2f(-0.2, -0.3); // x, y
  glVertex2f(0.2, -0.3);
  glEnd();
  glBegin(GL_LINES); // Each set of 4 vertices form a quad
  glVertex2f(0.2, 0.2);
  glVertex2f(-0.2, 0.2);
  glEnd();
  glBegin(GL_LINES);
  glVertex2f(0.2, 0.2); // x, y
  glVertex2f(0.2, -0.3);
  glEnd();
  glBegin(GL_LINES);
  glVertex2f(-0.2, 0.2);
  glVertex2f(-0.2, -0.3);
  glEnd();

  // house right window
  glBegin(GL_LINES);         // Each set of 4 vertices form a quad
                             //   glColor3f(0.0f, 1.0f, 0.0f); // Red
  glVertex2f(-0.15, -0.025); // x, y
  glVertex2f(-0.1, -0.025);
  glEnd();
  glBegin(GL_LINES); // Each set of 4 vertices form a quad
  glVertex2f(-0.15, 0.025);
  glVertex2f(-0.1, 0.025);
  glEnd();
  glBegin(GL_LINES);
  glVertex2f(-0.15, 0.025); // x, y
  glVertex2f(-0.15, -0.025);
  glEnd();
  glBegin(GL_LINES);
  glVertex2f(-0.1, 0.025);
  glVertex2f(-0.1, -0.025);
  glEnd();

  // house left window
  glBegin(GL_LINES);        // Each set of 4 vertices form a quad
                            //   glColor3f(0.0f, 1.0f, 0.0f); // Red
  glVertex2f(0.15, -0.025); // x, y
  glVertex2f(0.15 - 0.05, -0.025);
  glEnd();
  glBegin(GL_LINES); // Each set of 4 vertices form a quad
  glVertex2f(0.15, 0.025);
  glVertex2f(0.15 - 0.05, 0.025);
  glEnd();
  glBegin(GL_LINES);
  glVertex2f(0.15, 0.025); // x, y
  glVertex2f(0.15, -0.025);
  glEnd();
  glBegin(GL_LINES);
  glVertex2f(0.15 - 0.05, 0.025);
  glVertex2f(0.15 - 0.05, -0.025);
  glEnd();

  // house roof
  glBegin(GL_LINES);    // Each set of 4 vertices form a quad
                        //   glColor3f(0.0f, 1.0f, 0.0f); // Red
  glVertex2f(0.2, 0.2); // x, y
  glVertex2f(0.0, 0.3);
  glEnd();
  glBegin(GL_LINES); // Each set of 4 vertices form a quad
  glVertex2f(-0.2, 0.2);
  glVertex2f(0.0, 0.3);
  glEnd();

  // house door
  glBegin(GL_LINES);       // Each set of 4 vertices form a quad
                           //   glColor3f(0.0f, 1.0f, 0.0f); // Red
  glVertex2f(-0.05, -0.3); // x, y
  glVertex2f(0.05, -0.3);
  glEnd();
  glBegin(GL_LINES); // Each set of 4 vertices form a quad
  glVertex2f(0.05, -0.1);
  glVertex2f(-0.05, -0.1);
  glEnd();
  glBegin(GL_LINES);
  glVertex2f(0.05, -0.1); // x, y
  glVertex2f(0.05, -0.3);
  glEnd();
  glBegin(GL_LINES);
  glVertex2f(-0.05, -0.1);
  glVertex2f(-0.05, -0.3);
  glEnd();
  // mountains
  // mountain - 1
  glBegin(GL_TRIANGLES); // Each set of 3 vertices form a triangle
                         //   glColor3f(0.0f, 0.0f, 1.0f); // Blue
  glVertex2f(-1, 0.35);
  glVertex2f(0, 0.35);
  glVertex2f(-0.5, 1);
  glEnd();
  // mountain - 2
  glBegin(GL_TRIANGLES); // Each set of 3 vertices form a triangle
                         //   glColor3f(0.0f, 0.0f, 1.0f); // Blue
  glVertex2f(1, 0.35);
  glVertex2f(0, 0.35);
  glVertex2f(0.5, 1);
  glEnd();

  // sun
  glBegin(GL_POINTS);
  float x, y, i;
  for (i = 0; i < (2 * pi); i += 0.001)
  {
    // let 200 is radius of circle and as,
    // circle is defined as x=r*cos(i) and y=r*sin(i)
    x = 0 + 0.1 * cos(i);
    y = 0.8 + 0.1 * sin(i);

    glVertex2f(x, y);
  }
  glEnd();

  // steps
  glBegin(GL_LINES);        // Each set of 4 vertices form a quad
                            //   glColor3f(0.0f, 1.0f, 0.0f); // Red
  glVertex2f(-0.14, -0.32); // x, y
  glVertex2f(0.14, -0.32);
  glEnd();
  glBegin(GL_LINES);       // Each set of 4 vertices form a quad
                           //   glColor3f(0.0f, 1.0f, 0.0f); // Red
  glVertex2f(0.14, -0.32); // x, y
  glVertex2f(0.14, -0.3);
  glEnd();
  glBegin(GL_LINES);        // Each set of 4 vertices form a quad
                            //   glColor3f(0.0f, 1.0f, 0.0f); // Red
  glVertex2f(-0.14, -0.32); // x, y
  glVertex2f(-0.14, -0.3);
  glEnd();
  glBegin(GL_LINES); // Each set of 4 vertices form a quad
  glVertex2f(0.12, -0.34);
  glVertex2f(-0.12, -0.34);
  glEnd();
  glBegin(GL_LINES);       // Each set of 4 vertices form a quad
                           //   glColor3f(0.0f, 1.0f, 0.0f); // Red
  glVertex2f(0.12, -0.34); // x, y
  glVertex2f(0.12, -0.32);
  glEnd();
  glBegin(GL_LINES);        // Each set of 4 vertices form a quad
                            //   glColor3f(0.0f, 1.0f, 0.0f); // Red
  glVertex2f(-0.12, -0.34); // x, y
  glVertex2f(-0.12, -0.32);
  glEnd();
  glBegin(GL_LINES);
  glVertex2f(-0.1, -0.36); // x, y
  glVertex2f(0.1, -0.36);
  glEnd();
  glBegin(GL_LINES);      // Each set of 4 vertices form a quad
                          //   glColor3f(0.0f, 1.0f, 0.0f); // Red
  glVertex2f(0.1, -0.36); // x, y
  glVertex2f(0.1, -0.34);
  glEnd();
  glBegin(GL_LINES);       // Each set of 4 vertices form a quad
                           //   glColor3f(0.0f, 1.0f, 0.0f); // Red
  glVertex2f(-0.1, -0.36); // x, y
  glVertex2f(-0.1, -0.34);
  glEnd();
  glBegin(GL_LINES);
  glVertex2f(0.08, -0.38);
  glVertex2f(-0.08, -0.38);
  glEnd();
  glBegin(GL_LINES);       // Each set of 4 vertices form a quad
                           //   glColor3f(0.0f, 1.0f, 0.0f); // Red
  glVertex2f(0.08, -0.38); // x, y
  glVertex2f(0.08, -0.36);
  glEnd();
  glBegin(GL_LINES);        // Each set of 4 vertices form a quad
                            //   glColor3f(0.0f, 1.0f, 0.0f); // Red
  glVertex2f(-0.08, -0.38); // x, y
  glVertex2f(-0.08, -0.36);
  glEnd();
  glFlush();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  // giving window size in X- and Y- direction
  glutInitWindowSize(800, 800);
  glutInitWindowPosition(0, 0);

  // Giving name to window
  glutCreateWindow("Scenary");

  glutDisplayFunc(display);
  glutMainLoop();
}