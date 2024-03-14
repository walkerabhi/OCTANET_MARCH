#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // for std::transform
#include <sstream> // for std::stringstream

// Function to convert string to lowercase
std::string toLower(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Function to process user input and generate AI response
std::string processInput(std::string input) {
    // Convert input to lowercase for easier comparison
    input = toLower(input);

    // Define some simple rules or patterns for responses
    if (input.find("hello") != std::string::npos ||
        input.find("hi") != std::string::npos) {
        return "Hello! How can I assist you today?";
    } else if (input.find("time") != std::string::npos) {
        // Add code here to fetch current time
        return "I'm sorry, I cannot provide the current time.";
    } else {
        // Default response for unrecognized input
        return "I'm sorry, I don't understand. Can you please rephrase?";
    }
}

int main() {
    std::string userInput;
    std::cout << "AI Assistant: Hello! How can I assist you today?" << std::endl;
    
    // Main loop for interacting with the AI assistant
    while (true) {
        std::cout << "You: ";
        std::getline(std::cin, userInput);
        
        // Check if user wants to exit
        if (toLower(userInput) == "exit") {
            std::cout << "AI Assistant: Goodbye!" << std::endl;
            break;
        }
        
        // Process user input and generate AI response
        std::string response = processInput(userInput);
        std::cout << "AI Assistant: " << response << std::endl;
    }
    
    return 0;
}
