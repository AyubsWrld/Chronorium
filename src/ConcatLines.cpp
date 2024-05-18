#include "concatLines.h"
#include "State.h"
#include "App.h"



//------------------------------------------------------------------------------- Line Concatenation Implementation --------------------------------------------------------------------------------



void concatLines( App* app ) //Background process
{
  std::uint8_t           previousValue               { 0 } ;                     // Char BUFFER to view previous user Input
  std::uint8_t           BUFFER            =      _getch() ;

  while(!_kbhit() && (_kbhit && app->isOpen()) )                                //Loop until App closes !_kbhit() && _kbhit() Facilitates infinite loop (Dum asf imo stop tryna b different)
  {
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
