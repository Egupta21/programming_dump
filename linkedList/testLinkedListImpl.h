#pragma once
#include "linkedListImpl.h"
#include <assert.h>
#include <iostream>

template <typename T>
void testNodeCreation(const Node<T>* h)
{
   assert(h->value == 5);
   assert(h->next == nullptr);
}

template <typename T>
void testNodeAppend(const Node<T>* h)
{
   assert(h->value == 5);
   assert(h->next->value == 7);
   assert(h->next->next->value == 1);
   assert(h->next->next->next == nullptr);
}

template <typename T>
void testNodeInsertAtHead(const Node<T>* h)
{
   assert(h->value == 3);
   assert(h->next->value == 1);
   assert(h->next->next == nullptr);
}

template <typename T>
void testNodeInsert(const Node<T>* h)
{
   assert(h->value == 3);
   assert(h->next->value == 4);
   assert(h->next->next->value == 1);
   assert(h->next->next->next->value == 6);
   assert(h->next->next->next->next == nullptr);
}

template <typename T>
void testDeleteFromHead(const Node<T>* h)
{
   assert(h->value == 4);
   assert(h->next->value == 1);
   assert(h->next->next->value == 6);
   assert(h->next->next->next == nullptr);
}

template <typename T>
void testDeleteFromTail(const Node<T>* h)
{
   assert(h->value == 4);
   assert(h->next->value == 1);
   assert(h->next->next->next == nullptr);
}

template <typename T>
void testDeleteValue(const Node<T>* h)
{
   assert(h->value == 4);
   assert(h->next->value == 3);
   assert(h->next->next->value == 6);
   assert(h->next->next->next == nullptr);
}

void testCases();