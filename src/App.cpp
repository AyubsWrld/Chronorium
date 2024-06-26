#include <iostream>
#include <thread>  
#include <functional>
#include "App.h"
#include "State.h" 

App::App(const std::string& appName) : m_appName(appName), duration_spent(0), lines_written(0) {
    currentState = new OffState(this); 
}
App::~App() {
    delete currentState;
}

void App::setState(State* state) {
    if (currentState) {
        delete currentState;
    }
    currentState = state;
}

void App::toggle() {
    if (currentState) {
        currentState->toggle();
    }
}

void App::addLines() {
    if (currentState) {
        currentState->addLines();
    }
}

std::uint32_t App::getLines() const {
    std::cout << lines_written << std::endl;
    return lines_written;
}

void App::addDuration(std::chrono::duration<double> time) {
    /* duration_spent += std::chrono::duration_cast<std::chrono::seconds>(time); */
    duration_spent += time;
}

std::string App::getName() const {
    return m_appName;
}

std::chrono::seconds App::getDurationSpent() const
{
  return std::chrono::duration_cast<std::chrono::seconds>(duration_spent) ; 
}

std::chrono::duration<double> App::getTimeSpent() const {
    return duration_spent;
}

bool App::isOpen() const
{
  return currentState->isOpen() ; 
}


