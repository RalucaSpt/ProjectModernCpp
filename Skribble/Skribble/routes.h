#pragma once

#include <crow.h>

import match;

class Routes
{
public:
	void Run();
private:
	std::vector<skribble::Match> m_matches;
};
