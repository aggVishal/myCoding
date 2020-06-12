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


//leetcode 143

//class Question based on leetcode 143
public static void reorder_inv(Node head){
    
}