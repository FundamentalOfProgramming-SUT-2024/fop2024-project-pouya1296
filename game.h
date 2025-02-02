#ifndef Header_guard1 
#include "ncurses.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <locale.h>
#include <wchar.h>

#define Header_guard1
#define Regular 0
#define Treasure 1
#define Enchant 2
#define Nightmare 3
#define purgatory 4
#define maxx 151
#define maxy 39
#define middle_x COLS /2
#define middle_y LINES /2
#define DEAMON 0
#define FIRE 1
#define GIANT 2
#define SNAKE 3
#define UNDEED 4
#define NORMAL 0
#define GREAT 1
#define MAGIC 2
#define POISENOUS 3

int rightshot =0;
int leftshot = 0;
int upshot =0;
int downshot =0;


typedef struct{
    int x;
    int y;
} position;

typedef struct{
    int kind;
    int hp;
    int movement;
    int dontmove;
    position pos;

}monster;

typedef struct{
    int type;
    position topleft;
    position topright;
    position bottomright;
    position bottomleft;
    position door[5];
    int istrap;
    int isvisible;
    int stairs;
    int ishiddend;
    int player;
    int firsttime;
    int iswindow;
    position trap[2];
    position window;
    position hiddendoor;
    int islocked;
    int theme;
    int goldamount;
    monster mons[6];
    int monsnum;
} room;

typedef struct{
    position loc;
    int isvisible;
}corridor;

typedef struct{
char name[100];
int hpamount;
int fkind; 
time_t ftime;
} food;

typedef struct{
char name[100];
int isactive; 
int count;
int damage;
} weapon;

typedef struct{
char name[100];
int count;
} spell;

typedef struct{
char map[5][152][40];
char realmap[5][152][40];
char username[100];
room rooms[5][6];
position player;
food flist[6];
weapon wlist[6];
spell slist[4];
int lastx;
int lasty;
int lastlevel;
int firstdie;
int lastkey;
int hunger;
int foodamount;
int rank;
int numberofrooms;
int level;
int savelevel;
int playerhp;
int gold;
int hits;
int color;
int difficulty;
int music;
int ancient;
int brokenancient;
int experience;
int totalscore;
int endgame;
int numberofgames;
int totalgold;
int ishealthspell;
int isspeedspell;
int isdamagespell;
int spellcounter;
int recover;
} data;



#include <ncurses.h>
#include <string.h>

void printsoldierleft() {
    char text[][100] = {
"  ,   A           {}",
" / \\, | ,        .--.",
"|    =|= >      /.--.\\",
" \\ /` | `       |====|",
"  `   |         |`::`|",
"      |     .-;`\\..../`;-.",
"     /\\\\/  /  |...::...|  \\",
"     |:'\\ |   /'''::'''\\   |",
"      \\ /\\;-,/\\   ::   /\\--;",
"      |\\ <` >  >._::_.<,<__>",
"      | `""`  /   ^^   \\|  |",
"      |       |        |\\::/",
"      |       |        |/|||",
"      |       |___/\\___| '''",
"      |        \\_ || _/",
"      |        <_ >< _>",
"      |        |  ||  |",
"      |        |  ||  |",
"      |       _\\.:||:./_",
"      |      /____/\\____\\"
    };

    int starty = (LINES - sizeof(text) / sizeof(text[0])) / 2;
    int startx = 1;

    for (int i = 0; i < sizeof(text) / sizeof(text[0]); i++) {
        mvprintw(starty + i, startx, "%s", text[i]);
    }
}

void printsoldierright() {
    char text[][100] = {
"  ,   A           {}",
" / \\, | ,        .--.",
"|    =|= >      /.--.\\",
" \\ /` | `       |====|",
"  `   |         |`::`|",
"      |     .-;`\\..../`;-.",
"     /\\\\/  /  |...::...|  \\",
"     |:'\\ |   /'''::'''\\   |",
"      \\ /\\;-,/\\   ::   /\\--;",
"      |\\ <` >  >._::_.<,<__>",
"      | `""`  /   ^^   \\|  |",
"      |       |        |\\::/",
"      |       |        |/|||",
"      |       |___/\\___| '''",
"      |        \\_ || _/",
"      |        <_ >< _>",
"      |        |  ||  |",
"      |        |  ||  |",
"      |       _\\.:||:./_",
"      |      /____/\\____\\"
    };

    int starty = (LINES - sizeof(text) / sizeof(text[0])) / 2;
    int startx = COLS -30;

    for (int i = 0; i < sizeof(text) / sizeof(text[0]); i++) {
        mvprintw(starty + i, startx, "%s", text[i]);
    }
}

void printtea() {
    char text[][100] = {
"    (  )   (   )  )",
"     ) (   )  (  (",
"     ( )  (    ) )",
"     _____________",
"    <_____________> ___",
"    |             |/ _ \\",
"    |               | | |",
"    |               |_| |",
" ___|             |\\___/",
"/    \\___________/    \\",
"\\_____________________/"
    };

    int starty = (LINES - sizeof(text) / sizeof(text[0])) / 2;
    int startx = COLS -26;

    for (int i = 0; i < sizeof(text) / sizeof(text[0]); i++) {
        mvprintw(starty + i, startx, "%s", text[i]);
    }
}

void printquit(WINDOW* window) {
    char text[][100] = {
"   ____    _    _   _____   _______ ",
"  / __ \\  | |  | | |_   _| |__   __|",
" | |  | | | |  | |   | |      | |   ",
" | |  | | | |  | |   | |      | |   ",
" | |__| | | |__| |  _| |_     | | "  ,
"  \\___\\_\\  \\____/  |_____|    |_| "  
                                    
    };

    int starty = (30 - sizeof(text) / sizeof(text[0])) / 2 ;
    int startx = (100 - strlen(text[0])) / 2 ;

    for (int i = 0; i < sizeof(text) / sizeof(text[0]); i++) {
        mvwprintw(window, starty + i, startx, "%s", text[i]);
    }
}

void printkill() {
    char text[][100] = {

"  _  _______ _      _         ____  _____    _____ _____ ______ ",
" | |/ /_   _| |    | |       / __ \\|  __ \\  |  __ \\_   _|  ____|",
" | ' /  | | | |    | |      | |  | | |__) | | |  | || | | |__   ",
" |  <   | | | |    | |      | |  | |  _  /  | |  | || | |  __|  ",
" | . \\ _| |_| |____| |____  | |__| | | \\ \\  | |__| || |_| |____ ",
" |_|\\_\\_____|______|______|  \\____/|_|  \\_\\ |_____/_____|______|"
                                                                                          
    };

    int starty = 1;
    int startx = (COLS - strlen(text[0])) / 2;

    for (int i = 0; i < sizeof(text) / sizeof(text[0]); i++) {
        mvprintw(starty + i, startx, "%s", text[i]);
    }
}

void printspeed(WINDOW* window) {
    char text[][100] = {
        "            zeeeeee-",
        "            z$$$$$$\"",
        "           d$$$$$$\"",
        "          d$$$$$P",
        "         d$$$$$P",
        "        $$$$$$\"",
        "      .$$$$$$\"",
        "     .$$$$$$\"",
        "    4$$$$$$$$$$$$$\"",
        "   z$$$$$$$$$$$$$\"",
        "   \"\"\"\"\"\"\"3$$$$$\"",
        "         z$$$$P",
        "        d$$$$\"",
        "      .$$$$$\"",
        "     z$$$$$\"",
        "    z$$$$P",
        "   d$$$$$$$$$$\"",
        "  *******$$$\"",
        "       .$$$\"",
        "      .$$\"",
        "     4$P\"",
        "    z$\"",
        "   zP",
        "  z\"",
        " /    ",
        "^"
    };

    int starty = (30 - sizeof(text) / sizeof(text[0])) / 2 ;
    int startx = (100 - strlen(text[0])) / 2;

    for (int i = 0; i < sizeof(text) / sizeof(text[0]); i++) {
        mvwprintw(window, starty + i, startx, "%s", text[i]);
    }
}

void printheart(WINDOW * window) {
    char text[][100] = {
        "⠀⠀⢀⣤⣾⣿⣿⣿⣿⣿⣶⣤⡀⢀⣤⣶⣿⣿⣿⣿⣿⣷⣤⡀⠀⠀",
        "⠀⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀",
        "⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄",
        "⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇",
        "⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀",
        "⠀⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀",
        "⠀⠀⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⠀⠀",
        "⠀⠀⠀⠀⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠋⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⣿⣿⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠻⣿⣿⠟⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
    };

    int starty = (30 - sizeof(text) / sizeof(text[0])) / 2 ;
    int startx = (100 - strlen(text[0])) / 2 +27;

    for (int i = 0; i < sizeof(text) / sizeof(text[0]); i++) {
        mvwprintw(window, starty + i, startx, "%s", text[i]);
    }
}

void printwand(WINDOW* window) {
    char text[][100] = {
        "        __",
        "       ,. |_'",
        "      / / /:\\ \\",
        "    _/_/_/::: |",
        "   /o_'/o>::/ /",
        "   / /'/:::/ /",
        "  / /_/::.'_/",
        " / / \\__.-'              ",
        "/ /                      ",
        "/ /                        ",
        " /"        
    };

    int starty = (30 - sizeof(text) / sizeof(text[0])) / 2 ;
    int startx = (100 - strlen(text[0])) / 2;

    for (int i = 0; i < sizeof(text) / sizeof(text[0]); i++) {
        mvwprintw(window, starty + i, startx, "%s", text[i]);
    }
}

void printdagger(WINDOW* window) {
    char text[][100] = {
"   ___________________________________ ______________________",
"  \\                                  | (_)     (_)    (_)   \\",
"  `.                                |  __________________   }",
"    `-..........................____|_(                  )_/"
    };

    int starty = (30 - sizeof(text) / sizeof(text[0])) / 2 ;
    int startx = (100 - strlen(text[0])) / 2;

    for (int i = 0; i < sizeof(text) / sizeof(text[0]); i++) {
        mvwprintw(window, starty + i, startx, "%s", text[i]);
    }
}

void printmace(WINDOW* window) {
    char text[][100] = {
        "                                           _.gd8888888bp._                  ",
        "                                        .g88888888888888888p.               ",
        "                                     .d8888P\"\"       \"\"Y8888b.            ",
        "                                   \"Y8P\"               \"Y8P'            ",
        "                                        `.               ,'                ",
        "                                          \\     .-.     /                  ",
        "                                           \\   (___)   /                   ",
        ".------------------._______________________:__________j",
        "/                   |                      |           |`-.,_",
        "\\###################|######################|###########|,-'`",
        " `------------------'                       :    ___   l",
        "                                            /   (   )   \\",
        "                                           /     `-'     \\",
        "                                         ,'               `.",
        "                                      .d8b.               .d8b.",
        "                                      \"Y8888p..       ,.d8888P\"",
        "                                        \"Y88888888888888888P\"",
        "                                           \"\"YY8888888PP\"\"   "
    };

    int starty = (30 - sizeof(text) / sizeof(text[0])) / 2 ;
    int startx = (100 - strlen(text[0])) / 2;

    for (int i = 0; i < sizeof(text) / sizeof(text[0]); i++) {
        mvwprintw(window, starty + i, startx, "%s", text[i]);
    }
}

void printarrow(WINDOW* window) {
    char text[][100] = {
        ">>>>>>>_____________________\\`-._",
        ">>>>>>>                     /.-'"
    };

    int starty = (30 - sizeof(text) / sizeof(text[0])) / 2 ;
    int startx = (100 - strlen(text[0])) / 2;

    for (int i = 0; i < sizeof(text) / sizeof(text[0]); i++) {
        mvwprintw(window, starty + i, startx, "%s", text[i]);
    }
}

void printsword(WINDOW* window) {
    char text[][100] = {
"              />",
" ()          //---------------------------------------------------------(",
"(*)OXOXOXOXO(*>                                                          \\",
" ()          \\\\-----------------------------------------------------------)",
"              \\\\>"
};

    int starty = (30 - sizeof(text) / sizeof(text[0])) / 2 ;
    int startx = (100 - strlen(text[0])) / 2- 26;

    for (int i = 0; i < sizeof(text) / sizeof(text[0]); i++) {
        mvwprintw(window, starty + i, startx, "%s", text[i]);
    }
}

void printbio(WINDOW* window) {
    char text[][100] = {        
"                       __    _                                    ",
"                    _wr\"\"        \"-q__                             ",
"                 _dP                 9m_     ",
"               _#P                     9#_                         ",
"              d#@                       9#m                        ",
"             d##                         ###                      ",
"            J###                         ###L                     ",
"            {###K                       J###K                     ",
"            ]####K      ___aaa___      J####F                     ",
"        __gmM######_  w#P\"\"   \"\"9#m  _d#####Mmw__                ",
"     _g##############mZ_         __g##############m_              ",
"   _d####M@PPPP@@M#######Mmp gm#########@@PPP9@M####m_            ",
"  a###\"\"          ,Z\"#####@\" '######\"\\g          \"\"M##m           ",
" J#@\"             0L  \"*##     ##@\"  J#              *#K           ",
" #\"               `#    \"_gmwgm_~    dF               `#_          ",
"7F                 \"#_   ]#####F   _dK                 JE          ",
"]                    *m__ ##### __g@\"                   F          ",
"                       \"PJ#####LP\"                                 ",
" `                       0######_                      '           ",
"                       _0########_                                ",
"     .               _d#####^#####m__              ,              ",
"      \"*w_________am#####P\"   ~9#####mw_________w*\"                ",
"          \"\"9@#####@M\"\"           \"\"P@#####@M\"\" "
    };

    int starty = (30 - sizeof(text) / sizeof(text[0])) / 2 ;
    int startx = (100 - strlen(text[0])) / 2+4;

    for (int i = 0; i < sizeof(text) / sizeof(text[0]); i++) {
        mvwprintw(window, starty + i, startx, "%s", text[i]);
    }
}

void printcandy(WINDOW* window) {
    char text[][100] = {        
"        .",
"      ,i \\",
"    ,' 8b \\",
"  ,;o  `8b \\",
" ;  Y8. d8  \\",
"-+._ 8: d8. i:",
"    `:8 `8i `8",
"      `._Y8  8:  ___",
"         `'---Yjdp  \"8m._",
"              ,\"\' _,o9   `m._",
"              | o8P\"   _.8d8P`-._",
"              :8\'   _oodP\"   ,dP'`-._",
"               `: dd8P'   ,odP'  do8'`.",
"                 `-'   ,o8P'  ,o8P' ,8P`.",
"                   `._dP'   ddP'  ,8P' ,..",
"                      \"`._ PP'  ,8P' _d8\'L..__",
"                          `\"-._88\'  .PP,\'7 ,8.`-.._",
"                               ``'\"--\"\'  | d8' :8i `i.",
"                                         l d8  d8  dP/",
"                                          \\`' J8' `P\'",
"                                           \\ ,8F  87",
"                                           `.88  ,'",
"                                            `.,-' "
    };

    int starty = (30 - sizeof(text) / sizeof(text[0])) / 2 ;
    int startx = (100 - strlen(text[0])) / 2-20;

    for (int i = 0; i < sizeof(text) / sizeof(text[0]); i++) {
        mvwprintw(window, starty + i, startx, "%s", text[i]);
    }
}

void printicecream(WINDOW* window) {
    char text[][100] = {        
"            .oo.",
"          oGGGGGGo",
"         GGGGGGGGGG",
"  .mMMMMMMGGGGGGEEEE=",
" MMMMMMMMMMMGGEEEEEEEE",
"MMMMMMMMMMMNICKEEEEEEEE",
"MMMMMMMMMMMMMEEEEEEEEEE",
"!MMMMMMMMMMMOOEEEEEEEE",
" MMM!MMMMMMOOOOOOE!=",
"  MM!!!!!!!!!!!!!!!",
"   MM!!!!!!!!!!!!!'",
"   !M!!!!!!!!!!!!!",
"    MM!!!!!!!!!!!'",
"    MM!!!!!!!!!!!",
"    ! `!!!!!!!!!'",
"    .  !!!!!!!!!",
"       `!!!!!!!\'",
"        !!!!!!!",
"        `!!!!!\'",
"         !!!!!",
"         `!!!\'",
"          !!!",
"          `!\'",
"           !"   
    };

    int starty = (30 - sizeof(text) / sizeof(text[0])) / 2 ;
    int startx = (100 - strlen(text[0])) / 2-3;

    for (int i = 0; i < sizeof(text) / sizeof(text[0]); i++) {
        mvwprintw(window, starty + i, startx, "%s", text[i]);
    }
}

void printburger(WINDOW* window) {
    char text[][100] = {        
"                           |\\ /| /|_/|",
"                          |\\||-|\\||-/|/|",
"                           \\\\|\\|//||///",
"          _..----.._       |\\/\\||//||||",
"        .\'     o    \'.     |||\\\\|/\\\\ ||",
"       /   o       o  \\    | './\\_/.' |",
"      |o        o     o|   |          |",
"      /\'-.._o     __.-\'\\   |          |",
"      \\      `````     /   |          |",
"      |``--........--'`|    \'.______.\'",
"       \\              /",
"        `\'----------\'`"
    };

    int starty = (30 - sizeof(text) / sizeof(text[0])) / 2 ;
    int startx = (100 - strlen(text[0])) / 2-4;

    for (int i = 0; i < sizeof(text) / sizeof(text[0]); i++) {
        mvwprintw(window, starty + i, startx, "%s", text[i]);
    }
}

void printttt(char username[], int score) {
    char text[][200] = {
"    ⠀⠀⠀⢀⣠⣴⠶⠶⣦⣤⣀⣤⣶⣶⣶⡶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⣶⣶⣶⣦⣄⣤⣴⠶⠶⢦⣤⡀⠀⠀⠀⠀⠀ ",
"⠀⠀⠀⠀⠀⢠⡿⠉⢀⣠⣀⣀⠈⣽⠏⠉⠉⠙⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠉⠉⠉⣿⠁⣄⣦⣤⣀⠈⠻⣦⠀⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⣿⠀⢠⡟⠉⠉⠉⠛⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⡟⠋⠉⠉⢻⡆⠀⢻⡄⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⣿⠀⢸⡇⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠈⣷⠀⢸⡇⠀⠀⠀⠀",
"⠀⠀⠀⠀⠠⣿⠀⠸⣇⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⢰⡏⠀⣸⠇⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⢻⣆⠀⢻⣄⠀⠀⠀⢻⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⢀⡾⠁⢀⡿⠀⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⠀⢻⣆⠀⠹⣧⣄⠀⠈⢷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠃⠀⢀⣴⠟⠁⢠⡾⠁⠀⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠙⢷⣄⠀⠙⠻⢦⣼⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣯⣴⠾⠋⠁⣀⣴⠟⠁⠀⠀⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠻⢦⣄⣀⠈⠉⠻⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡾⠋⠁⢀⣠⣤⠾⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠛⠲⠶⠼⢷⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⠿⠶⠶⠛⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣦⡀⠀⠀⠀⠀⠀⣠⡾⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢷⡄⠀⠀⢀⡾⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡀⠀⣾⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡿⠀⠀⢻⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⠃⠀⠀⠈⢿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡾⠁⠀⠀⠀⠀⠀⢻⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣁⣀⣀⣀⣀⣀⣀⣀⣿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡟⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠹⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠿⠶⠶⠶⠶⠶⠶⠶⠶⠶⠶⠾⢷⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣼⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
    };


    int starty = 1;
    int startx = 50;

    for (int i = 0; i < 21; i++) {
        mvprintw(starty + i, startx, "%s", text[i]);
        if(i==4){
            for(int j =0; j<strlen(username); j++){
                mvprintw(4, startx +25 -( strlen(username))/2 + j, "%c", username[j]);
            }
        }
    } 
    mvprintw(6,startx +25-  ( strlen("SCORE: "))/2 ,"SCORE: %d", score);

 
}

void printweapon() {
    char text[][200] = {

" __          ________          _____   ____  _   _ ",
" \\ \\        / /  ____|   /\\   |  __ \\ / __ \\| \\ | |",
"  \\ \\  /\\  / /| |__     /  \\  | |__) | |  | |  \\| |",
"   \\ \\/  \\/ / |  __|   / /\\ \\ |  ___/| |  | | . ` |",
"    \\  /\\  /  | |____ / ____ \\| |    | |__| | |\\  |",
"     \\/  \\/   |______/_/    \\_\\_|     \\____/|_| \\_|"
    };


    int starty = 1;
    int startx = maxx/2 - strlen(text[0])/2;

    for (int i = 0; i < 6; i++) {
        mvprintw(starty + i, startx, "%s", text[i]);
    }

 
}

void printfood() {
    char text[][200] = {
"  ______ ____   ____  _____",
" |  ____/ __ \\ / __ \\|  __ \\ ",
" | |__ | |  | | |  | | |  | |",
" |  __|| |  | | |  | | |  | |",
" | |   | |__| | |__| | |__| |",
" |_|    \\____/ \\____/|_____/ "

    };


    int starty = 1;
    int startx = maxx/2 - strlen(text[0])/2;

    for (int i = 0; i < 6; i++) {
        mvprintw(starty + i, startx, "%s", text[i]);
    }

 
}

void printspell() {
    char text[][200] = {

"   _____ _____  ______ _      _   "  , 
"  / ____|  __ \\|  ____| |    | |   "  ,
" | (___ | |__) | |__  | |    | |   "  ,
"  \\___ \\|  ___/|  __| | |    | |     ",
"  ____) | |    | |____| |____| |____ ",
" |_____/|_|    |______|______|______|"

    };


    int starty = 1;
    int startx = maxx/2 - strlen(text[0])/2;

    for (int i = 0; i < 6; i++) {
        mvprintw(starty + i, startx, "%s", text[i]);
    }

 
}

void printwrong() {
    char text[][200] = {
" __          _______   ____  _   _  _____   _ ",
" \\ \\        / /  __ \\ / __ \\| \\ | |/ ____| | |",
"  \\ \\  /\\  / /| |__) | |  | |  \\| | |  __  | |",
"   \\ \\/  \\/ / |  _  /| |  | | . ` | | |_ | | |",
"    \\  /\\  /  | | \\ \\| |__| | |\\  | |__| | |_|",
"     \\/  \\/   |_|  \\_\\\\____/|_| \\_|\\_____| (_)"
                                              
    };


    int starty = 1;
    int startx = maxx/2 - strlen(text[0])/2;

    for (int i = 0; i < 6; i++) {
        mvprintw(starty + i, startx, "%s", text[i]);
    }

 
}

void printenter() {
    char text[][200] = {

"  ______ _   _ _______ ______ _____      ",
" |  ____| \\ | |__   __|  ____|  __ \\   _ ",
" | |__  |  \\| |  | |  | |__  | |__) | (_)",
" |  __| | . ` |  | |  |  __| |  _  /     ",
" | |____| |\\  |  | |  | |____| | \\ \\   _ ",
" |______|_| \\_|  |_|  |______|_|  \\_\\ (_)"
                                              
    };


    int starty = 1;
    int startx = maxx/2 - strlen(text[0])/2;

    for (int i = 0; i < 6; i++) {
        mvprintw(starty + i, startx, "%s", text[i]);
    }

 
}

void printyoulost(int score) {
    char you_lost[][200] = {        
        "____    ____   ______    __    __      __        ______        _______  ___________ ",
        "\\   \\  /   /  /  __  \\  |  |  |  |    |  |      /  __  \\      /       ||           |",
        " \\   \\/   /  |  |  |  | |  |  |  |    |  |     |  |  |  |    |   (----``---|  |---- ",
        "  \\_    _/   |  |  |  | |  |  |  |    |  |     |  |  |  |     \\   \\        |  |     ",    
        "    |  |     |  `--'  | |  `--'  |    |  `----.|  `--'  | .----)   |       |  |     ",    
        "    |__|      \\______/   \\______/     |_______| \\______/  |_______/        |__|     "
    };
    

    int starty = (LINES - 6) / 2 + 1;
    int startx = (COLS - strlen(you_lost[0])) / 2;

    for (int i = 0; i < 6; i++) {
        mvprintw(starty + i, startx, "%s", you_lost[i]);
    }
    mvprintw(starty+8,COLS/2- 5- ( strlen("SCORE: "))/2 ,"SCORE: %d", score);

}

void printyouwon() {
    char you_won[][200] = {        
        "____    ____   ______    __    __     ____    __    ____   ______    __   __  ",
        "\\   \\  /   /  /  __  \\  |  |  |  |    \\   \\  /  \\  /   /  /  __  \\  |  \\ |  | ",
        " \\   \\/   /  |  |  |  | |  |  |  |     \\   \\/    \\/   /  |  |  |  | |   \\|  | ",
        "  \\_    _/   |  |  |  | |  |  |  |      \\            /   |  |  |  | |  . `  | ",
        "    |  |     |  `--'  | |  `--'  |       \\    /\\    /    |  `--'  | |  |\\   | ",
        "    |__|      \\______/   \\______/         \\__/  \\__/      \\______/  |__| \\__| "                                                                           
    };


    int starty = (LINES - 6) / 2 + 6;
    int startx = 2+ (COLS - strlen(you_won[0])) / 2;

    for (int i = 0; i < 6; i++) {
        mvprintw(starty + i, startx, "%s", you_won[i]);
    }
}

