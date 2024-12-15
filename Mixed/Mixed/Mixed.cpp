#include <iostream>
#include <string>

// Include Caesar Cipher function
#include "caesar_cipher.cpp"

// Include RLE functions
#include "rle.cpp"

// Third function to combine Caesar Cipher and RLE
std::string processWithRLEAndCaesar(const std::string& text, int shift) {
    // Step 1: RLE Encode
    std::string rleEncoded = rleEncode(text);

    // Step 2: Caesar Cipher Encrypt
    std::string encrypted = caesarCipher(rleEncoded, shift);

    return encrypted;
}

std::string reverseProcessWithRLEAndCaesar(const std::string& encryptedText, int shift) {
    // Step 1: Caesar Cipher Decrypt
    std::string decrypted = caesarCipher(encryptedText, -shift);

    // Step 2: RLE Decode
    std::string rleDecoded = rleDecode(decrypted);

    return rleDecoded;
}

int main() {
    std::string message;
    int shift;

    // Input original message and shift value
    std::cout << "Enter text: ";
    std::getline(std::cin, message);
    std::cout << "Enter shift value: ";
    std::cin >> shift;

    // Process the message with RLE + Caesar
    std::string processed = processWithRLEAndCaesar(message, shift);
    std::cout << "Processed (RLE + Caesar): " << processed << std::endl;

    // Reverse the process
    std::string original = reverseProcessWithRLEAndCaesar(processed, shift);
    std::cout << "Original text: " << original << std::endl;

    return 0;
}
