#include "FS.h"
#include "windows.h"
#include <stdexcept>
bool FS::ReadClusterSize()
{
    return false;
}
bool FS::ReadCluster(unsigned int, BYTE*)
{
    return false;
}
FS::FS(LPCWSTR fileName) {
    fileHandler = CreateFileW(
        fileName,    // Drive to open
        GENERIC_READ,           // Access mode
        FILE_SHARE_READ | FILE_SHARE_WRITE,        // Share Mode
        NULL,                   // Security Descriptor
        OPEN_EXISTING,          // How to create
        0,                      // File attributes
        NULL);                  // Handle to template

    if (fileHandler == INVALID_HANDLE_VALUE)
    {
        printf("CreateFile: %u\n", GetLastError());
        throw std::invalid_argument("Error INVALID_HANDLE_VALUE!");
    }
}
FS::~FS() {
	CloseHandle(fileHandler);
}

