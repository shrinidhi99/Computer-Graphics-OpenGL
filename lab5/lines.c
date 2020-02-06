// #include <windows.h>  // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display()
{
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

   glBegin(GL_LINES);           // Line
   glColor3f(0.0f, 1.0f, 0.0f); // Green
   glVertex2f(-0.5f, -0.5f);    // x, y
   glVertex2f(0.5f, -0.5f);
   glEnd();

   glFlush(); // Render now
}

void MyMouse(int button, int state, int x, int y)
{
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
   switch (button)
   {
   case GLUT_LEFT_BUTTON:
      glBegin(GL_LINES);           // Line
      glColor3f(0.0f, 0.0f, 1.0f); // Green
      glVertex2f(-0.5f, -0.5f);    // x, y
      glVertex2f(0.5f, -0.5f);
      glEnd();
      break;
   case GLUT_RIGHT_BUTTON:
      glBegin(GL_LINES);           // Line
      glColor3f(1.0f, 0.0f, 0.0f); // Green
      glVertex2f(-0.5f, -0.5f);    // x, y
      glVertex2f(0.5f, -0.5f);
      glEnd();
      break;
   default:
      break;
   }
   glFlush(); // Render now
}

void MyKeyboard(unsigned char key, int x, int y)
{
   switch (key)
   {
   case 'W':
      glBegin(GL_LINES);           // Line
      glColor3f(0.0f, 0.0f, 1.0f); // Green
      glVertex2f(-0.5f, -0.5f);    // x, y
      glVertex2f(0.5f, -0.5f);
      glEnd();
      break;
   case 'S':
      glBegin(GL_LINES);           // Line
      glColor3f(1.0f, 0.0f, 0.0f); // Green
      glVertex2f(-0.5f, -0.5f);    // x, y
      glVertex2f(0.5f, -0.5f);
      glEnd();
      break;
   default:
      break;
   }
   glutPostRedisplay();
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char **argv)
{
   glutInit(&argc, argv);                 // Initialize GLUT
   glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
   glutInitWindowSize(400, 400);          // Set the window's initial width & height
   glutInitWindowPosition(50, 50);        // Position the window's initial top-left corner
   glutDisplayFunc(display);              // Register display callback handler for window re-paint
   glutMouseFunc(MyMouse);
   glutKeyboardFunc(MyKeyboard);
   glutMainLoop(); // Enter the event-processing loop
   return 0;
}
