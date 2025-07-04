#include "Lexer.h"
#include <iostream>





int keywordsCount = keywords.size();


 void Lexer::AddKeyword(std::string keyword) {
    // Lexer::keywords.pop_back();
      keywords.push_back(keyword);
 }


 std::string Lexer::GenerateRegex() {
     std::string keyword;
     std::string regex;
  
     for (int i = 0; i < keywordsCount;i++ ){
         keyword += keywords.at(i) + "|"; 
    }

   
     if (!keyword.empty()) {
         keyword.pop_back();
     }

   
    
     regex = "\\b( " + keyword + R"()\b|[a-zA-Z_]\w*|\d+|"[^"]*"|'[^']*'|[=;(){}""<><<>>.!*+-])";
     //std::cout << regex;
     return regex;
 }

 inline bool IsDigit(std::string data) {
     int buffer=0;
     for (size_t i = 0; i < data.size(); i++)
     {

         if (data.at(i) > 48 && data.at(i) < 57) {
             buffer++;
         }
         if (buffer == data.size()) {
             return true;
          }

     }
     return false;
     

 }
 inline bool IsKeyword(std::string token) {

     for (size_t i = 0; i < keywordsCount; i++)
     {
         if (token == keywords.at(i)) {
             return true;
         }
     }
     return false;
 }
 inline bool IsOperand(std::string token) {

     return (token == "+" or token == "-" or token == "=");


 }
 std::vector<std::string> Lexer::GetTokens(std::string code) {
    
  
     std::regex tokenPattern(GenerateRegex());
     std::sregex_iterator it(code.begin(), code.end(), tokenPattern);
     std::sregex_iterator end;

     std::vector<std::string> tokens;
     std::vector<Token_structure> structuredTokens;
     while (it != end) {
         tokens.push_back(it->str() + " ");
         ++it;
     }
     for (auto token: tokens)
     {
         Token_structure tk;
         if (IsDigit(token)) {
             tk.Type = Types::NUMBER;
             tk.Value = token;
             structuredTokens.push_back(tk);
         }
         else if (IsKeyword(token)) {
             tk.Type = Types::KEYWORD;
             tk.Value = token;
             structuredTokens.push_back(tk);

         }
         else if (IsOperand(token)) {
             tk.Type = Types::OPERAND;
             tk.Value = token;


         }
     }
    

   
     return tokens;
 }