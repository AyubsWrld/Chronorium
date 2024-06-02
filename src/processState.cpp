#include "processState.h"
#include "isForeground.h"



std::string toLower(std::string data)
{
  std::transform(data.begin(), data.end(), data.begin(),
      [](unsigned char c){ return std::tolower(c); });
  return data ; 
}



int getProcessStatus(std::string name)      
{
  BOOL found { } ; 
  HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
  if (hProcessSnap == INVALID_HANDLE_VALUE) 
  {
    std::cerr << "Failed to create snapshot of processes." << std::endl;
    return 1;
  }

  PROCESSENTRY32 pe32;
  pe32.dwSize = sizeof(PROCESSENTRY32);


  if (!Process32First(hProcessSnap, &pe32)) 
  {
    std::cerr << "Failed to retrieve the first process." << std::endl;
    CloseHandle(hProcessSnap); // Clean up the snapshot object
    return 1;
  }

    // Now walk the snapshot of processes and display information about each process
  while (Process32Next(hProcessSnap, &pe32))
  {
    if( toLower(( std::string ) pe32.szExeFile) == toLower(name) )
    {
      const char* cString = name.c_str();
      if(IsProcessInForeground(cString))
      {
        std::wcout << L"Process name: " << pe32.szExeFile << std::endl;
        std::cout << "And process is running in :    FOREGROUND" << std::endl; 
        std::cout << "\n" << std::endl;
        found = 1 ;
        break ; 
      } 
      else
      {
        std::wcout << L"Process name: " << pe32.szExeFile << std::endl;
        std::cout << "Process is running in :        BACKGROUND" << std::endl;
        std::cout << "\n" << std::endl;
        found = 1 ; 
        break ; 
      }
    }
  }  
  if(!found)
  {
    return 1 ;
    std::cout << "Process not found";
  }
  CloseHandle(hProcessSnap);
  return 0;
}


void handleProcesses(std::string processName , App * app)
{
  app->toggle() ; 
  BOOL isRunning { 0 }; 
  while(!isRunning)
  {
    std::this_thread::sleep_for(std::chrono::seconds(1)) ; 
    isRunning = getProcessStatus(processName); 
  }
  app->toggle() ; 
  std::cout << "\nProcess Ended" << std::endl;
  std::cout << "-------------------------------------------------------" << std::endl;
  std::cout << processName << " Ran for: " << app->getDurationSpent().count() << "s" << std::endl;
}
