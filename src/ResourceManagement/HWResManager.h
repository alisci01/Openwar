#pragma once

#include <map>
#include "HWResFile.h"

class HWResManager
{
// members
protected:
	std::map<std::string, HWResFile> m_resFileMap;

// functions
public:
	HWResManager(const char* basePath);
	~HWResManager();

};

