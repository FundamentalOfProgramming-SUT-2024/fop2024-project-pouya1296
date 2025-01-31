#include "ncurses.h"
#include <string.h>

void printprof() {
    char text[][100] = {        
        " _____  _____   ____  ______ _____ _      ______ ",
        "|  __ \\|  __ \\ / __ \\|  ____|_   _| |    |  ____|",
        "| |__) | |__) | |  | | |__    | | | |    | |__   ",
        "|  ___/|  _  /| |  | |  __|   | | | |    |  __|  ",
        "| |    | | \\ \\| |__| | |     _| |_| |____| |____ ",
        "|_|    |_|  \\_\\\\____/|_|    |_____|______|______|"
    };


    int starty = 1;
    int startx = (COLS - strlen(text[0])) / 2;

    for (int i = 0; i < 6; i++) {
        mvprintw(starty + i, startx, "%s", text[i]);
    }

}


void printprofile(char newusername[100], WINDOW *window){
        char information[110] = {0};
        int found =0;
    FILE *user = fopen("userinformation.txt", "r");
    int valid =0;
    int printflag =2;
    while (fgets(information, 100, user ))
    {
        int removelast = strlen(information) -1;
        information[removelast] = '\0';
        if(found){
            if(printflag == 5){
                break;
            }
            else{
                mvwprintw(window,printflag,1, "%s\n", information);
                wrefresh(window);
                printflag++;
            }
        }
        
       if(strncmp("username:", information, 9 ) ==0){
        if(strcmp(information + 9, newusername ) == 0){
           found =1;
           mvwprintw(window,1,1, "%s\n", information);
        }
       }
    }
    fclose(user);
  
}
void startprofile(char username[100]){
    initscr();
    start_color();
    clear();
    curs_set(true);
    cbreak();
    

        int boxheight = 20;
    int boxwidth = 70;
    int y_box = 5 + (LINES - boxheight) /2;
    int x_box = (COLS - boxwidth) /2;
    init_pair(1,COLOR_GREEN,COLOR_BLACK);
    attron(COLOR_PAIR(1));
    printprof();
    attroff(COLOR_PAIR(1));

   FILE *file = fopen("userinformation.txt", "a");
   WINDOW *window = newwin(boxheight, boxwidth, y_box, x_box);
   box(window, 0, 0);
   wbkgd(window, COLOR_PAIR(1));
   refresh();
   wrefresh(window);
   printprofile(username, window);
   mvwprintw(window, 10, 1, "Press any key to return to the menu");
   wrefresh(window);
   getch();
   delwin(window);
   clear();
   reset_color_pairs();
   endwin();
}