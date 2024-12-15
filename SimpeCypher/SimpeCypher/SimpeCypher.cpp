#include <iostream>
#include <string>
#include <unordered_map>

// Predefined shuffled alphabet
std::string shuffledAlphabet = "QWERTYUIOPASDFGHJKLZXCVBNM";  // This is the custom shuffled alphabet

// Function to encrypt the text using the shuffled alphabet
std::string encrypt(const std::string& text, const std::string& shuffledAlphabet) {
    std::string result = "";
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";  // Standard alphabet

    // Create the substitution table
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';  // Determine if the letter is uppercase
            // Find the index of the character in the standard alphabet and replace it with the character from the shuffled alphabet
            int index = toupper(c) - 'A';
            result += shuffledAlphabet[index];
        }
        else {
            result += c;  // If it's not a letter, leave the character unchanged
        }
    }
    return result;
}

// Function to decrypt the text using the shuffled alphabet
std::string decrypt(const std::string& text, const std::string& shuffledAlphabet) {
    std::string result = "";
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";  // Standard alphabet

    // Create the reverse substitution table
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';  // Determine if the letter is uppercase
            // Find the character in the shuffled alphabet and replace it with the character from the standard alphabet
            int index = shuffledAlphabet.find(toupper(c));
            result += (isupper(c) ? 'A' : 'a') + index;  // Maintain the case of the original character
        }
        else {
            result += c;  // If it's not a letter, leave the character unchanged
        }
    }
    return result;
}

int main() {
    std::string text;

    // Input the text
    std::cout << "Enter text: ";
    std::getline(std::cin, text);

    // Use the predefined shuffled alphabet
    std::cout << "Shuffled Alphabet: " << shuffledAlphabet << std::endl;

    // Encrypt the text
    std::string encrypted = encrypt(text, shuffledAlphabet);
    std::cout << "Encrypted text: " << encrypted << std::endl;

    // Decrypt the text
    std::string decrypted = decrypt(encrypted, shuffledAlphabet);
    std::cout << "Decrypted text: " << decrypted << std::endl;

    return 0;
}
