#pragma once

#include "../HWResource.h"

class HWPalette : public HWResource
{
	// members
protected:
	uint32_t	m_numColors;
	uint32_t*	m_colors;

// functions
public:
	HWPalette();
	HWPalette(HWResource& res);
	virtual ~HWPalette();

	void loadResource() override;

	inline uint32_t getColor(uint32_t palNdx)
	{
		if (palNdx >= m_numColors)
			return 0;

		return m_colors[palNdx];
	}

};

