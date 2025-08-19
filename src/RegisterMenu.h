#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include<time.h>
#include<unistd.h>
#include<curses.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdbool.h>
#ifndef RegisterMenu.h
#define  RegisterMenu.h
extern char usernamedarbazi[]="";
extern char usernamedarbaazic[]="";
extern char usernamedarbaazi1[]="";
extern int hasacc=1;
extern char **usernamesx=0;
extern int resume=0;
extern int nusers=0;
extern char playeremail[600]="";
extern char playerpassw[700]="";
extern char playerphone[600]="";
#endif  
const char *options_menu1[] = { "Sign Up", "Sign In", "Guest" };
const char *options_menu2[] = { "Username:", "Email Address:", "Password:", "Phone Number:", "Sign Up!" };
const char *options_menu3[] = { "Username:", "Password:","Sign in!", "I forgot my password!"};
 int highlight = 1;
int choice = 0;
int highlight2 = 1;
int choice2 = 0;
int highlight3=1;
int choice3=0;
int randpass=0;
int check_pass = 0;
int check_em = 0;
int check_ph = 0;
int check_us = 0;
int check_passv=0;
int check_phv=0;
int check_usv=0;
char passwords[300]= "";
char password[300] = "";
char username[300] = "";
char usernames[300]="";
char phone[300] = "";
char phones[300]="";
char email[300] = "";
FILE *file;
void draw_menu_border1() {
    clear();
    attron(COLOR_PAIR(117));
    mvprintw(8,COLS/2-29,"____  _____ ____ ___ ____ _____ _____ ____       __  __ _____ _   _ _   _ ");
    mvprintw(9,COLS/2-29,"|  _ \\| ____/ ___|_ _/ ___|_   _| ____|  _ \\     |  \\/  | ____| \\ | | | | |");
    mvprintw(10,COLS/2-29,"| |_) |  _|| |  _ | |\\___ \\ | | |  _| | |_) |    | |\\/| |  _| |  \\| | | | |");
    mvprintw(11,COLS/2-29,"|  _ <| |__| |_| || | ___) || | | |___|  _ <     | |  | | |___| |\\  | |_| |");
    mvprintw(12,COLS/2-29,"|_| \\_\\_____|____|___|____/ |_| |_____|_| \\_\\    |_|  |_|_____|_| \\_|\\___/");
    for (int x = 0; x < COLS; ++x) {
        mvprintw(0, x, "@");
        mvprintw(LINES - 1, x, "@");
    }
    for (int y = 1; y < LINES - 1; ++y) {
        mvprintw(y, 0, "@");
        mvprintw(y, COLS - 1, "@");
    }
    attroff(COLOR_PAIR(117));
}
void draw_menu_border2() {
    clear();
    attron(COLOR_PAIR(2));
    for (int x = 0; x < COLS; ++x) {
        mvprintw(0, x, "&");
        mvprintw(LINES - 1, x, "&");
    }
    for (int y = 1; y < LINES - 1; ++y) {
        mvprintw(y, 0, "&");
        mvprintw(y, COLS - 1, "&");
    }
    attroff(COLOR_PAIR(2));
}
void draw_menu_border3(){
    clear();
    attron(COLOR_PAIR(5));
    for (int x = 0; x < COLS; ++x) {
        mvprintw(0, x, "%%");
        mvprintw(LINES - 1, x, "%%");
    }
    for (int y = 1; y < LINES - 1; ++y) {
        mvprintw(y, 0, "%%");
        mvprintw(y, COLS - 1, "%%");
    }
    attroff(COLOR_PAIR(5));
}
void print_menu1(int highlight) {
    draw_menu_border1();
    for (int i = 0; i < 3; ++i) {
        if (highlight == i + 1) {
            attron(COLOR_PAIR(15));
        }
        mvprintw(LINES / 2 + (i - 1) * 2, COLS / 2, "%s", options_menu1[i]);
        attroff(A_REVERSE|COLOR_PAIR(15));
    }
    refresh();
}
void print_menu2() {
    refresh();
    draw_menu_border2();
    attron(COLOR_PAIR(5));
    if (check_us == 1) {
        mvprintw(LINES / 2 - 4, COLS / 2 - 10 + strlen(options_menu2[0]), "%s", username);
    }
    if (check_em == 1) {
        mvprintw(LINES / 2 - 2, COLS / 2 - 10 + strlen(options_menu2[1]), "%s", email);
    }
    if (check_pass == 1) {
        mvprintw(LINES / 2, COLS / 2 - 10 + strlen(options_menu2[2]), "%s", password);
    }
    if (check_ph == 1) {
        mvprintw(LINES / 2 + 2, COLS / 2 - 10 + strlen(options_menu2[3]), "%s", phone);
    }
    attroff(COLOR_PAIR(5));
    attron(COLOR_PAIR(2));
    mvprintw(7, COLS/2-22, "____ ___ ____ _   _   _   _ ____  ");
    mvprintw(8, COLS/2-22, "/ ___|_ _/ ___| \\ | | | | | |  _ \\ ");
    mvprintw(9, COLS/2-22, "\\___ \\| | |  _|  \\| | | | | | |_) |");
    mvprintw(10, COLS/2-22, " ___) | | |_| | |\\  | | |_| |  __/ ");
    mvprintw(11, COLS/2-22, "|____/___\\____|_| \\_|  \\___/|_|    ");
    
    attron(COLOR_PAIR(3));
    mvprintw(LINES - 2, COLS / 2 - 30, "*We need your phone number for password recovery later*");
    attroff(COLOR_PAIR(3));

    for (int i = -2; i < 3; i++) {
        if (highlight2 == i + 3) {
            attron(COLOR_PAIR(2));
            if (highlight2 == 5) {
                attron(COLOR_PAIR(1));
            }
        }
        mvprintw(LINES / 2 + 2 * i, COLS / 2 - 10, "%s", options_menu2[i + 2]);
        attroff(COLOR_PAIR(1));
        attroff(COLOR_PAIR(2));
    }
    refresh();
}
void print_menu3(){
    refresh();
    draw_menu_border3();
    attron(COLOR_PAIR(5));
    if(check_usv==1){
       mvprintw(LINES / 2-4, COLS / 2 - 10 + strlen(options_menu3[0]), "%s", usernames);
    }
    if(check_passv==1){
      mvprintw(LINES / 2 + -2, COLS / 2 - 10+strlen(options_menu3[1]),"%s",passwords);
    }
    attroff(COLOR_PAIR(5));
    attron(COLOR_PAIR(5));
    mvprintw(8, COLS/2 - 20, "____    ___    ____   _   _        ___   _   _ ");
    mvprintw(9, COLS/2 - 20, "/ ___|  |_ _|  / ___| | \\ | |      |_ _| | \\ | |");
    mvprintw(10, COLS/2-20, "\\___ \\   | |  | |  _  |  \\| |       | |  |  \\| |");
    mvprintw(11, COLS/2-20, " ___) |  | |  | |_| | | |\\  |       | |  | |\\  |");
    mvprintw(12, COLS/2-20, "|____/  |___|  \\____| |_| \\_|      |___| |_| \\_|");
    attroff(COLOR_PAIR(5));
    for (int i = -2; i < 2; i++) {
        if (highlight3== i + 3) {
            attron(COLOR_PAIR(5));
            if (highlight3 == 3) {
                attron(COLOR_PAIR(2));
            }
            else if(highlight3==4){
                attron(COLOR_PAIR(4));
            }
        }
        mvprintw(LINES / 2 + 2 * i, COLS / 2 - 10, "%s", options_menu3[i + 2]);
        attroff(COLOR_PAIR(5));
        attroff(COLOR_PAIR(2));
        attroff(COLOR_PAIR(4));
    }
    refresh();
}

