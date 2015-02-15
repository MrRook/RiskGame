void prnt(int a,int b,int c,const char *msg){
//glColor3f(0,0,0);
glRasterPos3f(a,b,1);

for(int i=0;msg[i]!='\0';++i)
{if(i%c==0 && i!=0){
b-=15;

glRasterPos3f(a,b,1);
}
glutBitmapCharacter(GLUT_BITMAP_9_BY_15,msg[i]);
}

glColor3f(1,1,1);

}
void prnt(int a,int b,int c,int depth,const char *msg){
glColor3f(0,0,0);
glRasterPos3f(a,b,depth);

for(int i=0;msg[i]!='\0';++i)
{if(i%c==0 && i!=0){
b-=15;

glRasterPos3f(a,b,depth);
}
glutBitmapCharacter(GLUT_BITMAP_9_BY_15,msg[i]);
}

glColor3f(1,1,1);

}



void blink(unsigned char a[800][600],int X,int Y)
{
glPointSize(8);
glBegin(GL_POINTS);
glColor4f(1,1,1,0.05);


for(int i=0;i<800;++i)
  for(int j=0;j<600;++j)
  if(a[X][Y]==a[i][j])
    glVertex3f(i,j,0);
     glPointSize(1);
     glEnd();
glPointSize(1);


}

