///////////////////
//////rule 1 at
////////
//////////
#define GLUT_DISABLE_ATEXIT_HACK 
#include <windows.h>
#include <vector>
#include <queue>
#include <iostream>
#include <cstdio>
#include <GL/glut.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <AL/alut.h>



/////////////////////////////
int prob_mat[10][10]=
{42,75,92,97,99,99,99,99,100,100,
11,36,66,79,89,93,97,98,99,99,
3,21,47,64,77,86,91,95,97,98,
1,9,31,48,64,74,83,89,93,95,
1,5,21,36,51,64,74,82,87,92,
1,2,13,25,40,52,64,73,81,86,
0,1,8,18,30,42,54,64,73,80,
0,0,5,12,22,33,45,55,65,72,
0,0,3,9,16,26,36,46,56,65,
0,0,2,6,12,19,29,38,48,57};






/////////////////////////////////////////////////////////////////////////////////////////////////////



///
FILE * err ;
void debug(int i){
err=fopen("error.txt","a+");
fprintf(err,"%d\n",i);
fclose(err);
}
void debug(char* s){
err=fopen("error.txt","a+");
fprintf(err,"%s\n",s);
fclose(err);
}
 
/////

#include"proj/initializeR.h"
#include"PROJ/BMP.h"
#include"PROJ/mouse.h"
#include"PROJ/object.h"
#include"PROJ/bass.h"
#include"PROJ/function.h"

#define ACQUIRE -1
#define REINFORCEMENT 0
#define FORTIFY 4


#define ATTACK_CHOOSE 1
#define ATTACK_MOVE 2
#define ATTACK_ROLL 3

#define TUNE_ENMY_CTRY (-1)
#define TUNE_MY_CTRY 1
#define TUNE_ENMY_ARM (-1)  
#define TUNE_MY_ARM 1


using namespace std;
///// GLOBALS///////////////////////////////////////////
ALuint sound_click_buffer, sound_click;
int curH,curW,scD,moX=0,moY=0,from=-1,to=-1,scrollB=0;
char keyP;
bool moB[3]={0},keyD,funcon=0;
int stream;
/*

curH = current window height need to be restored
curW = current window width need to be restored
scD =scrolling direction
moX = cursor position in X-axis
moY = cursor position in Y-axis
*/


unsigned char mousebuffer[800][600];
FILE *keyfile;
GLuint tid[10];
GLuint tid_alert,tid_attack_roll,tid_sword;
int i=0,stat=0,player_no=0,phase=-1,tot_player,temp=0,extra;
country world[42];
dice de;
int gamestate=0;

int attack_result=3;
int wait=1;
vector<int> aa;
vector<int> bb;
int random_aq=0;
//////////////////////////////////////////////////////////


void mousedetec(int,int);


class player{       public:

                    vector<int>  my_country;
                    int bonus_arm;

                    int type ; //bot or human
                   //card object;
                     void acquire(country *world,int cno)
                     {
                         world[cno].owner=player_no;

                     }




             }player_world[6];

/////
int ai_aq();

////////////


int  temp_player_count=1; ///

void game_init();
vector<float> best_optimal(int country_indx);
void reinforce_bot(int player_number);
void update_worth(int indx);
int delta_worth(int indx,int max);
void loadBasicMap();
void end(void);
void data_disp(void);
int alert(int a,int b,int resume_phase,const char * msg);

int    attack(int from,int to);
int attack_once( int atkr,int dfndr);

void get_color( int player_no ){

glColor3f(0,0,0);
if(player_no==0)
glColor3f(1,0,0);
else if(player_no==1)
glColor3f(0,1,0);
else if(player_no==2)
glColor3f(0,0,1);
else if(player_no==3)
glColor3f(1,1,0);
else if(player_no==4)
glColor3f(1,0,1);
else if(player_no==5)
glColor3f(0,1,1);

}