void health(data* game)
{
    float fraction = (float)game->playerhp / (100 );
    int width = (COLS / 3 - 1) * fraction;
    mvprintw(2, 0, "[");
    attron(COLOR_PAIR(1));
    for (int i = 1; i <= width; ++i)
        mvprintw(2, i, "#");
    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(2));
    for (int i = width + 1; i <= COLS / 3 - 1; ++i)
        mvprintw(2, i, ".");
    attroff(COLOR_PAIR(2));

    mvprintw(2, COLS / 3, "]");
    mvprintw(1, 0, "HP: %d", game->playerhp);
}

void hunger(data* game){
    float fraction = (float)game->hunger/ (100);
    int width = (COLS / 3 - 1) * fraction;
    mvprintw(4, 0, "[");
    attron(COLOR_PAIR(3));
    for (int i = 1; i <= width; ++i)
        mvprintw(4, i, "#");
    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(4));
    for (int i = width + 1; i <= COLS / 3 - 1; ++i)
        mvprintw(4, i, ".");
    attroff(COLOR_PAIR(4));

    mvprintw(4, COLS / 3, "]");
    mvprintw(3, 0, "HUNGER: %d", game->hunger);
}

void initializeweapon(data* game){
    for(int i =0; i<5; i++){
    game->wlist[i].count =0;
    game->wlist[i].isactive =0;
}
strcpy(game->wlist[0].name, "Mace");
game->wlist[0].count =1;
game->wlist[0].isactive =1;
game->wlist[0].damage =5;
strcpy(game->wlist[1].name, "Dagger");
game->wlist[1].damage =12;
strcpy(game->wlist[2].name, "Magic Wand");
game->wlist[2].damage =15;
strcpy(game->wlist[3].name, "Normal Arrow");
game->wlist[1].damage =5;
strcpy(game->wlist[4].name, "Sword");
game->wlist[1].damage =10;
}

void initializespell(data* game){
    for(int i =0; i<3; i++){
    game->slist[i].count =0;
}
strcpy(game->slist[0].name, "Health");
strcpy(game->slist[1].name, "Speed");
strcpy(game->slist[2].name, "Damage");
}

void adduser(data* users) {
    FILE *file = fopen("database.dat", "ab");
    fwrite(users, sizeof(data), 1, file);
    fclose(file);
}

int updateUser( char username[], data *user) {
    FILE *file = fopen("database.dat", "r+b");
    data temp;
    while (fread(&temp, sizeof(data), 1, file) == 1) {
        if (strcmp(temp.username, username) == 0) {
            fseek(file, -sizeof(data), SEEK_CUR);
            fwrite(user, sizeof(data), 1, file);
            fclose(file);
            return 1; 
        }
    }

    fclose(file);
    return 0;
}

int roomsearch(room rooms[], int x, int y){
    for(int i =0 ; i<6; i++){
        if((x<=rooms[i].bottomright.x) && (x>=rooms[i].bottomleft.x) && (y>=rooms[i].topleft.y)  &&(y<=rooms[i].bottomleft.y)) {
            return i;
        }
    }
    return -1;
}

void savegame(char username[], data *game) {
    char filename[256];
    snprintf(filename, sizeof(filename), "%s_savegame.dat", username);
    FILE *file = fopen(filename, "wb");
    fwrite(game, sizeof(data), 1, file);
    fclose(file);
}

int loadgame(char username[], data *game) {
    char filename[256];
    snprintf(filename, sizeof(filename), "%s_savegame.dat", username);
    FILE *file = fopen(filename, "rb");
    if(file == NULL){
        return 0;
    }
    else{
     fread(game, sizeof(data), 1, file);
     return 1;
     }
    
    fclose(file);
}

void initializemap(char map[maxx + 1][maxy + 1]){
for(int i =0; i<maxx +1; i++){
    for(int j =0; j<maxy +1; j++){
        map[i][j] = 0;
    }
}
}

void initializerooms(room *rooms){
        rooms->topleft.x = 0;
        rooms->topleft.y =0;
        rooms->topright.x = 0;
        rooms->topright.y =0;
        rooms->bottomleft.x = 0;
        rooms->bottomleft.y =0;
        rooms->bottomright.x = 0;
        rooms->bottomright.y =0;
        for(int j=0;j<6; j++ ){
            rooms->door[j].x = 0;
            rooms->door[j].y = 0;
        }
        rooms->stairs =0;
        rooms->trap[0].x =0;
        rooms->trap[0].y = 0;
        rooms->trap[1].x =0;
        rooms->trap[1].y = 0;
        rooms->ishiddend =0;
        rooms->window.x =0;
        rooms->window.y =0;
        rooms->player =0;
        rooms->isvisible =0;
        rooms->firsttime =0;
        rooms->istrap =0;
        rooms->islocked =-1;
        rooms->theme =Regular;
        for(int i =0; i<6; i++){
        rooms->mons[i].hp =5;
        rooms->mons[i].kind = DEAMON;
        rooms->mons[i].pos.x =0;
        rooms->mons[i].pos.y =0;
        rooms->mons[i].movement =0;
        rooms->mons[i].dontmove =0;
        }
        rooms->monsnum =0;

    }

int isroomvalid(room newroom, room rooms[], int numberoffilled){
    //int i =0;
   // int valid =1;
   if(numberoffilled == 1){
    if(newroom.topleft.y > 3)
    return 1;
    else
    return 0;
   }

     else if(numberoffilled == 2){
            if((newroom.topleft.x> 3 + rooms[0].topright.x) && (newroom.topleft.y > 3)){
                return 1;
            }
            else 
            return 0;
        }
        else if(numberoffilled ==3){
            if((newroom.topleft.x> 3 + rooms[1].topright.x) && (newroom.topleft.y > 3) && (newroom.topright.x <COLS-1) ){
                return 1;
            }
            else
            return 0;
        }
        else if(numberoffilled ==4){
            if((newroom.topleft.y> 3 + rooms[0].bottomleft.y) && (newroom.bottomleft.y<  LINES -2)){
                return 1;
            }
            else
            return 0;
        }
        else if(numberoffilled ==5){
            if((newroom.topleft.x> 3 + rooms[3].topright.x) && (newroom.topleft.y> 3 + rooms[1].bottomleft.y)&& (newroom.bottomleft.y<  LINES -2)){
                return 1;
            }
            else
            return 0;
        }
        else if(numberoffilled ==6){
            if((newroom.topleft.x> 3 + rooms[4].topright.x) && (newroom.topleft.y> 3 + rooms[2].bottomleft.y)&& (newroom.bottomleft.y<  LINES -2)&& (newroom.topright.x <COLS-1)){
                return 1;
            }
            else
            return 0;
        }
    //while((i+1< numberoffilled)){
        // if(((newroom.topright.x + 4 < rooms[i].topleft.x) || (newroom.topleft.x >  4+ rooms[i].topright.x) || (newroom.bottomleft.y  + 4< rooms[i].topleft.y) || (newroom.topleft.y >  4+rooms[i].bottomleft.y)) && (newroom.bottomleft.y < LINES -2 ) && (newroom.topleft.y>4)){
        //     i++;
        // }
        // else{
        //     return 0;
        // }
    //}
    // return valid;
}

void makerandomroom(room rooms[], int numberofrooms, position* player, int level){
    int numberoffilled =0;
    int numberofattemps =0;
    int i =0;
   while(i< numberofrooms){

        rooms[i].topleft.x = rand() %( maxx - 17);
        if(i ==0 || i ==1 || i ==2 ){
            rooms[i].topleft.x = 6 +(COLS/3 + 3) * i + rooms[i].topleft.x %(COLS/3 - 20);
        }
        else{
            rooms[i].topleft.x =6 + (COLS/3 + 3)*(i -3) + rooms[i].topleft.x %(COLS/3 - 20);
        }
        rooms[i].topright.x = rooms[i].topleft.x + 9 + (rand() %6);
        rooms[i].bottomleft.x = rooms[i].topleft.x;
        rooms[i].bottomright.x = rooms[i].topright.x;
        rooms[i].topleft.y =  rand() % (maxy -17);
        if(i ==0 || i ==1 || i ==2 ){
            rooms[i].topleft.y = 4  + rooms[i].topleft.x %6;
        }
        else{
            rooms[i].topleft.y = LINES/2 + 4 + rooms[i].topleft.x %6;
        }
        rooms[i].topright.y = rooms[i].topleft.y;
        rooms[i].bottomleft.y = rooms[i].topleft.y + 9 + (rand() %6 );
        rooms[i].bottomright.y = rooms[i].bottomleft.y;
        numberoffilled++;
        if(isroomvalid(rooms[i], rooms, numberoffilled)){
            i++;
        }
        else{
            initializerooms(&(rooms[i]));
            if(numberofattemps == 40){
                initializerooms(&(rooms[i -1]));
                i--;
                numberoffilled -=2;
                numberofattemps =0;
            }
            else{
                numberoffilled--;
                numberofattemps++;
            }
            

        }
        if(level ==0){
        player->x = rooms[0].topleft.x + 1;
        player->y = rooms[0].topleft.y + 1;}
 
    }
}

void clearmessage(){
    mvprintw(1,middle_x - 10, "                            ");
    refresh();
}

void printmessage(int hittype, int fire, int invalidcommand, int newlevel, int monshp){
    if(invalidcommand == 1){
        attron(COLOR_PAIR(1) | A_BOLD);
        mvprintw(1,middle_x - 8 , "Invalid command");
        refresh();
        attroff(COLOR_PAIR(1) | A_BOLD);}
    else{
        clearmessage();
        if(hittype == 2){

        attron(COLOR_PAIR(1) | A_BOLD);
        if(monshp <=0)
        mvprintw(0,middle_x - 10, "You killed the monster");
        else
        mvprintw(0,middle_x - 10, "You hit the monster! HP: %d", monshp);
        refresh();
        attroff(COLOR_PAIR(1) | A_BOLD);
        hittype =0;
    }
     else if(hittype == 1){
        attron(COLOR_PAIR(1) | A_BOLD);
        mvprintw(0,middle_x - 12 , "The monster hit you hard!");
        refresh();
        attroff(COLOR_PAIR(1) | A_BOLD);
        hittype =0;
    }
    else if(fire == 1){
        attron(COLOR_PAIR(1) | A_BOLD);
        mvprintw(0,middle_x -11, "You picked up a weapon");
        refresh();
        attroff(COLOR_PAIR(1) | A_BOLD);
        fire =0;
    }
    else if(fire == 2){
        attron(COLOR_PAIR(1) | A_BOLD);
        mvprintw(0,middle_x-6, "You picked up a spell");
        refresh();
        attroff(COLOR_PAIR(1) | A_BOLD);
    }}
}

void startmusic(int number){
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 512);
if(number ==0){
    Mix_Music *music = Mix_LoadMUS("./rockstar.mp3");
    Mix_PlayMusic(music, -1);
}
else if(number ==1){
    Mix_Music *music = Mix_LoadMUS("./loseyourself.mp3");
    Mix_PlayMusic(music, -1);
}
else if(number == 2){
    Mix_Music *music = Mix_LoadMUS("./comf.mp3");
    Mix_PlayMusic(music, -1);
}
else if(number == 3){
    Mix_Music *music = Mix_LoadMUS("./sweet.mp3");
    Mix_PlayMusic(music, -1);
}
else if(number == 4){
    Mix_Music *music = Mix_LoadMUS("./add.mp3");
    Mix_PlayMusic(music, -1);
}
else if(number == 5){
    Mix_Music *music = Mix_LoadMUS("./in.mp3");
    Mix_PlayMusic(music, -1);
}
else if(number == 6){
    Mix_Music *music = Mix_LoadMUS("./moon.mp3");
    Mix_PlayMusic(music, -1);
}
else if(number == 7){
    Mix_Music *music = Mix_LoadMUS("./weare.mp3");
    Mix_PlayMusic(music, -1);
}
else if(number == 8){
    Mix_Music *music = Mix_LoadMUS("./thumb.mp3");
    Mix_PlayMusic(music, -1);
}
else if(number == 10){
    Mix_Music *music = Mix_LoadMUS("./rains.mp3");
    Mix_PlayMusic(music, -1);
}

}

