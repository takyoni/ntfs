#include "windows.h"
#pragma once
class FS
{
protected:
	HANDLE fileHandler = NULL;
	unsigned int clusterSize = {0};
	virtual bool ReadClusterSize();
public:
	virtual bool Init(LPCWSTR);
	virtual bool ReadCluster(unsigned int, BYTE*);
	virtual unsigned int ClusterSize() { return clusterSize; };
	virtual ~FS();
};