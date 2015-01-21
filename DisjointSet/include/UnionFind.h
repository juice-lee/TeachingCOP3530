#ifndef UNIONFIND_H
#define UNIONFIND_H


class UnionFind
{
    public:
        UnionFind(int numElements);
        int FindRoot(int index);
        void Union(int index1, int index2);
        bool IsConnected(int index1, int index2);
        virtual ~UnionFind();
    protected:
    private:
        int* roots;
        int* progeny;
};

#endif // UNIONFIND_H
