#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include<time.h>
#include<unistd.h>
#include<curses.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdbool.h>
#ifndef  MainGameView.h
#define  MainGameView.h
int alldied=0;
typedef struct{
    int doorx;
    int doory;
    int show;
    int showlit;
    int x;
    int y;
    int width, height;
} House;
typedef struct{
    int x;
    int y;
    int gone;
}Trap;
typedef struct{
    int show;
    char is;
    int x;
    int y;
}Rahro;
typedef struct {
    int issignedin;
    int  golds;
    int energy;
    int points;
    int rank;
    int  nplayed;
    int nfinished;
     int health;
    char  username[30];
}Player;
typedef struct{
   int firstx;
   int firsty;
   int x;
   int y;
   int room;
   int health;
   int damage;
   int cantmove;
   int floor;
   int noe;
   int canbesh;
   int isfreez;
   int isdead;
}Enemy;
typedef struct{
  int x;
  int y;
}Rahpele;
Rahpele rahpele[5];
extern int gamewin=0;
extern int g12=0;
extern int g22=0;
extern int g32=0;
extern int g42=0;
extern int g52=0;
extern int h21=0;
extern int h22=0;
extern int h23=0;
 extern int h24=0;
extern int nfood1=0;
extern int nfood2=0;
extern int nfood3=0;
extern int h25=0;
extern int isfirstvisit[5]={1,1,1,1,1};
extern int enemydiedwarn=0;
extern int enemydamwarn=0;
extern int youdamwarn=0;
extern int nenemy=0;
extern int nenemy2=0;
extern int nenemy3=0;
extern int nenemy4=0;
extern int playerroom=0;
extern int  hasfoodpicker=0;
extern int haswpnpicker=0;
extern int  lnrahro=0;
extern int  lnrahro2=0;
extern int  lnrahro3=0;
extern int  lnrahro4=0;
extern int checkrahro=0;
extern int numkey=0;
extern int recgold=0;
extern int maxhealth=0;
extern int nsootoon=0;
extern int  nsootoon2=0;
extern int  nsootoon3=0;
extern int nsootoon4=0;
extern int nhouse=0;
extern int jahatsh=0;
extern int xsoot[6]={0,0,0,0,0,0};
extern int ysoot[6]={0,0,0,0,0,0};
extern int xsoot2[6]={0,0,0,0,0,0};
extern int ysoot2[6]={0,0,0,0,0,0};
extern int xsoot3[6]={0,0,0,0,0,0};
extern int ysoot3[6]={0,0,0,0,0,0};
extern int xsoot4[6]={0,0,0,0,0,0};
extern int ysoot4[6]={0,0,0,0,0,0};
extern int nrahpele[4]={0,0,0,0,0};
 extern char **map=0;
 extern int **mapshow=0;
 extern char **map2=0;
 extern int **mapshow2=0;
 extern  int playerhealth=60;
 extern int numberOfHouses=0;
 extern int distance=0;
 extern int beinghungry=100;
 extern int golds=0;
 extern int point=0; 
 extern int playerx=5;
 extern int playery=5;
 extern int colort=1;
 extern int floorx=1;
 extern int playerattack=1;
 extern int maxHeight=0;
 extern int maxWidth=0;
 extern int ishungry=0;
 extern int isveryhungry=0;
 extern int isvalidmove=1;
 extern int isfast=0;
 extern int zaribsoraat=1;
 extern  int haspanj[6]={0,0,0,0,0,0};
 extern int npanjtot=0;
 extern int nfood[3]={0,0,0};
 extern int nmajoon[3]={0,0,0};
 extern int nwp[5]={0,0,0,0,0};
 extern int foodchoice=0;
 extern int weaponchoice=0;
 extern int majoonchoice=0;
 extern int hasfooder=0;
 extern int hasmajooner=0;
 extern int hasweaponer=0;
 extern int weaponon=1;
 extern int atebadfood=0;
 extern int maxhealther=0;
 extern int haspower=0;
 extern int hasfast=0;
 extern int hashealtht=0;
 extern int distancehasht=0;
 extern int distancefast=0;
 extern int distancepower=0;
 extern int ntrap=0;
 extern int showfull=0;
 extern int allroomchecked=0;
 extern int nhousesshow=0;
 extern int ntrap2=0;
 extern int showfull2=0;
 extern int allroomchecked2=0;
 extern int nhousesshow2=0;
 extern int ntrap3=0;
 extern int showfull3=0;
 extern int allroomchecked3=0;
 extern int nhousesshow3=0;
 extern int ntrap4=0;
 extern int showfull4=0;
 extern int allroomchecked4=0;
 extern int nhousesshow4=0;
 extern int isfast1=0;
