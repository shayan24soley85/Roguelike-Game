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
#ifndef PreGameMenu.h
#define  PreGameMenu.h
extern int musicchoice=1;
extern int colorchoice=1;
extern int sathchoice=1;
#endif  
Mix_Music *music1;
Mix_Music *music2;
Mix_Music *music3;
const char *options_menu21[] = { "Resume game", "New game", "Settings","Score board","Profile" };
const char *options_menu22[]={"Game level","Change hero,s color","Music"};
const char *options_menusath[]={"EASY","MEDIUM","HARD"};
const char *options_menucolor[]={"yellow","green","blue"};
const char *options_menumusic[]={"Turn off","music1","music2","music3"};
const char *options_menufood[]={"simple","special","magic"};
const char *options_menumajoon[]={"Health","Speed","Damage"};
const char *options_menuweapon[]={"Mace","Dagger","Magic wand","Normal Arrow","Sword"};
const char *options_menup[] = { "Music","Foods","electuery","weapons", "Resume game","Score board", "Save and exit" };
char x[]="you are playing as'";
int highlight21=1;
int highlight22=1;
int highlightsath=1;
int highlightcolor=1;
int highlightmusic=1;
int highlightfood=1;
int highlightmajoon=1;
int highlightweapon=1;
int choice222=0;
int choice223=0;
int choice22=0;
int choice21=0;
int hasprofer=0;
FILE *file;

