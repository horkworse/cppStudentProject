#include "LinkedList.h"
//#include <iostream>

using namespace std;

linkedList::linkedList()
{
    this->_head = nullptr;
    this->_tail = nullptr;
    this->_count = 0;
};

linkedList::~linkedList()
{
    clear();
}

void linkedList::add(int value)
{
    ListNode* temp = new ListNode;
    temp->value = value;
    temp->next = nullptr;

    if (_head == nullptr)
    {
        _head = temp;
        _head->next = nullptr;
    }
    else
        _tail->next = temp;
    _tail = temp;
    this->_count++;
}

bool linkedList::contains(int value)
{
    ListNode* current = _head;
    ListNode* previous = new ListNode;

    while (current->next != nullptr)
    {
        previous = current;
        current = current->next;

        if (current->value == value)
            return true;
    }
    return false;
}

int linkedList::count()
{
    return this->_count;
}

void linkedList::removeDuplicates()
{
    if (_head == nullptr)
        return;

    ListNode* current = _head;

    while (current != nullptr)
    {
        ListNode* runner = current;
        while (runner->next != nullptr)
        {
            if (runner->next->value == current->value)
            {
                ListNode* temp = runner->next->next;
                delete runner->next;
                runner->next = nullptr;
                _count--;
                if (temp != nullptr)
                    runner->next = temp;
            }
            else
                runner = runner->next;
        }
        current = current->next;
    }
}

int linkedList::findFromBack(int index)
{
    if (index > _count)
        return -1;

    int counter = 0;
    int itemIndex = this->_count - index;

    ListNode* temp = _head;
    while (counter != itemIndex)
    {
        temp = temp->next;
        counter++;
    }
    return temp->value;
}

bool linkedList::remove(int value)
{
    ListNode* current = _head;
    ListNode* previous = new ListNode;

    while (current->next != nullptr)
    {
        previous = current;
        current = current->next;

        if (current->value == value)
        {
            previous->next = current->next;
            delete current;
            _count--;
            return true;
        }
    }
    return false;
}

void linkedList::clear()
{
    if (_head == nullptr)
        return;

    ListNode* tmp;
    while (_head != nullptr)
    {
        tmp = _head->next;
        delete _head;
        _head = tmp;
        _count = 0;
    }
}