extern int mahdoode=0;
extern int zarbe=0;
extern int haswpner2=0;
extern int hasbadshot=0;
extern int nottal=0;
 Trap   trap[6];
 House *houses[50];
 House *houses2[50];
 Rahro rahro[500];
 Player players[200];
 Enemy enemy[200];
 #endif
 int highlightmusicp=1;
 int dx,dy;
 int choicemenup=0;
 int highlightmenup=1;
 
 
int mainview(){
    houses[2]->show=1;
     drawmapborder();
    connectHouses(houses,numberOfHouses);
    while(1){
      numkey++;
        if(!allroomchecked){
        nhousesshow=0;
       for(int i=0;i<6;i++){
           if(houses[i]->show==1){
             nhousesshow++;
           }
           else{
            break;
           }
      }
      if(nhousesshow>4){
        allroomchecked=1;
      }
    }
    
    checkinroom();
    checkarea();
    checkend();
    checkkharabifood();
    enemymovement();
    enemydamage();
    isvalidmove=0;
    if(isfast1||hasfast){
        isfast=1;
        zaribsoraat=2;
    }
    else{
      isfast=0;
      zaribsoraat=1;
    }
     isvalidmove=0;
     int xx=0;
     int c5=getch();
     switch(c5){
        case 'p':
        case 'P':
          int h=pausemenu();
          if(h==0){
            return h;
          }
          else{
            return mainview();
          }
          break;
        case 's':
        case 'S':
           dx=0;
           dy=1*zaribsoraat;
           xx=checkmovement(playerx,playery,dx,dy,map,mapshow);
           if(xx==1){
             playerx+=dx;
             playery+=dy;
             isvalidmove=1;
              distance+=1;
           }
           else if(xx==2){
               playerx+=dx/2;
               playery+=dy/2;
               isvalidmove=1;
               distance+=1;
           }
           else{
            isvalidmove=0;
           }
           break;
        case 'w':
        case 'W':
           dx=0;
           dy=-1*zaribsoraat;
            xx=checkmovement(playerx,playery,dx,dy,map,mapshow);
           if(xx==1){
             playerx+=dx;
             playery+=dy;
             isvalidmove=1;
              distance+=1;
           }
           else if(xx==2){
               playerx+=dx/2;
               playery+=dy/2;
               isvalidmove=1;
               distance+=1;
           }
           else if(xx==0){
            isvalidmove=0;
           }
           break;
        case 'd':
        case 'D':
           dx=1*zaribsoraat;
           dy=0;
            xx=checkmovement(playerx,playery,dx,dy,map,mapshow);
           if(xx==1){
             playerx+=dx;
             playery+=dy;
             isvalidmove=1;
              distance+=1;
           }
           else if(xx==2){
               playerx+=dx/2;
               playery+=dy/2;
               isvalidmove=1;
               distance+=1;
           }
           else{
            isvalidmove=0;
           }
           break;
        case 'a':
        case 'A': 
           dx=-1*zaribsoraat;
           dy=0;
           xx=checkmovement(playerx,playery,dx,dy,map,mapshow);
           if(xx==1){
             playerx+=dx;
             playery+=dy;
             isvalidmove=1;
              distance+=1;
           }
           else if(xx==2){
               playerx+=dx/2;
               playery+=dy/2;
               isvalidmove=1;
               distance+=1;
           }
           else{
            isvalidmove=0;
           }
           break;
        case 'e':
        case 'E':
            dx=1*zaribsoraat;
           dy=-1*zaribsoraat;
           xx=checkmovement(playerx,playery,dx,dy,map,mapshow);
           if(xx==1){
             playerx+=dx;
             playery+=dy;
             isvalidmove=1;
              distance+=1*zaribsoraat;
           }
           else if(xx==2){
               playerx+=dx/2;
               playery+=dy/2;
               isvalidmove=1;
               distance+=1;
           }
           else{
            isvalidmove=0;
           }
           break;
        case 'q':
        case 'Q': 
           dx=-1*zaribsoraat;
           dy=-1*zaribsoraat;
            xx=checkmovement(playerx,playery,dx,dy,map,mapshow);
           if(xx==1){
             playerx+=dx;
             playery+=dy;
             isvalidmove=1;
              distance+=1;
           }
           else if(xx==2){
               playerx+=dx/2;
               playery+=dy/2;
               isvalidmove=1;
               distance+=1;
           }
           else{
            isvalidmove=0;
           }
           break;
        case 'x':
        case 'X':
           dx=1*zaribsoraat;
           dy=1*zaribsoraat;
            xx=checkmovement(playerx,playery,dx,dy,map,mapshow);
           if(xx==1){
             playerx+=dx;
             playery+=dy;
             isvalidmove=1;
              distance+=1*zaribsoraat;
           }
           else if(xx==2){
               playerx+=dx/2;
               playery+=dy/2;
               isvalidmove=1;
               distance+=1;
           }
           else{
            isvalidmove=0;
           }
           break;
        case 'Z':
        case 'z':
            dx=-1*zaribsoraat;
           dy=1*zaribsoraat;
            xx=checkmovement(playerx,playery,dx,dy,map,mapshow);
           if(xx==1){
             playerx+=dx;
             playery+=dy;
             isvalidmove=1;
              distance+=1*zaribsoraat;
           }
           else if(xx==2){
               playerx+=dx/2;for(int i=0;i<maxHeight;i++){
        for(int j=0;j<maxWidth;j++){
            mapshow[i][j]=0;
        }
    }
               playery+=dy/2;
               isvalidmove=1;
               distance+=1;
           }
           else{
            isvalidmove=0;
           }
           break;
        case 'm':
        case 'M':
            if(showfull){
                showfull=0;
            }
            else{
                showfull=1;
            }
            if(allroomchecked){
                showfull=1;
            }
            break;
        case 'g':
        case 'G':
           if(map[playery][playerx]=='1'){
            if(nfood[0]<5){
                map[playery][playerx]='.';
                nfood[0]++;
            }
            else{
                hasfoodpicker=1;
            }
           }
           else if(map[playery][playerx]=='2'){
              if(nfood[1]<5){
                map[playery][playerx]='.';
                nfood[1]++;
            }
            else{
                hasfoodpicker=1;
            } 
           }
           else if(map[playery][playerx]=='3'){
               if(nfood[2]<5){
                 map[playery][playerx]='.';
                 nfood[2]++;
               }
               else{
                 hasfoodpicker=1;
               }
             
           }
           else if(map[playery][playerx]=='4'){
              if(nmajoon[0]<5){
                 map[playery][playerx]='.';
                 nmajoon[0]++;
               }
               else{
                 hasfoodpicker=1;
               }
              
           }
           else if(map[playery][playerx]=='5'){
              if(nmajoon[1]<5){
                 map[playery][playerx]='.';
                 nmajoon[1]++;
               }
               else{
                 hasfoodpicker=1;
               }
           }
           else if(map[playery][playerx]=='6'){
              if(nmajoon[3]<5){
                 map[playery][playerx]='.';
                 nmajoon[2]++;
               }
               else{
                 hasfoodpicker=1;
               }
           }
           else if(map[playery][playerx]=='B'){
                 map[playery][playerx]='.';
                 nwp[1]+=10;
           }
           else if(map[playery][playerx]=='N'){
                 map[playery][playerx]='.';
                 nwp[2]+=8;
           }
           else if(map[playery][playerx]=='M'){
                 map[playery][playerx]='.';
                 nwp[3]+=20;
           }
           else if(map[playery][playerx]=='K'){
             if(nwp[4]==0){
                 map[playery][playerx]='.';
                 nwp[4]=1;
               }
               else{
                  haswpnpicker=1;
               }
           }
           else if(map[playery][playerx]=='Q'&&alldied){
             golds+=1000;
             gamewin=1;
           }
           break;
        case 'n':
        case 'N':
           if(floorx==4&&playerroom==4){
             for(int i=0;i<nenemy;i++){
              if(enemy[i].room==playerroom){
                enemy[i].isdead=1;
              }
             }
           }
           break;
        case 'r':
        case 'R': 
           if(isfast1==1){
            isfast1=0;
           }
           else{
            isfast1=1;
           }
           break;
        case ' ':
           fight();
           break;
        case KEY_UP:
           if(map[playery][playerx]=='<'){
              rahpele[floorx].x=playerx;
              rahpele[floorx].y=playery;
              if(floorx==1||floorx==2||floorx==3){
                floorx++;
                reset();
                mainx();
                for(int i=0;i<numberOfHouses;i++){
                    redolasthouse(i);
                 }
               for(int i=0;i<maxHeight;i++){
                for(int j=0;j<maxWidth;j++){
                  mapshow[i][j]=0;
               }
              }          
             return mainview();
              
              }
           }
           break;
        case KEY_DOWN:
           if(map[playery][playerx]=='<'){
             if(floorx==2){
                floorx--;
             }
              else if(floorx==3){
                floorx--;
               
              }
              else if(floorx==4){
                floorx--;
             
              }
           }
     }
     int checko=0;
     if(floorx==4&&playerroom==4){
        for(int i=0;i<nenemy;i++){
          if(enemy[i].room==4&&enemy[i].isdead==0){
             checko++;
          }
        }
        if(checko==0){
          alldied=1;
        }
        nottal=checko;
     }
      if(haspower){
         checkpower();
      }
      if(hasfast){
        if(isvalidmove){
          distancefast++;
          if(distancefast%150==0&&distancefast!=0){
            hasfast=0;
          }
        }
      }
      if(hashealtht){
        if(isvalidmove){
            distancehasht++;
            if(distancehasht%150==0&&distancehasht!=0){
                hashealtht=0;
            }
        }
      }
      if(enemydiedwarn){
        playerhealth=min(playerhealth+50,100);
      }
      if(enemydamwarn){
        playerhealth=min(playerhealth+20,100);
      }
      checkhealth();
      drawmapborder();
    }
    return 1;
}
int mainx(){
    srand(time(0));
    getmaxyx(stdscr, maxHeight, maxWidth);
    clear();
    numberOfHouses = 6;
    if(floorx==1){
    playerattack = 1;
    if(colorchoice==1){
        colort=5;
    }
    else if(colorchoice==2){
        colort=2;
    }
    else if(colorchoice==3){
        colort=1;
    }
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
    init_pair(5,COLOR_YELLOW,COLOR_BLACK);
    init_pair(6,COLOR_MAGENTA,COLOR_BLACK);
    init_pair(7,COLOR_BLACK,COLOR_YELLOW);
   init_pair(8, COLOR_WHITE, COLOR_BLACK);
   init_pair(117,117,COLOR_BLACK);
   init_pair(132,132,COLOR_BLACK);
   init_pair(210,210,COLOR_BLACK);
   init_pair(93,93,COLOR_BLACK);
   init_pair(183,183,COLOR_BLACK);
   init_pair(225,225,COLOR_BLACK);
   init_pair(18,COLOR_BLUE,COLOR_BLUE);
   init_pair(19,COLOR_RED,COLOR_RED);
   init_pair(110,132,132);
   init_pair(227,227,COLOR_BLACK);
   init_pair(134,227,227);
   init_pair(32,31,31);
   if(resume){
     daryaftet();
   }
    else if(sathchoice==1){
        playerhealth=100;
    }
    else if(sathchoice==2){
        playerhealth=80;
    }
    else{
        playerhealth=40;
    }
    maxhealth=playerhealth;}
    mainf();
    connectHouses(houses,numberOfHouses);
    for(int i=0;i<numberOfHouses;i++){
        redolasthouse(i);
    }
    for(int i=0;i<maxHeight;i++){
        for(int j=0;j<maxWidth;j++){
            mapshow[i][j]=0;
        }
    }
    return mainview();
}