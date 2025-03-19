#include "raddix.h"
#include <fstream>
#include <sstream>

RadixTreeNode::RadixTreeNode() : isEndOfWord(false), frequency(0) {}


RadixTree::RadixTree() : root(std::make_shared<RadixTreeNode>()) {}

std::shared_ptr<RadixTreeNode> RadixTree::getRoot() const {
    return root;
}

size_t getCommonPrefixLength(const std::string &str1, const std::string &str2) {
       size_t length = 0;
       while (length < str1.length() && length < str2.length() && str1[length] == str2[length]) {
           length++;
       }
       return length;
   }
// Insert a word into the Radix Tree with its frequency
void RadixTree::insert(const std::string &word, int frequency) {
    std::shared_ptr<RadixTreeNode> node = root;
    size_t index = 0;
    while (index < word.length()) {
        std::string remaining = word.substr(index);
        bool found = false;

        for (auto it = node->children.begin(); it != node->children.end(); ++it) {
            std::string childKey = it->first;
            size_t commonPrefixLength = getCommonPrefixLength(childKey, remaining);

            if (commonPrefixLength > 0) {
                if (commonPrefixLength < childKey.length()) {
                    std::shared_ptr<RadixTreeNode> newChild = std::make_shared<RadixTreeNode>();
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
            node->children[remaining] = std::make_shared<RadixTreeNode>();
            node = node->children[remaining];
            break;
        }
    }

    node->isEndOfWord = true;
    node->frequency = frequency;
}

// Search for a word and return its frequency
int RadixTree::search(const std::string &word) {
    std::shared_ptr<RadixTreeNode> node = root;
    size_t index = 0;

    while (index < word.length()) {
        std::string remaining = word.substr(index);
        bool found = false;

        for (auto &child : node->children) {
            std::string childKey = child.first;
            size_t commonPrefixLength = getCommonPrefixLength(childKey, remaining);

            if (commonPrefixLength == childKey.length()) {
                node = child.second;
                index += commonPrefixLength;
                found = true;
                break;
            }
        }

        if (!found) {
            return -1;
        }
    }

    return node->isEndOfWord ? node->frequency : -1;
}


std::vector<std::tuple<std::string, int, int>> RadixTree::contains_known_words(
    const std::string &password, 
    const std::vector<int>& index1, 
    const std::vector<int>& index2
) {
    std::vector<std::tuple<std::string, int, int>> foundWords;
    int index = 0;

    while (index < password.length()) {
        // Check if 'index' is inside an ignored range
        bool inIgnoredRange = false;
        for (size_t i = 0; i < index1.size(); ++i) {
            if (index >= index1[i] && index <= index2[i]) {
                // Move index to the first position *after* the ignored range
                index = index2[i] + 1;
                inIgnoredRange = true;
                break;
            }
        }
        if (inIgnoredRange) continue; // Skip searching in ignored ranges

        std::shared_ptr<RadixTreeNode> node = root;
        std::string matchedWord;
        int matchedFrequency = -1;
        int matchedLength = 0;
        int startIndex = index;

        for (int j = index; j < password.length(); ++j) {
            // Stop checking if the next index falls into an ignored range
            bool insideIgnored = false;
            for (size_t i = 0; i < index1.size(); ++i) {
                if (j >= index1[i] && j <= index2[i]) {
                    insideIgnored = true;
                    break;
                }
            }
            if (insideIgnored) break; // Stop checking further substrings

            std::string subword = password.substr(index, j - index + 1);
            std::shared_ptr<RadixTreeNode> currentNode = root;
            size_t subIndex = 0;
            bool exactMatch = false;

            // Follow the Radix Tree path
            while (subIndex < subword.length()) {
                bool found = false;
                for (auto& child : currentNode->children) {
                    std::string childKey = child.first;
                    size_t prefixLength = getCommonPrefixLength(childKey, subword.substr(subIndex));

                    if (prefixLength == childKey.length()) { // Move to the next node
                        currentNode = child.second;
                        subIndex += prefixLength;
                        found = true;
                        break;
                    }
                }
                if (!found) break;
            }

            // Only consider exact matches where isEndOfWord is true
            if (subIndex == subword.length() && currentNode->isEndOfWord) {
                matchedWord = subword;
                matchedFrequency = currentNode->frequency;
                matchedLength = j - index + 1;
                exactMatch = true;
            }
        }

        if (!matchedWord.empty()) {
            foundWords.emplace_back(matchedWord, matchedFrequency, startIndex);
            index += matchedLength; // Move past the matched word
        } else {
            index++; // No word found, move to the next character
        }
    }

    return foundWords;
}





// Load CSV file into the Radix Tree
void loadCsvIntoRadixTree(const std::string &csvFilePath, RadixTree &tree) {
    std::ifstream file(csvFilePath);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << csvFilePath << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string word;
        int frequency;

        std::getline(ss, word, ',');
        ss >> frequency;

        if (!word.empty() && frequency > 0) {
            tree.insert(word, frequency);
        }
    }
}
