#include "ncurses.h"
#include "difficulty.h"
#include "changecolor.h"
#include "music.h"

void printsetting() {
    char text[][100] = {
        "  _____   ______   _______   _______   _____   _   _    _____ ",
        " / ____| |  ____| |__   __| |__   __| |_   _| | \\ | |  / ____|",
        "| (___   | |__       | |       | |      | |   |  \\| | | |  __ ",
        " \\___ \\  |  __|      | |       | |      | |   | . ` | | | |_ |",
        " ____) | | |____     | |       | |     _| |_  | |\\  | | |__| |",
        "|_____/  |______|    |_|       |_|    |_____| |_| \\_|  \\_____"
    };


    int starty = 1;
    int startx = (COLS - strlen(text[0])) / 2;

    for (int i = 0; i < 6; i++) {
        mvprintw(starty + i, startx, "%s", text[i]);
    }

   
}


void startsetting(int* difficulty, int* color, int* music){
    initscr();
        while (1)
    {
        
         clear();
         curs_set(false);
         noecho();
         cbreak();
         keypad(stdscr, true);
    int boxheight = 20;
    int boxwidth = 70;
    int y_box = 5 + (LINES - boxheight) /2;
    int x_box = (COLS - boxwidth) /2;
    init_pair(2,COLOR_YELLOW, COLOR_BLACK);
    WINDOW *window = newwin(boxheight, boxwidth, y_box, x_box);
    char names[6][20] = {"Difficulty", "Change color", "Music", "Quit"};
    int choice =0;
    while(1){
        clear();
        box(window, 0, 0);
    wbkgd(window, COLOR_PAIR(2));
    attron(COLOR_PAIR(2));
    printsetting();
    attroff(COLOR_PAIR(2));
    refresh();
    wrefresh(window);
        for(int i =0; i<4; i++){
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
            choice =3;
        }
         if(key == KEY_DOWN){
            if(choice != 3){
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
        *difficulty = startdifficulty();
    }
     else if(choice == 1){
        *color = startchangecolor();
    }
    else if(choice ==2){
        *music = changemusic();
    }
    else if(choice == 3){
      break;
      
    }
    clear();

    }
    endwin();
}