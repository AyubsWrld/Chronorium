#include "processState.h"


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
      std::wcout << L"Process name: " << pe32.szExeFile << std::endl;
      std::wcout << L"Process ID: " << pe32.th32ProcessID << std::endl;
      std::wcout << L"Parent Process ID: " << pe32.th32ParentProcessID << std::endl;
      std::wcout << L"Thread count: " << pe32.cntThreads << std::endl;
      found = 1 ; 
      break ; 
    }
  }  
  if(!found)
  {
    return 1 ;
    std::cout << "Process not found";
  }
  CloseHandle(hProcessSnap);
  std::cout << found << std::endl;
  return 0;
}
