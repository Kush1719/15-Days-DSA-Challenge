Node *removeKthNode(Node *head, int K) {
    if (head == NULL || K == 0) {
        return head;
    }
    Node *slow = head;
    Node *fast = head;
    for (int i = 0; i < K; i++) {
        if (fast->next == NULL) {
            Node *next = head->next;
            head->next = NULL;
            head = next;
            return head;
        }
        else {
            fast = fast->next;
        }
    }
    while (fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return head;
}