void show_flag(int x,int y,int z)
{

glBegin(GL_POLYGON);
glVertex3f(x ,70+y,z);
glVertex3f(x+100 ,70+y,z);

glVertex3f(x+80 ,85+y,z);

glVertex3f(x+100,100+y,z);
glVertex3f(x,100+y,z);
glEnd();


glColor3f(0,0,0);

glBegin(GL_LINES);

glVertex3f(x,100+y,z);
glVertex3f(x,y,z);

glEnd();


}
void draw(void)
{


if(gamestate==0)
{
game_init();
}

else if(gamestate==1)
{

loadBasicMap();


for(int i=0;i<42;++i)
{world[i].draw();
}

//// buttons on board////

//close button
	if(moX<800&&750<moX&&moY<600&&570<moY)
		{
		if(alert(350,20,phase,"Do you really want to quit game !!"))
			end();
		}

//random button
	if(moX<313 && 208<moX && moY<55 && 13<moY)
{
random_aq=12;

}		
		
		//done button

	if(moX>720&&moY<60&&(moB[0]==GLUT_DOWN))
	{   
		if(player_no+1==tot_player)
		{
		phase++;
		phase=phase % 5;
		player_no=0;
		}
		else{
		player_no++;
		}
	alSourcePlay (sound_click);
	moX=-1;
	moY=-1;
	moB[0]=GLUT_UP;
	glutPostRedisplay();
	}

		
		data_disp();

/*if(moX<&&<moX&&moY<&&<moY)
{
}
*/




if(temp==42)
{
phase=REINFORCEMENT;
player_no=0;
                      ///acquire finished
//alert(350,20,REINFORCEMENT,"ReInforcement has stared genral !!");
//debug("phase");
//debug(phase);
temp=0;
}

if(phase==ACQUIRE){

if(random_aq==12){


int foo=rand()%42;

while(world[foo].owner!=-1){
foo=(foo+1)%42;

}


  
            world[foo].owner=player_no;
            world[foo].arm=1;
            player_world[player_no].my_country.push_back(foo);
            player_world[player_no].bonus_arm--;
            
			 player_no=(player_no+1)%tot_player;
           temp++;
            
alSourcePlay (sound_click);

}
else if(player_world[player_no].type== 1)   ///1 for human ;;;;0 for bot
{
if(mousebuffer[moX][moY]>=1&&mousebuffer[moX][moY]<=42&&moB[0]==GLUT_DOWN)            ///aquring phase
{


if(world[mousebuffer[moX][moY]-1].owner!=-1){
//cout<<"error : already aquired" ;

}
        else{
            world[mousebuffer[moX][moY]-1].owner=player_no;
            world[mousebuffer[moX][moY]-1].arm=1;
            player_world[player_no].my_country.push_back(mousebuffer[moX][moY]-1);
            player_world[player_no].bonus_arm--;
            
			 player_no=(player_no+1)%tot_player;
           temp++;
            }




blink(mousebuffer,moX,moY);
alSourcePlay (sound_click);

moB[0]=0;//reset
moX=-1;
moY=-1;

}
}

else{
////for bot

 int fio=ai_aq();

            world[fio].owner=player_no;
            world[fio].arm=1;
            player_world[player_no].my_country.push_back(fio);
            player_world[player_no].bonus_arm--;
            
			player_no=(player_no+1)%tot_player;
           temp++;
 glutPostRedisplay();


 }





}


	 

	 

	 
	 if( phase==REINFORCEMENT)//re -inforcement
{
//for human turn 

 if(player_world[player_no].bonus_arm <= 0){
         //phase change
         if(player_no==tot_player-1)
         {phase=ATTACK_CHOOSE;
		 player_no=0;

		 }
         else
         player_no=player_no+1;
		 
		 }
else if (player_world[player_no].type==1)
{
if(mousebuffer[moX][moY]>=1&&mousebuffer[moX][moY]<=42&&moB[0]==GLUT_DOWN)
    {if(world[mousebuffer[moX][moY]-1].owner!=player_no)
        { cout<<"Error!";
        }
      else{
          world[mousebuffer[moX][moY]-1].arm++;
          player_world[player_no].bonus_arm--;
       
	  
      
/*for bot

          world["target_country"].arm++;
          player_world[player_no].bonus_arm--;
       
	   if(player_world[player_no].bonus_arm==0){
         //phase change
         if(player_no==tot_player-1)
         phase=ATTACK;

         else
         player_no=player_no+1;
		 
*/		 
      
	  
///blinking
blink(mousebuffer,moX,moY);
alSourcePlay (sound_click);

moB[0]=0;//reset
moX=-1;
moY=-1;

		 }

		 
		 }


		 //graphics  for re inforcement//
		 
glEnable(GL_TEXTURE_2D);

glColor3f(1,1,1);
glBindTexture(GL_TEXTURE_2D,tid[5]);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
glBegin(GL_QUADS);
glTexCoord2f(0,0);
glVertex3f(500 ,50,2);
glTexCoord2f(1,0);
glVertex3f(600 ,50,2);
glTexCoord2f(1,1);
glVertex3f(600,150,2);
glTexCoord2f(0,1);
glVertex3f(500,150,2);
glEnd();
glDisable(GL_TEXTURE_2D);

get_color(player_no);
show_flag(500,50,2);

glColor3f(1,1,1);
char str_arm[10];
sprintf(str_arm,"%d",player_world[player_no].bonus_arm);
prnt(550,130,10,3,str_arm);


}		 
		 

		 
else if (player_world[player_no].type==0)
{      /////bot
for(int i=0;i<42;++i)
update_worth(i);

          reinforce_bot(player_no);

	  
	  alSourcePlay (sound_click);

	


		 //graphics  for re inforcement//
		 
glEnable(GL_TEXTURE_2D);

glColor3f(1,1,1);
glBindTexture(GL_TEXTURE_2D,tid[5]);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
glBegin(GL_QUADS);
glTexCoord2f(0,0);
glVertex3f(500 ,50,2);
glTexCoord2f(1,0);
glVertex3f(600 ,50,2);
glTexCoord2f(1,1);
glVertex3f(600,150,2);
glTexCoord2f(0,1);
glVertex3f(500,150,2);
glEnd();
glDisable(GL_TEXTURE_2D);

get_color(player_no);
show_flag(500,50,2);

glColor3f(1,1,1);
char str_arm[10];
sprintf(str_arm,"%d",player_world[player_no].bonus_arm);
prnt(550,130,10,3,str_arm);
player_no+=1;
          player_no%=tot_player;
          if(player_no==0)
          	phase=ATTACK_CHOOSE;


}		 
		 



		 }

	
else if(phase==ATTACK_CHOOSE )            ///attack phase
{
		

	////
	if((mousebuffer[moX][moY]>=1&&mousebuffer[moX][moY]<=42) and (moB[0]==GLUT_DOWN) and (to==-1 || from==-1) )
	{moB[0]=GLUT_UP;

	if(from==-1 && world[mousebuffer[moX][moY]-1].owner==player_no )
	{
	from=mousebuffer[moX][moY]-1;
	blink(mousebuffer,moX,moY);
	alSourcePlay (sound_click);
	moB[0]=0;//reset
	moX=-1;
	moY=-1;


	}

	else if( from !=-1 && to==-1 && world[mousebuffer[moX][moY]-1].owner!=player_no )
	{

	int ala=0;
	for(;ala<world[from].neb.size();++ala)
	{
	if( world[from].neb[ala]== mousebuffer[moX][moY]-1 )
	break;

	}

	if(ala<world[from].neb.size())
	{
	to=mousebuffer[moX][moY]-1;
	phase=ATTACK_MOVE;                                           /////PHASE CHANGE

	//blink
	blink(mousebuffer,moX,moY);
	alSourcePlay (sound_click);
	moB[0]=0;//reset
	moX=-1;
	moY=-1;

	//debug("to");
	//debug(to);
	}

	}


	else{
	//reset
	from=-1;to=-1;
	}
	}

}


//  moving
else if(phase==ATTACK_MOVE)
{
	if(from!=-1&&to!=-1 )
	{

	moving mov(world[from].arm);
	if(funcon==0)
	{
			glutMotionFunc(mousedetec);
			funcon=1;
			}
			//cout<<"\n"<<scrollB;
			 extra=mov.movescrolldraw(moX,moY,scrollB,tid[6]);
			if(extra>0)//(int mx,int my,int rx,int tid,int st)
			{
					//////////////////////////////////////////////and the attack goes here
					phase=ATTACK_ROLL;
					aa.clear();
					bb.clear();
					attack_result=3;
					world[from].arm -= extra;
	                wait=1;				
					glutMotionFunc(NULL);
					funcon=0;
					}
			else if(extra<0)
			{
				funcon=0;
				glutMotionFunc(NULL);
										//reset
				phase=ATTACK_CHOOSE;
				from=to=-1;
				}
			}
			}



			
else if(phase==ATTACK_ROLL){
//dictionary  attack_result 3= no attack yet ,,, 1,0 finnaly attack complited, 6   9  7 8 10 11 
//showing graphics		
		
glEnable(GL_TEXTURE_2D);
glColor3f(1,1,1);
glBindTexture(GL_TEXTURE_2D,tid_attack_roll);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
glBegin(GL_QUADS);
glTexCoord2f(0,0);
glVertex3f(350 ,100,-5);
glTexCoord2f(1,0);
glVertex3f(700 ,100,-5);
glTexCoord2f(1,1);
glVertex3f(700,500,-5);
glTexCoord2f(0,1);
glVertex3f(350,500,-5);
glEnd();
glDisable(GL_TEXTURE_2D);

		//// left flag
		char sss[10];
		get_color(player_no);
		show_flag(370,370, -6);

		sprintf(sss,"%d",extra );
		prnt(400,450,10,-6,sss);

		///right flag

		get_color(world[to].owner);
		show_flag(600,370, -6);

		sprintf(sss,"%d", world[to].arm );
		prnt(630,450,10,-6,sss);

		///	button roll
			if(wait==1&& (moX>600 && moY>120&& moX<660 && moY<150) && (moB[0]==GLUT_DOWN))
		{   
		wait=0;
		moB[0]=GLUT_UP;
		alSourcePlay (sound_click);
		
		}


		
		
if(wait== 0 ){		


//debug("not wait");
		if(attack_result>2)
		attack_result=attack_once(from, to);
		
		

		


//if attaker wins
		
		if (attack_result==1)
		{
			//taking country back
			for(int i=0;i<player_world[world[to].owner].my_country.size();i++){
				if(player_world[world[to].owner].my_country[i]==to)
					{player_world[world[to].owner].my_country.erase( player_world[world[to].owner].my_country.begin()+i );
					break;}
					
					}
			//giving country to winner
			cout<<" win extra arm="<<extra<<endl;

			world[to].owner=player_no;

			world[to].arm=extra;

			player_world[player_no].my_country.push_back(to);

			}
			//if ataker loose
			else if(attack_result==0){
			//cout<<" we loose extra arm="<<extra<<endl;

			
			}

if(attack_result<3) //attack ends/....
{
phase=ATTACK_CHOOSE;
from= -1;
to= -1;
attack_result=3;
	
	}
	
wait=1;
moB[0]=-1;
		}

		
		

//// grahics for dice values	


	for(int i=0;i<aa.size();i++){

		sprintf(sss,"%d",aa[i] );
		prnt(400,320-(i*40),10,-6,sss);

		}
		
		for(int i=0;i<bb.size();i++){

		sprintf(sss,"%d",bb[i] );
		prnt(630,320-(i*40),10,-6,sss);

}		
				//sword graphics

glEnable(GL_TEXTURE_2D);
glColor3f(1,1,1);
glBindTexture(GL_TEXTURE_2D,tid_sword);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);

				
		if(attack_result/3==2){
		
glBegin(GL_POLYGON);

glTexCoord2f(1,0);
glVertex3f(420 ,300,-6);

glTexCoord2f(1,1);
glVertex3f(420 ,350,-6);

glTexCoord2f(0,1);
glVertex3f(610,350,-6);

glTexCoord2f(0,0);
glVertex3f(610,300,-6);

glEnd();

}
		
		if(attack_result/3==3){

glEnable(GL_TEXTURE_2D);
glColor3f(1,1,1);
glBindTexture(GL_TEXTURE_2D,tid_sword);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);

glBegin(GL_POLYGON);

glTexCoord2f(0,0);
glVertex3f(420 ,300,-6);

glTexCoord2f(0,1);
glVertex3f(420 ,350,-6);

glTexCoord2f(1,1);
glVertex3f(610,350,-6);

glTexCoord2f(1,0);
glVertex3f(610,300,-6);

glEnd();
}
	
	if(attack_result%3==1 &&attack_result>3 ){
		glBegin(GL_POLYGON);

glTexCoord2f(1,0);
glVertex3f(420 ,250,-6);

glTexCoord2f(1,1);
glVertex3f(420 ,300,-6);

glTexCoord2f(0,1);
glVertex3f(610,300,-6);

glTexCoord2f(0,0);
glVertex3f(610,250,-6);

glEnd();		
}
		
		if(attack_result%3==2 && attack_result>3 ){
		glBegin(GL_POLYGON);

		
glTexCoord2f(0,0);
glVertex3f(420 ,250,-6);

glTexCoord2f(0,1);
glVertex3f(420 ,300,-6);

glTexCoord2f(1,1);
glVertex3f(610,300,-6);

glTexCoord2f(1,0);
glVertex3f(610,250,-6);


glEnd();
}

		
glDisable(GL_TEXTURE_2D);


		
		}			



