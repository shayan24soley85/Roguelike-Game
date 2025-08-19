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
int isfirstp=1;
int print_scoreboard(int azkoja){
    clear();
    refresh();
    mvprintw(1, 2,"you are playing as:");
    attron(COLOR_PAIR(6));
    mvprintw(1,2+strlen(x),"'%s'",usernamedarbaazic);
    attroff(COLOR_PAIR(6));
    attron(COLOR_PAIR(12));
    for (int x = 0; x < COLS; ++x) {
        mvaddstr(0, x, " ");
        mvaddstr(LINES - 1, x, " ");
    }
    for (int y = 1 ;y < LINES-1 ; ++y) {
        mvaddstr(y, 0, " ");
        mvaddstr(y, COLS - 1, " ");
    }
    attroff(COLOR_PAIR(12));
    attron(COLOR_PAIR(6));
    attron(A_HORIZONTAL|A_BLINK|A_BOLD);
    mvprintw(5,COLS/2-12,"🏆🏆🏆🏆🏆  scoreboard  🏆🏆🏆🏆🏆");
    attroff(A_HORIZONTAL|A_BLINK|A_BOLD);
    attron(COLOR_PAIR(6));
    for(int y=7;y<LINES-7;y++){
        mvaddstr(y,10,"\u2600");
        mvaddstr(y,COLS-10,"\u2600");
    }
    for(int x=10;x<COLS-9;x++){
        mvaddstr(7,x,"\u2600");
        mvaddstr(LINES-7,x,"\u2600");
    }
    
    int z=(LINES-20)/9;
    attron(COLOR_PAIR(6));
    for(int i=1;i<14;i++){
        for(int x=11;x<COLS-9;x++){
           mvaddstr(7+z*i,x,"\u2600");
        }
    }
    int z2=(COLS-14)/4;
    attron(A_BOLD|COLOR_PAIR(6));
    for(int y=8;y<LINES-7;y++){
           attron(COLOR_PAIR(6));
           mvaddstr(y,25,"\u2600");
           attron(COLOR_PAIR(210));
           mvprintw(8,13,"Experience");
           attroff(COLOR_PAIR(210));
    }
    for(int y=8;y<LINES-7;y++){
           attron(COLOR_PAIR(6));
           mvaddstr(y,40,"\u2600");
           attron(COLOR_PAIR(4));
           mvprintw(8,27,"Victories");
           attroff(COLOR_PAIR(4));
    }
    for(int y=8;y<LINES-7;y++){
           attron(COLOR_PAIR(6));
           mvaddstr(y,65,"\u2600");
           attron(COLOR_PAIR(2));
           mvprintw(8,49,"Points");
           attroff(COLOR_PAIR(2));
    }
    for(int y=8;y<LINES-7;y++){
           attron(COLOR_PAIR(6));
           mvaddstr(y,90,"\u2600");
           attron(COLOR_PAIR(5));
           mvprintw(8,76,"Golds");
           attroff(COLOR_PAIR(5));
    }
    for(int y=8;y<LINES-7;y++){
           attron(COLOR_PAIR(6));
           mvaddstr(y,125,"\u2600");
           attron(COLOR_PAIR(3));
           mvprintw(8,104,"Username");
           attroff(COLOR_PAIR(3));

    }
    attron(COLOR_PAIR(117));
    int i=0;
     mvprintw(8,128,"Rank");
     attroff(COLOR_PAIR(117));
     if(isfirstp){
        i=1;
     }
     else{
        i=14;
     }
     int ic=i;
     int j=0;
    for(i;i<ic+13;i++){
        j++;
        if(players[i-1].issignedin==1){
            attron(A_ITALIC|COLOR_PAIR(2));
            mvaddstr(8+2*i,120,"✅");
           
        }
        if(i==1){
            attron(COLOR_PAIR(117));
            mvprintw(10,92,"King");
            attron(COLOR_PAIR(220));
            mvprintw(10,123,"🥇");
        }
        else if(i==2){
            attron(COLOR_PAIR(117));
            mvprintw(12,92,"King");
            attron(COLOR_PAIR(249));
             mvprintw(12,123,"🥈");
        }
        else if(i==3){
            attron(COLOR_PAIR(117));
            mvprintw(14,92,"King");
            attron(COLOR_PAIR(130));
            mvprintw(14,123,"🥉");
        }
        mvprintw(8+2*j,129,"%d",i);
        mvprintw(8+2*j,102,"%s",players[i-1].username);
        mvprintw(8+2*j,78,"%d",players[i-1].golds);
        mvprintw(8+2*j,52,"%d",players[i-1].points);
        mvprintw(8+2*j,32,"%d",players[i-1].nfinished);
        mvprintw(8+2*j,18,"%d",players[i-1].nplayed);
        attroff(COLOR_PAIR(130)|COLOR_PAIR(220)|COLOR_PAIR(249)|A_ITALIC);
    }
    attroff(COLOR_PAIR(6)|A_BOLD|COLOR_PAIR(117));
}
int scoreboard(int azkoja){
     for(int i=0;i<nusers;i++){
        if(strcmp(players[i].username,usernamedarbaazic)==0){
            players[i].issignedin=1;
        }
    }
    print_scoreboard(azkoja);
    while (1) {
        int c2 = getch();
        switch (c2) {
            case KEY_UP:
                break;
            case KEY_DOWN:
                break;
            case 'b':
            case 'B':
                if(azkoja==1){
                  return menu_setbaazi();
                }
                else{
                    return pausemenu();
                }
                break;
            case 'q':
            case 'Q':
                if(azkoja==1){
                    return 0;
                }
                break;
            case 10:
                break;
            case KEY_LEFT:
               if(!isfirstp){
                isfirstp=1;
               }
               break;
            case KEY_RIGHT:
               if(isfirstp){
                isfirstp=0;
               }
               break;
            default:
                break;
        }clear();
        print_scoreboard(azkoja);
    }
}