int check_username() {
    curs_set(TRUE);
    echo();
    char usernamedarfile[200];
    int found = 0;
    
    mvscanw(LINES / 2 - 4, COLS / 2 - 10 + strlen(options_menu2[0]), "%s", username);
    curs_set(false);
    noecho();
    file = fopen("USERS/usernamelist.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 0;
    }

    while (fgets(usernamedarfile, sizeof(usernamedarfile), file)) {
        usernamedarfile[strcspn(usernamedarfile, "\n")] = 0;
        if (strcmp(usernamedarfile, username) == 0) {
            found = 1;
            break;
        }
    }
    fclose(file);

    if (!found) {
        if (file == NULL) {
            perror("Error opening file");
            return 0;
        }
        attron(COLOR_PAIR(2));
        mvprintw(LINES - 6, COLS / 2 - 30,"%s is valid and it can be yours^..^",username);
        attroff(COLOR_PAIR(2));
        noecho();
        curs_set(false);
        return 1;
    } else {
        attron(COLOR_PAIR(6));
        mvprintw(LINES - 6, COLS / 2 - 30, "Username '%s'is  already taken!. Choose another one.", username);
        attroff(COLOR_PAIR(6));
        choice2=0;
        return 0;
    }
}
int check_email() {
    curs_set(TRUE);
    echo();
    mvscanw(LINES / 2-2, COLS / 2 - 10 + strlen(options_menu2[1]), "%s", email);
    curs_set(false);
    noecho();
    int n12=0;
    int n01=0;
    int n23=0;
    int nad=0;
    int ndot=0;
    int wrong=0;
    for(int i=0;i<strlen(email);i++){
        if(nad==0&&ndot==0&&email[i]!='@'&&email[i]!='.'){
            n01++;
        }
        else if(email[i]=='@'){
            if(nad>=1||(nad==0&&ndot>=1)||(n01==0)){
               wrong++;
            }
            else{
               nad++; 
            }
        }
        else if(email[i]=='.'){
            if(nad==0||n12==0||n01==0||ndot>=1){
                wrong++;
            }
            else{
                ndot++;
            }
        }
        else if(nad==1&&ndot==0){
            n12++;
        }
        else if(nad==1&&ndot==1){
            n23++;
        }
    }
    if(n23==0){
        wrong++;
    }
    if(wrong==0){
       attron(COLOR_PAIR(2));
        mvprintw(LINES - 6, COLS / 2 - 30, "email addres is valid and you can use it.");
        attroff(COLOR_PAIR(2));
        return 1;
    }
    else{
        attron(COLOR_PAIR(6));
        mvprintw(LINES - 6, COLS / 2 - 30, "email addres is invalid!please enter a correct email address.");
        attroff(COLOR_PAIR(6));
        choice2=0;
        return 0;
    }
}

