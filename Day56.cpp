// 25. Reverse Nodes in k-Group
// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

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
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {

        int size = 0;
        ListNode *temp = head;

        while (temp != NULL)
        {
            temp = temp->next;
            size++;
        }
        if (size < k)
        {
            return head;
        }

        // base case
        if (head == NULL)
        {
            return NULL;
        }

        // reversing first k node
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *next = NULL;
        int count = 0;

        while (curr != NULL && count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // step-2
        if (next != NULL)
        {
            head->next = reverseKGroup(next, k);
        }

        // step-2
        return prev;
    }
};