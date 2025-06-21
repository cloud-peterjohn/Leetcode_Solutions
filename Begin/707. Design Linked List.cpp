// https://leetcode.com/problems/design-linked-list

class MyLinkedList
{
    struct Node
    {
        int val;
        Node *prev;
        Node *next;
        Node(int value)
        {
            this->val = value;
            this->next = nullptr;
            this->prev = nullptr;
        }
    };
    Node *head;
    Node *tail;
    int size;

public:
    MyLinkedList()
    {
        this->head = new Node(int());
        this->tail = new Node(int());
        this->head->next = this->tail;
        this->tail->prev = this->head;
        this->size = 0;
    }

    int get(int index)
    {
        if (index >= this->size || index < 0)
        {
            return -1;
        }
        Node *p = this->head;
        for (int i = 0; i <= index; i++)
        {
            p = p->next;
        }
        int p_val = p->val;
        return p_val;
    }

    void addAtHead(int val)
    {
        Node *new_node = new Node(val);
        Node *current_front = this->head->next;

        this->head->next = new_node;
        new_node->next = current_front;
        current_front->prev = new_node;
        new_node->prev = this->head;

        this->size++;
    }

    void addAtTail(int val)
    {
        Node *new_node = new Node(val);
        Node *current_back = this->tail->prev;

        this->tail->prev = new_node;
        new_node->prev = current_back;
        current_back->next = new_node;
        new_node->next = this->tail;

        this->size++;
    }

    void addAtIndex(int idx, int val)
    {
        if (idx >= 0 && idx <= this->size)
        {
            if (idx == 0)
            {
                addAtHead(val);
            }
            else if (idx == this->size)
            {
                addAtTail(val);
            }
            else
            {
                Node *org_node_idx_1 = this->head;
                // 找到原idx-1和idx结点
                for (int i = 0; i < idx; i++)
                {
                    org_node_idx_1 = org_node_idx_1->next;
                }
                Node *org_node_idx = org_node_idx_1->next;

                // 插入
                Node *new_node = new Node(val);
                org_node_idx_1->next = new_node;
                new_node->next = org_node_idx;
                org_node_idx->prev = new_node;
                new_node->prev = org_node_idx_1;

                this->size++;
            }
        }
        else
        {
            // throw runtime_error("Index invalid!");
            return;
        }
    }

    int pop_front()
    {
        if (this->size < 1)
        {
            // throw runtime_error("No elements to pop!");
            return 0;
        }

        Node *front = this->head->next;
        Node *second = front->next;

        this->head->next = second;
        second->prev = this->head;

        this->size--;

        int front_value = front->val;
        delete front;

        return front_value;
    }

    int pop_back()
    {
        if (this->size < 1)
        {
            // throw runtime_error("No elements to pop!");
            return 0;
        }

        Node *back = this->tail->prev;
        Node *back_prev = back->prev;

        back_prev->next = this->tail;
        this->tail->prev = back_prev;

        this->size--;

        int back_value = back->val;
        delete back;
        return back_value;
    }

    void deleteAtIndex(int idx)
    {
        if (idx < 0 || idx >= this->size)
        {
            // throw runtime_error("Index out of range!");
            return;
        }
        else
        {
            if (idx == 0)
            {
                pop_front();
            }
            else if (idx == this->size - 1)
            {
                pop_back();
            }
            else
            {
                // 找到idx-1结点
                Node *node_idx_prev = this->head;
                // 初始指向head，循环一次时指向index=0结点，循环idx次时指向index=idx-1结点
                for (int i = 0; i < idx; i++)
                {
                    node_idx_prev = node_idx_prev->next;
                }
                // 找到idx结点
                Node *node_idx = node_idx_prev->next;
                // 找到idx+1结点
                Node *node_idx_next = node_idx->next;

                node_idx_prev->next = node_idx_next;
                node_idx_next->prev = node_idx_prev;

                this->size--;
                int node_value = node_idx->val;
                delete node_idx;
            }
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */


