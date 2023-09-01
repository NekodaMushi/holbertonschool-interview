#include "binary_trees.h"
#include <stdlib.h>

heap_t *heapSort(heap_t *node);

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to insert
 * Return: Pointer to the inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{
heap_t *new_node, *node = *root;

if (*root == NULL)
{
*root = binary_tree_node(NULL, value);
return (*root);
}


heap_t **queue = malloc(100 * sizeof(heap_t *));
int q_start = 0, q_end = 0;

queue[q_end++] = *root;

while (q_start < q_end)
{
node = queue[q_start++];
if (!node->left)
{
new_node = binary_tree_node(node, value);
node->left = new_node;
break;
}
else if (!node->right)
{
new_node = binary_tree_node(node, value);
node->right = new_node;
break;
}
else
{
queue[q_end++] = node->left;
queue[q_end++] = node->right;
}
}
free(queue);

return heapSort(new_node);
}

/**
 * heapSort - Swap node and parent
 * @node: The node to heapify
 * Return: The node after swap
 */
heap_t *heapSort(heap_t *node)
{
int temp;
while (node->parent && node->n > node->parent->n)
{
temp = node->n;
node->n = node->parent->n;
node->parent->n = temp;

node = node->parent;
}
return node;
}
