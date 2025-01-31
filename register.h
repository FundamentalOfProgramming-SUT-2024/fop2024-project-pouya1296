
#include <string.h>
#include <stdlib.h>
#include <time.h>

void printnew() {
    char text[][100] = {        
        " _   _ ________          __",
        "| \\ | |  ____\\ \\        / /",
        "|  \\| | |__   \\ \\  /\\  / / ", 
        "| . ` |  __|   \\ \\/  \\/ /  ", 
        "| |\\  | |____   \\  /\\  /   ", 
        "|_| \\_|______|   \\/  \\/"
    };


    int starty = 1;
    int startx = (COLS - strlen(text[0])) / 2;

    for (int i = 0; i < 6; i++) {
        mvprintw(starty + i, startx, "%s", text[i]);
    }

}

int isusernamevalid(char newusername[100]){
    char information[110] = {0};
    FILE *user = fopen("userinformation.txt", "r");
    int valid =1;
    while (fgets(information, 100, user ))
    {
        int removelast = strlen(information) -1;
        information[removelast] = '\0';
       if(strncmp("username:", information, 9 ) ==0){
        if(strcmp(information + 9, newusername ) == 0){
            valid = 0;
            break;
        }
       }
    }
    fclose(user);
    return valid;    
}

int ispasswordvalid(char password[100]){
    int lowercase =0;
    int uppercase = 0;
    int number = 0;
            if(strlen(password)<7){
                return 1;
            }
            else{
                int i =0;
                while (password[i] != '\0')
                {
                   if((password[i] <= 'z') && ( password[i] >= 'a'))
                   lowercase = 1;
                   else if((password[i] <= 'Z') && ( password[i] >= 'A'))
                   uppercase =1;
                   else if((password[i] <= '9') && ( password[i] >= '0'))
                   number =1;
                   i++;
                }
                if(lowercase ==0)
                return 2;
                else if(uppercase ==0)
                return 3;
                else if(number ==0 )
                return 4;
                else
                return 5;
                
            }
        }

void printerror(int errortype, WINDOW *window){
    if(errortype == 1){
        mvwprintw(window, 4, 1, "The length of the password must be at least 7");
    }
    else if(errortype == 2){
        mvwprintw(window, 4, 1, "Password must contain at least one lowercase letter");
    }
    else if(errortype == 3){
        mvwprintw(window, 4, 1, "Password must contain at least one uppercase letter");
    }
    else if(errortype == 4){
        mvwprintw(window, 4, 1, "Password must contain at least one number");
    }
}

int isemailvalid(char email[100]){
    int atsign =0;
    int i =0;
    int valid =1;
    int beforeatsign =0;
    int afteratsign =0;
    int dot =0;
    int afterdot =0;
    while ((email[i] != '\0'))
    {
        if(email[i] == '@'){
        atsign++;
        break;}
        else if(((email[i] >= 'a') && (email[i] <='z')) || ((email[i] >= 'A') && (email[i] <='Z')) || ((email[i] >= '0') && (email[i] <='9'))){
            beforeatsign++;
        }
        else{
        valid =0;
        break;}
        i++;
        
    }
    i++;
    while ((email[i] != '\0') && valid){
       if(email[i] == '@'){
        valid =0;
        break;
       }
       else if((((email[i] >= 'a') && (email[i] <='z')) || ((email[i] >= 'A') && (email[i] <='Z')) )&& !dot){
        afteratsign++;
       }
       else if(email[i] == '.'){
        if(dot){
        valid =0;
        break;
       }
       dot= 1;
    }
    else if((((email[i] >= 'a') && (email[i] <='z')) || ((email[i] >= 'A') && (email[i] <='Z'))) && dot){
        afterdot++;
    }
    else{
        valid =0;
        break;
    }
    i++; 
}
if((afteratsign>0 )&& (beforeatsign>0) && (dot ==1 )&& (afterdot>0) && valid){
    return 1;
}
else
return 0;
}

