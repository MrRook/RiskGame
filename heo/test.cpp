#include<windows.h>
#include<iostream>
#include<cstdio>
#include<GL/glut.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<fstream>
#include"proj/initializeR.h"
#include"PROJ/BMP.h"
#include"PROJ/mouse.h"
#include"PROJ/object.h"
#include"PROJ/bass.h"

using namespace std;

int curH,curW,mask,parent,scrollx,mousex,mousey,stream;
unsigned char mousebuffer[800][600];
FILE *keyfile;

//////////////////////
GLuint tid[10];
int i=0,stat=0;


//////////////////////////////////////////////////////////////
moving *mm;
///////////////////////////////////////////////////////////////////////
flags f[42];
dice de;
void pet()
{   for(int i=0;i<100000000;++i)
{

    glClear(GL_COLOR_BUFFER_BIT);
    glRotatef(0,0,0,1);
    glutSolidCube(100);
    glutSwapBuffers();
}
}
void draw(void)
{


pet();

glutSwapBuffers();

}


void muse(int key,int state,int x,int y)
{
   if(state==0)
   {

   if(mousebuffer[x][600-y]!=0)
   {mask=mousebuffer[x][600-y];
   if(mask==0)
   mask=-1;
   else if(mask<43)
   {
   f[mask-1].add();
   }
   }

   fprintf(keyfile,"%d %d\n",x,600-y);


}
else if(state==1)
mask=-1;
glutPostRedisplay();
}
void keyb(unsigned char key,int x,int y)
{
    if(key==27)
    {
      fclose(keyfile);
    string f="qres.exe ";
char i[20],j[20];

cout<<itoa(10,i,10);
f=f+ "/x "+itoa(curW,i,10)+" /y "+itoa(curH,j,10);;
cout<<f<<endl;
system(&f[0]);

 BASS_StreamFree(stream);
            // free BASS
            BASS_Free();
            exit(0);
    glutLeaveGameMode();

    }
}
void refresh()
{
    draw();
}
void mousedetec(int x,int y)
{
    stat=1;
    mousex=x;
    if(x>360&&x<470&&(600-y)>315&&(600-y)<340)
    scrollx=x;
    mousey=600-y;
    glutPostRedisplay();
}
   int main(int arc,char **argv)
   {

       mm=new moving(50);
       FILE *fla;
    if (!BASS_Init(-1, 44100, 0, NULL ,NULL))
   {
   cout<<"Can't initialize device";
   return -1;
   }

            stream = BASS_StreamCreateFile(false, "abc.mp3", 0L, 0L, BASS_SAMPLE_LOOP);
            if (stream != 0)
            {
                // play the stream channel
                BASS_ChannelPlay(stream, false);
            }
            else
            {
                // error creating the stream
                cout<<"Stream error: {0}", BASS_ErrorGetCode();
            }
   fla=fopen("datafile/flagpos.txt","r");
   for(int i=0;i<42;++i)
   {int x,y;
       fscanf(fla,"%d %d",&x,&y);
       f[i].setcoord(x,y);
   }


    fclose(fla);
        glutInit(&arc,argv);
          curW=glutGet(GLUT_SCREEN_WIDTH);
               curH=glutGet(GLUT_SCREEN_HEIGHT);
               system("qres.exe /x 800 /y 600");
   keyfile=fopen("key.txt","w");


        glutInitDisplayMode (GLUT_DOUBLE|GLUT_RGBA);

        glutGameModeString( "800x600:32@80" );
       parent= glutEnterGameMode();
        init();

        glutDisplayFunc(draw);
        glutMainLoop();
   }
