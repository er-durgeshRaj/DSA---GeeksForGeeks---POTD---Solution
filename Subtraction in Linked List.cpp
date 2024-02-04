// QUESTION
// You are given two linked lists that represent two large positive numbers. From the two numbers represented by the linked lists, subtract the smaller number from the larger one. Look at the examples to get a better understanding of the task.

// Example 1:

// Input:
// L1 = 1->0->0
// L2 = 1->2
// Output: 88
// Explanation:  
// First linked list represents 100 and the
// second one represents 12. 12 subtracted from 100
// gives us 88 as the result. It is represented
// as 8->8 in the linked list.
// Example 2:

// Input:
// L1 = 0->0->6->3
// L2 = 7->1->0
// Output: 647
// Explanation: 
// First linked list represents 0063 => 63 and 
// the second one represents 710. 63 subtracted 
// from 710 gives us 647 as the result. It is
// represented as 6->4->7 in the linked list.
// Your Task:
// You do not have to take any input or print anything. The task is to complete the function subLinkedList() that takes heads of two linked lists as input parameters and which should subtract the smaller number from the larger one represented by the given linked lists and return the head of the linked list representing the result.

// n and m are the length of the two linked lists respectively.
// Expected Time Complexity:  O(n+m)
// Expected Auxiliary Space: O(n+m)

// Constraints:
// 1 <= n <= 10000
// 0 <= values represented by the linked lists < 10n
// 0 <= values represented by the linked lists < 10m
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOLUTION
class Solution {
public:
 int len(Node *head){
        int temp=0;
        while(head){
            temp++;
            head=head->next;
        }
        return temp;
    }
    int help(Node *head1,Node *head2){
        if(!head1 and !head2)return 0;
        if(head1->data>head2->data)return 1;
        if(head2->data>head1->data)return 2;
        return help(head1->next,head2->next);
    }
    Node* rev(Node *head){
        Node *curr=head,*prev=NULL,*nxt=NULL;
        while(curr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        Node *ans=new Node(0);
        while(head1 and head1->data==0)head1=head1->next;
        while(head2 and head2->data==0)head2=head2->next;
        if(!head1 and !head2)return ans;
        if(!head1)return head2;
        if(!head2)return head1;
        Node *greater=head1,*less=head2;
        if(len(head2)>len(head1)){
            greater=head2;
            less=head1;
        }
        else if(len(head1)==len(head2)){
            if(help(head1,head2)==2){
                greater=head2;
                less=head1;
            }
            else if(help(head1,head2)==0){
                return ans;
            }
        }
        greater=rev(greater);
        less=rev(less);
        Node *temp=ans;
        while(less){
            if(greater->data>=less->data){
                temp->next=new Node(greater->data-less->data);
            }
            else{
                temp->next = new Node(greater->data+10-less->data);
                Node *nxt = greater->next;
                while(nxt->data==0){
                    nxt->data=9;
                    nxt=nxt->next;
                }
                nxt->data=nxt->data-1;
            }
            greater=greater->next;
            less=less->next;
            temp=temp->next;
        }
        while(greater){
            temp->next=new Node(greater->data);
            temp=temp->next;
            greater=greater->next;
        }
        ans = rev(ans->next);
        while(ans and ans->data==0)ans=ans->next;
        return ans;
    }
};