void randompassword(char password[100]){
    char lowercase[26] ={'a','b','c','d','e','f','g','h','i','j','k','l','n','m','o','p','q','r','s','t','u','v','w','x','y','z'};
    char uppercase[26] = {0};
    for(int i =0; i<26; i++){
        uppercase[i] = lowercase[i] + 'A' - 'a';
    }
    int len = rand() % 10 + 7; 
    for(int i =0; i<len; i++){
        if(i == 0){
            password[i] = lowercase[rand() % 26];
        }
        else if((i % 2 )== 0){
            password[i] = '0' + rand() % 10;
        }
        else if((i %3) ==0){
            password[i] = uppercase[rand() % 26];
        }
        else{
            password[i] = lowercase[rand() % 26];
        }
    }
}


void registerUser(){
 initscr();
 start_color();
clear();
curs_set(true);
cbreak();
echo();
srand(time(0));
    char username[100] ={0};
    char password[100] = {0};
    char email[100] = {0};
    char question[100] = {0};
    char answer[100] = {0};
    int boxheight = 20;
    int boxwidth = 80;
    int starty = 5 + (LINES - boxheight) /2;
    int startx = (COLS - boxwidth) /2;
    
    init_pair(1,COLOR_MAGENTA, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    printnew();
    attroff(COLOR_PAIR(1));

   FILE *file = fopen("userinformation.txt", "a");
   WINDOW *window = newwin(boxheight, boxwidth, starty, startx);
   box(window, 0, 0);
   wbkgd(window, COLOR_PAIR(1));
   refresh();
   wrefresh(window);
while (1)
{
   mvwprintw(window, 1, 1, "Enter your username: ");
   wrefresh(window); 
   wgetstr(window, username);
   if(isusernamevalid(username)){
    mvwprintw(window, 2, 1, "                              ");
    wrefresh(window);
    break;
   }
   else{
    wmove(window, 1, 20);
    wclrtoeol(window);
   box(window, 0, 0);
    mvwprintw(window, 2, 1, "The username is already taken.");
    wrefresh(window);
   }
}
mvwprintw(window, 2,1, "press r for random and other keys for manual password:");
int choice =0;
choice = wgetch(window);
while (1)
{
    if(choice == 'r'){
    randompassword(password);
    mvwprintw(window, 3, 1, "Your password is:%s", password);
    wrefresh(window);
    mvwprintw(window, 2,1, "                                                           ");
    break;
   }
  else{
     mvwprintw(window, 2,1, "                                                          ");
   mvwprintw(window, 3, 1, "Enter your password:");
   wmove(window, 3, 21);
   wrefresh(window); 
   wgetstr(window, password);
   int valid = ispasswordvalid(password);
   if(valid ==5){
    mvwprintw(window, 4, 1, "                                                         ");
    wrefresh(window);
    break;
   }
   else{
    wmove(window, 3, 21);
    wclrtoeol(window);
    box(window, 0, 0);
    printerror(valid, window);
    wrefresh(window);
    
}
   }

}
while (1)
{
   mvwprintw(window, 5, 1, "Enter your email:");
   wrefresh(window); 
   wgetstr(window, email);
   if(isemailvalid(email)){
    mvwprintw(window, 6, 1, "                                                     ");
    wrefresh(window);
    break;
   }
   else{
    wmove(window, 5, 18);
    wclrtoeol(window);
   box(window, 0, 0);
    mvwprintw(window, 6, 1, "Please enter a valid email");
    wrefresh(window);
   }
}

while (1)
{
   mvwprintw(window, 7, 1, "Enter your security question: ");
   wrefresh(window); 
   wgetstr(window, question);
   mvwprintw(window, 8, 1, "Enter your answer:");
   wrefresh(window);
   wgetstr(window, answer);
   break;

}
   mvwprintw(window, 9, 3, "Welcome %s!", username );
   mvwprintw(window,10,3, "Press any key to return to the menu");
   
   wrefresh(window);


   fprintf(file, "username:%s\npassword:%s\nemail:%s\nquestion:%s\nanswer:%s\n", username, password, email, question, answer);
   fclose(file);
   noecho();
  getch();
  curs_set(false);
  clear();
  delwin(window);
  endwin();
}

