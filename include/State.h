#ifndef STATE_H
#define STATE_H

class App;
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

#endif 
