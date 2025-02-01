#include "ncurses.h"
#include <string.h>

typedef struct {
    char username[100];
    char password[100];
    char email[100];
    char question[100];
    char answer[100];
} usEr;

int loAduser(char *username, usEr *addeduser) {
    MYSQL *sql;
    MYSQL_RES *resault;
    MYSQL_ROW row;

    char *server = "localhost";
    char *user = "root";
    char *password = "pouya1234";
    char *database = "userdatabase";

    sql = mysql_init(NULL);
   
  mysql_real_connect(sql, server, user, password, database, 0, NULL, 0);
 
    char query[256];
    snprintf(query, sizeof(query), "SELECT username, password, email, question, answer FROM users WHERE username='%s'", username);
    if(mysql_query(sql, query)){

    return 0;
    }
    
    

    resault = mysql_store_result(sql);
    if(resault == NULL)
    return 0;

    row = mysql_fetch_row(resault);
    if(row == NULL)
    return 0;
        strcpy(addeduser->username, row[0]);
        strcpy(addeduser->password, row[1]);
        strcpy(addeduser->email, row[2]);
        strcpy(addeduser->question, row[3]);
        strcpy(addeduser->answer, row[4]);
    
    mysql_free_result(resault);
    mysql_close(sql);
    return 1;
}

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
     usEr asghar;
     loAduser(newusername, &asghar);
        mvwprintw(window, 1, 1, "username: %s", asghar.username);
         mvwprintw(window, 2, 1, "email: %s", asghar.email);
         mvwprintw(window, 3, 1, "question: %s", asghar.question);
         mvwprintw(window, 4, 1, "answer: %s", asghar.answer);

   
}

void startprofile(char username[100]){
    initscr();
    start_color();
    clear();
    curs_set(true);
    cbreak();
    

        int boxheight = 20;
    int boxwidth = 80;
    int y_box = 5 + (LINES - boxheight) /2;
    int x_box = (COLS - boxwidth) /2;
    init_pair(1,COLOR_GREEN,COLOR_BLACK);
    attron(COLOR_PAIR(1));
    printprof();
    attroff(COLOR_PAIR(1));

  // FILE *file = fopen("userinformation.txt", "a");
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