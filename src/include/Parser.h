/*
* Fast lang compiler, a custom compiler
* Copyright (c) 2025 L1stak
* SPDX-License-Identifier: GPL-3.0-or-later
*/

#pragma once
#include "AST.h"

class Parser
{
public:
	void ParseTokens(std::vector<Token_structure> tokens);
	void Except(Token_structure token, long long pos, long long line, std::string comment);
};

