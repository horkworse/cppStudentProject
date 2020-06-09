#include "BinaryTree.h"

TreeNode::TreeNode()
{
    left = right = nullptr;
    value = int();
}

TreeNode::TreeNode(int value, TreeNode left, TreeNode right, TreeNode parent)
{
    this->value = value;
    this->left->setLeftNode(&left);
    this->right->setRightNode(&right);
}

void TreeNode::setValue(int value)
{
    this->value = value;
}

void TreeNode::setLeftNode(TreeNode* left)
{
    this->left = left;
}

void TreeNode::setRightNode(TreeNode* right)
{
    this->right = right;
}

int TreeNode::getValue()
{
    return this->value;
}

TreeNode* TreeNode::getLeftNode()
{
    return this->left;
}

TreeNode* TreeNode::getRightNode()
{
    return this->right;
}

BinaryTree::BinaryTree()
{
    root = nullptr;
}

BinaryTree::BinaryTree(TreeNode* node)
{
    root = node;
}

BinaryTree::~BinaryTree()
{
    clear();
}

void BinaryTree::insert(int value)
{
    if (root == nullptr)
    {
        TreeNode* temp = new TreeNode;
        temp->setValue(value);
        root = temp;
    }
    else
        insert(value, root);
}

void BinaryTree::clear()
{
    if (root != nullptr)
    {
        clear(root);
    }
}

TreeNode* BinaryTree::search(int value)
{
    if (root == nullptr)
        return nullptr;

    if (root->getValue() == value)
        return root;
    else if (root->getValue() < value)
        return search(root->getRightNode(), value);
    else
        return search(root->getLeftNode(), value);
}


void BinaryTree::CreateMinimalBST(int* array, int start, int end)
{
    int index = (end + start) / 2;
    insert(array[index]);

    if (index < end)
        CreateMinimalBST(array, index + 1, end);
    if (index > start)
        CreateMinimalBST(array, start, index - 1);
}

void BinaryTree::insert(int value, TreeNode* node)
{
    if (node->getValue() > value)
    {
        if (node->getLeftNode() == nullptr)
        {
            TreeNode* temp = new TreeNode;
            temp->setValue(value);
            temp->setLeftNode(nullptr);
            temp->setRightNode(nullptr);
            node->setLeftNode(temp);
        }
        else
            insert(value, node->getLeftNode());
    }
    else
    {
        if (node->getRightNode() == nullptr)
        {
            TreeNode* temp = new TreeNode;
            temp->setValue(value);
            temp->setLeftNode(nullptr);
            temp->setRightNode(nullptr);
            node->setRightNode(temp);
        }
        else
            insert(value, node->getRightNode());
    }
}

void BinaryTree::clear(TreeNode* node)
{
    if (node != nullptr)
    {
        clear(node->getRightNode());
        clear(node->getLeftNode());
        delete node;
    }
}

TreeNode* BinaryTree::search(TreeNode* leaf, int key) {
    if (leaf != nullptr) {
        if (key == leaf->getValue()) {
            return leaf;
        }
        if (key < leaf->getValue()) {
            return search(leaf->getLeftNode(), key);
        }
        else {
            return search(leaf->getRightNode(), key);
        }
    }
    else {
        return nullptr;
    }
}