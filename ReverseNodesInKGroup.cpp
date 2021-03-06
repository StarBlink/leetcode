#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:

    ListNode* reverseList(ListNode* head)
    {
        ListNode *newList = new ListNode(0);
        while(head)
        {
            ListNode *tmp;
            tmp = newList->next;
            newList->next = head;
            head = head->next;
            newList->next->next = tmp;
        }
        return newList->next;
    }

    ListNode* findEnd(ListNode* head)
    {
        while(head->next)
        {
            head = head->next;
        }
        return head;
    }
    

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *start = head;
        ListNode *end = start;
        ListNode *prev = start;
        if(k == 1)
            return head;
        while(end)
        {
            for(int i = 0;i < k;++i)
            {
                if(!end->next && i < k - 1)
                {
                    return head;
                }
                if(i == k - 1)
                {
                    ListNode *tmp;
                    tmp = end;
                    end = end->next;
                    tmp->next = NULL;
                }
                else
                {
                    end = end->next;
                }
            }

            ListNode *result = reverseList(start);
            if(prev == head)
            {
                head = result;
            }
            else
            {
                prev->next = result;
            }
            ListNode *e = findEnd(result);
            e->next = end;
            prev = e;
            start = end;

        }
        return head;
    }
};

int main()
{
    ListNode *node = new ListNode(1);
    ListNode *head = node;
    node->next = new ListNode(2);
    node = node->next;
    node->next = new ListNode(3);
    node = node->next;
    node->next = new ListNode(4);
    node = node->next;
    node->next = new ListNode(5);
    node = node->next;
    Solution solution;
    solution.reverseKGroup(head,2);
}
