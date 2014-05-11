#pragma once

#include <map>
#include <string>
#include <cstdint>
#include "Stream.h"
#include "HWResource.h"

class HWResFile
{

// members
protected:
	gameplay::Stream*		m_resFileStream;
	uint32_t	m_numberOfFiles;
	std::map<std::string, HWResource> m_fileMap;

// functions
public:
	HWResFile(gameplay::Stream* stream);
	HWResFile();
	~HWResFile();

};

