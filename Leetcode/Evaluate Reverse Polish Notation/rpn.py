'''
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, and /. Each operand may be an integer or another expression.
Note that division between two integers should truncate toward zero.
It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.
Example:
        Input - ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
        Output - 22
        Explanation - ((10 * (6 / ((9 + 3) * -11))) + 17) + 5 = 22
        
        Input - ["2","1","+","3","*"]
        Output - 9
        Explanation - ((2 + 1) * 3) = 9
        
Constraints:
        Time complexity - O(n)
        Space complexxity - O(n)
        1 <= tokens.length <= 104
        tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].
'''

def evalRPN(tokens):
    stack = []
    for i in tokens:
        try:
            stack.append(int(i))
        except:
            m, n = stack.pop(), stack.pop()
            if i == "+":
                stack.append(m + n)
            elif i == "-":
                stack.append(n - m)
            elif i == "*":
                stack.append(m * n)
            else:
                if abs(m) > abs(n):
                    stack.append(0)
                else:
                    if n/m < 0:
                        stack.append(math.ceil(n/m))
                    else:
                        stack.append(math.floor(n/m))
    return stack[0]
    
if __name__ == "__main__":
    arr = input()
    arr = arr[1:-1].split(",")
    arr = [i.strip()[1:-1] for i in arr]
    print(evalRPN(arr))
