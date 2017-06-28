#ifndef HEAP_H
#define HEAP_H

#include "HTNode.h"

using namespace std;

const int HEAP_ARRAY_SIZE = 100;


class Heap
{
	private:
		int maxSize;
		HTNode** heapArray;
		int currentSize;

        void allocateHeap(int size)
        {
            maxSize = size;
            currentSize = 0;
            heapArray = new HTNode*[maxSize];
            for (int i = 0; i < maxSize; i++)
            {
                heapArray[i] = NULL;
            }
        }

	public:
		Heap()
		{
            allocateHeap(HEAP_ARRAY_SIZE);
		}

		Heap(int size)
		{
            allocateHeap(size);
		}

	~Heap()
		{
			delete heapArray;
		}

		Heap(const Heap &h)
		{
            allocateHeap(h.maxSize);
			
			for (int i = 0; i < maxSize; i++)
			{
				heapArray[i] = h.heapArray[i];
			}
			currentSize = h.currentSize;
		}

        void printHeapArray()
        {
            cout << "HEAP array looks like: ";
            for (int i = 1; i <= currentSize; i++)
            {
                cout << heapArray[i]->value << ":" << heapArray[i]->heapPos << " ";
            }
            cout << endl;
        }

		void percolateUp(int index)
		{
	
            while (index/2 != 0 && (heapArray[index]->value > heapArray[index/2]->value))
			{
                HTNode *temp = heapArray[index];

                heapArray[index] = heapArray[index/2];
                heapArray[index]->heapPos = index;
				
				heapArray[index/2] = temp;
				heapArray[index/2]->heapPos = index/2;

				index = index/2;
			}
		}

        void percolateDown(int index, int update_heapPos_flag)
		{
            while (2*index <= currentSize) 
            {
                int index2 = 2 * index;
                if (index2 + 1 <= currentSize)
                {
                    if (heapArray[index2 + 1]->value > heapArray[index2]->value)
                        index2++;
                }

                if (heapArray[index]->value >= heapArray[index2]->value)
                    break;
			    
                HTNode *temp = heapArray[index];
                
                heapArray[index] = heapArray[index2];
                heapArray[index2] = temp;

                if (update_heapPos_flag)
                {
                    heapArray[index]->heapPos = index;
                    heapArray[index2]->heapPos = index2;
                }
                index = index2;
			}
		}


		int insert(HTNode* n)
		{
			currentSize++;
			heapArray[currentSize] = n;
			n->heapPos = currentSize;

			percolateUp(currentSize);

//            cout << "HEAP added " << n->value << " at " << currentSize << endl;

           // printHeapArray();
            
            return n->heapPos;           ///<---------_SHOULD RETURN WHERE IN HEAP THE INT IS
		}

		HTNode* deleteMax(int update_heapPos_flag)
		{
			HTNode* returnVal = NULL;

			if(currentSize > 0)
			{
				returnVal = heapArray[1];
				heapArray[1] = heapArray[currentSize];
                if (update_heapPos_flag)
                    heapArray[1]->heapPos = 1;
				heapArray[currentSize] = NULL;
				currentSize--;
			
                percolateDown(1, update_heapPos_flag);
			}

			return returnVal;
		}


		HTNode* deleteIndex(int index)
		{
			HTNode* returnVal = heapArray[index];
			heapArray[index] = heapArray[currentSize];
            heapArray[index]->heapPos = index;
			heapArray[currentSize] = NULL;
			currentSize--;

			//cout << "OHHH YEAH PERCOLATE ME DADDY"
			percolateDown(index, 1);

			return returnVal;
		}

        /*
        Heap& operator = (const Heap& h)
        {

            if (maxSize != h.maxSize)
            {
                delete heapArray;

                allocateHeap(h.maxSize);
            }

            for (int i = 0; i < maxSize; i++)
            {
                heapArray[i] = h.heapArray[i];
            }

            currentSize = h.currentSize;
            return *this;

        }
*/


		void printBigtoSmall()
		{
            Heap copy(*this); 
            
			for(int i = currentSize; i > 0; i--)
			{
				cout << copy.deleteMax(0)->value << " ";
			}
			cout << endl;
		}

};


#endif