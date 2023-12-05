#include<bits/stdc++.h>
using namespace std;
Node<int>* sort(Node<int>* first, Node<int>* second){
    if(first -> next == NULL){
        first->next = second;
        return first;
    }
    Node<int>* cur1 = first, *next1 = first -> next;
    Node<int>* cur2 = second, *next2 = second -> next;
    while(next1 && cur2){
        if ((cur2->data) >= (cur1->data) && (cur2->data) <= (next1->data)) { 
            next2 = cur2->next; 
            cur1->next = cur2; 
            cur2->next = next1;
            cur1 = cur2; 
            cur2 = next2; 
        } 
        else {
            if (next1->next) { 
                next1 = next1->next; 
                cur1 = cur1->next; 
            }
            else { 
                next1->next = cur2; 
                return first; 
            } 
        } 
    }
    return first;
}
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second){
    if(!first){
        return second;
    }
    if(!second){
        return first;
    }
    if((first -> data) < (second ->data)){
        return sort(first, second);
    }
    else{
        return sort(second, first);
    }
}