# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(S):
    # write your code in Python 3.6
    if len(S) == 0:
        return ''

    stack = []
    for s in S:
        if len(stack) == 0:
            stack.append(s)
            continue
        last_letter = stack[-1]
        if isCouple(s, last_letter):
            stack.pop()
        else:
            stack.append(s)
    return ''.join(stack)


def isCouple(s1, s2):
    if s1 == 'A' and s2 == 'B':
        return True
    if s1 == 'B' and s2 == 'A':
        return True
    if s1 == 'C' and s2 == 'D':
        return True
    if s1 == 'D' and s2 == 'C':
        return True
    return False
