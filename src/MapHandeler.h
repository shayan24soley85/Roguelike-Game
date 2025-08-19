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
#include <locale.h>
#include <stdbool.h>

int checkCollision(House *newHouse, House *houses[], int numHouses, int maxWidth, int maxHeight){
    for (int i = 0; i < numHouses; i++)
    {
        if (newHouse == houses[i]) 
            continue;
        if ((newHouse->x < houses[i]->x + houses[i]->width &&newHouse->x + newHouse->width > houses[i]->x-7&&
        newHouse->y < houses[i]->y + houses[i]->height &&
            newHouse->y + newHouse->height > houses[i]->y-2)||(newHouse->x>houses[i]->x&&newHouse->x<houses[i]->x+houses[i]->width+7)||(newHouse->y>houses[i]->y&&newHouse->y<houses[i]->y+houses[i]->height+2))
        {
            return 1;
        }
    }
    if (newHouse->x + newHouse->width > maxWidth-2 || newHouse->y + newHouse->height > maxHeight-2 || newHouse->x < 2 ||  newHouse->y < 2) {
        return 1;
    }
    return 0; 
}
House *createHouse(int maxWidth, int maxHeight, House *houses[], int numHouses){
    House *newHouse = (House *)malloc(sizeof(House));
    if (!newHouse){
        perror("Failed to allocate memory for house");
        exit(EXIT_FAILURE);
    }
    if(1){
       while(1){
          newHouse->width = rand() % 10 + 12; 
          newHouse->height = rand() % 6 + 7;
          if((newHouse->height*4>newHouse->width)&&(newHouse->height*2<newHouse->width*3)){
             break;
          }
        }
       do{
           newHouse->x = rand() % (maxWidth -2- newHouse->width);
           newHouse->y = rand() % (maxHeight-1 - newHouse->height);
        } while (checkCollision(newHouse, houses, numHouses, maxWidth, maxHeight));
    }
    if(nsootoon<6){
             xsoot[nsootoon]=rand()%(newHouse->width-4)+newHouse->x+2;
             ysoot[nsootoon]=rand()%(newHouse->height-4)+newHouse->y+2;
             map[ysoot[nsootoon]][xsoot[nsootoon]]='O';
            
             nsootoon++;
    }
    int checkit2=0;
    int w=0;
   while(w<1&&floorx==1){
        checkit2=0;
       if(ntrap<6){
        while(1){
          trap[ntrap].x=rand()%(newHouse->width-4)+newHouse->x+3;
          trap[ntrap].y=rand()%(newHouse->height-3)+newHouse->y+3;
          if(map[trap[ntrap].y][trap[ntrap].x]==NULL){
            map[trap[ntrap].y][trap[ntrap].x]='^';
            mapshow[trap[ntrap].y][trap[ntrap].x]=0;
            ntrap++;
            w++;
            break;
          }
        }
       }
   }
   if(1){
    int w2=rand()%(3);
    int ytala1=0;
    int xtala1=0;
    int ytala2=0;
    int xtala2=0;
    int checkit=0;
    static  ntala1=0;
    static  ntala2=0;
    while(w2<3){
        checkit=0;
       if(ntala1<35){
          xtala1=rand()%(newHouse->width-2)+newHouse->x+1;
          ytala1=rand()%(newHouse->height)+newHouse->y+1;
          if(map[ytala1][xtala1]==NULL){
            checkit=1;
          }
       }
       if(checkit){
        ntala1++;
        w2++;
        map[ytala1][xtala1]='g';
    
       }
       else{
        break;
       }
    }
    if(ntala2<12&&numHouses>1){
        xtala2=rand()%(newHouse->width-2)+newHouse->x+1;
         ytala2=rand()%(newHouse->height-2)+newHouse->y+1;
        if(map[ytala2][xtala2]==NULL){
            map[ytala2][xtala2]='G';
            
             ntala2++;
        }
    }
    int w3=0;
    int w32=0;
    int w33=0;
    int xfood1;
    int yfood1;
    int xfood2;
    int xfood3;
    int yfood2;
    int yfood3;
    while(w3<2){
        if(nfood1<12){
            while(1){
              xfood1=rand()%(newHouse->width-2)+newHouse->x+1;
              yfood1=rand()%(newHouse->height-2)+newHouse->y+1;
              if(map[yfood1][xfood1]==NULL){
                map[yfood1][xfood1]='1';
                
                nfood1++;
                w3++;
                break;
              }
            }
        }
        else{
            break;
        }
    }
     while(w32<2){
        if(nfood2<9){
            while(1){
              xfood2=rand()%(newHouse->width-2)+newHouse->x+1;
              yfood2=rand()%(newHouse->height-2)+newHouse->y+1;
              if(map[yfood2][xfood2]==NULL){
                map[yfood2][xfood2]='2';
                
                nfood2++;
                w32++;
                break;
              }
            }
        }
        else{
            break;
        }
    }
     while(w33<2){
        if(nfood3<9){
            while(1){
              xfood3=rand()%(newHouse->width-2)+newHouse->x+1;
              yfood3=rand()%(newHouse->height-2)+newHouse->y+1;
              if(map[yfood3][xfood3]==NULL){
                map[yfood3][xfood3]='3';
               
                nfood3++;
                w33++;
                break;
              }
            }
        }
        else{
            break;
        }
    }
    int tel1=0;
    int tel2=0;
    int tel3=0;
    if(numHouses==1){
      while(tel1<5){
        while(1){
            int xtel=rand()%(newHouse->width-2)+newHouse->x+1;
             int  ytel=rand()%(newHouse->height-2)+newHouse->y+1;
             if(map[ytel][xtel]==NULL){
                map[ytel][xtel]='4';
                tel1++;
                break;
             }
        }
      }
      while(tel2<5){
        while(1){
          int xtel=rand()%(newHouse->width-2)+newHouse->x+1;
             int  ytel=rand()%(newHouse->height-2)+newHouse->y+1;
             if(map[ytel][xtel]==NULL){
                map[ytel][xtel]='5';
                tel2++;
                break;
             }
        }
      }
      while(tel3<5){
        while(1){
            int xtel=rand()%(newHouse->width-2)+newHouse->x+1;
             int  ytel=rand()%(newHouse->height-2)+newHouse->y+1;
             if(map[ytel][xtel]==NULL){
                map[ytel][xtel]='6';
                tel3++;
                break;
             }
        }
      }
    }
    int g1=0;
    int g2=0;
    int g3=0;
    int g4=0;
    int g5=0;
    while(g2<1){
        if(g22<7){
            while(1){
              int xwp=rand()%(newHouse->width-2)+newHouse->x+1;
              int ywp=rand()%(newHouse->height-2)+newHouse->y+1;
              if(map[ywp][xwp]==NULL){
                map[ywp][xwp]='B';
                g22++;
                g2++;
                break;
              }
            }
        }
        else{
            break;
        }
    }
    while(g3<1){
        if(g32<7){
            while(1){
              int xwp=rand()%(newHouse->width-2)+newHouse->x+1;
              int ywp=rand()%(newHouse->height-2)+newHouse->y+1;
              if(map[ywp][xwp]==NULL){
                map[ywp][xwp]='N';
               
                g32++;
                g3++;
                break;
              }
            }
        }
        else{
            break;
        }
    }
    while(g4<1){
        if(g42<7){
            while(1){
              int xwp=rand()%(newHouse->width-2)+newHouse->x+1;
              int ywp=rand()%(newHouse->height-2)+newHouse->y+1;
              if(map[ywp][xwp]==NULL){
                map[ywp][xwp]='M';
               
                g42++;
                g4++;
                break;
              }
            }
        }
        else{
            break;
        }
    }
    while(g5<1){
        if(g52<3){
            while(1){
              int xwp=rand()%(newHouse->width-2)+newHouse->x+1;
              int ywp=rand()%(newHouse->height-2)+newHouse->y+1;
              if(map[ywp][xwp]==NULL){
                map[ywp][xwp]='K';
               
                g52++;
                g5++;
                break;
              }
            }
        }
        else{
            break;
        }
    }
    int h1=0;
    int h2=0;
    int h3=0;
    int h4=0;
    int h5=0;
    int i=1;
    if(floorx==4&&numHouses==4){
        i=3;
    }
    int max1=1*i,max12=6,max2=1*i,max22=6,max3=1*i,max33=5,max4=1*i,max42=5,max5=1*i,max52=5;
    while(h1<max1){
        if(h21<max12){
            while(1){
              int xwp=rand()%(newHouse->width-2)+newHouse->x+1;
              int ywp=rand()%(newHouse->height-2)+newHouse->y+1;
              if(map[ywp][xwp]==' '||map[ywp][xwp]=='\0'||map[ywp][xwp]=='.'){
                map[ywp][xwp]='D';
                enemy[nenemy].firstx=xwp;
                enemy[nenemy].firsty=ywp;
                enemy[nenemy].y=ywp;
                enemy[nenemy].x=xwp;
                enemy[nenemy].room=numHouses;
                enemy[nenemy].floor=floorx;
                enemy[nenemy].damage=5;
                enemy[nenemy].health=5;
                enemy[nenemy].noe=1;
                h1++;
                h21++;
                nenemy++;
                break;
              }
            }
        }
        else{
            break;
        }
    }
     if(numHouses>1){
       while(h2<max2){
        if(h22<max22){
            while(1){
              int xwp=rand()%(newHouse->width-2)+newHouse->x+1;
              int ywp=rand()%(newHouse->height-2)+newHouse->y+1;
              if(map[ywp][xwp]==' '||map[ywp][xwp]=='\0'||map[ywp][xwp]=='.'){
                map[ywp][xwp]='F';
                enemy[nenemy].firstx=xwp;
                enemy[nenemy].firsty=ywp;
                enemy[nenemy].y=ywp;
                enemy[nenemy].x=xwp;
                enemy[nenemy].room=numHouses;
                enemy[nenemy].damage=10;
                enemy[nenemy].health=10;
                enemy[nenemy].floor=floorx;
                enemy[nenemy].noe=2;
                h2++;
                h22++;
                nenemy++;
                break;
              }
            }
        }
        else{
            break;
        }
     }
    }
    if(numHouses!=2){
       while(h3<max3){
        if(h23<max33){
            while(1){
              int xwp=rand()%(newHouse->width-2)+newHouse->x+1;
              int ywp=rand()%(newHouse->height-2)+newHouse->y+1;
              if(map[ywp][xwp]==' '||map[ywp][xwp]=='\0'||map[ywp][xwp]=='.'){
                map[ywp][xwp]='0';
                enemy[nenemy].firstx=xwp;
                enemy[nenemy].firsty=ywp;
                enemy[nenemy].y=ywp;
                enemy[nenemy].x=xwp;
                enemy[nenemy].room=numHouses;
                enemy[nenemy].damage=20;
                enemy[nenemy].health=20;
                enemy[nenemy].noe=4;
                enemy[nenemy].floor=floorx;
                h3++;
                h23++;
                nenemy++;
                break;
              }
            }
        }
        else{
            break;
        }
     }
    }
    if(numHouses!=2){
       while(h4<max4){
        if(h24<max42){
            while(1){
              int xwp=rand()%(newHouse->width-2)+newHouse->x+1;
              int ywp=rand()%(newHouse->height-2)+newHouse->y+1;
              if(map[ywp][xwp]==' '||map[ywp][xwp]=='\0'||map[ywp][xwp]=='.'){
                map[ywp][xwp]='S';
                enemy[nenemy].firstx=xwp;
                enemy[nenemy].firsty=ywp;
                enemy[nenemy].y=ywp;
                enemy[nenemy].x=xwp;
                enemy[nenemy].room=numHouses;
                enemy[nenemy].damage=20;
                enemy[nenemy].health=20;
                enemy[nenemy].noe=4;
                enemy[nenemy].floor=floorx;
                h4++;
                h24++;
                nenemy++;
                break;
              }
            }
        }
        else{
            break;
        }
     }
    }
    if(numHouses>2){
       while(h5<max5){
        if(h25<max52){
            while(1){
              int xwp=rand()%(newHouse->width-2)+newHouse->x+1;
              int ywp=rand()%(newHouse->height-2)+newHouse->y+1;
              if(map[ywp][xwp]==' '||map[ywp][xwp]=='\0'||map[ywp][xwp]=='.'){
                map[ywp][xwp]='U';
                enemy[nenemy].firstx=xwp;
                enemy[nenemy].firsty=ywp;
                enemy[nenemy].y=ywp;
                enemy[nenemy].x=xwp;
                enemy[nenemy].room=numHouses;
                enemy[nenemy].damage=30;
                enemy[nenemy].health=30;
                enemy[nenemy].noe=5;
                enemy[nenemy].floor=floorx;
                h5++;
                h25++;
                nenemy++;
                break;
              }
            }
        }
        else{
            break;
        }
     }
    }
   }
   if(numHouses==4&&floorx==4){
        int talax=0;
        while(talax<12){
            while(1){
                 int xtel=rand()%(newHouse->width-2)+newHouse->x+1;
                 int  ytel=rand()%(newHouse->height-2)+newHouse->y+1;
                 if(map[ytel][xtel]==' '||map[ytel][xtel]=='\0'||map[ytel][xtel]=='.'){
                    map[ytel][xtel]='G';
                    talax++;
                    break;
                 }
            }
        }
        int hd=0;
        int hf=0;
        int hu=0;
        int hg=0;
        int hs=0;
        int f1=0;
        int f2=0;
        int f3=0;
        int trap=0;
        /*while(trap<3){
            while(1){
                 int xtel=rand()%(newHouse->width-2)+newHouse->x+1;
                 int  ytel=rand()%(newHouse->height-2)+newHouse->y+1;
                 if(map[ytel][xtel]==NULL){
                    map[ytel][xtel]='^';
                    trap++;
                    break;
                 }
            }
        }
        while(hd<2){
            while(1){
                 int xtel=rand()%(newHouse->width-2)+newHouse->x+1;
                 int  ytel=rand()%(newHouse->height-2)+newHouse->y+1;
                 if(map[ytel][xtel]==NULL){
                    map[ytel][xtel]='D';
                    enemy[nenemy].firstx=xtel;
                    enemy[nenemy].firsty=ytel;
                      enemy[nenemy].y=xtel;
                      enemy[nenemy].x=ytel;
                     enemy[nenemy].room=numHouses;
                    enemy[nenemy].damage=5;
                    enemy[nenemy].health=5;
                     enemy[nenemy].noe=1;
                    hd++;
                    nenemy++;
                    break;
                 }
            }
        }
        while(hg<2){
            while(1){
                 int xtel=rand()%(newHouse->width-2)+newHouse->x+1;
              int  ytel=rand()%(newHouse->height-2)+newHouse->y+1;
                 if(map[ytel][xtel]==NULL){
                    map[ytel][xtel]='0';
                    enemy[nenemy].firstx=xtel;
                    enemy[nenemy].firsty=ytel;
                      enemy[nenemy].y=xtel;
                      enemy[nenemy].x=ytel;
                     enemy[nenemy].room=numHouses;
                    enemy[nenemy].damage=15;
                    enemy[nenemy].health=15;
                     enemy[nenemy].noe=3;
                    hg++;
                    nenemy++;
                    break;
                 }
            }
        }
        while(hf<2){
            while(1){
                 int xtel=rand()%(newHouse->width-2)+newHouse->x+1;
                 int  ytel=rand()%(newHouse->height-2)+newHouse->y+1;
                 if(map[ytel][xtel]==NULL){
                    map[ytel][xtel]='F';
                    hf++;
                    enemy[nenemy].firstx=xtel;
                    enemy[nenemy].firsty=ytel;
                      enemy[nenemy].y=xtel;
                      enemy[nenemy].x=ytel;
                     enemy[nenemy].room=numHouses;
                    enemy[nenemy].damage=10;
                    enemy[nenemy].health=10;
                     enemy[nenemy].noe=2;
                    nenemy++;
                    break;
                 }
            }
        }
        while(hs<2){
            while(1){
                 int xtel=rand()%(newHouse->width-2)+newHouse->x+1;
                 int  ytel=rand()%(newHouse->height-2)+newHouse->y+1;
                 if(map[ytel][xtel]==NULL){
                    map[ytel][xtel]='S';
                    hs++;
                    enemy[nenemy].firstx=xtel;
                    enemy[nenemy].firsty=ytel;
                      enemy[nenemy].y=xtel;
                      enemy[nenemy].x=ytel;
                     enemy[nenemy].room=numHouses;
                    enemy[nenemy].damage=20;
                    enemy[nenemy].health=20;
                     enemy[nenemy].noe=4;
                    
                    nenemy++;
                    break;
                 }
            }
        }
        while(hu<2){
            while(1){
                 int xtel=rand()%(newHouse->width-2)+newHouse->x+1;
                 int  ytel=rand()%(newHouse->height-2)+newHouse->y+1;
                 if(map[ytel][xtel]==NULL){
                    map[ytel][xtel]='U';
                    enemy[nenemy].firstx=xtel;
                    enemy[nenemy].firsty=ytel;
                      enemy[nenemy].y=xtel;
                      enemy[nenemy].x=ytel;
                     enemy[nenemy].room=numHouses;
                    enemy[nenemy].damage=30;
                    enemy[nenemy].health=30;
                     enemy[nenemy].noe=5;
                    hu++;
                    nenemy++;
                    break;
                 }
            }
        }
        while(f1<2){
            while(1){
                 int xtel=rand()%(newHouse->width-2)+newHouse->x+1;
                 int  ytel=rand()%(newHouse->height-2)+newHouse->y+1;
                 if(map[ytel][xtel]==NULL){
                    map[ytel][xtel]='1';
                    f1++;
                    break;
                 }
            }
        }
        while(f2<2){
            while(1){
                 int xtel=rand()%(newHouse->width-2)+newHouse->x+1;
                 int  ytel=rand()%(newHouse->height-2)+newHouse->y+1;
                 if(map[ytel][xtel]==NULL){
                    map[ytel][xtel]='2';
                    f2++;
                    break;
                 }
            }
        }*/
         map[newHouse->y+1][newHouse->x+1]='Q';
         map[newHouse->y+1][newHouse->x+newHouse->width-3]='Q';
      }
    nwp[0]=1;
    return newHouse;
}
void connectHouses(House *houses[], int numHouses){
    
    for(int j=0;j<numHouses;j++){
     for (int i=3; i < numHouses ; i++){
        House *current;
          House *next ;
           current = houses[j];
           next = houses[i];
        
        int currentWallX = current->x + current->width /2; 
        int currentWallY = current->y + current->height / 2;
        int nextWallX = next->x+next->width/2;
        int nextWallY = next->y + next->height-2;
        int x;
        int j=0;
        int xmax=currentWallX > nextWallX ? currentWallX : nextWallX;
        int xmin=currentWallX < nextWallX ? currentWallX : nextWallX;
        for (x = (currentWallX < nextWallX ? currentWallX : nextWallX); x <= (currentWallX > nextWallX ? currentWallX : nextWallX); x++) {
            if (mvinch(currentWallY, x) == ' '){
                if(mapshow[currentWallY][x]==1||showfull){
                    attron(COLOR_PAIR(2));
                     mvprintw(currentWallY, x, "#");
                     attroff(COLOR_PAIR(2));
                }
                map[currentWallY][x]='#';
                if(checkrahro==0){
                rahro[lnrahro].is='#';
                rahro[lnrahro].x=x;
                rahro[lnrahro].y=currentWallY;
                lnrahro++;}
            }
            if (mvinch(currentWallY, x) == '|'&&x!=xmax) {
                if(mapshow[currentWallY][x]==1||showfull){
                     attron(COLOR_PAIR(5));
                   mvprintw(currentWallY, x, "+");
                    attroff(COLOR_PAIR(5));
                }
                map[currentWallY][x]='+';
                if(checkrahro==0){
                rahro[lnrahro].is='+';
                rahro[lnrahro].x=x;
                rahro[lnrahro].y=currentWallY;
                lnrahro++;}
            }
            if (mvinch(currentWallY, nextWallX) == '-'){
                if(mapshow[currentWallY][currentWallX]==1||showfull){
                     attron(COLOR_PAIR(5));
                  mvprintw(currentWallY, nextWallX, "+");
                   attroff(COLOR_PAIR(5));
                }
                map[currentWallY][nextWallX]='+';
                if(checkrahro==0){rahro[lnrahro].is='+';
                rahro[lnrahro].x=nextWallX;
                rahro[lnrahro].y=currentWallY;
                lnrahro++;}
            }
        }
        int y;
        for (y = (currentWallY < nextWallY ? currentWallY : nextWallY); y <= (currentWallY > nextWallY ? currentWallY : nextWallY); y++){
            if (mvinch(y, nextWallX) == ' '){
                if(mapshow[y][currentWallX]==1||showfull){
                    attron(COLOR_PAIR(2));
                    mvprintw(y, nextWallX, "#");
                    attroff(COLOR_PAIR(2));
                }
                map[y][nextWallX]='#';
                if(checkrahro==0){rahro[lnrahro].is='#';
                rahro[lnrahro].x=nextWallX;
                rahro[lnrahro].y=y;
                lnrahro++;}

            }
            if (mvinch(y, nextWallX) == '-'||mvinch(y, nextWallX) == '_') {
                 attron(COLOR_PAIR(5));
                if (mvinch(y, nextWallX - 1) == ' ' && mvinch(y, nextWallX + 1) == '-'){
                    if(mapshow[y][currentWallX]==1||showfull){
                         mvprintw(y, nextWallX, "+");
                    }
                    if(mapshow[y][currentWallX+1]==1||showfull){
                       mvprintw(y, nextWallX + 1, "+");
                    }
                    map[y][nextWallX]='+';
                   map[y][nextWallX+1]='+';
                   if(checkrahro==0){
                   rahro[lnrahro].is='+';
                   rahro[lnrahro].x=nextWallX;
                   rahro[lnrahro].y=y;
                   lnrahro++;
                   rahro[lnrahro].is='+';
                   rahro[lnrahro].x=nextWallX+1;
                   rahro[lnrahro].y=y;
                   lnrahro++;}
                }
                else if (mvinch(y, nextWallX + 1) == ' ' && (mvinch(y-1, nextWallX ) == '|')){
                    if(mapshow[y][nextWallX]==1||showfull){
                        mvprintw(y, nextWallX, "+");
                    }
                   if(mapshow[y][nextWallX+1]==1||showfull){
                        mvprintw(y, nextWallX+1, "+");
                    }
                    map[y][nextWallX]='+';
                    map[y][nextWallX+1]='+';
                    if(checkrahro==0){rahro[lnrahro].is='+';
                   rahro[lnrahro].x=nextWallX;
                   rahro[lnrahro].y=y;
                   lnrahro++;
                   rahro[lnrahro].is='+';
                   rahro[lnrahro].x=nextWallX+1;
                   rahro[lnrahro].y=y;
                   lnrahro++;}
                }
                else{
                    if(mapshow[y][nextWallX]==1||showfull){
                        mvprintw(y, nextWallX, "+");
                    }
                    map[y][nextWallX]='+';
                   if(checkrahro==0){rahro[lnrahro].is='+';
                    rahro[lnrahro].x=nextWallX;
                    rahro[lnrahro].y=y;
                    lnrahro++;}
                }
            }
            if (mvinch(nextWallY, currentWallX) == '-'){
                if(mapshow[nextWallY][nextWallX]==1||showfull){
                        mvprintw(nextWallY, nextWallX, "+");
                }
                map[nextWallY][currentWallX]='+';
                if(checkrahro==0){rahro[lnrahro].is='+';
                rahro[lnrahro].x=currentWallX;
                rahro[lnrahro].y=nextWallY;
                lnrahro++;}
            }
        }
         attroff(COLOR_PAIR(5));

    }
    checkrahro=1;
    }
}
int redolasthouse(int i){
    attron(COLOR_PAIR(5));
  for(int x=houses[i]->x;x<=houses[i]->x+houses[i]->width;x++){
    if(x==houses[i]->x&&map[houses[i]->y-1][x]=='#'){
        map[houses[i]->y][x]='+';
        map[houses[i]->y][x+1]='+';
        if(mapshow[houses[i]->y][x]==1||showfull){

           mvprintw(houses[i]->y,x,"+");
        }
        if(mapshow[houses[i]->y][x+1]==1||showfull){
           
            mvprintw(houses[i]->y,x+1,"+");
        }
    } 
    else if(x==houses[i]->x+houses[i]->width&&map[houses[i]->y-1][x]=='#'){
         map[houses[i]->y][x]='+';
        map[houses[i]->y][x-1]='+';
         if(mapshow[houses[i]->y][x]==1||showfull){
           
           mvprintw(houses[i]->y,x,"+");
        }
        if(mapshow[houses[i]->y][x-1]==1||showfull){
         
            mvprintw(houses[i]->y,x-1,"+");
        }
    }
     else if(map[houses[i]->y-1][x]=='#'&&map[houses[i]->y-2][x]=='#'){
        map[houses[i]->y][x]='+';
        if(mapshow[houses[i]->y][x]==1||showfull){
        
           mvprintw(houses[i]->y,x,"+");
        }
     }
      if(x==houses[i]->x&&map[houses[i]->y+houses[i]->height+1][x]=='#'){
        map[houses[i]->y+houses[i]->height-1][x]='+';
        map[houses[i]->y+houses[i]->height-1][x+1]='+';
        if(mapshow[houses[i]->y+houses[i]->height-1][x]==1||showfull){
           
           mvprintw(houses[i]->y+houses[i]->height-1,x+1,"+");
        }
        if(mapshow[houses[i]->y+houses[i]->height-1][x]==1||showfull){
       
             mvprintw(houses[i]->y+houses[i]->height-1,x+1,"+");
        }
    } 
    else if(x==houses[i]->x+houses[i]->width&&map[houses[i]->y+houses[i]->height+1][x]=='#'){
         map[houses[i]->y+houses[i]->height-1][x]='+';
        map[houses[i]->y+houses[i]->height-1][x+1]='+';
        if(mapshow[houses[i]->y+houses[i]->height-1][x]==1||showfull){
       
           mvprintw(houses[i]->y+houses[i]->height-1,x,"+");
        }
        if(mapshow[houses[i]->y+houses[i]->height-1][x-1]==1||showfull){
           
            mvprintw(houses[i]->y+houses[i]->height-1,x-1,"+");
        }
    }
     else if(map[houses[i]->y+houses[i]->height+1][x]=='#'&&map[houses[i]->y+houses[i]->height+2][x]=='#'){
        map[houses[i]->y+houses[i]->height-1][x]='+';
        if(mapshow[houses[i]->y+houses[i]->height-1][x]==1||showfull){
           
             mvprintw(houses[i]->y+houses[i]->height-1,x,"+");
        }
     }
     
  }
   for(int y=houses[i]->y;y<=houses[i]->y+houses[i]->height;y++){
    if(y==houses[i]->y&&map[y][houses[i]->x-1]=='#'){
        map[y][houses[i]->x-1]='+';
        map[y+1][houses[i]->x-1]='+';
        if(mapshow[y][houses[i]->x]==1||showfull){
          
           mvprintw(y,houses[i]->x,"+");
        }
        if(mapshow[y+1][houses[i]->x]==1||showfull){
          
            mvprintw(y+1,houses[i]->x,"+");
        }
    } 
    else if(y==houses[i]->y+houses[i]->height&&map[y][houses[i]->x-1]=='#'){
         map[y][houses[i]->x]='+';
        map[y-1][houses[i]->x]='+';
         if(mapshow[y][houses[i]->x]==1||showfull){
          
           mvprintw(y,houses[i]->x,"+");
        }
        if(mapshow[y-1][houses[i]->x]==1||showfull){
        
            mvprintw(y-1,houses[i]->x,"+");
        }
    }
     else if(map[y][houses[i]->x-1]=='#'&&map[y][houses[i]->x-2]=='#'){
        map[y][houses[i]->x]='+';
        if(mapshow[y][houses[i]->x]==1||showfull){
         
           mvprintw(y,houses[i]->x,"+");
        }
     }
      if(y==houses[i]->y&&map[y][houses[i]->x+houses[i]->width+1]=='#'){
        map[y][houses[i]->x+houses[i]->width-1]='+';
        map[y+1][houses[i]->x+houses[i]->width-1]='+';
        if(mapshow[y][houses[i]->x+houses[i]->width-1]==1||showfull){
          
           mvprintw(y+1,houses[i]->x+houses[i]->width-1,"+");
        }
        if(mapshow[y][houses[i]->x+houses[i]->width-1]==1||showfull){
        
             mvprintw(y+1,houses[i]->x+houses[i]->width-1,"+");
        }
    } 
    else if(y==houses[i]->y+houses[i]->height&&map[y][houses[i]->x+houses[i]->width+1]=='#'){
         map[y][houses[i]->x+houses[i]->width-1]='+';
        map[y+1][houses[i]->x+houses[i]->width-1]='+';
        if(mapshow[y][houses[i]->x+houses[i]->width-1]==1||showfull){
      
           mvprintw(y,houses[i]->x+houses[i]->width-1,"+");
        }
        if(mapshow[y-1][houses[i]->x+houses[i]->width-1]==1||showfull){
         
            mvprintw(y-1,houses[i]->x+houses[i]->width-1,"+");
        }
    }
     else if(map[y][houses[i]->x+houses[i]->width+1]=='#'&&map[y][houses[i]->x+houses[i]->width+2]=='#'){
        map[y][houses[i]->x+houses[i]->width-1]='+';
        if(mapshow[y][houses[i]->x+houses[i]->width-1]==1||showfull){
          
             mvprintw(y,houses[i]->x+houses[i]->width-1,"+");
        }
     }
     
  }
   attroff(COLOR_PAIR(5));
}

