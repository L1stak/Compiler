#pragma once
#include <iostream>
#include <vector>
#include <regex>
#include <string>
enum Types {
	OPERAND,
	NUMBER,
	ID,
	KEYWORD

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

typedef struct Token {
	Types Type;
	std::string Value;

};
std::vector<std::string> keywords = { "import","func","while","boolean","for","int","str","if","else","elseif","char","byte","float","double" };

class Lexer
{
	
	
public:
 Token GetTokens(std::string code);
 std::string GenerateRegex();
 void AddKeyword(std::string keyword);
 

 
	

};

