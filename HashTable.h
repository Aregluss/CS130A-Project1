#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "HTNode.h"
#include <stdlib.h>

using namespace std;

const int H_TABLE_SIZE = 97;

class HashTable
{
	private:
		int size;
		HTNode **htable;

		void AllocateHashTable(int sz)
		{
			size = sz;
			htable = new HTNode*[size];
			for (int i = 0; i < size; i++)
			{
				htable[i] = NULL;
			}

		}

	public:
		HashTable()
		{
			AllocateHashTable(H_TABLE_SIZE);
		}

		HashTable(int sz)
		{
			AllocateHashTable(sz);
		}

		HashTable(HashTable *ht)   ////SHALLOW COPY ON THE EXTENDED NODES ?? so far used only in heaptable constructor, not concerned
		{
			size = ht->size;
			htable = new HTNode* [size];
			for(int i = 0; i < size; i++)
			{
				htable[i] = ht->htable[i];
			}
		}

		int getSize()
		{
			return size;
		}

		int HashFunc(int value)
		{
			return abs(value % size);
		}

		HTNode* hashInsert(int num, int pos)
		{
			HTNode* ptr = insertNode(num);
			ptr->heapPos = pos;
			return ptr;

		}

		HTNode* insertNode(int num)
		{
			int hVal = HashFunc(num);

			//cout << "Inserting " << num << " into Hash Table at " << hVal << endl;
			HTNode* last = NULL;
			HTNode* insertLoc = htable[hVal];

			while(insertLoc != NULL)
			{
                if (insertLoc->value == num) {
                    return NULL;        // num already exist
                }
                last = insertLoc;
				insertLoc = insertLoc->next;
			}

            HTNode* newNode = new HTNode(num);
			if(last == NULL)
			{
				htable[hVal] = newNode;			
			}
			else
			{
				last->next = newNode;				
			}

			return newNode;
		}

		int deleteNode(int num)
		{
			int hVal = HashFunc(num);
            HTNode* deletePrev = NULL;
			HTNode* deleteLoc = htable[hVal];
     
            while (deleteLoc != NULL)
            {
                if (deleteLoc->value == num)
                    break;
                deletePrev = deleteLoc;
                deleteLoc = deleteLoc->next;
            }

            if (deleteLoc == NULL)
			{
				return -1;
			}

            if (deletePrev == NULL)
            {
                htable[hVal] = deleteLoc->next;
            }
            else {
                deletePrev->next = deleteLoc->next;
            }

            int retVal = deleteLoc->heapPos;
			delete deleteLoc;

			return retVal;
		}

		int findNode(int num)
		{
            HTNode *node = NULL;
			int hVal = HashFunc(num);
			HTNode* searchLoc = htable[hVal];

			while(searchLoc != NULL)
            {
                if(searchLoc->value == num)
                {
                    node = searchLoc;
                    break;
                }
                searchLoc = searchLoc->next;
            }

			if(node)
				return 1;
			else
				return 0;
            //return node;
		}

		void printRow(int num)
		{
			int hVal = HashFunc(num);
			HTNode* nodes = htable[hVal];

            if (nodes != NULL) {
                while (nodes != NULL)
                {
                    cout << nodes->value << "/" << nodes->heapPos << " | ";
                    nodes = nodes->next;
                }
                cout << endl;
            }
		}
};

#endif