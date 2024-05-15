#include <iostream>
#include <chrono>
#include <stdexcept>
#include <optional>
#include <thread>

#include "State.h"


class App;
class State;

class OnState : public State
{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;

public:
    std::chrono::duration<double>   time      { }       ;
    std::chrono::duration<double>   *ptr_time { &time } ;
    OnState(App* app) : State(app) 
    {
        start = std::chrono::high_resolution_clock::now();
    }

    void toggle() override;
    bool isOpen() const override { return true; }
    inline void addLines(); // Removed override unless declared in State

    ~OnState() {}
};

class OffState : public State
{
public:
    OffState(App* app) : State(app) {}
    void toggle() override;
    bool isOpen() const override { return false; }
    inline void addLines() override 
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
};

class App
{
    State*                            currentState         ;
    std::string                       m_appName        { } ; 

public:

    std::chrono::duration<double>     duration_spent   { }                 ;
    std::chrono::duration<double>*    ptr_duration     { &duration_spent } ;
    volatile std::uint32_t            lines_written    { }                 ; 

    App(std::string appName) : currentState(new OffState(this)), m_appName(appName) {} // Initialize with OffState
    ~App() { delete currentState; }
    void setState(State* state)
    {
        if (currentState) delete currentState;
        currentState = state;
    }
    void toggle()
    {
        currentState->toggle();
    }

    void addLines()
    {
      currentState->addLines() ; 
    }
    std::uint32_t getLines() const 
    {
      return lines_written ; 
    }

    void addDuration(std::chrono::duration<double> time)
    {
      duration_spent += time ; 
    }

    std::string  getName() const 
    {
      return m_appName ; 
    }

    std::chrono::duration<double> getTimeSpent()
    {
      return duration_spent ; 
    }

};

void OnState::toggle()
{
    auto end = std::chrono::high_resolution_clock::now();
    *ptr_time = end - start;  
    app->addDuration(*ptr_time);  // Add the duration to the app
    app->setState(new OffState(app)); // Transition to OffState
}

void OffState::toggle()
{
  app->setState(new OnState(app)); // Pass app to the new state
}

inline void OnState::addLines()
{
  app->lines_written = app->lines_written + 1  ;
}


int main()
{
  auto begin = std::chrono::high_resolution_clock::now(); 
  App app("Vs-Code");
  app.toggle(); // On
  std::this_thread::sleep_for(std::chrono::seconds(3));
  app.toggle(); // Off 
  std::this_thread::sleep_for(std::chrono::seconds(3));
  auto end = std::chrono::high_resolution_clock::now(); 
  std::chrono::duration<double> time_final = end - begin ; 
  std::cout << "Total Time running Program " << time_final.count() <<std::endl;
  std::cout << "Total Time running " << app.getName() << ": " << (app.getTimeSpent()).count();
  return 0;
}
