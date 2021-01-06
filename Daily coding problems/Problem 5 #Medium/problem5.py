"""
This is an amazing problem. Learnt three new concepts while solving it, namely:
1. Nested functions;
2. Closure; and
3. Functional parameter

Nested functions are basically functions defined inside functions. For example,
in the cons(a, b) function, the pair function is defined inside it. The cons function
takes two arguments a and b, and returns the function pair.

Now, functional parameter means passing a function as a parameter. Here the function 
pair takes another function(f) as a parameter. It returns whatever value the
passed function returns.
So in short, cons(a, b) will return a function pair, which will return a value
returned by the inner function(f). If we try cons(a, b)(lambda a, b: a + b)
it will print the sum of a and b. If we do cons(a, b)(print), it will print a and b.

Now, since the pair is defined inside cons, and f is defined inside pair, yet it
can access a and b. Now this is because of something called as closure.In python,
nested functions are easily able to access variables in the parent function. That is because of closure.
A closure is a function object that remembers values in enclosing scopes even if they are not present in memory.
- It is a record that stores a function together with an environment: a mapping associating each free variable
of the function (variables that are used locally, but defined in an enclosing scope) with the value or
reference to which the name was bound when the closure was created.
- A closure—unlike a plain function—allows the function to access those captured variables through the
closure’s copies of their values or references, even when the function is invoked outside their scope. 
"""



def cons(a, b):
	#The 'pair' function is a function taking another function as an argument. 
	#Try with print function.
	#The parametes a, b are passed on to the nested function via closure.
	def pair(f):
		return f(a, b)
	return pair

def car(pair):
	def return_first(a, b):
		return a
	return pair(return_first)

def cdr(pair):
	def return_last(a, b):
		return b
	return pair(return_last)

a = input()
b = input()

print(car(cons(a, b)), cdr(cons(a, b)))
# print(cons(4, 5)(lambda a, b: a + b))
