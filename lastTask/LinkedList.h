#pragma once
class linkedList
{
    public:
        linkedList();
        ~linkedList();
        void add(int value);
        bool contains(int value);
        int count();
        void removeDuplicates();
        int findFromBack(int index);
        bool remove(int value);
        void clear();
        void print();

    private:
        class ListNode
        {
            public:
                ListNode();

                ListNode(int value, ListNode* next);

                int value;
                ListNode* next;
        };
        ListNode* _head;
        ListNode* _tail;
        int _count;
};
