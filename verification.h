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

queue branch_verpre(tree* root){
  queue q;
  create_queue(&q);
  if (root!=NULL)
  {
      enqueue(&q,root);
      //printf("| %d |",value(root));
      branch_verpre(fg(root));
      branch_verpre(fd(root));
  }
  return q;
}

