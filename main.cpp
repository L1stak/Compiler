#include <iostream>
#include "Lexer.h"


#include <vector>
#include <regex>
#include <string>
Lexer* lexer = new Lexer();
int main() {
    std::string code = "import sio func main(int b, int a) {int d = 5; if i > 5 { print("")}else { }";

    lexer->GetTokens(code);

    return 0;
}