void makemap(char map[maxx + 1][maxy + 1], room rooms[], int numberofrooms, position player, int level){
    int firstpillar = rand() % 5;
    int secondpillar = firstpillar + 3;
    int thirdpillar = firstpillar +2;
    for(int i =0; i<6; i++){
        rooms[i].theme = Regular;
        rooms[i].monsnum =0;
    }
    if(level == 0){
    rooms[0].isvisible = 1;
    rooms[1].isvisible =0;
    rooms[2].isvisible = 0;
    rooms[3].isvisible = 0;
    rooms[4].isvisible = 0;
    rooms[5].isvisible = 0;}
    else if(level ==1){
          rooms[0].isvisible = 0;
    rooms[1].isvisible =0;
    rooms[2].isvisible = 0;
    rooms[3].isvisible = 0;
    rooms[4].isvisible = 0;
    rooms[5].isvisible = 1;
    }
    else if(level ==2){
          rooms[0].isvisible = 0;
    rooms[1].isvisible =0;
    rooms[2].isvisible = 1;
    rooms[3].isvisible = 0;
    rooms[4].isvisible = 0;
    rooms[5].isvisible = 0;
    }
    else if(level ==3){
          rooms[0].isvisible = 0;
    rooms[1].isvisible =0;
    rooms[2].isvisible = 0;
    rooms[3].isvisible = 1;
    rooms[4].isvisible = 0;
    rooms[5].isvisible = 0;
    }
    for(int i =0; i< numberofrooms; i++){
        rooms[i].door[0].x = rooms[i].bottomleft.x ;
        rooms[i].door[0].y = rooms[i].topleft.y  + 2 + rand() % 4;
        rooms[i].door[1].x = rooms[i].bottomright.x;
        rooms[i].door[1].y = rooms[i].topright.y + 2 + rand() % 4; 
        rooms[i].door[2].x = rooms[i].bottomleft.x + 2 + rand() % 4;;
        rooms[i].door[2].y = rooms[i].bottomleft.y ;
        rooms[i].door[3].x = rooms[i].bottomleft.x + 2 + rand() % 4;;
        rooms[i].door[3].y = rooms[i].topleft.y ;

        for(int j = rooms[i].bottomleft.x + 1; j<rooms[i].bottomright.x; j++){
            map[j][rooms[i].bottomleft.y] = '_';
            map[j][rooms[i].topleft.y] = '_';
        }
        for(int j =rooms[i].topright.y+1; j<rooms[i].bottomright.y; j++){
            map[rooms[i].topleft.x][j] = '|';
            map[rooms[i].topright.x][j] = '|';
        }
        for(int k = rooms[i].bottomleft.x + 1; k<rooms[i].bottomright.x; k++ ){
        for(int j =rooms[i].topleft.y +1; j<rooms[i].bottomleft.y; j++){
            map[k][j] = '.';
        }
        
        if(i == 0 ){
            map[ rooms[i].door[1].x ][rooms[i].door[1].y] ='+';
            map[ rooms[i].door[2].x ][rooms[i].door[2].y] ='+';
            rooms[i].player =1;
        }
        else if(i == 1){
            map[ rooms[i].door[1].x ][rooms[i].door[1].y] ='+';
            int hidden = rand() %10;
            if((hidden == 1) || (hidden == 4) ||(hidden == 6) || (hidden ==7)){
                map[ rooms[i].door[1].x ][rooms[i].door[1].y] ='?';
                rooms[i].ishiddend =1;
                rooms[2].theme = Enchant;
            }
            map[ rooms[i].door[0].x ][rooms[i].door[0].y] ='+';
            map[ rooms[i].door[2].x ][rooms[i].door[2].y] ='+';
        }
        else if(i== 2){
            map[ rooms[i].door[0].x ][rooms[i].door[0].y] ='+';
        }
        else if(i ==4){
              map[ rooms[i].door[1].x ][rooms[i].door[1].y] ='+';
              int hidden = rand() %10;
            if((hidden == 1) || (hidden == 4) ||(hidden == 6) || (hidden == 7)){
                map[ rooms[i].door[1].x ][rooms[i].door[1].y] ='?';
                rooms[i].ishiddend = 1;
                rooms[5].theme = Enchant;
            }
            map[ rooms[i].door[0].x ][rooms[i].door[0].y] ='+';
            map[ rooms[i].door[3].x ][rooms[i].door[3].y] ='+';
        }
        else if(i == 5){
            map[ rooms[i].door[0].x ][rooms[i].door[0].y] ='+';
        }
        else if(i == 3){
            map[ rooms[i].door[3].x ][rooms[i].door[3].y] ='+';
        map[ rooms[i].door[1].x ][rooms[i].door[1].y] = '+';
        }
        }
        rooms[i].islocked =-1;
        
    }

    if(level == 3){
        for(int i =0; i<6; i++){
            int theme = rand() % 10;
            if((theme == 5) || (theme ==6) || (theme ==1)){
                if(rooms[i].theme == Regular){
                rooms[i].theme = Nightmare;
                rooms[i].isvisible =0;}
            }
        }
        int troom = rand() % 6;
        if(troom == 3)
        troom++;
        rooms[troom].theme = Treasure;
        rooms[troom].istrap =1;
                rooms[troom].trap[0].x = rooms[troom].bottomright.x -3 - (rand()%2);
                rooms[troom].trap[0].y = rooms[troom].bottomleft.y - 3 - (rand() %2);
                rooms[troom].trap[1].x = rooms[troom].bottomleft.x + 3 + rand()%2;
                rooms[troom].trap[1].y = rooms[troom].topleft.y + 3 + rand() %2;
                rooms[troom].trap[2].x = rooms[troom].bottomright.x -(rand() %2) - 3;
                 rooms[troom].trap[2].y = rooms[troom].bottomleft.y - 3 - (rand() %3);
                 rooms[troom].trap[3].x = rooms[troom].bottomleft.x +( rand() %2) + 2;
                 rooms[troom].trap[3].y = rooms[troom].bottomleft.y - 3 -(rand() %2) ;
                map[rooms[troom].bottomleft.x + 1][rooms[troom].topleft.y + 1] = 'E';
    }
    else{
           for(int i =0; i<6; i++){
            int theme = rand() % 10;
            if(((theme == 5) || (theme ==6)|| (theme ==1) ) && (rooms[i].theme == Regular)){
                rooms[i].theme = Nightmare;
                rooms[i].isvisible=0;
            }

        }
    }


    int ancient = rand() % 6;
    int ancientx = rooms[ancient].bottomleft.x + rand() %6 + 1;
    int ancienty = rooms[ancient].bottomleft.y - 1 - rand() % 6;
    if(map[ancientx][ancienty] == '.')
    map[ancientx][ancienty] = 'd';
     int lock = rand() % 3;
        if( (lock == 1) || (lock == 2)){
            if(level == 1){
                rooms[1].islocked = 1;
                map[rooms[1].door[1].x][rooms[1].door[1].y] = '@';
                map[rooms[1].bottomleft.x + 1][rooms[1].bottomleft.y - 1] = '&';
            }
            else if (level == 0){
                rooms[4].islocked = 1;
                map[rooms[4].door[1].x][rooms[4].door[1].y] = '@';
                map[rooms[4].bottomright.x - 1][rooms[4].bottomleft.y - 1] = '&';
            }
            else if (level == 2){
                rooms[4].islocked = 1;
                map[rooms[4].door[0].x][rooms[4].door[0].y] = '@';
                map[rooms[4].bottomleft.x + 1][rooms[4].bottomleft.y - 1] = '&';
                map[rooms[4].bottomright.x - 1][rooms[4].bottomright.y - 1] = '&';
                
            }
            else if (level == 3){
                rooms[3].islocked = 1;
                map[rooms[3].door[3].x][rooms[3].door[3].y] = '@';
                map[rooms[3].bottomleft.x + 1][rooms[3].topleft.y + 1] = '&';
                 map[rooms[3].bottomright.x - 1][rooms[3].topright.y + 1] = '&';
            }
        }
    
    int firstwindow = rand() % 3;
    int secondwindow = firstwindow + 2;
       rooms[firstwindow].window.x = rooms[firstwindow].bottomleft.x + 2 + rand() % 4;
        rooms[firstwindow].window.y = rooms[firstwindow].bottomright.y;
        if(map[rooms[firstwindow].window.x ][rooms[firstwindow].window.y ] == '_'){
            rooms[firstwindow].iswindow =1;
        map[rooms[firstwindow].window.x ][rooms[firstwindow].window.y ] = '=';}
        else{
            rooms[firstwindow].iswindow =0;
            rooms[firstwindow].window.x = 0;
             rooms[firstwindow].window.y = rooms[firstwindow].bottomright.y;
        }
        rooms[secondwindow].window.x = rooms[secondwindow].bottomleft.x + 2 + rand() % 4;
        rooms[secondwindow].window.y = rooms[secondwindow].bottomright.y;
        if(map[rooms[secondwindow].window.x ][rooms[secondwindow].window.y ] == '_'){
            rooms[secondwindow].iswindow =1;
        map[rooms[secondwindow].window.x ][rooms[secondwindow].window.y ] = '=';}
        else{
            rooms[secondwindow].iswindow =0;
            rooms[secondwindow].window.x = 0;
             rooms[secondwindow].window.y = rooms[secondwindow].bottomright.y;
        }
        
        if(level ==0){
            map[rooms[5].bottomright.x - 1][rooms[5].bottomright.y -1 ] = '<';
        }
        else if(level == 1){
            map[rooms[5].bottomright.x - 1][rooms[5].bottomright.y -1 ] = '<';
            map[rooms[2].topleft.x + 1][rooms[2].topleft.y +1 ] = '<';
        }
        else if(level == 2){
            map[rooms[2].topleft.x + 1][rooms[2].topleft.y +1 ] = '<';
            rooms[2].theme = Enchant;
            map[rooms[3].bottomleft.x + 1][rooms[3].bottomleft.y -1 ] = '<';
        }
        else if(level == 3){
            rooms[3].theme = Enchant;
            map[rooms[3].bottomleft.x + 1][rooms[3].bottomleft.y -1 ] = '<';
        }

        for(int i =0; i<6; i++){
            
            if(rooms[i].theme == Regular){
                int isgold = rand() %5;
                if(isgold <3){
                position gold;
                gold.x = rooms[i].bottomleft.x + 2 + rand() % 3;
                gold.y = rooms[i].topleft.y + 2 + rand() % 3;
                if(map[gold.x][gold.y] == '.'){
                    map[gold.x][gold.y] = '$';
                    rooms[i].goldamount =1 + rand() % 5;
                }}

                if(isgold == 4){
                    position gold;
                gold.x = rooms[i].bottomleft.x + 4 + rand() % 3;
                gold.y = rooms[i].topleft.y + 4 + rand() % 3;
                if(map[gold.x][gold.y] == '.'){
                    map[gold.x][gold.y] = 'b';
                    rooms[i].goldamount =20 + rand() % 5;
                }
                }
                int istrap = rand() %3;
                if(istrap){
                    position traps[2];
                    traps[0].x= rooms[i].bottomleft.x + 3 + rand()%6;
                    traps[0].y = rooms[i].topleft.y + 3 + rand() % 6;
                     traps[1].x= rooms[i].bottomleft.x + 5 + rand()%6;
                    traps[1].y = rooms[i].topleft.y + 5 + rand() % 6;
                    
                    if((map[traps[0].x][traps[0].y] == '.') && (map[traps[1].x][traps[1].y] == '.')){
                    rooms[i].istrap = 1;
                    for(int j =0; j<2; j++){
                        rooms[i].trap[j].x = traps[j].x;
                        rooms[i].trap[j].y = traps[j].y;
                    }
                    }


                }

                int ismons = rand()%4;
                if(ismons && (!((i == 0) && (level ==0)))){
                    if(ismons){
                    int monsx = rooms[i].bottomleft.x + 1 + rand() % 5;
                    int monsy = rooms[i].topleft.y + 1 + rand() % 5;
                    if(map[monsx][monsy] == '.'){
                        rooms[i].mons[0].kind = DEAMON;
                        rooms[i].mons[0].hp = 5;
                        rooms[i].mons[0].pos.x = monsx;
                        rooms[i].mons[0].pos.y = monsy;
                        rooms[i].monsnum =1;
                        map[monsx][monsy] = 'D';
                    }}
                     else if(ismons == 2){
                     int monsx = rooms[i].bottomleft.x + 1 + rand() % 5;
                     int monsy = rooms[i].topleft.y + 1 + rand() % 5;
                    if(map[monsx][monsy] == '.'){
                        rooms[i].mons[0].kind = FIRE;
                        rooms[i].mons[0].hp = 10;
                        rooms[i].mons[0].pos.x = monsx;
                        rooms[i].mons[0].pos.y = monsy;
                        rooms[i].monsnum =1;
                        map[monsx][monsy] = 'F';
                    }}
                     else if(ismons == 3){
                     int monsx = rooms[i].bottomleft.x + 1 + rand() % 5;
                     int monsy = rooms[i].topleft.y + 1 + rand() % 5;
                    if(map[monsx][monsy] == '.'){
                        rooms[i].mons[0].kind = GIANT;
                        rooms[i].mons[0].hp = 15;
                        rooms[i].mons[0].pos.x = monsx;
                        rooms[i].mons[0].pos.y = monsy;
                        rooms[i].monsnum =1;
                        map[monsx][monsy] = 'G';
                    }}
                }

            }
             
             else if(rooms[i].theme == Nightmare){
                int isgold = rand() %5;
                if(1){
                position gold;
                gold.x = rooms[i].bottomleft.x + 3 + rand() % 3;
                gold.y = rooms[i].topleft.y + 4 + rand() % 3;
                if(map[gold.x][gold.y] == '.'){
                    map[gold.x][gold.y] = '$';
                    rooms[i].goldamount =0;
                }
                }

                int istrap = rand() %3;
                if(istrap){
                    position traps[2];
                    traps[0].x= rooms[i].bottomleft.x + 3 + rand()%6;
                    traps[0].y = rooms[i].topleft.y + 3 + rand() % 6;
                     traps[1].x= rooms[i].bottomleft.x + 5 + rand()%6;
                    traps[1].y = rooms[i].topleft.y + 5 + rand() % 6;
                    
                    if((map[traps[0].x][traps[0].y] == '.') && (map[traps[1].x][traps[1].y] == '.')){
                    rooms[i].istrap = 1;
                    for(int j =0; j<2; j++){
                        rooms[i].trap[j].x = traps[j].x;
                        rooms[i].trap[j].y = traps[j].y;
                    }
                    }
                            
            }
            

                int ismons = rand()%4;
                if(ismons &&(!((i == 0) && (level ==0)))){
                    if(ismons){
                    int monsx = rooms[i].bottomleft.x + 1 + rand() % 5;
                    int monsy = rooms[i].topleft.y + 1 + rand() % 5;
                    if(map[monsx][monsy] == '.'){
                        rooms[i].mons[rooms[i].monsnum].kind = DEAMON;
                        rooms[i].mons[rooms[i].monsnum].hp = 5;
                        rooms[i].mons[rooms[i].monsnum].pos.x = monsx;
                        rooms[i].mons[rooms[i].monsnum].pos.y = monsy;
                        rooms[i].monsnum++;
                        map[monsx][monsy] = 'D';
                    }}
                      if(ismons >=2){
                     int monsx = rooms[i].bottomleft.x + 1 + rand() % 5;
                     int monsy = rooms[i].topleft.y + 1 + rand() % 5;
                    if(map[monsx][monsy] == '.'){
                        rooms[i].mons[rooms[i].monsnum].kind = FIRE;
                        rooms[i].mons[rooms[i].monsnum].hp = 10;
                        rooms[i].mons[rooms[i].monsnum].pos.x = monsx;
                        rooms[i].mons[rooms[i].monsnum].pos.y = monsy;
                        rooms[i].monsnum++;
                        map[monsx][monsy] = 'F';
                    }}
                      if(ismons == 3){
                     int monsx = rooms[i].bottomleft.x + 1 + rand() % 5;
                     int monsy = rooms[i].topleft.y + 1 + rand() % 5;
                    if(map[monsx][monsy] == '.'){
                        rooms[i].mons[rooms[i].monsnum].kind = GIANT;
                        rooms[i].mons[rooms[i].monsnum].hp = 15;
                        rooms[i].mons[rooms[i].monsnum].pos.x = monsx;
                        rooms[i].mons[rooms[i].monsnum].pos.y = monsy;
                        rooms[i].monsnum++;
                        map[monsx][monsy] = 'G';
                    }}
                }

            }

            else if(rooms[i].theme == Enchant){
                int isgold = rand() %5;
                if((isgold<4) && (isgold !=1)){
                position gold;
                gold.x = rooms[i].bottomleft.x + 5 + rand() % 3;
                gold.y = rooms[i].topleft.y + 5 + rand() % 4;
                if(map[gold.x][gold.y] == '.'){
                    map[gold.x][gold.y] = '$';
                    rooms[i].goldamount = 5 + rand() % 6;
                }
                }

                if((isgold == 4) || (isgold ==  1)){
                    position gold;
                gold.x = rooms[i].bottomleft.x + 2 + rand() % 3;
                gold.y = rooms[i].topleft.y + 2 + rand() % 3;
                if(map[gold.x][gold.y] == '.'){
                    map[gold.x][gold.y] = 'b';
                    rooms[i].goldamount =30 + rand() % 15;
                }}

                
                if(1){
                position spell1;
                spell1.x = rooms[i].bottomleft.x + 6 + rand()%5;
                spell1.y = rooms[i].topleft.y + 2 + rand() % 4;
                if(map[spell1.x][spell1.y] == '.'){
                    int type = rand()%3 +'6';
                    map[spell1.x][spell1.y] = type;
                }}
                   
                
                if(1){
                  position spell2;
                spell2.x = rooms[i].bottomleft.x + 3 + rand() % 7;
                spell2.y = rooms[i].topleft.y + 6 + rand() % 5;
                if(map[spell2.x][spell2.y] == '.'){
                    int type = rand()%3 +'6';
                    map[spell2.x][spell2.y] = type;
                }    
                }

                if(1){
                     position spell3;
                spell3.x = rooms[i].bottomleft.x + 4 + rand() % 6;
                spell3.y = rooms[i].topleft.y + 7 + rand() % 2;
                if(map[spell3.x][spell3.y] == '.'){
                    int type = rand()%3 +'6';
                    map[spell3.x][spell3.y] = type;
                } 
                }
        
                int istrap = rand() %3;
                if(istrap){
                    position traps[2];
                    traps[0].x= rooms[i].bottomleft.x + 5 + rand()%6;
                    traps[0].y = rooms[i].topleft.y + 4 + rand() % 6;
                     traps[1].x= rooms[i].bottomleft.x + 2 + rand()%6;
                    traps[1].y = rooms[i].topleft.y + 2 + rand() % 6;
                    
                    if((map[traps[0].x][traps[0].y] == '.') && (map[traps[1].x][traps[1].y] == '.')){
                    rooms[i].istrap = 1;
                    for(int j =0; j<2; j++){
                        rooms[i].trap[j].x = traps[j].x;
                        rooms[i].trap[j].y = traps[j].y;
                    }
                    }  
            }

             int ismons = rand()%4;
                if(ismons){
                    if(ismons&&(!((i == 0) && (level ==0)))){
                    int monsx = rooms[i].bottomleft.x + 1 + rand() % 5;
                    int monsy = rooms[i].topleft.y + 1 + rand() % 5;
                    if(map[monsx][monsy] == '.'){
                        rooms[i].mons[0].kind = SNAKE;
                        rooms[i].mons[0].hp = 20;
                        rooms[i].mons[0].pos.x = monsx;
                        rooms[i].mons[0].pos.y = monsy;
                        rooms[i].monsnum++;
                        map[monsx][monsy] = 'S';
                    }}
                    if(ismons){
                    int monsx = rooms[i].bottomleft.x + 1 + rand() % 6;
                    int monsy = rooms[i].topleft.y + 1 + rand() % 6;
                    if(map[monsx][monsy] == '.'){
                        rooms[i].mons[rooms[i].monsnum].kind = DEAMON;
                        rooms[i].mons[rooms[i].monsnum].hp = 20;
                        rooms[i].mons[rooms[i].monsnum].pos.x = monsx;
                        rooms[i].mons[rooms[i].monsnum].pos.y = monsy;
                        rooms[i].monsnum++;
                        map[monsx][monsy] = 'D';
                    }}
                      if(ismons >=2){
                     int monsx = rooms[i].bottomleft.x + 1 + rand() % 5;
                     int monsy = rooms[i].topleft.y + 1 + rand() % 5;
                    if(map[monsx][monsy] == '.'){
                        rooms[i].mons[rooms[i].monsnum].kind = UNDEED;
                        rooms[i].mons[rooms[i].monsnum].hp = 30;
                        rooms[i].mons[rooms[i].monsnum].pos.x = monsx;
                        rooms[i].mons[rooms[i].monsnum].pos.y = monsy;
                        rooms[i].monsnum++;
                        map[monsx][monsy] = 'U';
                    }}
                      if(ismons == 3){
                     int monsx = rooms[i].bottomleft.x + 1 + rand() % 5;
                     int monsy = rooms[i].topleft.y + 1 + rand() % 5;
                    if(map[monsx][monsy] == '.'){
                        rooms[i].mons[rooms[i].monsnum].kind = GIANT;
                        rooms[i].mons[rooms[i].monsnum].hp = 15;
                        rooms[i].mons[rooms[i].monsnum].pos.x = monsx;
                        rooms[i].mons[rooms[i].monsnum].pos.y = monsy;
                        rooms[i].monsnum++;
                        map[monsx][monsy] = 'G';
                    }}
                }
            
            }
            
            else if(rooms[i].theme == Treasure){
                int isgold = rand() %6;
                if(1){
                position gold;
                gold.x = rooms[i].bottomleft.x + 6 + rand() % 2;
                gold.y = rooms[i].topleft.y + 4 + rand() % 5;
                if(map[gold.x][gold.y] == '.'){
                    map[gold.x][gold.y] = '$';
                    rooms[i].goldamount = 20 + rand() % 6;
                }                
                }

                if(1){
                    position gold;
                gold.x = rooms[i].bottomleft.x + 3 + rand() % 4;
                gold.y = rooms[i].topleft.y + 7 + rand() % 3;
                if(map[gold.x][gold.y] == '.'){
                    map[gold.x][gold.y] = 'b';
                    rooms[i].goldamount =50 + rand() % 15;
                }
                }
                 
                 int ismons = rand()%4;
                 for(int k =0; k<6;k++){
                    rooms[i].mons[k].hp = 0;
                 }
                if(1){
                    if(1){
                    int monsx = rooms[i].bottomleft.x + 1 + rand() % 5;
                    int monsy = rooms[i].topleft.y + 1 + rand() % 5;
                    if(map[monsx][monsy] == '.'){
                        rooms[i].mons[0].kind = SNAKE;
                        rooms[i].mons[0].hp = 20;
                        rooms[i].mons[0].pos.x = monsx;
                        rooms[i].mons[0].pos.y = monsy;
                        rooms[i].monsnum++;
                        map[monsx][monsy] = 'S';
                    }}
                    if(1){
                    int monsx = rooms[i].bottomleft.x + 1 + rand() % 7;
                    int monsy = rooms[i].topleft.y + 1 + rand() % 7;
                    if(map[monsx][monsy] == '.'){
                        rooms[i].mons[rooms[i].monsnum].kind = SNAKE;
                        rooms[i].mons[rooms[i].monsnum].hp = 20;
                        rooms[i].mons[rooms[i].monsnum].pos.x = monsx;
                        rooms[i].mons[rooms[i].monsnum].pos.y = monsy;
                        rooms[i].monsnum++;
                        map[monsx][monsy] = 'S';
                    }}
                    if(1){
                    int monsx = rooms[i].bottomleft.x + 1 + rand() % 7;
                    int monsy = rooms[i].topleft.y + 1 + rand() % 7;
                    if(map[monsx][monsy] == '.'){
                        rooms[i].mons[rooms[i].monsnum].kind = FIRE;
                        rooms[i].mons[rooms[i].monsnum].hp = 20;
                        rooms[i].mons[rooms[i].monsnum].pos.x = monsx;
                        rooms[i].mons[rooms[i].monsnum].pos.y = monsy;
                        rooms[i].monsnum++;
                        map[monsx][monsy] = 'F';
                    }}
                      if(1){
                     int monsx = rooms[i].bottomleft.x + 1 + rand() % 7;
                     int monsy = rooms[i].topleft.y + 1 + rand() % 7;
                    if(map[monsx][monsy] == '.'){
                        rooms[i].mons[rooms[i].monsnum].kind = UNDEED;
                        rooms[i].mons[rooms[i].monsnum].hp = 30;
                        rooms[i].mons[rooms[i].monsnum].pos.x = monsx;
                        rooms[i].mons[rooms[i].monsnum].pos.y = monsy;
                        rooms[i].monsnum++;
                        map[monsx][monsy] = 'U';
                    }}
                      if(1){
                     int monsx = rooms[i].bottomleft.x + 1 + rand() % 7;
                     int monsy = rooms[i].topleft.y + 1 + rand() % 7;
                    if(map[monsx][monsy] == '.'){
                        rooms[i].mons[rooms[i].monsnum].kind = GIANT;
                        rooms[i].mons[rooms[i].monsnum].hp = 15;
                        rooms[i].mons[rooms[i].monsnum].pos.x = monsx;
                        rooms[i].mons[rooms[i].monsnum].pos.y = monsy;
                        rooms[i].monsnum++;
                        map[monsx][monsy] = 'G';
                    }}
                    if(ismons <= 2){
                     int monsx = rooms[i].bottomleft.x + 1 + rand() % 7;
                     int monsy = rooms[i].topleft.y + 1 + rand() % 7;
                    if(map[monsx][monsy] == '.'){
                        rooms[i].mons[rooms[i].monsnum].kind = SNAKE;
                        rooms[i].mons[rooms[i].monsnum].hp = 20;
                        rooms[i].mons[rooms[i].monsnum].pos.x = monsx;
                        rooms[i].mons[rooms[i].monsnum].pos.y = monsy;
                        rooms[i].monsnum++;
                        map[monsx][monsy] = 'S';
                    }}
                }

                map[rooms[i].bottomleft.x + 1][rooms[i].topleft.y + 1] = 'E';
            }
        

if((i == firstpillar) || (i == secondpillar) || (i == thirdpillar) || (i == 5) || (i ==2)){
    int randompillar = rand() % 5;
                if(map[rooms[i].bottomleft.x + 2 + randompillar][rooms[i].topleft.y +2 + randompillar] == '.')
                map[rooms[i].bottomleft.x + 2 + randompillar][rooms[i].topleft.y +2 + randompillar] = 'O';
            }
        
        int isfood = rand() %5;
                if(isfood <3){
                position foodi;
                foodi.x = rooms[i].bottomleft.x + 2 + rand() % 3;
                foodi.y = rooms[i].topleft.y + 2 + rand() % 3;
                if(map[foodi.x][foodi.y] == '.'){
                    if(isfood ==0)
                    map[foodi.x][foodi.y] = 'f';
                    else if(isfood == 1)
                    map[foodi.x][foodi.y] = 'L';
                    else if(isfood == 2)
                    map[foodi.x][foodi.y] = 'J';

                }
                
                            
                }
                if(isfood == 3){
                  position foodi;
                foodi.x = rooms[i].bottomleft.x + 6 + rand() % 3;
                foodi.y = rooms[i].topleft.y + 7 + rand() % 3;
                if(map[foodi.x][foodi.y] == '.'){
                    map[foodi.x][foodi.y] = 'I';
                }    
                }

int isweapon = rand() % 5;
 if(isweapon <3){
                position weaponi;
                weaponi.x = rooms[i].bottomleft.x + 4 + rand() % 3;
                weaponi.y = rooms[i].topleft.y + 4 + rand() % 3;
                if(map[weaponi.x][weaponi.y] == '.'){
                    int type = rand()%5 +'2';
                    map[weaponi.x][weaponi.y] = type;
                }            
                }
                if(isweapon == 1){
                  position weaponi;
                weaponi.x = rooms[i].bottomleft.x + 5 + rand() % 6;
                weaponi.y = rooms[i].topleft.y + 5 + rand() % 6;
                if(map[weaponi.x][weaponi.y] == '.'){
                    int type = rand()%5 +'2';
                    map[weaponi.x][weaponi.y] = type;
                }    
                }

                int isspell = rand() % 5;
 if(isspell <3){
                position spell4;
                spell4.x = rooms[i].bottomleft.x + 7 + rand() % 3;
                spell4.y = rooms[i].topleft.y + 4 + rand() % 3;
                if(map[spell4.x][spell4.y] == '.'){
                    int type = rand()%3 +'6';
                    map[spell4.x][spell4.y] = type;
                }            
                }
                if(isspell == 1){
                  position spell5;
                spell5.x = rooms[i].bottomleft.x + 6 + rand() % 3;
                spell5.y = rooms[i].topleft.y + 2 + rand() % 8;
                if(map[spell5.x][spell5.y] == '.'){
                    int type = rand()%3 +'6';
                    map[spell5.x][spell5.y] = type;
                }    
                }
}

}

void makecorridor(char map[maxx + 1][maxy + 1], room rooms[], int numberofrooms){
            if(rooms[0].door[1].y >= rooms[1].door[0].y){
                map[rooms[0].door[1].x + 1][rooms[0].door[1].y] ='#';

                for(int j =rooms[0].door[1].y  ; j>=rooms[1].door[0].y; j--){
                    map[rooms[0].door[1].x + 2][j] ='#';
                }
                for(int j =rooms[0].door[1].x + 2; j<rooms[1].door[0].x; j++){
                    map[j][rooms[1].door[0].y] ='#';

                }
            }
            else{
                map[rooms[0].door[1].x + 1][rooms[0].door[1].y] ='#';
                for(int j =rooms[1].door[0].y  ; j>=rooms[0].door[1].y; j--){
                    map[rooms[0].door[1].x + 2][j] ='#';
                }
                for(int j =rooms[0].door[1].x + 2; j<rooms[1].door[0].x; j++){
                    map[j][rooms[1].door[0].y] ='#';

                }
            }
            if(rooms[0].door[2].x >= rooms[3].door[3].x){
                map[rooms[0].door[2].x ][rooms[0].door[2].y + 1] ='#';
                for(int j =rooms[0].door[2].x  ; j>=rooms[3].door[3].x; j--){
                    map[j][rooms[0].door[2].y + 2] ='#';
                }
                for(int j =rooms[0].door[2].y + 2; j<rooms[3].door[3].y; j++){
                    map[rooms[3].door[3].x][j] ='#';

                }
            }
            else{
                 map[rooms[0].door[2].x ][rooms[0].door[2].y + 1] ='#';
                for(int j =rooms[3].door[3].x  ; j>=rooms[0].door[2].x; j--){
                    map[j][rooms[0].door[2].y + 2] ='#';
                }
                for(int j =rooms[0].door[2].y + 2; j<rooms[3].door[3].y; j++){
                    map[rooms[3].door[3].x][j] ='#';

                }
            }
            if(rooms[1].door[1].y >= rooms[2].door[0].y){
             map[rooms[1].door[1].x +1 ][rooms[1].door[1].y] ='#';
                for(int j =rooms[1].door[1].y  ; j>=rooms[2].door[0].y; j--){
                    map[rooms[1].door[1].x + 2][j] ='#';
                }
                for(int j =rooms[1].door[1].x + 2; j<rooms[2].door[0].x; j++){
                    map[j][rooms[2].door[0].y] ='#';

                }
            }
            else{
                map[rooms[1].door[1].x +1 ][rooms[1].door[1].y] ='#';
                for(int j =rooms[2].door[0].y  ; j>=rooms[1].door[1].y; j--){
                    map[rooms[1].door[1].x + 2][j] ='#';
                }
                for(int j =rooms[1].door[1].x + 2; j<rooms[2].door[0].x; j++){
                    map[j][rooms[2].door[0].y] ='#';

                }
            }
            if(rooms[1].door[2].x >= rooms[4].door[3].x){
                 map[rooms[1].door[2].x ][rooms[1].door[2].y + 1] ='#';
                for(int j =rooms[1].door[2].x  ; j>=rooms[4].door[3].x; j--){
                    map[j][rooms[1].door[2].y + 2] ='#';
                }
                for(int j =rooms[1].door[2].y + 2; j<rooms[4].door[3].y; j++){
                    map[rooms[4].door[3].x][j] ='#';

                }
            }
            else{
                  map[rooms[1].door[2].x ][rooms[1].door[2].y + 1] ='#';
                for(int j =rooms[4].door[3].x  ; j>=rooms[1].door[2].x; j--){
                    map[j][rooms[1].door[2].y + 2] ='#';
                }
                for(int j =rooms[1].door[2].y + 2; j<rooms[4].door[3].y; j++){
                    map[rooms[4].door[3].x][j] ='#';

                }
            }
            if(rooms[3].door[1].y>= rooms[4].door[0].y){
                map[rooms[3].door[1].x +1 ][rooms[3].door[1].y] ='#';
                for(int j =rooms[3].door[1].y  ; j>=rooms[4].door[0].y; j--){
                    map[rooms[3].door[1].x + 2][j] ='#';
                }
                for(int j =rooms[3].door[1].x + 2; j<rooms[4].door[0].x; j++){
                    map[j][rooms[4].door[0].y] ='#';

                }
            }
            else{
                map[rooms[3].door[1].x +1 ][rooms[3].door[1].y] ='#';
                for(int j =rooms[4].door[0].y  ; j>=rooms[3].door[1].y; j--){
                    map[rooms[3].door[1].x + 2][j] ='#';
                }
                for(int j =rooms[3].door[1].x + 2; j<rooms[4].door[0].x; j++){
                    map[j][rooms[4].door[0].y] ='#';

                }
            }
            if(rooms[4].door[1].y>= rooms[5].door[0].y){
              map[rooms[4].door[1].x +1 ][rooms[4].door[1].y] ='#';
                for(int j =rooms[4].door[1].y  ; j>=rooms[5].door[0].y; j--){
                    map[rooms[4].door[1].x + 2][j] ='#';
                }
                for(int j =rooms[4].door[1].x + 2; j<rooms[5].door[0].x; j++){
                    map[j][rooms[5].door[0].y] ='#';

                }
            }
            else{
                map[rooms[4].door[1].x +1 ][rooms[4].door[1].y] ='#';
                for(int j =rooms[5].door[0].y  ; j>=rooms[4].door[1].y; j--){
                    map[rooms[4].door[1].x + 2][j] ='#';
                }
                for(int j =rooms[4].door[1].x + 2; j<rooms[5].door[0].x; j++){
                    map[j][rooms[5].door[0].y] ='#';

                }
            }
            
        }

void starttheme(char map[maxx +1][maxy + 1], int x, int y, room rooms[], int level, int night){
    if(map[x][y] == '&')
    attron(COLOR_PAIR(4));
    else if((map[x][y] == '@') &&(rooms[4].islocked ==1) &&(level == 0))
    attron(COLOR_PAIR(1));
    else if((map[x][y] == '@') &&(rooms[4].islocked ==0) && (level ==0))
    attron(COLOR_PAIR(3));
    else if((map[x][y] == '@') &&(rooms[1].islocked ==1) && (level == 1))
    attron(COLOR_PAIR(1));
    else if((map[x][y] == '@') &&(rooms[1].islocked ==0) && (level == 1))
    attron(COLOR_PAIR(3));
    else if((map[x][y] == '@') &&(rooms[4].islocked >0) && (level == 2))
    attron(COLOR_PAIR(1));
    else if((map[x][y] == '@') &&(rooms[4].islocked ==0) && (level == 2))
    attron(COLOR_PAIR(3));
    else if((map[x][y] == '@') &&(rooms[3].islocked >0) && (level == 3))
    attron(COLOR_PAIR(1));
    else if((map[x][y] == '@') &&(rooms[3].islocked ==0) && (level == 3))
    attron(COLOR_PAIR(3));
    else if((map[x][y] == 'd') || (map[x][y] == '$'))
    attron(COLOR_PAIR(4));
    else if((map[x][y] == 'E'))
    attron(COLOR_PAIR(1));
    else if((map[x][y] == 'b'))
    attron(COLOR_PAIR(4));
    else if((map[x][y] == 'f') || (map[x][y] == 'I') || (map[x][y] == 'L')  || (map[x][y] == 'J') )
    attron(COLOR_PAIR(5));
    else if(((map[x][y] <= '5') && ((map[x][y] >= '1'))) || (map[x][y] == 'k') || (map[x][y] == 'a') ||(map[x][y] == 'm'))
    attron(COLOR_PAIR(4));
    else if(map[x][y] == '6')
    attron(COLOR_PAIR(1));
    else if(map[x][y] == '7')
    attron(COLOR_PAIR(2));
    else if(map[x][y] == '8')
    attron(COLOR_PAIR(3));
    else if(map[x][y] == '#')
    attron(COLOR_PAIR(6));
    else if(map[x][y] == 'D')
    attron(COLOR_PAIR(2));
    else if(map[x][y] == 'F')
    attron(COLOR_PAIR(5));
    else if(map[x][y] == 'G')
    attron(COLOR_PAIR(2));
    else if(map[x][y] == 'S')
    attron(COLOR_PAIR(3));
    else if(map[x][y] == 'U')
    attron(COLOR_PAIR(5));

    else{
        for(int i= 0; i<6; i++){
             if((x<=rooms[i].bottomright.x) && (x>=rooms[i].bottomleft.x) && (y>=rooms[i].topleft.y)  &&(y<=rooms[i].bottomleft.y) ){
        if((map[x][y] == '.') ||(map[x][y] == '_') || (map[x][y] == '|')  ){
        if(rooms[i].theme == Regular){
            attron(COLOR_PAIR(6));
        }
        else if(rooms[i].theme == Enchant){
            attron(COLOR_PAIR(1));
        }
        else if(rooms[i].theme == Nightmare){
            attron(COLOR_PAIR(3));
        }
        else if(rooms[i].theme == purgatory){
            attron(COLOR_PAIR(5));
        }
        else{
            attron(COLOR_PAIR(4));
        }

        }

        else if(((map[x][y] == '^')) || ((map[x][y] == 'O')) || ((map[x][y] == '+')) || ((map[x][y] == '?') && (night !=0)) ){
            if(rooms[i].theme == Regular){
            attron(COLOR_PAIR(1));
        }
        else if(rooms[i].theme == Enchant){
            attron(COLOR_PAIR(3));
        }
        else if(rooms[i].theme == Nightmare){
            attron(COLOR_PAIR(5));
        }
         else{
            attron(COLOR_PAIR(2));
        }
        
        }

        }}
}
    }

