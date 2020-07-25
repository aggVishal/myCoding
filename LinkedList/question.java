// Linked List Leetcode Questions


public class question {

    public class ListNode {
        int val;
        ListNode next;

        ListNode(int val) {
            this.val = val;
        }

    }

    

// leetcode 876 Middle of the Linked list
    public ListNode middleNode(ListNode head) {              // Upper Bound
        if(head==null||head.next==null)return head;
        ListNode fast=head;
        ListNode slow=head;
        while(fast!=null&&fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }
        return slow;      
    }
//class question:
    public ListNode middleNode2(ListNode head) {              //Lower Bound
        if(head==null)return head;
        ListNode fast=head;
        ListNode slow=head;
        while(fast.next!=null&&fast.next.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }
        return slow;      
    }

// leetcode 206
    public ListNode reverseList(ListNode head) {
        ListNode prev=null;
        ListNode curr=head;
        ListNode frw=head;
        while(curr!=null){   
            frw=curr.next;
            curr.next=prev;
            prev=curr;
            curr=frw;
        }
        return prev;        
    }

//reverseList2 : reverse data
    public ListNode reverseList2(ListNode head){
        ListNode curr=head;
        ListNode midNode=middleNode2(head);
        ListNode nhead=reverseList(midNode.next);
        midNode.next=null;
        ListNode curr1=nhead;
        while(curr!=null&&curr1!=null){
            int temp=curr.val;
            curr.val=curr1.val;
            curr1.val=temp;

            curr=curr.next;
            curr1=curr1.next            
        }
        nhead=reverseList(nhead);
        midNode.next=nhead;
    }

//leetcode 234  palindrome
    public boolean isPalindrome(ListNode head) {
        if(head==null||head.next==null)return true;
        ListNode mid=middleNode(head);
        ListNode nhead=mid.next;
        mid.next=null;
        nhead=reverseList(nhead);
        ListNode curr=head;
        ListNode curr1=nhead;
        while(curr1!=null&&curr!=null){
            if(curr.val!=curr1.val) return false;
            curr=curr.next;
            curr1=curr1.next;
        }
        return true;
    }


//leetcode 19 Remove nth node from last
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head==null)return null;
        ListNode prev=head;
        ListNode curr=head;
        while(n-->0){
            curr=curr.next;
        }
        if(curr==null)return prev.next;
        while(curr.next!=null){
            curr=curr.next;
            prev=prev.next;
        }
        prev.next=prev.next.next;
        return head;
    }


//leetcode 143 Reorder List
    public void reorderList(ListNode head) {
        if(head==null||head.next==null)return;
        ListNode mid=middleNode2(head);
        ListNode nhead=reverseList(mid.next);
        mid.next=null;
        ListNode curr=head;
        ListNode curr1=nhead;
        while(curr1!=null&&curr!=null){            
            ListNode f1=curr.next;
            ListNode f2=curr1.next;
            curr.next=curr1;
            curr1.next=f1;
            curr=f1;
            curr1=f2;
        }
    }


//class Question: based on leetcode 143
    public void reorder_inv(ListNode head){    //wrong
        if(head==null||head.next==null)return ;
        ListNode curr1=head;
        ListNode curr2=head.next;
        ListNode prev=null;
        while(curr2.next!=null&&curr1.next!=null){
            ListNode f1=curr2.next;
            ListNode f2=f1.next;

            curr1.next=f1;
            curr2.next=prev;
            prev=curr2;
            curr1=f1;
            curr2=f2;
        }
        if(curr1==null){
            curr1=prev;
        }
        else curr1.next=prev;
    }

//leetcode: 21 Merge two LL
public ListNode mergeTwoLists(ListNode l1, ListNode l2) {        
        ListNode c1=l1;
        ListNode c2=l2;
        ListNode head=new ListNode(-1);
        ListNode pre=head;
        while(c1!=null&&c2!=null){
            if(c1.val>c2.val){
                pre.next=c2;
                pre=pre.next;
                c2=c2.next;
            }
            else{
                pre.next=c1;
                pre=pre.next;
                c1=c1.next;
            }
            
        }
        if(c1==null){
            pre.next=c2;
        }
        else{
            pre.next=c1;
        }
        return head.next;
    }

