#include "./include/Parser.h"
//////////////////////////////////////////////////
///         Copyright (C) 2025  L1stak         ///
///             fast lang compiler             ///
//////////////////////////////////////////////////

void Parser::Except(Token_structure token, long long pos, long long line, std::string comment) {

	if (token.Type != NULL) {
		std::cout << char(7) << std::endl;
		std::cout << "Syntax Error," << comment<< token.Type << " " << token.Value << " at line " << line <<std::endl;
	}
}

std::vector<AbstractSyntaxTree> syntaxTree;
AbstractSyntaxTree ASTObj;
void Parser::ParseTokens(std::vector<Token_structure> tokens) {
	long long pos = 0;
	long long len = tokens.size();
	long long line = 0;
	bool HasMain = false;

	/*
	TODO: 
		Adding for and while logic and varibles
	
	*/
	for (pos; pos < len;pos++) {
		if (tokens[pos].Type == Types::NEWLINE) {
			line++;

		}
		else if (tokens[pos].Type == Types::KEYWORD) {
			if (tokens[pos].Value == "func") {
				Function func;
				
				if (tokens[pos + 1].Type != Types::ID | tokens[pos + 1].Value != "(") { // Error if token  after func not "(" or func name
					Except(tokens[pos + 1], pos + 1, line,"symbol after func must be () or func name");
					
				}

				else {
					if (tokens[pos + 1].Type == Types::ID) { // define func name
						func.name = tokens[pos + 1].Value;

						if (func.name == "main") { // if func name = main
							HasMain = true;
						}

					}
				}
				ASTObj.structure = func; // object for AST
				syntaxTree.push_back(ASTObj);
			}

			else if (tokens[pos].Value == "for") {

									// logic for FOR

			}
			else if (tokens[pos].Value == "while") {

					// logic for while
			}
			else if (tokens[pos].Value == "import") {
					if (tokens[pos+1].Type != Types::ID) {
						Except(tokens[pos + 1], pos + 1, line,"after import must be name for import");
					}
					Import imp;
					imp.nameForImport = tokens[pos+1].Value;
					ASTObj.structure = imp;
					syntaxTree.push_back(ASTObj);
			}


		}
		

	}


}

