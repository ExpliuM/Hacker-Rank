#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node
{
   Node *next;
   Node *prev;
   int value;
   int key;
   Node(Node *p, Node *n, int k, int val) : prev(p), next(n), key(k), value(val){};
   Node(int k, int val) : prev(NULL), next(NULL), key(k), value(val){};
};

class Cache
{
protected:
   map<int, Node *> mp;            // map the key to the node in the linked list
   int cp;                         // capacity
   Node *tail;                     // double linked list tail pointer
   Node *head;                     // double linked list head pointer
   virtual void set(int, int) = 0; // set function
   virtual int get(int) = 0;       // get function
};

class LRUCache : private Cache
{
public:
   LRUCache(int capacity)
   {
      this->head = nullptr;
      this->tail = nullptr;
      this->cp = capacity;
   }

   virtual void set(int key, int value)
   {
      Node *nodeToHandle = this->mp[key];

      if (nodeToHandle == nullptr)
      {
         nodeToHandle = new Node(key, value);

         // Add to map
         this->mp[key] = nodeToHandle;
      }
      else
      {
         // Handle hit
         nodeToHandle->value = value;
         // Tie up next node
         if (nodeToHandle->next == nullptr)
         {
            // nodeToHandle is the tail node
            this->tail = this->tail->prev;
            if (this->tail == nullptr)
            {
               this->head = nullptr;
            }
            else
            {
               tail->next = nullptr;
            }
         }
         else
         {
            // nodeToHandle is not the tail node
            nodeToHandle->next->prev = nodeToHandle->prev;
         }

         // Tie up prev node
         if (nodeToHandle->prev == nullptr)
         {
            // nodeToHandle is the head node
            if (this->head != nullptr)
            {
               this->head = this->head->next;
               this->head->prev = nullptr;
            }
         }
         else
         {
            nodeToHandle->prev->next = nodeToHandle->next;
         }
      }

      // Is this the first node?
      if (this->head == nullptr)
      {
         this->tail = nodeToHandle;
      }
      else
      {
         // Connect previous head
         this->head->prev = nodeToHandle;
      }

      nodeToHandle->next = this->head;

      // Replace head`
      this->head = nodeToHandle;

      // Handle overflow
      if ((int)this->mp.size() > this->cp)
      {
         Node *tailToDelete = this->tail;

         // Update tail
         this->tail = tailToDelete->prev;

         // Remove from map
         mp.erase(tailToDelete->key);

         // delete node
         delete (tailToDelete);
      }
   }

   virtual int get(int key)
   {
      Node *nodePtr = this->mp[key];
      if (nodePtr == nullptr)
      {
         return -1;
      }
      return nodePtr->value;
   }
};

int main(int argc, char *argv[])
{
   int n, capacity, i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for (i = 0; i < n; i++)
   {
      string command;
      cin >> command;
      if (command == "get")
      {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      }
      else if (command == "set")
      {
         int key, value;
         cin >> key >> value;
         l.set(key, value);
      }
   }

   return 0;
}
