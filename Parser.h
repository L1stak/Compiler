#pragma once
#include "AST.h"

//////////////////////////////////////////////////
///         Copyright (C) 2025  L1stak         ///
///             fast lang compiler             ///
//////////////////////////////////////////////////
class Parser
{
public:
	void ParseTokens(std::vector<Token_structure> tokens);
	void Expect(Token_structure token, long long pos, long long line);
};

