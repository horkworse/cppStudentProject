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
                ListNode()
                {
                    this->value = 0;
                    this->next = nullptr;
                };

                ListNode(int value, ListNode* next)
                {
                    this->value = value;
                    this->next = next;
                };

                int value;
                ListNode* next;
        };
        ListNode* _head;
        ListNode* _tail;
        int _count;
};