int  draw_menu_border21() {
    clear();
    mvprintw(1, 2,"you are playing as");
    attron(COLOR_PAIR(6));
    mvprintw(1,2+strlen(x),"'%s'",usernamedarbazi);
    attroff(COLOR_PAIR(6));
    attron(COLOR_PAIR(90));
    for (int x = 0; x < COLS; ++x) {
        mvprintw(0, x, " ");
        mvprintw(LINES - 1, x, " ");
    }
    for (int y = 1; y < LINES - 1; ++y) {
        mvprintw(y, 0, " ");
        mvprintw(y, COLS - 1, " ");
    }
    attroff(COLOR_PAIR(90));
}
int draw_menu_border22(){
    clear();
    mvprintw(1, 2,"you are playing as:");
    attron(COLOR_PAIR(6));
    mvprintw(1,2+strlen(x),"'%s'",usernamedarbazi);
    attroff(COLOR_PAIR(6));
    attron(COLOR_PAIR(198));
    for (int x = 0; x < COLS; ++x) {
        mvprintw(0, x, " ");
        mvprintw(LINES - 1, x, " ");
    }
    for (int y = 1; y < LINES - 1; ++y) {
        mvprintw(y, 0, " ");
        mvprintw(y, COLS - 1, " ");
    }
    attroff(COLOR_PAIR(198));
}
int  print_menu21() {
    draw_menu_border21();
    int cols = (COLS / 2) - 32;
    attron(COLOR_PAIR(210));
    mvprintw(8, cols, "____  ____  _____    ____    _    __  __ _____   __  __ _____ _   _ _   _ ");
    mvprintw(9, cols, "|  _ \\|  _ \\| ____|  / ___|  / \\  |  \\/  | ____| |  \\/  | ____| \\ | | | | |");
    mvprintw(10, cols, "| |_) | |_) |  _|   | |  _  / _ \\ | |\\/| |  _|   | |\\/| |  _| |  \\| | | | |");
    mvprintw(11, cols, "|  __/|  _ <| |___  | |_| |/ ___ \\| |  | | |___  | |  | | |___| |\\  | |_| |");
    mvprintw(12, cols, "|_|   |_| \\_\\_____|  \\____/_/   \\_\\_|  |_|_____| |_|  |_|_____|_| \\_|\\___/");
    attroff(COLOR_PAIR(210));
    for (int i = 0; i < 5; ++i) {
        if (highlight21 == i + 1) {
            attron(COLOR_PAIR(26));
        }
        mvprintw(LINES / 2 + (i - 2) * 2, COLS / 2, "%s", options_menu21[i]);
        attroff(COLOR_PAIR(26));
    }
    if(hasprofer){
        attron(COLOR_PAIR(1));
        mvprintw(1,COLS/2-10,"You Dont have profile ,you are playing as guest");
        attroff(COLOR_PAIR(1));
        hasprofer=0;
    }
    refresh();
}
int print_menu22(){
    draw_menu_border22();
    int cols = (COLS / 2) - 31; 
    attron(COLOR_PAIR(199));
    mvprintw(8, cols, "____  _____ _____ _____ ___ _   _  ____   __  __ _____ _   _ _   _ ");
    mvprintw(9, cols, "/ ___|| ____|_   _|_   _|_ _| \\ | |/ ___| |  \\/  | ____| \\ | | | | |");
    mvprintw(10, cols, "\\___ \\|  _|   | |   | |  | ||  \\| | |  _  | |\\/| |  _| |  \\| | | | |");
    mvprintw(11, cols, " ___) | |___  | |   | |  | || |\\  | |_| | | |  | | |___| |\\  | |_| |");
    mvprintw(12, cols, "|____/|_____| |_|   |_| |___|_| \\_|\\____| |_|  |_|_____|_| \\_|\\___/");
    attroff(COLOR_PAIR(199));
    for (int i = 0; i < 3; ++i) {
        if (highlight22== i + 1) {
            attron(COLOR_PAIR(195));
        }
        mvprintw(LINES / 2 + (i - 1) * 4, COLS / 2, "%s", options_menu22[i]);
        attroff(COLOR_PAIR(195));
    }
    refresh();
}
int print_menusath(){
    print_menu22();
    for (int i = 0; i < 3; ++i) {
        if (highlightsath== i + 1) {
            attron(COLOR_PAIR(6));
        }
        mvprintw(LINES / 2 + (i - 1) * 1-4, COLS / 2+strlen(options_menu22[0])+3, "%s", options_menusath[i]);
        attroff(COLOR_PAIR(6));
    }
    for (int i = 0; i < 3; ++i) {
        if (sathchoice== i + 1) {
            attron(COLOR_PAIR(1));
            mvprintw(LINES / 2 + (i - 1) * 1-4, COLS / 2+strlen(options_menu22[0])+4+strlen(options_menusath[i]), "✅");
        }
        attroff(COLOR_PAIR(1));
    }
    refresh();
}
int print_menucolor(){
    print_menu22();
    for (int i = 0; i < 3; ++i) {
        if (highlightcolor== i + 1) {
            attron(COLOR_PAIR(6));
        }
        mvprintw(LINES / 2 + (i - 1) * 1, COLS / 2+strlen(options_menu22[1])+3, "%s", options_menucolor[i]);
        attroff(COLOR_PAIR(6));
    }
    for (int i = 0; i < 3; ++i) {
        if (colorchoice== i + 1) {
            attron(COLOR_PAIR(1));
            mvprintw(LINES / 2 + (i - 1) * 1, COLS / 2+strlen(options_menu22[1])+4+strlen(options_menucolor[i]), "✅");
        }
        attroff(COLOR_PAIR(1));
    }
    refresh();
}
int print_menumusic(){
    print_menu22();
    for (int i = 0; i < 4; ++i) {
        if (highlightmusic== i + 1) {
            attron(COLOR_PAIR(3));
            if(highlightmusic==1){
                 attron(COLOR_PAIR(2));
            }
        }
        mvprintw(LINES / 2 + (i - 1) * 1+4, COLS / 2+strlen(options_menu22[2])+3, "%s", options_menumusic[i]);
        attroff(COLOR_PAIR(2));
        attroff(COLOR_PAIR(3));
    }
    for (int i = 0; i < 4; ++i) {
        if (musicchoice== i + 1) {
            attron(COLOR_PAIR(1));
            mvprintw(LINES / 2 + (i - 1) * 1+4, COLS / 2+strlen(options_menu22[2])+4+strlen(options_menumusic[i]), "✅");
        }
        attroff(COLOR_PAIR(1));
    }
    refresh();
}

