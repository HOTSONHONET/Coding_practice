#User function Template for python3
'''
	Your task is to check if given linkedlist
	is a pallindrome or not.
	
	Function Arguments: head (reference to head of the linked list)
	Return Type: boolean , no need to print just return True or False.

	{
		# Node Class
		class Node:
		    def __init__(self, data):   # data -> value stored in node
		        self.data = data
		        self.next = None
	}

	Contributed By: Nagendra Jha
'''
#Function to check whether the list is palindrome.
class Solution:

    # Function to check if given
    # linked list is pallindrome or not
    def isPalindrome(self, head):
         
        slow_ptr = head
        fast_ptr = head
        prev_of_slow_ptr = head
         
        # To handle odd size list
        midnode = None
         
        # Initialize result
        res = True 
         
        if (head != None and head.next != None):
             
            # Get the middle of the list.
            # Move slow_ptr by 1 and
            # fast_ptrr by 2, slow_ptr
            # will have the middle node
            while (fast_ptr != None and
                   fast_ptr.next != None):
                       
                # We need previous of the slow_ptr
                # for linked lists  with odd
                # elements
                fast_ptr = fast_ptr.next.next
                prev_of_slow_ptr = slow_ptr
                slow_ptr = slow_ptr.next
                 
            # fast_ptr would become NULL when
            # there are even elements in the
            # list and not NULL for odd elements.
            # We need to skip the middle node for
            # odd case and store it somewhere so
            # that we can restore the original list
            if (fast_ptr != None):
                midnode = slow_ptr
                slow_ptr = slow_ptr.next
                 
            # Now reverse the second half
            # and compare it with first half
            second_half = slow_ptr
             
            # NULL terminate first half
            prev_of_slow_ptr.next = None
             
            # Reverse the second half
            second_half = self.reverse(second_half)
             
            # Compare
            res = self.compareLists(head, second_half) 
             
            # Construct the original list back
            # Reverse the second half again
            second_half = self.reverse(second_half)
             
            if (midnode != None):
                 
                # If there was a mid node (odd size
                # case) which was not part of either
                # first half or second half.
                prev_of_slow_ptr.next = midnode
                midnode.next = second_half
            else:
                prev_of_slow_ptr.next = second_half
        return res
     
    # Function to reverse the linked list
    # Note that this function may change
    # the head
    def reverse(self, second_half):
         
        prev = None
        current = second_half
        next = None
         
        while current != None:
            next = current.next
            current.next = prev
            prev = current
            current = next
             
        second_half = prev
        return second_half
 
    # Function to check if two input
    # lists have same data
    def compareLists(self, head1, head2):
         
        temp1 = head1
        temp2 = head2
         
        while (temp1 and temp2):
            if (temp1.data == temp2.data):
                temp1 = temp1.next
                temp2 = temp2.next
            else:
                return 0
                 
        # Both are empty return 1
        if (temp1 == None and temp2 == None):
            return 1
             
        # Will reach here when one is NULL
        # and other is not
        return 0
     
    # Function to insert a new node
    # at the beginning
    def push(self, new_data):
         
        # Allocate the Node &
        # Put in the data
        new_node = Node(new_data)
         
        # Link the old list off the new one
        new_node.next = self.head
         
        # Move the head to point to new Node
        self.head = new_node
 
    # A utility function to print
    # a given linked list
    def printList(self):
         
        temp = self.head
         
        while(temp):
            print(temp.data, end = "->")
            temp = temp.next
             
        print("NULL")

#{ 
#  Driver Code Starts
#Initial Template for Python 3
#Contributed by : Nagendra Jha

import atexit
import io
import sys

class Node:
    def __init__(self, data):   # data -> value stored in node
        self.data = data
        self.next = None

# Linked List Class
class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    # creates a new node with given value and appends it at the end of the linked list
    def append(self, new_value):
        new_node = Node(new_value)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
            return
        self.tail.next = new_node
        self.tail = new_node 

if __name__ == '__main__':
    t=int(input())
    for cases in range(t):
        n = int(input())
        a = LinkedList() # create a new linked list 'a'.
        nodes_a = list(map(int, input().strip().split()))
        for x in nodes_a:
            a.append(x)  # add to the end of the list

        if Solution().isPalindrome(a.head):
            print(1)
        else:
            print(0)
# } Driver Code Ends