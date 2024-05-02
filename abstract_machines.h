#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tree {
  int val;
  struct tree* fg;
  struct tree* fd;
  bool visited;
}tree;

typedef struct qc {
  tree* node;
  struct qc* next;
}qc;

typedef struct queue {
  qc* head;
  qc* tail;
}queue;

typedef struct stack{
  qc* top;
}stack;

// Function headers

void create_node(tree** node);
void ass_fg(tree* parent, tree* fg);
void ass_fd(tree* parent, tree* fd);
void ass_val(tree* node, int val);
void ass_visited(tree* node, bool vis);
tree* fg(tree* node);
tree* fd(tree* node);
int value(tree* node);
bool visited(tree* node);

tree* insert(tree* node, int val);
bool leaf(tree* node);
tree* delete(tree* root, int val);
bool search_recursive(tree* node, int val);
void print_tree(tree* root, int space);

void allocate_qc(qc** p);
tree* value_qc(qc* p);
qc* next_qc(qc* p);
void ass_val_qc(qc* p, tree* v);
void ass_adr_qc(qc* p, qc* q);


void create_queue(queue* q);
bool empty_queue(queue q);
void enqueue(queue* q, tree* val);
void dequeue(queue* q, tree** val);


void print_stack(stack s);
void create_stack(stack* s);
bool empty_stack(stack s);
void push(stack* s, tree* val);
void pop(stack* s, tree** val);
void print_queue(queue q);

//tree 
//----------------------------------------------------------------

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

void print_queue(queue q) {
  tree* node;
  while (!empty_queue(q)) {
    dequeue(&q,&node);
    printf("%2d |",value(node));
  }
  printf("\n");
}