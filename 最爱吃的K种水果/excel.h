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
	assert(r != 0);	// ���汣֤һ��������� fruit �ظ���ֵ

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
	// �����и����� Set
	// 1. ˳���
	// 2. ����������
	// 3. ��ϣ��
	// �������ǣ��������������˳��������
	// �˴�ǿ���ö���������
	struct Node *root = NULL;

	for (int i = 0; i < size; i++) {
		char *fruit = fruits[i];

		struct ResultItem *item = Find(root, fruit);
		if (item != NULL) {
			// ����Ѿ��й������ִ��� + 1
			item->count++;
		}
		else {
			// ���û�г��ֹ����Ž�ȥ�������� 1 ��
			Insert(&root, fruit);
		}
	}

	// ǰ������ķ�ʽȡ����
	struct ResultItem *result = (struct ResultItem *)malloc(4 * sizeof(struct ResultItem));
	PreOrder(result, root);

	*pResultSize = 4;
	return result;
}

void ArrayAdjustDown(struct ResultItem array[], int size, int root)
{
	int parent = root;

	while (1) {
		// ���ж���û�к��ӣ�Ҷ�ӽ�㣩
		// ����Ƕ�ȥ��	-> ���ӵ��±��Ƿ�Խ��
		// ֻҪ�ж����ӵ��±꣨��Ϊ����ȫ������)
		int left = parent * 2 + 1;
		if (left >= size) {
			// Խ�磬û�����ӣ�Ҳ�϶�û���Һ���
			return;
		}

		// һ��������
		int maxChild = left;
		if (2 * parent + 2 < size && array[2 * parent + 2].count < array[left].count) {
			// ǰһ���������ж��Һ�����û��
			// ��һ�������ж����Һ����Ƿ�����Ӵ�
			maxChild = 2 * parent + 2;
		}

		if (array[parent].count < array[maxChild].count) {
			return;
		}

		// ���� root �� maxChild �±����ڵ�ֵ
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

	// result �ж��ٸ�Ԫ��, result_size ��
	struct ResultItem *result = StaticsFruitCount(favor_fruits, favor_size, &result_size);

	// topk �ж��ٸ�Ԫ�أ��𰸾��� k ��
	struct ResultItem *topk = TopK(result, result_size, 2);

	for (int i = 0; i < 2; i++) {
		printf("%s %d\n", topk[i].fruit, topk[i].count);
	}
}