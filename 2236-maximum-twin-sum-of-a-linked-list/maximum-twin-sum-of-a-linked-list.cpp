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
int TwoPointer( vector<int>&Arr ){
     int Left = 0 ;
     int Right = Arr.size() - 1;
     int TwinSum = 0 ;
     while( Left < Right ){
         int Sum = Arr[Left] + Arr[Right];
         TwinSum = max(TwinSum , Sum );
         Left++;
         Right--;
     }
     return TwinSum;
}
    int pairSum(ListNode* head) {
        vector<int>Arr;
        ListNode* Curr = head;
        while( Curr != nullptr ){
             Arr.push_back( Curr -> val );
             Curr = Curr -> next ;
        }
        return TwoPointer( Arr );
    }
};