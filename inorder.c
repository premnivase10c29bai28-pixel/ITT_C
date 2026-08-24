void traverse(struct TreeNode* root, int* result, int* index)
{
    if (root == NULL) 
    {
        return;
    }
    traverse(root->left, result, index);
    result[(*index)++] = root->val;
    traverse(root->right, result, index);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int *)malloc(100 * sizeof(int));
    int index = 0;
    traverse(root, result, &index);
    *returnSize = index;
    return result;
}
