// Linked List Leetcode Quetions

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


//class Question based on leetcode 143
    public static void reorder_inv(ListNode head){

    }


//leetcode: Odd Even Linked List
    public ListNode oddEvenList(ListNode head) {
        if(head==null||head.next==null)return head;
        ListNode curr=head;
        ListNode curr1=head.next;
        while(curr!=null&&curr1!=null){
            ListNode f1=curr1.next;
            ListNode f2=f1.next;

            curr.next=curr1;
            curr1.next=
        }
    }