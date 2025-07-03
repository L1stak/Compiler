#include "Lexer.h"
#include <iostream>








void Lexer::AddKeyword(std::string keyword) {

    keywords.push_back(keyword);

}


std::string GenerateRegex() {
    std::string keyword;
    std::string regex;
  
    for (int i = 0; i < keywords.size();i++ ){
        keyword += keywords.at(i) + "|"; 
    }

   
    if (!keyword.empty()) {
        keyword.pop_back();
    }

   
    regex = R"(\b( )" + keyword + R"(\b|[a-zA-Z_]\w*|\d+|"[^"]*"|'[^']*'|[=;(){}])";

    return regex;
}
Token Lexer::GetTokens(std::string code) {
   // std::string regex ="R\"("+ GenerateRegex() + ")\"";
  
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