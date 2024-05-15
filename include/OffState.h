#ifndef OFFSTATE_H
#define OFFSTATE_H

class State;
class App;
class OffState : public State
{
public:
    explicit OffState(App* app) : State(app) {}
    void toggle() override;
    bool isOpen() const override; 
    inline void addLines() override 
};
#endif
