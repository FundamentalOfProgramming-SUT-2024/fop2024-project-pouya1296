#include <ncurses.h>
#include <string.h>
#include <mysql/mysql.h>

typedef struct {
    char username[100];
    char password[100];
    char email[100];
    char question[100];
    char answer[100];
} User;

void printshape() {
    char shape[][100] = {        
        " .-=========-.",
        " \\'-=======-'/",
        " _|   .=.   |_",
        "((|  {{1}}  |))",
        " \\|   /|\\   |/",
        "  \\__ '`' __/",
        "    _`) (`_",
        "  _/_______\\_",
        " /___________\\"
    };



    int starty = 15;
    int startx = 4;

    for (int i = 0; i < 9; i++) {
        mvprintw(starty + i, startx, "%s", shape[i]);
    }

}


void printlogin() {
    char text[][100] = {        
        " _      ____   _____ _____ _   _ ",
        "| |    / __ \\ / ____|_   _| \\ | |",
        "| |   | |  | | |  __  | | |  \\| |",
        "| |   | |  | | | |_ | | | | . ` |",
        "| |___| |__| | |__| |_| |_| |\\  |",
        "|______\\____/ \\_____|_____|_| \\_|"
    };

    int starty = 1;
    int startx = (COLS - strlen(text[0])) / 2;

    for (int i = 0; i < 6; i++) {
        mvprintw(starty + i, startx, "%s", text[i]);
    }

}


void printarc() {
    char text[][100] = {

"    __________________________",
"   |OFFo oON                  |",
"   | .----------------------. |",
"   | |  .----------------.  | |",
"   | |  |                |  | |",
"   | |))|                |  | |",
"   | |  |                |  | |",
"   | |  |                |  | |",
"   | |  |                |  | |",
"   | |  |                |  | |",
"   | |  |                |  | |",
"   | |  '----------------'  | |",
"   | |__GAME BOY____________/ |",
"   |          ________        |",
"   |    .    (Nintendo)       |",
"   |  _| |_   \"\"\"\"\"\"\"\"   .-.  |",
"   |-[_   _]-       .-. (   ) |",
"   |   |_|         (   ) '-'  |",
"   |    '           '-'   A   |",
"   |                 B        |",
"   |          ___   ___       |",
"   |         (___) (___)  ,., |",
"   |        select start ;:;: |",
"   |                    ,;:;' /",
"   |                   ,:;:'.'",
"   '-----------------------`"
    };

    int starty = (LINES - sizeof(text) / sizeof(text[0])) / 2 + 2;
    int startx = COLS -32;

    for (int i = 0; i < sizeof(text) / sizeof(text[0]); i++) {
        mvprintw(starty + i, startx, "%s", text[i]);
    }
}

