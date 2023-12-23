#pragma once
#include "Node.h"


class GaiDatabase
{
private:
    Node* root;
    Node* insertNode(Node* node, const string& nomer, const string& zalet);
    void showInOrder(Node* node);
    void showByNomer(Node* node, const string& nomer);
    void showInRange(Node* node, const string& start, const string& end);

public:
    GaiDatabase() : root(nullptr) {}
    void addZalet(const string& nomer, const string& zalet);
    void showDatabase();
    void showByNomer(const string& nomer);
    void showByRange(const string& start, const string& end);
    void clear(Node* node);

    ~GaiDatabase();
};
