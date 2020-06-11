public class c001{
    public class linkedlist{
        public class Node{
            int data;
            Node next=null;
            public Node(int data){
                this.data=data;
            }
        }
        Node head=null;
        Node tail=null;
        int size=0;
        //Basic functions==================================================================
        public int size(){
            return this.size;
        }

        public boolean isEmpty(){
            return this.size==0;
        }

        @Override
        public String toString(){                //overriding the toString method()
            Node curr=this.head;
            String str="";
            while(curr!=null){
                str+=(curr.data + " -> ");
                curr=curr.next;
            }
            return str;
        }

        public Node getNodeAt(int pos){   //ensuring that pos is a valid position
            Node curr=head;
            while(pos-->0){
                curr=curr.next;
            }
            return curr;
        }


        //add element========================================================================
        private void addFirst(Node node){            
            if(size==0){
                head=node;
                tail=node;
            }
            else{
                node.next=head;
                head=node;
            }
            size++;
        }
        public void addFirstNode(int data){
            Node node=new Node(data);
            addFirst(node);
        }
        //===============================
        private void addLast(Node node){
            if(size==0){
                head=node;
                tail=node;
            }
            else{
                tail.next=node;
                tail=node;
            }       
            size++;   
        }
        public void addLastNode(int data){
            Node node=new Node(data);
            addLast(node);
        }
        //==============================
        private void addAt(Node node,int pos){

            //code

            size++;
        }
        public void addAtPos(int data,int pos){
            Node node=new Node(data);
            addAt(node,pos);
        }
        //===============================
        //remove element=======================================================================
        private void removeFirst(){            
            if(head==null){
                System.out.print("Empty");
            }
            else{
                Node rm=head;
                head=head.next;
                rm.next=null;
            }
            size--;
        }
        public void removeFirstNode(){
            removeFirst();
        }
        //================================
        private void removeLast(){            
            if(tail==null){
                System.out.print("Empty");
            }
            if(size(head)==1) head==null;tail==null;
            else{
                Node curr=head;
                while(size-->2){
                    curr=curr.next;
                }
                tail=curr;
                curr.next=null;
            }
            size--;
        }
        public void removeLastNode(){
            removeLast();
        }
        //====================================
        private void removeAt(int pos){   
            //exception case code 
            
            Node node=getNodeAt(pos-1);
            Node rn=node.next;
            node.next=node.next.next;
            rn.next=null;
            size--;
        }
        public void removeAtPos(int pos){
            removeAt(pos);
        }
        //====================================
        //find element==========================================================================


    }
}