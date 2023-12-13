int countDigits(Node<int> *head) {
    int c = 0;
    while (head) {
        head = head->next;
        c++;
    }
    return c;
}
Node<int> *reverseList(Node<int> *head) {
    Node<int> *prev = NULL, *curr = head, *nextNode;
    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}
Node<int> *addTwoLists(Node<int> *first, Node<int> *second) {
    first = reverseList(first);
    second = reverseList(second);
    if (countDigits(first) < countDigits(second)) {
        Node<int> *temp = first;
        first = second;
        second = temp;
    }
    int carry = 0;
    Node<int> *head = first;
    while (second != NULL) {
        first->data += second->data + carry;
        carry = first->data / 10;
        first->data %= 10;
        if (first->next == NULL && carry) {
            Node<int> *newNode = new Node<int>(carry);
            first->next = newNode;
            first = first->next;
            carry = 0;
            break;
        }
        first = first->next;
        second = second->next;
    }
    while (first != NULL) {
        first->data += carry;
        carry = first->data / 10;
        first->data %= 10;
        if (first->next == NULL && carry) {
            Node<int> *newNode = new Node<int>(carry);
            first->next = newNode;
            break;
        }
        first = first->next;
    }
    head = reverseList(head);
    return head;
}