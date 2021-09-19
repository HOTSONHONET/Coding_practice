from itertools import permutations

answers = []
multiples = []
for i in range(1, 10):
    multiples.append(str(i)*i)
    answers.append(str(i)*i)



ans = ""
for i in range(len(multiples)):
    ans += multiples[i]
    for j in range(len(multiples)):
        if (i != j):
            ans +=multiples[j]
            if(len(ans) > 12):
                ans = ""
                break
            answers.append(ans)


# print(answers)


def findAns2(n, num):
    num = int(num)
    found = False
    f_ans = 1000000000000
    for ans in answers:
        if(len(ans) == n):
            tmp = sorted(ans, reverse=True)
            tmp = "".join(tmp)
            if(int(tmp) > num):
                if(found == False): found = True
                f_ans = min(int(tmp), f_ans)


    if not found:
        return -1

    f_ans_min = sorted(str(f_ans))

    if(int("".join(f_ans_min))   > num):
        return int("".join(f_ans_min))

    
    perms = permutations(f_ans_min)
    
    for d in perms:
        if( int("".join(d))>num ):
            return int("".join(d))



def findAns(n, num):
    num = int(num)
    found = False
    f_ans = 1000000000000
    pos_ans = []
    for ans in answers:
        if(len(ans) == n):
            pos_ans.append(ans)

    # print(pos_ans)

    for pd in pos_ans:
        for d in permutations(pd):
            int_d = int("".join(d))
            if(int_d > num):
                if(found == False): found = True
                f_ans = min(int_d, f_ans)  
    if not found:
        return -1
    return f_ans


def beautifulNumber(N):
    # Write your code here
    n = len(N)
    pos_ans = findAns2(n, N)
    if(pos_ans != -1): 
        return pos_ans
    
    return findAns2(n+1, N)


T = int(input())
for _ in range(T):
    N = input()

    out_ = beautifulNumber(N)
    # print (N, out_)
    print(N, "->", out_)