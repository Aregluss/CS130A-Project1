#ifndef HEAPHASHTABLE_H
#define HEAPHASHTABLE_H

class HashTable;
class Heap;

class HeapHashTable
{
private:
    Heap *hp;
    HashTable *ht;

public:

	HeapHashTable()
	{
		hp = new Heap();
		ht = new HashTable();
	}

	HeapHashTable(int sizeT, int sizeH)
	{
		hp = new Heap(sizeH);
		ht = new HashTable(sizeT);
	}

	void insert(int num)
	{
		//this order seems ot work better
		
        HTNode* htnode = ht->insertNode(num);
        
        if (htnode != NULL)
        {
            hp->insert(htnode);
        }
        else
        {
            cout << "error: item already exists\n";
        }
        // hp->printHeapArray();
	}

	void find(int num)
	{
		int node = ht->findNode(num);

		if(node)
			cout << "found " << num << endl;
		else
			cout << num << " not found " << endl;
	}


	void deleteMax()
	{
		HTNode* max = hp->deleteMax(1);

		if(max != NULL)
		{
			ht->deleteNode(max->value);
			cout << max->value << endl;
		}
		else
		{
			cout << "error\n";
		}
	}

	void deleteIndex(int num)
	{
		int pos = ht->deleteNode(num);
		
		if(pos > 0)
		{
			hp->deleteIndex(pos);
		}
		else
		{
			cout << "error: item not present\n";
		}
        // hp->printHeapArray();
	}



	void print()
	{
		hp->printBigtoSmall();
	}

};



#endif