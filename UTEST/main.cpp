#include <iostream> 
#include "processState.h"



  
using namespace  std::chrono_literals ; 


int main() {
    App Netflix("notepad.exe") ; 
    App *pNetflix{ &Netflix } ;
    std::string  executable_name  = "notepad.exe" ; 
    std::this_thread::sleep_for(std::chrono::seconds(1));
    test(executable_name , pNetflix);
    return 0;
}
