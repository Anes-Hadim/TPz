#include <time.h>
#include"./traversal_methods.h"

tree* create_tree(tree* root);
void reset_visited(tree* node);

tree* create_tree(tree* root){
  int val;
  srand(time(NULL));
  for (int i = 0; i < 10; i++)
  {
    val=rand()%1000;
    root=insert(root,val);
  }
  return root;
}

void reset_visited(tree* node) {
  if (node!=NULL) {
    ass_visited(node,false);
    reset_visited(fg(node));
    reset_visited(fd(node));
  }
}

void branch_verpre(tree* root,tree tab[],int* index){
  if (root!=NULL)
  {
      tab[*index]=*root;
      (*index)++;
      //printf("| %d |",value(root));
      branch_verpre(fg(root),tab,index);
      branch_verpre(fd(root),tab,index);
  }
}


void branch_trav(tree tab[],int size){
  tree* node;
  stack s;
  create_stack(&s);
  for (int i = 0; i < size; i++)
  {
    push(&s,(tab+i));
    if (tab[i].fg==NULL && tab[i].fd==NULL)
    {
      while (!empty_stack(s))
      {
      pop(&s,&node);
      printf("%d |",value(node));
      }
    }
  }
}

void preorder(tree* root){     // <Root> <left> <Right>
     if (root!=NULL)
     {
      printf("| %d |",value(root));
      preorder(fg(root));
      preorder(fd(root));
     }
}

