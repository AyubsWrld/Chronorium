#include "concatLines.h"
#include "State.h"
#include "App.h"



//------------------------------------------------------------------------------- Line Concatenation Implementation --------------------------------------------------------------------------------



void concatLines( App* app ) //Background process
{
  std::uint8_t           previousValue               { 0 } ;                     // Char BUFFER to view previous user Input
  std::uint8_t           BUFFER            =      _getch() ;

  while(!_kbhit() && (_kbhit && app->isOpen() ))                                //Loop until App closes !_kbhit() && _kbhit() Facilitates infinite loop (Dum asf imo stop tryna b different)
  {
    std::cout << "Running" << std::endl;
    if(static_cast<int>(BUFFER) == ENTER  && previousValue != ENTER)            // Whitespace handling , Check if User input is 13 ( 'ENTER' ascii ) && PreviousValue is not 'Enter' 
    {
      ++ app->lines_written                                 ;  
    }
    std::cout << BUFFER << std::endl; 
                         previousValue     =        BUFFER  ;                    //Remove Consecutive Enter Values for adding whitespace . 
                         BUFFER            =       _getch() ;
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Slight delay to reduce CPU usage
    if(!app->isOpen())
    {
      break;
    }
  }


  std::cout << app->lines_written;
}


//------------------------------------------------------------------------------- Line Concatenation Implementation --------------------------------------------------------------------------------

/* int main() { */
/*     HANDLE hProcessSnap; */
/*     PROCESSENTRY32 pe32; */
/**/
/*     // Take a snapshot of all processes in the system. */
/*     hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); */
/*     if (INVALID_HANDLE_VALUE == hProcessSnap) return -1; */
/**/
/*     pe32.dwSize = sizeof(PROCESSENTRY32); */
/**/
/*     // Retrieve information about the first process. */
/*     if (!Process32First(hProcessSnap, &pe32)) { */
/*         CloseHandle(hProcessSnap); */
/*         return -1; */
/*     } */
/**/
/*     // Now walk the snapshot of processes, and */
/*     // display information about each process in turn */
/*     do { */
/*         std::wcout << "Process Name: " << pe32.szExeFile << std::endl; */
/*     } while (Process32Next(hProcessSnap, &pe32)); */
/**/
/*     CloseHandle(hProcessSnap); */
/*     std::uint32_t lineswritten { 30 } ;  */
/*     concatLines(lineswritten);  */
/*     return 0; */
/* } */
