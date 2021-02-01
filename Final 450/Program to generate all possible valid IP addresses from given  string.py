def isValid(s):
    #code here
    nums = s.split(".")
    if(len(nums)!=4): return 0;
    
    for num in nums:
        if (len(num)>3 or len(num) == 0):
            return 0
        if (num[0] == '0' and len(num)>1):
            return 0
        try:
            num = int(num)
            if(num > 255):
                return 0
        except ValueError:
            return 0
    
    return 1