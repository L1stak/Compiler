/*
* Fast lang compiler, a custom compiler
* Copyright (c) 2025 L1stak
* SPDX-License-Identifier: GPL-3.0-or-later
*/

#pragma once
#include "./Lexer.h"
#include <string>
#include <any>

typedef struct AbstractSyntaxTree {
	std::any structure;


}AbstractSyntaxTree;
struct Varible {
	std::string name;
	std::any value;
	Types ValueType;
};

struct Function {
	std::string name;
	std::string args;

	Types ReturnValueType;
};

struct Operand {
	std::string operand;
	Types OperandType;
};

struct Number {
	std::string number;
};

struct Call {
	std::string id;
	std::string args;
};
struct Import {
	std::string nameForImport;

};
static std::string VarType[8] = { "","","","int","char","float","double","boolean" }; // �������, �����  OPTIMIZATE ME

// int string boolean float double char

class AST
{

	


};

