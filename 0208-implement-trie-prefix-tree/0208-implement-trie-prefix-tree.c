
struct node {
    char *string;
    struct node *next;
};

typedef struct {
    struct node *top;
} Trie;


Trie* trieCreate() {
    Trie* newtrie = (Trie*)malloc(sizeof(Trie));
    if (!newtrie) {
        return NULL;
    }
    newtrie->top = NULL;
    return newtrie;
}

struct node *createNode(char* word) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (!newnode) return NULL;
    newnode->string = (char *) malloc(sizeof(char)* (strlen(word)+1));
    strcpy(newnode->string, word);
    newnode->next = NULL;
    return newnode;
}

void trieInsert(Trie* obj, char* word) {
    if (obj == NULL) return;
    struct node * node = createNode(word);
    if (obj->top == NULL) {
        obj->top = node;
    } else {
        node->next = obj->top;
        obj->top = node;
    }
}

bool trieSearch(Trie* obj, char* word) {
    struct node * runnode = obj->top;
    printf("word = %s.\n", word);
    while (runnode) {
        printf("runnode->string = %s.\n", runnode->string);
        if (strcmp(runnode->string, word) == 0) {
            return true;
        }
        runnode = runnode->next;
    }
    return false;
}

bool trieStartsWith(Trie* obj, char* prefix) {
    int i = 0;
    if (obj == NULL) {
        return false;
    }
    struct node * runnode = obj->top;
    while (runnode) {
        while(prefix[i] != '\0') {
            if (runnode->string[i] == prefix[i]) {
                i++;
            } else {
                break;
            }
        }
        if (prefix[i] == '\0')
            return true;
        i = 0;
        runnode = runnode->next;
    }
    return false;
}

void trieFree(Trie* obj) {
    if (obj == NULL) {
        return;
    }
    struct node * topnode = obj->top;
    while (topnode) {
        struct node * tmp = topnode;
        topnode = topnode->next;
        free(tmp->string);
        free(tmp);
    }
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/