else if(phase==FORTIFY )            ///fortify
{
	
	////
	if((mousebuffer[moX][moY]>=1&&mousebuffer[moX][moY]<=42) and (moB[0]==GLUT_DOWN) and (to==-1 || from==-1) )
	{moB[0]=GLUT_UP;

	if(from==-1 && world[mousebuffer[moX][moY]-1].owner==player_no )
	{
	from=mousebuffer[moX][moY]-1;
	blink(mousebuffer,moX,moY);
	alSourcePlay (sound_click);
	moB[0]=0;//reset
	moX=-1;
	moY=-1;


	}

	else if( from !=-1 && to==-1 && world[mousebuffer[moX][moY]-1].owner==player_no )
	{

	int ala=0;
	for(;ala<world[from].neb.size();++ala)
	{
	if( world[from].neb[ala]== mousebuffer[moX][moY]-1 )
	break;

	}

	if(ala<world[from].neb.size())
	{
	to=mousebuffer[moX][moY]-1;
	
	//blink
	blink(mousebuffer,moX,moY);
	alSourcePlay (sound_click);
	moB[0]=0;//reset
	moX=-1;
	moY=-1;

	//debug("to");
	//debug(to);
	}

	}


	else{
	//reset
	from=-1;to=-1;
	}
	}

	if( from!= -1 && to!= -1 )
	{ 
	
	moving mov(world[from].arm);
	if(funcon==0)
	{
			glutMotionFunc(mousedetec);
			funcon=1;
			}
			//cout<<"\n"<<scrollB;
			 extra=mov.movescrolldraw(moX,moY,scrollB,tid[6]);
			if(extra>0)//(int mx,int my,int rx,int tid,int st)
			{
					//////////////////////////////////////////////and the attack goes here
					glutMotionFunc(NULL);
					funcon=0;
					
					
					world[from].arm-=extra;
					world[to].arm+=extra;
			
			from=to=-1;
					
					player_no++;
					if(player_no=tot_player)
					{player_no=0;
					phase=REINFORCEMENT;
					}
					
			}
			else if(extra<0)
			{
				funcon=0;
				glutMotionFunc(NULL);
										//reset
				from=to=-1;
				}
	

	}
	
}

}

