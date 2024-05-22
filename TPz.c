#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#include"./verification.h"


int main()
{
 
  tree tab[100];

  tree* root=NULL;

  // root=create_tree(root);
  // print_tree(root,0);

//   root=insert(root,45);
//   root=insert(root,20);
//   root=insert(root,10);
//   root=insert(root,35);
//   root=insert(root,65);
//   root=insert(root,55);
//   root=insert(root,50);
//   root=insert(root,58);
//   root=insert(root,56);
//   root=insert(root,57);
//   root=insert(root,60);
//   root=insert(root,62);
//   root=insert(root,85);
//   root=insert(root,75);
//   root=insert(root,95);
//   root=insert(root,90);
//   root=insert(root,88);
//   root=insert(root,98);
// 

  root=insert(root,328);
  root=insert(root,287);
  root=insert(root,302);
  root=insert(root,956);
  root=insert(root,407);
  root=insert(root,574);
  root=insert(root,704);
  root=insert(root,884);
  root=insert(root,969);
  root=insert(root,960);
  print_tree(root,0);


  branche_trav_L(root);
  reset_visited(root);
  printf("\n\n\n\n\n\n\n");

  // branche_trav_R(root);
  // reset_visited(root);
  // printf("\n\n\n\n\n\n\n");

  // leaf_trav_L(root);
  // reset_visited(root);
  // printf("\n\n\n\n\n\n\n");

  // leaf_trav_R(root);

  // free_tree(root);
  preorder(root);
  printf("\n\n");
  int ind=0;
  branch_verpre(root,tab,&ind);
  for (int i = 0; i < 10; i++)
  {
    printf("%d |", tab[i].val);
  }

  printf("\n\n\n\n\n\n");

  branch_trav(tab,10);

  return 0;
}