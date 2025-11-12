#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

struct HuffmanNode {
    char data;                  
    int frequency;              
    HuffmanNode *left, *right;  

    HuffmanNode(char data, int frequency) {
        left = right = nullptr;
        this->data = data;
        this->frequency = frequency;
    }
};

struct Compare {
    bool operator()(HuffmanNode* left, HuffmanNode* right) {
        return left->frequency > right->frequency;
    }
};

void printCodes(HuffmanNode* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;

    if (!root->left && !root->right) {
        huffmanCodes[root->data] = code;
        cout << root->data << ": " << code << endl;
    }

    printCodes(root->left, code + "0", huffmanCodes);
    printCodes(root->right, code + "1", huffmanCodes);
}

void buildHuffmanTree(const string& text) {
    unordered_map<char, int> frequencyMap;
    for (char ch : text) {
        frequencyMap[ch]++;
    }

    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;

    for (auto pair : frequencyMap) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        HuffmanNode* left = pq.top();
        pq.pop();
        HuffmanNode* right = pq.top();
        pq.pop();

        HuffmanNode* newNode = new HuffmanNode('\0', left->frequency + right->frequency);

        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    HuffmanNode* root = pq.top();

    unordered_map<char, string> huffmanCodes;
    printCodes(root, "", huffmanCodes);

    cout << "\nEncoded string: ";
    for (char ch : text) {
        cout << huffmanCodes[ch];
    }
    cout << endl;
}

int main() {
    string text;
    cout << "Enter text to encode using Huffman Encoding: ";
    getline(cin, text);

    buildHuffmanTree(text);

    return 0;
}