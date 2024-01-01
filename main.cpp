#include "iGraphics.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>

struct highscorer
{
 char name[100];
 int sss;

}high[1000];
int final_score;
int x = 200, y = 20, r = 20;
int len;
int mode=0;
int R=255,G=255,B=255;
int text_y=100;
int flag=0, horn=0,display1=1,display2=0,display3=0,display4=0;
int stop1=0,stop2=0,stop3=0,stop4=0;
int carselector=0;
int life=3;
char score[1000],str[1000],str2[1000];
char *car="car.bmp";
int Point=0;
int currentscore;
int y1_tree=2000,y2_tree=1300,y3_tree=1700;

int x_car=220,y_car=230;
int temp1,temp2,temp3;
int x_opponent1_car=120 , x_opponent2_car=220,x_opponent3_car=320,x_opponent4_car=20;
int y_opponent1_car=1010,y_opponent2_car=1100,y_opponent3_car=1500,y_opponent4_car=2000;
int change = 500;
int carspeed = 500;
int multiply=1000;
double road=1000;

int initial_time=0;


int n;
/*
	function iDraw() is called again and again by the system.

	*/

void credit_text_scroll()
{   if (text_y>=1300)

    text_y =100;
    text_y +=1;
}
int credit=iSetTimer(10,credit_text_scroll);
void colour_change_of_score()
{
    srand(time(NULL));
    R=rand()%255+1;
    G=rand()%60+1;
    B=rand()%255+1;

}

void drawTextBox()
{
    iSetColor(500,123,122);
    iText(50,290,"Enter Your Name :",GLUT_BITMAP_HELVETICA_18);
	iSetColor(150, 150, 150);
	iRectangle(50, 250, 250, 30);
}

void timE()
{
    initial_time+=1;
}

void score_increase()
{
    Point +=1;
}
int t=iSetTimer(500,score_increase);


void time_forward()
{
    multiply -=10;
}
void down_move()
{
    change -=1;
}
void opponent_fast()
{
    srand(time(NULL));
    if (y_opponent1_car==0)
    {
        y_opponent1_car=rand()%1000+1100;
            temp1=x_opponent1_car;
            x_opponent1_car=x_opponent4_car;
            x_opponent4_car=temp1;


    }
    if (y_opponent2_car==0)
    {
        y_opponent2_car=rand()%1000+1300;
        x_opponent2_car=320;

    }
    if (y_opponent3_car==0)
    {

        y_opponent3_car=rand()%1000+1000;
        x_opponent3_car=220;

    }
    if (y_opponent4_car==0)
    {
        y_opponent4_car=rand()%1000+1200;

    }
    y_opponent1_car -=Point*0.01;
    y_opponent2_car -=Point*0.01;
    y_opponent3_car -=Point*0.01;
    y_opponent4_car -=Point*0.01;
}
int o=iSetTimer(1,opponent_fast);
void fast()
{
    road -=1;
    if (road==0) road = 600;
    y2_tree -=1;
    if(y2_tree<=0) y2_tree +=1300;
    y3_tree -=1;
      if(y3_tree<=0) y3_tree +=1700;
      y1_tree -=1;
      if(y1_tree<=0) y1_tree +=2000;
}


void left()
{
    if (x_car>=20)   x_car -=10;
}
void right()
{
    if (x_car<=320) x_car +=10;
}
void up()
{
    if (y_car<=850) y_car +=10;
}
void down()
{
    if (y_car>=240)   y_car -=10;
}
void left_down()
{
    if (x_car>=20 && y_car>=240)   x_car -=10,y_car -=10;
}
void left_up()
{
    if (x_car>=20 && y_car<=850)   x_car -=10,y_car +=10;
}
void right_down()
{
    if (x_car<=320 && y_car>=240)   x_car +=10,y_car -=10;
}
void right_up()
{
    if (x_car<=320 && y_car<=850)   x_car +=10,y_car +=10;
}

