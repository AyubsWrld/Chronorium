#ifndef APP_H
#define APP_H

#include <string>

 
// Forward declaration of State to avoid including State.h
class State;

class App {

    State*               currentState                 ;
    std::string          m_appName                    ;

public:
    //Member Variables 

    std::chrono::duration<double> duration_spent      ;
    std::uint32_t        lines_written                ;

    //Constructor && Destructor
    explicit App(const std::string& appName);
    ~App();

    //Mmeber Functions
    void                 setState(State* state)       ;
    void                 toggle()                     ;
    void                 addLines()                   ;
    std::uint32_t        getLines()              const;
    void addDuration(std::chrono::duration<double> time);
    std::string          getName()               const;
    std::chrono::duration<double> getTimeSpent() const;
    bool                 isOpen()               const ;

};

#endif // APP_H
