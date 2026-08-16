/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        map<ListNode*, bool> visited;
        ListNode* temp = head;
        while (temp != NULL) {
            // cycle is present
            if (visited[temp] == true) {
                return temp;
            }
            // cycle is absent
            visited[temp] = true;
            temp = temp->next;
        }
        return temp;
    }
};