#include<GL/glut.h>
#include<windows.h>
void draw(void)
{

glClear(GL_COLOR_BUFFER_BIT);
glutSolidCube(100);
glutSwapBuffers();
}


void reshape (int w, int h)
{
glViewport (0, 0, (GLsizei) w, (GLsizei) h);
glMatrixMode (GL_PROJECTION);
glLoadIdentity ();
glOrtho (-w,w, -100,h,-300,300);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}



   void init()
   {
        glClearColor(0.0,0.0,0.0,0.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-300,300, -100,500,-300,300);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
   }


   int main(int arc,char **argv)
   {


        glutInit(&arc,argv);
        glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
        glutInitWindowSize(1368,736);
        glutCreateWindow("point");
        init();
        glutDisplayFunc(draw);
               glutReshapeFunc(reshape);
        glutMainLoop();
   }
