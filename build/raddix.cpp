#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <memory>
#include <string>

using namespace std;

// Radix Tree Node
class RadixTreeNode {
public:
    unordered_map<string, shared_ptr<RadixTreeNode>> children;
    bool isEndOfWord;
    int frequency;

    RadixTreeNode() : isEndOfWord(false), frequency(0) {}
};

// Radix Tree
class RadixTree {
private:
    shared_ptr<RadixTreeNode> root;

public:
    RadixTree() : root(make_shared<RadixTreeNode>()) {}

    shared_ptr<RadixTreeNode> getRoot() const {
        return root;
    }

    // Insert a word with its frequency into the Radix Tree
    void insert(const string &word, int frequency) {
        shared_ptr<RadixTreeNode> node = root;
        size_t index = 0;
    
     //   cout << "\nInserting: " << word << " (Frequency: " << frequency << ")\n";
    
        while (index < word.length()) {
            string remaining = word.substr(index);
            bool found = false;
    
            for (auto it = node->children.begin(); it != node->children.end(); ++it) {
                string childKey = it->first;
                size_t commonPrefixLength = getCommonPrefixLength(childKey, remaining);
    
                if (commonPrefixLength > 0) {
            //        cout << "Common prefix found: " << childKey << " with " << remaining << endl;
    
                    if (commonPrefixLength < childKey.length()) {
             //           cout << "Splitting node: " << childKey << " at " << commonPrefixLength << endl;
    
                        shared_ptr<RadixTreeNode> newChild = make_shared<RadixTreeNode>();
                        newChild->children[childKey.substr(commonPrefixLength)] = it->second;
                        it->second = newChild;
                        node->children.erase(it);
                        node->children[childKey.substr(0, commonPrefixLength)] = newChild;
                    }
    
                    node = it->second;
                    index += commonPrefixLength;
                    found = true;
                    break;
                }
            }
    
            if (!found) {
        //        cout << "Creating new node for: " << remaining << endl;
                node->children[remaining] = make_shared<RadixTreeNode>();
                node = node->children[remaining];
                break;
            }
        }
    
        node->isEndOfWord = true;
        node->frequency = frequency;
      //  cout << "Inserted successfully: " << word << " with frequency " << frequency << endl;
    
        // Print tree after inserting
      //  cout << "Current Radix Tree Structure:\n";
      //  printTree(root, 0, 3);
      //  cout << "-----------------------------\n";
    }
    
    

    // Search for a word and return its frequency
    int search(const string &word) {
        shared_ptr<RadixTreeNode> node = root;
        size_t index = 0;
    
      //  cout << "Searching for: " << word << endl;  // Debugging
    
        while (index < word.length()) {
            string remaining = word.substr(index);
            bool found = false;
    
            for (auto &child : node->children) {
                string childKey = child.first;
                size_t commonPrefixLength = getCommonPrefixLength(childKey, remaining);
    
        //        cout << "Checking child: " << childKey << endl;
    
                if (commonPrefixLength > 0) {
     //               cout << "Matched prefix: " << childKey << endl;
                    node = child.second;
                    index += commonPrefixLength;
                    found = true;
                    break;
                }
            }
    
            if (!found) {
                cout << "Word not found!" << endl;
                return -1;
            }
        }
    
        if (node->isEndOfWord) {
            cout << "Word found with frequency: " << node->frequency << endl;
            return node->frequency;
        } else {
            cout << "Word found but is not an end-of-word!" << endl;
            return -1;
        }
    }
    
    

    // Print the tree structure
    void printTree(shared_ptr<RadixTreeNode> node, int depth, int maxDepth) {
        if (depth > maxDepth) return;
    
        for (auto &child : node->children) {
            cout << string(depth * 2, '-') << " " << child.first;
            if (child.second->isEndOfWord) {
                cout << " [END] (Frequency: " << child.second->frequency << ")";
            }
            cout << endl;
            printTree(child.second, depth + 1, maxDepth);
        }
    }
    

private:
    size_t getCommonPrefixLength(const string &str1, const string &str2) {
        size_t length = 0;
        while (length < str1.length() && length < str2.length() && str1[length] == str2[length]) {
            length++;
        }
        return length;
    }
};

// Function to load CSV file and insert into the Radix Tree
void loadCsvIntoRadixTree(const string &csvFilePath, RadixTree &tree) {
    ifstream file(csvFilePath);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << csvFilePath << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string word;
        int frequency;

        getline(ss, word, ',');
        ss >> frequency;

        if (!word.empty()) {
            cout << "Reading from CSV: " << word << " -> " << frequency << endl;
            tree.insert(word, frequency);
        }
    }
}


int main() {
    string csvFilePath = "data/unigram_freq.csv";  // Path to your CSV file containing words and frequencies
    RadixTree tree;

    // Load the CSV data into the Radix Tree
    loadCsvIntoRadixTree(csvFilePath, tree);

    // Print the tree structure up to a certain depth
    int maxDepth = 3;
    cout << "Radix Tree structure (up to depth " << maxDepth << "):\n";
    tree.printTree(tree.getRoot(), 0, maxDepth);

    // Search for words in the Radix Tree
    string wordToSearch;
    cout << "Enter a word to search: ";
    cin >> wordToSearch;

    int frequency = tree.search(wordToSearch);
    if (frequency != -1) {
        cout << "The word '" << wordToSearch << "' has a frequency of " << frequency << " in the radix tree." << endl;
    } else {
        cout << "The word '" << wordToSearch << "' was not found in the radix tree." << endl;
    }

    return 0;
}

