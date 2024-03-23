#include "NTFS.h"
#include <iostream>
#include "windows.h"
#include "stdio.h"
using namespace std;
bool NTFS::ReadCluster(unsigned int clusterNum, BYTE* array)
{
    DWORD bytesRead;
    DWORD bytesToRead = clusterSize;
    LARGE_INTEGER sectorSizeOffset;
    sectorSizeOffset.QuadPart = clusterNum * clusterSize; // Смещение для размера сектора

    // Устанавливаем смещение
    if (!SetFilePointerEx(fileHandler, sectorSizeOffset, NULL, FILE_BEGIN)) {
        //std::cerr << "Parse error\n";
        throw std::invalid_argument("Parse error!");
        CloseHandle(fileHandler);
        return false;
    }
    if (!ReadFile(fileHandler, array, clusterSize, &bytesRead, NULL))
    {
        throw std::invalid_argument("Parse error!");
        //printf("ReadFile: %u\n", GetLastError());
        CloseHandle(fileHandler);
        return false;
    }
    return true;
}
bool NTFS::ReadClusterSize()
{
    BYTE sector[512];
    DWORD bytesRead;
    DWORD bytesToRead = sizeof(sector);

    //SetFilePointer(device,0, NULL, FILE_BEGIN);
    LARGE_INTEGER sectorSizeOffset;
    sectorSizeOffset.QuadPart = 512; // Смещение для размера сектора
    // Устанавливаем смещение
    if (!SetFilePointerEx(fileHandler, sectorSizeOffset, NULL, FILE_BEGIN)) {
        std::cerr << "Parse error\n";
        CloseHandle(fileHandler);
        //return GetLastError();
    }
    if (!ReadFile(fileHandler, sector, bytesToRead, &bytesRead, NULL))
    {
        printf("ReadFile: %u\n", GetLastError());
        CloseHandle(fileHandler);
        //return GetLastError();
    }
    unsigned int sectorSize = (sector[12] << 8) | sector[11];
    unsigned int countSectors = static_cast<int>(sector[13]);
    clusterSize = sectorSize * countSectors;
}

