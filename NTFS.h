#pragma once
#include "FS.h"
class NTFS :
	public FS
{
public:
	bool ReadCluster(unsigned int, BYTE*);
	bool ReadClusterSize();
};

