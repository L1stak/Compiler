#include "./include/Parser.h"
//////////////////////////////////////////////////
///         Copyright (C) 2025  L1stak         ///
///             fast lang compiler             ///
//////////////////////////////////////////////////

void Parser::Expect(Token_structure token, long long pos, long long line) {

	if (token.Type != NULL) {
		std::cout << char(7) << std::endl;
		std::cout << "Syntax Error" << token.Type << " " << token.Value << " at line " << line <<std::endl;
	}
}

std::vector<AbstractSyntaxTree> syntaxTree;
AbstractSyntaxTree ASTObj;
void Parser::ParseTokens(std::vector<Token_structure> tokens) {
	long long pos = 0;
	long long len = tokens.size();
	long long line = 0;
	bool HasMain = false;

	for (pos; pos < len;pos++) {
		if (tokens[pos].Type == Types::NEWLINE) {
			line++;

		}
		else if (tokens[pos].Type == Types::KEYWORD) {
			if (tokens[pos].Value == "func") {
				Function func;
				
				if (tokens[pos + 1].Type != Types::ID and tokens[pos + 1].Value != "(") { // Error if token  after func not "(" or func name
					Expect(tokens[pos + 1], pos + 1, line);
				}

				else {
					if (tokens[pos + 1].Type == Types::ID) {
						func.name = tokens[pos + 1].Value;

						if (func.name == "main") {
							HasMain = true;
						}

					}
				}
				ASTObj.structure = func;
				syntaxTree.push_back(ASTObj);
			}

			else if (tokens[pos].Value == "for") {

									// logic for FOR

			}
			else if (tokens[pos].Value == "while") {

					// logic for while
			}
			else if (tokens[pos].Value == "import") {


			}

		}
		

	}


}