void endtheme(char map[maxx +1][maxy + 1], int x, int y, room rooms[], int level, int night){
    if(map[x][y] == '&')
    attroff(COLOR_PAIR(4));
    else if((map[x][y] == '@') &&(rooms[4].islocked ==1) &&(level == 0))
    attroff(COLOR_PAIR(1));
    else if((map[x][y] == '@') &&(rooms[4].islocked ==0) && (level ==0))
    attroff(COLOR_PAIR(3));
    else if((map[x][y] == '@') &&(rooms[1].islocked ==1) && (level == 1))
    attroff(COLOR_PAIR(1));
    else if((map[x][y] == '@') &&(rooms[1].islocked ==0) && (level == 1))
    attroff(COLOR_PAIR(3));
    else if((map[x][y] == '@') &&(rooms[4].islocked >0) && (level == 2))
    attroff(COLOR_PAIR(1));
    else if((map[x][y] == '@') &&(rooms[4].islocked ==0) && (level == 2))
    attroff(COLOR_PAIR(3));
    else if((map[x][y] == '@') &&(rooms[3].islocked >0) && (level == 3))
    attroff(COLOR_PAIR(1));
    else if((map[x][y] == '@') &&(rooms[3].islocked ==0) && (level == 3))
    attroff(COLOR_PAIR(3));
    else if((map[x][y] == 'd') || (map[x][y] == '$'))
    attroff(COLOR_PAIR(4));
     else if((map[x][y] == 'E'))
    attroff(COLOR_PAIR(1));
    else if((map[x][y] == 'b'))
    attroff(COLOR_PAIR(4));
    else if((map[x][y] == 'f') || (map[x][y] == 'I') || (map[x][y] == 'L')  || (map[x][y] == 'J') )
    attroff(COLOR_PAIR(5));
    else if(((map[x][y] <= '5') && ((map[x][y] >= '1'))) || (map[x][y] == 'k')|| (map[x][y] == 'a') ||(map[x][y] == 'm') )
    attroff(COLOR_PAIR(4));
    else if(map[x][y] == '6')
    attroff(COLOR_PAIR(1));
    else if(map[x][y] == '7')
    attroff(COLOR_PAIR(2));
    else if(map[x][y] == '8')
    attroff(COLOR_PAIR(3));
    else if(map[x][y] == '#')
    attroff(COLOR_PAIR(6));
    else if(map[x][y] == 'D')
    attroff(COLOR_PAIR(2));
    else if(map[x][y] == 'F')
    attroff(COLOR_PAIR(5));
    else if(map[x][y] == 'G')
    attroff(COLOR_PAIR(2));
    else if(map[x][y] == 'S')
    attroff(COLOR_PAIR(3));
    else if(map[x][y] == 'U')
    attroff(COLOR_PAIR(5));

    else{
        for(int i= 0; i<6; i++){
             if((x<=rooms[i].bottomright.x) && (x>=rooms[i].bottomleft.x) && (y>=rooms[i].topleft.y)  &&(y<=rooms[i].bottomleft.y) ){
        if((map[x][y] == '.') ||(map[x][y] == '_') || (map[x][y] == '|')  ){
        if(rooms[i].theme == Regular){
            attroff(COLOR_PAIR(6));
        }
        else if(rooms[i].theme == Enchant){
            attroff(COLOR_PAIR(1));
        }
        else if(rooms[i].theme == Nightmare){
            attroff(COLOR_PAIR(3));
        }
        else if(rooms[i].theme == purgatory){
            attron(COLOR_PAIR(5));
        }
        else{
            attroff(COLOR_PAIR(4));
        }
        }

        else if(((map[x][y] == '^')) || ((map[x][y] == 'O')) || ((map[x][y] == '+')) || ((map[x][y] == '?')&& (night !=0)) ){
            if(rooms[i].theme == Regular){
            attroff(COLOR_PAIR(1));
        }
        else if(rooms[i].theme == Enchant){
            attroff(COLOR_PAIR(3));
        }
        else if(rooms[i].theme == Nightmare){
            attroff(COLOR_PAIR(5));
        }
        else{
            attroff(COLOR_PAIR(2));
        }
        }

        }}
}
}

void printmap(char map[maxx +1][maxy + 1], position player, int color, room rooms[],char realmap[maxx +1][maxy + 1] , int level){
    int roomnumb = roomsearch(rooms, player.x, player.y);
    for(int i =0; i<6; i++){
    if((rooms[i].isvisible ==1)){
        for(int k = rooms[i].bottomleft.x ; k<=rooms[i].bottomright.x; k++ ){
            for(int j =rooms[i].topleft.y ; j<=rooms[i].bottomleft.y; j++){
        realmap[k][j] = map[k][j];
        if((realmap[k][j] == '?')){
            if(rooms[i].ishiddend){
                realmap[k][j] ='|';
            }
        }
        }
        }
        }
        }
       
        // if(map[player.x][player.y] == '#'){
        //     realmap[player.x][player.y] = map[player.x][player.y];   
        //     if(map[player.x+1][player.y] == '#')
        //      realmap[player.x+1][player.y] = map[player.x+1][player.y];
        //      if(map[player.x][player.y+1] == '#')  
        //      realmap[player.x][player.y+1] = map[player.x][player.y+1];  
        //      if(map[player.x+1][player.y+1] == '#')
        //      realmap[player.x+1][player.y+1] = map[player.x+1][player.y+1];  
        // }
        if(map[player.x][player.y] == '#'){
        for(int i = -1; i<2; i++){
            for(int j =-1; j<2; j++){
            if(map[player.x+i ][player.y +j] == '#'){
                realmap[player.x + i][player.y +j] = '#';
            }
            }
        }
        }
        
        for(int i =0; i<maxx; i++){
            for(int j =0; j< maxy; j++){
             if((roomnumb != -1)&&(rooms[roomnumb].theme != Nightmare)){
              
              if(upshot){
                int i =1;
                while ((player.y -i>upshot)&&(map[player.x][player.y -i] != '_')&&(map[player.x][player.y -i] != 'O')&&(map[player.x][player.y -i] != '+')&&(map[player.x][player.y -i] != 'D')&&(map[player.x][player.y -i] != 'G')&&(map[player.x][player.y -i] != 'F')&&(map[player.x][player.y -i] != 'S')&&(map[player.x][player.y -i] != 'U')&(map[player.x][player.y -i] != 'E'))
                {
                    realmap[player.x][player.y -i] = '|';
                    i++;
                }
                upshot =0;
                downshot =0;
                leftshot =0;
                rightshot =0;
                
              }
            
             else if(downshot){
                int i =1;
                while ((player.y +i<downshot)&&(map[player.x][player.y +i] != '_')&&(map[player.x][player.y +i] != 'O')&&(map[player.x][player.y +i] != '+')&&(map[player.x][player.y +i] != 'D')&&(map[player.x][player.y +i] != 'G')&&(map[player.x][player.y +i] != 'F')&&(map[player.x][player.y +i] != 'S')&&(map[player.x][player.y +i] != 'U')&&(map[player.x][player.y +i] != 'E'))
                {
                    realmap[player.x][player.y +i] = '|';
                    i++;
                }
                upshot =0;
                downshot =0;
                leftshot =0;
                rightshot =0;
                
              }
             
              else if(leftshot){
                int i =1;
                while ((player.x-i>leftshot)&&(map[player.x-i][player.y ] != '|')&&(map[player.x-i][player.y ] != 'O')&&(map[player.x-i][player.y ] != '+')&&(map[player.x-i][player.y ] != 'D')&&(map[player.x-i][player.y ] != 'G')&&(map[player.x-i][player.y ] != 'F')&&(map[player.x-i][player.y ] != 'S')&&(map[player.x-i][player.y ] != 'U')&&(map[player.x-i][player.y ] != 'E'))
                {
                    realmap[player.x-i][player.y ] = '-';
                    i++;
                }
                upshot =0;
                downshot =0;
                leftshot =0;
                rightshot =0;
                
              }
              
              else if(rightshot){
                int i =1;
                while ((player.x+i<rightshot)&&(map[player.x+i][player.y ] != '|')&&(map[player.x+i][player.y ] != 'O')&&(map[player.x+i][player.y ] != '+')&&(map[player.x+i][player.y ] != 'D')&&(map[player.x+i][player.y ] != 'G')&&(map[player.x+i][player.y ] != 'F')&&(map[player.x+i][player.y ] != 'S')&&(map[player.x+i][player.y ] != 'U')&&(map[player.x+i][player.y ] != 'E'))
                {
                    realmap[player.x+i][player.y ] = '-';
                    i++;
                }
                upshot =0;
                downshot =0;
                leftshot =0;
                rightshot =0;
                
              }
               }
                starttheme(realmap, i, j, rooms, level,1);
                if(realmap[i][j] == 'd')
                mvprintw(j,i,"Δ");
                else if(realmap[i][j] == 'b')
                mvprintw(j, i, "\u03A6");
                else if((realmap[i][j] == 'f') ||(realmap[i][j] == 'I')  )
                mvprintw(j, i, "α");
                else if((realmap[i][j] == 'L') )
                mvprintw(j, i, "β");
                 else if((realmap[i][j] == 'J') )
                mvprintw(j, i, "δ");
                else if(realmap[i][j] == '1')
                mvprintw(j, i, "\u2692");
                else if((realmap[i][j] == '2') || (realmap[i][j] == 'k'))
                mvprintw(j, i, "τ");
                else if((realmap[i][j] == '3')||(realmap[i][j] == 'm'))
                mvprintw(j, i, "Ψ");
                else if((realmap[i][j] == '4')||(realmap[i][j] == 'a'))
                mvprintw(j, i, "➵");
                else if(realmap[i][j] == '5')
                mvprintw(j, i, "Χ");
                else if(realmap[i][j] == '6')
                mvprintw(j, i, "♥");
                else if(realmap[i][j] == '7')
                mvprintw(j, i, "►");
                else if(realmap[i][j] == '8')
                mvprintw(j, i, "☠");
                else
                mvprintw(j,i,"%c", realmap[i][j]);
                endtheme(realmap, i, j, rooms, level, 1);
            }
        }

                   for(int k= 0; k<6; k++){
             if((player.x<=rooms[k].bottomright.x) && (player.x>=rooms[k].bottomleft.x) && (player.y>=rooms[k].topleft.y)  &&(player.y<=rooms[k].bottomleft.y) &&(rooms[k].theme == Nightmare)){
                    for(int z = player.x-2; z<player.x + 3; z++){
                        for(int a = player.y-2; a<player.y + 3; a++){
                            starttheme(map, z, a, rooms, level, 0);
                if(map[z][a] == 'd')
                mvprintw(a,z,"Δ");
                else if(map[z][a] == 'b')
                mvprintw(a, z, "\u03A6");
                 else if((map[z][a] == 'f') ||(map[z][a] == 'I')  )
                mvprintw(a, z, "α");
                else if((map[z][a] == 'L') )
                mvprintw(a, z, "β");
                 else if((map[z][a] == 'J') )
                mvprintw(a, z, "δ");
                else if(map[z][a] == '?'){
                    attron(COLOR_PAIR(3));
                mvprintw(a, z, "|");
                attroff(COLOR_PAIR(3));
                }
                else if(map[z][a] == '1')
                mvprintw(a, z, "Ω");
                else if((map[z][a] == '2') || (map[z][a] == 'k'))
                mvprintw(a, z, "τ");
                else if((map[z][a] == '3')||(map[z][a] == 'm'))
                mvprintw(a, z, "Ψ");
                else if((map[z][a] == '4')||(map[z][a] == 'a'))
                mvprintw(a, z, "➵");
                else if(map[z][a] == '5')
                mvprintw(a, z, "Χ");
                 else if(map[z][a] == '6')
                mvprintw(a, z, "♥");
                else if(map[z][a] == '7')
                mvprintw(a, z, "►");
                else if(map[z][a] == '8')
                mvprintw(a, z, "☠");
                else{
                if(map[z][a] != '#'){
                    
                mvprintw(a,z,"%c", map[z][a]);}}

                endtheme(map, z, a, rooms, level, 0);
                        }
                       }}}

    
attron(COLOR_PAIR(color));
mvprintw(player.y,player.x,"A"); 
attroff(COLOR_PAIR(color));
}

void endmusic(){
    Mix_HaltMusic();
    Mix_CloseAudio();
   
}

int passwordcheck(char password[]){
    char input[100] = {0};
    echo();
    for(int i =0; i<3; i++ ){
        clear();
         if(i ==1 ){
        attron(COLOR_PAIR(4));
        printwrong();
        attroff(COLOR_PAIR(4));
        refresh();
    }
    else if(i ==2 ){
        attron(COLOR_PAIR(5));
        printwrong();
        attroff(COLOR_PAIR(5));
        refresh();
    }
    attron(COLOR_PAIR(1));
    mvprintw(20, COLS/2 -7 , "enter password:");
    attroff(COLOR_PAIR(1));
    refresh();
    getstr(input);
    if(strcmp(input , password ) == 0){
        noecho();
        return 1;
    }
    
    }
    clear();
    noecho();
    return 0;
}

void foodmenu(data* game){
curs_set(false);
         noecho();
 while (1)
    {
         
    int boxheight = 30;
    int boxwidth = 100;
    int y_box = (LINES - boxheight) /2 +5;
    int x_box = (COLS - boxwidth) /2-4;

    WINDOW *window = newwin(boxheight, boxwidth, y_box, x_box);
    box(window, 0, 0);
    wbkgd(window, COLOR_PAIR(4));
    keypad(stdscr, true);
    int choice =0;
    while(1){
        clear();
          curs_set(false);
         noecho();
         wclear(window);
     box(window, 0, 0);
    wbkgd(window, COLOR_PAIR(4));
    keypad(stdscr, true);
    
    health(game);
    hunger(game);
    attron(COLOR_PAIR(4) | A_BOLD);
    printfood();
    printtea();
    attroff( COLOR_PAIR(4) | A_BOLD);
    if(choice == game->foodamount){
        printquit(window);
    }
    else{
        if(strcmp(game->flist[choice].name, "Normal") == 0){
            printcandy(window);
        }
        else if(strcmp(game->flist[choice].name, "Great") == 0){
            printicecream(window);
        }
        else if(strcmp(game->flist[choice].name, "Magic") == 0){
            printburger(window);
        }
    }

        for(int i =0; i<game->foodamount +1; i++){
            if(i == choice){
                wattron(window, A_REVERSE);
            }
            if(i == game->foodamount)
            mvwprintw(window, 1 + i, 3,"%s", "Quit");
            else
            mvwprintw(window, 1 + i, 3,"%s", game->flist[i].name);
            if(i == choice){
                wattroff(window, A_REVERSE);
            }
            
        }
        refresh();
        wrefresh(window);
        int key = getch();
        if(key != ERR){
        if(key == KEY_UP){
            if(choice != 0){
                choice --;
            }
            else
            choice =game->foodamount;
        }
         if(key == KEY_DOWN){
            if(choice != game->foodamount){
                choice ++;
            }
            else
            choice =0;
        }
        else if(key == 10){
            break;
        }}


    }

    delwin(window);
    if(choice != game->foodamount){
        if((game->flist[choice].fkind == NORMAL) ||(game->flist[choice].fkind == GREAT) || (game->flist[choice].fkind == MAGIC)){
        if(game->hunger>=15)
        game->hunger = game->hunger - 15;
        else
        game->hunger =0;}
        if(game->flist[choice].fkind == POISENOUS)
        game->hunger = game->hunger +5;
        game->playerhp += game->flist[choice].hpamount;
        if(game->flist[choice].fkind == GREAT){
        game->isdamagespell = 1;
        game->isspeedspell =  0;
        game->ishealthspell = 0;
        }
        if(game->flist[choice].fkind == MAGIC){
        game->isspeedspell = 1;
        game->ishealthspell = 0;
        game->isdamagespell = 0;
        }
        if(game->playerhp > 100)
        game->playerhp =100;
        if(game->playerhp<0)
        game->playerhp =0;

        for(int i =choice;i<game->foodamount-1; i++){
           game->flist[i].hpamount =game->flist[i+1].hpamount;
           game->flist[i].fkind =game->flist[i+1].fkind;
           game->flist[i].ftime = game->flist[i +1].ftime ;
            strcpy(game->flist[i].name,game->flist[i+1].name);
        }
        game->foodamount = game->foodamount -1;
    }
     
    else {
      break;
    }
    clear();
    }

}

void weaponlist(data* game){

 while (1)
    {
         clear();
         curs_set(false);
         noecho();
    int boxheight = 30;
    int boxwidth = 100;
    int y_box =  5+(LINES - boxheight) /2;
    int x_box = (COLS - boxwidth) /2-4;

    WINDOW *window = newwin(boxheight, boxwidth, y_box, x_box);
    box(window, 0, 0);
    wbkgd(window, COLOR_PAIR(3));
    keypad(stdscr, true);
    refresh();
    wrefresh(window);
    int choice =0;
    while(game->wlist[choice].count == 0){
                choice++;
                if(choice == 5)
                break;
                }
                
    while(1){
        clear();
        wclear(window);
          curs_set(false);
         noecho();
     box(window, 0, 0);
    wbkgd(window, COLOR_PAIR(3));
    keypad(stdscr, true);
    attron(COLOR_PAIR(2) | A_BOLD);
    printweapon();
    printsoldierright();
    attroff( COLOR_PAIR(2) | A_BOLD);
        for(int i =0; i<6; i++){
            if(i == choice){
                wattron(window, A_REVERSE);
            }
            if(i == 5)
            mvwprintw(window, 1 + i, 3,"%s", "Quit");
            else{
                if(game->wlist[i].isactive)
                wattron(window, A_BOLD);
                if(i ==0)
            mvwprintw(window, 1 + i, 3,"Ω Mace         COUNT:     DAMAGE: 5  SHORT-RANGE   ");
            else if(i == 1)
            mvwprintw(window, 1 + i, 3,"τ Dagger       COUNT:     DAMAGE: 12 LONG-RANGE: 5 ");
            else if(i == 2)
            mvwprintw(window, 1 + i, 3,"Ψ Magic Wand   COUNT:     DAMAGE: 15 LONG-RANGE: 10");
            else if(i == 3)
            mvwprintw(window, 1 + i, 3,"➵ Normal Arrow COUNT:     DAMAGE: 5  LONG-RANGE: 5 ");
            else if(i == 4)
            mvwprintw(window, 1 + i, 3,"Χ sword        COUNT:     DAMAGE: 10 SHORT-RANGE   ");
             mvwprintw(window, 1+i, 25, "%d", game->wlist[i].count);
         if(game->wlist[i].isactive)
                wattroff(window, A_BOLD);
                }
            if(i == choice){
                wattroff(window, A_REVERSE);
            }
            
        }
        
        wattron(window,COLOR_PAIR(1) | A_BOLD);
         if(choice == 4){
    printsword(window);
        }
         else if(choice == 3){
   printarrow(window);
        }
             else if(choice == 2){
   printwand(window);
        }
             else if(choice == 1){
   printdagger(window);
        }
             else if(choice == 0){
   printmace(window);
        }
        else if(choice == 5)
        printquit(window);
        wattroff(window, COLOR_PAIR(1) | A_BOLD);
        refresh();
        wrefresh(window);

        int key = getch();
        if(key != ERR){
        if(key == KEY_UP){
            if(choice != 0){
                choice--;
                while(game->wlist[choice].count == 0){
                if(choice == 0){
                    if(game->wlist[choice].count == 0)
                    choice =5;
                break;}
                choice--;
                }

            }
            else
            choice =5;
        }
         if(key == KEY_DOWN){
            if(choice != 5){
                choice++;
                if(choice !=5){
                while(game->wlist[choice].count == 0){
                choice++;
                if(choice == 5)
                break;
                }}
            }
            else{
            choice =0;
            while(game->wlist[choice].count == 0){
                choice++;
                if(choice == 5)
                break;
                }
            }
            
        }
        else if(key == 10){
            break;
        }}


    }

    delwin(window);
    if(choice != 5){
        for(int i =0; i<5; i++){
            game->wlist[i].isactive =0;
        }
        game->wlist[choice].isactive =1;
    }
     
    else {
      break;
    }
    clear();
    }
}

void spelllist(data* game){
 while (1)
    {
         clear();
         curs_set(false);
         noecho();
    int boxheight = 30;
    int boxwidth = 100;
    int y_box = 5 + (LINES - boxheight) /2;
    int x_box = (COLS - boxwidth) /2;

    WINDOW *window = newwin(boxheight, boxwidth, y_box, x_box);
    box(window, 0, 0);
    wbkgd(window, COLOR_PAIR(5));
    keypad(stdscr, true);
    refresh();
    wrefresh(window);
    int choice =0;
    while(game->slist[choice].count == 0){
                choice++;
                if(choice == 3)
                break;
                }

    while(1){
        clear();
        wclear(window);
          curs_set(false);
         noecho();
     box(window, 0, 0);
    wbkgd(window, COLOR_PAIR(5));
    keypad(stdscr, true);
    attron(COLOR_PAIR(1) | A_BOLD);
    printspell();
    attroff( COLOR_PAIR(1) | A_BOLD);

        for(int i =0; i<4; i++){
            if(i == choice){
                wattron(window, A_REVERSE);
            }
            if(i == 3)
            mvwprintw(window, 1 + i, 3,"%s", "Quit");
            else{
            mvwprintw(window, 1 + i, 3,"%s COUNT: %d", game->slist[i].name, game->slist[i].count);
                }
            if(i == choice){
                wattroff(window, A_REVERSE);
            }
            
        }
           wattron(window, COLOR_PAIR(3) | A_BOLD);
        if(choice == 2){
    printbio(window);
        }
        else if(choice == 1){
            printspeed(window);
        }
        else if(choice == 0){
            printheart(window);
        }
        else if(choice == 3)
        printquit(window);
        wattroff(window, COLOR_PAIR(3) | A_BOLD);
        refresh();
        wrefresh(window);

        int key = getch();
        if(key != ERR){
        if(key == KEY_UP){
            if(choice != 0){
                choice--;
                while(game->slist[choice].count == 0){
                if(choice == 0){
                    if(game->slist[choice].count == 0)
                    choice =3;
                break;}
                choice--;
                }
            }
            else
            choice =3;
        }
         if(key == KEY_DOWN){
            if(choice != 3){
                choice++;
                if(choice != 3){
                while(game->slist[choice].count == 0){
                choice++;
                if(choice == 3)
                break;
                }}
            }
            else{
            choice =0;
            while(game->slist[choice].count == 0){
                choice++;
                if(choice == 3)
                break;
                }
            }
        }
        else if(key == 10){
            break;
        }}


    }

    delwin(window);
    if(choice != 3){
        game->slist[choice].count =game->slist[choice].count -1;

         game->ishealthspell =0;
        game->isspeedspell =0;
        game->isdamagespell =0;

        if(choice == 0)
        game->ishealthspell =1;
        else if(choice == 1)
        game->isspeedspell =1;
        else if(choice ==2 )
        game->isdamagespell =1;
    }
     
    else {
      break;
    }
    clear();
    }
}

int playercheck(char map[][maxx + 1][maxy+ 1], int x,int  y, int *level){
    if((map[*level][x][y ] == '.') || (map[*level][x][y ] == '+') || (map[*level][x][y ] == '#') ||(map[*level][x][y ] == '=') ||(map[*level][x][y ] == '^')||(map[*level][x][y ] == '?') || (map[*level][x][y ] == '<') || (map[*level][x][y ] == '&') ||(map[*level][x][y ] == '@') || (map[*level][x][y ] == 'd')|| (map[*level][x][y ] == '$')|| (map[*level][x][y ] == 'E')|| (map[*level][x][y ] == 'b')||(map[*level][x][y ] == 'f') ||((map[*level][x][y ] >= '1')&& (map[*level][x][y ] <= '8')) ||(map[*level][x][y ] == 'k')||(map[*level][x][y ] == 'a')||(map[*level][x][y ] == 'm')||(map[*level][x][y ] == 'L')||(map[*level][x][y ] == 'J')||(map[*level][x][y ] == 'I')){
        return 1;
        }
        else
        return 0;
}

