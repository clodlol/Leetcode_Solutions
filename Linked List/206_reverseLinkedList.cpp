/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void reverse(ListNode *head, ListNode *prehead, ListNode **newHead)
    {
        if (!head)
        {
            *newHead = prehead;
            return;
        }

        reverse(head->next, head, newHead);
        head->next = prehead;
    }

    ListNode *reverseList(ListNode *head)
    {
        ListNode *newHead = nullptr;
        reverse(head, nullptr, &newHead);

        return newHead;
    }

    ListNode *reverseListIter(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        auto prev = head;
        auto ptr = head->next;
        prev->next = nullptr;
        while (ptr->next != nullptr)
        {
            auto temp = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = temp;
        }
        ptr->next = prev;
        head = ptr;

        return head;
    }
};