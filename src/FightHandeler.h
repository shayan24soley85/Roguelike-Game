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
int mojaz=0;
int checkenemyinroom(){
    for(int i=0;i<nenemy;i++){
        if(enemy[i].room==playerroom&&enemy[i].floor==floorx){
            enemy[i].canbesh=1;
            enemy[i].cantmove=0;
        }
        else{
            enemy[i].canbesh=0;
            enemy[i].cantmove=1;
        }
    }
}
int checkdamage(int i){
    int x=enemy[i].x;
    int y=enemy[i].y;
    if(x<=playerx+1&&x>=playerx-1&&y<=playery+1&&y>=playery-1&&enemy[i].canbesh==1&&enemy[i].isdead==0&&enemy[i].floor==floorx){
        return 1;
    }
    else{
        return 0;
    }
}
int shoot2(){
    for(int i=0;i<nenemy;i++){
            if(enemy[i].canbesh==1&&!enemy[i].isdead){
                if(enemy[i].x>=playerx-1&&enemy[i].x<=playerx+1&&playery+1>=enemy[i].y&&enemy[i].y>=playery-1){
                     enemy[i].health=max(enemy[i].health-zarbe,0);
                     if(enemy[i].health==0){
                        enemy[i].isdead=1;
                        enemy[i].canbesh=0;
                        enemydiedwarn=1;
                        map[enemy[i].y][enemy[i].x]='.';
                        map[enemy[i].firsty][enemy[i].firstx]='.';
                     }
                    else{
                        enemydamwarn=1;
                    }
                    hasbadshot=0;
                    break;
                }
                else{
                    hasbadshot=1;
                }
            
            }
    }
}
int shoot(int jahat){
    if(jahat==1){
        for(int i=0;i<nenemy;i++){
            if(enemy[i].canbesh==1&&!enemy[i].isdead){
                if(enemy[i].y==playery&&(playerx-enemy[i].x)<mahdoode&&playerx>enemy[i].x){
                    if(weaponon==2){
                        enemy[i].isfreez==1;
                    }
                     enemy[i].health=max(enemy[i].health-zarbe,0);
                     if(enemy[i].health==0){
                        enemy[i].isdead=1;
                        enemy[i].canbesh=0;
                        enemydiedwarn=1;
                        map[enemy[i].y][enemy[i].x]='.';
                        map[enemy[i].firsty][enemy[i].firstx]='.';
                     }
                    else{
                        enemydamwarn=1;
                    }
                    hasbadshot=0;
                    break;
                }
                else{
                    hasbadshot=1;
                }
            }
        }
    }
    else if(jahat==2){
        for(int i=0;i<nenemy;i++){
            if(enemy[i].canbesh==1&&!enemy[i].isdead){
                if(enemy[i].y==playery&&(-playerx+enemy[i].x)<mahdoode&&playerx<enemy[i].x){
                    if(weaponon==2){
                        enemy[i].isfreez==1;
                    }
                     enemy[i].health=max(enemy[i].health-zarbe,0);
                     if(enemy[i].health==0){
                        enemy[i].isdead=1;
                        enemy[i].canbesh=0;
                        enemydiedwarn=1;
                        map[enemy[i].y][enemy[i].x]='.';
                        map[enemy[i].firsty][enemy[i].firstx]='.';
                     }
                    else{
                        enemydamwarn=1;
                    }
                    hasbadshot=0;
                    break;
                }
                else{
                    hasbadshot=1;
                }
            }
        }
    }
     else if(jahat==3){
        for(int i=0;i<nenemy;i++){

            if(enemy[i].canbesh==1&&!enemy[i].isdead){
                if(enemy[i].x==playerx&&(playery-enemy[i].y)<mahdoode&&playery>enemy[i].y){
                    if(weaponon==2){
                        enemy[i].isfreez==1;
                    }
                     enemy[i].health=max(enemy[i].health-zarbe,0);
                     if(enemy[i].health==0){
                        enemy[i].isdead=1;
                        enemy[i].canbesh=0;
                        enemydiedwarn=1;
                        map[enemy[i].y][enemy[i].x]='.';
                        map[enemy[i].firsty][enemy[i].firstx]='.';
                     }
                    else{
                        enemydamwarn=1;
                    }
                    hasbadshot=0;
                    break;
                }
                else{
                    hasbadshot=1;
                }
            }
        }
    }
     else if(jahat==4){
        for(int i=0;i<nenemy;i++){
            if(enemy[i].canbesh==1&&!enemy[i].isdead){
                if(enemy[i].x==playerx&&(-playery+enemy[i].y)<mahdoode&&playery<enemy[i].y){
                    if(weaponon==2){
                        enemy[i].isfreez==1;
                    }
                     enemy[i].health=max(enemy[i].health-zarbe,0);
                     if(enemy[i].health==0){
                        enemy[i].isdead=1;
                        enemy[i].canbesh=0;
                        enemydiedwarn=1;
                        map[enemy[i].y][enemy[i].x]='.';
                        map[enemy[i].firsty][enemy[i].firstx]='.';
                     }
                    else{
                        enemydamwarn=1;
                    }
                    hasbadshot=0;
                    break;
                }
                else{
                    hasbadshot=1;
                }
            }
        }
    }
}
int fight(){
    int back=0;
    if(weaponon>=2&&weaponon<=4){
        int c=getch();
        switch (c){
        case KEY_LEFT:
            jahatsh=1;
            break;
        case KEY_RIGHT:
            jahatsh=2;
            break;
        case KEY_UP:
            jahatsh=3;
            break;
        case KEY_DOWN:
            jahatsh=4;
            break;
        default:
            back=1;
            break;
        }
        if(back==0){
         if(weaponon!=3){
            mahdoode=5;
        }
        else{
            mahdoode=10;
        }
        if(weaponon==2){
            if(nwp[1]>=1){
              nwp[1]--;
              zarbe=playerattack*12;
              mojaz=1;
            }
            else{
                mojaz=0;
            }
        }
        else if(weaponon==3){
           if(nwp[2]>=1){
              nwp[2]--;
              zarbe=playerattack*15;
              mojaz=1;
            }
            else{
                mojaz=0;
            }
        }
        else if(weaponon==4){
           if(nwp[3]>=1){
              nwp[3]--;
              zarbe=playerattack*5;
              mojaz=1;
            }
            else{
                mojaz=0;
            }
        }
        if(mojaz){
            if(jahatsh==1){
        for(int i=playerx-1;i>=playerx-mahdoode;i--){
                        attron(COLOR_PAIR(3));
                        if(map[playery][i]!='-'&&map[playery][i]!='|'){
                        mvprintw(playery,i,"<");
                         refresh();
                         napms(40);}
                         else{
                            break;
                         }
                        attroff(COLOR_PAIR(3));
        }}
        else if(jahatsh==2){
            for(int i=playerx+1;i<=playerx+mahdoode;i++){
                        attron(COLOR_PAIR(3));
                        if(map[playery][i]!='-'&&map[playery][i]!='|'){
                        mvprintw(playery,i,">");
                         refresh();
                         napms(40);}
                         else{
                            break;
                         }
                        attroff(COLOR_PAIR(3));
                    }
        }
        else if(jahatsh==3){
            for(int i=playery-1;i>=playery-mahdoode;i--){
                        attron(COLOR_PAIR(3));
                        if(map[i][playerx]!='-'&&map[i][playerx]!='|'){
                        mvprintw(i,playerx,"!");
                         refresh();
                         napms(40);}
                         else{
                            break;
                         }
                        attroff(COLOR_PAIR(3));
                    }
        }
        else if(jahatsh==4){
            for(int i=playery+1;i<=playery+mahdoode;i++){
                        attron(COLOR_PAIR(3));
                        if(map[i][playerx]!='-'&&map[i][playerx]!='|'){
                        mvprintw(i,playerx,"!");
                         refresh();
                         napms(40);}
                         else{
                            break;
                         }
                        attroff(COLOR_PAIR(3));
            }
        }
           checkenemyinroom();
           shoot(jahatsh);
        }
        else{
            haswpner2=1;
            weaponon=1;
        }
        }
    }
    else{
       if(weaponon==1){
           zarbe=playerattack*5;
        }
        else if(weaponon==5){
            zarbe=playerattack*10;
        }
        checkenemyinroom();
        shoot2();
    }
}
int checkfasel(int i,int nop){
    int x=enemy[i].x;
    int y=enemy[i].y;
    if(nop==2){
        if(!(enemy[i].x>=enemy[i].firstx-5&&enemy[i].x<=enemy[i].firstx+5&&enemy[i].y<=enemy[i].firsty+5&&enemy[i].y>=enemy[i].firsty-5)){
            return 0;
        }
    }
    if(playerx>enemy[i].x&&playery>enemy[i].y){
        if(nop==1){ 
            if(map[y+1][x+1]=='#'||map[y+1][x+1]=='+'||map[y+1][x+1]==' '){
                return 0;
            }
        }
           if(playerx==enemy[i].x+1&&playery==enemy[i].y+1){
            return 0;
           }
           else{
            return 1;
           }
    }
    else if(playerx<enemy[i].x&&playery<enemy[i].y){
        if(nop==1){ 
            if(map[y-1][x-1]=='#'||map[y-1][x-1]=='+'||map[y-1][x-1]==' '){
                return 0;
            }
        }
         if(playerx==enemy[i].x-1&&playery==enemy[i].y-1){
            return 0;
           }
           else{
            return 1;
           }
   }
   else if(playerx>enemy[i].x&&playery<enemy[i].y){
        if(nop==1){ 
            if(map[y-1][x+1]=='#'||map[y-1][x+1]=='+'||map[y-1][x+1]==' '){
                return 0;
            }
        }
        if(playerx==enemy[i].x+1&&playery==enemy[i].y-1){
            return 0;
           }
           else{
            return 1;
           }
    
   }
   else if(playerx<enemy[i].x&&playery>enemy[i].y){
          if(nop==1){ 
            if(map[y+1][x-1]=='#'||map[y+1][x-1]=='+'||map[y+1][x-1]==' '){
                return 0;
            }
          }
           if(playerx==enemy[i].x-1&&playery==enemy[i].y+1){
            return 0;
           }
           else{
            return 1;
           }
   }
   else if(playerx>enemy[i].x&&playery==enemy[i].y){
          if(nop==1){ 
            if(map[y][x+1]=='#'||map[y][x+1]=='+'||map[y][x+1]==' '){
                return 0;
            }
        }
          if(playerx==enemy[i].x+1){
            return 0;
           }
           else{
            return 1;
           }
    
   }
   else if(playerx<enemy[i].x&&playery==enemy[i].y){
    if(nop==1){ 
            if(map[y][x-1]=='#'||map[y][x-1]=='+'||map[y][x-1]==' '){
                return 0;
            }
        }
     if(playerx==enemy[i].x-1){
            return 0;
           }
           else{
            return 1;
           }
    
   }
   else if(playerx==enemy[i].x&&playery>enemy[i].y){
    if(nop==1){ 
            if(map[y+1][x]=='#'||map[y+1][x]=='+'||map[y+1][x]==' '){
                return 0;
            }
        }
     if(playery==enemy[i].y+1){
            return 0;
           }
           else{
            return 1;
           }
    
   }
   else if(playerx==enemy[i].x&&playery<enemy[i].y){
      if(nop==1){ 
            if(map[y-1][x]=='#'||map[y-1][x]=='+'||map[y-1][x]==' '){
                return 0;
            }
        }
     if(playery==enemy[i].y-1){
            return 0;
           }
           else{
            return 1;
           }
   }

}
int enemymovement(){
    checkenemyinroom();
    for(int i=0;i<nenemy;i++){
        int checkmo;
        if(enemy[i].noe==4){
             checkmo=checkfasel(i,1);
        }
        else{
             checkmo=checkfasel(i,2);
        }
        
        if(enemy[i].canbesh&&enemy[i].isdead==0&&checkmo){
            if(enemy[i].noe==4){
                if(playerx>enemy[i].x&&playery>enemy[i].y){
                    map[enemy[i].y][enemy[i].x]='.';
                    enemy[i].x++;
                    enemy[i].y++;
                    map[enemy[i].y][enemy[i].x]='S';
                }
                else if(playerx<enemy[i].x&&playery<enemy[i].y){
                    map[enemy[i].y][enemy[i].x]='.';
                    enemy[i].x--;
                    enemy[i].y--;
                    map[enemy[i].y][enemy[i].x]='S';
                }
                else if(playerx>enemy[i].x&&playery<enemy[i].y){
                    map[enemy[i].y][enemy[i].x]='.';
                    enemy[i].x++;
                    enemy[i].y--;
                    map[enemy[i].y][enemy[i].x]='S';
                }
                else if(playerx<enemy[i].x&&playery>enemy[i].y){
                    map[enemy[i].y][enemy[i].x]='.';
                    enemy[i].x--;
                    enemy[i].y++;
                    map[enemy[i].y][enemy[i].x]='S';
                }
                else if(playerx>enemy[i].x&&playery==enemy[i].y){
                    map[enemy[i].y][enemy[i].x]='.';
                    enemy[i].x++;
                    map[enemy[i].y][enemy[i].x]='S';
                }
                else if(playerx<enemy[i].x&&playery==enemy[i].y){
                    map[enemy[i].y][enemy[i].x]='.';
                    enemy[i].x--;
                    map[enemy[i].y][enemy[i].x]='S';
                }
                else if(playerx==enemy[i].x&&playery>enemy[i].y){
                    map[enemy[i].y][enemy[i].x]='.';
                    enemy[i].y++;
                    map[enemy[i].y][enemy[i].x]='S';
                }
                else if(playerx==enemy[i].x&&playery<enemy[i].y){
                    map[enemy[i].y][enemy[i].x]='.';
                    enemy[i].y--;
                    map[enemy[i].y][enemy[i].x]='S';
                }
            }
            else if(checkmo){
                char x;
                if(enemy[i].noe==1){
                    x='D';
                }
                else if(enemy[i].noe==2){
                    x='F';
                }
                else if(enemy[i].noe==3){
                    x='0';
                }
                else if(enemy[i].noe==5){
                    x='U';
                }
                if(playerx>enemy[i].x&&playery>enemy[i].y){
                    map[enemy[i].y][enemy[i].x]='.';
                    enemy[i].x++;
                    enemy[i].y++;
                    map[enemy[i].y][enemy[i].x]=x;
                }
                else if(playerx<enemy[i].x&&playery<enemy[i].y){
                    map[enemy[i].y][enemy[i].x]='.';
                    enemy[i].x--;
                    enemy[i].y--;
                    map[enemy[i].y][enemy[i].x]=x;
                }
                else if(playerx>enemy[i].x&&playery<enemy[i].y){
                    map[enemy[i].y][enemy[i].x]='.';
                    enemy[i].x++;
                    enemy[i].y--;
                    map[enemy[i].y][enemy[i].x]=x;
                }
                else if(playerx<enemy[i].x&&playery>enemy[i].y){
                    map[enemy[i].y][enemy[i].x]='.';
                    enemy[i].x--;
                    enemy[i].y++;
                    map[enemy[i].y][enemy[i].x]=x;
                }
                else if(playerx>enemy[i].x&&playery==enemy[i].y){
                    map[enemy[i].y][enemy[i].x]='.';
                    enemy[i].x++;
                    map[enemy[i].y][enemy[i].x]=x;
                }
                else if(playerx<enemy[i].x&&playery==enemy[i].y){
                    map[enemy[i].y][enemy[i].x]='.';
                    enemy[i].x--;
                    map[enemy[i].y][enemy[i].x]=x;
                }
                else if(playerx==enemy[i].x&&playery>enemy[i].y){
                    map[enemy[i].y][enemy[i].x]='.';
                    enemy[i].y++;
                    map[enemy[i].y][enemy[i].x]=x;
                }
                else if(playerx==enemy[i].x&&playery<enemy[i].y){
                    map[enemy[i].y][enemy[i].x]='.';
                    enemy[i].y--;
                    map[enemy[i].y][enemy[i].x]=x;
                }
            }
        }
    }
}
enemydamage(){
    for(int i=0;i<nenemy;i++){
        int checkdm=checkdamage(i);
        int x=enemy[i].noe;
        int dm;
        if(x==1){
            dm=5;
        }
        else if(x==2){
            dm=10;
        }
        else if(x==3){
            dm=15;
        }
        else if(x==4){
            dm=20;
        }
        else if(x==5){
            dm=30;
        }
        if(enemy[i].canbesh==1&&checkdm&&numkey%700==0){
            if(x!=4){
                playerhealth=max(0,playerhealth-dm);
            }
            else if(x==4&&numkey%90==0){
                playerhealth=max(0,playerhealth-dm);
            }
        }
    }
}