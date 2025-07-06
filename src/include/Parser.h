#pragma once
#include "./include/AST.h"

//////////////////////////////////////////////////
///         Copyright (C) 2025  L1stak         ///
///             fast lang compiler             ///
//////////////////////////////////////////////////
class Parser
{
public:
	void ParseTokens(std::vector<Token_structure> tokens);
	void Except(Token_structure token, long long pos, long long line, std::string comment);
};

