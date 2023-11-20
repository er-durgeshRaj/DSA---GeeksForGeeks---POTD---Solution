//QUESTION
// Given two linked lists sorted in increasing order, create a new linked list representing the intersection of the two linked lists. The new linked list should be made with without changing the original lists.

// Note: The elements of the linked list are not necessarily distinct.

// Example 1:

// Input:
// LinkedList1 = 1->2->3->4->6
// LinkedList2 = 2->4->6->8
// Output: 2 4 6
// Explanation: For the given two
// linked list, 2, 4 and 6 are the elements
// in the intersection.
// Example 2:

// Input:
// LinkedList1 = 10->20->40->50
// LinkedList2 = 15->40
// Output: 40
// Your Task:
// You don't have to take any input of print anything. Your task is to complete the function findIntersection(), which will take head of both of the linked lists as input and should find the intersection of two linked list and add all the elements in intersection to the third linked list and return the head of the third linked list.

// Expected Time Complexity : O(n+m)
// Expected Auxilliary Space : O(n+m)
// Note: n, m are the size of the respective linked lists.
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Solution
class Solution
{
    public:
    Node* findIntersection(Node* t1, Node* t2)
    {
       Node* result = nullptr;
        Node* curr = nullptr;

        std::unordered_map<int, int> set;
        while (t1 != nullptr) {
            set[t1->data] = set[t1->data] + 1;
            t1 = t1->next;
        }

        while (t2 != nullptr) {
            if (set.find(t2->data) != set.end() && set[t2->data] > 0) {
                set[t2->data] = set[t2->data] - 1;
                if (result == nullptr) {
                    result = new Node(t2->data);
                    curr = result;
                } else {
                    curr->next = new Node(t2->data);
                    curr = curr->next;
                }
            }
            t2 = t2->next;
        }

        return result;
    }
};
