#include <functional>
#include <windows.h>
#include <tlhelp32.h>
#include <iostream>
#include <psapi.h>
#include <algorithm>

#pragma once

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)     ;
DWORD GetForegroundProcessID()                              ;
DWORD GetProcessIDByName(const char* processName)           ;
bool IsProcessInForeground(const char* processName)         ;



