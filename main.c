
#include <ncurses.h>
#include "menu.h"
#include <locale.h>



int main(){
setlocale(LC_ALL, "");

curs_set(false);
start_color();

startmenu();


    return 0;
}