glutSwapBuffers();


}

void muse(int key,int state,int x,int y)
{
  moB[key]=state;
  moX=(x/float(curW))*800;
  moY=((curH-y)/float(curH))*600;
 /*
 if(moB[0]==GLUT_DOWN){
	debug("MOUSE");
 debug(moX);
 debug(moY);
 }
 */
 glutPostRedisplay();
}

void keyb(unsigned char key,int x,int y)
{
    keyP=key;
   moX=(x/float(curW))*800;
  moY=((curH-y)/float(curH))*600;
    keyD=1;
    glutPostRedisplay();

}


void mousedetec(int x,int y)
{
cout<<"x: "<<x<<" y: "<<y<<endl;
    moX=(x/float(curW))*800;
  moY=((curH-y)/float(curH))*600;
  //if(moB[0]==GLUT_DOWN)
  scrollB=moX;
// cout<<"bitch "<<moY;
    glutPostRedisplay();
}




int main(int arc,char **argv)
   {
   random_aq=0;
              alutInit (&arc, argv);
			  sound_click_buffer=alutCreateBufferFromFile ("click.wav");
			  alGenSources (1, &sound_click);
			  alSourcei (sound_click, AL_BUFFER, sound_click_buffer);
              glutInit(&arc,argv);
              curW=800;//glutGet(GLUT_SCREEN_WIDTH);
               curH=600;//glutGet(GLUT_SCREEN_HEIGHT);
   
   //system("qres.exe /x 800 /y 600");

       FILE *fla;
	   /*
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
			*/
   fla=fopen("datafile/flagpos.txt","r");
   for(int i=0;i<42;++i)
   {int x,y;
       fscanf(fla,"%d %d",&x,&y);
       world[i].setcoord(x,y);
   }


    fclose(fla);




   keyfile=fopen("key.txt","w");


        glutInitDisplayMode (GLUT_DOUBLE|GLUT_RGBA);

      //  glutGameModeString( "800x600:32@80" );
      // glutEnterGameMode();
glutInitWindowSize(800,600);
	  glutCreateWindow("title");
	   init();

        glutDisplayFunc(draw);
        glutKeyboardFunc(keyb);
               glutReshapeFunc(reshape);
               mousebuf(mousebuffer,"datafile/menu.bin");
               glutMouseFunc(muse);
               tid[0]=load("texture/basic.bmp");
               //tid[1]=load("texture/basic.bmp");
               tid[2]=load("texture/front_page.bmp");
			 tid[5]=load("texture/bonus_arm.bmp");
             tid[6]=load("texture/move.bmp");  
			 tid_alert=load("texture/alert.bmp");
			 tid_attack_roll=load("texture/attack_roll.bmp");
	 tid_sword=load("texture/sword.bmp");

        glutMainLoop();
   }



   
   
