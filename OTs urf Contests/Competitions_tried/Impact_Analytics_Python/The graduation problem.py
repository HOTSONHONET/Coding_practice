"""
with this solution I got scored 55/100 
11/20 testcases = pass
9/20 testcases = failed

"""

from itertools import product

def Solve (n):
    # Write your code here
    var = ['a', 'p']
    # tcomb = [p for p in product(var, repeat=n)]
    # no_aa = []
    num_ways = 0
    num_ways_cant_attend = 0

    for aa in product(var, repeat=n):
        aa_count = 0
        for i in range(len(aa)-1):
            if (aa[i]==aa[i+1] and aa[i]=='a'):
                aa_count+=1
        if(aa_count == 0):
            if(aa[-1] == 'a'):
                num_ways_cant_attend += 1
            num_ways += 1

    # num_ways = len(no_aa)
    # num_ways_cant_attend = 0
    # for non_aa in no_aa:
    #     if(non_aa[-1]=='a'):
    #         num_ways_cant_attend+=1
    num_ways_she_cant_attend = "{}/{}".format(num_ways_cant_attend, num_ways)

    return [str(num_ways), num_ways_she_cant_attend]
    

N = int(input())

out_ = Solve(N)
for i_out_ in out_:
    print (i_out_)


