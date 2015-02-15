//for getting collor of player
void get_colour(int owner){
if(owner==-1)
glColor3f(0,0,0);
else if(owner==0)
glColor3f(1,0,0);
else if(owner==1)
glColor3f(0,1,0);
else if(owner==2)
glColor3f(0,0,1);
else if(owner==3)
glColor3f(1,1,0);
else if(owner==4)
glColor3f(1,0,1);
else if(owner==5)
glColor3f(0,1,1);

}


class country_func{
      public:

      int arm;
      float val;
      std::vector<int > neb;

country_func(){};



      };

//////////////////////////////////////////////////////////////////////////////
class country:public country_func
{
public:

int x,y,owner;
float worth;
country():x(0),y(0),owner(-1),worth(0){};

void setcoord(int p,int q)
{x=p,y=q;
arm=0;}

void draw()
{
glColor3f(0,0,0);
glPointSize(5);
glBegin(GL_LINES);
glVertex3f(x,y,-1);
glVertex3f(x,y+20,-1);
glEnd();

get_colour(owner);
glBegin(GL_QUADS);
glVertex3f(x,y+40,-1);
glVertex3f(x+30,y+40,1);
glVertex3f(x+30,y+20,-1);
glVertex3f(x,y+20,-1);
glEnd();

glColor3f(1,1,1);
glRasterPos3f(x+5,y+27,-1);
char p[3];
itoa(arm,p,10);
if(p[1]=='\0')
glRasterPos3f(x+10,y+27,-1);
for(int i=0;p[i]!='\0';++i)
glutBitmapCharacter(GLUT_BITMAP_9_BY_15,p[i]);
glColor3f(1,1,1);

}
};

//////////////////////////////////////////////

//////////////////////////////////////////////////////scroll
class moving
{

int par,nx,val;
public:
moving(int p):par(p-2),nx(365),val(1){};
int movescrolldraw(int mx,int my,int rx,int tid)
{
glEnable(GL_TEXTURE_2D);
glColor4f(1,1,1,0.95);
glBindTexture(GL_TEXTURE_2D,tid);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
glBegin(GL_QUADS);
glTexCoord2f(0,0);
glVertex3f(300,250,0);
glTexCoord2f(1,0);
glVertex3f(556,250,0);
glTexCoord2f(1,1);
glVertex3f(556,378,0);
glTexCoord2f(0,1);
glVertex3f(300,378,0);
glEnd();
/////cancel
nx=rx;
if(rx<365)
nx=365;
if(rx>465)
nx=465;
 glColor3f(1,1,0);

        glBegin(GL_QUADS);
       glVertex3f(nx,318,0);
         glVertex3f(nx+20,318,0);
          glVertex3f(nx+20,338,0);
           glVertex3f(nx,338,0);
        glEnd();
   
val=par*((nx-365)/100.0)+1;

glColor4f(1,1,1,0.8);
glRasterPos2f(410,290);
char p[3];
itoa(val,p,10);
if(p[1]=='\0')
glRasterPos2f(410+5,290);
for(int i=0;p[i]!='\0';++i)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,p[i]);

if(((mx-345)*(mx-354))/(25*25)+((my-270)*(my-270))/(15*15)-1<0)
{
    glColor4f(1,1,1,0.2);
    glBegin(GL_POLYGON);
    for(float i=0;i<6.28;i=i+0.3)
    {
        glVertex3f(345+25*cos(i),270+15*sin(i),0);
		
    }

    glEnd();
    val=1;
    return -1;


}
if(((mx-510)*(mx-510))/(25*25)+((my-270)*(my-270))/(15*15)-1<0)
{
    glColor4f(1,1,1,0.2);
    glBegin(GL_POLYGON);
    for(float i=0;i<6.28;i=i+0.3)
    {
        glVertex3f(500+25*cos(i),270+15*sin(i),0);
    }

    glEnd();
    return val;


}
return 0;
}

};

///////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
///////////////////////dice;

            class dice{int r;

    public:
           dice()
           {
r=60;
           }
          int  draw()
           {
            char  tid[6][50]={"texture/one.bmp","texture/two.bmp","texture/three.bmp","texture/four.bmp","texture/five.bmp","texture/six.bmp"};
           srand(time(0));
           //int val=rand()%6;
           GLuint t=load(tid[r/10-1]);
           glEnable(GL_TEXTURE_2D);
           glBindTexture(GL_TEXTURE_2D,t);
           glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
           glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
           glBegin(GL_QUADS);

glTexCoord2f(1,0);
glVertex3f(100,10,0);
glTexCoord2f(1,1);
glVertex3f(100,110,0);
glTexCoord2f(0,1);
glVertex3f(0,110,0);
glTexCoord2f(0,0);
 glVertex3f(0,10,0);
glEnd();
glDisable(GL_TEXTURE_2D);


if(r--<=0)
r=60;
           //return r+1;
           }
};
