#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct Trailer;
struct Leader
{
    int key;
    int count;
    Leader   *nx;
    Trailer *tr;
};
struct Trailer
{
    Leader   *ld;
    Trailer *nx;
};

void AddEdge(Leader *& vertexes, int vertexA, int vertexB){
    Leader *ptrA = nullptr, *ptrB= nullptr;
    for(ptrA = vertexes;ptrA && ptrA->key!= vertexA;ptrA = ptrA->nx);
    for(ptrB = vertexes;ptrB && ptrB->key!= vertexB;ptrB = ptrB->nx);
    bool setEdge = true;
    if(ptrA && ptrB){
        Trailer * trTmp = ptrA->tr;
        for(Trailer * trTmp = ptrA->tr;trTmp && trTmp->ld!=ptrB;trTmp = trTmp->nx);
        setEdge = (bool)trTmp;
    }
    else{

        if(!ptrA){
            ptrA = new Leader;
            ptrA->key = vertexA;
            ptrA->count = 0;
            ptrA->nx = nullptr;
            ptrA->tr = nullptr;

            ptrA->nx = vertexes;
            vertexes = ptrA;
        }

        if(!ptrB){
            ptrB = new Leader;
            ptrB->key = vertexB;
            ptrB->count = 0;
            ptrB->nx = nullptr;
            ptrB->tr = nullptr;
            ptrB->nx = vertexes;
            vertexes = ptrB;}

    }

    if(setEdge){
        ptrB->count++;
        Trailer* elemTr = new Trailer;
        elemTr->ld = ptrB;
        elemTr->nx = ptrA->tr;
        ptrA->tr = elemTr;
    }
}

void PrintGraph(Leader*vertexes){
    if(vertexes == nullptr)
        printf("Graph is Empty");
    else
        while(vertexes){
            Trailer* trTmp = vertexes->tr;
            while(trTmp){
                printf("(%d,%d)\n",vertexes->key,trTmp->ld->key);
                trTmp = trTmp->nx;
            }
            vertexes = vertexes->nx;
        }
}

void DeleteGraph(Leader*&vertexes){
    while(vertexes){
        while(vertexes->tr){
            Trailer*tmp = vertexes->tr;
            vertexes->tr = vertexes->tr->nx;
            delete tmp;
        }
        Leader*tmp = vertexes;
        vertexes = vertexes->nx;
        delete tmp;
    }

}

bool ExcludeEdge(Leader *& vertexes, int vertexA, int vertexB){
    Leader *ptrA = nullptr, *ptrB= nullptr;
    for(ptrA = vertexes;ptrA && ptrA->key!= vertexA;ptrA = ptrA->nx);
    for(ptrB = vertexes;ptrB && ptrB->key!= vertexB;ptrB = ptrB->nx);
    if(ptrA && ptrA->tr && ptrB){
        if(ptrA->tr->ld == ptrB){
            Trailer * t = ptrA->tr;
            ptrA->tr = ptrA->tr->nx;
            delete t;
            ptrB->count--;

        }
        else{
            Trailer * trTmp;
            for(trTmp = ptrA->tr;trTmp->nx && trTmp->nx->ld!=ptrB;trTmp = trTmp->nx);
            if(trTmp->nx){
                Trailer * t = trTmp->nx;
                trTmp->nx = trTmp->nx->nx;
                delete t;
                ptrB->count--;
            }
        }
        return true;
    }
    return false;
}

void sort(Leader* graph){
    Leader* f = new Leader;
    f->nx = graph;
    Leader* LDnew = new Leader;
    LDnew->nx = NULL;
    Leader* p, *q;
    Trailer* t;
    Leader* r;

    while(f->nx){
        p = f;
        while(p->nx){
            if(p->nx->count != 0){
                p = p->nx;
            } else {
                q = p->nx;
                ExcludeEdge(graph, q->key,q->nx->key);
                t = q->tr;
                for(Leader* ptrA = q->nx; ptrA && ptrA->key;ptrA->count--, ptrA = ptrA->nx);

            }

        }
    }
}


int main(int argc, char** argv) {

    FILE* graphInFile = fopen(R"(C:\Users\old_g\CLionProjects\TopologicalSort\graph.txt)","r");
    Leader *graph = nullptr;
    int vertexA = 0, vertexB = 0;
    int k=0;
    if(graphInFile)
    {
        k = fscanf(graphInFile, "%d%d", &vertexA, &vertexB) > 0;
        while(k){
            printf("(%d,%d)\n",vertexA,vertexB);
            AddEdge(graph,vertexA,vertexB);
            k = fscanf(graphInFile, "%d%d", &vertexA, &vertexB) > 0;
        }

        fclose(graphInFile);
        puts("Print Graph");
        PrintGraph(graph);
        ExcludeEdge(graph,1,5);
        ExcludeEdge(graph,4,5);
        ExcludeEdge(graph,5,3);
        PrintGraph(graph);
        DeleteGraph(graph);
        PrintGraph(graph);

    }else
        puts("File is not open");
    return 0;
}