void handleinput(position* player, char map[][maxx + 1][maxy+ 1], int input ,room rooms[4][6], int * playerhp, int *level, int* invalid, char password[], int* passwordmode, int* passend, int* ancient, int* brokenancient, position* save, int color, data* game, int* dontpick, int* win, int* newroom, int dontchoose, int* hittype,int* monshp, int* spellcounter, int* isspeed, int* fire){
    int copyx = player->x;
    int copyy = player ->y;
    int roomsnum = roomsearch(rooms[*level], player->x, player->y);
    if(roomsnum == -1){
        for(int i =0; i<6; i++){
            for(int j =0; j<6; j++){
        rooms[*level][i].mons[j].movement =0;
        }
        }
    }

    if(game->isdamagespell ==1){
        (*spellcounter) += 1;
        if((*spellcounter) == 11){
            (*spellcounter) = 0;
            game->isdamagespell =0;
        }
    }
   
    if((input == 'l')&&(game->lastkey !=0)){
        handleinput(player, map, 123, rooms, playerhp, level, invalid, password, passwordmode, passend , ancient, brokenancient, save, color, game, dontpick,win, newroom, dontchoose, hittype, monshp, spellcounter, isspeed,fire);    
    }
    
    if(input == 'w'){
        if((*isspeed)&&(*spellcounter <= 10)){
            player->y = player->y -2;
        *invalid = 0;
        *spellcounter = *spellcounter + 1;
        }

        else{
            player->y = player->y -1;
        *invalid = 0;
        }

        if(!(*spellcounter <= 10)){
            *isspeed =0;
            *spellcounter =0;
        }
    }
    
    else if(input == 'a'){
        if((*isspeed)&&(*spellcounter <= 10)){
            player->x = player->x -2;
        *invalid = 0;
        *spellcounter = *spellcounter + 1;
        }

        else{
            player->x = player->x -1;
        *invalid = 0;
        }
        
        if(!(*spellcounter <= 10)){
            *isspeed =0;
            *spellcounter =0;
        }
    }
    
    else if(input == 's'){
        if((*isspeed)&&(*spellcounter <= 10)){
            player->y = player->y + 2;
        *invalid = 0;
        *spellcounter = *spellcounter + 1;
        }

        else{
            player->y = player->y +1;
        *invalid = 0;
        }
        
        if(!(*spellcounter <= 10)){
            *isspeed =0;
            *spellcounter =0;
        }
    }
    
    else if(input == 'd'){
       if((*isspeed)&&(*spellcounter <= 10)){
            player->x = player->x +2;
        *invalid = 0;
        *spellcounter = *spellcounter + 1;
        }

        else{
            player->x = player->x +1;
        *invalid = 0;
        }
        
        if(!(*spellcounter <= 10)){
            *isspeed =0;
            *spellcounter =0;
        }
    }
    
    else if(input == 'e'){
        if((*isspeed)&&(*spellcounter <= 10)){
            player->y = player->y -2;
             player->x = player->x +2;
        *invalid = 0;
        *spellcounter = *spellcounter + 1;
        }

        else{
            player->y = player->y -1;
            player->x = player->x +1;
        *invalid = 0;
        }
        
        if(!(*spellcounter <= 10)){
            *isspeed =0;
            *spellcounter =0;
        }
    }
    
    else if(input == 'q'){
        if((*isspeed)&&(*spellcounter <= 10)){
            player->y = player->y -2;
             player->x = player->x -2;
        *invalid = 0;
        *spellcounter = *spellcounter + 1;
        }

        else{
            player->y = player->y -1;
            player->x = player->x -1;
        *invalid = 0;
        }
        
        if(!(*spellcounter <= 10)){
            *isspeed =0;
            *spellcounter =0;
        }
    }
    
    else if(input == 'c'){
         if((*isspeed)&&(*spellcounter <= 10)){
            player->y = player->y +2;
             player->x = player->x +2;
        *invalid = 0;
        *spellcounter = *spellcounter + 1;
        }

        else{
            player->y = player->y +1;
            player->x = player->x +1;
        *invalid = 0;
        }
        
        if(!(*spellcounter <= 10)){
            *isspeed =0;
            *spellcounter =0;
        }
    }
    
    else if(input == 'z'){
             if((*isspeed)&&(*spellcounter <= 10)){
            player->y = player->y +2;
             player->x = player->x -2;
        *invalid = 0;
        *spellcounter = *spellcounter + 1;
        }

        else{
            player->y = player->y +1;
            player->x = player->x -1;
        *invalid = 0;
        }
        
        if(!(*spellcounter <= 10)){
            *isspeed =0;
            *spellcounter =0;
        }
    }
    
    else if(input == 'm'){
        clear();
        for(int i =0; i<maxx; i++){
            for(int j =0; j< maxy; j++){
                starttheme(map[*level], i, j, rooms[*level], *level, 1);
                if(map[*level][i][j] == 'd')
                mvprintw(j,i, "Δ");
                else if(map[*level][i][j] == 'b')
                mvprintw(j, i, "\u03A6");
                 else if((map[*level][i][j] == 'f') ||(map[*level][i][j] == 'I')  )
                mvprintw(j, i, "α");
                else if((map[*level][i][j] == 'L') )
                mvprintw(j, i, "β");
                 else if((map[*level][i][j] == 'J') )
                mvprintw(j, i, "δ");
                else if(map[*level][i][j] == '1')
                mvprintw(j, i, "Ω");
                else if((map[*level][i][j] == '2') || (map[*level][i][j] == 'k'))
                mvprintw(j, i, "τ");
                else if((map[*level][i][j] == '3')||(map[*level][i][j] == 'm'))
                mvprintw(j, i, "Ψ");
                else if((map[*level][i][j] == '4')||(map[*level][i][j] == 'a'))
                mvprintw(j, i, "➵");
                else if(map[*level][i][j] == '5')
                mvprintw(j, i, "Χ");
                 else if(map[*level][i][j] == '6')
                mvprintw(j, i, "♥");
                else if(map[*level][i][j] == '7')
                mvprintw(j, i, "►");
                else if(map[*level][i][j] == '8')
                mvprintw(j, i, "☠");
                else
                mvprintw(j,i,"%c", map[*level][i][j]);
                endtheme(map[*level], i, j, rooms[*level], *level, 1);
            }
        }
        attron(COLOR_PAIR(color));
        mvprintw(player->y,player->x,"A"); 
        attroff(COLOR_PAIR(color));
        refresh();
        while (1)
        {
            int back = 0;
            back = getch();
            if(back == 'm'){
                break;
            }
        }
    }
    
    else if(input == 'f'){
        int key = 0;
        int savex =0;
        int savey =0;
        key = getch();
        if((key != ERR) && (key != 'h') && (key != 'f') && (key != 'm') && (key != 'g')){
        while (!((player->x == savex) && (player->y == savey)))
        {
            savex = player->x;
            savey = player->y;
            handleinput(player, map, key,rooms,playerhp,level, invalid, password, passwordmode,passend,ancient,brokenancient, save,color, game, dontpick, win, newroom, 1, hittype, monshp, spellcounter, isspeed, fire);
            printmap(map[*level], *player, color, rooms[*level], game->realmap[*level], *level);
            refresh();
        }}
        
    }
    
    else if(input == 'g'){
         *dontpick =1;
    }
    
    else if(input == 'x'){
        for(int i = player->x -2; i<player->x + 3; i++){
            for(int j = player->y -2; j<player->y + 3; j++){
                int roomnumber = roomsearch(rooms[*level], i, j);
                if(roomnumber != -1){
                if(map[*level][i][j] == '?')
                 rooms[*level][roomnumber].ishiddend = 0;
                 
       for(int k =0; k<6; k++){
        if(rooms[*level][k].istrap ==1){
            if(rooms[*level][k].theme == Treasure){
                 for(int z =0; z<4; z++){
            if((i == rooms[*level][k].trap[z].x) && (j == rooms[*level][k].trap[z].y)){
                map[*level][i][j] = '^';
                
            }}
            }
            for(int z =0; z<2; z++){
            if((i == rooms[*level][k].trap[z].x) && (j == rooms[*level][k].trap[z].y)){
                map[*level][i][j] = '^';
               
            }}
        }
    }
        }
        }
    }}

    else if(input == 'r'){
        foodmenu(game);
    }

    else if(input == 't'){
        weaponlist(game);
    }

    else if(input == 'y'){
        spelllist(game);
    }

    else if(input == 'i'){
        if(game->wlist[0].isactive != 1){
        game->wlist[0].isactive = 1;
        for(int i =1; i<5; i++){
            game->wlist[i].isactive =0;
        }
        }
        else
        game->wlist[0].isactive = 0;
    }
   
    else if((input == 'o') && (game->wlist[1].isactive != 1) && (game->wlist[1].count >0)){
         
        game->wlist[1].isactive = 1;
        for(int i =0; i<5; i++){
            if(i !=1)
            game->wlist[i].isactive =0;
        }
    }

    else if((input == 'o') && (game->wlist[1].isactive == 1)){
        game->wlist[1].isactive = 0;
    }

    else if((input == ';') && (game->wlist[2].isactive != 1) && (game->wlist[2].count >0)){
         
        game->wlist[2].isactive = 1;
        for(int i =0; i<5; i++){
            if(i !=2)
            game->wlist[i].isactive =0;
        }
    }

    else if((input == ';') && (game->wlist[2].isactive == 1)){
        game->wlist[2].isactive = 0;
    }

    else if((input == 'k') && (game->wlist[3].isactive != 1) && (game->wlist[3].count >0)){
         
        game->wlist[3].isactive = 1;
        for(int i =0; i<5; i++){
            if(i !=3)
            game->wlist[i].isactive =0;
        }
    }

    else if((input == 'k') && (game->wlist[3].isactive == 1)){
        game->wlist[3].isactive = 0;
    }

    else if(input == 'j'){
        if(game->wlist[4].isactive != 1){
        game->wlist[4].isactive = 1;
        for(int i =0; i<4; i++){
            game->wlist[i].isactive =0;
        }
        }
        else
        game->wlist[4].isactive = 0;
    }

    else if(input == 32){

        if(game->wlist[0].isactive == 1){
            int ishit =0;
            for(int i =player->x -1; i<player->x + 2; i++){
                for(int j = player->y -1; j<player->y +2; j++){
                    for(int k = 0 ; k<6; k++){
                    if((rooms[*level][roomsnum].mons[k].pos.x == i)&&(rooms[*level][roomsnum].mons[k].pos.y == j)){
                        rooms[*level][roomsnum].mons[k].hp -= 5;
                        if(game->isdamagespell == 1)
                        rooms[*level][roomsnum].mons[k].hp -= 5;
                        if(rooms[*level][roomsnum].mons[k].hp<=0){
                        rooms[*level][roomsnum].mons[k].hp =0;
                        map[*level][i][j] = '.';
                        rooms[*level][roomsnum].mons[k].pos.x = -1;
                        rooms[*level][roomsnum].mons[k].pos.y = -1;
                        }
                        ishit =1;
                        *monshp = rooms[*level][roomsnum].mons[k].hp;
                        *hittype = 2;
                    }
                    }
                }
            }
            if(ishit ==0){
                        *hittype = 0;
            }
            game->lastkey =0;
        }

        else if((game->wlist[1].isactive ==1) ){
            int ishit =0;
            int key;
            if((game->wlist[1].count>=1)){

            while(1){
        printmap(map[*level], *player, color, rooms[*level], game->realmap[*level], *level);
        refresh();
     key = getch();
    game->lastkey = key;
      if(key == 'w'){
      for(int i =player->y; (i>rooms[*level][roomsnum].topleft.y) && (i>= player->y -5)&&(map[*level][player->x][i] != 'O')&&(map[*level][player->x][i] != '&')&&(map[*level][player->x][i] != 'E')&&(map[*level][player->x][i] != 'O')&&(map[*level][player->x][i] != '&')&&(map[*level][player->x][i] != 'E'); i--){
        upshot =i;
        for(int k=0; k<6; k++){
        if((rooms[*level][roomsnum].mons[k].pos.x == player->x)&&(rooms[*level][roomsnum].mons[k].pos.y == i)){
            rooms[*level][roomsnum].mons[k].hp -= 12;
            if(game->isdamagespell == 1)
            rooms[*level][roomsnum].mons[k].hp -= 12;
            ishit =1;
            *hittype =2;
            *invalid =0;
            if(rooms[*level][roomsnum].mons[k].hp <= 0){
            map[*level][player->x][i] = '.';
            rooms[*level][roomsnum].mons[k].pos.x =-1;
            rooms[*level][roomsnum].mons[k].pos.y = -1;
            }
            break;
        }
        }
        if(ishit)
        break;
      }
      if(ishit ==0){
    *hittype = 0;
    *invalid =0;
        map[*level][player->x][upshot] = 'k';
      }
      game->wlist[1].count--;
      break;

      }
    
    else if(key == 'a'){
         for(int i =player->x; (i>rooms[*level][roomsnum].topleft.x) && (i>= player->x -5)&&(map[*level][i][player->y] != 'O')&&(map[*level][i][player->y] != '&')&&(map[*level][i][player->y] != 'E'); i--){
            leftshot =i;
        for(int k=0; k<6; k++){
        if((rooms[*level][roomsnum].mons[k].pos.x == i)&&(rooms[*level][roomsnum].mons[k].pos.y == player->y)){
            rooms[*level][roomsnum].mons[k].hp -= 12;
            if(game->isdamagespell == 1)
                        rooms[*level][roomsnum].mons[k].hp -= 12;
            ishit =1;
            *hittype =2;
            *invalid =0;
            if(rooms[*level][roomsnum].mons[k].hp <= 0){
            map[*level][i][player->y] = '.';
            rooms[*level][roomsnum].mons[k].pos.x =-1;
            rooms[*level][roomsnum].mons[k].pos.y = -1;
            }
            break;
        }
        }
        if(ishit)
        break;
      }
      if(ishit ==0){
    *hittype = 0;
    *invalid =0;
        map[*level][leftshot][player->y] = 'k';
      }
      game->wlist[1].count--;
      break;
    }
    
    else if(key == 's'){
      for(int i =player->y; (i<rooms[*level][roomsnum].bottomleft.y) && (i<= player->y +5)&&(map[*level][player->x][i] != 'O')&&(map[*level][player->x][i] != '&')&&(map[*level][player->x][i] != 'E'); i++){
        downshot = i;
        for(int k=0; k<6; k++){
        if((rooms[*level][roomsnum].mons[k].pos.x == player->x)&&(rooms[*level][roomsnum].mons[k].pos.y == i)){
            rooms[*level][roomsnum].mons[k].hp -= 12;
            if(game->isdamagespell == 1)
                        rooms[*level][roomsnum].mons[k].hp -= 12;
            ishit =1;
            *hittype =2;
            *invalid =0;
            if(rooms[*level][roomsnum].mons[k].hp <= 0){
            map[*level][player->x][i] = '.';
            rooms[*level][roomsnum].mons[k].pos.x =-1;
            rooms[*level][roomsnum].mons[k].pos.y = -1;
            }
            break;
        }
        }
        if(ishit)
        break;
      }
      if(ishit ==0){
    *hittype = 0;
    *invalid =0;
        map[*level][player->x][downshot] = 'k';
      }
      game->wlist[1].count--;
      break;
    }
    
    else if(key == 'd'){
               for(int i =player->x; (i<rooms[*level][roomsnum].topright.x) && (i<= player->x +5)&&(map[*level][i][player->y] != 'O')&&(map[*level][i][player->y] != '&')&&(map[*level][i][player->y] != 'E'); i++){
                rightshot = i;
        for(int k=0; k<6; k++){
        if((rooms[*level][roomsnum].mons[k].pos.x == i)&&(rooms[*level][roomsnum].mons[k].pos.y == player->y)){
            rooms[*level][roomsnum].mons[k].hp -= 12;
            if(game->isdamagespell == 1)
                        rooms[*level][roomsnum].mons[k].hp -= 12;
            ishit =1;
            *hittype =2;
            *invalid =0;
            if(rooms[*level][roomsnum].mons[k].hp <= 0){
            map[*level][i][player->y] = '.';
            rooms[*level][roomsnum].mons[k].pos.x =-1;
            rooms[*level][roomsnum].mons[k].pos.y = -1;
            }
            break;
        }
        }
        if(ishit)
        break;
      }
      if(ishit ==0){
    *hittype = 0;
    *invalid =0;
        map[*level][rightshot][player->y] = 'k';
      }
      game->wlist[1].count--;
      break;
    }
  
    else if((key != ERR)&&(key != 32)){
        handleinput(player, map, key, rooms, playerhp, level, invalid, password, passwordmode, passend, ancient, brokenancient, save, color, game, dontpick, win, newroom,0, hittype, monshp, spellcounter, isspeed, fire);
        break;
    }
    
    }
    
    } 
    else{
        *hittype =0;
        *invalid =1;
      }
    
    if(game->wlist[1].count ==0){
        game->wlist[1].isactive =0;
        game->wlist[0].isactive =1;

    }

 
       
        }
       
        else if((game->wlist[2].isactive ==1) ){
            int ishit =0;
            int key;
            if((game->wlist[2].count>=1)){

            while(1){
        printmap(map[*level], *player, color, rooms[*level], game->realmap[*level], *level);
        refresh();
     key = getch();
    game->lastkey = key;
      if(key == 'w'){
      for(int i =player->y; (i>rooms[*level][roomsnum].topleft.y) && (i>= player->y -10)&&(map[*level][player->x][i] != 'O')&&(map[*level][player->x][i] != '&')&&(map[*level][player->x][i] != 'E'); i--){
        upshot = i;
        for(int k=0; k<6; k++){
        if((rooms[*level][roomsnum].mons[k].pos.x == player->x)&&(rooms[*level][roomsnum].mons[k].pos.y == i)){
            rooms[*level][roomsnum].mons[k].hp -= 15;
            if(game->isdamagespell == 1)
                        rooms[*level][roomsnum].mons[k].hp -= 15;
            ishit =1;
            rooms[*level][roomsnum].mons[k].dontmove =1;
            *hittype =2;
            *invalid =0;
            if(rooms[*level][roomsnum].mons[k].hp <= 0){
            map[*level][player->x][i] = '.';
            rooms[*level][roomsnum].mons[k].pos.x =-1;
            rooms[*level][roomsnum].mons[k].pos.y = -1;
            }
            break;
        }
        }
        if(ishit)
        break;
      }
      if(ishit ==0){
    *hittype = 0;
    *invalid =0;
        map[*level][player->x][upshot] = 'm';
      }
      game->wlist[2].count--;
      break;

      }
    
    else if(key == 'a'){
         for(int i =player->x; (i>rooms[*level][roomsnum].topleft.x) && (i>= player->x -10)&&(map[*level][i][player->y] != 'O')&&(map[*level][i][player->y] != '&')&&(map[*level][i][player->y] != 'E'); i--){
            leftshot = i;
        for(int k=0; k<6; k++){
        if((rooms[*level][roomsnum].mons[k].pos.x == i)&&(rooms[*level][roomsnum].mons[k].pos.y == player->y)){
            rooms[*level][roomsnum].mons[k].hp -= 15;
            if(game->isdamagespell == 1)
                        rooms[*level][roomsnum].mons[k].hp -= 15;
                   rooms[*level][roomsnum].mons[k].dontmove =1;     
            ishit =1;
            *hittype =2;
            *invalid =0;
            if(rooms[*level][roomsnum].mons[k].hp <= 0){
            map[*level][i][player->y] = '.';
            rooms[*level][roomsnum].mons[k].pos.x =-1;
            rooms[*level][roomsnum].mons[k].pos.y = -1;
            }
            break;
        }
        }
        if(ishit)
        break;
      }
      if(ishit ==0){
    *hittype = 0;
    *invalid =0;
         map[*level][leftshot][player->y] = 'm';
      }
      game->wlist[2].count--;
      break;
    }
    
    else if(key == 's'){
      for(int i =player->y; (i<rooms[*level][roomsnum].bottomleft.y) && (i<= player->y +10)&&(map[*level][player->x][i] != 'O')&&(map[*level][player->x][i] != '&')&&(map[*level][player->x][i] != 'E'); i++){
        downshot = i;
        for(int k=0; k<6; k++){
        if((rooms[*level][roomsnum].mons[k].pos.x == player->x)&&(rooms[*level][roomsnum].mons[k].pos.y == i)){
            rooms[*level][roomsnum].mons[k].hp -= 15;
            if(game->isdamagespell == 1)
                        rooms[*level][roomsnum].mons[k].hp -= 15;
                        rooms[*level][roomsnum].mons[k].dontmove =1;
            ishit =1;
            *hittype =2;
            *invalid =0;
            if(rooms[*level][roomsnum].mons[k].hp <= 0){
            map[*level][player->x][i] = '.';
            rooms[*level][roomsnum].mons[k].pos.x =-1;
            rooms[*level][roomsnum].mons[k].pos.y = -1;
            }
            break;
        }
        }
        if(ishit)
        break;
      }
      if(ishit ==0){
    *hittype = 0;
    *invalid =0;
        map[*level][player->x][downshot] = 'm';
      }
      game->wlist[2].count--;
      break;
    }
    
    else if(key == 'd'){
               for(int i =player->x; (i<rooms[*level][roomsnum].topright.x) && (i<= player->x +10)&&(map[*level][i][player->y] != 'O')&&(map[*level][i][player->y] != '&')&&(map[*level][i][player->y] != 'E'); i++){
                rightshot = i;
        for(int k=0; k<6; k++){
        if((rooms[*level][roomsnum].mons[k].pos.x == i)&&(rooms[*level][roomsnum].mons[k].pos.y == player->y)){
            rooms[*level][roomsnum].mons[k].hp -= 15;
            if(game->isdamagespell == 1)
                        rooms[*level][roomsnum].mons[k].hp -= 15;
                        rooms[*level][roomsnum].mons[k].dontmove =1;
            ishit =1;
            *hittype =2;
            *invalid =0;
            if(rooms[*level][roomsnum].mons[k].hp <= 0){
            map[*level][i][player->y] = '.';
            rooms[*level][roomsnum].mons[k].pos.x =-1;
            rooms[*level][roomsnum].mons[k].pos.y = -1;
            }
            break;
        }
        }
        if(ishit)
        break;
      }
      if(ishit ==0){
    *hittype = 0;
    *invalid =0;
         map[*level][rightshot][player->y] = 'm';
      }
      game->wlist[2].count--;
      break;
    
    }
  
    else if((key != ERR)&&(key != 32)){
        handleinput(player, map, key, rooms, playerhp, level, invalid, password, passwordmode, passend, ancient, brokenancient, save, color, game, dontpick, win, newroom,0, hittype, monshp, spellcounter, isspeed, fire);
        break;
    }
     
    }
    
    } 
    else{
        *hittype =0;
        *invalid =1;
      }

    if(game->wlist[2].count ==0){
        game->wlist[2].isactive =0;
        game->wlist[0].isactive =1;

    }    

            

    

        }
        
        else if((game->wlist[3].isactive ==1) ){
            int ishit =0;
            int key;
            if((game->wlist[3].count>=1)){

            while(1){
        printmap(map[*level], *player, color, rooms[*level], game->realmap[*level], *level);
        refresh();
     key = getch();
    game->lastkey = key;
      if(key == 'w'){
      for(int i =player->y; (i>rooms[*level][roomsnum].topleft.y) && (i>= player->y -5)&&(map[*level][player->x][i] != 'O')&&(map[*level][player->x][i] != '&')&&(map[*level][player->x][i] != 'E')&&(map[*level][player->x][i] != 'O')&&(map[*level][player->x][i] != '&')&&(map[*level][player->x][i] != 'E'); i--){
        upshot = i;
        for(int k=0; k<6; k++){
        if((rooms[*level][roomsnum].mons[k].pos.x == player->x)&&(rooms[*level][roomsnum].mons[k].pos.y == i)){
            rooms[*level][roomsnum].mons[k].hp -= 5;
            if(game->isdamagespell == 1)
                        rooms[*level][roomsnum].mons[k].hp -= 5;
            ishit =1;
            *hittype =2;
            *invalid =0;
            if(rooms[*level][roomsnum].mons[k].hp <= 0){
            map[*level][player->x][i] = '.';
            rooms[*level][roomsnum].mons[k].pos.x =-1;
            rooms[*level][roomsnum].mons[k].pos.y = -1;
            }
            break;
        }
        }
        if(ishit)
        break;
      }
      if(ishit ==0){
    *hittype = 0;
    *invalid =0;

            map[*level][player->x][upshot] = 'a'; 

      }
      game->wlist[3].count--;
      break;

      }
    
    else if(key == 'a'){
         for(int i =player->x; (i>rooms[*level][roomsnum].topleft.x) && (i>= player->x -5)&&(map[*level][i][player->y] != 'O')&&(map[*level][i][player->y] != '&')&&(map[*level][i][player->y] != 'E'); i--){
            leftshot = i;
        for(int k=0; k<6; k++){
        if((rooms[*level][roomsnum].mons[k].pos.x == i)&&(rooms[*level][roomsnum].mons[k].pos.y == player->y)){
            rooms[*level][roomsnum].mons[k].hp -= 5;
            if(game->isdamagespell == 1)
                        rooms[*level][roomsnum].mons[k].hp -= 5;
            ishit =1;
            *hittype =2;
            *invalid =0;
            if(rooms[*level][roomsnum].mons[k].hp <= 0){
            map[*level][i][player->y] = '.';
            rooms[*level][roomsnum].mons[k].pos.x =-1;
            rooms[*level][roomsnum].mons[k].pos.y = -1;
            }
            break;
        }
        }
        if(ishit)
        break;
      }
      if(ishit ==0){
    *hittype = 0;
    *invalid =0;
      map[*level][leftshot][player->y] = 'a';
      }
      game->wlist[3].count--;
      break;
    }
    
    else if(key == 's'){
      for(int i =player->y; (i<rooms[*level][roomsnum].bottomleft.y) && (i<= player->y +5)&&(map[*level][player->x][i] != 'O')&&(map[*level][player->x][i] != '&')&&(map[*level][player->x][i] != 'E'); i++){
        downshot = i ;
        for(int k=0; k<6; k++){
        if((rooms[*level][roomsnum].mons[k].pos.x == player->x)&&(rooms[*level][roomsnum].mons[k].pos.y == i)){
            rooms[*level][roomsnum].mons[k].hp -= 5;
            if(game->isdamagespell == 1)
                        rooms[*level][roomsnum].mons[k].hp -= 5;
            ishit =1;
            *hittype =2;
            *invalid =0;
            if(rooms[*level][roomsnum].mons[k].hp <= 0){
            map[*level][player->x][i] = '.';
            rooms[*level][roomsnum].mons[k].pos.x =-1;
            rooms[*level][roomsnum].mons[k].pos.y = -1;
            }
            break;
        }
        }
        if(ishit)
        break;
      }
      if(ishit ==0){
    *hittype = 0;
    *invalid =0;
         map[*level][player->x][downshot] = 'a';
      }
      game->wlist[3].count--;
      break;
    }
    
    else if(key == 'd'){
               for(int i =player->x; (i<rooms[*level][roomsnum].topright.x) && (i<= player->x +5)&&(map[*level][i][player->y] != 'O')&&(map[*level][i][player->y] != '&')&&(map[*level][i][player->y] != 'E'); i++){
                rightshot = i;
        for(int k=0; k<6; k++){
        if((rooms[*level][roomsnum].mons[k].pos.x == i)&&(rooms[*level][roomsnum].mons[k].pos.y == player->y)){
            rooms[*level][roomsnum].mons[k].hp -= 5;
            if(game->isdamagespell == 1)
                        rooms[*level][roomsnum].mons[k].hp -= 5;
            ishit =1;
            *hittype =2;
            *invalid =0;
            if(rooms[*level][roomsnum].mons[k].hp <= 0){
            map[*level][i][player->y] = '.';
            rooms[*level][roomsnum].mons[k].pos.x =-1;
            rooms[*level][roomsnum].mons[k].pos.y = -1;
            }
            break;
        }
        }
        if(ishit)
        break;
      }
      if(ishit ==0){
    *hittype = 0;
    *invalid =0;
        map[*level][rightshot][player->y] = 'a';
      }
      game->wlist[3].count--;
      break;
    }
  
    else if((key != ERR)&&(key != 32)){
        handleinput(player, map, key, rooms, playerhp, level, invalid, password, passwordmode, passend, ancient, brokenancient, save, color, game, dontpick, win, newroom,0, hittype, monshp, spellcounter, isspeed, fire);
        break;
    }
    
        
   
    }
    
    } 
    else{
        *hittype =0;
        *invalid =1;
      }
    
    if(game->wlist[3].count ==0){
        game->wlist[3].isactive =0;
        game->wlist[0].isactive =1;

    }
     
        }
     
        else if(game->wlist[4].isactive == 1){
            int ishit =0;
            for(int i =player->x -1; i<player->x + 2; i++){
                for(int j = player->y -1; j<player->y +2; j++){
                    for(int k = 0 ; k<6; k++){
                    if((rooms[*level][roomsnum].mons[k].pos.x == i)&&(rooms[*level][roomsnum].mons[k].pos.y == j)){
                        rooms[*level][roomsnum].mons[k].hp -= 10;
                        if(game->isdamagespell == 1)
                        rooms[*level][roomsnum].mons[k].hp -= 10;
                        if(rooms[*level][roomsnum].mons[k].hp<=0){
                        rooms[*level][roomsnum].mons[k].hp =0;
                        map[*level][i][j] = '.';
                        rooms[*level][roomsnum].mons[k].pos.x = -1;
                        rooms[*level][roomsnum].mons[k].pos.y = -1;
                        }
                        ishit =1;
                        *monshp = rooms[*level][roomsnum].mons[k].hp;
                        *hittype = 2;
                    }
                    }
                }
            }
            if(ishit ==0){
                        *hittype = 0;
            }
            game->lastkey = 0;
        }
    

    }

    else if(input == 123){

         if((game->wlist[1].isactive ==1) ){
            int ishit =0;
            int key = game->lastkey;
            game->lastkey = key;
            if((game->wlist[1].count>=1)){
                
            while(1){
        printmap(map[*level], *player, color, rooms[*level], game->realmap[*level], *level);
        refresh();
      if(key == 'w'){
      for(int i =player->y; (i>rooms[*level][roomsnum].topleft.y) && (i>= player->y -5)&&(map[*level][player->x][i] != 'O')&&(map[*level][player->x][i] != '&')&&(map[*level][player->x][i] != 'E')&&(map[*level][player->x][i] != 'O')&&(map[*level][player->x][i] != '&')&&(map[*level][player->x][i] != 'E'); i--){
        upshot =i;
        for(int k=0; k<6; k++){
        if((rooms[*level][roomsnum].mons[k].pos.x == player->x)&&(rooms[*level][roomsnum].mons[k].pos.y == i)){
            rooms[*level][roomsnum].mons[k].hp -= 12;
            if(game->isdamagespell == 1)
            rooms[*level][roomsnum].mons[k].hp -= 12;
            ishit =1;
            *hittype =2;
            *invalid =0;
            if(rooms[*level][roomsnum].mons[k].hp <= 0){
            map[*level][player->x][i] = '.';
            rooms[*level][roomsnum].mons[k].pos.x =-1;
            rooms[*level][roomsnum].mons[k].pos.y = -1;
            }
            break;
        }
        }
        if(ishit)
        break;
      }
      if(ishit ==0){
    *hittype = 0;
    *invalid =0;
        map[*level][player->x][upshot] = 'k';
      }
      game->wlist[1].count--;
      break;

      }

   else if(key == 'a'){
         for(int i =player->x; (i>rooms[*level][roomsnum].topleft.x) && (i>= player->x -5)&&(map[*level][i][player->y] != 'O')&&(map[*level][i][player->y] != '&')&&(map[*level][i][player->y] != 'E'); i--){
            leftshot =i;
        for(int k=0; k<6; k++){
        if((rooms[*level][roomsnum].mons[k].pos.x == i)&&(rooms[*level][roomsnum].mons[k].pos.y == player->y)){
            rooms[*level][roomsnum].mons[k].hp -= 12;
            if(game->isdamagespell == 1)
                        rooms[*level][roomsnum].mons[k].hp -= 12;
            ishit =1;
            *hittype =2;
            *invalid =0;
            if(rooms[*level][roomsnum].mons[k].hp <= 0){
            map[*level][i][player->y] = '.';
            rooms[*level][roomsnum].mons[k].pos.x =-1;
            rooms[*level][roomsnum].mons[k].pos.y = -1;
            }
            break;
        }
        }
        if(ishit)
        break;
      }
      if(ishit ==0){
    *hittype = 0;
    *invalid =0;
        map[*level][leftshot][player->y] = 'k';
      }
      game->wlist[1].count--;
      break;
    }
    
    else if(key == 's'){
      for(int i =player->y; (i<rooms[*level][roomsnum].bottomleft.y) && (i<= player->y +5)&&(map[*level][player->x][i] != 'O')&&(map[*level][player->x][i] != '&')&&(map[*level][player->x][i] != 'E'); i++){
        downshot = i;
        for(int k=0; k<6; k++){
        if((rooms[*level][roomsnum].mons[k].pos.x == player->x)&&(rooms[*level][roomsnum].mons[k].pos.y == i)){
            rooms[*level][roomsnum].mons[k].hp -= 12;
            if(game->isdamagespell == 1)
                        rooms[*level][roomsnum].mons[k].hp -= 12;
            ishit =1;
            *hittype =2;
            *invalid =0;
            if(rooms[*level][roomsnum].mons[k].hp <= 0){
            map[*level][player->x][i] = '.';
            rooms[*level][roomsnum].mons[k].pos.x =-1;
            rooms[*level][roomsnum].mons[k].pos.y = -1;
            }
            break;
        }
        }
        if(ishit)
        break;
      }
      if(ishit ==0){
    *hittype = 0;
    *invalid =0;
        map[*level][player->x][downshot] = 'k';
      }
      game->wlist[1].count--;
      break;
    }
    
    else if(key == 'd'){
               for(int i =player->x; (i<rooms[*level][roomsnum].topright.x) && (i<= player->x +5)&&(map[*level][i][player->y] != 'O')&&(map[*level][i][player->y] != '&')&&(map[*level][i][player->y] != 'E'); i++){
                rightshot = i;
        for(int k=0; k<6; k++){
        if((rooms[*level][roomsnum].mons[k].pos.x == i)&&(rooms[*level][roomsnum].mons[k].pos.y == player->y)){
            rooms[*level][roomsnum].mons[k].hp -= 12;
            if(game->isdamagespell == 1)
                        rooms[*level][roomsnum].mons[k].hp -= 12;
            ishit =1;
            *hittype =2;
            *invalid =0;
            if(rooms[*level][roomsnum].mons[k].hp <= 0){
            map[*level][i][player->y] = '.';
            rooms[*level][roomsnum].mons[k].pos.x =-1;
            rooms[*level][roomsnum].mons[k].pos.y = -1;
            }
            break;
        }
        }
        if(ishit)
        break;
      }
      if(ishit ==0){
    *hittype = 0;
    *invalid =0;
        map[*level][rightshot][player->y] = 'k';
      }
      game->wlist[1].count--;
      break;
    }
  
    else if((key != ERR)&&(key != 32)){
        handleinput(player, map, key, rooms, playerhp, level, invalid, password, passwordmode, passend, ancient, brokenancient, save, color, game, dontpick, win, newroom,0, hittype, monshp, spellcounter, isspeed, fire);
        break;
    }
    
    }
    
    } 
    else{
        *hittype =0;
        *invalid =1;
      }
    
    if(game->wlist[1].count ==0){
        game->wlist[1].isactive =0;
        game->wlist[0].isactive =1;

    }

 
       
        }
       
        else if((game->wlist[2].isactive ==1) ){
            int ishit =0;
            int key = game->lastkey;
            game->lastkey = key;
            if((game->wlist[2].count>=1)){

            while(1){
        printmap(map[*level], *player, color, rooms[*level], game->realmap[*level], *level);
        refresh();
      if(key == 'w'){
      for(int i =player->y; (i>rooms[*level][roomsnum].topleft.y) && (i>= player->y -10)&&(map[*level][player->x][i] != 'O')&&(map[*level][player->x][i] != '&')&&(map[*level][player->x][i] != 'E'); i--){
        upshot = i;
        for(int k=0; k<6; k++){
        if((rooms[*level][roomsnum].mons[k].pos.x == player->x)&&(rooms[*level][roomsnum].mons[k].pos.y == i)){
            rooms[*level][roomsnum].mons[k].hp -= 15;
            if(game->isdamagespell == 1)
                        rooms[*level][roomsnum].mons[k].hp -= 15;
            ishit =1;
            rooms[*level][roomsnum].mons[k].dontmove =1;
            *hittype =2;
            *invalid =0;
            if(rooms[*level][roomsnum].mons[k].hp <= 0){
            map[*level][player->x][i] = '.';
            rooms[*level][roomsnum].mons[k].pos.x =-1;
            rooms[*level][roomsnum].mons[k].pos.y = -1;
            }
            break;
        }
        }
        if(ishit)
        break;
      }
      if(ishit ==0){
    *hittype = 0;
    *invalid =0;
        map[*level][player->x][upshot] = 'm';
      }
      game->wlist[2].count--;
      break;

      }
    
    else if(key == 'a'){
         for(int i =player->x; (i>rooms[*level][roomsnum].topleft.x) && (i>= player->x -10)&&(map[*level][i][player->y] != 'O')&&(map[*level][i][player->y] != '&')&&(map[*level][i][player->y] != 'E'); i--){
            leftshot = i;
        for(int k=0; k<6; k++){
        if((rooms[*level][roomsnum].mons[k].pos.x == i)&&(rooms[*level][roomsnum].mons[k].pos.y == player->y)){
            rooms[*level][roomsnum].mons[k].hp -= 15;
            if(game->isdamagespell == 1)
                        rooms[*level][roomsnum].mons[k].hp -= 15;
                   rooms[*level][roomsnum].mons[k].dontmove =1;     
            ishit =1;
            *hittype =2;
            *invalid =0;
            if(rooms[*level][roomsnum].mons[k].hp <= 0){
            map[*level][i][player->y] = '.';
            rooms[*level][roomsnum].mons[k].pos.x =-1;
            rooms[*level][roomsnum].mons[k].pos.y = -1;
            }
            break;
        }
        }
        if(ishit)
        break;
      }
      if(ishit ==0){
    *hittype = 0;
    *invalid =0;
         map[*level][leftshot][player->y] = 'm';
      }
      game->wlist[2].count--;
      break;
    }
    
    else if(key == 's'){
      for(int i =player->y; (i<rooms[*level][roomsnum].bottomleft.y) && (i<= player->y +10)&&(map[*level][player->x][i] != 'O')&&(map[*level][player->x][i] != '&')&&(map[*level][player->x][i] != 'E'); i++){
        downshot = i;
        for(int k=0; k<6; k++){
        if((rooms[*level][roomsnum].mons[k].pos.x == player->x)&&(rooms[*level][roomsnum].mons[k].pos.y == i)){
            rooms[*level][roomsnum].mons[k].hp -= 15;
            if(game->isdamagespell == 1)
                        rooms[*level][roomsnum].mons[k].hp -= 15;
                        rooms[*level][roomsnum].mons[k].dontmove =1;
            ishit =1;
            *hittype =2;
            *invalid =0;
            if(rooms[*level][roomsnum].mons[k].hp <= 0){
            map[*level][player->x][i] = '.';
            rooms[*level][roomsnum].mons[k].pos.x =-1;
            rooms[*level][roomsnum].mons[k].pos.y = -1;
            }
            break;
        }
        }
        if(ishit)
        break;
      }
      if(ishit ==0){
    *hittype = 0;
    *invalid =0;
        map[*level][player->x][downshot] = 'm';
      }
      game->wlist[2].count--;
      break;
    }
    
    else if(key == 'd'){
               for(int i =player->x; (i<rooms[*level][roomsnum].topright.x) && (i<= player->x +10)&&(map[*level][i][player->y] != 'O')&&(map[*level][i][player->y] != '&')&&(map[*level][i][player->y] != 'E'); i++){
                rightshot = i;
        for(int k=0; k<6; k++){
        if((rooms[*level][roomsnum].mons[k].pos.x == i)&&(rooms[*level][roomsnum].mons[k].pos.y == player->y)){
            rooms[*level][roomsnum].mons[k].hp -= 15;
            if(game->isdamagespell == 1)
                        rooms[*level][roomsnum].mons[k].hp -= 15;
                        rooms[*level][roomsnum].mons[k].dontmove =1;
            ishit =1;
            *hittype =2;
            *invalid =0;
            if(rooms[*level][roomsnum].mons[k].hp <= 0){
            map[*level][i][player->y] = '.';
            rooms[*level][roomsnum].mons[k].pos.x =-1;
            rooms[*level][roomsnum].mons[k].pos.y = -1;
            }
            break;
        }
        }
        if(ishit)
        break;
      }
      if(ishit ==0){
    *hittype = 0;
    *invalid =0;
         map[*level][rightshot][player->y] = 'm';
      }
      game->wlist[2].count--;
      break;
    
    }
  
    else if((key != ERR)&&(key != 32)){
        handleinput(player, map, key, rooms, playerhp, level, invalid, password, passwordmode, passend, ancient, brokenancient, save, color, game, dontpick, win, newroom,0, hittype, monshp, spellcounter, isspeed, fire);
        break;
    }
     
    }
    
    } 
    else{
        *hittype =0;
        *invalid =1;
      }

    if(game->wlist[2].count ==0){
        game->wlist[2].isactive =0;
        game->wlist[0].isactive =1;

    }    

            

    

        }
        
        else if((game->wlist[3].isactive ==1) ){
            int ishit =0;
            int key = game->lastkey;
            game->lastkey = key;
            if((game->wlist[3].count>=1)){

            while(1){
        printmap(map[*level], *player, color, rooms[*level], game->realmap[*level], *level);
        refresh();

      if(key == 'w'){
      for(int i =player->y; (i>rooms[*level][roomsnum].topleft.y) && (i>= player->y -5)&&(map[*level][player->x][i] != 'O')&&(map[*level][player->x][i] != '&')&&(map[*level][player->x][i] != 'E')&&(map[*level][player->x][i] != 'O')&&(map[*level][player->x][i] != '&')&&(map[*level][player->x][i] != 'E'); i--){
        upshot = i;
        for(int k=0; k<6; k++){
        if((rooms[*level][roomsnum].mons[k].pos.x == player->x)&&(rooms[*level][roomsnum].mons[k].pos.y == i)){
            rooms[*level][roomsnum].mons[k].hp -= 5;
            if(game->isdamagespell == 1)
                        rooms[*level][roomsnum].mons[k].hp -= 5;
            ishit =1;
            *hittype =2;
            *invalid =0;
            if(rooms[*level][roomsnum].mons[k].hp <= 0){
            map[*level][player->x][i] = '.';
            rooms[*level][roomsnum].mons[k].pos.x =-1;
            rooms[*level][roomsnum].mons[k].pos.y = -1;
            }
            break;
        }
        }
        if(ishit)
        break;
      }
      if(ishit ==0){
    *hittype = 0;
    *invalid =0;

            map[*level][player->x][upshot] = 'a'; 

      }
      game->wlist[3].count--;
      break;

      }
    
    else if(key == 'a'){
         for(int i =player->x; (i>rooms[*level][roomsnum].topleft.x) && (i>= player->x -5)&&(map[*level][i][player->y] != 'O')&&(map[*level][i][player->y] != '&')&&(map[*level][i][player->y] != 'E'); i--){
            leftshot = i;
        for(int k=0; k<6; k++){
        if((rooms[*level][roomsnum].mons[k].pos.x == i)&&(rooms[*level][roomsnum].mons[k].pos.y == player->y)){
            rooms[*level][roomsnum].mons[k].hp -= 5;
            if(game->isdamagespell == 1)
                        rooms[*level][roomsnum].mons[k].hp -= 5;
            ishit =1;
            *hittype =2;
            *invalid =0;
            if(rooms[*level][roomsnum].mons[k].hp <= 0){
            map[*level][i][player->y] = '.';
            rooms[*level][roomsnum].mons[k].pos.x =-1;
            rooms[*level][roomsnum].mons[k].pos.y = -1;
            }
            break;
        }
        }
        if(ishit)
        break;
      }
      if(ishit ==0){
    *hittype = 0;
    *invalid =0;
      map[*level][leftshot][player->y] = 'a';
      }
      game->wlist[3].count--;
      break;
    }
    
    else if(key == 's'){
      for(int i =player->y; (i<rooms[*level][roomsnum].bottomleft.y) && (i<= player->y +5)&&(map[*level][player->x][i] != 'O')&&(map[*level][player->x][i] != '&')&&(map[*level][player->x][i] != 'E'); i++){
        downshot = i +1;
        for(int k=0; k<6; k++){
        if((rooms[*level][roomsnum].mons[k].pos.x == player->x)&&(rooms[*level][roomsnum].mons[k].pos.y == i)){
            rooms[*level][roomsnum].mons[k].hp -= 5;
            if(game->isdamagespell == 1)
                        rooms[*level][roomsnum].mons[k].hp -= 5;
            ishit =1;
            *hittype =2;
            *invalid =0;
            if(rooms[*level][roomsnum].mons[k].hp <= 0){
            map[*level][player->x][i] = '.';
            rooms[*level][roomsnum].mons[k].pos.x =-1;
            rooms[*level][roomsnum].mons[k].pos.y = -1;
            }
            break;
        }
        }
        if(ishit)
        break;
      }
      if(ishit ==0){
    *hittype = 0;
    *invalid =0;
         map[*level][player->x][downshot] = 'a';
      }
      game->wlist[3].count--;
      break;
    }
    
    else if(key == 'd'){
               for(int i =player->x; (i<rooms[*level][roomsnum].topright.x) && (i<= player->x +5)&&(map[*level][i][player->y] != 'O')&&(map[*level][i][player->y] != '&')&&(map[*level][i][player->y] != 'E'); i++){
                rightshot = i;
        for(int k=0; k<6; k++){
        if((rooms[*level][roomsnum].mons[k].pos.x == i)&&(rooms[*level][roomsnum].mons[k].pos.y == player->y)){
            rooms[*level][roomsnum].mons[k].hp -= 5;
            if(game->isdamagespell == 1)
                        rooms[*level][roomsnum].mons[k].hp -= 5;
            ishit =1;
            *hittype =2;
            *invalid =0;
            if(rooms[*level][roomsnum].mons[k].hp <= 0){
            map[*level][i][player->y] = '.';
            rooms[*level][roomsnum].mons[k].pos.x =-1;
            rooms[*level][roomsnum].mons[k].pos.y = -1;
            }
            break;
        }
        }
        if(ishit)
        break;
      }
      if(ishit ==0){
    *hittype = 0;
    *invalid =0;
        map[*level][rightshot][player->y] = 'a';
      }
      game->wlist[3].count--;
      break;
    }
  
    else if((key != ERR)&&(key != 32)){
        handleinput(player, map, key, rooms, playerhp, level, invalid, password, passwordmode, passend, ancient, brokenancient, save, color, game, dontpick, win, newroom,0, hittype, monshp, spellcounter, isspeed, fire);
        break;
    }
    
        
   
    }
    
    } 
    else{
        *hittype =0;
        *invalid =1;
      }
    
    if(game->wlist[3].count ==0){
        game->wlist[3].isactive =0;
        game->wlist[0].isactive =1;

    }
     
        }
   
    }

    else if((input == 'h') && (map[*level][player->x][player->y] == '<')){
        if(*level == 0){
        *level =1;
        player->x = rooms[*level][5].bottomright.x-1;
        player->y = rooms[*level][5].bottomright.y-1;}
        else if(*level == 1){
            if((player->y ==(rooms[*level][5].bottomright.y -1 ))){
            *level =0;
        player->x = rooms[*level][5].bottomright.x-1;
        player->y = rooms[*level][5].bottomright.y-1;
        }
        else{
        
            *level = 2;
            player->x = rooms[*level][2].topleft.x+1;
            player->y = rooms[*level][2].topleft.y+1;
        }

        }
        else if(*level == 2){
            if(player->x == rooms[*level][2].topleft.x + 1){
                *level = 1;
                player->x =rooms[*level][2].topleft.x + 1;
                player->y =rooms[*level][2].topleft.y + 1;
            }
            else{
                *level= 3;
                player->x =rooms[*level][3].bottomleft.x + 1;
                player->y = rooms[*level][3].bottomleft.y - 1;
            }
        }
        else if(*level == 3){
            *level = 2;
                player->x =rooms[*level][3].bottomleft.x + 1;
                player->y = rooms[*level][3].bottomleft.y - 1;
        }
    }
    
    else{
       *invalid = 1;
    }
    
    if(!((*isspeed)&&(*spellcounter <= 11))){
    if((map[*level][player->x][player->y ] == '.') || (map[*level][player->x][player->y ] == '+') || (map[*level][player->x][player->y ] == '#') ||(map[*level][player->x][player->y ] == '=') ||(map[*level][player->x][player->y ] == '^')||(map[*level][player->x][player->y ] == '?') || (map[*level][player->x][player->y ] == '<') || (map[*level][player->x][player->y ] == '&') ||(map[*level][player->x][player->y ] == '@') || (map[*level][player->x][player->y ] == 'd')|| (map[*level][player->x][player->y ] == '$')|| (map[*level][player->x][player->y ] == 'E')|| (map[*level][player->x][player->y ] == 'b')||(map[*level][player->x][player->y ] == 'f') ||((map[*level][player->x][player->y ] >= '1')&& (map[*level][player->x][player->y ] <= '8')) ||(map[*level][player->x][player->y ] == 'k')||(map[*level][player->x][player->y ] == 'a')||(map[*level][player->x][player->y ] == 'm')||(map[*level][player->x][player->y ] == 'L')||(map[*level][player->x][player->y ] == 'J')||(map[*level][player->x][player->y ] == 'I')){
        }
    
        else{
            player->x = copyx;
            player->y = copyy;
        }
}
else{
    if(playercheck(map, player->x, player->y, level)){
        if(input =='a'){
            if(playercheck(map, player->x+1, player->y, level)){

            }
            else{
            player->x = copyx;
            player->y = copyy;
        }

        }
        
        else if(input =='w'){
            if(playercheck(map, player->x, player->y+1, level)){

            }
            else{
            player->x = copyx;
            player->y = copyy;
        }

        }
        
        else if(input =='s'){
            if(playercheck(map, player->x, player->y-1, level)){

            }
            else{
            player->x = copyx;
            player->y = copyy;
        }

        }
        
        else if(input =='d'){
            if(playercheck(map, player->x-1, player->y, level)){

            }
            else{
            player->x = copyx;
            player->y = copyy;
        }

        }
       
        else if(input =='q'){
            if(playercheck(map, player->x+1, player->y+1, level)){

            }
            else{
            player->x = copyx;
            player->y = copyy;
        }

        }
        
        else if(input =='e'){
            if(playercheck(map, player->x-1, player->y+1, level)){

            }
            else{
            player->x = copyx;
            player->y = copyy;
        }

        }
           
        else if(input =='z'){
            if(playercheck(map, player->x+1, player->y-1, level)){

            }
            else{
            player->x = copyx;
            player->y = copyy;
        }

        }
     
        else if(input =='c'){
            if(playercheck(map, player->x-1, player->y-1, level)){

            }
            else{
            player->x = copyx;
            player->y = copyy;
        }

        }
  
    }
     
     else{
            player->x = copyx;
            player->y = copyy;
        }
}

    if(map[*level][player ->x][player ->y] == '+'){
        if(((player ->x == rooms[*level][0].door[1].x) &&(player ->y == rooms[*level][0].door[1].y) ) ||(player ->x == rooms[*level][0].door[2].x) &&(player ->y == rooms[*level][0].door[2].y) ){
            if(rooms[*level][0].theme !=Nightmare)
            rooms[*level][0].isvisible =1;
            if(*level != 0)
            *newroom =1;
            for(int i =0; i<6; i++){
                rooms[*level][0].mons[i].movement =0;
            }
        }
        else if(((player ->x == rooms[*level][1].door[1].x ) &&(player ->y == rooms[*level][1].door[1].y )) ||((player ->x == rooms[*level][1].door[0].x ) &&(player ->y == rooms[*level][1].door[0].y )) || ((player ->x == rooms[*level][1].door[2].x ) &&(player ->y == rooms[*level][1].door[2].y ))){
            if(rooms[*level][1].theme !=Nightmare)
            rooms[*level][1].isvisible =1;
            *newroom =1;
            for(int i =0; i<6; i++){
                rooms[*level][1].mons[i].movement =0;
            }
        }
        else if((player ->x == rooms[*level][2].door[0].x ) && (player ->y == rooms[*level][2].door[0].y ) ){
            *newroom =1;
            if(rooms[*level][2].theme !=Nightmare)
            rooms[*level][2].isvisible =1;
            for(int i =0; i<6; i++){
                rooms[*level][2].mons[i].movement =0;
            }
        }
        else if(((player ->x == rooms[*level][3].door[3].x) &&(player ->y == rooms[*level][3].door[3].y) ) || ((player ->x == rooms[*level][3].door[1].x) &&(player ->y == rooms[*level][3].door[1].y) )){
            *newroom =1;
            if(rooms[*level][3].theme !=Nightmare)
            rooms[*level][3].isvisible =1;
            for(int i =0; i<6; i++){
                rooms[*level][3].mons[i].movement =0;
            }
        }
        else if(((player ->x == rooms[*level][4].door[3].x) &&(player ->y == rooms[*level][4].door[3].y)) || ((player ->x == rooms[*level][4].door[1].x) &&(player ->y == rooms[*level][4].door[1].y))||((player ->x == rooms[*level][4].door[0].x) &&(player ->y == rooms[*level][4].door[0].y)  )){
            *newroom =1;
            if(rooms[*level][4].theme !=Nightmare)
            rooms[*level][4].isvisible =1;
            for(int i =0; i<6; i++){
                rooms[*level][4].mons[i].movement =0;
            }
        }
         else if((player ->x == rooms[*level][5].door[0].x) &&(player ->y == rooms[*level][5].door[0].y) ){
            *newroom =1;
            if(rooms[*level][5].theme !=Nightmare)
            rooms[*level][5].isvisible =1;
            for(int i =0; i<6; i++){
                rooms[*level][5].mons[i].movement =0;
            }
        }

    }
    
    if(map[*level][player ->x][player ->y] == 'd'){
        if(!(*dontpick)){
            if(!(rooms[*level][roomsearch(rooms[*level], player->x, player->y)].theme  == Nightmare))
            *ancient = *ancient + 1;
           map[*level][player ->x][player ->y] = '.';}
           else
           *dontpick =0;
        

    }
   
    if(map[*level][player ->x][player ->y] == '='){
        if((rooms[*level][0].window.x == player ->x) && (rooms[*level][0].window.y == player ->y)){
            if(rooms[*level][3].theme != Nightmare)
            rooms[*level][3].isvisible =1;
        }
        else if((rooms[*level][1].window.x == player ->x) && (rooms[*level][1].window.y == player ->y)){
            if(rooms[*level][4].theme != Nightmare)
            rooms[*level][4].isvisible =1;
        }
        else if((rooms[*level][2].window.x == player -> x) && (rooms[*level][2].window.y == player -> y)){
            if(rooms[*level][5].theme != Nightmare)
            rooms[*level][5].isvisible =1;
        }
        player->x = copyx;
        player->y = copyy;
    }

    if(map[*level][player->x][player->y] == '?'){
       if((player->x == rooms[*level][1].door[1].x) &&(player->y == rooms[*level][1].door[1].y)){
            rooms[*level][1].ishiddend =0;
            *newroom =1;
            if(rooms[*level][1].theme !=Nightmare)
            rooms[*level][1].isvisible = 1;
        }
        else if((player->x == rooms[*level][4].door[1].x) &&(player->y == rooms[*level][4].door[1].y)){
            *newroom =1;
            rooms[*level][4].ishiddend =0;
            if(rooms[*level][4].theme !=Nightmare)
            rooms[*level][4].isvisible = 1;
        }

}
 
   if(map[*level][player->x][player->y] == '&'){
    save->x = player ->x;
    save->y = player ->y;
    *passwordmode = 1;
    *passend = 0;
}
   
   if(map[*level][player->x][player->y] == '@'){
    if(*level == 0){
        if(rooms[0][4].islocked == 0){
            *passend = 1; 
        }
        else if(*ancient >0){
             player->x = copyx;
             player->y = copyy;
             int broken = rand() % 10;
             if(broken == 2){
                *ancient = *ancient -1;
                *brokenancient = *brokenancient + 1;
                if((*brokenancient == 2)){
                   *brokenancient = 0;
                    *ancient = *ancient + 1;
                }
             }
             else{
            *ancient = *ancient -1;
            rooms[0][4].islocked =0;
            *passend= 1;}
        }
        else{
            if(passwordcheck(password) == 1){
                for(int i= 0; i<4; i++){
                    password[i] = -1;
                }
                rooms[0][4].islocked =0;
                *passend= 1;
                map[*level][save->x ][save ->y] = '.';
            }
            else{
             
            }
             player->x = copyx;
             player->y = copyy;
        }
    }

    else if(*level == 1){
        if(rooms[1][1].islocked == 0){
*passend = 1; 
        }
         else if(*ancient > 0){
            player->x = copyx;
             player->y = copyy;
             int broken = rand() % 10;
             if(broken == 2){
                *ancient = *ancient -1;
                *brokenancient = *brokenancient + 1;
                if(*brokenancient == 2){
                   *brokenancient = 0;
                    *ancient = *ancient + 1;
                }
             }
             else{
            *ancient = *ancient -1;
            rooms[1][1].islocked =0;
            *passend= 1;}
        }
        else{
            if(passwordcheck(password) == 1){
                for(int i= 0; i<4; i++){
                    password[i] = -1;
                }
                rooms[1][1].islocked =0;
                *passend = 1; 
                map[*level][save->x ][save ->y] = '.';
            }
            else{
            }
            player->x = copyx;
             player->y = copyy;
        }
    }

    else if(*level == 2){
        if(rooms[2][4].islocked == 0){
*passend = 1; 
        }
         else if(*ancient >0){
            player->x = copyx;
             player->y = copyy;
             int broken = rand() % 10;
             if(broken == 2){
               *ancient = *ancient -1;
                *brokenancient = *brokenancient + 1;
                if(*brokenancient == 2){
                   *brokenancient = 0;
                    *ancient = *ancient +1;
                }
             }
             else{
            *ancient = *ancient -1;
            rooms[2][4].islocked =0;
            *passend= 1;}
        }
        else{
            if(passwordcheck(password) == 1){
                for(int i= 0; i<4; i++){
                    password[i] = -1;
                }
                if(rooms[2][4].islocked == 1 ){
                  rooms[2][4].islocked =2;  
                  *passend =1;}
                else{
                rooms[2][4].islocked =0;
                *passend = 1; }
                map[*level][save->x ][save ->y] = '.';
            }
            else{
            }
                player->x = copyx;
             player->y = copyy;
        }
    }

    else if(*level == 3){
        if(rooms[3][3].islocked == 0){
*passend = 1; 
        }
         else if(*ancient >0){
            player->x = copyx;
             player->y = copyy;
             int broken = rand() % 10;
             if(broken == 2){
               *ancient = *ancient -1;
                *brokenancient = *brokenancient + 1;
                if(*brokenancient == 2){
                   *brokenancient = 0;
                    *ancient = *ancient +1;
                }
             }
             else{
           *ancient = *ancient -1;
            rooms[3][3].islocked =0;
            *passend= 1;}
        }
        else{

            if(passwordcheck(password) == 1){

                for(int i= 0; i<4; i++){
                    password[i] = -1;
                }
                if(rooms[3][3].islocked == 1){
                    rooms[3][3].islocked =2;
                    *passend =1;
                }
                else{
                rooms[3][3].islocked =0;
                *passend = 1; }
                 map[*level][save->x ][save ->y] = '.';
            }
            else{
              
            }
                player->x = copyx;
             player->y = copyy;
        }
    }
}

if(map[*level][player->x][player->y] == '$'){
    if(!(*dontpick)){
    game->gold = game->gold + rooms[*level][roomsearch(rooms[*level], player->x, player->y)].goldamount;
    rooms[*level][roomsearch(rooms[*level], player->x, player->y)].goldamount =0;
    map[*level][player->x][player->y] = '.';}
    else
    *dontpick =0;
}

if(map[*level][player->x][player->y] == 'b'){
    if(!(*dontpick)){
    game->gold = game->gold + rooms[*level][roomsearch(rooms[*level], player->x, player->y)].goldamount;
    rooms[*level][roomsearch(rooms[*level], player->x, player->y)].goldamount =0;
    map[*level][player->x][player->y] = '.';}
    else
           *dontpick =0;
}

if(map[*level][player->x][player->y] == 'E'){
    int winner = 1;
    for(int i=0; i<6; i++){
        if(!(rooms[*level][roomsnum].mons[i].hp<=0))
        winner =0;
    }
    if(winner){
    game->endgame =1;
    *win =1;}
}

if(map[*level][player->x][player->y] == '#'){
            game->realmap[*level][player->x][player->y] = '#';    
        }

if(map[*level][player->x][player->y] == 'f'){
    if(!(*dontpick)){
    if(game->foodamount<5){
        if(rooms[*level][roomsearch(rooms[*level], player->x, player->y)].theme != Nightmare){
        game->flist[game->foodamount].hpamount =10;
       strcpy(game->flist[game->foodamount].name ,"Normal");
       game->flist[game->foodamount].ftime = time(NULL);
         game->foodamount= game->foodamount + 1;}
         map[*level][player->x][player->y] = '.';
    }}
    else
    *dontpick =0;
}
 
if(map[*level][player->x][player->y] == 'L'){
    if(!(*dontpick)){
    if(game->foodamount<5){
        if(rooms[*level][roomsearch(rooms[*level], player->x, player->y)].theme != Nightmare){
        game->flist[game->foodamount].hpamount =16;
        game->flist[game->foodamount].fkind =GREAT;
       strcpy(game->flist[game->foodamount].name ,"Great");
        game->flist[game->foodamount].ftime = time(NULL);
         game->foodamount= game->foodamount + 1;}
         map[*level][player->x][player->y] = '.';
    }}
    else
    *dontpick =0;
}
 
if(map[*level][player->x][player->y] == 'J'){
    if(!(*dontpick)){
    if(game->foodamount<5){
        if(rooms[*level][roomsearch(rooms[*level], player->x, player->y)].theme != Nightmare){
        game->flist[game->foodamount].hpamount =20;
        game->flist[game->foodamount].fkind =MAGIC;
       strcpy(game->flist[game->foodamount].name ,"Magic");
        game->flist[game->foodamount].ftime = time(NULL);
         game->foodamount= game->foodamount + 1;}
         map[*level][player->x][player->y] = '.';
    }}
    else
    *dontpick =0;
}
 
if(map[*level][player->x][player->y] == 'I'){
    if(!(*dontpick)){
    if(game->foodamount<5){
        if(rooms[*level][roomsearch(rooms[*level], player->x, player->y)].theme != Nightmare){
        game->flist[game->foodamount].hpamount = -5;
        game->flist[game->foodamount].fkind =POISENOUS;
       strcpy(game->flist[game->foodamount].name ,"Normal");
        game->flist[game->foodamount].ftime = time(NULL);
         game->foodamount= game->foodamount + 1;}
         map[*level][player->x][player->y] = '.';
    }}
    else
    *dontpick =0;
}
  
 if(((map[*level][player->x][player->y ] >= '1')&& (map[*level][player->x][player->y ] <= '5')) || (map[*level][player->x][player->y ] == 'k')|| (map[*level][player->x][player->y ] == 'm')|| (map[*level][player->x][player->y ] == 'a')){
    if(!(*dontpick)&& (!dontchoose)){
    while(1){
        printmap(map[*level], *player, color, rooms[*level], game->realmap[*level], *level);
        refresh();
    int key = getch();
    if(key == 'p'){ 
    if(map[*level][player->x][player->y ] == '1'){
        if(rooms[*level][roomsearch(rooms[*level], player->x, player->y)].theme !=Nightmare)
        game->wlist[0].count = game->wlist[0].count + 1;
        map[*level][player->x][player->y ] = '.';
    }
    else if(map[*level][player->x][player->y ] == '2'){
         map[*level][player->x][player->y ] = '.';
         if(rooms[*level][roomsearch(rooms[*level], player->x, player->y)].theme !=Nightmare)
         game->wlist[1].count = game->wlist[1].count + 10;
    }
    else if(map[*level][player->x][player->y ] == '3'){
         map[*level][player->x][player->y ] = '.';
         if(rooms[*level][roomsearch(rooms[*level], player->x, player->y)].theme !=Nightmare)
         game->wlist[2].count = game->wlist[2].count + 8;
    }
    else if(map[*level][player->x][player->y ] == '4'){
         map[*level][player->x][player->y ] = '.';
         if(rooms[*level][roomsearch(rooms[*level], player->x, player->y)].theme !=Nightmare)
         game->wlist[3].count = game->wlist[3].count + 20;
    }
    else if(map[*level][player->x][player->y ] == '5'){
        map[*level][player->x][player->y ] = '.';
        if(rooms[*level][roomsearch(rooms[*level], player->x, player->y)].theme !=Nightmare)
        game->wlist[4].count = 1;
    }
    else if(map[*level][player->x][player->y ] == 'k'){
         map[*level][player->x][player->y ] = '.';
         if(rooms[*level][roomsearch(rooms[*level], player->x, player->y)].theme !=Nightmare)
         game->wlist[1].count = game->wlist[1].count + 1;
    }
    else if(map[*level][player->x][player->y ] == 'm'){
         map[*level][player->x][player->y ] = '.';
         if(rooms[*level][roomsearch(rooms[*level], player->x, player->y)].theme !=Nightmare)
         game->wlist[2].count = game->wlist[2].count + 1;
    }
    else if(map[*level][player->x][player->y ] == 'a'){
         map[*level][player->x][player->y ] = '.';
         if(rooms[*level][roomsearch(rooms[*level], player->x, player->y)].theme !=Nightmare)
         game->wlist[3].count = game->wlist[3].count + 1;
    }
    *fire =1;
    break;
    }
    else if(key != ERR){
        handleinput(player, map, key, rooms, playerhp, level, invalid, password, passwordmode, passend, ancient, brokenancient, save, color, game, dontpick, win, newroom,0, hittype, monshp, spellcounter, isspeed, fire);
        break;
    }
    }}
    else
    *dontpick =0;
 }

if((map[*level][player->x][player->y ] >= '6')&& (map[*level][player->x][player->y ] <= '8')){
    if(!(*dontpick)&& (!dontchoose)){
    while(1){
        printmap(map[*level], *player, color, rooms[*level], game->realmap[*level], *level);
        refresh();
    int key = getch();
    if(key == 'p'){ 
    if(map[*level][player->x][player->y ] == '6'){
        if(rooms[*level][roomsearch(rooms[*level], player->x, player->y)].theme !=Nightmare){
        game->slist[0].count = game->slist[0].count + 1;
        *fire =2;
        *hittype =0; 
        *invalid =0;
        }
        map[*level][player->x][player->y ] = '.';
    }
    else if(map[*level][player->x][player->y ] == '7'){
         map[*level][player->x][player->y ] = '.';
         if(rooms[*level][roomsearch(rooms[*level], player->x, player->y)].theme !=Nightmare){
         game->slist[1].count = game->slist[1].count + 1;
         *fire =2;
        *hittype =0; 
        *invalid =0;}
    }
    else if(map[*level][player->x][player->y ] == '8'){
         map[*level][player->x][player->y ] = '.';
         if(rooms[*level][roomsearch(rooms[*level], player->x, player->y)].theme !=Nightmare){
         game->slist[2].count = game->slist[2].count + 1;
         *fire =2;
        *hittype =0; 
        *invalid =0;}
    }
    break;
    }
    else if(key != ERR){
        handleinput(player, map, key, rooms, playerhp, level, invalid, password, passwordmode, passend, ancient, brokenancient, save, color, game, dontpick, win, newroom,0, hittype, monshp, spellcounter, isspeed, fire);
        break;
    }
    }}
    else
    *dontpick =0;
 }

 for(int i =0; i<6; i++){
        if(rooms[*level][i].istrap ==1){
            if(rooms[*level][i].theme == Treasure){
                 for(int j =0; j<4; j++){
            if((player ->x == rooms[*level][i].trap[j].x) && (player ->y == rooms[*level][i].trap[j].y)){
                map[*level][player->x][player->y] = '^';
                *playerhp = *playerhp -5;
            }}
            }
            for(int j =0; j<2; j++){
            if((player ->x == rooms[*level][i].trap[j].x) && (player ->y == rooms[*level][i].trap[j].y)){
                map[*level][player->x][player->y] = '^';
                *playerhp = *playerhp -5;
            }}
        }
    }

if((input == 32)||(input == 'w')||(input == 'a')||(input == 's')||(input == 'd')||(input == 'q')||(input == 'e')||(input == 'z')||(input == 'c')){

for(int i=0; i<6; i++){
    if(rooms[*level][roomsnum].mons[i].hp>0){
        if(((player->x==rooms[*level][roomsnum].mons[i].pos.x)||(player->x==rooms[*level][roomsnum].mons[i].pos.x+1)||(player->x==rooms[*level][roomsnum].mons[i].pos.x-1))&&((player->y==rooms[*level][roomsnum].mons[i].pos.y)||(player->y==rooms[*level][roomsnum].mons[i].pos.y+1)||(player->y==rooms[*level][roomsnum].mons[i].pos.y-1))){
            game->playerhp -= (rooms[*level][roomsnum].mons[i].kind + 1) *1;
            game->recover =0;
            *hittype =1;
        }
        else{
            if(((rooms[*level][roomsnum].mons[i].kind == GIANT )||(rooms[*level][roomsnum].mons[i].kind == UNDEED)||(rooms[*level][roomsnum].mons[i].kind == SNAKE))&&(rooms[*level][roomsnum].mons[i].dontmove ==0)){
            
            if((player->x > rooms[*level][roomsnum].mons[i].pos.x + 1)&&(game->map[*level][rooms[*level][roomsnum].mons[i].pos.x + 1][rooms[*level][roomsnum].mons[i].pos.y] == '.')){
                if((rooms[*level][roomsnum].mons[i].kind == GIANT )&& (rooms[*level][roomsnum].mons[i].movement <5)){
                game->map[*level][rooms[*level][roomsnum].mons[i].pos.x + 1][rooms[*level][roomsnum].mons[i].pos.y] = 'G';
                rooms[*level][roomsnum].mons[i].movement++;
                 game->map[*level][rooms[*level][roomsnum].mons[i].pos.x][rooms[*level][roomsnum].mons[i].pos.y] = '.';
                rooms[*level][roomsnum].mons[i].pos.x++;
                }
                else if((rooms[*level][roomsnum].mons[i].kind == UNDEED )&& (rooms[*level][roomsnum].mons[i].movement <5)){
                game->map[*level][rooms[*level][roomsnum].mons[i].pos.x + 1][rooms[*level][roomsnum].mons[i].pos.y] = 'U';
                rooms[*level][roomsnum].mons[i].movement++;
                 game->map[*level][rooms[*level][roomsnum].mons[i].pos.x][rooms[*level][roomsnum].mons[i].pos.y] = '.';
                rooms[*level][roomsnum].mons[i].pos.x++;
                }
                if((rooms[*level][roomsnum].mons[i].kind == SNAKE )){
                game->map[*level][rooms[*level][roomsnum].mons[i].pos.x + 1][rooms[*level][roomsnum].mons[i].pos.y] = 'S';
                 game->map[*level][rooms[*level][roomsnum].mons[i].pos.x][rooms[*level][roomsnum].mons[i].pos.y] = '.';
                rooms[*level][roomsnum].mons[i].pos.x++;
                }
            }
            
           else if((player->y > rooms[*level][roomsnum].mons[i].pos.y + 1)&&(game->map[*level][rooms[*level][roomsnum].mons[i].pos.x ][rooms[*level][roomsnum].mons[i].pos.y+1] == '.')){
                if((rooms[*level][roomsnum].mons[i].kind == GIANT )&& (rooms[*level][roomsnum].mons[i].movement <5)){
                game->map[*level][rooms[*level][roomsnum].mons[i].pos.x][rooms[*level][roomsnum].mons[i].pos.y+1] = 'G';
                rooms[*level][roomsnum].mons[i].movement++;
                 game->map[*level][rooms[*level][roomsnum].mons[i].pos.x][rooms[*level][roomsnum].mons[i].pos.y] = '.';
                rooms[*level][roomsnum].mons[i].pos.y++;
                }
                else if((rooms[*level][roomsnum].mons[i].kind == UNDEED )&& (rooms[*level][roomsnum].mons[i].movement <5)){
                game->map[*level][rooms[*level][roomsnum].mons[i].pos.x][rooms[*level][roomsnum].mons[i].pos.y+1] = 'U';
                rooms[*level][roomsnum].mons[i].movement++;
                 game->map[*level][rooms[*level][roomsnum].mons[i].pos.x][rooms[*level][roomsnum].mons[i].pos.y] = '.';
                rooms[*level][roomsnum].mons[i].pos.y++;
                }
                if((rooms[*level][roomsnum].mons[i].kind == SNAKE )){
                game->map[*level][rooms[*level][roomsnum].mons[i].pos.x][rooms[*level][roomsnum].mons[i].pos.y+1] = 'S';
                 game->map[*level][rooms[*level][roomsnum].mons[i].pos.x][rooms[*level][roomsnum].mons[i].pos.y] = '.';
                rooms[*level][roomsnum].mons[i].pos.y++;
                }
            }
            
           else if((player->y < rooms[*level][roomsnum].mons[i].pos.y - 1)&&(game->map[*level][rooms[*level][roomsnum].mons[i].pos.x ][rooms[*level][roomsnum].mons[i].pos.y-1] == '.')){
                if((rooms[*level][roomsnum].mons[i].kind == GIANT )&& (rooms[*level][roomsnum].mons[i].movement <5)){
                game->map[*level][rooms[*level][roomsnum].mons[i].pos.x][rooms[*level][roomsnum].mons[i].pos.y-1] = 'G';
                rooms[*level][roomsnum].mons[i].movement++;
                 game->map[*level][rooms[*level][roomsnum].mons[i].pos.x][rooms[*level][roomsnum].mons[i].pos.y] = '.';
                rooms[*level][roomsnum].mons[i].pos.y--;
                }
                else if((rooms[*level][roomsnum].mons[i].kind == UNDEED )&& (rooms[*level][roomsnum].mons[i].movement <5)){
                game->map[*level][rooms[*level][roomsnum].mons[i].pos.x][rooms[*level][roomsnum].mons[i].pos.y-1] = 'U';
                rooms[*level][roomsnum].mons[i].movement++;
                 game->map[*level][rooms[*level][roomsnum].mons[i].pos.x][rooms[*level][roomsnum].mons[i].pos.y] = '.';
                rooms[*level][roomsnum].mons[i].pos.y--;
                }
                if((rooms[*level][roomsnum].mons[i].kind == SNAKE )){
                game->map[*level][rooms[*level][roomsnum].mons[i].pos.x][rooms[*level][roomsnum].mons[i].pos.y-1] = 'S';
                 game->map[*level][rooms[*level][roomsnum].mons[i].pos.x][rooms[*level][roomsnum].mons[i].pos.y] = '.';
                rooms[*level][roomsnum].mons[i].pos.y--;
                }
            }
                  
           else if((player->x < rooms[*level][roomsnum].mons[i].pos.x - 1)&&(game->map[*level][rooms[*level][roomsnum].mons[i].pos.x - 1][rooms[*level][roomsnum].mons[i].pos.y] == '.')){
                if((rooms[*level][roomsnum].mons[i].kind == GIANT )&& (rooms[*level][roomsnum].mons[i].movement <5)){
                game->map[*level][rooms[*level][roomsnum].mons[i].pos.x - 1][rooms[*level][roomsnum].mons[i].pos.y] = 'G';
                rooms[*level][roomsnum].mons[i].movement++;
                 game->map[*level][rooms[*level][roomsnum].mons[i].pos.x][rooms[*level][roomsnum].mons[i].pos.y] = '.';
                rooms[*level][roomsnum].mons[i].pos.x--;
                }
                else if((rooms[*level][roomsnum].mons[i].kind == UNDEED )&& (rooms[*level][roomsnum].mons[i].movement <5)){
                game->map[*level][rooms[*level][roomsnum].mons[i].pos.x - 1][rooms[*level][roomsnum].mons[i].pos.y] = 'U';
                rooms[*level][roomsnum].mons[i].movement++;
                 game->map[*level][rooms[*level][roomsnum].mons[i].pos.x][rooms[*level][roomsnum].mons[i].pos.y] = '.';
                rooms[*level][roomsnum].mons[i].pos.x--;
                }
                if((rooms[*level][roomsnum].mons[i].kind == SNAKE )){
                game->map[*level][rooms[*level][roomsnum].mons[i].pos.x - 1][rooms[*level][roomsnum].mons[i].pos.y] = 'S';
                 game->map[*level][rooms[*level][roomsnum].mons[i].pos.x][rooms[*level][roomsnum].mons[i].pos.y] = '.';
                rooms[*level][roomsnum].mons[i].pos.x--;
                }
            }
            
            
            }
        }

    }
    }

}

}

