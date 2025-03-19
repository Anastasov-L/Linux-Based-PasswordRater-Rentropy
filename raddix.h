#ifndef RADDIX_H
#define RADDIX_H

#include <iostream>
#include <unordered_map>
#include <memory>
#include <string>
#include <vector>  

// Radix Tree Node
class RadixTreeNode {
public:
    std::unordered_map<std::string, std::shared_ptr<RadixTreeNode>> children;
    bool isEndOfWord;
    int frequency;

    RadixTreeNode();
};

// Radix Tree
class RadixTree {
private:
    std::shared_ptr<RadixTreeNode> root;

public:
    RadixTree();
    void insert(const std::string &word, int frequency);
    int search(const std::string &word);
    std::vector<std::tuple<std::string, int, int>> contains_known_words(const std::string &password, const std::vector<int>& index1, const std::vector<int>& index2);
    std::shared_ptr<RadixTreeNode> getRoot() const;
};

// Load CSV into the Radix Tree
void loadCsvIntoRadixTree(const std::string &csvFilePath, RadixTree &tree);

#endif
