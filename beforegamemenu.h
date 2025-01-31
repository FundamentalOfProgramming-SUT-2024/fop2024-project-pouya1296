#include "ncurses.h"
#include "setting.h"
#include "game.h"
#include "profile.h"
#include "scoreboard.h"



void printwelcome() {
    char text[][100] = {        
        "__          ________ _      _____ ____  __  __ ______ ",
        "\\ \\        / /  ____| |    / ____/ __ \\|  \\/  |  ____|",
        " \\ \\  /\\  / /| |__  | |   | |   | |  | | \\  / | |__   ",
        "  \\ \\/  \\/ / |  __| | |   | |   | |  | | |\\/| |  __|  ",
        "   \\  /\\  /  | |____| |___| |___| |__| | |  | | |____ ",
        "    \\/  \\/   |______|______\\_____\\____/|_|  |_|______|"
    };

 

    int starty = 1;
    int startx = (COLS - strlen(text[0])) / 2;

    for (int i = 0; i < 6; i++) {
        mvprintw(starty + i, startx, "%s", text[i]);
    }


}

void startbeforegame(char username[100]){
    int color = 1;
    int music = 0;
    int difficulty =0;
 while (1)
    {
         initscr();

        start_color();
         clear();
         curs_set(false);
         noecho();
         cbreak();
    int boxheight = 20;
    int boxwidth = 70;
    int y_box =  5 +(LINES - boxheight) /2;
    int x_box = (COLS - boxwidth) /2;
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    WINDOW *window = newwin(boxheight, boxwidth, y_box, x_box);
    box(window, 0, 0);
    wbkgd(window, COLOR_PAIR(2));
    keypad(stdscr, true);
    refresh();
    wrefresh(window);
    char names[6][20] = {"New game", "Load game", "Scoreboard", "Setting new game", "profile", "Quit"};
    int choice =0;
    while(1){
        clear();
          curs_set(false);
         noecho();
     box(window, 0, 0);
    wbkgd(window, COLOR_PAIR(2));
    keypad(stdscr, true);
    attron(COLOR_PAIR(2));
    printwelcome();
    attroff(COLOR_PAIR(2));
    refresh();
    wrefresh(window);
        for(int i =0; i<6; i++){
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
            choice =5;
        }
         if(key == KEY_DOWN){
            if(choice != 5){
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
       startgame(difficulty, color, music, username, 0); 
       curs_set(false);
    }
     else if(choice == 1){
        endwin();
        startloadedgame(username);
        curs_set(false);
    }
    else if(choice == 2){
        endwin();
        startscore(username);
    }
    else if(choice == 3){
        endwin();
      startsetting(&difficulty, &color, &music);    }
    else if(choice == 4){
        endwin();
      startprofile(username);
    }
    else if(choice == 5){
        endwin();
      break;
    }
    clear();
    }}