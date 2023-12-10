int length(Node *head){
    int length = 0;
    Node *tmp = head;
    while (tmp != NULL){
        tmp = tmp->next;
        length++;
    }
    return length;
}
Node* findIntersection(Node *firstHead, Node *secondHead){
    int firstListLength = length(firstHead), secondListLength = length(secondHead);
    while (firstListLength > secondListLength){
        firstHead = firstHead->next;
        firstListLength--;
    }
    while (firstListLength < secondListLength){
        secondHead = secondHead->next;
        secondListLength--;
    }
    while (firstHead != secondHead){
        firstHead = firstHead->next;
        secondHead = secondHead->next;
    }
    return firstHead;
}