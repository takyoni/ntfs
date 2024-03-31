#include <iostream>
#include "FS.h"
#include "NTFS.h"
#include "FAT16.h"
#include "EFAT.h"
#include "HFS+.h"
#include "windows.h"
#include <iomanip>
using namespace std;

void hexdump(const BYTE* array, unsigned int length, unsigned int offset) {
    const int bytes_per_line = 16;
    for (size_t i = 0; i < length; i += bytes_per_line) {
        // Вывод адреса текущей строки
        std::cout << std::setw(8) << std::setfill('0') << std::hex << offset + i << ": ";

        // Вывод байтов в шестнадцатеричном формате
        for (int j = 0; j < bytes_per_line; ++j) {
            if (i + j < length) {
                std::cout << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(array[i + j]) << " ";
            }
            else {
                std::cout << "   "; // для неполных строк
            }
        }

        // Вывод символов ASCII
        std::cout << "  ";
        for (int j = 0; j < bytes_per_line; ++j) {
            if (i + j < length) {
                char c = array[i + j];
                std::cout << (c >= 32 && c < 127 ? c : '.');
            }
            else {
                std::cout << " "; // для неполных строк
            }
        }

        std::cout << std::endl;
    }
}

int main()
{
    // NTFS
    NTFS fileSystem;

    if (!fileSystem.Init(L"\\\\.\\C:")) {
        cout << "Init: " << GetLastError();
        return false;
    };
    unsigned int clusterSize = fileSystem.ClusterSize();
    unsigned int clusterNumber = 5;
    BYTE * cluster = new BYTE[clusterSize];

    if (!fileSystem.ReadCluster(clusterNumber, cluster)) {
        cout << "Read cluster error: " << GetLastError();
        return false;
    };

    hexdump(cluster, clusterSize, clusterNumber * clusterSize);
    cout << "Cluster size per bytes: " << dec << clusterSize << endl;

    // FAT16
    /*
    FAT16 fileSystem;

    if (!fileSystem.Init(L"\\\\.\\E:")) {
        cout << "Init: " << GetLastError();
        return false;
    };
    unsigned int clusterSize = fileSystem.ClusterSize();
    unsigned int clusterNumber = 0;
    BYTE* cluster = new BYTE[clusterSize];

    if (!fileSystem.ReadCluster(clusterNumber, cluster)) {
        cout << "Read cluster error: " << GetLastError();
        return false;
    };

    cout << "Read cluster result: " << endl;
    hexdump(cluster, clusterSize, clusterNumber * clusterSize);
    cout << "Cluster size per bytes: " << dec << clusterSize << endl;
    */

    // EFAT
    /*
    EFAT fileSystem;

    if (!fileSystem.Init(L"\\\\.\\G:")) {
        cout << "Init: " << GetLastError();
        return false;
    };
    unsigned int clusterSize = fileSystem.ClusterSize();
    unsigned int clusterNumber = 0;
    BYTE* cluster = new BYTE[clusterSize];

    if (!fileSystem.ReadCluster(clusterNumber, cluster)) {
        cout << "Read cluster error: " << GetLastError();
        return false;
    };

    hexdump(cluster, clusterSize, clusterNumber * clusterSize);
    
    cout << "\nCluster size per bytes: " << dec << clusterSize << endl;
    */
    
    // HFS+
    /*
    HFSP fileSystem;

    if (!fileSystem.Init(L"\\\\.\\F:")) {
        cout << "Init: " << GetLastError();
        return false;
    };
    unsigned int clusterSize = fileSystem.ClusterSize();
    unsigned int clusterNumber = 0;
    BYTE * cluster = new BYTE[clusterSize];

    if (!fileSystem.ReadCluster(clusterNumber, cluster)) {
        cout << "Read cluster error: " << GetLastError();
        return false;
    };

    hexdump(cluster, clusterSize, clusterNumber * clusterSize);
    cout << "Cluster size per bytes: " << dec << clusterSize << endl;
    */

    // FAT32
    /*
    FAT32 fileSystem;

    if (!fileSystem.Init(L"\\\\.\\D:")) {
    cout << "Init: " << GetLastError();
    return false;
    };
    unsigned int clusterSize = fileSystem.ClusterSize();
    unsigned int clusterNumber = 0;
    BYTE* cluster = new BYTE[clusterSize];

    if (!fileSystem.ReadCluster(clusterNumber, cluster)) {
    cout << "Read cluster error: " << GetLastError();
    return false;
    };

    cout << "Read cluster result: " << endl;
    hexdump(cluster, clusterSize, clusterNumber * clusterSize);
    cout << "Cluster size per bytes: " << dec << clusterSize << endl;
    */

    delete[] cluster;
}
