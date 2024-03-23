#include "windows.h"
#pragma once
class FS
{
protected:
	unsigned int clusterSize = {0};
	HANDLE fileHandler = NULL;
public:
//	virtual void Init(LPCWSTR);
	virtual bool ReadClusterSize();
	virtual bool ReadCluster(unsigned int, BYTE*);
	virtual unsigned int ClusterSize() { return clusterSize; };
	virtual bool ReadCluster(unsigned int, char*) { return false; };
	FS(LPCWSTR);
	virtual ~FS();
};