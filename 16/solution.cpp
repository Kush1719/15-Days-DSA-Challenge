Node *removeLoop(Node *head){
    if (head == nullptr || head->next == nullptr){
        return head;
    }
    Node *slow = head;
    Node *fast = head;
    while (true){
        if (fast == nullptr || fast->next == nullptr){
            return head;
        }
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast){
            break;
        }
    }
    fast = head;
    Node *start = nullptr;
    while (fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    start = slow;
    Node *cur = start;
    while (true){
        if (cur->next == start){
            cur->next = nullptr;
            return head;
        }
        cur = cur->next;
    }
}