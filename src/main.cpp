#include <iostream>
#include "./include/Lexer.h"


#include <vector>
#include <regex>
#include <string>
//Lexer* lexer = new Lexer();
int main() {
    Lexer lexer;
    std::string code = "import sio func main(int b, int a) {int d = 5; if i > 5 { print("")}else { }";

   std::vector<std::string> data = lexer.GetTokens(code);
   for ( auto token : data)
   {
       std::cout << token;
   }
    return 0;
}