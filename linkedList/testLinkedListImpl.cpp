#include "testLinkedListImpl.h"
#include "linkedListImpl.h"

void testCases()
{
   Node<int> node1{5}; // Works in c++17
   Node<int>* head = &node1;
   testNodeCreation(head);

   Node node2{7}; // will not work in c++17 due to Class Template Argument Deduction blindspot failure when making
                  // a class type with no constructors
   Node node3{1};
   append(head, node2);
   append(head, node3);
   testNodeAppend(head);

   Node node4{1};
   Node node5{3};
   Node node6{4};
   Node node7{6};
   Node node8{0};
   Node<int>* head2{&node4};
   insertAtHead(head2, node5);
   testNodeInsertAtHead(head2);

   insert(head2, node6, 1);
   insert(head2, node7, 4);
   insert(head2, node7, 3);
   testNodeInsert(head2);

   deleteFromHead(head2);
   testDeleteFromHead(head2);

   deleteFromTail(head2);
   testDeleteFromTail(head2);

   node5.next = nullptr;
   node6.next = nullptr;
   node8.next = nullptr;

   append(head2, node5);
   append(head2, node7);
   append(head2, node8);
   deleteValue(head2, 0);
   deleteValue(head2, 1);
   testDeleteValue(head2);
}