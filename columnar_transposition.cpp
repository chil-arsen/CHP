std::string ColumnarTranspositionCipher::encrypt(const std::string& message, int columns) {
    std::string paddedMessage = padMessage(message, columns);
    int rows = paddedMessage.length() / columns;
    std::vector<std::string> grid(rows);

    for (int i = 0; i < rows; ++i) {
        grid[i] = paddedMessage.substr(i * columns, columns);
    }

    std::string ciphertext;
    for (int col = 0; col < columns; ++col) {
        for (int row = 0; row < rows; ++row) {
            ciphertext += grid[row][col];
        }
    }

    return ciphertext;
}
