#pragma once
#ifndef ADD_H
#define ADD_H

template<typename T>
class TreeNode
{
public:
    TreeNode<T>()
    {
        left = right = nullptr;
        value = T();
    }

    TreeNode<T>(T value, TreeNode<T> left, TreeNode<T> right, TreeNode<T> parent)
    {
        this->value = value;
        this->left = left;
        this->right = right;
    }

    void setValue(T value)
    {
        this->value = value;
    }

    void setLeftNode(TreeNode<T>* left)
    {
        this->left = left;
    }

    void setRightNode(TreeNode<T>* right)
    {
        this->right = right;
    }

    T getValue()
    {
        return this->value;
    }

    TreeNode<T>* getLeftNode()
    {
        return this->left;
    }

    TreeNode<T>* getRightNode()
    {
        return this->right;
    }

private:
    T value;
    TreeNode* left;
    TreeNode* right;
};

template<typename T>
class BinaryTree
{
public:
    BinaryTree()
    {
        root = nullptr;
    }

    BinaryTree(TreeNode<T> node)
    {
        root = node;
    }

    ~BinaryTree()
    {
        clear();
    }

    void insert(T value)
    {
        if (root == nullptr)
        {
            TreeNode<T>* temp = new TreeNode<T>;
            temp->setValue(value);
            root = temp;
        }
        else
            insert(value, root);
    }

    void clear()
    {
        if (root != nullptr)
        {
            clear(root);
        }
    }

    TreeNode<T>* search(T value)
    {
        if (root == nullptr)
            return nullptr;

        if (root->getValue() == value)
            return root;
        else if (root->getValue() < value)
            return search(root->right, value);
        else
            return search(root->left, value);
    }

    
    void CreateMinimalBST(T* array, int start, int end)
    {
        int index = (end + start) / 2;
        insert(array[index]);

        if (index < end)
            CreateMinimalBST(array, index + 1, end);
        if (index > start)
            CreateMinimalBST(array, start, index - 1);
    }

private:
    void insert(T value, TreeNode<T>* node)
    {
        if (node->getValue() > value)
        {
            if (node->getLeftNode() == nullptr)
            {
                TreeNode<T>* temp = new TreeNode<T>;
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
                TreeNode<T>* temp = new TreeNode<T>;
                temp->setValue(value);
                temp->setLeftNode(nullptr);
                temp->setRightNode(nullptr);
                node->setRightNode(temp);
            }
            else
                insert(value, node->getRightNode());
        }
    }

    void clear(TreeNode<T> node)
    {
        if (node != nullptr)
        {
            clear(node->right);
            clear(node->left);
            delete node;
        }
    }

    TreeNode<T>* root;
};

#endif