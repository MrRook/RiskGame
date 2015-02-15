
 void init()
{

glClearColor(1.0,1.0,1.0,1.0);
glMatrixMode (GL_PROJECTION);
glLoadIdentity();
glOrtho(0,800,0,600,-10,10);
glEnable (GL_BLEND);
glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}
void reshape (int w, int h)
{
glClearColor(1.0,1.0,1.0,1.0);

glMatrixMode (GL_PROJECTION);
glLoadIdentity();
glOrtho(0,800,0,600,-10,10);
glEnable (GL_BLEND);
glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}
