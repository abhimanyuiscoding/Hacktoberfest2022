class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        def convert(s):
            return (ord(s)-48)
        
        def build(s):
            cur_num = convert(s[0])
            
            for i in range(1,len(s)):
                num = convert(s[i])
                cur_num *= 10
                cur_num+=num
                
            return cur_num
        
        return str(build(num1)*build(num2))
