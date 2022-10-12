import java.util.Stack;
class Node {
  int data;
  Node next;
  Node(int value) {
    data = value;
    next = null;
  }
}
public class Palindrome {
  Node head;
public void insertAtLast(int data) {
   Node newNode = new Node(data);
    if (head == null) {
      head = newNode;
      return;
    }
    newNode.next = null;
    Node temp = head;
    while (temp.next != null) {
      temp = temp.next;
    }
    temp.next = newNode;
  }
public void printList(Node head) {
    System.out.println("Printing the linked list");
    Node temp = head;
    while (temp != null) {
      System.out.print(temp.data + " ");
      temp = temp.next;
    }
 System.out.println();
  }
public boolean isPalindrome(Node head) {
    Stack<Integer> myStack = new Stack<>();
    Node temp = head;
    boolean status = false;
while (temp != null) {
      myStack.push(temp.data);
      temp = temp.next;
    }
    temp = head;
while (temp != null) {
      int element = myStack.pop();
      if (temp.data == element) {
        status = true;
        temp = temp.next;
      } else {
        status = false;
        break;
      }
    }
return status;
}
  public static void main(String[] args) {
    Palindrome ll = new Palindrome();
    ll.head = new Node(1);
    ll.insertAtLast(2);
    ll.insertAtLast(1);
    ll.insertAtLast(2);
    ll.insertAtLast(1);
    ll.printList(ll.head);
    if (ll.isPalindrome(ll.head)) {
      System.out.println("Palindrome Linked List");
    } else {
      System.out.println("Not a Palindrome Linked List");
    }
    Palindrome ll2 = new Palindrome();
    ll2.head = new Node(4);
    ll2.insertAtLast(2);
    ll2.insertAtLast(5);
    ll2.insertAtLast(6);
    ll2.printList(ll2.head);
    if (ll2.isPalindrome(ll2.head)) {
      System.out.println("Palindrome Linked List");
    } else {
      System.out.println("Not a Palindrome Linked List");
    }

  }
}
