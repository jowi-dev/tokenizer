#include <iostream>
#include <string>

#include "./lexer.cpp"

int main() {
    std::string userInput;
    
    while (true) {
        std::cout << "Enter a line of text (or 'quit' to exit): ";
        std::getline(std::cin, userInput);
        
        if (userInput == "quit") {
            break;
        }

        auto tokens = tokenize(userInput);
        
        std::cout << "You entered: " << userInput << std::endl;
        for(int i = 0; i < tokens.size(); i++){
          std::cout << "{" << tokens[i].literal << ", " <<tokens[i].toString() << "}" << std::endl;
        }
    }
    
    return 0;
}