void printinfo(int hp, int level, int hits, int gold, int ancient, int brokenancient, int goldsave){
    attron(COLOR_PAIR(1) | A_BOLD);
    mvprintw(LINES -1, COLS/6 - 5, "LEVEL: %d", level + 1);
    mvprintw(LINES -1, 2*COLS/6-5 , "HITS: %d", hits);
    mvprintw(LINES -1, 3*COLS/6-5, "GOLD: %d", gold);
    mvprintw(LINES -1, 4*COLS/6-5, "ANCIENTKEYS: %d", ancient);
    mvprintw(LINES -1, 5*COLS/6-5, "BROKENKEYS: %d", brokenancient);
    attroff(COLOR_PAIR(1) | A_BOLD);
    if(gold != goldsave){
       attron(COLOR_PAIR(1));
    mvprintw(3, middle_x - 8, "YOU GOT %d GOLDS!", gold - goldsave);
    attroff(COLOR_PAIR(1));}
    

}

void pass(char password[],data game, int invalid, int isguest, char username[]){
    for(int i =0; i<4; i++){
        password[i] =  '0' + rand()%10;
    }
}

void reverspass(char password[], char copypass[]){
    for(int i =0; i<4; i++){
        copypass[3 - i] = 'a';
    }
}

void makepurgatory(char map[maxx + 1][maxy + 1], room rooms[]){
    rooms[0].bottomleft.x = COLS/2 - 12;
    rooms[0].bottomleft.y = LINES /2 + 12;
    rooms[0].bottomright.x = COLS/2 +12;
    rooms[0].bottomright.y  = rooms[0].bottomleft.y ;
    rooms[0].topleft.x = rooms[0].bottomleft.x;
    rooms[0].topleft.y = LINES/2 - 12;
    rooms[0].topright.x = rooms[0].bottomright.x;
    rooms[0].topright.y = rooms[0].topleft.y;
    for(int i =0; i< maxx; i++){
        for(int j=0; j<maxy; j++){
            map[i][j] = 0;
        }
    }
    for(int i=rooms[0].bottomleft.x; i<=rooms[0].bottomright.x; i++){
        map[i][rooms[0].bottomleft.y] = '_';
    }
    for(int i=rooms[0].topleft.x+1; i<rooms[0].topright.x; i++){
        map[i][rooms[0].topleft.y] = '_';
    }
    for(int i=rooms[0].topleft.y+1; i<=rooms[0].bottomleft.y; i++){
        map[rooms[0].bottomleft.x][i] = '|';
        map[rooms[0].bottomright.x][i] = '|';

    }
    for(int i=rooms[0].topleft.y+ 1; i<rooms[0].bottomleft.y; i++){
        for(int j=rooms[0].topleft.x + 1; j<rooms[0].topright.x; j++){
            map[j][i] = '.';
        }

    }
    rooms[0].theme = purgatory;
    for(int i =0; i<6; i++){
        rooms[0].mons[i].hp = 20;
        rooms[0].mons[i].kind = SNAKE;
        rooms[0].mons[i].pos.x = rooms[0].bottomleft.x +1+ 4*(i);
        rooms[0].mons[i].pos.y = rooms[0].topleft.y + 1+ 3*i;
    }
    rooms[0].isvisible = 1;


    
}


