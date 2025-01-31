
#include <ncurses.h>
#include "register.h"
#include "login.h"
#include "beforegamemenu.h"
#include "game.h"
#include <unistd.h>


void printdragon() {
    char text[][100] = {

"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣿⣀⣀⣤⣴⡞⠀⠀⣀⣴⣿⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⠿⣿⣿⢿⣿⣷⣶⣿⣿⣿⡟⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡏⠀⠈⠁⠘⠿⠟⠛⢉⣽⣿⠃⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡘⠃⠀⠀⠀⠀⠀⠀⢰⣿⣿⣋⣀⡄⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⣦⠀⠀⠀⠀⠀⣀⣬⣿⣿⡿⠋⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣷⣄⠀⣀⣀⣻⣿⣏⣉⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣦⡙⢿⣿⣿⣿⣿⣿⡷⠈⠙⠛⠛⠋⠁⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣄⠙⢿⠿⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⠀⣠⣿⣿⣿⣿⣿⡿⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⠀⢀⣴⣿⣿⣿⠿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⠠⣿⣿⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⠀⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
    };

    int starty = (LINES - sizeof(text) / sizeof(text[0])) / 2;
    int startx = COLS -32;

    for (int i = 0; i < sizeof(text) / sizeof(text[0]); i++) {
        mvprintw(starty + i, startx, "%s", text[i]);
    }
}

void astaraki() {
    char text[][100] = {        
"              _____   _______              _____               _  __  _____ ",
"     /\\      / ____| |__   __|     /\\     |  __ \\      /\\     | |/ / |_   _|",
"    /  \\    | (___      | |       /  \\    | |__) |    /  \\    | ' /    | |  ",
"   / /\\ \\    \\___ \\     | |      / /\\ \\   |  _  /    / /\\ \\   |  <     | |  ",
"  / ____ \\   ____) |    | |     / ____ \\  | | \\ \\   / ____ \\  | . \\   _| |_ ",
" /_/    \\_\\ |_____/     |_|    /_/    \\_\\ |_|  \\_\\ /_/    \\_\\ |_|\\_\\ |_____|"
                                                                                                                                                  
    };


    int starty = 8;
    int startx = (COLS - strlen(text[0])) / 2;

    for (int i = 0; i < 6; i++) {
        mvprintw(starty + i, startx, "%s", text[i]);
    }

}

void printrogue() {
    char banner[][100] = {        
        "  _____   ____   _____ _    _ ______ ",
        " |  __ \\ / __ \\ / ____| |  | |  ____|",
        " | |__) | |  | | |  __| |  | | |__   ",
        " |  _  /| |  | | | |_ | |  | |  __|  ",
        " | | \\ \\| |__| | |__| | |__| | |____ ",
        " |_|  \\_\\\\____/ \\_____|\\____/|______|"
    };

    int starty = 1;
    int startx = (COLS - strlen(banner[0])) / 2;

    for (int i = 0; i < 6; i++) {
        mvprintw(starty + i, startx, "%s", banner[i]);
    }

}

void printtropy() {
    char shape[][100] = {        
        "    ___________",
        "   '._==_==_=_.",
        "   .-\\:      /-.",
        "  | (|:.     |) |",
        "   '-|:.     |-'",
        "     \\::.    /",
        "      '::. .'",
        "        ) (",
        "      _.' '._",
        "     `\"\"\"\"\"\"\"`"
    };

    int starty = 15;
    int startx = 4;

    for (int i = 0; i < 10; i++) {
        mvprintw(starty + i, startx, "%s", shape[i]);
    }

}



void startmenu(){
    initscr();
    while (1)
    {
        start_color();
         clear();
         curs_set(false);
         noecho();
         cbreak();
    int boxheight = 20;
    int boxwidth = 70;
    int y_box = 7 + (LINES - boxheight) /2;
    int x_box = (COLS - boxwidth) /2;
    //init_pair(1,COLOR_RED, COLOR_BLACK);
    init_pair(2,COLOR_RED, COLOR_BLACK);
    WINDOW *window = newwin(boxheight, boxwidth, y_box, x_box);
    box(window, 0, 0);
    wbkgd(window, COLOR_PAIR(2));
    keypad(stdscr, true);
    refresh();
    wrefresh(window);
    char names[6][20] = {"New user", "Login", "Quit"};
    int choice =0;
    while(1){
        clear();
        curs_set(false);
         noecho();
             attron(COLOR_PAIR(2));
    printtropy();
    printrogue();
    astaraki();
    printdragon();
    attroff(COLOR_PAIR(2));
    int boxheight = 20;
    int boxwidth = 70;
    int y_box =  5 +(LINES - boxheight) /2;
    int x_box = (COLS - boxwidth) /2;

    WINDOW *window = newwin(boxheight, boxwidth, y_box, x_box);
    box(window, 0, 0);
    wbkgd(window, COLOR_PAIR(2));
    keypad(stdscr, true);
    refresh();
    wrefresh(window);
        for(int i =0; i<3; i++){
            if(i == choice){
                wattron(window, A_REVERSE);
            }
            mvwprintw(window, 1 + i, 3,"%s", names[i]);
            if(i == choice){
                wattroff(window, A_REVERSE);
            }
            
        }
        wrefresh(window);

        int key = getch();
        if(key == KEY_UP){
            if(choice != 0){
                choice --;
            }
            else
            choice =2;
        }
         if(key == KEY_DOWN){
            if(choice != 2){
                choice ++;
            }
            else
            choice =0;
        }
        else if(key == 10){
            break;
        }

    }
    delwin(window);
    if(choice == 0){
         endwin();
        registerUser();
        
    }
     else if(choice == 1){
        char username[100] ={0};
      if(startlogin(username)){
         endwin();
        startbeforegame(username);
        clear(); 
      }
      else{
        endwin();
        startgame(1, 1, 2, username, 1);
        clear();
      }
    }
    else if(choice == 2){
         endwin();
      break;
    }

      clear();

    }


}


