#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <stdlib.h>
#include <stdio.h>

static char * fruits[] = {
	"apple", "pear", "banana", "orange"
};

int size = sizeof(fruits) / sizeof(char *);

void Generate()
{
	srand(20190711);
	for (int i = 0; i < 60; i++) {
		printf("    \"%s\", \n", fruits[rand() % size]);
	}
}

static char * favor_fruits[] = {
	"pear",
	"pear",
	"apple",
	"banana",
	"apple",
	"apple",
	"pear",
	"banana",
	"banana",
	"apple",
	"banana",
	"banana",
	"pear",
	"orange",
	"banana",
	"apple",
	"apple",
	"orange",
	"apple",
	"orange",
	"orange",
	"banana",
	"pear",
	"banana",
	"pear",
	"pear",
	"apple",
	"apple",
	"orange",
	"orange",
	"pear",
	"banana",
	"apple",
	"orange",
	"banana",
	"banana",
	"orange",
	"pear",
	"orange",
	"pear",
	"pear",
	"apple",
	"apple",
	"orange",
	"apple",
	"banana",
	"orange",
	"pear",
	"banana",
	"apple",
	"apple",
	"apple",
	"banana",
	"banana",
	"pear",
	"pear",
	"apple",
	"pear",
	"banana",
	"apple"
};

int favor_size = sizeof(favor_fruits) / sizeof(char *);

struct ResultItem {
	char fruit[20];	// key
	int count;		// value
};


struct Node {
	struct ResultItem data;
	struct Node *left;
	struct Node *right;
};

#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

void Insert(struct Node **root, char *fruit)
{
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	strcpy(node->data.fruit, fruit);
	node->data.count = 1;
	node->left = node->right = NULL;

	if (*root == NULL) {
		*root = node;
		return;
	}

	int r = strcmp((*root)->data.fruit, fruit);
	assert(r != 0);	// 外面保证一定不会插入 fruit 重复的值

	if (r < 0) {
		Insert(&(*root)->left, fruit);
	}
	else {
		Insert(&(*root)->right, fruit);
	}
}


struct ResultItem * Find(struct Node *root, char *fruit)
{
	if (root == NULL) {
		return NULL;
	}

	int r = strcmp(root->data.fruit, fruit);
	if (r == 0) {
		return &root->data;	// ?
	}

	if (r < 0) {
		return Find(root->left, fruit);
	}
	else {
		return Find(root->right, fruit);
	}
}

void PreOrder(struct ResultItem * result, struct Node *root)
{
	if (root == NULL) { return; }

	int i;
	switch (root->data.fruit[0]) {
	case 'a':
		// apple
		i = 0;
		break;
	case 'b':
		// banana
		i = 1;
		break;
	case 'o':
		// orange
		i = 2;
		break;
	case 'p':
		// pear
		i = 3;
		break;
	}

	result[i] = root->data;
	printf("%s %d\n", root->data.fruit, root->data.count);
	
	PreOrder(result, root->left);
	PreOrder(result, root->right);
}

struct ResultItem * StaticsFruitCount(char *fruits[], int size, int *pResultSize)
{
	// 假设有个集合 Set
	// 1. 顺序表
	// 2. 二叉搜索树
	// 3. 哈希表
	// 正常考虑，这个数据量，有顺序表更合适
	// 此处强行用二叉搜索树
	struct Node *root = NULL;

	for (int i = 0; i < size; i++) {
		char *fruit = fruits[i];

		struct ResultItem *item = Find(root, fruit);
		if (item != NULL) {
			// 如果已经有过，出现次数 + 1
			item->count++;
		}
		else {
			// 如果没有出现过，放进去，次数是 1 次
			Insert(&root, fruit);
		}
	}

	// 前序遍历的方式取出来
	struct ResultItem *result = (struct ResultItem *)malloc(4 * sizeof(struct ResultItem));
	PreOrder(result, root);

	*pResultSize = 4;
	return result;
}

void ArrayAdjustDown(struct ResultItem array[], int size, int root)
{
	int parent = root;

	while (1) {
		// 先判断有没有孩子（叶子结点）
		// 数组角度去想	-> 孩子的下标是否越界
		// 只要判断左孩子的下标（因为是完全二叉树)
		int left = parent * 2 + 1;
		if (left >= size) {
			// 越界，没有左孩子，也肯定没有右孩子
			return;
		}

		// 一定有左孩子
		int maxChild = left;
		if (2 * parent + 2 < size && array[2 * parent + 2].count < array[left].count) {
			// 前一个条件是判断右孩子有没有
			// 后一个条件判读是右孩子是否比左孩子大
			maxChild = 2 * parent + 2;
		}

		if (array[parent].count < array[maxChild].count) {
			return;
		}

		// 交换 root 和 maxChild 下标所在的值
		struct ResultItem t = array[parent];
		array[parent] = array[maxChild];
		array[maxChild] = t;

		parent = maxChild;
	}
}

struct ResultItem * TopK(struct ResultItem *result, int size, int k)
{
	struct ResultItem *heap = (struct ResultItem *)malloc(sizeof(struct ResultItem) * k);
	assert(heap);

	for (int i = 0; i < k; i++) {
		heap[i] = result[i];
	}

	for (int j = (k - 2) / 2; j >= 0; j--) {
		ArrayAdjustDown(heap, k, j);
	}

	for (int m = k; m < size; m++) {
		if (result[m].count > heap[0].count) {
			heap[0] = result[m];
			ArrayAdjustDown(heap, k, 0);
		}
	}

	return heap;
}

void FindTopK()
{
	int result_size;

	// result 有多少个元素, result_size 个
	struct ResultItem *result = StaticsFruitCount(favor_fruits, favor_size, &result_size);

	// topk 有多少个元素，答案就是 k 个
	struct ResultItem *topk = TopK(result, result_size, 2);

	for (int i = 0; i < 2; i++) {
		printf("%s %d\n", topk[i].fruit, topk[i].count);
	}
}