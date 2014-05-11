#include "HWResource.h"

HWResource::HWResource(HWResFile* resFile, uint32_t flags, uint32_t offset, uint32_t size, std::string name)
{
	Name = name;
	Flags = flags;
	m_offset = offset;
	m_size = size;
	m_resFile = resFile;
}

HWResource::HWResource()
{
	Name = "";
	Flags = 0;
	m_offset = 0;
	m_size = 0;
	m_resFile = nullptr;
}

HWResource::~HWResource()
{
}
