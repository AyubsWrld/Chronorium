#ifndef APP_H
#define APP_H

#include <string>

 
// Forward declaration of State to avoid including State.h
class State;

class App {

public:
    State* currentState;
    std::string m_appName;
    std::chrono::duration<double> duration_spent;
    std::uint32_t lines_written;

    explicit App(const std::string& appName);
    ~App();

    void setState(State* state);
    void toggle();
    void addLines();
    std::uint32_t getLines() const;
    void addDuration(std::chrono::duration<double> time);
    std::string getName() const;
    std::chrono::duration<double> getTimeSpent() const;
    bool isOpen();

};

#endif // APP_H
