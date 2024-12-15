#include <iostream>
#include <string>
#include <stdexcept>

// Function to encrypt the message
std::string encrypt(const std::string& plaintext, const std::string& key) {
    if (plaintext.length() != key.length()) {
        throw std::invalid_argument("Key must be the same length as the message.");
    }

    std::string ciphertext;
    for (size_t i = 0; i < plaintext.length(); ++i) {
        // Encrypt only alphabetic characters
        if (isalpha(plaintext[i]) && isalpha(key[i])) {
            char p = toupper(plaintext[i]) - 'A';  // Convert to number (0-25)
            char k = toupper(key[i]) - 'A';       // Convert to number (0-25)
            char c = (p + k) % 26 + 'A';          // Encrypt and convert back to character
            ciphertext += c;
        }
        else {
            // If not alphabetic, just add it to the ciphertext as is
            ciphertext += plaintext[i];
        }
    }
    return ciphertext;
}

// Function to decrypt the message
std::string decrypt(const std::string& ciphertext, const std::string& key) {
    if (ciphertext.length() != key.length()) {
        throw std::invalid_argument("Key must be the same length as the ciphertext.");
    }

    std::string plaintext;
    for (size_t i = 0; i < ciphertext.length(); ++i) {
        // Decrypt only alphabetic characters
        if (isalpha(ciphertext[i]) && isalpha(key[i])) {
            char c = toupper(ciphertext[i]) - 'A';  // Convert to number (0-25)
            char k = toupper(key[i]) - 'A';         // Convert to number (0-25)
            char p = (c - k + 26) % 26 + 'A';      // Decrypt and convert back to character
            plaintext += p;
        }
        else {
            // If not alphabetic, just add it to the plaintext as is
            plaintext += ciphertext[i];
        }
    }
    return plaintext;
}

int main() {
    std::string message, key;

    // Get input from user
    std::cout << "Enter message to encrypt: ";
    std::getline(std::cin, message);
    std::cout << "Enter key (must be the same length as message): ";
    std::getline(std::cin, key);

    try {
        // Encrypt and display the ciphertext
        std::string encrypted = encrypt(message, key);
        std::cout << "Encrypted Message: " << encrypted << std::endl;

        // Decrypt and display the original message
        std::string decrypted = decrypt(encrypted, key);
        std::cout << "Decrypted Message: " << decrypted << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
