#include <functional>
#include <windows.h>
#include <tlhelp32.h>
#include <iostream>
#include <psapi.h>
#include <algorithm>
#include <chrono> 
#include <thread> 

#pragma once

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)     ;
DWORD GetForegroundProcessID()                              ;
DWORD GetProcessIDByName(const char* processName)           ;
bool IsProcessInForeground(const char* processName)         ;