int loaduser(char *username, User *addeduser) {
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


int usernamevalid(char newusername[100]){
    User asghar;
    return loaduser(newusername, &asghar);    
}

int passwordvalid(char password[100], char username[100]){
   // char information[110] = {0};
    //FILE *user = fopen("userinformation.txt", "r");
    // int valid =0;
    // int found =0;
    // while (fgets(information, 100, user ))
    // {
    //     int removelast = strlen(information) -1;
    //     information[removelast] = '\0';
    //     if(found){
    //         if(strcmp(information+ 9, password) ==0){
    //             valid =1;
    //             break;
    //         }
    //     }
        
    //    if(strncmp("username:", information, 9 ) ==0){
    //     if(strcmp(information + 9, username ) == 0){
    //        found =1;
    //     }
    //    }
     
    // }
    
    //fclose(user);
    User asghar;
    loaduser(username, &asghar);
    if(strcmp(password, asghar.password) == 0)
    return 1;
    return 0;
       
}

int questionvalid(char answer[100], char username[100]){
    // char information[110] = {0};
    // FILE *user = fopen("userinformation.txt", "r");
    // int valid =0;
    // int found =0;
    // while (fgets(information, 100, user ))
    // {
    //     int removelast = strlen(information) -1;
    //     information[removelast] = '\0';
    //     if(found){
    //         if(strncmp(information, "answer:" ,7) ==0){
    //             if(strcmp(information+ 7, answer ) ==0)
    //             valid =1;
    //             break;
    //         }
            
    //     }
        
    //    if(strncmp("username:", information, 9 ) ==0){
    //     if(strcmp(information + 9, username ) == 0){
    //        found =1;
    //     }
    //    }
     
    // }
    // fclose(user);
    // return valid;
    User asghar;
    loaduser(username, &asghar);
    if(strcmp(answer, asghar.answer) == 0)
    return 1;
    return 0;    
}

void findquestion(char question[100] , char username[100]){
    //     char information[110] = {0};
    // FILE *user = fopen("userinformation.txt", "r");
    // int valid =0;
    // int found =0;
    // while (fgets(information, 100, user ))
    // {
    //     int removelast = strlen(information) -1;
    //     information[removelast] = '\0';
    //     if(found){
    //         if(strncmp(information, "question:" ,9) ==0){
    //             strcpy(question, information + 9);
    //             break;
    //         }
         
    //     }
        
    //    if(strncmp("username:", information, 9 ) ==0){
    //     if(strcmp(information + 9, username ) == 0){
    //        found =1;
    //     }
    //    }
     
    // }
    // fclose(user);
    User asghar;
    loaduser(username, &asghar);
    strcpy(question, asghar.question);
}


int startlogin(char username[100]){
    initscr();
    start_color();
    clear();
    curs_set(true);
    cbreak();
    echo();
    char password[100] = {0};
    char answer[100] = {0};
    char question[100] = {0};

    int boxheight = 20;
    int boxwidth = 70;
    int y_box =  5 +(LINES - boxheight) /2;
    int x_box = (COLS - boxwidth) /2;
    
    init_pair(1,COLOR_GREEN, COLOR_BLACK);

   //FILE *file = fopen("userinformation.txt", "a");
   WINDOW *window = newwin(boxheight, boxwidth, y_box, x_box);
   box(window, 0, 0);
   wbkgd(window, COLOR_PAIR(1));
   attron(COLOR_PAIR(1));
   printshape();
   printarc();
   printlogin();
   attroff(COLOR_PAIR(1));
   refresh();
   wrefresh(window);
   int choice =0;
   mvwprintw(window, 2, 1, "press g for play as guest and other keys for login:");
   choice = wgetch(window);
   if(choice == 'g'){
    mvwprintw(window, 1, 1, "Enter your username: ");
   wrefresh(window); 
   wgetstr(window, username);
     //fclose(file);
  curs_set(false);
  noecho();
  clear();
  return 0;
   }
   else{
    mvwprintw(window, 2, 1, "                                                     ");
    mvwprintw(window, 2, 1, "forgotten password? press f else press other keys");
    choice = wgetch(window);
    if(choice == 'f'){
         mvwprintw(window, 2, 1, "                                                  ");
      while (1)
{
   mvwprintw(window, 1, 1, "Enter your username: ");
   wrefresh(window); 
   wgetstr(window, username);
   if(usernamevalid(username)){
    mvwprintw(window, 2, 1, "                                                   ");
    wrefresh(window);
    break;
   }
   else{
    wmove(window, 1, 20);
    wclrtoeol(window);
   box(window, 0, 0);
    mvwprintw(window, 2, 1, "User with this username could not be found");
    wrefresh(window);
   }
}
 while (1)
{  
    findquestion(question, username);
   mvwprintw(window, 3, 1, "%s?", question);
   wrefresh(window); 
   wgetstr(window, answer);
   if(questionvalid(answer, username)){
    mvwprintw(window, 4, 1, "                  ");
    wrefresh(window);
    break;
   }
   else{
    wmove(window, 3, strlen(question)+1);
    wclrtoeol(window);
   box(window, 0, 0);
    mvwprintw(window, 4, 1, "Wrong answer");
    wrefresh(window);
   }
}
    }
    else{
    mvwprintw(window, 2, 1, "                                                      ");
   while (1)
{
   mvwprintw(window, 1, 1, "Enter your username: ");
   wrefresh(window); 
   wgetstr(window, username);
   if(usernamevalid(username)){
    mvwprintw(window, 2, 1, "                                                     ");
    wrefresh(window);
    break;
   }
   else{
    wmove(window, 1, 20);
    wclrtoeol(window);
   box(window, 0, 0);
    mvwprintw(window, 2, 1, "User with this username could not be found");
    wrefresh(window);
   }
}

   while (1)
{
   mvwprintw(window, 3, 1, "Enter your password: ");
   wrefresh(window); 
   wgetstr(window, password);
   if(passwordvalid(password, username)){
    mvwprintw(window, 4, 1, "                  ");
    wrefresh(window);
    break;
   }
   else{
    wmove(window, 3, 20);
    wclrtoeol(window);
   box(window, 0, 0);
    mvwprintw(window, 4, 1, "Wrong password");
    wrefresh(window);
   }
}}}
 //fclose(file);
  curs_set(false);
  noecho();
  clear();
  delwin(window);
  nocbreak();
  endwin();;
  return 1;

}