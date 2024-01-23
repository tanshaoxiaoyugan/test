#pragma once

class CDGI {
public:

	bool setResolution(uint vRes);
	bool run(const PC_t::Ptr vInput, const PC_t::Ptr voOutput);


private:
	uint m_Res;

};