print_prof(){
     clear();
    refresh();
    mvprintw(1, 2,"you are playing as:");
    attron(COLOR_PAIR(6));
    mvprintw(1,2+strlen(x),"'%s'",usernamedarbaazic);
    attroff(COLOR_PAIR(6));
    attron(COLOR_PAIR(14));
    for (int x = 0; x < COLS; ++x) {
        mvaddstr(0, x, " ");
        mvaddstr(LINES - 1, x, " ");
    }
    for (int y = 1 ;y < LINES-1 ; ++y) {
        mvaddstr(y, 0, " ");
        mvaddstr(y, COLS - 1, " ");
    }
    attron(COLOR_PAIR(2));
    for(int y=8;y<LINES-8;y++){
        mvprintw(y,COLS/2-10,"@");
        mvprintw(y,COLS/2+25,"@");
    }
    attron(A_BOLD);
    mvprintw(6,COLS/2,"Profile Menu");
    attroff(A_BOLD);
    attron(COLOR_PAIR(117));
    mvprintw(10,COLS/2-3,"Username: %s",usernamedarbaazic);
    mvprintw(16,COLS/2-3,"Email: %s",playeremail);
    mvprintw(24,COLS/2-3,"Password: %s",playerpassw);
    mvprintw(32,COLS/2-3,"Phone Number: %s",playerphone);

}
int prof(){
    estekhraaj();
    print_prof();
    while (1) {
        int c2 = getch();
        switch (c2) {
            case KEY_UP:
                break;
            case KEY_DOWN:
                break;
            case 'b':
            case 'B':
                return menu_setbaazi();
                break;
            case 'q':
            case 'Q':
                    return 0;
                break;
            case 10:
                break;
            default:
                break;
        }clear();
        print_prof();
    }
}
int sath(){
    highlightsath=1;
    print_menusath();
    while (1) {
        int c2 = getch();
        switch (c2) {
            case KEY_UP:
                highlightsath--;
                if (highlightsath < 1) highlightsath = 3;
                break;
            case KEY_DOWN:
                highlightsath++;
                if (highlightsath > 3) highlightsath = 1;
                break;
            case 'b':
            case 'B':
                clear();
                int returno;
                choice22=0;
                returno=setting();
            
                return returno;
                break;
            case 'q':
            case 'Q':
                return 0;
            case 10:
                sathchoice = highlightsath;
                break;
            default:
                break;
        }
        print_menusath();
    }
}
int rang(){
    highlightcolor=1;
    print_menucolor();
    while (1) {
        int c3 = getch();
        switch (c3) {
            case KEY_UP:
                highlightcolor--;
                if (highlightcolor < 1) highlightcolor= 3;
                break;
            case KEY_DOWN:
                highlightcolor++;
                if (highlightcolor > 3) highlightcolor = 1;
                break;
            case 'b':
            case 'B':
                clear();
                int returnp;
                choice22=0;
                returnp=setting();
                return returnp;
                break;
            case 'q':
            case 'Q':
                return 0;
            case 10:
                colorchoice = highlightcolor;
                break;
            default:
                break;
        }
        print_menucolor();
    }
}
bool initializeSDL() {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        return false;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        return false;
    }
    music1 = Mix_LoadMUS("musics/music1x.mp3");
    music2 = Mix_LoadMUS("musics/music2x.mp3");
    music3 = Mix_LoadMUS("musics/music3x.mp3");
    if (!music1 || !music2 || !music3) {
        printf("Failed to load music! SDL_mixer Error: %s\n", Mix_GetError());
        return false;
    }
    return true;
}
void cleanupSDL() {
    Mix_FreeMusic(music1);
    Mix_FreeMusic(music2);
    Mix_FreeMusic(music3);
    Mix_CloseAudio();
    SDL_Quit();
}
int playMusic(int musicchoicex) {
    Mix_HaltMusic();
    switch (musicchoicex) {
        case 1:
            Mix_HaltMusic();
            break;
        case 2:
            Mix_PlayMusic(music1, -1); 
            break;
        case 3:
            Mix_PlayMusic(music2, -1); 
            break;
        case 4:
            Mix_PlayMusic(music3, -1); 
            break;
        default:
            break;
    }

}
int music(){
   highlightmusic=1;
    print_menumusic();
    if (!initializeSDL()) {
        printf("Failed to initialize SDL and SDL_Mixer!\n");
        return 1;
    }
    while (1) {
        int c4 = getch();
        switch (c4) {
            case KEY_UP:
                highlightmusic--;
                if (highlightmusic < 1) highlightmusic= 4;
                break;
            case KEY_DOWN:
                highlightmusic++;
                if (highlightmusic > 4) highlightmusic = 1;
                break;
            case 'b':
            case 'B':
                clear();
                int returnm;
                choice22=0;
                returnm=setting();
            
                return returnm;
                break;
            case 'q':
            case 'Q':
                return 0;
                break;
            case 10:
                musicchoice = highlightmusic;
                playMusic(musicchoice);
                break;
            default:
                break;
        }
        print_menumusic();
    }
}
int setting(){
    print_menu22();
    while (1) {
        int c2 = getch();
        switch (c2) {
            case KEY_UP:
                highlight22--;
                if (highlight22 < 1) highlight22 = 3;
                break;
            case KEY_DOWN:
                highlight22++;
                if (highlight22 > 3) highlight22 = 1;
                break;
            case 'b':
            case 'B':
                clear();
                int returnx;
                choice21=0;
                choice22=0;
                returnx=menu_setbaazi();
                return returnx;
                break;
            case 'q':
            case 'Q':
                return 0;
                break;
            case 10:
                choice22 = highlight22;
                break;
            default:
                break;
        }
        print_menu22();
        if(choice22==1){
            int n=sath();
            return n;
        }
        else if(choice22==2){
            int n=rang();
            return n;
        }
        else if(choice22==3){
            int n=music();
            return n;
        }
    }
}

