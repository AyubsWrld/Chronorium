#include <iostream>
#include <chrono>
#include <stdexcept>
#include <optional>
#include <thread>

class App;
class State;

class State
{
protected:
    App* app; // Protected so that derived classes can access it directly
public:
    State(App* app) : app(app) {} // Constructor to initialize App pointer
    virtual ~State() {}
    virtual void toggle() = 0;
    virtual bool isOpen() const = 0;
    virtual inline void addLines() = 0;
};

class OnState : public State
{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;

public:
    OnState(App* app) : State(app) 
    {
        start = std::chrono::high_resolution_clock::now();
    }

    void toggle() override;
    bool isOpen() const override { return true; }
    inline void addLines(); // Removed override unless declared in State

    ~OnState() 
    { 
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> time = end - start;
        std::cout << "Duration: " << time.count() << " seconds" << std::endl;
    }
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

    std::chrono::seconds              duration_spent   { } ;
    volatile std::uint32_t            lines_written    { } ; 

    App() : currentState(new OffState(this)) {} // Initialize with OffState
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

    void addDuration()
    {

    }

};

void OnState::toggle()
{
    std::cout << "App is turning off\n";
    app->setState(new OffState(app)); // Pass app to the new state
}

void OffState::toggle()
{
    std::cout << "App is turning on\n";
    app->setState(new OnState(app)); // Pass app to the new state
}

inline void OnState::addLines()
{
  app->lines_written = app->lines_written + 1  ;
}


int main()
{
    App app;
    app.toggle(); // On
    std::this_thread::sleep_for(std::chrono::seconds(3));

    return 0;
}
