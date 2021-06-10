# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(S):
    # write your code in Python 3.6
    total = 0
    for s in S:
        total += int(s)

    answer = 1 if total%3 == 0 else 0
    for s in S:
        n = int(s)
        for i in range(0, 10):
            if i == n:
                continue
            if (total - n + i)%3 == 0:
                # print("i:", i, "total-n+i: ", total - n + i)
                answer += 1
    return answer