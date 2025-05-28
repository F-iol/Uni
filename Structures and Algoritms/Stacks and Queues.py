# stacks last in fist out
stack = []
stack.append(5)
stack.append(6)
stack.append(10)
print(stack)

x = stack.pop()
print(stack,x)

print(stack[-1])

#queus first in first out

from collections import deque

q = deque()

print(q)

q.append(1)
q.append(2)
print(q)
q.appendleft(3)
q.appendleft(4)
print(q)
q.pop()
q.popleft()
print(q)