int is_valid_password() {  
     int has2_digit = 0, has2_lower = 0, has2_upper = 0;  

    for (int i = 0; i < strlen(password); i++) {  
        if (password[i] >= '0' && password[i] <= '9') has2_digit = 1;  
        if (password[i] >= 'a' && password[i] <= 'z') has2_lower = 1;  
        if (password[i] >= 'A' && password[i] <= 'Z') has2_upper = 1;  
    }  
    if(has2_digit+has2_lower+has2_upper==3){
      return 1 ; 
    }
    else{
        return 0;
    }
}  
int  generate_password() {  
    const char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; 
    srand(time(0));    
    for (int i = 0; i <9; i++) {  
        password[i] = characters[rand() % (sizeof(characters) - 1)];  
    }  
    password[9] = '\0';  
    if(is_valid_password()){
        return 1;
    }
    else{
        generate_password();
    }
}  

int check_password() {
    curs_set(TRUE);
    echo();
    if(randpass==0){
    mvscanw(LINES / 2, COLS / 2 - 10 + strlen(options_menu2[2]), "%s", password);
    curs_set(false);
    noecho();
    if (strlen(password) < 7) {
        attron(COLOR_PAIR(6));
        mvprintw(LINES - 6, COLS / 2 - 30, "Password must be at least 7 characters long!");
        attroff(COLOR_PAIR(6));
        choice2=0;
        return 0;
    }

    int has_upper = 0, has_lower = 0, has_digit = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) has_upper = 1;
        if (islower(password[i])) has_lower = 1;
        if (isdigit(password[i])) has_digit = 1;
    }

    if (has_upper && has_lower && has_digit) {
        attron(COLOR_PAIR(2));
        mvprintw(LINES - 6, COLS / 2 - 30, "Nice! Your password is strong enough :)");
        attroff(COLOR_PAIR(2));
        return 1;
    } else {
        attron(COLOR_PAIR(6));
        mvprintw(LINES - 8, COLS / 2 - 30, "Password must contain at least one uppercase letter, one lowercase letter, and one digit.");
        attroff(COLOR_PAIR(6));
        choice2=0;
        return 0;
    }
    }
    else{
        generate_password();  
        attron(COLOR_PAIR(2));
        mvprintw(LINES - 8, COLS / 2 - 30, "Nice! Your password is strong enough :)");
        attroff(COLOR_PAIR(2));
        curs_set(false);
        noecho();
        return 1;
    }
}

