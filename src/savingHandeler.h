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
int newplayer(){
    char filename[60];
    sprintf(filename, "USERS/%sinf.txt",usernamedarbaazic);
    FILE *file;
    file=fopen(filename,"w");
    fprintf(file,"%d\n%d\n%d\n%d\n%d\n",0,0,0,0,100);
    fclose(file);
}
int saveplayeritems(){
       refresh();
       char filename[60];
       char usernamx[50];
       strcpy(usernamx,usernamedarbaazic);
       sprintf(filename, "USERS/%sinf.txt",usernamx);
       FILE *file;
       FILE *file2;
       file=fopen((filename),"r");
        int val1, val2, val3,val4,val5;
    if (fscanf(file, "%d", &val1) != 1 ||
        fscanf(file, "%d", &val2) != 1 ||
        fscanf(file, "%d", &val3) != 1||
        fscanf(file, "%d", &val4) != 1||
        fscanf(file, "%d", &val5) != 1) {
        perror("خطا در خواندن داده‌های فایل");
        getch();
        fclose(file);
        return 0;
    }
    fclose(file);
    val1 += golds; 
    val2 += 2*golds; 
    val3++;     
    if(gamewin){
        val4++;
    }
    val5=playerhealth; 
    file2=fopen((filename),"w");
    fprintf(file2, "%d\n%d\n%d\n%d\n%d\n", val1, val2, val3,val4,val5);
    fclose(file2);
    exit(0);
}
int compare(const void *a, const void *b) {
    return ((Player *)b)->golds - ((Player *)a)->golds;
}
int sortlist(){
    for (int i = 0; i < nusers; i++) {       
        strcpy(players[i].username, usernamesx[i]);
        char filename[50];
        sprintf(filename, "USERS/%sinf.txt", usernamesx[i]);
        FILE *file = fopen(filename, "r");
        if (file) {
            fscanf(file, "%d", &players[i].golds);
            fscanf(file,"%d",&players[i].points);
            fscanf(file,"%d %d %d",&players[i].nplayed,&players[i].nfinished,&players[i].health);
            if(strcmp(players[i].username,usernamedarbazi)==0){
               playerhealth=players[i].health;
            }
            fclose(file);
        }
    }
    qsort(players, nusers, sizeof(Player), compare);
      
}
int listusernames(){
    FILE *file;
    file = fopen("USERS/usernamelist.txt", "r");
    usernamesx = (char **)malloc(70 * sizeof(char *));
    char buffer[70];
    int count = 0;
    while (fgets(buffer, 70, file) && count < 70) {
        buffer[strcspn(buffer, "\n")] = 0;
        usernamesx[count] = (char *)malloc(strlen(buffer) + 1);
        strcpy(usernamesx[count], buffer);
        count++;
    }
    nusers=count;
    fclose(file);
    sortlist();
}
int estekhraaj(){
    char filename[60];
    sprintf(filename, "USERS/%s.txt",usernamedarbaazic);
    FILE *file;
    file=fopen((filename),"r");
    char buffer[70];
    int count = 0;
    char matn[70];
       int lines=0;
        while(fgets(playerpassw, sizeof(playerpassw), file)){
            playerpassw[strcspn(playerpassw, "\n")] = 0;
            if(lines==2){
                break;
            }
            lines++;
        }
        fclose(file);
        file=fopen((filename),"r");
        int lines2=0;
        while(fgets(playeremail, sizeof(playeremail), file)){
            playeremail[strcspn(playeremail, "\n")] = 0;
            if(lines2==1){
                break;
            }
            lines2++;
        }
        fclose(file);
        file=fopen((filename),"r");
        int lines3=0;
        while(fgets(playerphone, sizeof(playerphone), file)){
            playerphone[strcspn(playerphone, "\n")] = 0;
            if(lines3==3){
                break;
            }
            lines3++;
        }
        fclose(file);
}
int updatescoreboard(){
    saveplayeritems();
    listusernames();
    sortlist();
}
int daryaftet(){
    char filename[60];
    sprintf(filename, "USERS/%sinf.txt",usernamedarbaazic);
    FILE *file;
    file=fopen(filename,"r");
    int x;
    int x2;
    if (fscanf(file, "%d", &golds) != 1 ||
        fscanf(file, "%d", &point) != 1 ||
        fscanf(file, "%d", &x) != 1||
        fscanf(file, "%d", &x2) != 1||
        fscanf(file, "%d", &playerhealth) != 1) {
        perror("خطا در خواندن داده‌های فایل");
        getch();
        fclose(file);
        return 0;
    }
    fclose(file);
}