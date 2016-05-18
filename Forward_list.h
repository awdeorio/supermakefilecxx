#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H
/* Forward_list.h
 *
 * singly-linked list with iterator interface
 *
 * Andrew DeOrio <awdeorio@umich.edu>
 */

#include <cassert>  //assert
#include <iostream> //cout


////////////////////////////////////////////////////////////////////////////////
// Forward_list declaration
template <typename T>
class Forward_list {
  //OVERVIEW: a singly-linked list
 public:

  //EFFECTS:  returns true if the list is empty
  bool empty() const;

  //REQUIRES: list is not empty
  //EFFECTS: Returns a reference to the first element in the list
  T & front() const;

  //MODIFIES: this
  //EFFECTS:  inserts datum into the front of the list
  void push_front(const T &datum);

  //REQUIRES: list is not empty
  //MODIFIES: this
  //EFFECTS:  removes the item at the front of the list
  void pop_front();

  //default constructor and Big Three
  Forward_list();
  Forward_list(const Forward_list &other);
  ~Forward_list();
  Forward_list & operator=(const Forward_list &rhs);

private:
  //a private type
  struct Node {
    Node *next;
    T datum;
  };

  //MODIFIES: this
  //EFFECTS:  copies all nodes from l to this
  void push_all(const Forward_list &other);

  //MODIFIES: this
  //EFFECTS:  removes all nodes
  void pop_all();

  Node *front_ptr; //pointer to the first Node in the list, 0 for empty list

 public:
  ////////////////////////////////////////
	class Iterator {
    //OVERVIEW: Iterator interface to Forward_list
  public:

    // create a default Iterator, which points "past the end", AKA NULL, AKA 0
    Iterator() : node_ptr(0) {}
				
    // get the T at the current Iterator position
    T& operator* () const {
      assert(node_ptr);
      return node_ptr->datum;
    }

    // return the address of the data in the pointed-to node
    // the compiler then re-applies the "->" operator with the returned pointer
    T* operator-> () const {
      assert(node_ptr);
      return &(node_ptr->datum);
    }

    // move Iterator to next position (prefix)
    // REQUIRES: Iterator is not at default position
    Iterator& operator++ () { 
      assert(node_ptr);
      node_ptr = node_ptr->next;
      return *this;
    }

    // move Iterator to next position (postfix)
    Iterator operator++ (int) {
      assert(node_ptr);
      Iterator tmp(node_ptr);
      node_ptr = node_ptr->next;
      return tmp; //Note: returns a copy!  This is how postfix works.
    }

    // compare two Iterator objects by the their position
    bool operator!= (Iterator rhs) const { return
        node_ptr != rhs.node_ptr;
    }

    // compare two Iterator objects by the their position
    bool operator== (Iterator rhs) const {
      return node_ptr == rhs.node_ptr;
    }

  private:
    Node *node_ptr;    //current Iterator position is a Forward_list node
    friend class Forward_list; //needed so that Forward_list::begin() can access private ctor

    // construct an Iterator at a specific position
    Iterator(Node *p) : node_ptr(p) {}

  };//Forward_list::Iterator

	// return an Iterator pointing to the first node
  Iterator begin() const {
    return Iterator(front_ptr);
  }

	// return an Iterator pointing to "past the end"
	Iterator end() const {
    return Iterator();
  }

};//Forward_list


////////////////////////////////////////////////////////////////////////////////
// Forward_list implementation

template <typename T>
bool Forward_list<T>::empty() const {
  return front_ptr == 0;
}

template <typename T>
T & Forward_list<T>::front() const {
  assert(!empty());
  return front_ptr->datum;
}

template <typename T>
void Forward_list<T>::push_front(const T &datum) {
  Node *p = new Node;
  p->datum = datum;
  p->next = front_ptr;
  front_ptr = p;
}

template <typename T>
void Forward_list<T>::pop_front() {
  assert(!empty());
  Node *victim = front_ptr;
  front_ptr = front_ptr->next;
  delete victim; victim=0;
}

template <typename T>
void Forward_list<T>::pop_all() {
  while (!empty()) {
    pop_front();
  }
}

template <typename T>
void Forward_list<T>::push_all(const Forward_list &other) {
  //HACK this is a very inefficient solution!
  Forward_list<T> reverse_copy;
  for (auto i:other) reverse_copy.push_front(i);
  for (auto i:reverse_copy) push_front(i);
}

template <typename T>
Forward_list<T>::Forward_list()
  : front_ptr(0) {}

template <typename T>
Forward_list<T>::~Forward_list() {
  pop_all();
}

template <typename T>
Forward_list<T>::Forward_list(const Forward_list &other)
  : front_ptr(0) {
  push_all(other);
}

template <typename T>
Forward_list<T> & Forward_list<T>::operator= (const Forward_list &rhs) {
  if (this == &rhs) return *this;
  pop_all();
  push_all(rhs);
  return *this;
}

#endif
