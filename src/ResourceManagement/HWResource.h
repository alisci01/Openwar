#pragma once

#include <string>
#include <cstdint>

class HWResFile;

class HWResource
{

// members
public:
	uint32_t	Flags;
	std::string	Name;

protected:
	uint32_t	m_offset;
	uint32_t	m_size;
	char*		m_data;

// functions
public:
	HWResource(HWResFile* resFile, uint32_t flags, uint32_t offset, uint32_t size, std::string name);
	HWResource();
	~HWResource();

};

