#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#include"./abstract_machines.h"



void iter_stack(stack* s,queue* q) {
  qc* head=(*s).top;
  while (head!=NULL) {
    tree* node=value_qc(head);
    if (!visited(node))
    {
      ass_visited(node,true);
      enqueue(&(*q),value_qc(head));
    }
    head=next_qc(head);
  }
}

void branche_trav_L(tree* node) {
  stack s;
  queue q;
  if (node!=NULL) {
    create_stack(&s);
    create_queue(&q);
    while (!empty_stack(s) || node!=NULL) {
      while (node!=NULL) {
        push(&s,node);
        if (fg(node)==NULL && fd(node)!=NULL) {
          node=fd(node);
          push(&s,node);
        }
        node=fg(node);
      }
      iter_stack(&s,&q);
      pop(&s,&node);
      node=fd(node);
    }
    print_queue(q);
  }
}

void branche_trav_R(tree* node) {
  stack s;
  queue q;
  if (node!=NULL) {
    create_stack(&s);
    create_queue(&q);
    while (!empty_stack(s) || node!=NULL) {
      while (node!=NULL) {
        push(&s,node);
        if (fg(node)!=NULL && fd(node)==NULL) {
          node=fg(node);
          push(&s,node);
        }
        node=fd(node);
      }
      iter_stack(&s,&q);
      pop(&s,&node);
      node=fg(node);
    }
    print_queue(q);
  }
}

void leaf_trav(tree* node){
  stack s;
  queue q;
  tree* temp=node;
  if (node!=NULL) {
    create_stack(&s);
    create_queue(&q);
    while(visited(fg(temp))==false && visited(fd(temp))==false){
      node=temp;
    while (!empty_stack(s) || node!=NULL) {
      while (node!=NULL) {
        push(&s,node);
        if (visited(fg(node))==false)
        {
          node=fg(node);
        }
        else{
          node=NULL;
        }
      }
      pop(&s,&node);
      if (leaf(node) && visited(node)!=true)
      {
        enqueue(&(q),node);
        ass_visited(node,true);
      }
      if (visited(node)==false)
      {
        node=fd(node);
      }
      else if (fd(node)==NULL){
        node=NULL;
      }
    }
    create_stack(&s);
  }
  }
  print_queue(q);
}

bool children_visited(tree* node) {
  if (leaf(node)) {
    return true;
  } else if (fg(node)!=NULL && fd(node)==NULL) {
    return visited(fg(node));
  } else if (fg(node)==NULL && fd(node)!=NULL) {
    return visited(fd(node));
  } else {
    return visited(fg(node)) && visited(fd(node));
  }
}

void leaf_trav_L(tree* root){
  stack s;
  queue q;
  tree* node=root;
  bool temp=false,ignore=false;
  if (node!=NULL) {
    create_queue(&q);
    create_stack(&s);
    while (!visited(root)) {
      while (!empty_stack(s) || node!=NULL) {
        while (node!=NULL) {
          push(&s,node);
          node=fg(node);
        }
        pop(&s,&node);
        temp=visited(node);
        if (!ignore && (leaf(node) && !visited(node)) || (!visited(node) && children_visited(node))) {
          ass_visited(node,true);
          enqueue(&q,node);
        }
        if (temp!=visited(node)) {
          ignore=true;
        } else {
          ignore=false;
        }
        node=fd(node);
      }
      node=root;
    }
    print_queue(q);
  }
}



int main()
{
  tree *example1 = NULL;
  example1 = insert(example1, 45);
  example1 = insert(example1, 20);
  example1 = insert(example1, 10);
  example1 = insert(example1, 35);
  example1 = insert(example1, 65);
  example1 = insert(example1, 55);
  example1 = insert(example1, 50);
  example1 = insert(example1, 58);
  example1 = insert(example1, 56);
  example1 = insert(example1, 57);
  example1 = insert(example1, 60);
  example1 = insert(example1, 62);
  example1 = insert(example1, 85);
  example1 = insert(example1, 75);
  example1 = insert(example1, 95);
  example1 = insert(example1, 90);
  example1 = insert(example1, 88);
  example1 = insert(example1, 98);
  // example1 = insert(example1, 15);
  // example1 = insert(example1, 3);
  // example1 = insert(example1, 9);
  // example1 = insert(example1, 5);
  // example1 = insert(example1, 11);

  printf("\nTesting functions with Example 1:\n");

  print_tree(example1, 0);
  // branche_trav_L(example1);
  // branche_trav_R(example1);
  // leaf_trav(example1);
  //leaf_trav_L(example1);
  leaf_trav_Lv2(example1);

  return 0;
}