#include <ncurses.h>  
#include <string.h> 
#include<stdlib.h>
#include<time.h>
#include "RegisterMenu.h"
#include "PreGameMenu.h"
#include "MainGameView.h"
#include "PauseMenu.h"
#include "GameDetailsHandeler.h"
#include "MapHandeler.h"
#include "ScoreboardMenu.h"
#include "savingHandeler.h"
#include "FightHandeler.h"
#include<unistd.h>
#include <locale.h>
#include<curses.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdbool.h>

int min(int a,int b){
    if(a>b){
        return b;
    }
    else{
        return a;
    }
} 
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int main() {  
    setlocale(LC_ALL, ""); 
    initscr();  
    cbreak();
    noecho();
    keypad(stdscr, TRUE);  
    start_color(); 
    curs_set(0); 
    int x=menu_vorud();
    if(x==0){
        refresh();
        endwin();
    }
    int y;
    int z;
    if(x!=0){
        y=menu_setbaazi();
    }
    if(y==0||x==0){
        refresh();
        endwin();
    }
    else{
       z=mainx();
    }
    if(z==0||x==0||y==0){
        refresh();
        endwin();
    }
    refresh();
    endwin();
    cleanupSDL();
    return 0;  
}