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
int print_menumusicp(){
    drawpausemenu();
    for (int i = 0; i < 4; ++i) {
        if (highlightmusicp== i + 1) {
            attron(COLOR_PAIR(3));
            if(highlightmusicp==1){
                 attron(COLOR_PAIR(2));
            }
        }
        mvprintw(LINES / 2 + (i - 3) * 1-10, COLS / 2+strlen(options_menup[0])+3, "%s", options_menumusic[i]);
        attroff(COLOR_PAIR(2));
        attroff(COLOR_PAIR(3));
    }
    for (int i = 0; i < 4; ++i) {
        if (musicchoice== i + 1) {
            attron(COLOR_PAIR(1));
            mvprintw(LINES / 2 + (i - 3) * 1-10, COLS / 2+strlen(options_menup[0])+3+strlen(options_menumusic[i]), "✅");
        }
        attroff(COLOR_PAIR(1));
    }
    refresh();
}
int print_foodmenu(){
    clear();
    attron(COLOR_PAIR(4));
    mvprintw(LINES-2,COLS/2-65,"Health:%d\tgolds:%d       score:%d     energy:%d      Floor:%d",playerhealth,golds,point,beinghungry,floorx);
    attroff(COLOR_PAIR(4));
    if(hasfooder){
        attron(COLOR_PAIR(117));
        mvprintw(1, COLS/2-8,"You don,t have this food!");
        attroff(COLOR_PAIR(117));
        hasfooder=0;
    }
    if(atebadfood){
        attron(COLOR_PAIR(210));
        mvprintw(1,COLS/2-8,"You ate spoiled food!!!");
        attroff(COLOR_PAIR(210));
        atebadfood=0;
    }
    if(maxhealther){
        attron(COLOR_PAIR(2));
        mvprintw(1,COLS/2-8,"You your health is max!");
        attroff(COLOR_PAIR(2));
        maxhealther=0;
    }
    attron(COLOR_PAIR(210)|A_BOLD);
    mvprintw(LINES/2-10, COLS/2-1,"Your Foods");
    attroff(COLOR_PAIR(210)|A_BOLD);
    mvprintw(1, 2,"you are playing as:");
    attron(COLOR_PAIR(6));
    mvprintw(1,2+strlen(x),"'%s'",usernamedarbazi);
    attroff(COLOR_PAIR(6));
    attron(COLOR_PAIR(210));
    for(int y=LINES/2-9;y<=LINES/2+8;y++){
        mvaddstr(y,COLS/2-8,"\u2299");
        mvaddstr(y,COLS/2+16,"\u2299");
    }
    for (int x = 0; x < COLS; ++x) {
        mvprintw(0, x, "-");
        mvprintw(LINES - 1, x, "-");
    }
    for (int y = 1; y < LINES - 1; ++y) {
        mvprintw(y, 0, "|");
        mvprintw(y, COLS - 1, "|");
    }
    attroff(COLOR_PAIR(210));
    for (int i = 0; i < 3; ++i) {
        if (highlightfood== i + 1) {
            attron(COLOR_PAIR(210));
        }
        mvprintw(LINES / 2 + (i - 1) * 4, COLS / 2, "%s  %d", options_menufood[i],nfood[i]);
        attroff(COLOR_PAIR(210));
    }
    refresh();
}
int print_majoonmenu(){
    clear();
    attron(COLOR_PAIR(4));
    mvprintw(LINES-2,COLS/2-65,"Health:%d\tgolds:%d       score:%d     energy:%d      Floor:%d",playerhealth,golds,point,beinghungry,floorx);
    attroff(COLOR_PAIR(4));
    if(hasmajooner){
        attron(COLOR_PAIR(117));
        mvprintw(1, COLS/2-8,"You don,t have this magic drink!");
        attroff(COLOR_PAIR(117));
        hasmajooner=0;
    }
    attron(COLOR_PAIR(93)|A_BOLD);
    int cols = (COLS / 2) - 2;     
    mvprintw(2, cols, " . .      ");
    mvprintw(3, cols, "  ...     ");
    mvprintw(4, cols, "\\~~~~~/  ");
    mvprintw(5, cols, " \\   /   ");
    mvprintw(6, cols, "  \\ /    ");
    mvprintw(7, cols, "   V     ");
    mvprintw(8, cols, "   |     ");
    mvprintw(9, cols, "   |     ");
    mvprintw(10, cols, "  ---    ");
    mvprintw(LINES/2-10, COLS/2-4,"Your Magic drinks");
    attroff(COLOR_PAIR(93)|A_BOLD);
    mvprintw(1, 2,"you are playing as:");
    attron(COLOR_PAIR(6));
    mvprintw(1,2+strlen(x),"'%s'",usernamedarbazi);
    attroff(COLOR_PAIR(6));
    attron(COLOR_PAIR(93));
    for(int y=LINES/2-9;y<=LINES/2+8;y++){
        mvaddstr(y,COLS/2-8,"\u271D");
        mvaddstr(y,COLS/2+16,"\u271D");
    }
    for (int x = 0; x < COLS; ++x) {
        mvprintw(0, x, "-");
        mvprintw(LINES - 1, x, "-");
    }
    for (int y = 1; y < LINES - 1; ++y) {
        mvprintw(y, 0, "|");
        mvprintw(y, COLS - 1, "|");
    }
    attroff(COLOR_PAIR(3));
    for (int i = 0; i < 3; ++i) {
        if (highlightmajoon== i + 1) {
            attron(COLOR_PAIR(93));
        }
        mvprintw(LINES / 2 + (i - 1) * 4, COLS / 2, "%s  %d", options_menumajoon[i],nmajoon[i]);
        attroff(COLOR_PAIR(93));
    }
    refresh();
}
int print_weaponmenu(){
   clear();
    attron(COLOR_PAIR(4));
    mvprintw(LINES-2,COLS/2-65,"Health:%d\tgolds:%d       score:%d     energy:%d      Floor:%d",playerhealth,golds,point,beinghungry,floorx);
    attroff(COLOR_PAIR(4));
    if(hasweaponer){
        attron(COLOR_PAIR(117));
        mvprintw(1, COLS/2-8,"You don,t have this weapon!");
        attroff(COLOR_PAIR(117));
        hasweaponer=0;
    }
   
    int cols = (COLS / 2) - 25;
     attron(COLOR_PAIR(1));
    mvprintw(4, cols, "                 UJFHLJJLLNHJJJBHJFDFQQQQOOLLN       BQ     ");
    mvprintw(5, cols, "     YYYYYYYYYYQJAAAAAFHJFDDHHHFAFHNHJLJHJJQHFHFDDBBBAAAAAAD ");
    mvprintw(6, cols, " DBBBBBBBBBBBBDDHFBBFFDDBBDDBBBAADFABO                        ");
    mvprintw(7, cols, " BDDBBBDDBAAAAQ    BDBBWS JLHJJJQ                             ");
    mvprintw(8, cols, " BBAAABU          SBBH      SFHHJY                            ");
    mvprintw(9, cols, "                  AAAY       LHHHJ                            ");
    attroff(COLOR_PAIR(1));
     attron(COLOR_PAIR(31)|A_BOLD);
    mvprintw(LINES/2-11, COLS/2-2,"Your Weapons");
    attroff(COLOR_PAIR(31)|A_BOLD);
    mvprintw(1, 2,"you are playing as:");
    attron(COLOR_PAIR(6));
    mvprintw(1,2+strlen(x),"'%s'",usernamedarbazi);
    attroff(COLOR_PAIR(6));
    attron(COLOR_PAIR(31));
    for(int y=LINES/2-9;y<=LINES/2+8;y++){
        mvaddstr(y,COLS/2-8,"\u2694");
        mvaddstr(y,COLS/2+16,"\u2694");
    }
    attroff(COLOR_PAIR(31));
    attron(COLOR_PAIR(32));
    for (int x = 0; x < COLS; ++x) {
        mvprintw(0, x, " ");
        mvprintw(LINES - 1, x, " ");
    }
    for (int y = 1; y < LINES - 1; ++y) {
        mvprintw(y, 0, " ");
        mvprintw(y, COLS - 1, " ");
    }
    attroff(COLOR_PAIR(3));
    for (int i = 0; i < 5; ++i) {
        if (highlightweapon== i + 1) {
            attron(COLOR_PAIR(31));
        }
        mvprintw(LINES / 2 + (i - 2) * 4, COLS / 2, "%s", options_menuweapon[i]);
        attroff(COLOR_PAIR(31));
        if(nwp[i]>0){
            if(i==0||i==4){
            attron(COLOR_PAIR(2));
            mvaddstr(LINES / 2 + (i - 2) * 4,COLS/2+11,"\u2795");
            attroff(COLOR_PAIR(2));
            }
            else{
                mvprintw(LINES/2+(i-2)*4,COLS/2+13,"%d",nwp[i]);
            }
        }
        if(weaponon==i+1){
            attron(COLOR_PAIR(2));
            mvaddstr(LINES / 2 + (i - 2) * 4,COLS/2-5,"✅");
            attroff(COLOR_PAIR(2));
        }
    }
    refresh();
}
int drawpausemenu(){
     clear();
     attron(COLOR_PAIR(4));
    mvprintw(LINES-2,COLS/2-65,"Health:%d ❣️     golds:%d 💰    score:%d  💯  energy:%d 🔋   Level %d  🛗  Distance:%d 🏃‍♂️",playerhealth,golds,point,beinghungry,floorx,distance);
    attroff(COLOR_PAIR(4));
    mvprintw(1, 2,"you are playing as:");
    attron(COLOR_PAIR(6));
    mvprintw(1,2+strlen(x),"'%s'",usernamedarbazi);
    attroff(COLOR_PAIR(6));
    attron(COLOR_PAIR(132));
    for(int y=LINES/2-13;y<=LINES/2+12;y++){
        mvprintw(y,COLS/2-8,"%%");
        mvprintw(y,COLS/2+16,"%%");
    }
    attron(COLOR_PAIR(110));
    for (int x = 0; x < COLS; ++x) {
        mvprintw(0, x, " ");
        mvprintw(LINES - 1, x, " ");
    }
    for (int y = 1; y < LINES - 1; ++y) {
        mvprintw(y, 0, " ");
        mvprintw(y, COLS - 1, " ");
    }
    attroff(COLOR_PAIR(110));
    for (int i = 0; i < 7; ++i) {
        if (highlightmenup== i + 1) {
            attron(COLOR_PAIR(132));
        }
        mvprintw(LINES / 2 + (i - 3) * 4, COLS / 2, "%s", options_menup[i]);
        attroff(COLOR_PAIR(132));
    }
    refresh();
}
int musicp(){
   highlightmusicp=1;
    print_menumusicp();
    if (!initializeSDL()) {
        printf("Failed to initialize SDL and SDL_Mixer!\n");
        return 1;
    }
    while (1) {
        int c4 = getch();
        switch (c4) {
            case KEY_UP:
                highlightmusicp--;
                if (highlightmusicp < 1) highlightmusicp= 4;
                break;
            case KEY_DOWN:
                highlightmusicp++;
                if (highlightmusicp > 4) highlightmusicp = 1;
                break;
            case 10:
                musicchoice = highlightmusicp;
                playMusic(musicchoice);
                break;
            case 'b':
            case 'B':
                clear();
                int returnm;
                choicemenup=0;
                highlightmusicp=1;
                highlightmenup=1;
                returnm=pausemenu();
                return returnm;
                break;
            default:
                break;
        }
        print_menumusicp();
    }
}
int majoon(){
    print_majoonmenu();
    while (1) {
        int c4 = getch();
        switch (c4) {
            case KEY_UP:
                highlightmajoon--;
                if (highlightmajoon < 1) highlightmajoon= 3;
                break;
            case KEY_DOWN:
                highlightmajoon++;
                if (highlightmajoon > 3) highlightmajoon = 1;
                break;
            case 10:
                majoonchoice=highlightmajoon;
                int x=checkmajoon();
                break;
            case 'b':
            case 'B':
                clear();
                int returnm;
                choicemenup=0;
                highlightmajoon=1;
                majoonchoice=0;
                highlightmenup=1;
                returnm=pausemenu();
                return returnm;
                break;
            default:
                break;
        }
        print_majoonmenu();
    }
}
int weapon(){
    print_weaponmenu();
    while (1) {
        int c4 = getch();
        switch (c4) {
            case KEY_UP:
                highlightweapon--;
                if (highlightweapon < 1) highlightweapon= 5;
                break;
            case KEY_DOWN:
                highlightweapon++;
                if (highlightweapon > 5) highlightweapon = 1;
                break;
            case 10:
                weaponchoice=highlightweapon;
                int x=checkweapon();
                break;
            case 'b':
            case 'B':
                clear();
                int returnm;
                choicemenup=0;
                highlightweapon=1;
                foodchoice=0;
                highlightmenup=1;
                returnm=pausemenu();
                return returnm;
                break;
            default:
                break;
        }
        print_weaponmenu();
    }

}
int foods(){
    print_foodmenu();
    while (1) {
        int c4 = getch();
        switch (c4) {
            case KEY_UP:
                highlightfood--;
                if (highlightfood < 1) highlightfood= 3;
                break;
            case KEY_DOWN:
                highlightfood++;
                if (highlightfood > 3) highlightfood = 1;
                break;
            case 10:
                foodchoice=highlightfood;
                int x=checkfood();
                break;
            case 'b':
            case 'B':
                clear();
                int returnm;
                choicemenup=0;
                highlightfood=1;
                foodchoice=0;
                highlightmenup=1;
                returnm=pausemenu();
                return returnm;
                break;
            default:
                break;
        }
        print_foodmenu();
    }
}
int pausemenu(){
    init_pair(31,31,COLOR_BLACK);
    choicemenup=0;
   drawpausemenu();
   while (1) {
        int c2 = getch();
        switch (c2) {
            case KEY_UP:
                highlightmenup--;
                if (highlightmenup < 1) highlightmenup = 7;
                break;
            case KEY_DOWN:
                highlightmenup++;
                if (highlightmenup > 7) highlightmenup = 1;
                break;
            case 10:
                choicemenup = highlightmenup;
                break;
            default:
                break;
        }
        drawpausemenu();
        refresh();
        if(choicemenup==1){
            return musicp();
        }
        else if(choicemenup==2){
            return foods();
        }
        else if(choicemenup==3){
           return majoon();
        }
        else if(choicemenup==4){
           return weapon();
        }
        else  if(choicemenup==5){
            choicemenup=0;
            highlightmenup=1;
            highlightmusicp=1;
                 return mainview();
        }
        else if(choicemenup==6){
            return scoreboard(2);
        }
        else if(choicemenup==7){
            if(hasacc){
                saveplayeritems();
            }
            exit(0);
        }
   }
}