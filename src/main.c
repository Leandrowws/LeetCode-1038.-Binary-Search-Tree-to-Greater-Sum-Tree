#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* right;
    struct TreeNode* left;
};

struct TreeNode* Inserir(struct TreeNode* root, int val) {
    if(root==NULL) {
        struct TreeNode* aux = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        aux->val = val;
        aux->left = NULL;
        aux->right = NULL;
        return aux;
    } else {
        if(val < root->val) {
            root->left = Inserir(root->left, val);
        } else {
            root->right = Inserir(root->right, val);
        }
        return root;
    }
}

void SomaArvore(struct TreeNode* root, int* soma) {
   if(root!=NULL) {
        SomaArvore(root->right, soma);
        (*soma) += root->val;
        root->val = *soma;
        SomaArvore(root->left, soma);
   }
}

struct TreeNode* bstToGst(struct TreeNode* root) {
   
    int soma = 0;

    SomaArvore(root, &soma);

    return root;
}

void Imprimir(struct TreeNode* root) {
    if(root!=NULL) {
        Imprimir(root->left);
        printf("%d ", root->val);
        Imprimir(root->right);
    }
}

int main() {
    
    struct TreeNode* arv = NULL;

    arv = Inserir(arv, 5);
    arv = Inserir(arv, 9);
    arv = Inserir(arv, 1);
    arv = Inserir(arv, 3);
    arv = Inserir(arv, 7);
    arv = Inserir(arv, 4);
    arv = Inserir(arv, 6);
    arv = Inserir(arv, 2);
    arv = Inserir(arv, 8);

    printf("Arvore antes: ");
    Imprimir(arv);

    arv = bstToGst(arv);

    printf("\nArvore depois: ");
    Imprimir(arv);

    return 0;
}
