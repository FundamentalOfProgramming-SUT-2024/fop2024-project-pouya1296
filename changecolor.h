    #include "ncurses.h"
    

void printcolor() {
    char text[][100] = {        
        "  _____ ____  _      ____  _____  ",
        " / ____/ __ \\| |    / __ \\|  __ \\ ",
        "| |   | |  | | |   | |  | | |__) |",
        "| |   | |  | | |   | |  | |  _  / ",
        "| |___| |__| | |___| |__| | | \\ \\ ",
        " \\_____\\____/|______\\____/|_|  \\_\\"
    };


    int starty = 1;
    int startx = (COLS - strlen(text[0])) / 2;

    for (int i = 0; i < 6; i++) {
        mvprintw(starty + i, startx, "%s", text[i]);
    }

 
}





    int startchangecolor(){
    while (1)
    {
        initscr();
        start_color();
         clear();
         curs_set(false);
         noecho();
         keypad(stdscr, true);
    int boxheight = 20;
    int boxwidth = 80;
    int y_box = 5+  (LINES - boxheight) /2;
    int x_box = (COLS - boxwidth) /2;
    init_pair(2,COLOR_MAGENTA, COLOR_BLACK);
    WINDOW *window = newwin(boxheight, boxwidth, y_box, x_box);
  
    char names[6][20] = {"RED", "BLUE", "GREEN"};
    int choice =0;
    while(1){
        clear();
   box(window, 0, 0);
    wbkgd(window, COLOR_PAIR(2));
    attron(COLOR_PAIR(2));
    printcolor();
    attroff(COLOR_PAIR(2));
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
       return 1;
    }
     else if(choice == 1){
        return 2;
    }
    else if(choice == 2){
        return 3;   
    }
    clear();
    }
    nocbreak();
    endwin();}