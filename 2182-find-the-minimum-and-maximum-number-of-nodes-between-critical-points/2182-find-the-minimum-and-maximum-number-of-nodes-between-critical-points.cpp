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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }
        ListNode* temp = head;
        int minDistance = INT_MAX;
        int maxDistance = INT_MIN;
        int count = 1;
        vector<int> v;
        vector<int> res;
        while (temp->next->next != NULL) {
            if ((temp->next->val < temp->val &&
                 temp->next->val < temp->next->next->val) ||
                (temp->next->val > temp->val &&
                 temp->next->val > temp->next->next->val)) {
                v.push_back(count);
            }
            count++;
            temp = temp->next;
        }

        if (v.size() < 2) {
            return {-1, -1};
        }
        for (size_t i = 1; i < v.size(); ++i) {
            minDistance = min(minDistance, v[i] - v[i - 1]);
        }

        maxDistance = v.back() - v.front();
        res.push_back(minDistance);
        res.push_back(maxDistance);
        return res;
    }
};