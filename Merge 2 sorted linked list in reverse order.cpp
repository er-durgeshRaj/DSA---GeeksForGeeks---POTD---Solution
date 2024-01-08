// QUESTION
// Given two linked lists of size N and M, which are sorted in non-decreasing order. The task is to merge them in such a way that the resulting list is in non-increasing order.

// Example 1:

// Input:
// N = 2, M = 2
// list1 = 1->3
// list2 = 2->4
// Output:
// 4->3->2->1
// Explanation:
// After merging the two lists in non-increasing order, we have new lists as 4->3->2->1.
// Example 2:

// Input:
// N = 4, M = 3
// list1 = 5->10->15->40 
// list2 = 2->3->20
// Output:
// 40->20->15->10->5->3->2
// Explanation:
// After merging the two lists in non-increasing order, we have new lists as 40->20->15->10->5->3->2.
// Your Task:
// The task is to complete the function mergeResult() which takes reference to the heads of both linked list and returns the pointer to the merged linked list.

// Expected Time Complexity : O(N+M)
// Expected Auxiliary Space : O(1)

// Constraints:
// 0 <= N, M <= 104
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOLUTION
class Solution
{
    public:
    
    Node * reverse(Node * node){
        Node * prev = nullptr;
        
        while(node){
            Node * next = node -> next;
            node -> next = prev;
            prev = node;
            node = next;
        }
        
        return prev;
    }
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        node1 = reverse(node1);
        node2 = reverse(node2);
        
        Node * newHead = nullptr;
        Node * curNode = nullptr;
        
        while(node1 and node2){
            if(node1 -> data > node2 -> data){
                if(!curNode){
                    curNode = new Node;
                    curNode -> data = node1 -> data;
                    newHead = curNode;
                }
                else{
                    Node * newNode = new Node;
                    newNode -> data = node1 -> data;
                    
                    curNode -> next = newNode;
                    curNode = newNode;
                }
                
                node1 = node1 -> next;
            }
            else{
                if(!curNode){
                    curNode = new Node;
                    curNode -> data = node2 -> data;
                    newHead = curNode;
                }
                else{
                    Node * newNode = new Node;
                    newNode -> data = node2 -> data;
                    curNode -> next = newNode;
                    curNode = newNode;
                }   
                
                node2 = node2 -> next;
            }
        }
        
        while(node1){
            if(!curNode){
                curNode = new Node;
                curNode -> data = node1 -> data;
                newHead = curNode;
            }
            else{
                Node * newNode = new Node;
                newNode -> data = node1 -> data;
                curNode -> next = newNode;
                curNode = newNode;
            }  
            
            node1 = node1 -> next;
        }
        
        while(node2){
            if(!curNode){
                curNode = new Node;
                curNode -> data = node2 -> data;
                newHead = curNode;
            }
            else{
                Node * newNode = new Node;
                newNode -> data = node2 -> data;
                curNode -> next = newNode;
                curNode = newNode;
            }  
            
            node2 = node2 -> next;
        }
        
        return newHead;
    }  
};
