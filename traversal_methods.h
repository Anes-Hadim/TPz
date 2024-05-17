#include"./abstract_machines.h"

void iter_stack(stack* s, queue* q);
void branche_trav_L(tree* node);
void branche_trav_R(tree* node);
bool children_visited(tree* node);
void leaf_trav_L_recursive(tree* node);
void leaf_trav_L(tree* root);
void leaf_trav_R_recursive(tree* node);
void leaf_trav_R(tree* root);
void branch_ver(tree* root);

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
        } else {
          node=fg(node);
        }
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

void leaf_trav_L_recursive(tree* node) {
  if (node!=NULL) {
    bool ignore=false;
    bool temp1 = fg(node)==NULL ?  true : visited(fg(node));
    bool temp2 = fd(node)==NULL ?  true : visited(fd(node));
    leaf_trav_L_recursive(fg(node));
    leaf_trav_L_recursive(fd(node));
    if ((fg(node)!=NULL && temp1!=visited(fg(node))) || (fd(node)!=NULL && temp2!=visited(fd(node)))) {
      ignore=true;
    } else {
      ignore=false;
    }
    if (!ignore && ((leaf(node) && !visited(node)) || (!visited(node) && children_visited(node)))) {
      ass_visited(node,true);
      printf("%2d |",value(node));
    }
  } 
}

void leaf_trav_L(tree* root) {
  while (!visited(root)) {
    leaf_trav_L_recursive(root);
  }
}

void leaf_trav_R_recursive(tree* node) {
  if (node!=NULL) {
    bool ignore=false;
    bool temp1 = fg(node)==NULL ?  true : visited(fg(node));
    bool temp2 = fd(node)==NULL ?  true : visited(fd(node));
    leaf_trav_R_recursive(fd(node));
    leaf_trav_R_recursive(fg(node));
    if ((fg(node)!=NULL && temp1!=visited(fg(node))) || (fd(node)!=NULL && temp2!=visited(fd(node)))) {
      ignore=true;
    } else {
      ignore=false;
    }
    if (!ignore && ((leaf(node) && !visited(node)) || (!visited(node) && children_visited(node)))) {
      ass_visited(node,true);
      printf("%2d |",value(node));
    }
  } 
}

void leaf_trav_R(tree* root) {
  while (!visited(root)) {
    leaf_trav_R_recursive(root);
  }
}


void branch_ver(tree* root){
  stack s;
  create_stack(&s);
  queue q;
  create_queue(&q);
  tree* node=root;
    while(!visited(root)){
      node=root;
      while(node!=NULL){
        push(&s,node);
        if ((fg(node)==NULL || visited(fg(node))==true) && fd(node)!=NULL)
        {
          node=fd(node);
          push(&s,node);
        }
        node=fg(node);
      }
      while (!empty_stack(s))
      {
        pop(&s,&node);
        if (leaf(node) || children_visited(node))
        {
            ass_visited(node,true);
        }
        enqueue(&q,node);
      }
    }
    print_queue(q);
}