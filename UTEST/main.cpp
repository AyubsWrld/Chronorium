#include <iostream> 

#include "processState.h"
#include "User.h"

using namespace  std::chrono_literals ; 

int main() {
  App Netflix("notepad.exe") ; 
  User user1("Ayub" , "iwantwraiths@gmail.com") ;
  user1.instantiateApplication( "notepad.exe" ) ; 
  user1.instantiateApplication( "notion.exe" ) ; 
  /* handleProcesses(user1.getApplicationFirst()->getName() , user1.getApplicationFirst());  */
  user1.runApplications(); 
  return 0;
}
