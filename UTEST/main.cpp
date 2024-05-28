#include <chrono> 
#include <thread> 
#include <iostream> 
#include <functional>
#include <windows.h>
#include <tlhelp32.h>
#include <iostream>
#include <psapi.h>

#include "App.h"

  
using namespace  std::chrono_literals ; 


void getProcessStateByPath(const std::string& targetPath) {
    HANDLE hProcessSnap  ; //
    PROCESSENTRY32 pe32  ;
    bool found  { false };

    // Take a snapshot of all processes in the system.
    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (INVALID_HANDLE_VALUE == hProcessSnap) return;

    pe32.dwSize = sizeof(PROCESSENTRY32);

    if (!Process32First(hProcessSnap, &pe32)) {
        CloseHandle(hProcessSnap);
        return;
    }

    do {
        HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pe32.th32ProcessID);
        if (hProcess != NULL) {
            char szProcessPath[MAX_PATH];
            if (GetModuleFileNameExA(hProcess, NULL, szProcessPath, MAX_PATH) > 0) {
                if (targetPath == szProcessPath) {
                    std::cout << "Process ID: " << pe32.th32ProcessID << std::endl;
                    std::cout << "Process Name: " << pe32.szExeFile << std::endl;
                    found = true;
                    CloseHandle(hProcess);
                    break;
                }
            }
            CloseHandle(hProcess);
        }
    } while (Process32Next(hProcessSnap, &pe32));

    if (!found) 
    {
        std::cout << "Process with the specified path not found." << std::endl;
    }
    CloseHandle(hProcessSnap);
}


int main() 
{
  std::string processPath = "C:\\Users\\pc\\AppData\\Local\\Programs\\Notion\\Notion.exe";
  getProcessStateByPath(processPath) ; 
  return 0;
}

