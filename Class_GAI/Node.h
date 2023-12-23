#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>

using namespace std;

class Node
{
    friend class GaiDatabase;
private:
    string Nomer;
    vector<string> zalet;
    Node* left;
    Node* right;
public:
    Node(const string& nomer) : Nomer(nomer), left(nullptr), right(nullptr) {}
};
