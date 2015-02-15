class dice{
    GLuint tid[6];
    public:
           dice()
           {


tid[0]=load("one.bmp");
tid[1]=load("two.bmp");
tid[2]=load("three.bmp");
tid[3]=load("four.bmp");
tid[4]=load("five.bmp");
tid[5]=load("six.bmp");

           }
          int  draw()
           {
           srand(time(0));
           int val=rand()%6;
           glEnable(GL_TEXTURE_2D);
           glBindTexture(GL_TEXTURE_2D,tid[val]);
           glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
           glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
           glBegin(GL_QUADS);
          glVertex3f(0,0,0);
           glTexCoord2f(1,0);
glVertex3f(40,0,0);
glTexCoord2f(1,1);
glVertex3f(40,40,0);
glTexCoord2f(0,1);
glVertex3f(0,40,0);
glTexCoord2f(0,0);
glEnd();
glDisable(GL_TEXTURE_2D)
           return val+1;
           }
}
