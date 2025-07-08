/*
* Fast lang compiler, a custom compiler
* Copyright (c) 2025 L1stak
* SPDX-License-Identifier: GPL-3.0-or-later
*/

#include "./include/Lexer.h"
#include <iostream>

int keywordsCount = keywords.size();


 void Lexer::AddKeyword(std::string keyword) {
   
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

     if (token[0] >= 42 && token[0] <= 47 or token[0] == 33 or token[0] >= 58 or token[0] <= 62) {

         return true;
     }

     return false;
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
             structuredTokens.push_back(tk);

         }
         else if (token == "\n") {
             tk.Type = Types::NEWLINE;
             tk.Value = "";
             structuredTokens.push_back(tk);
         }
         else {
             tk.Type = Types::ID;
             tk.Value = token;
             structuredTokens.push_back(tk);
         }
     }
    

   
     return tokens;
 }