#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>

//tree 
//----------------------------------------------------------------

typedef struct tree {
  int val;
  struct tree* fg;
  struct tree* fd;
  bool visited;
}tree;

void create_node(tree** node) {
  *node=(tree *)malloc(sizeof(tree));
}

void ass_fg(tree* parent,tree* fg) {
  parent->fg=fg;
}

void ass_fd(tree* parent,tree* fd) {
  parent->fd=fd;
}

void ass_val(tree* node,int val) {
  node->val=val;
}

void ass_visited(tree* node,bool vis) {
  node->visited=vis;
}

tree* fg(tree* node) {
  return node->fg;
}

tree* fd(tree* node) {
  return node->fd;
}

int value(tree* node) {
  return node->val;
}

bool visited(tree* node) {
  return node->visited;
}

//--------------------------------------------------------
//BST
//--------------------------------------------------------

tree* insert(tree* node,int val) {
  if (node==NULL) {
    tree* newNode;
    create_node(&newNode);
    ass_val(newNode,val);
    ass_fd(newNode,NULL);
    ass_fg(newNode,NULL);
    ass_visited(newNode,false);
    return newNode;
  } else if (value(node)<val) {
    ass_fd(node,insert(fd(node),val));
  } else {
    ass_fg(node,insert(fg(node),val));
  }
  return node;
}

bool leaf(tree* node) {
  return fg(node)==NULL && fd(node)==NULL;
}

tree* delete(tree* root,int val) {
  if (root==NULL) {
    return root;
  }
  if (val<value(root)) {
    ass_fg(root,delete(fg(root),val));
  } else if (val>value(root)) {
    ass_fd(root,delete(fd(root),val));
  } else {
    if (leaf(root)) {
      free(root);
      root=NULL;
    } else if (fg(root)==NULL) {
      tree* temp=root;
      root=fd(root);
      free(temp);
    } else if (fd(root)==NULL) {
      tree* temp=root;
      root=fg(root);
      free(temp);
    } else {
      tree* p=fd(root);
      while (fg(p)!=NULL) {
        p=fg(p);
      }
      ass_val(root,value(p));
      ass_fd(root,delete(fd(root),value(p)));
    }
  }
  return root;
}


bool search_recursive(tree* node,int val) {
  if (node==NULL) {
    return false;
  } else if(value(node)==val){
    return true;
  } else {
    if (value(node)<val) {
      return search_recursive(fd(node),val);
    } else {
      return search_recursive(fg(node),val);
    }
  }
}

void print_tree(tree *root, int space)
{
  if (root == NULL)
  {
    return;
  }

  space += 10;
  print_tree(fd(root), space);

  printf("\n");
  for (int i = 10; i < space; i++)
  {
    printf(" ");
  }

  printf("%d\n", value(root));

  print_tree(fg(root), space);
}

//---------------------------------------------------------------------
//queue
//---------------------------------------------------------------------


typedef struct qc {
  tree* node;
  struct qc* next;
}qc;

void allocate_qc(qc** p) {
  *p=(qc*)malloc(sizeof(qc));
}

tree* value_qc(qc* p) { //give the value of a cell
  return p->node;
}

qc* next_qc(qc* p) { //give the next cell pointer
  return p->next;
}

void ass_val_qc(qc*p,tree* v) { //assigne a value to the cell
  p->node=v;
}

void ass_adr_qc(qc* p,qc* q) { //assigne a next value to the cell
  p->next=q;
}

typedef struct queue {
  qc* head;
  qc* tail;
}queue;

void create_queue(queue* q) {
  q->head=NULL;
}

bool empty_queue(queue q) {
  return q.head==NULL;
}

void enqueue(queue* q,tree* val) {
  qc* new_cell;
  allocate_qc(&new_cell);
  ass_val_qc(new_cell,val);
  ass_adr_qc(new_cell,NULL);
  if (empty_queue(*q)) {
    q->head=new_cell;
  } else {
    ass_adr_qc(q->tail,new_cell);
  }
  q->tail=new_cell;
}

void dequeue(queue* q,tree** val) {
  if(!empty_queue(*q)) {
    qc* temp=q->head;
    *val=value_qc(temp);
    q->head=next_qc(q->head);
    free(temp);
  } else {
    printf("underflow\n");
    *val=NULL;
  }
}

//---------------------------------------------------------------
//stack
//---------------------------------------------------------------

typedef struct stack{
  qc* top;
}stack;

void print_stack(stack s) {
  qc* p=s.top;
  while (p!=NULL) {
    printf("%2d |",value_qc(p));
    p=next_qc(p);
  }
  printf("\n");
}

void create_stack(stack* s) {
  s->top=NULL;
}

bool empty_stack(stack s) {
  return s.top==NULL;
}

void push(stack* s,tree* val) {
  qc* new_cell;
  allocate_qc(&new_cell);
  ass_val_qc(new_cell,val);
  ass_adr_qc(new_cell,s->top);
  s->top=new_cell;
}

void pop(stack* s,tree** val) {
  if(!empty_stack(*s)) {
    *val=value_qc(s->top);
    qc* temp=s->top;
    s->top=next_qc(s->top);
    free(temp);
  } else {
    printf("underflow\n");
  }
}

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

void print_queue(queue q) {
  tree* node;
  while (!empty_queue(q)) {
    dequeue(&q,&node);
    printf("%2d |",value(node));
  }
  printf("\n");
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
  }
  print_queue(q);
}


int main()
{
  tree *example1 = NULL;
  // example1 = insert(example1, 45);
  // example1 = insert(example1, 20);
  // example1 = insert(example1, 10);
  // example1 = insert(example1, 35);
  // example1 = insert(example1, 65);
  // example1 = insert(example1, 55);
  // example1 = insert(example1, 50);
  // example1 = insert(example1, 58);
  // example1 = insert(example1, 56);
  // example1 = insert(example1, 57);
  // example1 = insert(example1, 60);
  // example1 = insert(example1, 62);
  // example1 = insert(example1, 85);
  // example1 = insert(example1, 75);
  // example1 = insert(example1, 95);
  // example1 = insert(example1, 90);
  // example1 = insert(example1, 88);
  // example1 = insert(example1, 98);
  example1 = insert(example1, 15);
  example1 = insert(example1, 3);
  example1 = insert(example1, 9);
  example1 = insert(example1, 5);
  example1 = insert(example1, 11);

  printf("\nTesting functions with Example 1:\n");

  print_tree(example1, 0);
  branche_trav_L(example1);
  

  return 0;
}