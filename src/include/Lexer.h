/*
* Fast lang compiler, a custom compiler
* Copyright (c) 2025 L1stak
* SPDX-License-Identifier: GPL-3.0-or-later
*/

#pragma once

#include <iostream>
#include <vector>
#include <regex>
#include <string>
static std::vector<std::string> keywords = { "import", "func", "while", "boolean", "for", "int", "str", "if", "else", "elseif", "char", "byte", "float", "double" };

enum Types {
	OPERAND,
	NUMBER,
	ID,
	KEYWORD,
	VARIBLE,
	INT,
	STR,
	BOOL,
	FLOAT,
	DOUBLE,
	BYTE,
	PLUS,
	MINUS,
	MUL,
	DIV,
	NEWLINE

};

enum KeywordsEnum {
	_import,
	_func,
	_for,
	_while,
	_int,
	_str,
	_if,
	_else,
	_elseif,
	_char,
	_byte,
	_float,
	_boolean


};

struct Token_structure {
	Types Type;
	std::string Value;

};

class Lexer
{
public:
  std::vector<std::string> GetTokens(std::string code);
  std::string GenerateRegex();
  void AddKeyword(std::string keyword);
  



};

