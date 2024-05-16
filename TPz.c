#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#include"./verification.h"


int main()
{
  queue q;
  tree* root=NULL;

  root=create_tree(root);
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
  q=branch_verpre(root);
  print_queue(q);

  return 0;
}