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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        
        int i = 1;
        ListNode* traverse;
        ListNode* first;
        ListNode* second;
        traverse = head;
        while(traverse!=nullptr)
        {
            if(i==k) first = traverse;
            i++;
            traverse = traverse->next;
        }
        k = i-k;
        i = 1;
        traverse = head;
        while(traverse!=nullptr)
        {
            if(i==k)
            {
                second = traverse;
                break;
            }
            i++;
            traverse = traverse->next;
        }
        int temp = second->val;
        second->val = first->val;
        first->val = temp;
        return head;
    }
};