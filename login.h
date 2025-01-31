#include <ncurses.h>
#include <string.h>


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





int usernamevalid(char newusername[100]){
    char information[110] = {0};
    FILE *user = fopen("userinformation.txt", "r");
    int valid =0;
    while (fgets(information, 100, user ))
    {
        int removelast = strlen(information) -1;
        information[removelast] = '\0';
       if(strncmp("username:", information, 9 ) ==0){
        if(strcmp(information + 9, newusername ) == 0){
            valid = 1;
            break;
        }
       }
    }
    fclose(user);
    return valid;    
}

int passwordvalid(char password[100], char username[100]){
    char information[110] = {0};
    FILE *user = fopen("userinformation.txt", "r");
    int valid =0;
    int found =0;
    while (fgets(information, 100, user ))
    {
        int removelast = strlen(information) -1;
        information[removelast] = '\0';
        if(found){
            if(strcmp(information+ 9, password) ==0){
                valid =1;
                break;
            }
        }
        
       if(strncmp("username:", information, 9 ) ==0){
        if(strcmp(information + 9, username ) == 0){
           found =1;
        }
       }
     
    }
    fclose(user);
    return valid;    
}

int questionvalid(char answer[100], char username[100]){
    char information[110] = {0};
    FILE *user = fopen("userinformation.txt", "r");
    int valid =0;
    int found =0;
    while (fgets(information, 100, user ))
    {
        int removelast = strlen(information) -1;
        information[removelast] = '\0';
        if(found){
            if(strncmp(information, "answer:" ,7) ==0){
                if(strcmp(information+ 7, answer ) ==0)
                valid =1;
                break;
            }
            
        }
        
       if(strncmp("username:", information, 9 ) ==0){
        if(strcmp(information + 9, username ) == 0){
           found =1;
        }
       }
     
    }
    fclose(user);
    return valid;    
}

void findquestion(char question[100] , char username[100]){
        char information[110] = {0};
    FILE *user = fopen("userinformation.txt", "r");
    int valid =0;
    int found =0;
    while (fgets(information, 100, user ))
    {
        int removelast = strlen(information) -1;
        information[removelast] = '\0';
        if(found){
            if(strncmp(information, "question:" ,9) ==0){
                strcpy(question, information + 9);
                break;
            }
         
        }
        
       if(strncmp("username:", information, 9 ) ==0){
        if(strcmp(information + 9, username ) == 0){
           found =1;
        }
       }
     
    }
    fclose(user);
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

   FILE *file = fopen("userinformation.txt", "a");
   WINDOW *window = newwin(boxheight, boxwidth, y_box, x_box);
   box(window, 0, 0);
   wbkgd(window, COLOR_PAIR(1));
   attron(COLOR_PAIR(1));
   printshape();
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
     fclose(file);
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
 fclose(file);
  curs_set(false);
  noecho();
  clear();
  delwin(window);
  nocbreak();
  endwin();;
  return 1;

}