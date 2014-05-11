#include <vector>
#include <string>
#include <locale>
#include "HWResManager.h"
#include "HWResFile.h"
#include "FileSystem.h"

using namespace gameplay;

const std::string resExt = ".res";

bool iequals(const std::string& a, const std::string& b)
{
	std::locale loc;
	unsigned int sz = a.size();
	if (b.size() != sz)
		return false;
	for (unsigned int i = 0; i < sz; ++i)
	if (std::tolower(a[i], loc) != std::tolower(b[i], loc))
		return false;
	return true;
}

HWResManager::HWResManager(const char* basePath)
{
	std::vector<std::string> listOfFiles;
	if (FileSystem::listFiles(basePath, listOfFiles))
	{
		for (std::string& filePath : listOfFiles)
		{
			std::string fileExt = FileSystem::getExtension(filePath.c_str());
			if (iequals(fileExt, resExt))
			{
				auto fileStream = FileSystem::open(filePath.c_str());
				m_resFileMap[FileSystem::getFileNameWithoutExtension(filePath.c_str())] = HWResFile(fileStream);
			}
		}
	}
	else
	{
		// TODO error checking
	}
}

HWResManager::~HWResManager()
{
}
