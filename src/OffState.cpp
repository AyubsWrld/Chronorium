#include "OffState.h"
#include <iostream>
#include <stdexcept>

OffState::OffState(App* app) : State(app) {}

void OffState::toggle()
{
    app->setState(new OnState(app)); // Assuming OnState is included somewhere or declared forward.
}

bool OffState::isOpen() const
{
    return false;
}

void OffState::addLines() 
{
    try 
    {
        throw std::runtime_error("Cannot add lines to a program which is not actively running");
    } 
    catch (const std::runtime_error& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}


