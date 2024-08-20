/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

// create a hash table.
// initial it with 101 node.
struct Node **hash_table;

struct Node *dfs(struct Node *s) {
    if (s == NULL) return NULL;
    // deal with node recorded by hash table.
    if (hash_table[s->val]) {
        return hash_table[s->val];
    }

    // deal with node which is not recorded.
    struct Node *cloneNode = (struct Node *)malloc(sizeof(struct Node));
    cloneNode->val = s->val;
    cloneNode->numNeighbors = s->numNeighbors;
    //cloneNode->neighbors = s->neighbors;

    hash_table[cloneNode->val] = cloneNode;
    cloneNode->neighbors = (struct Node **)malloc(sizeof(struct Node*)*(cloneNode->numNeighbors));

    for (int i = 0; i < s->numNeighbors; i++) {
        cloneNode->neighbors[i] = dfs(s->neighbors[i]);
    }
    return cloneNode;
}

struct Node *cloneGraph(struct Node *s) {
	hash_table = (struct Node **) malloc(sizeof(struct Node *)*101);
    memset(hash_table, 0, sizeof(struct Node *)*101);
    return dfs(s);
}