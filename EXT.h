#pragma once
#include "FS.h"
class EXT :
	public FS
{
protected:
	// � ������ �� ����������� ������ ������� ��������� ������� ��������
	bool ReadClusterSize();
};