#include "GaiDatabase.h"

Node* GaiDatabase::insertNode(Node* node, const string& nomer, const string& zalet)
{
    if (node == nullptr) {
        Node* newNode = new Node(nomer);
        newNode->zalet.push_back(zalet);
        return newNode;
    }
    if (nomer < node->Nomer) {
        node->left = insertNode(node->left, nomer, zalet);
    }
    else if (nomer > node->Nomer) {
        node->right = insertNode(node->right, nomer, zalet);
    }
    else {
        node->zalet.push_back(zalet);
    }
    return node;
}

void GaiDatabase::showInOrder(Node* node)
{
    if (node == nullptr) {
        return;
    }

    showInOrder(node->left);

    cout << "Номер автомашины: " << node->Nomer << endl;

    cout << "Правонарушения: ";
    for (const auto& zalet : node->zalet) {
        cout << zalet << " ";
    }
    cout << endl;

    showInOrder(node->right);
}

void GaiDatabase::showByNomer(Node* node, const string& nomer)
{
    if (node == nullptr) {
        cout << "Номер автомашины не найден" << endl;
        return;
    }
    if (nomer == node->Nomer) {
        cout << "Номер автомашины: " << node->Nomer << endl;
        cout << "Правонарушения: ";
        for (const auto& zalet : node->zalet) {
            cout << zalet << " ";
        }
        cout << endl;
    }
    else if (nomer < node->Nomer) {
        showByNomer(node->left, nomer);
    }
    else {
        showByNomer(node->right, nomer);
    }
}

void GaiDatabase::showInRange(Node* node, const string& start, const string& end)
{
    if (node == nullptr) {
        return;
    }
    if (start < node->Nomer) {
        showInRange(node->left, start, end);
    }
    if (start <= node->Nomer && node->Nomer <= end) {
        cout << "Номер автомашины: " << node->Nomer << endl;
        cout << "Правонарушения: ";
        for (const auto& zalet : node->zalet) {
            cout << zalet << " ";
        }
        cout << endl;
    }
    if (node->Nomer < end) {
        showInRange(node->right, start, end);
    }
}

void GaiDatabase::addZalet(const string& nomer, const string& zalet)
{
    root = insertNode(root, nomer, zalet);
}

void GaiDatabase::showDatabase()
{
    showInOrder(root);
}

void GaiDatabase::showByNomer(const string& nomer)
{
    showByNomer(root, nomer);
}

void GaiDatabase::showByRange(const string& start, const string& end)
{
    showInRange(root, start, end);
}

void GaiDatabase::clear(Node* node)
{
    if (node != nullptr) 
    {
     clear(node->left);
     clear(node->right);
     delete node;
    }
}

GaiDatabase::~GaiDatabase()
{
    clear(root);
}
