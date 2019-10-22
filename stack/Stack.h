/*
 * Simple Stack Implementation using Singly Linked List
 *
 * @author
 *   Abhilash Muraleedharan <amuraleedharan13@gmail.com>
 *
 */
#pragma once

#include <iostream>
#include <exception>

template <typename T>
class Stack {
   public:
      Stack() : head_(nullptr), size_(0) { }

      ~Stack() {
         StackNode *thru = head_;
         while(thru != nullptr) {
            StackNode *toDelete = thru;
            thru = thru->next;
            delete toDelete;
            toDelete = nullptr;
         }
      }

      void push(const T & data);   // Adds the element data at the top of the stack.

      void pop();   // Deletes the top most element of the stack.

      const T & top();   // Returns a reference to the top most element of the stack.

      unsigned size();   // Returns the size of the stack.

      bool empty();   // Returns whether the stack is empty.

   private:
      class StackNode {
         public:
            const T & data;   // Stores the node data
            StackNode *next;  // Points to the next node in stack
            StackNode(const T & data) : data(data), next(nullptr) { }
      };
    
      StackNode *head_;   // Points to the top most element.
      unsigned size_;     // Stores the size of the stack
};

/*
 * Adds the element data at the top of the stack
 */
template <typename T>
void Stack<T>::push(const T & data) {
   StackNode *node =  new StackNode(data);
   if (empty()) {
      // This is the first node
      node->next = nullptr;
   } else {
      // Not an empty stack
      node->next = head_;
   }
   // Update head
   head_ = node;
   // Increment stack size counter
   size_++;
}

/*
 * Deletes the top most element of the stack
 */
template <typename T>
void Stack<T>::pop() {
   if (!empty()) {
      StackNode *toDelete = head_;
      head_ = head_->next;
      delete toDelete;
      toDelete = nullptr;
      // Decrement the stack size pointer
      size_--;
   } else {
      std::cerr << "Nothing to pop. Stack is empty!!!" << std::endl;
   }
}

/*
 * Returns a reference to the top most element of the stack.
 */
template <typename T>
const T & Stack<T>::top() {
   if(!empty()) {
      return head_->data;
   } else {
      std::cerr << "Stack is empty!!!" << std::endl;
      throw std::runtime_error("Stack is empty!!!");
   }
}

/*
 * Returns the size of the stack
 */
template <typename T>
unsigned Stack<T>::size() {
   return size_;
}

/*
 * Checks whether the stack is empty.
 * Returns TRUE if the stack is empty, returns FALSE otherwise.
 */
template <typename T>
bool Stack<T>::empty() {
   return (head_ == nullptr);
}
