#include <math.h>
#include <iostream>
#include "HashTable.h"
#include "Heap.h"
#include "HeapHashTable.h"

using namespace std;

int getPrimeSize(int);

int main()
{
    int sizeT = H_TABLE_SIZE;
    int sizeH = HEAP_ARRAY_SIZE;

    int szT, szH;
    cin >> szT;
    cin >> szH;

    szT = getPrimeSize(szT);


    if(szT > 0 && szT > 0)
    {
        sizeT = szT;
        sizeH = szH;
    }else
    {
        cout << "Invalid Size Error\n";
    }
    
    HeapHashTable test(sizeT, sizeH+10);

    for(int i = 0; i < sizeH; i++)
    {
        string command = "";
        int value = -1;
        cin >> command;
        
        if(!(command.compare("insert")))
        {
            cin >> value;
            test.insert(value);
        }
        else if(!(command.compare("delete")))
        {
            cin >> value;
            test.deleteIndex(value);
        }
        else if(!(command.compare("deleteMax")))
        {
            test.deleteMax();    
        }
        else if(!(command.compare("lookup")))
        {
            cin >> value;
            test.find(value);
        }
        else if(!(command.compare("print")))
            test.print();
    }
    
}


int getPrimeSize(int n)
{
    if(n % 2 == 0)
    {
        n++;
    }

    int i;

    for(i = n; i < 2*n; i+=2)
    {
        int notPrime = 0;
        int root = (int)sqrt(i);
        int j; 
        for(j = 3; j <= root; j+=2)
        {
            if(i%j == 0)
            {
                notPrime = 1;
                break;
            }
        }
        if(notPrime == 0)
                break;

    }

    return i;

}
