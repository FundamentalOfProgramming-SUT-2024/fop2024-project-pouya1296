#include <ncurses.h>


void printtr(char username[]) {
    char art[][100] = {        
        "⠀⠀⠀⠀⢀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⠀⠀⠀⠀",
        "⢠⣤⣤⣤⣼⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣄⣤⣤⣠",
        "⢸⠀⡶⠶⠾⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡷⠶⠶⡆⡼",
        "⠈⡇⢷⠀⠀⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠇⠀⢸⢁⡗",
        "⠀⢹⡘⡆⠀⢹⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡸⠀⢀⡏⡼⠀",
        "⠀⠀⢳⡙⣆⠈⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠇⢀⠞⡼⠁⠀",
        "⠀⠀⠀⠙⣌⠳⣼⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣞⡴⣫⠞⠀⠀⠀",
        "⠀⠀⠀⠀⠈⠓⢮⣻⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡼⣩⠞⠉⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠉⠛⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠞⠋⠁⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⢤⣀⠀⠀⠀⠀⢀⣠⠖⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⡇⢸⡏⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠖⠒⠓⠚⠓⠒⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⣀⣠⣞⣉⣉⣉⣉⣉⣉⣉⣉⣉⣉⣙⣆⣀⡀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠓⠲⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠖⠃⠀⠀⠀⠀⠀⠀"
    };

    int starty = 0;
    int startx =  30 +(COLS - strlen(art[0])) / 2;

    for (int i = 0; i < 17; i++) {
        mvprintw(starty + i, startx, "%s", art[i]);
        if(i == 2){
            for(int j = 0; j<strlen(username); j++){
                mvprintw(2, startx+15 - strlen(username)/2+j, "%c", username[j]);
            }
            mvprintw(2, startx+13 - strlen(username)/2, "🏆");
        }

    }
}

int loadlusers(data users[]) {
    FILE *file = fopen("database.dat", "rb");
    int userCount = 0;
    while ((userCount < 100 )&& (fread(&users[userCount], sizeof(data), 1, file) == 1)) {
        userCount++;
    }
    fclose(file);
    return userCount;
}

void printsolright() {
    char text[][100] = {
"              {}",
"             {{}}",
"             {{}}",
"              {}",
"            .-''-.",
"           /  __  \\",
"          /.-'  '-.\\",
"          \\::.  .::/",
"           \\'    '/",
"      __ ___)    (___ __",
"    .'   \\\\        //   `.",
"   /     | '-.__.-' |     \\",
"   |     |  '::::'  |     |",
"   |    /    '::'    \\    |",
"   |_.-;\\     __     /;-._|",
"   \\.'^`\\\\    \\/    //`^'./",
"   /   _.-._ _||_ _.-._   \\",
"  `\\___\\    '-..-'    /___/`",
"       /'---.  `\\.---'\\",
"      ||    |`\\\\\\|    ||",
"      ||    | || |    ||",
"      |;.__.' || '.__.;|",
"      |       ||       |",
"      {{{{{{{{||}}}}}}}}",
"       |      ||      |",
"       |.-==-.||.-==-.|",
"       <.    .||.    .>",
"        \\'=='/||\\'=='/",
"        |   / || \\   |",
"        |   | || |   |",
"        |   | || |   |",
"        /^^\\| || |\\/^^\\",
"       /   .' || '.   \\",
"      /   /   ||   \\   \\",
"     (__.'    \\/    '.__)",

    };

    int len = sizeof(text) / sizeof(text[0]);
    int starty = (LINES - len) / 2;
    int startx = COLS - strlen(text[0]) - 12;

    for (int i = 0; i < len; i++) {
        mvprintw(starty + i, startx, "%s", text[i]);
    }
}

void printsolleft() {
    char text[][100] = {
"              {}",
"             {{}}",
"             {{}}",
"              {}",
"            .-''-.",
"           /  __  \\",
"          /.-'  '-.\\",
"          \\::.  .::/",
"           \\'    '/",
"      __ ___)    (___ __",
"    .'   \\\\        //   `.",
"   /     | '-.__.-' |     \\",
"   |     |  '::::'  |     |",
"   |    /    '::'    \\    |",
"   |_.-;\\     __     /;-._|",
"   \\.'^`\\\\    \\/    //`^'./",
"   /   _.-._ _||_ _.-._   \\",
"  `\\___\\    '-..-'    /___/`",
"       /'---.  `\\.---'\\",
"      ||    |`\\\\\\|    ||",
"      ||    | || |    ||",
"      |;.__.' || '.__.;|",
"      |       ||       |",
"      {{{{{{{{||}}}}}}}}",
"       |      ||      |",
"       |.-==-.||.-==-.|",
"       <.    .||.    .>",
"        \\'=='/||\\'=='/",
"        |   / || \\   |",
"        |   | || |   |",
"        |   | || |   |",
"        /^^\\| || |\\/^^\\",
"       /   .' || '.   \\",
"      /   /   ||   \\   \\",
"     (__.'    \\/    '.__)",

    };

    int len = sizeof(text) / sizeof(text[0]);
    int starty = (LINES - len) / 2;
    int startx = 1;

    for (int i = 0; i < len; i++) {
        mvprintw(starty + i, startx, "%s", text[i]);
    }
}

