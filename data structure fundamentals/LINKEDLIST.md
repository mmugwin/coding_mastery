# Linked Lists

- A sequential data structure consisting of linked nodes
- Each node contains some data/a value and a pointer to the next node
- The last node/tail node point to the ```nullptr```

## Node class declaration

As a struct


```c++
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
```

As a class


```c++
class ListNode{
    public:
        int data;
        ListNode *next;
        ListNode(): data(0), next(nullptr)
        ListNode(int data): data(data), next(nullptr){}
};
```

## Notes when working with linked lists

To traverse a linked list iteratively, we can use a while loop that checks that the current node is not pointing to ```NULL```


```c++
while(curr != nullptr) {
    //some operations
    curr = curr->next;
}
```

To declare a new linked list


```c++
ListNode* newNode = new ListNode();
```

Whenever you try to access the data or value of a linked list node **make sure the node is not a ```nullptr```**. Suppose we want to assign the value contained in the node ```head``` to a variable ```digit1```


```c++
int digit1 = head ? head -> val : 0;

//or

int digit1;
if (head != nullptr) {
    digit1 = head->val;
} else {
    digit1 = 0;
}
```

## Basic Operations

For the following basic operations suppose we have been given the following template for a linked list node

```c++
ListNode {
    int data;
    ListNode* next;
}
```

### Insert a node at the head of the linked list


```c++
ListNode* insertNodeAtHead(ListNode* head, int data) {
ListNode* tmp = new ListNode(data);
tmp->next = head;
head = tmp;
return head;
}
```

### Insert a node at the tail of the linked list


```c+++
ListNode* insertAtTail(ListNode* head, int data) {
  ListNode* node = new ListNode(data);
  ListNode* tail = head; 
  node->next = nullptr;

  if (head == nullptr){
      head = node;
  } else{
      while(tail->next != nullptr){
          tail = tail->next;
      }
      tail->next = node;
  }
  return head; 
}    
```

### Delete a node at a given position in the linked list


```c++
ListNode* deleteNode(ListNode* head, int position) {
  ListNode* curr_node;
  ListNode* tmp;
  curr_node = head;
  int counter = 0;
  while(counter < position){
      tmp = curr_node;                // this gets us to one node before the one we
                                      // want to delete   
      curr_node = curr_node->next;    // this is the node we want to delete   
      counter++;
  }

  tmp->next = curr_node->next;
  delete curr_node;

  return head;
}
```

### Reverse a Linked List

```c++
ListNode* reverse(ListNode* head) {
  ListNode* tail;
  ListNode* nextNode;

  tail = nullptr;

  while (head!=nullptr){
      nextNode = head->next;
      head->next = tail;
      tail = head;
      head = nextNode;
  }
  return tail;
}
```

## Examples

### Qu: Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

```
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
```

### Ans

```c++
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  int carry = 0, currSum, currDigit1, currDigit2;   
  ListNode* res = new ListNode();
  ListNode* out = res;

  while(l1 || l2) {

      currDigit1 = l1 ? l1->val: 0;
      currDigit2 = l2 ? l2->val: 0;
      currSum =  currDigit1 + currDigit2 + carry;

      ListNode* temp = new ListNode(currSum % 10);
      res->next =  temp;
      res = res->next;    

      carry = currSum / 10;

      l1 = l1 ? l1->next : nullptr;
      l2 = l2 ? l2->next : nullptr;

  }

  if ( carry ) {
      ListNode* temp = new ListNode(carry);
      res->next = temp;
  } 

  return out->next;
}
```

### Qu: Add Two Numbers II

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example
```
Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
```

### Ans:

```c++
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<ListNode*> s1, s2, out;
    
    while(l1 || l2) {
        ListNode* temp =  new ListNode(0);
        
        if(l1){
            s1.push(l1);
            l1 = l1->next;
        } 
        
        if(l2) {
            s2.push(l2);
            l2 = l2 -> next;
        } 
    }
    
    int carry = 0;
    
    while (!s1.empty() || !s2.empty()) {
        ListNode* curr1 = !s1.empty() ? s1.top() : nullptr;
        ListNode* curr2 = !s2.empty() ? s2.top() : nullptr;
        
        
        int digit1 = curr1 ? curr1 -> val : 0;
        int digit2 = curr2 ? curr2 -> val : 0; 
        
        int sum = carry + digit1 + digit2;
        
        ListNode* temp = new ListNode(sum % 10);
        carry = sum / 10;       
        out.push(temp);
        if (!s1.empty()) s1.pop();
        if (!s2.empty()) s2.pop();
    }
    
    if (carry) {
        ListNode* temp = new ListNode(carry);
        out.push(temp);
    }
    
    ListNode* res = new ListNode();
    ListNode* ans = res;
    
    while (!out.empty()) {
        ListNode* temp = out.top();
        res->next = temp;
        res = res->next;
        out.pop();
    }
    
    return ans->next;
    
}
```

### Qu: Remove nth Node from the end of the list 

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example:

```
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5] 
```

### Ans:

```c++
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head) return head;

    ListNode *out = new ListNode(); 
    out->next = head;
    
    ListNode* slow = out;
    ListNode* fast = out;
    
    int i = 0;
    while(i <= n) {
        fast = fast->next;
        i++;
    }
    
    while (fast) {
        slow = slow->next;
        fast = fast->next;
        i++;
    }       

    slow -> next = slow->next ? slow->next->next : nullptr;
    
    return out->next;
}
```

<!--
### Qu:



### Ans:

```c++

``` 
-->