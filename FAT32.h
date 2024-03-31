#pragma once
#include "FS.h"

class FAT32 :
	public FS
{
private:
#pragma pack(push, 1)
	typedef struct {
		BYTE Padding1[11];
		BYTE bytesPerSector[2];
		BYTE sectorsPerCluster;
	} BootRecord;
#pragma pack(pop)
protected:
	// В разных ФС различается только процесс получения размера кластера
	bool ReadClusterSize();
};
