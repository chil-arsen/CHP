#include <iostream>
#include <vector>
#include <string>

struct Token {
    int offset;   // How far back the match starts
    int length;   // Length of the match
    char next;    // Next character after the match
};

std::vector<Token> compressLZ77(const std::string& data, int windowSize) {
    std::vector<Token> tokens;
    int dataSize = data.size();

    for (int i = 0; i < dataSize; ) {
        int matchLength = 0;
        int matchOffset = 0;

        // Search for the longest match in the sliding window
        int start = std::max(0, i - windowSize);
        for (int j = start; j < i; ++j) {
            int k = 0;
            while (i + k < dataSize && data[j + k] == data[i + k]) {
                ++k;
                if (j + k >= i) break;
            }

            if (k > matchLength) {
                matchLength = k;
                matchOffset = i - j;
            }
        }

        // Add the token
        char nextChar = (i + matchLength < dataSize) ? data[i + matchLength] : '\0';
        tokens.push_back({ matchOffset, matchLength, nextChar });

        // Move forward in the input
        i += matchLength + 1;
    }

    return tokens;
}

// Helper to display the compressed data
void printTokens(const std::vector<Token>& tokens) {
    for (const auto& token : tokens) {
        std::cout << "(" << token.offset << ", " << token.length << ", '" << token.next << "') ";
    }
    std::cout << std::endl;
}

int main() {
    std::string data = "aabcaabcda";
    int windowSize = 6;

    std::vector<Token> compressedData = compressLZ77(data, windowSize);

    std::cout << "Compressed Data: ";
    printTokens(compressedData);

    return 0;
}
