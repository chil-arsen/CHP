#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// Node structure for the Huffman Tree
struct Node {
    char ch;  // Character
    int freq; // Frequency of the character
    Node* left, * right; // Left and right child nodes

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Comparison structure for priority queue
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq; // Min-heap: nodes with smaller frequency have higher priority
    }
};

// Function to traverse the Huffman Tree and generate binary codes
void generateCodes(Node* root, string code, unordered_map<char, string>& codes) {
    if (!root) return;

    // If leaf node, assign the accumulated binary code to the character
    if (!root->left && !root->right) {
        codes[root->ch] = code;
    }

    // Recurse left and right
    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

// Function to encode the input text using Huffman coding
string huffmanEncode(const string& text, unordered_map<char, string>& codes, Node*& root) {
    // Step 1: Calculate frequency of each character
    unordered_map<char, int> freq;
    for (char ch : text) freq[ch]++;

    // Step 2: Build a priority queue (min-heap) of Huffman Tree nodes
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto& pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Step 3: Build the Huffman Tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        // Combine the two smallest nodes into a new node
        Node* newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // The remaining node is the root of the Huffman Tree
    root = pq.top();

    // Step 4: Generate Huffman codes
    generateCodes(root, "", codes);

    // Step 5: Encode the text using the generated codes
    string encoded;
    for (char ch : text) {
        encoded += codes[ch];
    }
    return encoded;
}

// Function to decode an encoded string using the Huffman Tree
string huffmanDecode(Node* root, const string& encoded) {
    string decoded;
    Node* current = root;

    for (char bit : encoded) {
        // Traverse left for '0' and right for '1'
        if (bit == '0') current = current->left;
        else current = current->right;

        // If a leaf node is reached, add the character to the decoded string
        if (!current->left && !current->right) {
            decoded += current->ch;
            current = root; // Reset to root for the next character
        }
    }

    return decoded;
}

int main() {
    string text = "hello huffman";

    // Step 1: Encode the input text
    unordered_map<char, string> codes; // Store Huffman codes for each character
    Node* root = nullptr; // Root of the Huffman Tree
    string encoded = huffmanEncode(text, codes, root);

    // Display the Huffman codes
    cout << "Huffman Codes:\n";
    for (auto& pair : codes) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Display the encoded string
    cout << "\nEncoded String: " << encoded << endl;

    // Step 2: Decode the encoded string
    string decoded = huffmanDecode(root, encoded);
    cout << "\nDecoded String: " << decoded << endl;

    return 0;
}
