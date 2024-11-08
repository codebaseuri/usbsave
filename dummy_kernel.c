//___ wlecome to the main kernel.file 
// i have decided to split certain codes into diffrent
// files for readability and cuz im a responsible and 
// and reasonable human being.

// defines for curser functions
#include "print_functions.h"

#include "idt_setup.h"
void main() {
    clear_Screen();
    initialize_idt();
    int a=1/0;
    char str[]="welcome mortals\n";
    print_Str("maksim is a fag \n");
    print_Str("maksimdsdsd dsdsdfffsssdis a fsag \n");
}
