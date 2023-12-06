LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) {
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *current = head;
    while (current != NULL) {
        LinkedListNode<int> *nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;

    }
    return prev;
}