//.............................................................................

int alert(int a,int b,int resume_phase,const char * msg){
int c=300;
int d=300;



glEnable(GL_TEXTURE_2D);
glColor3f(1,1,1);
glBindTexture(GL_TEXTURE_2D,tid_alert);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
glBegin(GL_QUADS);
glTexCoord2f(0,0);
glVertex3f(a ,b,-5);
glTexCoord2f(1,0);
glVertex3f(a+c ,b,-5);
glTexCoord2f(1,1);
glVertex3f(a+c,b+d,-5);
glTexCoord2f(0,1);
glVertex3f(a,b+d,-5);
glEnd();
glDisable(GL_TEXTURE_2D);

prnt(a+30,b+d-50,10,-5,msg);


	
	//done button
	if(moX>720&&moY<60&&(moB[0]==GLUT_DOWN))
	{   
		alSourcePlay (sound_click);
	moX=-1;
	moY=-1;
	moB[0]=GLUT_UP;
	



phase=resume_phase;


return 1;
}

return 1;
}
   
   

//.............................................................................
   
void data_disp(void){


char temp_str[50];
//
if(phase == ACQUIRE){
sprintf(temp_str,"Acquision Phase");

}
else if(phase == REINFORCEMENT){
sprintf(temp_str,"Re-Inforcement Phase");

}
else if(phase == ATTACK_ROLL ){
sprintf(temp_str,"Attack roll");

}
else if( phase 	== ATTACK_CHOOSE){
sprintf(temp_str,"Attack choose");

}

else if( phase 	== ATTACK_MOVE){
sprintf(temp_str,"Attack move");

}

else if(phase == FORTIFY){
sprintf(temp_str,"Fortify Phase");

}

glColor3f(0,0,0);
prnt(70,580,88,temp_str);

////////////////////printing player name 

 
sprintf(temp_str,"Player No= %d ", player_no);
glColor3f(0,0,0);
prnt(320,580,88,temp_str);

//printing score

sprintf(temp_str,"P No- C Bonus  ");
glColor3f(0,0,0);
prnt(20,144,88,temp_str);

for(int i=0;i<tot_player;i++){

glColor3f(0,0,0);
sprintf( temp_str,"P %d- %d   %d", 
i,
player_world[i].my_country.size(),
player_world[i].bonus_arm  );

prnt(20,130-(i*17),88,temp_str);
}


}




