// Copyright 2014 Ali Scissons
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//	http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

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
	gameplay::Stream*					m_resFileStream;
	uint32_t							m_numberOfFiles;
	std::map<std::string, HWResource*>	m_fileMap;

// functions
public:
	HWResFile(gameplay::Stream* stream);
	HWResFile();
	~HWResFile();

	void readData(unsigned char* dest, uint32_t offset, uint32_t size);

};

