#include <iostream>
#include "FS.h"
#include "NTFS.h"
#include "FAT16.h"
#include "windows.h"
using namespace std;

int main()
{
    // NTFS
    NTFS fileSystem;

    if (!fileSystem.Init(L"\\\\.\\E:")) {
        cout << "Init: " << GetLastError();
        return false;
    };
    int clusterSize = fileSystem.ClusterSize();
    BYTE * cluster = new BYTE[clusterSize];

    if (!fileSystem.ReadCluster(0, cluster)) {
        cout << "Read cluster error: " << GetLastError();
        return false;
    };

    for (int i = 0; i < clusterSize; i++) {
        cout << hex << static_cast<int>(cluster[i]) <<" ";
        if ((i + 1) % 16 == 0 || i == clusterSize - 1) {
            cout << endl;
        }
    }
    cout << "Cluster size per bytes: " << dec << clusterSize << endl;

    // FAT16
    /*
    FAT16 fileSystem;

    if (!fileSystem.Init(L"\\\\.\\E:")) {
        cout << "Init: " << GetLastError();
        return false;
    };
    int clusterSize = fileSystem.ClusterSize();
    BYTE* cluster = new BYTE[clusterSize];

    if (!fileSystem.ReadCluster(0, cluster)) {
        cout << "Read cluster error: " << GetLastError();
        return false;
    };

    cout << "Read cluster result: " << endl;
    for (int i = 0; i < clusterSize; i++) {
        cout << hex << static_cast<int>(cluster[i]) << " ";
        if ((i + 1) % 16 == 0 || i == clusterSize - 1) {
            cout << endl;
        }
    }
    cout << "Cluster size per bytes: " << dec << clusterSize << endl;
    */

    delete[] cluster;
}