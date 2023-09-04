from data import Data
from node import Node

class List():
    def __init__(self):
        self.head = None
        self.tail = None

    def append(self):
        node = Node(Data())
        if self.head is None:
            self.head = node
            self.tail = node
        else:
            self.tail.next = node
            node.prev = self.tail
            self.tail = node

    def showList(self):
        if self.head is None:
            print('Empty list')
            return
        node = self.head
        while node:
            print(node, end=' ')
            node = node.next