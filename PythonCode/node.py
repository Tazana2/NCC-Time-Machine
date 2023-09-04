class Node():
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

    def __repr__(self):
        if self.next is None:
            return f'{self.data}'
        return f'{self.data} ->'