void drawHouse(House *house,int numhouse,int show){
     int npanj=0; 
     if(numhouse==1){
        attron(COLOR_PAIR(6));
     }
     else if(numhouse==4&&floorx==4){
        attron(COLOR_PAIR(5));
     }
     else{
        attron(COLOR_PAIR(210));
     }
    for (int x = house->x; x < house->x + house->width; x++)
    {
        if(map[house->y][x]!='+'){
        mvprintw(house->y, x, "-");           
        map[house->y][x]='-'; }
        else{
            if(mapshow[house->y][x]==1){
               mvprintw(house->y, x, "+"); 
            }
        }
        int p=rand()%4+3;   
        if((x==(house->width+house->x)-2)&&numhouse!=2&&npanj==0&&haspanj[numhouse]==0&&npanjtot<3){
    
            map[house->y+house->height-1][x]='<';
            npanj++;
            npanjtot++;
            haspanj[numhouse]=1;
        }
        else if(map[house->y+house->height-1][x]=='<'){
            attron(COLOR_PAIR(3));
            mvprintw(house->y + house->height - 1, x, "<");
             attroff(COLOR_PAIR(3));
        }
        else{
            if(numhouse==1){
                 attron(COLOR_PAIR(6));
            }
             else if(numhouse==4&&floorx==4){
        attron(COLOR_PAIR(5));
     }
          else{
                attron(COLOR_PAIR(210));
           }
            mvprintw(house->y + house->height - 1, x, "-");
             map[house->y+house->height-1][x]='-';
        }
    }
    attroff(COLOR_PAIR(5));
     if(numhouse==1){
        attron(COLOR_PAIR(6));
     }
      else if(numhouse==4&&floorx==4){
        attron(COLOR_PAIR(5));
     }
     else{
        attron(COLOR_PAIR(210));
     }
    for (int y = house->y + 1; y < house->y + house->height - 1; y++)
    {
         if(numhouse==1){
            attron(COLOR_PAIR(6));
        }
         else if(numhouse==4&&floorx==4){
        attron(COLOR_PAIR(5));
     }
        else{
            attron(COLOR_PAIR(210));
        }
        mvprintw(y, house->x, "|");   
        map[y][house->x]='|';
        if(nrahpele[floorx]<3&&y==(house->y + house->height - 3)&&numhouse!=2){
           map[y][house->x+house->width-1]='=';  
           nrahpele[floorx]++;  
        }
        else if(map[y][house->x+house->width-1]=='='){
             attron(COLOR_PAIR(117));
             mvprintw(y, house->x + house->width - 1, "=");
              attroff(COLOR_PAIR(117));
        }  
        else{       
            if(numhouse==1){
                   attron(COLOR_PAIR(6));
             }
              else if(numhouse==4&&floorx==4){
        attron(COLOR_PAIR(5));
     }
           else{
              attron(COLOR_PAIR(210));
            }      
           mvprintw(y, house->x + house->width - 1, "|"); 
           map[y][house->x+house->width-1]='|';
        }

        for (int x = house->x + 1; x < house->x + house->width - 1; x++)
        {
            if(map[y][x]=='O'){
                attron(COLOR_PAIR(4));
               mvprintw(y, x, "O");
               attroff(COLOR_PAIR(4));
            }
            else if(map[y][x]=='G'){
                attron(COLOR_PAIR(5));
                mvaddstr(y,x,"\u26c2");
                attroff(COLOR_PAIR(5));
            }
            else if(map[y][x]=='g'){
                attron(COLOR_PAIR(5));
                 mvaddstr(y, x, "\u26c0");
                 attroff(COLOR_PAIR(5));
            }
            else if(map[y][x]=='^'&&floorx==1){
                int i=0;
               while(1){
                   if(trap[i].y==y&&trap[i].x==x){
                      break;
                   }
                   i++;
               }
                if(trap[i].gone==0){
                    if(numhouse==1){
                     attron(COLOR_PAIR(6));
                   }
                    else if(numhouse==4&&floorx==4){
                    attron(COLOR_PAIR(5));
                   }
                   else{
                     attron(COLOR_PAIR(210));
                  }
                    mvprintw(y,x,".");
                }
                else{
                    attron(COLOR_PAIR(3));
                    mvprintw(y,x,"^");
                     attroff(COLOR_PAIR(3));
                }
            }
            else if(map[y][x]=='1'){
                  attron(COLOR_PAIR(210));
                  mvaddstr(y,x,"\u2299");
                  attroff(COLOR_PAIR(210));
            }
            else if(map[y][x]=='2'){
                  attron(COLOR_PAIR(2));
                  mvaddstr(y,x,"\u2299");
                  attroff(COLOR_PAIR(2));
            }
            else if(map[y][x]=='3'){
                  attron(COLOR_PAIR(4));
                  mvaddstr(y,x,"\u2299");
                  attroff(COLOR_PAIR(4));
            }
            else if(map[y][x]=='4'){
                  attron(COLOR_PAIR(183));
                  mvaddstr(y,x,"\u2695");
                  attroff(COLOR_PAIR(183));
            }
            else if(map[y][x]=='5'){
                  attron(COLOR_PAIR(183));
                  mvaddstr(y,x,"\u26f7");
                  attroff(COLOR_PAIR(183));
            }
            else if(map[y][x]=='6'){
                  attron(COLOR_PAIR(183));
                  mvaddstr(y,x,"\u2620");
                  attroff(COLOR_PAIR(183));
            }
            else if(map[y][x]=='B'){
                  attron(COLOR_PAIR(5));
                  mvaddstr(y,x,"\u2020");
                  attroff(COLOR_PAIR(5));
            }
            else if(map[y][x]=='N'){
                  attron(COLOR_PAIR(1));
                  mvaddstr(y,x,"\u269A");
                  attroff(COLOR_PAIR(1));
            }
            else if(map[y][x]=='M'){
                  attron(COLOR_PAIR(225));
                  mvaddstr(y,x,"\u27B3");
                  attroff(COLOR_PAIR(225));
            }
            else if(map[y][x]=='K'){
                  attron(COLOR_PAIR(2));
                  mvaddstr(y,x,"\u2694");
                  attroff(COLOR_PAIR(2));
            }
            else if(map[y][x]=='D'){
                attron(COLOR_PAIR(3));
                mvprintw(y,x,"D");
                attroff(COLOR_PAIR(3));
            }
            else if(map[y][x]=='S'){
                attron(COLOR_PAIR(3));
                mvprintw(y,x,"S");
                attroff(COLOR_PAIR(3));
            }
            else if(map[y][x]=='U'){
                attron(COLOR_PAIR(3));
                mvprintw(y,x,"U");
                attroff(COLOR_PAIR(3));
            }
            else if(map[y][x]=='F'){
                attron(COLOR_PAIR(3));
                mvprintw(y,x,"F");
                attroff(COLOR_PAIR(3));
            }
            else if(map[y][x]=='0'){
                attron(COLOR_PAIR(3));
                mvprintw(y,x,"G");
                attroff(COLOR_PAIR(3));
            }
            else if(map[y][x]=='Q'){
                attron(COLOR_PAIR(220));
                mvaddstr(y,x,"\u2733");
            }
            else{
                if(numhouse==1){
                    attron(COLOR_PAIR(6));
                }
                 else if(numhouse==4&&floorx==4){
        attron(COLOR_PAIR(5));
     }
                else{
                    attron(COLOR_PAIR(210));
                }
                map[y][x]='.';
                mvprintw(y, x, ".");
            }
        }
        attroff(COLOR_PAIR(3)|COLOR_PAIR(210)|COLOR_PAIR(6)||COLOR_PAIR(5));
    }
}
int drawmapborder(){
    clear();
    if(allroomchecked){
       for(int i=0;i<maxHeight;i++){
        for(int j=0;j<maxWidth;j++){
            mapshow[i][j]=1;
        }
      }
      for(int i=0;i<6;i++){
        houses[i]->show=1;
      }
    }
    for (int i = 0; i < 6; i++){
        if(houses[i]->show==1||showfull){
            if(houses[i]->show==1){
                for (int x = houses[i]->x; x <= houses[i]->x + houses[i]->width; x++){
                    int y=houses[i]->y;
                    int y2=houses[i]->y+houses[i]->height-1;
                   if(map[y][x]=='+'){
                      mapshow[y][x]=1;
                   }
                  if(map[y2][x]=='+'){
                       mapshow[y2][x]=1;
                  }
               }
               for (int y = houses[i]->y; y <= houses[i]->y + houses[i]->height; y++){
                    int x=houses[i]->x;
                    int x2=houses[i]->x+houses[i]->width-1;
                  if(map[y][x]=='+'){
                       mapshow[y][x]=1;
                   }
                  if(map[y][x2]=='+'){
                       mapshow[y][x2]=1;
                  }
               }
            }
           drawHouse(houses[i],i,houses[i]->show);
        }
    }
    connectHouses(houses,numberOfHouses);
    for(int i=0;i<numberOfHouses;i++){
        redolasthouse(i);
    }
   refresh();
    mvprintw(1, 2,"you are playing as");
    attron(COLOR_PAIR(6));
    mvprintw(1,2+strlen("you are playing as:"),"'%s'",usernamedarbaazi1);
    attroff(COLOR_PAIR(6));
    if(ishungry==1){
        attron(COLOR_PAIR(3));
        mvprintw(1,18+strlen("you are playing as:"),"you need food!");
    }
    if(hasfoodpicker){
        attron(COLOR_PAIR(117));
        mvprintw(1,COLS/2-10,"You can,t pick up more than 5 of each item:(");
        attroff(COLOR_PAIR(117));
        hasfoodpicker=0;
    }
    if(haswpnpicker){
        attron(COLOR_PAIR(117));
        mvprintw(1,COLS/2-10,"You have already picked up this weapon");
        attroff(COLOR_PAIR(117));
        haswpnpicker=0;
    }
    if(haswpner2){
        attron(COLOR_PAIR(3));
        mvprintw(1,COLS/2-4,"You dont have enough ammo");
        attroff(COLOR_PAIR(3));
        haswpner2=0;
    }
    if(enemydamwarn){
        attron(COLOR_PAIR(2));
        mvprintw(1,COLS/2-11,"Perfect you damaged your enemy: %d",zarbe);
        attroff(COLOR_PAIR(2));
        enemydamwarn=0;
    }
    if(enemydiedwarn){
        attron(COLOR_PAIR(5));
        mvprintw(1,COLS/2-11,"Perfect you killed your enemy");
        attroff(COLOR_PAIR(5));
        point+=50;
        enemydiedwarn=0;
    }
    if(hasbadshot){
        attron(COLOR_PAIR(183));
        mvprintw(1,COLS/2-11,"you shot went to no where!");
        attroff(COLOR_PAIR(183));
        hasbadshot=0;
    }
    if(recgold){
        attron(COLOR_PAIR(5));
        mvprintw(1,25+strlen("you are playing as:  you need food!you are  running fast "),"you recieved gold!");
        attroff(COLOR_PAIR(5));
        recgold=0;
    }
    attron(COLOR_PAIR(2));
    mvprintw(1, COLS / 2 +53, "click P to go 📋");
    attroff(COLOR_PAIR(2));
    attron(COLOR_PAIR(4));
    if(beinghungry<=20){
        mvprintw(LINES-2,COLS/2-65,"Health:%d ❣️     golds:%d 💰    score:%d  💯  energy:%d 🔋  Level %d 🛗   Distance:%d 🏃‍♂️",playerhealth,golds,point,beinghungry,floorx,distance);
    }
    else{
        mvprintw(LINES-2,COLS/2-65,"Health:%d ❣️     golds:%d 💰    score:%d  💯  energy:%d 🔋   Level %d  🛗  Distance:%d 🏃‍♂️",playerhealth,golds,point,beinghungry,floorx,distance);
    }
    attroff(COLOR_PAIR(4));
    if(isfast){
        attron(COLOR_PAIR(19));
        mvprintw(LINES-2,COLS/2-65+strlen("Health:                  golds:       score:d                            energy:d      Floor:d"),"You are as fast as $FLASH$!");
        attroff(COLOR_PAIR(3));
    }
     attron(COLOR_PAIR(18));
    if(playerhealth<=maxhealth/2){
        attron(COLOR_PAIR(19));
    }
    for (int x = 0; x < COLS; ++x) {
        mvprintw(0, x, " ");
        mvprintw(LINES - 1, x, " ");
    }
    for (int y = 1; y < LINES - 1; ++y) {
        mvprintw(y, 0, " ");
        mvprintw(y, COLS - 1, " ");
    }
    attroff(COLOR_PAIR(3));
    attron(COLOR_PAIR(colort));
    mvprintw(playery,playerx,"@");
    attroff(COLOR_PAIR(colort));
}
int mainf(){
    setlocale(LC_ALL, ""); 
    map=(char **)malloc(maxHeight*(sizeof(char *)));
    mapshow=(int **)malloc(maxHeight*(sizeof(int*)));
    for(int i=0;i<maxHeight;i++){
        map[i] =(char *) malloc(maxWidth* sizeof(char));
        mapshow[i]=(int *)malloc(maxWidth*sizeof(int));
    }
    for (int i = 0; i < numberOfHouses; i++){
        houses[i] = createHouse(maxWidth, maxHeight, houses, i);
    }
    playerx=houses[2]->x+1;
    playery=houses[2]->y+1;
}