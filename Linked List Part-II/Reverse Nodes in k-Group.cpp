#include <bits/stdc++.h>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    if(head==NULL || k==1) return head;
     ListNode* dummy=new ListNode(0,head);
     ListNode *cur=dummy,*pre=dummy,*nex=dummy;
     int cnt=0;
     while(cur->next!=NULL){
         cur=cur->next;
         cnt++;
     }
     while(cnt>=k){
         cur=pre->next;
         nex=cur->next;
         for(int i=1;i<k;i++){
             cur->next=nex->next;
             nex->next=pre->next;
             pre->next=nex;
             nex=cur->next;
         }
         pre=cur;
         cnt-=k;
     }
    return dummy->next;
    }
};