int check_phone() {
    curs_set(TRUE);
    echo();
    mvscanw(LINES / 2+2, COLS / 2 - 10 + strlen(options_menu2[3]), "%s", phone);
    curs_set(false);
    noecho();
    int ndigit=0;
    for(int i=0;i<strlen(phone);i++){
         if(phone[i]>='0'&&phone[i]<='9'){
            ndigit++;
         }
    }
    if(strlen(phone)==11&&ndigit==11&&phone[0]=='0'){
        attron(COLOR_PAIR(2));
        mvprintw(LINES - 6, COLS / 2 - 30, "such a good phone number:)");
        attroff(COLOR_PAIR(2));
    return 1;
    }
    else{
        attron(COLOR_PAIR(6));
       mvprintw(LINES - 6, COLS / 2 - 30, "invalid number ;please enter correct phone number!!");
       attroff(COLOR_PAIR(6));
       choice2=0;
       return 0;
    }
}

int sign_up() {
    highlight2 = 1;
    print_menu2();
    while (1) {
        int c2 = getch();
        switch (c2) {
            case KEY_UP:
                highlight2--;
                if (highlight2 < 1) highlight2 = 5;
                break;
            case KEY_DOWN:
                highlight2++;
                if (highlight2 > 5) highlight2 = 1;
                break;
            case 'b':
            case 'B':
                check_em=0;
                check_ph=0;
                check_us=0;
                check_pass=0;
                choice=0;
                choice2=0;
                highlight=1;
                clear();
                int returnx;
                returnx=menu_vorud();
                return returnx;
            case 'r':
            case 'R':
                highlight2=3;
                randpass=1;
                choice2=highlight2;
            break;
            case 'q':
            case 'Q':
                return 0;
            case 10:
                choice2 = highlight2;
                break;
            default:
                break;
        }
        print_menu2();
        if (choice2 == 1&&check_us==0) {
            check_us = check_username();
        } else if (choice2 == 2&&check_em==0) {
            check_em = check_email();
        } else if (choice2 == 3&&check_pass==0) {
            check_pass = check_password();
        } else if (choice2 == 4&&check_ph==0) {
            check_ph = check_phone();
        } else if (choice2 == 5) {
            if (check_us+check_em+check_pass+check_ph==4) {
                file = fopen("USERS/usernamelist.txt", "a");
                fprintf(file, "%s\n", username);
                fclose(file);
                char userInfoFileName[100];
                sprintf(userInfoFileName, "USERS/%s.txt",username);
                 FILE *UserInfo = fopen(userInfoFileName, "a");
                 mvprintw(LINES - 6, COLS / 2 - 30,"%s",UserInfo);
                 if (UserInfo == NULL) {
                    perror("Error opening file");
                }
                else{
                fprintf(UserInfo,"%s\n%s\n%s\n%s\n", username, email, password,phone);
                fclose(UserInfo);
                attron(COLOR_PAIR(2));
                listusernames();
                strcpy(usernamedarbazi,username);
                strcpy(usernamedarbaazi1,username);
                strcpy(usernamedarbaazic,username);
                newplayer();
                mvprintw(LINES - 6, COLS / 2 - 30, "wellcome to game!\npress enter button to countinue.");
                attroff(COLOR_PAIR(2));
                refresh();
                return 1;
                }
            } else {
                attron(COLOR_PAIR(6));
                mvprintw(LINES - 6, COLS / 2 - 30, "Please complete all fields before signing up.");
                attroff(COLOR_PAIR(6));
            }
        }
    }
}
int  check_phsabt(){
    char hoshdar[]="For recovering your password please enter your phone:";
    attron(COLOR_PAIR(2));
     mvprintw(LINES / 2 +4, COLS / 2 - 30,"For recovering your password please enter your phone:");
     attroff(COLOR_PAIR(2));
     char phonedarfile[3000];
    int found=0;
    curs_set(TRUE);
    echo();
     mvscanw(LINES / 2 +4, COLS / 2 - 30+strlen(hoshdar),"%s",phones);
    curs_set(false);
    noecho();
    char userInfoFileName[100];
    sprintf(userInfoFileName, "USERS/%s.txt",usernames);
    file = fopen(userInfoFileName, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 0;
    }
    else{
        int lines=0;
        while(fgets(phonedarfile, sizeof(phonedarfile), file)){
            phonedarfile[strcspn(phonedarfile, "\n")] = 0;
            if(lines==3){
                break;
            }
            lines++;
        }
        if(strcmp(phonedarfile,phones)==0){
            fclose(file);
            file = fopen(userInfoFileName, "r");
           if (file == NULL) {
             perror("Error opening file");
             return 0;
            }
            char showpassword[300];
            int line=0;
            while(fgets(showpassword,sizeof(showpassword),file)){
                showpassword[strcspn(showpassword,"\n")]=0;
                if(line==2){
                break;
                }
                line++;
            }
            attron(COLOR_PAIR(5));
            mvprintw(LINES - 8, COLS / 2 - 30,"your password is ' %s ' .be careful in protecting it!!",showpassword);
            attroff(COLOR_PAIR(5));
            return 1;
        }
        else{
            attron(COLOR_PAIR(6));
           mvprintw(LINES - 10, COLS / 2 - 30, "phone number is not correct , try again!");
            attroff(COLOR_PAIR(6));
            fclose(file);
            return 0;
        }
    }
}
int check_passsabt(){
    char passdarfile[3000];
    int found=0;
    curs_set(TRUE);
    echo();
    mvscanw(LINES / 2 + -2, COLS / 2 - 10+strlen(options_menu3[1]),"%s",passwords);
    curs_set(false);
    noecho();
    char userInfoFileName[100];
    sprintf(userInfoFileName, "USERS/%s.txt",usernames);
    file = fopen(userInfoFileName, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 0;
    }
    else{
        int lines=0;
        while(fgets(passdarfile, sizeof(passdarfile), file)){
            passdarfile[strcspn(passdarfile, "\n")] = 0;
            if(lines==2){
                break;
            }
            lines++;
        }
         fclose(file);
    
        if(strcmp(passdarfile,passwords)==0){
            return 1;
        }
        else{
            attron(COLOR_PAIR(6));
           mvprintw(LINES - 10, COLS / 2 - 30, "password is not correct , try again!");
            attroff(COLOR_PAIR(6));
            choice3=0;
            return 0;
        }
    }
}
int check_ussabt(){
    char usernamedarfile[30000];
    int found=0;
    curs_set(TRUE);
    echo();
    mvscanw(LINES / 2-4, COLS / 2 - 10 + strlen(options_menu3[0]), "%s", usernames);
    curs_set(false);
    noecho();
    file = fopen("USERS/usernamelist.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 0;
    }

    while (fgets(usernamedarfile, sizeof(usernamedarfile), file)) {
        usernamedarfile[strcspn(usernamedarfile, "\n")] = 0;
        if (strcmp(usernamedarfile, usernames) == 0) {
            found = 1;
            break;
        }
    }
    fclose(file);
    if(found==0){
        attron(COLOR_PAIR(6));
        mvprintw(LINES - 10, COLS / 2 - 30, "Username '%s'does not exist, sign up!", usernames);
        choice3=0;
        attroff(COLOR_PAIR(6));
        return 0;
    }
    else{
        attron(COLOR_PAIR(2));
        mvprintw(LINES - 10, COLS / 2 - 30, "'%s'is valid ,fill password to login!", usernames);
        attroff(COLOR_PAIR(2));
        return 1;
    }
}
int signin(){
   highlight3 = 1;
    print_menu3();
    while (1) {
        int c3 = getch();
        switch (c3) {
            case KEY_UP:
                highlight3--;
                if (highlight3 < 1) highlight3 = 4;
                break;
            case KEY_DOWN:
                highlight3++;
                if (highlight3 > 4) highlight3 = 1;
                break;
            case 'b':
            case 'B':
                check_phv=0;
                check_usv=0;
                check_passv=0;
                highlight=1;
                choice=0;
                choice3=0;
                clear();
                int returnx;
                returnx=menu_vorud();
                return returnx;
            case 'q':
            case 'Q':
                return 0;
            case 10:
                choice3 = highlight3;
                break;
            default:
                break;
        }
        print_menu3();
        if(choice3==1&&check_usv==0){
            check_usv=check_ussabt();
        }
        else if(choice3==2&&check_passv==0){
            if(check_usv==1){
            check_passv=check_passsabt();
            }
            else{
                attron(COLOR_PAIR(6));
                 mvprintw(LINES - 6, COLS / 2 - 30,"before filling in the password ,please complete the username section!!");
                attroff(COLOR_PAIR(6));
            }
        }
        else if(choice3==3){
            if(check_passv+check_usv==2){
                listusernames();
                strcpy(usernamedarbazi,usernames);
                strcpy(usernamedarbaazi1,usernames);
                 strcpy(usernamedarbaazic,usernames);
                attron(COLOR_PAIR(2));
                mvprintw(LINES - 6, COLS / 2 - 30, "wellcome to game!\npress enter button to continue.");
                attroff(COLOR_PAIR(2));
                refresh();
                
                refresh();
                return 1;
            
            }
            else{
                attron(COLOR_PAIR(6));
                mvprintw(LINES - 6, COLS / 2 - 30, "Please fill in  all the fields correctly before signing in.");
                attroff(COLOR_PAIR(6));
            }
        }
        else if(choice3==4&&check_phv==0){
            if(check_usv==1){
            check_phv=check_phsabt();
            }
            else{
                attron(COLOR_PAIR(6));
                mvprintw(LINES - 6, COLS / 2 - 30,"before asking for recovering your password ,please complete the username section!!");
                attroff(COLOR_PAIR(6));  
            }
        }
    }
}
int menu_vorud() {
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
   init_pair(15,COLOR_BLACK,117);
    print_menu1(1);
   

    while (1) {
        int c = getch();
        switch (c) {
            case KEY_UP:
                highlight--;
                if (highlight < 1) highlight = 3;
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight > 3) highlight = 1;
                break;
            case 10:
                choice = highlight;
                break;
            case 'q':
            case 'Q':
                return 0;
            default:
                break;
        }

        print_menu1(highlight);
        if (choice != 0) break;
    }
    clear();
    if (choice == 1) {
        draw_menu_border2();
       return  sign_up();
    } else if (choice == 2) {
        draw_menu_border3();
        return signin();
    } else if (choice == 3) {
        hasacc=0;
        listusernames();
        strcpy(usernamedarbazi,"guestplayer");
        strcpy(usernamedarbaazi1,"guestplayer");
        strcpy(usernamedarbaazic,"guestplayer");
        return 1;
    }
    return 1;
}
