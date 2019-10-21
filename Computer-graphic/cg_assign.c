#include <GL/glut.h>
#include<stdlib.h>

 void display()
 {
//     glClear(GL_COLOR_BUFFER_BITS);
      glColor4f(1, 3, 0, 1);
      glBegin(GL_POLYGON);
      glVertex2f(0, -1);
      glVertex2f(1,-0.5);
                glVertex2f( 1,0.5);
                 glVertex2f( 0,1);
                 glVertex2f( -1,0.5);
                 glVertex2f( -1,-0.5);
                  glEnd();
                   glutSwapBuffers(); }

 int main(int argc, char **argv)
  {
      int mode=GLUT_RGB|GLUT_DOUBLE;
      glutInit(&argc, argv);
      glutInitDisplayMode(mode);
      glutInitWindowSize(600, 600);
       glutCreateWindow("Computer");

       glutDisplayFunc(display);
     //   glutKeyboardFunc(key);
         glutMainLoop();
 }