//..............................................................................
void end(void){
char tmp_str[30];
fclose(keyfile);
//sprintf(tmp_str,"qres.exe /x %d /y %d ",curW,curH);
//debug(tmp_str);

system(tmp_str);
exit(0);
}

//.........................................................
void game_init()
{
glClear(GL_COLOR_BUFFER_BIT);
glEnable(GL_TEXTURE_2D);
glColor3f(1,1,1);
glBindTexture(GL_TEXTURE_2D,tid[2]);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
glBegin(GL_QUADS);
glTexCoord2f(0,0);
glVertex3f(0,0,0);
glTexCoord2f(1,0);
glVertex3f(800,0,0);
glTexCoord2f(1,1);
glVertex3f(800,600,0);
glTexCoord2f(0,1);
glVertex3f(0,600,0);
glEnd();
glDisable(GL_TEXTURE_2D);

if(mousebuffer[moX][moY]==3&&moB[0]==GLUT_DOWN)
{
blink(mousebuffer,moX,moY);
alSourcePlay (sound_click);

moB[0]=0;//reset
moX=-1;
moY=-1;

 tot_player=temp_player_count+1;
    for(int i=0;i<tot_player;++i)
    player_world[i].type=1;



 ///to be write on ok button....   country nebhour load
 int bonus= 15;

 if(tot_player==2)
  bonus= 30;
if(tot_player==3)
 bonus= 25;
if(tot_player==4)
  bonus= 15;
if(tot_player>5)
  bonus= 10;
//for human
 player_world[0].bonus_arm=bonus;
 
 //bot
for(int i=1;i<tot_player;i++){
{player_world[i].bonus_arm=bonus;
player_world[i].type=0;
}
//// assumed ok
gamestate=1;
}
    ifstream fin("datafile/nebhour_data.dat");
 int temp_int,temp_c_no=0;

    while(fin)
    {fin>>temp_int;
   
	
	if(temp_int==-1)
    temp_c_no++;
	else
	world[temp_c_no].neb.push_back(temp_int);
    }
   
	
   ///init end
   gamestate=1;
mousebuf(mousebuffer,"datafile/screen.bin");

}
else if(mousebuffer[moX][moY]==1&&moB[0]==GLUT_DOWN)
{
if(temp_player_count<5)
temp_player_count++;



blink(mousebuffer,moX,moY);
alSourcePlay (sound_click);

moB[0]=0;//reset
moX=-1;
moY=-1;
}
else if(mousebuffer[moX][moY]==2&&moB[0]==GLUT_DOWN)
{
if(temp_player_count>1)
temp_player_count--;
blink(mousebuffer,moX,moY);
alSourcePlay (sound_click);

moB[0]=0;//reset
moX=-1;
moY=-1;
}
else if(mousebuffer[moX][moY]==4&&moB[0]==GLUT_DOWN)
{
cout<<"help";
blink(mousebuffer,moX,moY);
alSourcePlay (sound_click);
moB[0]=0;//reset
moX=-1;
moY=-1;
}
char msg[3];
itoa(temp_player_count,msg,10);
glColor3f(223/255.0,203/255.0,152/255.0);
glRasterPos3f(510,198,3);
for(int i=0;msg[i]!='\0';++i)
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg[i]);


