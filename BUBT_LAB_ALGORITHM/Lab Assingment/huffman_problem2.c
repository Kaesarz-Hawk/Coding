#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
};

int totalBits = 0;
int totalChars = 0;

struct Node* createNode(char ch, int freq) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->ch = ch;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

int findMin(struct Node* arr[], int n, int skip) {
    int minIdx = -1;
    int i;
    for (i = 0; i < n; i++) {
        if (i == skip) continue;
        if (minIdx == -1 || arr[i]->freq < arr[minIdx]->freq)
            minIdx = i;
    }
    return minIdx;
}

struct Node* buildTree(char chars[], int freq[], int n) {
    struct Node* arr[MAX];
    int count = n;
    int i;
    for (i = 0; i < n; i++)
        arr[i] = createNode(chars[i], freq[i]);

    while (count > 1) {
        int i1 = findMin(arr, count, -1);
        int i2 = findMin(arr, count, i1);

        struct Node* parent = createNode('$', arr[i1]->freq + arr[i2]->freq);
        parent->left = arr[i1];
        parent->right = arr[i2];

        struct Node* newArr[MAX];
        int k = 0;
        for (i = 0; i < count; i++) {
            if (i != i1 && i != i2)
                newArr[k++] = arr[i];
        }
        newArr[k++] = parent;
        for (i = 0; i < k; i++)
            arr[i] = newArr[i];
        count = k;
    }
    return arr[0];
}

void traverse(struct Node* root, char code[], int depth) {
    if (root->left == NULL && root->right == NULL) {
        code[depth] = '\0';
        printf("%c : %s\n", root->ch, code);
        totalBits += root->freq * depth;
        totalChars += root->freq;
        return;
    }
    code[depth] = '0';
    traverse(root->left, code, depth + 1);
    code[depth] = '1';
    traverse(root->right, code, depth + 1);
}

int main() {
    char chars[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int n = sizeof(chars) / sizeof(chars[0]);
    char code[MAX];

    struct Node* root = buildTree(chars, freq, n);

    printf("Character : Huffman Code\n");
    traverse(root, code, 0);

    printf("\nTotal bits in encoded message = %d\n", totalBits);
    printf("Average code length = %.2f\n", (float)totalBits / totalChars);

    return 0;
}
