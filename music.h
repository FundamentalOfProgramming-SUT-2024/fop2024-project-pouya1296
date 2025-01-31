    #include "ncurses.h"
    #include <stdlib.h>
    #include <time.h>


    void printmusic() {
    char text[][100] = {        
        " __  __   _    _    _____   _____    _____ ",
        "|  \\/  | | |  | |  / ____| |_   _|  / ____|",
        "| \\  / | | |  | | | (___     | |   | |     ",
        "| |\\/| | | |  | |  \\___ \\    | |   | |     ",
        "| |  | | | |__| |  ____) |  _| |_  | |____ ",
        "|_|  |_|  \\____/  |_____/  |_____|  \\_____"
    };

    int starty = 1;
    int startx = (COLS - strlen(text[0])) / 2;

    for (int i = 0; i < 6; i++) {
        mvprintw(starty + i, startx, "%s", text[i]);
    }

}

    int changemusic(){
    while (1)
    {
        initscr();
        start_color();
         clear();
         curs_set(false);
         noecho();
         cbreak();
         keypad(stdscr, true);
    int boxheight = 20;
    int boxwidth = 70;
    int y_box = 5 +(LINES - boxheight) /2;
    int x_box = (COLS - boxwidth) /2;
    init_pair(2,COLOR_RED, COLOR_BLACK);
    WINDOW *window = newwin(boxheight, boxwidth, y_box, x_box);
    char names[10][20] = {"ROCKSTAR", "LOSE YOURSELF", "COMFORTABLY NUMB","SWEET DREAMS", "ADDICTED", "INT THE END", "RANDOM", "OFF"};
    int choice =0;
    srand(time(0));
    while(1){    
   box(window, 0, 0);
    wbkgd(window, COLOR_PAIR(2));
    attron(COLOR_PAIR(2));
    printmusic();
    attroff(COLOR_PAIR(2));
    refresh();
    wrefresh(window);
        for(int i =0; i<8; i++){
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
            choice =7;
        }
         if(key == KEY_DOWN){
            if(choice != 7){
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
        
       return 0;
    }
     else if(choice == 1){
        
        return 1;
    }
    else if(choice == 2){
        
        return 2;   
    }
    else if(choice == 3){
        
        return 3;   
    }
    else if(choice == 4){
        
        return 4;   
    }
    else if(choice == 5){
        
        return 5;   
    }
    else if(choice == 6 ){
        
        int random = rand() % 6;
        return random;   
    }
    else if(choice == 7){
        
        return 9;   
    }
    clear();
    }
    nocbreak();
    endwin();}