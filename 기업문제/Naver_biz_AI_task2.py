# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(S, C):
    # write your code in Python 3.6
    names = S.split('; ')
    email_suffix = f'@{C.lower()}.com'
    name_map = {}

    answer = [''] * len(names)
    for i in range(len(names)):
        name_split = names[i].split(' ')
        first = getFirstName(name_split)
        last = getLastName(name_split)

        email_prefix = f'{last}_{first}'
        if name_map.get(email_prefix) is not None:
            name_map[email_prefix] += 1
            email_prefix = email_prefix + str(name_map[email_prefix])
        else:
            name_map[email_prefix] = 1
        answer[i] = f'{names[i]} <{email_prefix}{email_suffix}>'
    return '; '.join(answer)

def getFirstName(names):
    return names[0].lower().replace('-', '')

def getLastName(names):
    last = names[1] if len(names) == 2 else names[2]
    return last.lower().replace('-', '')
