"""
Given an infix expression in the form of string str. Convert this infix expression to postfix expression.
    Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
    Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
    Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -. 
Example:
        Input - exp = 'a+b*(c^d-e)^(f+g*h)-i'
        Output - abcd^e-fgh*+^*+i-
        Explanation - After converting the infix expression into postfix expression, the resultant expression will be abcd^e-fgh*+^*+i-
        
        Input - exp = 'A*(B+C)/D'
        Output - ABC+*D/
        
Constraints:
        Time complexity - O(|s|)
        Space complexity - O(|s|)
        1 ≤ |s| ≤ 10^5

Note: This program is written in python because it's just easier to give precedence in it XD 
"""

class Solution:
    def InfixtoPostfix(self, exp):
        stack, op = [], []
        operators = {'+': 10, '-': 10, '*': 20, '/': 20, '^': 30, '(': 1, ')': 0}
        for i in exp:
            try:
                val = operators[i]
                if op != []:
                    if val > 1:
                        if val > operators[op[-1]]:
                            op.append(i)
                        else:
                            while op != [] and operators[op[-1]] >= val:
                                stack.append(op.pop())
                            op.append(i)
                    elif val == 1:
                        op.append(i)
                    else:
                        while op[-1] != '(':
                            stack.append(op.pop())
                        op.pop()
                else:
                    op.append(i)
            except KeyError as e:
                stack.append(i)
        
        while op != []:
            stack.append(op.pop())
        return "".join(stack)

if __name__ == "__main__":
    expression = input()
    sol = Solution()
    print(sol.InfixtoPostfix(expression))
