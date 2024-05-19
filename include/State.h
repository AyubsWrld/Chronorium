#include <chrono> 
#include <memory> 

#ifndef STATE_H
#define STATE_H

class App;  // Forward Declaration of App 

/* --------------------------------------------------------------------- State Definitions ------------------------------------------------------------------ */

class State
{
protected:
    std::shared_ptr<App>  app                                          ;     // Protected so that derived classes can access it directly
public:
    explicit            State(std::shared_ptr<App> app)               ;    // Constructor to initialize App pointer
    virtual             ~State()                      ;

    virtual void        toggle()       = 0            ;
    virtual bool        isOpen() const = 0            ; 
    virtual inline void addLines()     = 0            ;
};


/* --------------------------------------------------------------------- State Definitions ------------------------------------------------------------------ */

/* --------------------------------------------------------------------- OffState Definitions ------------------------------------------------------------------ */
class OffState : public State
{
public:
    explicit            OffState(std::shared_ptr<App> app)            ; 
    void                toggle()                      ;
    bool                isOpen()                const ;
    void                addLines()                    ;
    void                incrementTime()               ;
};

/* --------------------------------------------------------------------- OffState Definitions ------------------------------------------------------------------ */

class OnState : public State {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start     ; // Logic which controls duration and
    std::chrono::duration<double> time {}                                 ; // Concatenates it to the running total
    std::chrono::duration<double> *ptr_time { &time }                     ;

public:
    explicit OnState(std::shared_ptr<App> app)                        ;
    ~OnState() override                               ;

    void                toggle()            override  ;
    bool                isOpen()            const     ;
    void                addLines()          override  ;
};

#endif // STATE_H

