"""
Composing Functions
f: x*x
g: x+1

In math
f(g(x)) -> (x+1) * (x+1)
"""

# map
def map(func, aList):
    result = []
    for e in aList:
        result.append(func(e))
    return result

def square(x):
    return x*x

def isMultipleOf(x):
    def ofThis(n):
        if n % x == 0:
            return True
        else:
            return False
    return ofThis

#filter
def filter(func, aList):
    result = []
    for e in aList:
        if func(e):
            result.append(e)
    return result

def sum(x,y):
    return x+y

#reduce
def reduce(func, aList, initial):
    result = initial
    for e in aList:
        result = func(e, result)
    return result


print reduce(sum, [1,2,3,4,5,6], 0)
print map(square,[1,2,3,4,5,6])
print filter(isMultipleOf(2),[1,2,3,4,5,6,7])