glColor3f(1,1,1);
moB[0]=GLUT_UP;


}

   ///init end




///.................................................................................

//................................................................................
void loadBasicMap()
{
glClear(GL_COLOR_BUFFER_BIT);

glEnable(GL_TEXTURE_2D);
glColor3f(1,1,1);
glBindTexture(GL_TEXTURE_2D,tid[0]);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
glBegin(GL_QUADS);
glTexCoord2f(0,0);
glVertex3f(0,0,0);
glTexCoord2f(1,0);
glVertex3f(800,0,0);
glTexCoord2f(1,1);
glVertex3f(800,600,0);
glTexCoord2f(0,1);
glVertex3f(0,600,0);
glEnd();
glDisable(GL_TEXTURE_2D);
}

//...............................................................................................

//////////////////////countryfunc   attack k fun def

int attack_once( int atkr,int dfndr){
//aa attecker ..........bb defender

/////grapics



int a,b,result=3;


if(world[dfndr].arm >=2){
                b=2;
                }
                else if(world[dfndr].arm ==1)   b=1;

                else if(world[dfndr].arm == 0 ){ return 1 ;}/////we finly wins(ataker)

if(extra>=3){
                a=3;
                }
                else if(extra==2)  a=2;
                else if(extra==1)  a=1;
                else if(extra==0)  return 0;  //// he finally win(defender)


srand(time(0));

aa.clear();
bb.clear();
for(int i=0;i<a;i++){
        aa.push_back((rand()%5)+1);

	 }

for(int i=0;i<b;i++){
        bb.push_back((rand()%5)+1);
	   }

       sort(aa.begin(),aa.end());
       sort(bb.begin(),bb.end());
reverse(aa.begin(),aa.end());
reverse(bb.begin(),bb.end());
	   
	   
int i=0;int j=0;

if(aa[i]>bb[j])
{ world[dfndr].arm-- ;
////
result =6;
////



}
else{
extra-- ;
 
 ///
result =9;
 
 

 ///
 
 }

i++;j++;
     if(i<aa.size() && j<bb.size()){
      if(aa[i]>bb[j])
      { world[dfndr].arm-- ;

///

result+=1;
//


	  }
       else{
       extra-- ;
//
result+=2;
//
       }

             }



return result; //continue

    }
	
