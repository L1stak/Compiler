#include "Lexer.h"
#include <iostream>








 void Lexer::AddKeyword(std::string keyword) {
    // Lexer::keywords.pop_back();
      keywords.push_back(keyword);
 }


 std::string Lexer::GenerateRegex() {
     std::string keyword;
     std::string regex;
  
     for (int i = 0; i < Lexer::keywords.size();i++ ){
         keyword += Lexer::keywords.at(i) + "|"; 
    }

   
     if (!keyword.empty()) {
         keyword.pop_back();
     }

   
    
     regex = "\\b( " + keyword + R"()\b|[a-zA-Z_]\w*|\d+|"[^"]*"|'[^']*'|[=;(){}])";
     //std::cout << regex;
     return regex;
 }
 Token Lexer::GetTokens(std::string code) {
    
  
     std::regex tokenPattern(GenerateRegex());
     std::sregex_iterator it(code.begin(), code.end(), tokenPattern);
     std::sregex_iterator end;

     std::vector<std::string> tokens;

     while (it != end) {
         tokens.push_back(it->str());
         ++it;
     }

     for (const auto& t : tokens) {
         std::cout << "[" << t << "]\n";
     }

     Token token;
     token.Type = Types::ID;
     return token;
 }