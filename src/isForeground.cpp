#include "isForeground.h"

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
    char windowTitle[256];
    if (GetWindowTextA(hwnd, windowTitle, sizeof(windowTitle))) {
        std::cout << "Window Handle: " << hwnd << " | Title: " << windowTitle << std::endl;
    }
    return TRUE; // Continue enumeration
}


DWORD GetForegroundProcessID() {
    HWND hwnd = GetForegroundWindow();
    if (hwnd == NULL) {
        return 0;
    }
    DWORD pid;
    GetWindowThreadProcessId(hwnd, &pid);
    return pid;
}

DWORD GetProcessIDByName(const char* processName) {
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE) {
        return 0;
    }

    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32);

    if (!Process32First(hSnapshot, &pe32)) {
        CloseHandle(hSnapshot);
        return 0;
    }

    do {
        if (strcmp(pe32.szExeFile, processName) == 0) {
            CloseHandle(hSnapshot);
            return pe32.th32ProcessID;
        }
    } while (Process32Next(hSnapshot, &pe32));

    CloseHandle(hSnapshot);
    return 0;
}


bool IsProcessInForeground(const char* processName) {
    DWORD foregroundPid = GetForegroundProcessID();
    DWORD processPid = GetProcessIDByName(processName);

    return (foregroundPid != 0 && foregroundPid == processPid);
}
