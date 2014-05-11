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

	enum HWResourceType
	{
		PAL,
		SPR,
		NONE
	};

protected:
	HWResFile*		m_resFile;
	uint32_t		m_offset;
	uint32_t		m_size;
	unsigned char*	m_data;
	HWResourceType	m_resType;

// functions
public:
	HWResource(HWResFile* resFile, uint32_t flags, uint32_t offset, uint32_t size, std::string name);
	HWResource(HWResource& res);
	HWResource();
	~HWResource();

	virtual void loadResource() {}

	inline HWResourceType getResourceType() { return m_resType; }

protected:
	void getData();

	static HWResourceType getResourceTypeFromExtension(std::string fileExtension);

};

