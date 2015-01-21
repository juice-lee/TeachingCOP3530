/*
Author: Kevin Jeyakumar
Date: January 20, 2015
Description: An implementation of Dijoint-Set / Union-Find data structure using path compression and some basic weighting heuristics.
Implementation: I used an array whose elements are the roots. Example: roots[i] = k means the ith element has a root k.
Weighting was handled by a second array which holds the "progeny" which is the number of things that point to that root (other than itself).
Other solutions using other data structures are also possible, but this is a very easy implement and has pretty good complexity for what it does.
Plenty of comments, many trivial, are added for clarity and teaching purposes. Email further questions to kevinj1121@gmail.com with COP3530 in subject line.
~~Things to note: if i is a root, then root[i] = i.
The file has certain input args. The first line is the number of elements. Each line after that has 3 args: operation element1 element2. If operation is 0 then we connect elements 1 and 2. If operation is 1, we determine if element 1 and 2 are connected. The file concludes when the input args are -1 -1 -1
Complexity: log(n)
*/

#include <iostream>
#include "UnionFind.h"
#include <stdio.h>
using namespace std;


int main(void)
{
    int numElements, operation, element1, element2; // variables
    const char* INPUTFILE = "uf-medium.in";

    freopen(INPUTFILE, "r", stdin); // opening the file "uf-medium.in" in read mode with stdin as the stream
    scanf("%d", &numElements); // reads the first number in the file and stores it in numElements

    UnionFind *disjointSets = new UnionFind(numElements); // instantiate UnionFind and pass in the number of elements to the constructor

    while (3 == scanf("%d %d %d", &operation, &element1, &element2)) // this is just a condition to ensure there is nothing wrong with the file
    {
        if (operation == -1 && element1 == -1 && element1 == -1) // break-condition when the inputs are -1 -1 -1, indicating end of the file
            break;
        else if (!operation) // Connect/Union. Predefined that when operation == 0, form a connection
        {
            disjointSets->Union(element1 - 1, element2 - 1); // I subtract 1 because the ith element has index i-1
        }
        else // Connected/Find Predefined that when operation == 1, determine if elements are connected and output T or F
        {
            if(disjointSets->IsConnected(element1-1,element2-1))
                cout<<"T"<<endl;
            else
                cout<<"F"<<endl;
        }
    }
    disjointSets->~UnionFind(); //clean up memory and destruct! boom

    string eof;
    cin>>eof; // This is used for IDEs that automatically close their console window after runtime, forcing them to wait for user input
    return 0;
}
