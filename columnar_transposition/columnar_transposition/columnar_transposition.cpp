#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class ColumnarTranspositionCipher {
public:
    static std::string padMessage(const std::string& message, int columns) {
        std::string paddedMessage = message;
        int paddingLength = columns - (message.length() % columns);
        if (paddingLength != columns) {
            paddedMessage += std::string(paddingLength, 'X'); // Pad with 'X'
        }
        return paddedMessage;
    }

    static std::string encrypt(const std::string& message, int columns) {
        std::string paddedMessage = padMessage(message, columns);
        int rows = paddedMessage.length() / columns;

        // Debug: Print the padded message
        std::cout << "Padded message: " << paddedMessage << std::endl;

        // Create the grid
        std::vector<std::string> grid(rows);
        for (int i = 0; i < rows; ++i) {
            grid[i] = paddedMessage.substr(i * columns, columns);
        }

        // Debug: Print the grid
        std::cout << "Grid:" << std::endl;
        for (const auto& row : grid) {
            std::cout << row << std::endl;
        }

        // Read column by column
        std::string ciphertext;
        for (int col = 0; col < columns; ++col) {
            for (int row = 0; row < rows; ++row) {
                ciphertext += grid[row][col];
            }
        }

        return ciphertext;
    }
};

int main() {
    std::string message;
    int columns;

    std::cout << "Enter the message to encrypt: ";
    std::getline(std::cin, message);

    std::cout << "Enter the number of columns: ";
    std::cin >> columns;

    std::string encryptedMessage = ColumnarTranspositionCipher::encrypt(message, columns);

    std::cout << "Encrypted message: " << encryptedMessage << std::endl;

    return 0;
}
