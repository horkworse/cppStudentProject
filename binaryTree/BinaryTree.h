#pragma once
#ifndef ADD_H
#define ADD_H

class TreeNode
{
public:
    TreeNode();
    TreeNode(int value, TreeNode left, TreeNode right, TreeNode parent);
    void setValue(int value);
    void setLeftNode(TreeNode* left);
    void setRightNode(TreeNode* right);
    int getValue();
    TreeNode* getLeftNode();
    TreeNode* getRightNode();
private:
    int value;
    TreeNode* left;
    TreeNode* right;
};

class BinaryTree
{
public:
    BinaryTree();
    BinaryTree(TreeNode* node);
    ~BinaryTree();
    void insert(int value);
    void clear();
    TreeNode* search(int value);
    void CreateMinimalBST(int* array, int start, int end);

private:
    void insert(int value, TreeNode* node);
    void clear(TreeNode* node);
    TreeNode* search(TreeNode* leaf, int key);
    TreeNode* root;
};

#endif