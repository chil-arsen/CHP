#include <iostream>
#include <string>

// Encrypt text using Caesar Cipher
std::string caesarCipher(const std::string& text, int shift) {
    std::string result = "";

    // Loop through each character
    for (char c : text) {
        if (isalpha(c)) {
            // Check if the character is uppercase or lowercase
            char base = isupper(c) ? 'A' : 'a';
            // Shift the character and wrap around the alphabet
            result += (c - base + shift) % 26 + base;
        }
        else {
            // Leave non-alphabetic characters unchanged
            result += c;
        }
    }

    return result;
}

int main() {
    std::string text;
    int shift;

    // Input text and shift value
    std::cout << "Enter text: ";
    std::getline(std::cin, text);
    std::cout << "Enter shift value: ";
    std::cin >> shift;

    // Encrypt and display the result
    std::string encrypted = caesarCipher(text, shift);
    std::cout << "Encrypted text: " << encrypted << std::endl;

    // Decrypt and display the result (shift backwards)
    std::string decrypted = caesarCipher(encrypted, -shift);
    std::cout << "Decrypted text: " << decrypted << std::endl;

    return 0;
}
