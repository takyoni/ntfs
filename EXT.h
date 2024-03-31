#pragma once
#include "FS.h"
class EXT :
	public FS
{
protected:
	// В разных ФС различается только процесс получения размера кластера
	bool ReadClusterSize();
};