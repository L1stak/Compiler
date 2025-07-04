


#pragma once

#include <iostream>
#include <vector>
#include <regex>
#include <string>
//////////////////////////////////////////////////
///         Copyright (C) 2025  L1stak         ///
///             fast lang compiler             ///
//////////////////////////////////////////////////
static std::vector<std::string> keywords = { "import", "func", "while", "boolean", "for", "int", "str", "if", "else", "elseif", "char", "byte", "float", "double" };

enum Types {
	OPERAND,
	NUMBER,
	ID,
	KEYWORD,
	VARIBLE

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

typedef struct Token_structure {
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