//leetcode: 328  Odd Even Linked List
    public ListNode oddEvenList(ListNode head) {
        if(head==null||head.next==null)return head;
        ListNode curr1=head;
        ListNode curr2=head.next;
        ListNode c2=head.next;
        while(curr1.next!=null&&curr2.next!=null){
            ListNode f1=curr2.next;
            ListNode f2=f1.next;

            curr1.next=f1;
            curr2.next=f2;
            curr1=f1;
            curr2=f2;
        }
        if(curr2!=null){
            curr2.next=null;
            curr1.next=c2;
        }
        else curr1.next=c2;
        return head;
    }

//leetcode: 203
//leetcode: 83


//leetcode: 141 Linked List Cycle
    public boolean hasCycle(ListNode head) {
        if(head==null||head.next==null)return false;
        ListNode fast=head;
        ListNode slow=head;
        while(fast!=null&&fast.next!=null){
            fast=fast.next.next;
            slow=slow.next;
            if(fast==slow){
                return true;
            }
        }
        return false;       
    }
//leetcode: 142 Linked List Cycle II
    public ListNode detectCycle(ListNode head) {
        if(head==null||head.next==null)return null;
        ListNode fast=head;
        ListNode slow=head;
        ListNode c;
        while(fast!=null&&fast.next!=null){
            fast=fast.next.next;
            slow=slow.next;
            if(fast==slow){
                c=fast;
                slow=head;
                while(fast!=slow){
                    fast=fast.next;
                    slow=slow.next;
                }
                return fast;
            }
        }
        return null;
    }
//leetcode: 160 Intersection of Two Linked Lists
    public ListNode getIntersectionNode(ListNode head, ListNode headB) {
        if(headB==null)return null;
        ListNode curr=headB;
        while(curr.next!=null){
            curr=curr.next;
        }
        curr.next=headB;
        
        if(head==null||head.next==null){
            curr.next=null;
            return null;
        }
        ListNode fast=head;
        ListNode slow=head;
        ListNode c;
        while(fast!=null&&fast.next!=null){
            fast=fast.next.next;
            slow=slow.next;
            if(fast==slow){
                c=fast;
                slow=head;
                while(fast!=slow){
                    fast=fast.next;
                    slow=slow.next;
                }
                curr.next=null;
                return fast;
            }
        }
        curr.next=null;
        return null;
        
    }


//leetcode: 445 Add Two Numbers 2   (imp)
//leetcode: 2 Add Two Numbers
    public ListNode  addTwoNumbers(ListNode  l1, ListNode  l2) {
        int c=0;
        ListNode *x=l1;
        ListNode *y=l2;
        l2=l2->next;
        l1=l1->next;
        int a;
        a=(x->val)+(y->val)+c;
        ListNode  l=new ListNode(a%10);
        ListNode head=l;
        c=a/10;
        while(l1!=NULL||l2!=NULL){
            if(l1==NULL&&l2!=NULL){
                a=l2->val + c;
                //=l1->next;
                l2=l2->next;
            }
            if(l1!=NULL&&l2==NULL){
                a=l1->val + c;
                l1=l1->next;
                //=l2->next;
            }
            if(l1!=NULL&&l2!=NULL){
                a=l2->val+l1->val+c;
                l1=l1->next;
                l2=l2->next;
            }
            ListNode newnode=new ListNode(a%10);
            c=a/10;
            l->next=newnode;
            l=newnode;            
        }
        if(c!=0)
        {
            ListNode newnode=new ListNode(c);
            l->next=newnode;            
        }
        return head;
    }
//leetcode: 82
//leetcode: 92


//leetcode 148 Sort linked list
    public ListNode sortList(ListNode head) {
        if(head==null||head.next==null) return head;
        ListNode mid=middleNode2(head);
        ListNode nhead=mid.next;
        mid.next=null;
        
        return mergeTwoLists(sortList(head),sortList(nhead));
    }


//leetcode 23 Merge k linked lists
    public ListNode mergeKLists_(ListNode[] lists,int si,int ei) {
        if(si==ei){
            return lists[si];
        }        
        int mid=(si+ei)/2;
        return mergeTwoLists(mergeKLists_(lists,si,mid),mergeKLists_(lists,mid+1,ei));
    }
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length==0)return null;
        return mergeKLists_(lists,0,lists.length-1);       
    }

//leetcode 138 Copy List with Random Pointer




}