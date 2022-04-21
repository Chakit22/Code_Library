    void removeloop(Node **slow,Node *head)
    {
        if((*slow)->next == head->next)
        {
            (*slow)->next = NULL;
            return;
        }
        removeloop(&(*slow)->next,head->next);
    }
    
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        Node *slow = head;
        Node*fast = head;
        Node *prev = slow;
        while(fast and fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            break;
        }
        if(fast == NULL || fast->next==NULL)
        return;
        
        if(slow == head)
        {
            prev->next = NULL;
            return;
        }
        removeloop(&slow,head);
    }