int ranksearch(data users[], int usercount, int rank){
    for(int i =0 ; i<usercount; i++){
        if(users[i].rank == rank){
            return i;
        }
    }
}

void startscore(char username[]){
    initscr();
    noecho();
    cbreak();
    init_pair(1, COLOR_CYAN,  COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_GREEN, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    data user[100];
int usercount =0;
usercount =loadlusers(user);
for(int i =0; i<usercount; i++){
    for(int j =i+1; j<usercount; j++ ){
        if(user[j].totalscore > user[i].totalscore){
            data temp = user[i];
            user[i] = user[j];
            user[j] = temp;
        }
    }
}
    int height = 20;
    int width =80;
    int starty = 10 +(LINES - height) /2;
    int satartx = (COLS - width)/2;
     clear();
    WINDOW *window = newwin(height, width, starty, satartx);
    keypad(window, TRUE);
    wbkgd(window, COLOR_PAIR(1));
     box(window, 0, 0);
     attron(COLOR_PAIR(3));
        printtr(user[0].username);
        printsolleft();
         printsolright();
        attroff(COLOR_PAIR(3));
    int key = 0;
    int start = 0;
    int max = height -2;
    refresh();
    while (key!= 27) {
        wclear(window);
        wbkgd(window, COLOR_PAIR(1));
            box(window, 0, 0);
        wattron(window, COLOR_PAIR(4));
         mvwprintw(window, 1, 1, "RANK      USERNAME           TOTALSCORE       GOLD      GAMES      EXPERIENCE");
         wattroff(window, COLOR_PAIR(4));
         wrefresh(window);
        refresh();

        for (int i = start ; (i < usercount)&&(i<start + 10) ; i++) {
            if(i ==0){
                mvwprintw(window,i-start +2, 1, "🏆");
            }
            if(i == 1){
               mvwprintw(window,i-start +2, 1, "🥈"); 
            }
            if(i==2){
                mvwprintw(window,i-start +2, 1, "🥉");
            }
            if(strcmp(username, user[i].username) == 0)
            wattron(window, A_REVERSE);
            
            
            if(i>=3)
            wattron(window, COLOR_PAIR(2));
            if(i == 0){
               wattron(window, COLOR_PAIR(6)); 
            mvwprintw(window, i -start + 2, 10, " LEGEND %s" , user[i].username);
            
            }
            else if(i == 1){
                wattron(window, COLOR_PAIR(5));
            mvwprintw(window, i -start + 2, 10, " MOSALAT %s" , user[i].username);
            }
            else if(i ==2){
                wattron(window, COLOR_PAIR(4));
            mvwprintw(window, i -start + 2, 10, " SAVAR %s" , user[i].username);}
            else{
            mvwprintw(window, i -start + 2, 1, "%d" , i+1);
            mvwprintw(window, i -start + 2, 11, "%s" , user[i].username);}
            mvwprintw(window, i -start + 2, 30, "%d" , user[i].totalscore);
            mvwprintw(window, i -start + 2, 47, "%d" , user[i].totalgold);
            mvwprintw(window, i -start + 2, 57, "%d" , user[i].numberofgames);
            mvwprintw(window, i -start + 2, 68, "%d" , user[i].experience);
            if(strcmp(username, user[i].username) == 0)
            wattroff(window, A_REVERSE);
            
            if(i>=3)
            wattroff(window, COLOR_PAIR(2));
            if(i == 0){
               wattroff(window, COLOR_PAIR(6)); 
            }
            else if(i == 1){
                wattroff(window, COLOR_PAIR(5));;
            }
            else if(i ==2)
                wattroff(window, COLOR_PAIR(4));
        }
        key = wgetch(window);
            if (key == KEY_UP){
                if (start > 0) 
                start--;}
            else if (key == KEY_DOWN){
                if ((start) < usercount) 
                start++;}
        
    }

    delwin(window);

     clear();
      endwin();
}