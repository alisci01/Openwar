#include "HWPalette.h"

HWPalette::HWPalette() : HWResource()
{
}

HWPalette::HWPalette(HWResource& res) : HWResource(res)
{
}

HWPalette::~HWPalette()
{
}

void HWPalette::loadResource()
{
	getData();
	m_numColors = m_data[3] << 8 | m_data[2];
	m_colors = new uint32_t[m_numColors];
	
	for (uint32_t i = 4; i < m_numColors; i += 3)
	{
		uint32_t color = 0;
		// blue
		color |= (m_data[i] << 10) & 0xFF00;
		// green
		color |= (m_data[i + 1] << 18) & 0xFF0000;
		// red
		color |= (m_data[i + 2] << 26) & 0xFF000000;
		// alpha
		color |= 0xFF;

		m_colors[(i - 4) / 3] = color;
	}

	delete[] m_data;
}