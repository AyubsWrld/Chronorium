#include <chrono> 

#ifndef STATE_H
#define STATE_H

class App; 

/* --------------------------------------------------------------------- State Definitions ------------------------------------------------------------------ */

class State
{
protected:
    App* app; // Protected so that derived classes can access it directly
public:
    explicit State(App* app); // Constructor to initialize App pointer
    virtual ~State();

    virtual void toggle() = 0 ;
    virtual bool isOpen() const = 0 ;
    virtual inline void addLines() = 0;
};


/* --------------------------------------------------------------------- State Definitions ------------------------------------------------------------------ */

/* --------------------------------------------------------------------- OffState Definitions ------------------------------------------------------------------ */
class OffState : public State
{
public:
    explicit OffState(App* app)  ; 
    void toggle()       ;
    bool isOpen() const ;
    void addLines()     ;
};

/* --------------------------------------------------------------------- OffState Definitions ------------------------------------------------------------------ */

class OnState : public State {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    std::chrono::duration<double> time {};
    std::chrono::duration<double> *ptr_time { &time };

public:
    explicit OnState(App* app);
    ~OnState() override;

    void toggle() override;
    bool isOpen() const override;
    void addLines() override;
};

#endif // STATE_H
