
#include <iostream> 

#include "App.h"
#include "isForeground.h"

  
using namespace  std::chrono_literals ; 



void isOpen(const char *  processName)
{
  BOOL isRunning { 0 }; 
  while(!isRunning)
  {
    std::this_thread::sleep_for(std::chrono::seconds(1)) ; 
    /* isRunning = test(executable_name);  */
    if (IsProcessInForeground(processName)) 
    {
      std::cout << processName << " is running in the foreground." << std::endl;
    } 
    else 
    {
      std::cout << processName << " is not running in the foreground." << std::endl;
    }
  }
  std::cout << "Process Ended";
}

int main() {
    std::this_thread::sleep_for(std::chrono::seconds(2s)) ; 
    const char* processName = "notepad.exe"; // Replace with the name of the process you want to check
    isOpen(processName) ;
    return 0;
}
