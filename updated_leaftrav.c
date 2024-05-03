void enqueues(queue* q,tree* val) {
  qc* new_cell;
  if (val==NULL)
  {
    return;
  }
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

// the problem is the infinite loop but i think this method is true




void print(queue q) {
  tree* node;
  while (!empty_queue(q)) {
    dequeue(&q,&node);
    if ((leaf(node)) || (visited(fd(node)) && visited(fg(node))))
    {
       printf("%2d |",value(node));
    }
  }
  // printf("\n");
}





void leaf_trav_Lv2(tree* node){
  queue q;
  tree* node1=node;
  while(visited(fg(node1))==false && visited(fd(node1))==false){
   create_queue(&q);
   enqueues(&q,node);
   while(!empty_queue(q)){
       dequeue(&q,&node);
       enqueues(&q,fd(node));
       enqueues(&q,fg(node));
   }
  print(q);
}
}