class Solution(object):
    def singleNumber(self, nums):
        for i in nums:
            print i
            var=i
            nums.remove(i)
            try:
                nums.remove(var)
            except ValueError:
                return var
temp=Solution()
print temp.singleNumber([1,1,2,2,3,4,4,5,5])
