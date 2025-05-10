#include<bits/stdc++.h>
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
int SIZE(ListNode* head){
        ListNode* cur=head;
        int cnt=0;
        while(cur!=NULL){
            cur=cur->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode * ans=new ListNode(-1);
        ans->next=head;
        int n=SIZE(head);
        k=k%n;
        cout<<k<<"\n";
        ListNode * cur=ans;

        for(int i=1;i<=n-k;i++){
            cur=cur->next;
        }

        ListNode * prev=cur;

        cur=cur->next;
        ans->next=cur;
        while(cur->next!=NULL){
            cur=cur->next;
        }
        cur->next=prev;
        prev->next=NULL;
        return ans->next;

    }
};

int main(){

    int n,k;cin>>n>>k;

    ListNode* ar=new ListNode(-400);
    ListNode* head=ar;
    while(n--){
        int x;cin>>x;
        ar->next=new ListNode(x);
        ar=ar->next;
    }
    Solution a;

    ListNode* ans=a.rotateRight(head->next,k);
    while(ans!=NULL){
        cout<<ans->val<<" ";
        ans=ans->next;
    }

}
