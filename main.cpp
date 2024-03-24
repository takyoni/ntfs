#include <iostream>
#include "FS.h"
#include "NTFS.h"
#include "windows.h"
using namespace std;

int main()
{
    NTFS fileSystem;

    if (!fileSystem.Init(L"\\\\.\\C:")) {
        cout << "Init: " << GetLastError();
        return false;
    };
    int clusterSize = fileSystem.ClusterSize();
    BYTE * cluster = new BYTE[clusterSize];

    if (!fileSystem.ReadCluster(5, cluster)) {
        cout << "ReadCluster: " << GetLastError();
        return false;
    };

    for (int i = 0; i < clusterSize; i++) {
        cout << hex << static_cast<int>(cluster[i]) <<" ";
        if ((i + 1) % 16 == 0 || i == clusterSize - 1) {
            std::cout << std::endl;
        }
    }

    delete[] cluster;
}