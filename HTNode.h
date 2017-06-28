#ifndef HTNODE_H
#define HTNODE_H

class HTNode
{
	public:
		HTNode* next;
		int value;
		int heapPos;


		
		HTNode(int val)
		{
			value = val;
			next = NULL;
			heapPos = -1;
		}

		HTNode(int val, int heap)
        {
            value = val;
			next = NULL;
			heapPos = heap;
        }

        void setNext(HTNode* n)
        {
        	if(n != NULL)
        		next = n;
        }

        HTNode* getNext()
        {
        	return next;
        }

        HTNode* getLast()
        {
            HTNode* last = this;
            while (last->next != NULL)
            {
                last = last->next;
            }
            return last;
        }

};

#endif