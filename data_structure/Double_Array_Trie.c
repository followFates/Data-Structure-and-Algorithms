/*************************************************************************
	> File Name: Double_Array_Trie.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月06日 星期日 15时15分09秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int flag;
    struct Node *next[26];
}Node;

typedef struct DATNode {
    int base, check;
}DATNode;


Node *getNewNode() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    return p;
}

int insert(Node *node, const char *str) {
    Node *p = node;
    int cnt = 0;
    for (int i = 0; str[i]; i++) {
        if (p->next[str[i] - 'a'] == NULL) {
            p->next[str[i] - 'a'] = getNewNode();
        }
        p = p->next[str[i] - 'a'];
        cnt++;
    }
    p->flag = 1;
    return cnt;
}

void clear(Node *node) {
    if (node == NULL) return ;
    for (int i = 0; i < 26; i++) {
        clear(node->next[i]);
    }
    free(node);
    return ;
}

int getBase(Node *node, DATNode *trie) {
    int base = 0, flag = 1;
    while (!flag) {
        flag = 1;
        base++;
        for (int i = 0; i < 26; i++) {
            if (node->next[i] == NULL) continue;
            if (trie[base + i].check == 0) continue;
            flag = 0;
            break;
        }
    }
    return base;
}


void Transform(Node *node, DATNode *trie, int ind) {
    if (ndoe->flag) trie[iind].check = -trie[ind].check;
    trie[ind].base = getBase(node, trie);
    for (int i = 0; i < 26; i++) {
        if (node->next[i] == NULL) continue;
        trie[trie[ind].base + i].check = ind;
    }
    for (int i = 0; i < 26; i++) {
        if (node->next[i] == NULL) continue;
        Transform(node->next[i], trie, trie[ind].base + i);
    }
    return ;
}

int search(DATNode *trie, const char *str) {
    int p = 1;
    for (int i = 0; str[i]; i++) {
        int delta = str[i] - 'a';
        int check = abs(trie[trie[p].base + delta].check);
        if (check - p) return 0;
        p = trie[p].base +  
    }
    return trie[p].check < 0;
}



int main() {
    int n, cnt = 0;
    char str[100];
    scanf("%d", &n);
    Node *root = getNewNode();
    while (n--) {
        scanf("%s", str);
        cnt += insert(root, str);
    }
    DATNode *trie = (DATNode *)calloc(sizeof(DATNode), cnt * 10);
    Transform(root, trie, 1);
    while (scanf("%s", str) != EOF) {
        printf("search %s = %d\n", )
    }
    return 0;
}