void update_worth(int indx)
    {
    	int enmy_ctry=0,my_ctry=0,enmy_arm=0,my_arm=0,own;
    	

     for(int i=0;i<world[indx].neb.size();++i)
     {

     	if(world[indx].owner!=world[world[indx].neb[i]].owner)
     	{
     		enmy_arm+=world[world[indx].neb[i]].arm;
     		enmy_ctry++;

     	}
     	else
     	{
     	my_arm+=world[world[indx].neb[i]].arm;
     	my_ctry++;	
     	}
       }

	 
	   world[indx].worth =  (TUNE_ENMY_CTRY *enmy_ctry)+(TUNE_MY_CTRY * my_ctry) + (TUNE_ENMY_ARM *enmy_arm)+(TUNE_MY_ARM *my_arm);
	 
      
	  }
	

int ai_aq(){

int ans=0 ,indx=0;
float max=-32940;
	for( indx=0;indx<42;indx++)
    {if(world[indx].owner!=-1)
	 continue;
	 
    	float enmy_ctry=0,my_ctry=0,noman=0;
    	

     for(int i=0;i<world[indx].neb.size();++i)
     {
	 	if(player_no!=world[world[indx].neb[i]].owner)
     	{
     		enmy_ctry++;

     	}
		else if(world[world[indx].neb[i]].owner==-1){
		noman++;
		}
     	else
     	{
     	my_ctry++;	
     	}
       }

	   
	    if(( ( (-0.6) *enmy_ctry)+( my_ctry) + (0.3 * noman))>max)
	   {
	   max=( ( (-0.6) *enmy_ctry)+( my_ctry) + (0.3 * noman));
	   ans=indx;
	   
	   
	   }
	  }
	return ans;
	}
	
	
	
	
	/////////////////////////////////////////////////////////////////////////////////////////

struct newS
 {
 	int arm,indx;
 	float wPa;
 	bool operator<(const newS& a) const
    {
        return wPa < a.wPa;
    }
 };
    

 

	///////////////////////
	void reinforce_bot(int player_number)
{
	float tmp;
	int ff;
	float mx,nrm;

	vector < newS> ara;
	newS newse;
for(int k=0;k<=player_world[player_number].bonus_arm;++k)
				{
					
	for(int i=0;i<player_world[player_number].my_country.size();++i)
	{ff=0;
		            tmp=0;
		            mx=-9999;
		

		for (int j = 0; j < world[player_world[player_number].my_country[i]].neb.size(); ++j)
		{
			if( world[world[player_world[player_number].my_country[i]].neb[j]].owner!=player_number)
				{nrm=max(world[player_world[player_number].my_country[i]].arm+k,world[world[player_world[player_number].my_country[i]].neb[j]].arm)+1;

				 tmp=world[world[player_world[player_number].my_country[i]].neb[j]].worth * prob_mat[int(10*(world[player_world[player_number].my_country[i]].arm+k)/nrm)] [int(10*(world[world[player_world[player_number].my_country[i]].neb[j]].arm)/nrm)] ;
				tmp=tmp/(k+0.01);
				if(tmp>mx)
				{
					mx=tmp;
					ff=j;
				}

				}
			}
				newse.arm=k;
				newse.indx=player_world[player_number].my_country[i];
				newse.wPa=mx;
				ara.push_back(newse);

		}
    

	}
	sort(ara.begin(),ara.end());
	
	while(ara.size()>0)
	{
		debug(ara[ara.size()-1].wPa);
		if(player_world[player_number].bonus_arm-ara[ara.size()-1].arm>=0)
		{
			player_world[player_number].bonus_arm-=ara[ara.size()-1].arm;
			world[ara[ara.size()-1].indx].arm+=ara[ara.size()-1].arm;
		}
		ara.pop_back();
	}
}
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////