void startloadedgame(char username[]){
initscr();
clear();
curs_set(false);
start_color();
noecho();
cbreak();
srand(time(0));
init_pair(1,COLOR_RED, COLOR_BLACK);
init_pair(2, COLOR_BLUE, COLOR_BLACK);
init_pair(3, COLOR_GREEN, COLOR_BLACK);
init_pair(4, COLOR_YELLOW,COLOR_BLACK );
init_pair(5,COLOR_MAGENTA , COLOR_BLACK);
init_pair(6,COLOR_CYAN , COLOR_BLACK);
init_pair(7, COLOR_WHITE, COLOR_BLACK);
SDL_Init(SDL_INIT_AUDIO);
bkgd(COLOR_PAIR(7));
data game;
if(loadgame(username, &game) && (game.endgame != 1)){

startmusic(game.music);
int invalid =0;
char password[4] = {0};
char copypass[4] = {0};
position save;
time_t temptime = time(NULL);
time_t starttime = time(NULL);
time_t spelltime = time(NULL);
int remaining = 30;
int passwordmode = 0;
int passend =1;
int changepass= 0;
int isold =0;
int goldsave =0;
int dontpick =0;
int win =0;
int isenchant =0;
int isnight =0;
int istreasure =0;
int isregular =0;
int ispurgatory =0;
game.savelevel =0;
int newlevel =0;
int newroom =0;
time_t htime = time(NULL);
time_t ftime = time(NULL);
int hremaining =0;
int ishungry =0;
time_t enchanttime =0;
int enchantremaining =0;
int fremaining = 0;
int spellremain =0;
int input =0;
int hittype =0;
int fire =0; 
int monshp =0;
halfdelay(10);
while(1){
if(game.level != 4){
    game.lastlevel = game.level;
    game.lastx = game.player.x;
    game.lasty = game.player.y;
    }

        for(int i=0; i<6; i++){
            if((game.flist[i].fkind == NORMAL) && (difftime(time(NULL), game.flist[i].ftime)> 40)){
            game.flist[i].fkind = POISENOUS;
            game.flist[i].hpamount = -5;
            game.flist[i].ftime = time(NULL);

            }
            else if((game.flist[i].fkind == GREAT || game.flist[i].fkind == MAGIC ) && (difftime(time(NULL), game.flist[i].ftime) > 40)){
            game.flist[i].ftime = time(NULL);
            game.flist[i].fkind = NORMAL;
            game.flist[i].hpamount = 5;
            strcpy(game.flist[i].name, "Normal");
            }
       }
  
    if(game.level>game.savelevel){
    game.savelevel =game.level;
    newlevel =1;
    }

    int roomnumber =roomsearch(game.rooms[game.level], game.player.x, game.player.y);
    if((roomnumber == -1) || (game.rooms[game.level][roomnumber].theme  == Regular)){
        if(isregular ==0){
            if(game.music != 9){
        endmusic();
        startmusic(game.music);}
    isenchant =0;
    istreasure =0;
    isnight =0;
    isregular =1;
    }
    }
    
    else{
        isregular =0;
if(game.rooms[game.level][roomnumber].theme != Nightmare){
    game.rooms[game.level][roomnumber].isvisible = 1;
}
if((game.rooms[game.level][roomnumber].theme  == Enchant)){
    if(isenchant ==0){
        enchanttime = time(NULL);
        isenchant = 1;
        if(game.music != 9){
        endmusic();
        startmusic(6);}
    }
}
else{
   isenchant = 0; 
}
if(isenchant){
    enchantremaining = (int)difftime(time(NULL), enchanttime);
    if(enchantremaining >= 1){
    enchanttime = time(NULL);
    game.playerhp--;}
}
if((game.rooms[game.level][roomnumber].theme  == Nightmare)){
    if(isnight ==0){
        isnight = 1;
        if(game.music != 9){
        endmusic();
        startmusic(8);}
    }
}
else{
   isnight = 0; 
}
if((game.rooms[game.level][roomnumber].theme  == Treasure)){
    if(istreasure ==0){
        istreasure = 1;
        if(game.music != 9){
        endmusic();
        startmusic(7);}
    }
}
else{
   istreasure = 0; 
}}

if(game.level !=4){

if(ishungry){
    game.recover =0;
    hremaining = (int)difftime(time(NULL), htime);
    if(hremaining >= 1){
    game.playerhp = game.playerhp -1;
    if(game.hunger<100)
    game.hunger += 1;
        htime = time(NULL);}
    }

else{
    hremaining = (int)difftime(time(NULL), htime);
    if((game.recover>=20)&&(game.playerhp<100)&& (!isenchant)&&(hremaining>=1))
    game.playerhp++;

    if(hremaining>=1){
    if((game.hunger<100)&&(!game.ishealthspell))
    game.hunger += 1;
    if(game.hunger<75)
    game.recover++;
        htime = time(NULL); }
        if(game.playerhp == 100)
        game.recover =0;
}

if(game.hunger>75){
    ishungry =1;
    game.recover =0;
}

else
ishungry =0;
}

if(game.level == 4){

if(game.music != 9){
    if(ispurgatory == 0){
    endmusic();
    startmusic(10);}
}
ispurgatory =1;
    int backtogame =1;
    for(int i =0; i<6; i++){
        if(game.rooms[4][0].mons[i].hp>0)
        backtogame =0;
    }
    if(backtogame){
        game.level = game.lastlevel;
        ispurgatory =0;
        game.player.x =game.lastx;
        game.player.y = game.lasty;
        endmusic();
    }
}
 
if(game.ishealthspell){
    if(game.spellcounter<=10){
    spellremain = (int)difftime(time(NULL), spelltime);
    
    if(spellremain>=1){
        if(game.playerhp<99)
        game.playerhp+=2;
        spelltime = time(NULL);
        game.spellcounter++;
    }
    }
    else{
        game.spellcounter =0;
        game.ishealthspell =0;
    }
}


    clear();

if(passwordmode == 1){
    temptime = time(NULL);
    passwordmode =0;
    passend =0;
    changepass = rand() % 3;
    isold = rand() %3;

}

if(remaining <=0){
    passend =1;
    remaining = 30;
}

if((!passend)){
    remaining = 30 - (int)difftime(time(NULL), temptime);
     mvprintw(0, middle_x - 15, "Remaining time: %d seconds", remaining);
     if((isold == 1)&& (game.level != 2) &&(game.level != 3)){
         attron(COLOR_PAIR(1));
         mvprintw(3, middle_x -15, "password: " );
         for(int i =0; i<4;i++){
    mvprintw(3, middle_x -5 + i, "%c", password[3-i] );}
    attroff(COLOR_PAIR(1));
     }
     else{
    attron(COLOR_PAIR(1));
    mvprintw(3, middle_x -15, "password: %s", password );
    attroff(COLOR_PAIR(1));}
    if((changepass == 2)&& (game.level != 2) &&(game.level != 3)){
        if(  ( remaining == 25) || ( ( remaining == 27)))
        pass(password, game,invalid, 0, username);
    }
}

if(passend){
changepass = 0;
isold =0;
}

printmap(game.map[game.level], game.player, game.color, game.rooms[game.level], game.realmap[ game.level], game.level);
leftshot =0;
rightshot =0;
upshot =0;
downshot =0;
printmessage(hittype, fire, invalid, newlevel,monshp);
fire =0;
hittype =0;
invalid =0;
newlevel =0;
if(game.level !=4)
health(&game);
printinfo(game.playerhp, game.level, game.hits, game.gold, game.ancient, game.brokenancient, goldsave);
if(game.level == 4){
    attron(COLOR_PAIR(6));
    printsoldierleft();
    printsoldierright();
    printkill();
    attroff(COLOR_PAIR(6));
}
refresh();



input = getch();
if(input != ERR){
if(input == 27){
    game.experience += (int)difftime(time(NULL), starttime);
    if(updateUser(username, &game)){

    }
    else
    adduser(&game);
    savegame(username, &game);
    break;
}
 else{
    goldsave = game.gold;
     handleinput(&game.player, game.map, input, game.rooms, &game.playerhp, &game.level, &invalid, password, &passwordmode, &passend, &game.ancient, &game.brokenancient, &save,game.color, &game, &dontpick, &win, &newroom,0, &hittype, &monshp, &game.spellcounter, &game.isspeedspell, &fire);
     if(passwordmode == 1){
        pass(password, game,invalid, 0, username);
     }
}

if(game.playerhp <= 0){
        if(game.firstdie == 1){
        game.endgame =1;}
    else{
        game.firstdie = 1;
        game.playerhp = 75;
        game.level = 4;
        game.player.x = game.rooms[4][0].bottomleft.x + 1;
        game.player.y = game.rooms[4][0].bottomleft.y - 1;
    }
    }
 
if(game.endgame == 1){
    game.totalscore += game.gold *(game.difficulty +1);
    game.experience += (int)difftime(time(NULL), starttime);
    game.totalgold += game.gold;
    game.numberofgames +=1;
    if(win)
    game.totalscore +=(1+game.difficulty)*100;
    if(updateUser(username, &game)){

    }
    else
    adduser(&game);
    savegame(username, &game);
    
    break;
}
}
}
if(win && game.endgame){
    clear();
    cbreak();
    attron(COLOR_PAIR(1) | A_BOLD);
    printyouwon();
     printttt(username,game.totalscore);
     printinfo(game.playerhp, game.level, game.hits, game.gold, game.ancient, game.brokenancient, goldsave);
    attroff(COLOR_PAIR(1) | A_BOLD);
    getch();
}

else if(!win && game.endgame){
       clear();
       cbreak();
    attron(COLOR_PAIR(1) | A_BOLD);
    printyoulost(game.totalscore);
    printinfo(game.playerhp, game.level, game.hits, game.gold, game.ancient, game.brokenancient, goldsave);
    attroff(COLOR_PAIR(1) | A_BOLD);
    getch();
}

endmusic(game.music);
SDL_Quit();
clear();
endwin();}

else{
cbreak();
SDL_Quit();
clear();
endwin();
}
}


