<<<<<<< HEAD
#include "State.h"
#include "App.h"
#include "ConcatLines.h"
#include <iostream>
#include <stdexcept>
#include <chrono>
#include <thread>



/* --------------------------------------------------------------------- State Implementation ------------------------------------------------------------------ */

State::State(App* app) : app(app) {} // Constructor to initialize App pointer
State::~State() {}

/* --------------------------------------------------------------------- State Implementation ------------------------------------------------------------------ */


/* --------------------------------------------------------------------- OffState Implementation ------------------------------------------------------------------ */

OffState::OffState(App* app) : State(app) { } ; 
void OffState::toggle()
{
  app->setState(new OnState(app)); // Pass app to the new state
}
bool  OffState::isOpen()  const
{ 
  return false  ;  
} 
void OffState::addLines()  
{
  try 
  {
    throw std::runtime_error("Cannot add lines to program which is not actively runnning");
  } 
  catch (const std::runtime_error& e) 
  {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}

/* --------------------------------------------------------------------- OffState Implementation ------------------------------------------------------------------ */

OnState::OnState(App* app) : State(app), start(std::chrono::high_resolution_clock::now()) {  }


OnState::~OnState() {}

void OnState::toggle() 
{
  auto end = std::chrono::high_resolution_clock::now();
  *ptr_time = end - start;
  app->addDuration(*ptr_time);
  app->setState(new OffState(app));  
}

bool  OnState::isOpen()  const
{
  return  true ;
}


void OnState::addLines() 
{
  concatLines( app )  ; 
}
=======
#include "State.h"
#include "App.h"
#include "ConcatLines.h"
#include <iostream>
#include <stdexcept>
#include <chrono>
#include <thread>



/* --------------------------------------------------------------------- State Implementation ------------------------------------------------------------------ */

State::State(App* app) : app(app) {} // Constructor to initialize App pointer
State::~State() {}

/* --------------------------------------------------------------------- State Implementation ------------------------------------------------------------------ */


/* --------------------------------------------------------------------- OffState Implementation ------------------------------------------------------------------ */

OffState::OffState(App* app) : State(app) { } ; 
void OffState::toggle()
{
  app->setState(new OnState(app)); // Pass app to the new state
}
bool  OffState::isOpen()  const
{ 
  return false  ;  
} 
void OffState::addLines()  
{
  try 
  {
    throw std::runtime_error("Cannot add lines to program which is not actively runnning");
  } 
  catch (const std::runtime_error& e) 
  {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}

/* --------------------------------------------------------------------- OffState Implementation ------------------------------------------------------------------ */

OnState::OnState(App* app) : State(app), start(std::chrono::high_resolution_clock::now()) {  }


OnState::~OnState() {}

void OnState::toggle() 
{
  auto end = std::chrono::high_resolution_clock::now();
  *ptr_time = end - start;
  app->addDuration(*ptr_time);
  app->setState(new OffState(app));  
}

bool  OnState::isOpen()  const
{
  return  true ;
}


void OnState::addLines() 
{
  concatLines( app )  ; 
}
>>>>>>> 10b4dd7d7c7cfcdc80b8db6b17089b629367b1da
