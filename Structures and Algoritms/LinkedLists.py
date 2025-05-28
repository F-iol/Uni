class Node:
    def __init__(self,info):
        self.info=info
        self.next=None


class LinkedList:
    def __init__(self):
        self.head=None
        
    def append(self,info):
        new_node = Node(info)
        if not self.head:
            self.head=new_node
            return
        last = self.head
        while last.next:
            last = last.next
        last.next=new_node
        
    def DisplayNode(self):
        current = self.head
        while current:
            print(current.info,end=" >>> ")
            current = current.next
        print("None")
            
            
linkedlist = LinkedList()
linkedlist.append(10)
linkedlist.append(20)
linkedlist.append(30)
linkedlist.append(40)
linkedlist.append(50)
linkedlist.append(60)

linkedlist.DisplayNode()