void startgame(int difficulty, int color, int music, char username[], int isguest){
initscr();
clear();
curs_set(false);
start_color();
noecho();
cbreak();
srand(time(0));
SDL_Init(SDL_INIT_AUDIO);
startmusic(music);
init_pair(1,COLOR_RED, COLOR_BLACK);
init_pair(2, COLOR_BLUE, COLOR_BLACK);
init_pair(3, COLOR_GREEN, COLOR_BLACK);
init_pair(4, COLOR_YELLOW,COLOR_BLACK );
init_pair(5,COLOR_MAGENTA , COLOR_BLACK);
init_pair(6,COLOR_CYAN , COLOR_BLACK);
init_pair(7, COLOR_WHITE, COLOR_BLACK);
SDL_Init(SDL_INIT_AUDIO);
bkgd(COLOR_PAIR(7));
data game;
if(!isguest){
    if((loadgame(username, &game)) ){
            game.totalscore += game.gold * (difficulty + 1);
            game.totalgold += game.gold;
            }
    else{
        game.experience =0;
        game.totalscore =0;
        game.numberofgames =0;
        game.totalgold =0;
    }
}
for(int i =0; i<5; i++){
initializemap(game.map[i]);
initializemap(game.realmap[i]);
}
strcpy(game.username, username);
game.numberofrooms = 6;
game.gold =0;
game.playerhp = 100 - 25 * difficulty;
game.level =0;
game.hits =0;
game.color =color;
game.difficulty = difficulty;
game.music = music;
game.ancient = 0;
game.brokenancient =0;
 game.endgame =0;
 game.foodamount =0;
game.hunger =0;
game.firstdie =0;
game.lastlevel=0;
for(int j =0; j<5; j++){
for(int i =0; i<game.numberofrooms; i++){
initializerooms(&(game.rooms[j][i]));}}
for(int i =0; i<4; i++){
makerandomroom(game.rooms[i], game.numberofrooms, &game.player, i);
makemap(game.map[i],game.rooms[i], game.numberofrooms, game.player ,i);
makecorridor(game.map[i], game.rooms[i], game.numberofrooms);}
makepurgatory(game.map[4], game.rooms[4]);
int invalid =0;
char password[4] = {0};
char copypass[4] = {0};
position save;
time_t temptime = time(NULL);
time_t starttime = time(NULL);
time_t enchanttime = time(NULL);
int remaining = 30;
int passwordmode = 0;
int passend =1;
int changepass = 0;
int isold =0;
int goldsave =0;
int dontpick =0;
int win =0;
int isenchant =0;
int isnight =0;
int istreasure =0;
int isregular =0;
int newlevel =0;
int ispurgatory =0;
game.savelevel =0;
int newroom =0;
int ishungry =0;
time_t htime = time(NULL);
time_t spelltime = time(NULL);
time_t ftime = time(NULL);
game.spellcounter =0;
int hremaining =0;
int enchantremaining =0;
int monshp =0;
initializeweapon(&game);
initializespell(&game);
game.recover =0;
game.ishealthspell =0;
game.isspeedspell =0;
game.isdamagespell =0;
int spellremain =0;
game.lastkey =0;
int input =0;
int hittype =0;
int fire =0; 
for(int i=0; i<6; i++){
game.flist[i].fkind =NORMAL;
}
int fremaining =0;


halfdelay(10);
while(1){
    if(game.level != 4){
    game.lastlevel = game.level;
    game.lastx = game.player.x;
    game.lasty = game.player.y;
    }
           for(int i=0; i<6; i++){
            if((game.flist[i].fkind == NORMAL) && (difftime(time(NULL), game.flist[i].ftime)> 40)){
            game.flist[i].fkind = POISENOUS;
            game.flist[i].hpamount = -5;
            game.flist[i].ftime = time(NULL);

            }
            else if((game.flist[i].fkind == GREAT || game.flist[i].fkind == MAGIC ) && (difftime(time(NULL), game.flist[i].ftime) > 40)){
            game.flist[i].ftime = time(NULL);
            game.flist[i].fkind = NORMAL;
            game.flist[i].hpamount = 5;
            strcpy(game.flist[i].name, "Normal");
            }
       }
    
    if(game.level>game.savelevel){
    game.savelevel =game.level;
    newlevel =1;
    }
    clear();
     int roomnumber =roomsearch(game.rooms[game.level], game.player.x, game.player.y);
    if((roomnumber == -1) || (game.rooms[game.level][roomnumber].theme  == Regular)){
        if(isregular ==0){
            if(game.music != 9){
        endmusic();
        startmusic(game.music);}
    isenchant =0;
    istreasure =0;
    isnight =0;
    isregular =1;
    }
    }
   
    else{
        isregular =0;
if(game.rooms[game.level][roomnumber].theme != Nightmare){
    game.rooms[game.level][roomnumber].isvisible = 1;
}

if((game.rooms[game.level][roomnumber].theme  == Enchant)){
    if(isenchant ==0){
        enchanttime = time(NULL);
        isenchant = 1;
        if(game.music != 9){
        endmusic();
        startmusic(6);}
    }
}

else{
   isenchant = 0; 
}

if(isenchant){
    enchantremaining = (int)difftime(time(NULL), enchanttime);
    if(enchantremaining >= 1){
    enchanttime = time(NULL);
    game.playerhp--;}
}

if((game.rooms[game.level][roomnumber].theme  == Nightmare)){
    if(isnight ==0){
        isnight = 1;
        if(game.music != 9){
        endmusic();
        startmusic(8);}
    }
}

else{
   isnight = 0; 
}

if((game.rooms[game.level][roomnumber].theme  == Treasure)){
    if(istreasure ==0){
        istreasure = 1;
        if(game.music != 9){
        endmusic();
        startmusic(7);}
    }
}

else{
   istreasure = 0; 
}}

if(game.level !=4){

if(ishungry){
    game.recover =0;
    hremaining = (int)difftime(time(NULL), htime);
    if(hremaining >= 1){
    game.playerhp = game.playerhp -1;
    if(game.hunger<100)
    game.hunger += 1;
        htime = time(NULL);}
    }

else{
    hremaining = (int)difftime(time(NULL), htime);
    if((game.recover>=20)&&(game.playerhp<100)&& (!isenchant)&&(hremaining>=1))
    game.playerhp++;

    if(hremaining>=1){
    if((game.hunger<100) && (!game.ishealthspell))
    game.hunger += 1;
    if(game.hunger<75)
    game.recover++;
        htime = time(NULL); }
        if(game.playerhp == 100)
        game.recover =0;
}

if(game.hunger>75){
    ishungry =1;
    game.recover =0;
}

else
ishungry =0;
}

if(game.level == 4){

if(game.music != 9){
    if(ispurgatory == 0){
    endmusic();
    startmusic(10);}
}
ispurgatory =1;
    int backtogame =1;
    for(int i =0; i<6; i++){
        if(game.rooms[4][0].mons[i].hp>0)
        backtogame =0;
    }
    if(backtogame){
        game.level = game.lastlevel;
        ispurgatory =0;
        game.player.x =game.lastx;
        game.player.y = game.lasty;
        endmusic();
    }
}

if(game.ishealthspell){
    if(game.spellcounter<=10){
    spellremain = (int)difftime(time(NULL), spelltime);
    
    if(spellremain>=1){
        if(game.playerhp<99)
        game.playerhp+=2;
        spelltime = time(NULL);
        game.spellcounter++;
    }
    }
    else{
        game.spellcounter =0;
        game.ishealthspell =0;
    }
}


if(passwordmode == 1){
    temptime = time(NULL);
    passwordmode =0;
    passend =0;
    changepass = rand() % 3;
    isold = rand() %3;
}

if(remaining <=0){
    passend =1;
    remaining = 30;
}

if((!passend)){
    remaining = 30 - (int)difftime(time(NULL), temptime);
     mvprintw(0, middle_x - 15, "Remaining time: %d seconds", remaining);
     if((isold == 1)&& (game.level != 2) &&(game.level != 3)){
         attron(COLOR_PAIR(1));
         mvprintw(3, middle_x -15, "password: " );
         for(int i =0; i<4;i++){
    mvprintw(3, middle_x -5 + i, "%c", password[3-i] );}
    attroff(COLOR_PAIR(1));
     }
     else{
    attron(COLOR_PAIR(1));
    mvprintw(3, middle_x -15, "password: %s", password );
    attroff(COLOR_PAIR(1));}
    if((changepass == 2)&& (game.level != 2) &&(game.level != 3)){
        if(  ( remaining == 25) || ( ( remaining == 27)))
        pass(password, game,invalid, 0, username);
    }
}

if(passend){
changepass = 0;
isold =0;
}

printmap(game.map[game.level], game.player, color, game.rooms[game.level], game.realmap[ game.level], game.level);
leftshot =0;
rightshot =0;
upshot =0;
downshot =0;
printmessage(hittype, fire, invalid, newlevel, monshp);
fire =0;
hittype =0;
invalid =0;
newlevel =0;
if(game.level != 4)
health(&game);
printinfo(game.playerhp, game.level, game.hits, game.gold, game.ancient, game.brokenancient, goldsave);
if(game.level == 4){
    attron(COLOR_PAIR(6));
    printsoldierleft();
    printsoldierright();
     printkill();
    attroff(COLOR_PAIR(6));
}
refresh();
newlevel =0;

input = getch();
if(input != ERR){
if(input == 27){
    if(!isguest){
        game.experience += (int)difftime(time(NULL), starttime);
    savegame(username, &game);
    if(updateUser(username, &game)){

    }
    else{
        adduser(&game);
    }}
    break;
}
 else{
    goldsave = game.gold;
     handleinput(&game.player, game.map, input, game.rooms, &game.playerhp, &game.level, &invalid, password, &passwordmode, &passend, &game.ancient, &game.brokenancient, &save, game.color, &game, &dontpick, &win, &newroom, 0, &hittype, &monshp, &game.spellcounter, &game.isspeedspell, &fire);
     if(passwordmode == 1){
        pass(password, game,invalid, 0, username);
     }
}}


if(game.playerhp <= 0){
        if(game.firstdie == 1){
        game.endgame =1;
       }
        else{
        game.firstdie =1;
        game.playerhp =75;
        game.level =4;
        game.player.x = game.rooms[4][0].bottomleft.x + 1;
        game.player.y = game.rooms[4][0].bottomleft.y - 1;
        }
    }
 
  
if(game.endgame == 1){
    if(!isguest){
    game.totalscore += game.gold *(game.difficulty + 1);
    game.experience += (int)difftime(time(NULL), starttime);
    game.numberofgames +=1;
    game.totalgold += game.gold;
    if(win)
    game.totalscore += (1+game.difficulty)*100;
    savegame(username, &game);
    if(updateUser(username, &game)){

    }
    else{
        adduser(&game);
    }}
    break;
}
}

cbreak();
if(win && game.endgame){
    clear();

    attron(COLOR_PAIR(4) | A_BOLD);
     printyouwon();
     if(!isguest)
     printttt(username, game.totalscore);
     else
     printttt(username, game.gold *(game.difficulty + 1));
     printinfo(game.playerhp, game.level, game.hits, game.gold, game.ancient, game.brokenancient, goldsave);
    attroff(COLOR_PAIR(4) | A_BOLD);
    refresh();
    getch();
    
}
else if ( !win && game.endgame){
       clear();
       attron(COLOR_PAIR(1) | A_BOLD);
       if(!isguest)
    printyoulost(game.totalscore);
    else
    printyoulost(game.gold *(game.difficulty + 1));
    printinfo(game.playerhp, game.level, game.hits, game.gold, game.ancient, game.brokenancient, goldsave);
    attroff(COLOR_PAIR(1) | A_BOLD);
    refresh();
    getch();

}


endmusic(music);
SDL_Quit();
clear();
endwin();
}
#endif

