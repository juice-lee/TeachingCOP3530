#include "UnionFind.h"

UnionFind::UnionFind(int numElements)
{
    progeny = new int[numElements]; //make arrays the size of numElements
    roots = new int[numElements];
    for(int i = 0; i<numElements; i++){
        progeny[i] = 0; //set progeny to 0 since the only thing that points to it is itself
        roots[i] = i; //initialize roots to -1 since there are no connections yet and technically everything is a root
    }
}

int UnionFind::FindRoot(int index){
    if(roots[index] == index) //if the index is a root, just return the root itself
        return index;
    else
        return roots[index] = FindRoot(roots[index]); //this finds the root and performs path compression (for every index that is a child of the root, progeny[i] is set to the root)
}

void UnionFind::Union(int index1, int index2){
    index1 = FindRoot(index1); //index1 is now the root of index1
    index2 = FindRoot(index2); //index2 is now the root of index2

    if(index1==index2) // just break if index1 and index2 have the same root
        return;
    else if(progeny[index1] > progeny[index2]){ // if index1 has more things underneath it OR if index2 has not connected to anything, then set index2's root to index1's root
        roots[index2] = index1;
        progeny[index1] = progeny[index1] + progeny[index2] + 1; // increase the progeny of index1 by the number of progeny at index2
    }
    else{ //this else occurs when index2 has more than or equal to progeny than index 1 OR any other case (which there shouldn't be)
        roots[index1] = index2; // attach index1's root to index2's root
        progeny[index2] = progeny[index2] + progeny[index1] + 1; // increase the progeny of index2 by the number of progeny at index1
    }
}

bool UnionFind::IsConnected(int index1, int index2){
    if(FindRoot(index1)==FindRoot(index2) ) // if both index1 and 2 have the same root, then return true
        return true;
    return false; // if the roots are different or not set, return false

}


UnionFind::~UnionFind()
{
    delete[] progeny;// #FreeTheMemory
    delete[] roots;// #MemoryHasRightsToo
}
