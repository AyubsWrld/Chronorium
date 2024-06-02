
#include "App.h"
#include "isForeground.h"

#pragma once



std::string toLower(std::string data)                   ;
int getProcessStatus(std::string name)                  ;
void handleProcesses(std::string processName, App * app)           ;
