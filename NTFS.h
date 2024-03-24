#pragma once
#include "FS.h"
class NTFS :
	public FS
{
protected:
	// В разных ФС различается только процесс получения размера кластера
	bool ReadClusterSize();
};

