#include "HWResFile.h"
#include "Resources/HWPalette.h"
#include "Resources/HWSprTexture.h"
#include "Stream.h"

typedef struct
{
	uint32_t flags;
	char name[16];
	uint32_t offset;
	uint32_t size;
} FileRecord;

const char* XorString = "SOFTWAREREFINERY";

using namespace gameplay;

HWResFile::HWResFile(Stream* stream)
{
	m_resFileStream = stream;
	// seek to last 4 bytes and get the header offset
	stream->seek(-4, SEEK_END);
	uint32_t headerOffset = 0;
	stream->read(&headerOffset, sizeof(uint32_t), 1);
	// seek to offset and get the number of files in this RES file
	stream->seek(headerOffset, SEEK_SET);
	stream->read(&m_numberOfFiles, sizeof(uint32_t), 1);
	// not sure if the 0x80000000 bit flag means anything
	m_numberOfFiles &= 0x7FFFFFFF;

	// read through all them file records
	FileRecord* fileRecords = new FileRecord[m_numberOfFiles];
	stream->read(fileRecords, sizeof(FileRecord), m_numberOfFiles);

	// setup the filemap
	for (int i = 0; i < m_numberOfFiles; i++)
	{
		FileRecord& record = fileRecords[i];
		std::string name;

		// decode the name string
		for (int j = 0; j < 16; j++)
		{
			char decodedChar = fileRecords[i].name[j] ^ XorString[j];
			if (decodedChar != ' ' && decodedChar != '\0')
				name.append(1, decodedChar);
		}

		HWResource res(this, record.flags, record.offset, record.size, name);
		HWResource* resPtr = nullptr;
		auto resType = res.getResourceType();
		switch (resType)
		{
		case HWResource::HWResourceType::PAL:
			resPtr = new HWPalette(res);
			resPtr->loadResource();
			break;
		case HWResource::HWResourceType::SPR:
			resPtr = new HWSprTexture(res);
			break;
		default:
			resPtr = new HWResource(res);
			break;
		}
		m_fileMap[name] = resPtr;
	}

	delete[] fileRecords;
}

HWResFile::HWResFile()
{
}

HWResFile::~HWResFile()
{
	m_resFileStream->close();
}

void HWResFile::readData(unsigned char* dest, uint32_t offset, uint32_t size)
{
	m_resFileStream->seek(offset, SEEK_SET);
	m_resFileStream->read(dest, sizeof(unsigned char), size);
	m_resFileStream->seek(0, SEEK_SET);
}