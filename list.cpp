#include <iostream>
#include "list.h"

using namespace std;

void createList(List &L)
{
    First(L) = NULL;
    Last(L) = NULL;
}

address alokasi(infotype x)
{
    address P = new elemenList;
    Info(P) = x;
    Next(P) = NULL;
    Prev(P) = NULL;
    return P;
}

void dealokasi(address &P)
{
    delete P;
}

void insertFirst(List &L, address P)
{
    if(First(L)==NULL) {
        First(L)=P;
        Next(P)=First(L);
        Prev(P)=First(L);
        Last(L)=P;
    }
    else {
        Next(P) = First(L);
        Prev(P) = Last(L);
        Next(Last(L))=P;
        Prev(Last(L)) = P;
        First(L) = P;
    }
}

void insertLast(List &L, address P)
{
    if(First(L)==NULL){
        insertFirst(L,P);
    }
    else {
        Next(P) = First(L);
        Prev(P) = Last(L);
        Next(Last(L))=P;
        Prev(Last(L)) = P;
        Last(L) = P;
    }
}

void insertAfter(List &L, address P, address Prec) //NAUFALDZAKYANWARI
{
    if(First(L) == NULL)
    {
        insertFirst(L,P);
    }
    else
    {
        Next(P) = Next(Prec);
        Next(Prec) = P;
    }
}

void deleteFirst(List &L, address &P) //ANDINIULYA
{
    P = First(L);
    First(L) = Next(P);
    Next(P) = NULL;
}

void deleteLast(List &L, address &P) //ANDINIULYA
{
    if(Next(First(L)) == NULL)
    {
        deleteFirst(L,P);
    }
    else
    {
        address Q = First(L);
        while(Next(Next(Q)) != NULL)
        {
            Q = Next(Q);
        }
        P = Next(Q);
        Next(Q) = NULL;
    }
}

void deleteAfter(List &L, address &P, address &Prec) //NAUFALDZAKYANWARI
{
    P = Next(Prec);
    Next(Prec) = Next(P);
    Next(P) = NULL;
}

void insertID (List &L2, address P) //ANDINIULYA
{

}

void insertName(List &L2, address P) {
    address Q;
    Q=First(L2);
    if(Q==NULL) {
        insertFirst(L2,P);
    }
     else if(Info(P).name < Info(Q).name) {
        insertFirst(L2,P);
    }
    else {
        while (Info(P).name > Info(Q).name && Next(Q)!= First(L2)) {
            if (Info(Next(Q)).name > Info(P).name) {
                break;
            }
            Q=Next(Q);
        }
        insertAfter(L2,P,Q);
    }

}

address findElm(List L, infotype x) //ANDINIULYA
{
    address Q = First(L);
    while(Q != NULL){
        if(Info(Q).ID == x.ID){
            return Q;
        }
        Q = Next(Q);
    }
    return NULL;
}

