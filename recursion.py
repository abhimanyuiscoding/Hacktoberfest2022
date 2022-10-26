##single list 
class Node:
    def __init__(self,value=None):
        self.value=value
        self.next=None


class SSLinked:
    def __init__(self):
        self.head=None
        self.tail=None
    
    def __iter__(self):
        node=self.head
        while node:
            yield node
            node=node.next

    def insertssl(self,value,location):
        newnode=Node(value)
        if self.head is None:
            self.head=newnode
            self.tail=newnode
        
        else:
            #Fist we put the new node reference value as initial head value by using 
            #newnode.next=self.head
            #now we self.head reference to newnode
            #
            if location==0:
                newnode.next=self.head
                self.head=newnode
#In the below sentences refer the algorithm as it says 1)-1 means we end up on the last node 
#First delete the reference of the last node by newnode.next=None
#now update inittially existing tail reference to the newnode
#now make the new node as the tail 

            elif location ==-1:
                newnode.next=None
                self.tail.next=newnode 
                self.tail=newnode
            
            else:
                value=0
                temp=self.head
                while value<location-1:
                    temp=temp.next
                    index+=1
                
                #
                #
                #first get tem and change its reference to the new node value ie temp.next=newnode
                #then newnode.next=temp.next but use it in a variable
                lastone=temp.next
                temp.next=newnode
                newnode.next=lastone
                #if the temp is the last one then select the tail as the new node
                if temp==self.tail:
                    self.tail=newnode

    def transversal(self):
        node=self.head
        while node is not None:
            print(node.value)
            node=node.next

    def search(self,value):
        node=self.head
        while node is not None:
            if node.value==value:
                return node.value,"has been found"
            node=node.next

    def delete(self,location):
        if self.head==None:
            print("node does not exist")
        
        else:
            if location==0:
                if self.head==self.tail:
                    self.head=None
                    self.tail=None
                
                else:
                    self.head=self.head.next

            elif location ==-1:
                if location==0:
                    if self.head==self.tail:
                        self.head=None
                        self.tail=None
                
                else:
                    node=self.head
                    while node is not None:
                        if node.next==self.tail:
                            break
                        node=node.next
                    node.next=None
                    self.tail=node

            else:
                tempnode=self.head
                index=0
                while index<location-1:
                    tempnode=tempnode.next
                    index+=1
                
                lastnode=tempnode.next
                tempnode.next=lastnode.next

    def deleteall(self):
        self.head=None
        self.tail=None



singlelist=SSLinked()
singlelist.insertssl(1,1)
singlelist.insertssl(2,-1)
singlelist.insertssl(3,-1)
singlelist.insertssl(4,-1)
singlelist.transversal()
print(singlelist.search(2))
singlelist.delete(2)
singlelist.deleteall()
print([n.value for n in singlelist ])
                
                
                
            
