
struct linked_list {
    int val;
    struct linked_list * next;
};

typedef struct {
    struct linked_list *min;
    struct linked_list *top;
} MinStack;


MinStack* minStackCreate() {
    MinStack *newstack = (MinStack*) malloc(sizeof(MinStack));
    if (!newstack) return NULL; // Allocated memory failed.
    newstack->min = NULL;
    newstack->top = NULL;
    return newstack;
}
struct linked_list *create_node(val) {
    struct linked_list *newnode  = (struct linked_list *) malloc(sizeof(struct linked_list));
    if(!newnode) return NULL;
    newnode->val = val;
    newnode->next = NULL;
    return newnode;
}
void insert_min_node(struct linked_list *node, struct linked_list *node2) {
    struct linked_list *pre = node;
    struct linked_list *curr = node->next;
    while (curr && curr->val < node2->val) {
        curr = curr->next;
        pre = pre->next;
    }
    pre->next = node2;
    node2->next = curr;
}

void minStackPush(MinStack* obj, int val) {
    struct linked_list *node = create_node(val);
    struct linked_list *node2 = create_node(val);
    if (!obj->top && !obj->min) {
        obj->min = node2;
    } else {
        if (obj->min->val > val) {
            node2->next = obj->min;
            obj->min = node2;
        } else {
            insert_min_node(obj->min, node2);
        }
    }
    node->next = obj->top;
    obj->top = node;
    printf("obj->top->val %d\n",obj->top->val);
    return;
}

void delete_min_node(struct linked_list *node, int target) {
    struct linked_list *tmpnode = node->next;
    struct linked_list *prenode = node;

    while (tmpnode->val != target) {
        tmpnode = tmpnode->next;
        prenode = prenode->next;
    }
    prenode->next = tmpnode->next;
    free(tmpnode);
    return;
}
void minStackPop(MinStack* obj) {
    if (!obj->top) {
        printf("This stack is empty.\n");
    }
    if (obj->min->val == obj->top->val) {
        struct linked_list *tmp_min = obj->min;
        obj->min = obj->min->next;
        free(tmp_min);
    } else {
        //delete_node
        delete_min_node(obj->min, obj->top->val);
    }
    // free node by tmp.
    struct linked_list *tmp = obj->top;
    obj->top = obj->top->next;
    free(tmp);
}

int minStackTop(MinStack* obj) {
    if (!obj->top) {
        printf("This stack is empty.\n");
        return -1;
    }
    return obj->top->val;
}

int minStackGetMin(MinStack* obj) {
    if (!obj->top) return -1;
    return obj->min->val;
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/