#include "manage_classes.h"
#include "manage_menu.h"

int main()
{
    int log = log_in();
    if(log == 1)
        return 0;

    submenu();

    return 0;
}
