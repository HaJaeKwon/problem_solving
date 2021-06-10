# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

GOOD = '.'
HOLE = 'X'

def solution(S):
    # write your code in Python 3.6
    answer, i = 0, 0
    while i < len(S):
        # print("i: ", i)
        if S[i] == HOLE:
            answer += 1
            i += 2
        i += 1

    return answer