void iDraw()
{
    //place your drawing codes here
    iClear();
    initial_time++;

     if (flag==100) ///Game OVER
 {
    mode=1;
     Point=0;
     iShowBMP(0,150,"game_over.bmp");
     iShowBMP(10,944,"back.bmp");

     iSetColor(255,255,255);
     iText(390,765,score,GLUT_BITMAP_TIMES_ROMAN_24);
     if(mode == 1)
	{
		drawTextBox();
		iSetColor(255, 255, 255);
		iText(55, 260, str);
	}


 }
    if(flag==0 || flag==2 || flag==3)
    {
        iPauseTimer(t);
    }
    if (flag==0)
    {
        iShowBMP(0,150,"scene_1.bmp");
        iPauseTimer(credit);
        iPauseTimer(o);
        iPauseTimer(t);

    }

    if (flag==2)
    {
        iPauseTimer(credit);
        iPauseTimer(credit);
        iPauseTimer(o);
        iShowBMP(0,150,"car_selector.bmp");
        iShowBMP(0,280,"display1.bmp");
        if(display1==1)
        {
            iShowBMP(0,280,"display1.bmp");
            car="car.bmp";




        }
        if (display2==1)
        {
            iShowBMP(0,280,"display2.bmp");
             car="car2.bmp";
        }
        if(display3==1)
        {
             iShowBMP(0,280,"display3.bmp");
              car="car3.bmp";
        }
        if(display4==1)
        {
             iShowBMP(0,280,"display4.bmp");
              car="car4.bmp";
        }

        iSetColor(250,50,50);
        iFilledCircle(135,220,20,100);
        iSetColor(15,10,196);
        iFilledCircle(235,220,20,100);
        iSetColor(6,206,255);
        iFilledCircle(335,220,20,100);
        iSetColor(255,255,255);
        iFilledCircle(435,220,20,100);
        iShowBMP(240,280,"play_button.bmp");


    } ///Eng of Flag 2 or display car options

    if (flag==3)
    {
    iPauseTimer(o);
    iPauseTimer(t);
    iPauseTimer(credit);
    iShowBMP(0,150,"game_pause.bmp");
    iShowBMP(260,800,"play.bmp");
    iShowBMP(260,720,"quit.bmp");
    iShowBMP(260,640,"close.bmp");
    iSetColor(0,0,0);
    iText(312,816,"Resume",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(312,737,"Main Menu",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(312,660,"Quit",GLUT_BITMAP_TIMES_ROMAN_24);

    }

    if (flag==4)
    {   iPauseTimer(o);
        iPauseTimer(t);
        iResumeTimer(credit);
        iShowBMP(0,150,"credit.bmp");
        iSetColor(R,G,B);
        iText(100,text_y+80,"SUPERVISOR : MAHMUDUR RAHMAN HERA",GLUT_BITMAP_HELVETICA_18);
        iText(200,text_y+50,"LECTURER, DEPT OF CSE, BUET",GLUT_BITMAP_HELVETICA_18);
        iText(100,text_y-20," ~####### CREATED  BY #######~",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,255,255);
          iText(180,text_y-100,"       SHAMIM AHSAN",GLUT_BITMAP_HELVETICA_18);
            iText(180,text_y-130,"       CSE,BUET (17)",GLUT_BITMAP_HELVETICA_18);
                    iText(180,text_y-200,"       RIDWANUL HAQUE ",GLUT_BITMAP_HELVETICA_18);
                            iText(180,text_y-230,"       CSE,BUET (17) ",GLUT_BITMAP_HELVETICA_18);
                                    iText(180,text_y-300,"       SOHAM KHISA",GLUT_BITMAP_HELVETICA_18);
                                            iText(180,text_y-330,"       CSE,BUET (17)",GLUT_BITMAP_HELVETICA_18);
        iShowBMP(10,920,"back.bmp");

    }
    if (flag==5)
    {
        iShowBMP(0, 150, "green_board.bmp");
        iShowBMP(35,913,"back.bmp");
        iSetColor(0,0,255);

        iSetColor(255,255,255);


        FILE *fp;
        fp= fopen("score.txt","r");
        int idx=0;
        while(!feof(fp))
        {
            fscanf(fp,"%s %d",high[idx].name,&high[idx].sss);
            idx++;
            if(feof(fp))
                break;
        }
        fclose(fp);

        while(1)
        {
            int swapped=0;
            for(int ini=0;ini<idx-1;ini++)
            {
                if(high[ini].sss<high[ini+1].sss)
                {
                    int temp=high[ini].sss;
                    high[ini].sss=high[ini+1].sss;
                    high[ini+1].sss=temp;
                    char nam[1000];
                    strcpy(nam,high[ini].name);
                    strcpy(high[ini].name,high[ini+1].name);
                    strcpy(high[ini+1].name,nam);
                    swapped=1;
                }
            }
            if(swapped==0)
                break;
        }

        iText(160,828,"### HALL  OF  FAME ###",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(144,820,"________________________",GLUT_BITMAP_TIMES_ROMAN_24);
        int y_y=730;
        for(int ini=0;ini<5;ini++)
        {
            iText(200,y_y,high[ini].name,GLUT_BITMAP_TIMES_ROMAN_24);
            char show[100];
            itoa(high[ini].sss,show,10);
            iText(380,y_y,show,GLUT_BITMAP_TIMES_ROMAN_24);
            y_y-=50;

        }

    }

    if (flag==1)
    {
    iPauseTimer(credit);
    iResumeTimer(t);
    iResumeTimer(o);
    iSetColor(123,687,654);

    iSetColor(255,255,255);
    iFilledRectangle(0,0,600,1000);


    iSetColor(255,255,51);
    iFilledRectangle(400, 00, 4, 1000);
    iSetColor(20, 200, 0);




    ///Road Divider1
    iSetColor(0,0,0);
    iFilledRectangle(98,road,4,70);
    iFilledRectangle(98,road-100,4,70);
    iFilledRectangle(98,road-200,4,70);
    iFilledRectangle(98,road-300,4,70);
    iFilledRectangle(98,road-400,4,70);
    iFilledRectangle(98,road-500,4,70);
    iFilledRectangle(98,road-600,4,70);
    iFilledRectangle(98,road-700,4,70);
    iFilledRectangle(98,road-800,4,70);
    iFilledRectangle(98,road-900,4,70);
    iFilledRectangle(98,road+1000,4,70);
    iFilledRectangle(98,road+100,4,70);
    iFilledRectangle(98,road+200,4,70);
    iFilledRectangle(98,road+300,4,70);
    iFilledRectangle(98,road+400,4,70);
    iFilledRectangle(98,road+500,4,70);
    iFilledRectangle(98,road+600,4,70);
    iFilledRectangle(98,road+700,4,70);
    iFilledRectangle(98,road+800,4,70);
    iFilledRectangle(98,road+900,4,70);
    iFilledRectangle(98,road+1000,4,70);


    ///Road Divider2
    iSetColor(0,0,0);
    iFilledRectangle(198,road,4,70);
    iFilledRectangle(198,road-100,4,70);
    iFilledRectangle(198,road-200,4,70);
    iFilledRectangle(198,road-300,4,70);
    iFilledRectangle(198,road-400,4,70);
    iFilledRectangle(198,road-500,4,70);
    iFilledRectangle(198,road-600,4,70);
    iFilledRectangle(198,road-700,4,70);
    iFilledRectangle(198,road-800,4,70);
    iFilledRectangle(198,road-900,4,70);
    iFilledRectangle(198,road+1000,4,70);
    iFilledRectangle(198,road+100,4,70);
    iFilledRectangle(198,road+200,4,70);
    iFilledRectangle(198,road+300,4,70);
    iFilledRectangle(198,road+400,4,70);
    iFilledRectangle(198,road+500,4,70);
    iFilledRectangle(198,road+600,4,70);
    iFilledRectangle(198,road+700,4,70);
    iFilledRectangle(198,road+800,4,70);
    iFilledRectangle(198,road+900,4,70);
    iFilledRectangle(198,road+1000,4,70);

    ///Road Divider3
    iSetColor(0,0,0);
    iFilledRectangle(298,road,4,70);
    iFilledRectangle(298,road-100,4,70);
    iFilledRectangle(298,road-200,4,70);
    iFilledRectangle(298,road-300,4,70);
    iFilledRectangle(298,road-400,4,70);
    iFilledRectangle(298,road-500,4,70);
    iFilledRectangle(298,road-600,4,70);
    iFilledRectangle(298,road-700,4,70);
    iFilledRectangle(298,road-800,4,70);
    iFilledRectangle(298,road-900,4,70);
    iFilledRectangle(298,road+1000,4,70);
    iFilledRectangle(298,road+100,4,70);
    iFilledRectangle(298,road+200,4,70);
    iFilledRectangle(298,road+300,4,70);
    iFilledRectangle(298,road+400,4,70);
    iFilledRectangle(298,road+500,4,70);
    iFilledRectangle(298,road+600,4,70);
    iFilledRectangle(298,road+700,4,70);
    iFilledRectangle(298,road+800,4,70);
    iFilledRectangle(298,road+900,4,70);
    iFilledRectangle(298,road+1000,4,70);




    ///main car
    iShowBMP(x_car,y_car,car);

    ///opponent car 1 :
    iShowBMP(x_opponent1_car,y_opponent1_car,"opponent.bmp");

    ///opponent car 2 :
    iShowBMP(x_opponent2_car,y_opponent2_car,"opponent2.bmp");

    ///opponent car 3 :
    iShowBMP(x_opponent3_car,y_opponent3_car,"opponent3.bmp");

    ///opponent car 4:
    iShowBMP(x_opponent4_car,y_opponent4_car,"opponent4.bmp");


    iSetColor(255,255,255);
    iFilledRectangle(0,0,600,230);
    iSetColor(158,9,83); ///giving border
    iLine(0,230,600,230);


    ///CRASH CODE :

///Head to Head
    if (abs(x_opponent1_car-x_car)<=58 && y_car+160==y_opponent1_car)
        {
            life -=1;
            y_opponent1_car +=1000;
        }
        if (abs(x_opponent2_car-x_car)<=58 && y_car+160==y_opponent2_car)
        {
            life -=1;
            y_opponent2_car +=1000;
        }
        if (abs(x_opponent3_car-x_car)<=58 && y_car+160==y_opponent3_car)
        {
            life -=1;
            y_opponent3_car +=1000;
        }
        if (abs(x_opponent4_car-x_car)<=58 && y_car+160==y_opponent4_car)
        {
            life -=1;
            y_opponent4_car +=1000;
        }
///Back to Head
    if (abs(x_opponent1_car-x_car)<=58 && y_car==y_opponent1_car+180+20)
        {
            life -=1;
            y_opponent1_car +=1000;
        }
        if (abs(x_opponent2_car-x_car)<=58 && y_car==y_opponent2_car+118+10)
        {
            life -=1;
            y_opponent2_car +=1000;
        }
        if (abs(x_opponent3_car-x_car)<=58 && y_car==y_opponent3_car+154+10)
        {
            life -=1;
            y_opponent3_car +=1000;
        }
        if (abs(x_opponent4_car-x_car)<=58 && y_car==y_opponent4_car+144+10)
        {
            life -=1;
            y_opponent4_car +=1000;
        }



///Side to Side Crash :
///1
if  ( (abs(x_car-x_opponent1_car)<=60-2) && (abs(y_opponent1_car-y_car)<=180-2) )
{
    life -=1;
    printf("x_car = %d      x_opponent_1 = %d\n",x_car,x_opponent1_car);
    printf("y_car = %d      y_opponent_1 = %d\n",y_car,y_opponent1_car);
    y_opponent1_car +=1000;
}

if  ( (abs(x_opponent1_car-x_car)<=60-2) && (abs(y_opponent1_car-y_car)<=180-2) )
{
    life -=1;
    printf("x_car = %d      x_opponent_1 = %d\n",x_car,x_opponent1_car);
    printf("y_car = %d      y_opponent_1 = %d\n",y_car,y_opponent1_car);
    y_opponent1_car +=1000;
}
///2
if  ( (abs(x_car-x_opponent2_car)<=60-2) && (abs(y_opponent2_car-y_car)<=118-2) )
{
    life -=1;
    printf("x_car = %d      x_opponent_1 = %d\n",x_car,x_opponent1_car);
    printf("y_car = %d      y_opponent_1 = %d\n",y_car,y_opponent1_car);
    y_opponent2_car +=1000;
}

if  ( (abs(x_opponent2_car-x_car)<=60-2) && (abs(y_opponent2_car-y_car)<=118-2) )
{
    life -=1;
    printf("x_car = %d      x_opponent_1 = %d\n",x_car,x_opponent1_car);
    printf("y_car = %d      y_opponent_1 = %d\n",y_car,y_opponent1_car);
    y_opponent2_car +=1000;
}

///3
if  ( (abs(x_car-x_opponent3_car)<=60-2) && (abs(y_opponent3_car-y_car)<=154-2) )
{
    life -=1;
    printf("x_car = %d      x_opponent_1 = %d\n",x_car,x_opponent1_car);
    printf("y_car = %d      y_opponent_1 = %d\n",y_car,y_opponent1_car);
    y_opponent3_car +=1000;
}

if  ( (abs(x_opponent3_car-x_car)<=60-2) && (abs(y_opponent3_car-y_car)<=154-2) )
{
    life -=1;
    printf("x_car = %d      x_opponent_1 = %d\n",x_car,x_opponent1_car);
    printf("y_car = %d      y_opponent_1 = %d\n",y_car,y_opponent1_car);
    y_opponent3_car +=1000;
}

///4
if  ( (abs(x_car-x_opponent4_car)<=60-2) && (abs(y_opponent4_car-y_car)<=144-2) )
{
    life -=1;
    printf("x_car = %d      x_opponent_1 = %d\n",x_car,x_opponent1_car);
    printf("y_car = %d      y_opponent_1 = %d\n",y_car,y_opponent1_car);
    y_opponent4_car +=1000;
}

if  ( (abs(x_opponent4_car-x_car)<=60-2) && (abs(y_opponent4_car-y_car)<=144-2) )
{
    life -=1;
    printf("x_car = %d      x_opponent_1 = %d\n",x_car,x_opponent1_car);
    printf("y_car = %d      y_opponent_1 = %d\n",y_car,y_opponent1_car);
    y_opponent4_car +=1000;
}

iShowBMP(408,y2_tree,"tree2.bmp");
iShowBMP(408,y3_tree,"tree3.bmp");
iShowBMP(412,y1_tree,"tree.bmp");




 iShowBMP(0,155,"logo.bmp"); ///Score Board
 iShowBMP(500,736,"pause.bmp");
 iShowBMP(470,820,"score_card.bmp");

 iSetColor(255,255,255);
 iText(502,938,"SCORE",GLUT_BITMAP_HELVETICA_18);
iSetColor(0,0,0);
 iRectangle(490,890,90,36);
 iSetColor(R,G,B);
 itoa(Point,score,10);
 iText(525,900,score,GLUT_BITMAP_TIMES_ROMAN_24);

 iSetColor(255,255,255);
 if (life==3)
 {
      iText(497,850,"LIFE : 3",GLUT_BITMAP_TIMES_ROMAN_24);
 }
  if (life==2)
 {
      iText(497,850,"LIFE : 2",GLUT_BITMAP_TIMES_ROMAN_24);
 }
  if (life==1)
 {
      iText(497,850,"LIFE : 1",GLUT_BITMAP_TIMES_ROMAN_24);
 }

 if (life==0)
 {
     flag=100; ///Game Over
     life=3;
     y_opponent1_car=1010;y_opponent2_car=1100;y_opponent3_car=1500;y_opponent4_car=2000;y_car=230;
     final_score=Point;

     return;
 }



} ///END OF FLAG 1 or Main Game




}







/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my)
{

    //place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my)
{

    if (flag==0)
    {
        life=3;
        Point=0;
    }
     if (flag==0 && mx>=210 && mx<=390 && my>=895 && my<=930)
    {
        flag=1; ///flag 1 starts the game
        PlaySound("music\\background.wav",NULL,SND_LOOP|SND_ASYNC);

    }


    if (flag==0 && mx>=150 && mx<=448 && my>=848 && my<=880)
    {
        flag=2; ///flag 2 selects the car

        life=3;


    }




    if (flag==2)
    {
        if (mx>=116 && mx<=153 && my>=341 && my<=372)
        {
            display1=1;
            display2=0;
            display3=0;
            display4=0;

        }
            if (mx>=218 && mx<=252 && my>=344 && my<=372)
        {
            display1=0;
            display2=1;
            display3=0;
            display4=0;

        }
        if (mx>=316 && mx<=354 && my>=342 && my<=374)
        {
            display1=0;
            display2=0;
            display3=1;
            display4=0;

        }

        if (mx>=415 && mx<=452 && my>=346 && my<=375)
        {
            display1=0;
            display2=0;
            display3=0;
            display4=1;

        }
        if (mx>=243 && mx<=336 && my>=410 && my<=434)
        {
           flag=1;

        }




    }
            if (flag==1 && mx>=500 && mx<=562 && my>=784 && my<=846)
        {
           flag=3; ///flag 3 brings the pause menu

        }
        if (flag==3 && mx>=250 && mx<=308 && my>=836 && my<=878) ///flag 3 indicates pause section
        {
            flag=1;
        }
                if (flag==3 && Point!=0 && mx>=260 && mx<=308 && my>=772 && my<=810)
        {
            flag=0;
            Point=0;
            y_opponent1_car=1010;y_opponent2_car=1100;y_opponent3_car=1500;y_opponent4_car=2000;y_car=230;


        }
                if (flag==3 && mx>=260 && mx<=308 && my>=705 && my<=747)
        {
            exit(0);
        }
         if (flag==0 && mx>=194 && mx<=404 && my>=800 && my<=833)
        {
            flag=4; ///flag 4 indicates Credit;
        }
        if (flag==4 && Point==0 && mx>=11 && mx<=155 && my>=936 && my<=980)
        {
            flag = 0;
        }
        if (flag==100 && mx>=11 && mx<=155 && my>=955 && my<=999) ///GAME OVER
        {
            flag = 0;
        }
        if (flag==0 && mx>=245 && mx<=364 && my>=760 && my<=784)
        {
           exit(0);
        }
        if (flag==1)      PlaySound("music\\background.wav",NULL,SND_LOOP|SND_ASYNC);
        if (flag==0 && mx>=442 && mx<=596 && my>=964 && my<=996)
        {
            flag=5;
        }
        if (flag==5 && mx>=37 && mx<=180 && my>=932 && my<=973)
        {
            flag=0;
        }


    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
        //printf("x = %d, y= %d\n",mx,my);
        x += 10;
        y += 10;
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
        x -= 10;
        y -= 10;
    }


        printf("x = %d, y= %d\n",mx,my);

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key)
{


     if (key == 'h' || key == 'H')
    {

             PlaySoundA("music\\horn.wav",NULL,SND_ASYNC);




    }







    if(flag==100)
	{

        if(key == '\r')
		{
			//mode = 0;
			strcpy(str2, str);
			printf("%s\n", str2);
			FILE *fp;
			fp=fopen("score.txt","a");
			fprintf(fp,"\n%s %d",str2,final_score);
			fclose(fp);
			for(int i = 0; i < len; i++)
				str[i] = 0;
			len = 0;

		}
		else
		{
			str[len] = key;
			len++;
		}

}

    //place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key)
{

    if (key == GLUT_KEY_UP)
    {
        up();


    }
        if (key == GLUT_KEY_DOWN)
    {
        down();

    }
        if (key == GLUT_KEY_LEFT)
    {
        left();

    }
        if (key == GLUT_KEY_RIGHT)
    {
        right();

    }
    //place your codes for other keys here
}


int main()
{
    //place your own initialization codes here.


    iSetTimer(20,down_move);
    iSetTimer(10,time_forward);


    iSetTimer(1,opponent_fast);



    iSetTimer(10,fast);

    iSetTimer(50,colour_change_of_score);
    iSetTimer(1000,timE);
    iSetTimer(10,credit_text_scroll);


    iInitialize(600, 1000, "Infinite Racing 2018");


    return 0;
}

