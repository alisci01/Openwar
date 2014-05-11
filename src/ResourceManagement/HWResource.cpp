#include <locale>
#include "HWResource.h"
#include "HWResFile.h"
#include "FileSystem.h"

using namespace gameplay;

HWResource::HWResource(HWResFile* resFile, uint32_t flags, uint32_t offset, uint32_t size, std::string name)
{
	Name = name;
	Flags = flags;
	m_offset = offset;
	m_size = size;
	m_resFile = resFile;
	m_resType = getResourceTypeFromExtension(FileSystem::getExtension(name.c_str()));
	m_data = nullptr;
}

HWResource::HWResource(HWResource& res)
{
	Name = res.Name;
	Flags = res.Flags;
	m_offset = res.m_offset;
	m_size = res.m_size;
	m_resFile = res.m_resFile;
	m_resType = res.m_resType;
	m_data = nullptr;
}

HWResource::HWResource()
{
	Name = "";
	Flags = 0;
	m_offset = 0;
	m_size = 0;
	m_resFile = nullptr;
	m_resType = HWResourceType::NONE;
	m_data = nullptr;
}

HWResource::~HWResource()
{
}

void HWResource::getData()
{
	if (m_data != nullptr)
		delete[] m_data;

	m_data = new unsigned char[m_size];
	m_resFile->readData(m_data, m_offset, m_size);
}

bool iequals(const std::string& a, const std::string& b);

HWResource::HWResourceType HWResource::getResourceTypeFromExtension(std::string fileExtension)
{
	if (iequals(fileExtension, ".SPR"))
		return HWResourceType::SPR;
	else if (iequals(fileExtension, ".PAL"))
		return HWResourceType::PAL;

	return HWResourceType::NONE;
}