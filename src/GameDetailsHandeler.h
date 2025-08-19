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
int nisveryhungry=0;
int checkmovement(int playerx,int playery,int dx,int dy,char **mapx,int **mapshowx){
   if(isfast==0){
     if(map[playery+dy][playerx+dx]=='.'||map[playery+dy][playerx+dx]=='Q'||map[playery+dy][playerx+dx]=='<'||map[playery+dy][playerx+dx]=='#'||map[playery+dy][playerx+dx]=='+'||map[playery+dy][playerx+dx]=='1'
       ||map[playery+dy][playerx+dx]=='2'||map[playery+dy][playerx+dx]=='3'||
       map[playery+dy][playerx+dx]=='4'||map[playery+dy][playerx+dx]=='5'||
       map[playery+dy][playerx+dx]=='6'||map[playery+dy][playerx+dx]=='V'||map[playery+dy][playerx+dx]=='B'||map[playery+dy][playerx+dx]=='N'
       ||map[playery+dy][playerx+dx]=='M'||map[playery+dy][playerx+dx]=='K'){
         return 1;
       }
     else if(map[playery+dy][playerx+dx]=='g'||map[playery+dy][playerx+dx]=='G'){
        if(map[playery+dy][playerx+dx]=='g'){
         golds+=5;
       }
       else if(map[playery+dy][playerx+dx]=='G'){
         golds+=20;
       }
       map[playery+dy][playerx+dx]='.';
       recgold=1;
       return 1;
     }
     else if(map[playery+dy][playerx+dx]=='^'){
      int i=0;
         while(1){
            if(trap[i].y==playery+dy&&trap[i].x==playerx+dx){
               break;
            }
            i++;
         }
         trap[i].gone=1;
         playerhealth-=20*maxhealth/100;
         return 1;
     }
     else{
      return 0;
     }
   }
   else if(isfast==1){
       if(map[playery+dy][playerx+dx]=='.'||map[playery+dy][playerx+dx]=='Q'||map[playery+dy][playerx+dx]=='<'||map[playery+dy][playerx+dx]=='#'||map[playery+dy][playerx+dx]=='+'||map[playery+dy][playerx+dx]=='1'
       ||map[playery+dy][playerx+dx]=='2'||map[playery+dy][playerx+dx]=='3'||
       map[playery+dy][playerx+dx]=='4'||map[playery+dy][playerx+dx]=='5'||
       map[playery+dy][playerx+dx]=='6'||map[playery+dy][playerx+dx]=='V'||map[playery+dy][playerx+dx]=='B'||map[playery+dy][playerx+dx]=='N'
       ||map[playery+dy][playerx+dx]=='M'||map[playery+dy][playerx+dx]=='K'){
          if(mapx[playery+dy/2][playerx+dx/2]=='O'){
            isvalidmove=0;
            return 0;
          }
         if(map[playery+dy/2][playerx+dx/2]=='g'||map[playery+dy/2][playerx+dx/2]=='G'){
            if(map[playery+dy][playerx+dx]=='g'){
                golds+=5;
            }
            else if(map[playery+dy/2][playerx+dx/2]=='G'){
                 golds+=20;
             }
            map[playery+dy/2][playerx+dx/2]='.';
           recgold=1;
         }
         else if(map[playery+dy/2][playerx+dx/2]=='^'){
             int i=0;
             while(1){
                 if(trap[i].y==playery+dy/2&&trap[i].x==playerx+dx/2){
                   break;
                }
                i++;
             }
             trap[i].gone=1;
             playerhealth-=20*maxhealth/100;
         return 1;
         }
         return 1;
       }
       else if((map[playery+dy][playerx+dx]=='_')||(map[playery+dy][playerx+dx]=='-')||(map[playery+dy][playerx+dx]=='|')||
       (map[playery+dy][playerx+dx]=='O')||(map[playery+dy][playerx+dx]=='=')){
         if(map[playery+dy/2][playerx+dx/2]=='g'||map[playery+dy/2][playerx+dx/2]=='G'){
            if(map[playery+dy][playerx+dx]=='g'){
                golds+=5;
            }
            else if(map[playery+dy/2][playerx+dx/2]=='G'){
                 golds+=20;
             }
            map[playery+dy/2][playerx+dx/2]='.';
           recgold=1;
        }
         return 2;
       }
       else if(map[playery+dy][playerx+dx]=='g'||map[playery+dy][playerx+dx]=='G'){
          if(map[playery+dy][playerx+dx]=='g'){
             golds+=5;
          }
          else if(map[playery+dy][playerx+dx]=='G'){
             golds+=20;
          }
         map[playery+dy][playerx+dx]='.';
         recgold=1;
         return 1;
      }
      else if(map[playery+dy][playerx+dx]=='^'){
         if(map[playery+dy/2][playerx+dx/2]!='O'){
             int i=0;
             while(1){
                if(trap[i].y==playery+dy&&trap[i].x==playerx+dx){
                  break;
            }
            i++;
         }
         trap[i].gone=1;
         playerhealth-=20*maxhealth/100;
         return 1;
         }
         else{
            return 0;
         }
      }
      else{
      return 0;
     }
   }
}
int checkhealth(){
   if(isvalidmove){
    if(distance%10==0&&beinghungry>0&&distance!=0){
        beinghungry-=1;
     }
     if(beinghungry<=20&&beinghungry>0){
        ishungry=1;
     }
     else if(beinghungry==0){
        isveryhungry=1;
     }
     else{
        ishungry=0;
        isveryhungry=0;
     }
     if(isveryhungry){
      nisveryhungry++;
      if(nisveryhungry%15==0){
        playerhealth--;
      }
     }
     if(beinghungry>=90&&playerhealth<maxhealth){
        int i=1;
        if(hashealtht){
            i=2;
        }
       playerhealth+=i*1;
     }
   }
}
int checkend(){
   if(playerhealth<=0){
      clear();
      attron(COLOR_PAIR(3)|A_BOLD|A_ITALIC);
      for(int y=0;y<LINES;y++){
        mvaddstr(y,10,"🩸");
        mvaddstr(y,COLS-10,"🩸");
    }
    for(int x=0;x<COLS;x++){
        mvaddstr(7,x,"🩸");
        mvaddstr(LINES-7,x,"🩸");
    }
      mvprintw(LINES/2,COLS/2-20,"You lost!😥 Stay positive,work hard and make it happen💪🗿");
      attroff(COLOR_PAIR(3)|A_BOLD|A_ITALIC);
      attron(COLOR_PAIR(5));
      mvprintw(LINES/2+2,COLS/2-17,"Your golds: %d 🪙",golds);
      attroff(COLOR_PAIR(5));
      if(hasacc){
          saveplayeritems();
      }
      int w=0;
      while(1){
         int x= getch();
         switch (x){
         case 'q':
         case 'Q':
            clear();
            exit(0);
           break;
     
         default:
           break;
        }
      }
      
   }
   if(gamewin){
      clear();
      for(int y=0;y<LINES;y++){
        mvaddstr(y,10,"🏆");
        mvaddstr(y,COLS-12,"🏆");
    }
    for(int x=0;x<COLS;x++){
        mvaddstr(7,x,"🏆");
        mvaddstr(LINES-7,x,"🏆");
    }
    attron(COLOR_PAIR(5));
      mvprintw(LINES/2,COLS/2-20,"🌟🌟🌟🌟🌟🌟congratulations 🤠 you won the game🌟🌟🌟🌟🌟");
      attroff(COLOR_PAIR(3)|A_BOLD|A_ITALIC);
      attron(COLOR_PAIR(5));
      mvprintw(LINES/2+2,COLS/2-17,"Your golds: %d 🪙",golds);
      attroff(COLOR_PAIR(5));
      if(hasacc){
          saveplayeritems();
      }
      int w=0;
      while(1){
         int x= getch();
         switch (x){
         case 'q':
         case 'Q':
           clear();
           exit(0);
           break;
     
         default:
           break;
        }
      }
   }
}
int checkfood(){
   if(nfood[foodchoice-1]>0){
      if(foodchoice==1){
         int x=rand()%14;
         if(x==3||x==4||x==5||x==12){
            playerhealth-=10;
            nfood[0]--;
            atebadfood=1;
         }
         else{
            if(playerhealth==maxhealth){
               maxhealther=1;
            }
            else{
               nfood[0]--;
               playerhealth=min(playerhealth+maxhealth/5,maxhealth);
               beinghungry=min(beinghungry+40,100);
            }
         }
      }
      else if(foodchoice==2){
         haspower=1;
         distancepower=0;
         playerhealth=min(playerhealth+maxhealth/5,maxhealth);
          beinghungry=min(beinghungry+40,100);
          nfood[1]--;
         
      }
      else if(foodchoice==3){
         hasfast=1;
         distancefast=0;
         nfood[2]--;
         playerhealth=min(playerhealth+maxhealth/5,maxhealth);
          beinghungry=min(beinghungry+40,100);
      }
   }
   else{
      hasfooder=1;
   }
   foodchoice=0;
   return 0;
}
int checkmajoon(){
    if(nmajoon[majoonchoice-1]>0){
      if(majoonchoice==1){
         hashealtht=1;
         distancehasht=0;
        nmajoon[0]--;
        beinghungry=min(beinghungry+50,100);
      }
      else if(majoonchoice==3){
         haspower=1;
         distancepower=0;
          beinghungry=min(beinghungry+50,100);
          nmajoon[2]--;
         
      }
      else if(majoonchoice==2){
         hasfast=1;
         distancefast=0;
         nmajoon[1]--;
          beinghungry=min(beinghungry+50,100);
      }
   }
   else{
     hasmajooner=1;
   }
   majoonchoice=0;
   return 0;
}
int checkweapon(){
   if(nwp[weaponchoice-1]>0){
      if(weaponchoice==1){
         weaponon=1;
      }
      else if(weaponchoice==2){
           weaponon=2;
      }
      else if(weaponchoice==3){
         weaponon=3;
      }
      else if(weaponchoice==4){
         weaponon=4;
      }
      else if(weaponchoice==5){
         weaponon=5;
      }
   }
   else{
     hasweaponer=1;
   }
   weaponchoice=0;
   return 0;
}
int checkpower(){
   playerattack=2;
   if(isvalidmove){
      distancepower++;
      if(distancepower%50==0&&distancepower!=0){
         haspower=0;
         playerattack=1;
      }
   }
}
int checkinroom(){
   for(int i=0;i<6;i++){
      if(houses[i]->show==0){
         if(((playerx>=houses[i]->x)&&(playerx<houses[i]->x+houses[i]->width))&&((playery>=houses[i]->y)&&(playery<houses[i]->y+houses[i]->height))){
            houses[i]->show=1;
         }
      }
   }
   for(int i=0;i<numberOfHouses;i++){
         if(playerx>=houses[i]->x&&playerx<houses[i]->x+houses[i]->width&&playery>=houses[i]->y&&playery<houses[i]->y+houses[i]->height){
            playerroom=i;
            break;
         }
         else{
            playerroom=0;
         }
   }
}
int checkarea(){
   for(int i=playery-2;i<=playery+2;i++){
      for(int j=playerx-2;j<=playerx+2;j++){
         mapshow[i][j]=1;
         for(int z=0;z<lnrahro;z++){
            if(rahro[z].x>=playerx-2&&playerx+2>=rahro[z].x&&rahro[z].y>=playery-2&&playery+2>=rahro[z].y){
               rahro[z].show=1;
               mapshow[rahro[z].y][rahro[z].x]=1;
            }
         }
      }
   }
   for(int h=0;h<lnrahro;h++){
      if(rahro[h].show==1){
           if((rahro[h].x==playerx&&rahro[h].y==playery)){
            continue;
           }
           else if(map[rahro[h].y][rahro[h].x]=='+'||map[rahro[h].y][rahro[h].x]=='#'){
             attron(COLOR_PAIR(2));
             mvprintw(rahro[h].y,rahro[h].x,"%c",rahro[h].is);
              attron(COLOR_PAIR(2));
           }
      }
   }
}
int reset(){
   if (map != NULL) {
    for (int i = 0; i < maxHeight; i++) {
        free(map[i]);
    }
    free(map);
}
  map = (char **)malloc(maxHeight * sizeof(char *));
  for (int i = 0; i < maxHeight; i++) {
    map[i] = (char *)malloc(maxWidth * sizeof(char));
   }
   for (int i = 0; i < maxHeight; i++) {
        free(mapshow[i]);
    }
    free(mapshow);
    checkrahro = 0;
    /*recgold = 0;
    maxhealth = 0;*/
    nsootoon = 0;
    nsootoon2 = 0;
    nsootoon3 = 0;
    nsootoon4 = 0;
    nhouse = 0;
    numberOfHouses = 0;
    npanjtot = 0;
    ntrap = 0;
    showfull = 0;
    allroomchecked = 0;
    nhousesshow = 0;
    allroomchecked4 = 0;
    nhousesshow4 = 0;
    for(int i = 0; i < 6; i++) {
        xsoot[i] = 0;
        ysoot[i] = 0;
        haspanj[i] = 0;
    }
    for(int i = 0; i < 10; i++) {
        rahro[i] = (Rahro){0};
    }
    for (int i = 0; i < 50; i++) {
    free(houses[i]);
    }

    g12=0;
    g22=0;
    g32=0;
    g42=0;
    g52=0;
    h21=0;
    h22=0;
    h23=0;
    h24=0;
    nfood1=0;
    nfood2=0;
   nfood3=0;
    h25=0;
    for(int i = 0; i < 40; i++) {
        enemy[i] = (Enemy){0};
    }
    map = NULL;
    mapshow = NULL;
}
checkkharabifood(){
   if(distance%500==0&&distance!=0){
      if(nfood[1]>0){
         nfood[1]--;
         nfood[0]++;
      }
      if(nfood[2]>0){
         nfood[2]--;
         nfood[0]++;
      }
   }
}
