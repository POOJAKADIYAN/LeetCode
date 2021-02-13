# Given a String of length **S**, reverse the whole string without reversing the individual words in it. Words are separated by **dots**.

# **Input:**The first line contains **T** denoting the number of testcases. T testcases follow. Each case contains a string S containing characters.

# **Output:**For each test case, in a new line, output a single line containing the reversed String.

# **User Task:**The task is to complete the function **reverseWords**() which reverse words from the given string and prints the answer. The **newline** is automatically appended by the **driver code**.

# **Constraints:**1 <= T <= 1001 <= |S| <= 2000

# **Example:Input:**2i.like.this.program.very.muchpqr.mno

# **Output:**much.very.program.this.like.imno.pqr

# **Explanation:Testcase 1:** After reversing the whole string(not individual words), the input string becomes much.very.program.this.like.i.

# ```python
def reverseWords(s):
    li=[]
    li=s.split('.')
    li.reverse()
    new = "" 
    # traverse in the string  
    for x in li: 
        new=new+x+"."
    # return string
    n=len(new)
    new=new[:n-1]
    print(new,end="")
    #print (new[0:-1],end ="")
# ```