int menu_setbaazi(){
    choice21=0;
    highlight21=1;
    clear();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
    init_pair(5,COLOR_YELLOW,COLOR_BLACK);
    init_pair(6,COLOR_MAGENTA,COLOR_BLACK);
    init_pair(7,COLOR_BLACK,COLOR_YELLOW);
    init_pair(220,220,COLOR_BLACK);
    init_pair(12,COLOR_YELLOW,COLOR_YELLOW);
    init_pair(117,117,COLOR_BLACK);
   init_pair(132,132,COLOR_BLACK);
   init_pair(210,210,COLOR_BLACK);
   init_pair(93,93,COLOR_BLACK);
   init_pair(90,210,210);
   init_pair(26,COLOR_BLACK,210);
   init_pair(261,210,COLOR_BLACK);
   init_pair(249,249,COLOR_BLACK);
   init_pair(130,130,COLOR_BLACK);
   init_pair(14,COLOR_GREEN,COLOR_GREEN);
   init_pair(110,132,132);
   init_pair(199,199,COLOR_BLACK);
   init_pair(198,199,199);
   init_pair(195,COLOR_BLACK,199);

   init_pair(134,227,227);
    print_menu21();
    while (1) {
        int cs = getch();
        switch (cs) {
            case KEY_UP:
                highlight21--;
                if (highlight21 < 1) highlight21 = 5;
                break;
            case KEY_DOWN:
                highlight21++;
                if (highlight21 > 5) highlight21 = 1;
                break;
            case 10:
                choice21 = highlight21;
                break;
            case 'q':
            case 'Q':
                return 0;
                break;
            default:
                break;
        }
         print_menu21();
        if (choice21!= 0) break;
    }
    clear();
    if(choice21==2){
        
      return 1;
    }
    else if(choice21==1){
    if(hasacc){
      resume=1;
        
    }  
        return 1;
    }
    else if(choice21==3){
        draw_menu_border22();
         return setting();
        
    }
    else if(choice21==4){
       return scoreboard(1);
    }
    else if(choice21==5){
        if(hasacc){
           return prof();
        }
        else{
            hasprofer=1;
            return menu_setbaazi();
        }
    }
}