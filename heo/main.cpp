#include<windows.h>
#include<GL/glut.h>

using namespace std;


void reshape (int w, int h)
{
glViewport (0, 0, (GLsizei) w, (GLsizei) h);

glMatrixMode (GL_PROJECTION);
glLoadIdentity ();
glOrtho (-w,w, -100,h,-300,300);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}
int counter=1000;
void func()
{

if(counter-->0)
{
glReadBuffer (GL_BACK);
glDrawBuffer (GL_FRONT);
//glCopyPixels (GL_COLOR);
//glReadPixels();
glColor3f(1,0,0);
glRotatef(1,0,0,1);
glutSolidCube(100);
glutSwapBuffers();
func();
}
glutSolidCube(100);
glutSwapBuffers();
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

void draw(void)
{

glClear(GL_COLOR_BUFFER_BIT);

glBegin(GL_TRIANGLES);
glVertex3f(0,0,0);
glVertex3f(100,0,0);
glVertex3f(0,100,0);
glReadBuffer(GL_FRONT);
glReadPixels(0,0,400,400,GL_RGB,Gl_)
glReadBuffer(GL_BACK);
glEnd();

glutSwapBuffers();

//func();

}

void f()
{
glutPostRedisplay();
}

   int main(int arc,char **argv)
   {



        glutInitDisplayMode (GLUT_DOUBLE|GLUT_RGBA);

        init();
glutInitWindowSize(400,400);
        glutCreateWindow("point");
               glutReshapeFunc(reshape);
                glutDisplayFunc(draw);
//glutIdleFunc(f);
        glutMainLoop();
   }
