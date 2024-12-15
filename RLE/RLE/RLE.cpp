= #include <iostream>
#include <string>
#include <cctype>

// Function to perform Run-Length Encoding
std::string rleEncode(const std::string& input) {
    std::string encoded = "";
    int n = input.length();
    for (int i = 0; i < n; ++i) {
        int count = 1;
        while (i < n - 1 && input[i] == input[i + 1]) {
            ++count;
            ++i;
        }
        encoded += input[i] + std::to_string(count);
    }
    return encoded;
}

// Function to decode Run-Length Encoded string
std::string rleDecode(const std::string& encoded) {
    std::string decoded = "";
    int n = encoded.length();
    for (int i = 0; i < n; ++i) {
        char currentChar = encoded[i];
        ++i;
        std::string countStr = "";
        while (i < n && std::isdigit(encoded[i])) {
            countStr += encoded[i];
            ++i;
        }
        --i;
        int count = std::stoi(countStr);
        decoded += std::string(count, currentChar);
    }
    return decoded;
}

int main() {
    std::string input;

    std::cout << "Enter a string to encode: ";
    std::getline(std::cin, input);

    // Perform RLE encoding
    std::string encoded = rleEncode(input);
    std::cout << "Encoded string: " << encoded << std::endl;

    // Perform RLE decoding
    std::string decoded = rleDecode(encoded);
    std::cout << "Decoded string: " << decoded << std::endl;

    return 0;
}
