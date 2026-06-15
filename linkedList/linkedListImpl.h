#pragma once

#include <assert.h>
#include <iostream>

template <typename T>
struct Node
{
   T value;
   Node<T>* next{nullptr};
};

template <typename T>
void insertAtHead(Node<T>*& head, Node<T>& n)
{
   n.next = head;
   head = &n;
   return;
}

template <typename T>
void append(Node<T>*& head, Node<T>& n)
{
   if (head == nullptr)
   {
      std::cout << "head provided is empty\n";
      return;
   }

   Node<T>* nodePtr = head;
   while (nodePtr->next != nullptr)
   {
      nodePtr = nodePtr->next;
   }

   nodePtr->next = &n;
}

template <typename T>
void insert(Node<T>*& head, Node<T>& n, int position)
{
   if (position == 0)
   {
      std::cout << "Use insertAtHead() to insert at the start of the list\n";
      return;
   }

   if (head == nullptr)
   {
      std::cout << "head provided is empty\n";
      return;
   }

   Node<T>* temp = head;
   for (int i = 0; i < position - 1; i++)
   {
      if (temp->next != nullptr)
      {
         temp = temp->next;
      }
      else
      {
         std::cerr << "Position out of range\n";
         return;
      }
   }

   n.next = temp->next;
   temp->next = &n;
}

template <typename T>
void deleteFromHead(Node<T>*& head)
{
   if (head == nullptr)
   {
      std::cout << "head provided is empty\n";
      return;
   }

   Node<T>* nextPtr = head->next;
   head = nextPtr;
}

template <typename T>
void deleteValue(Node<T>*& head, int value)
{
   if (head == nullptr)
   {
      std::cout << "head provided is empty\n";
      return;
   }

   Node<T>* tempPtr = head;
   while (tempPtr->next != nullptr)
   {
      if (tempPtr->next->value == value)
      {
         deleteFromHead(tempPtr->next);
         return;
      }
      tempPtr = tempPtr->next;
   }
}

template <typename T>
void deleteFromTail(Node<T>*& head)
{
   if (head == nullptr)
   {
      std::cout << "head provided is empty\n";
      return;
   }
   if (head->next == nullptr)
   {
      head = nullptr;
      return;
   }

   Node<T>* prevPtr{head};
   Node<T>* nodePtr{head};
   while (nodePtr->next != nullptr)
   {
      prevPtr = nodePtr;
      nodePtr = nodePtr->next;
   }

   prevPtr = nullptr;
}
