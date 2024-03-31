#include "EXT.h"
#include <iostream>
#include "windows.h"
#include "stdio.h"
using namespace std;

bool EXT::ReadClusterSize()
{
    BYTE sector[1024];
    DWORD bytesRead;
    DWORD bytesToRead = sizeof(sector);

    LARGE_INTEGER sectorSizeOffset;
    sectorSizeOffset.QuadPart = 1024;

    if (!SetFilePointerEx(fileHandler, sectorSizeOffset, NULL, FILE_BEGIN)) {
        throw std::invalid_argument("Set FilePointer error");
        CloseHandle(fileHandler);
        return false;
    }
    if (!ReadFile(fileHandler, sector, bytesToRead, &bytesRead, NULL))
    {
        throw std::invalid_argument("ReadFile error");
        CloseHandle(fileHandler);
        return false;
    }
    //размер сектора
    unsigned int sectorSize = 1024 << sector[19];
    //количество секторов
    unsigned int countSectors = *(reinterpret_cast<unsigned int*>(sector + 32));
    //размер кластера
    clusterSize = sectorSize * countSectors;
    return true;
}