#pragma once

#include <crow.h>
#include "SkribbleDatabase.h"

import match;

class Routes
{
public:
	void Run();
private:
	std::vector<skribble::Match> m_matches;
	UserStorage m_userDb;
	WordStorage m_wordDb;
};
