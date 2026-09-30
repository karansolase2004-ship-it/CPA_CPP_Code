class Gensquare_iterator:
    def __init__(self, G):
        self.G = G
    def __next__(self):
        return self.G.__next__()

class Gensquare:
    def __init__(self, N:int):
        assert type(N) == int, "Bad type : N"
        assert N > 0, "Bad value: N"
        self.N = N

    def __iter__(self):
        def get_generator(N):
            for i in range(N):
                yield i ** 2
        return Gensquare_iterator(get_generator(self.N))

print("Iterating using while")
G = Gensquare(10)
I = G.__iter__()
while True:
    try:
        n = I.__next__()
        print(n)
    except StopIteration:
        break

print("Iterating using for")
for x in G:
    print(x) 

"""
ITERATOR PATTERN:

class YOUR_CLASSNAME_iterator:
    def __init__(self, G):
        self.G = G
    def __next__(self):
        return self.G.__next__()

class <YOUR CONTAINER CLASS NAME>:
    def __init__(self, N:int):
       YOUR CONTAINER OBJECT NAMESPACE 

    def __iter__(self):
        def get_generator(YOUR PARAM):
            YOUR CONTAINER YIELD STATEMENT
        return YOUR_CLASS_NAME_iterator(get_generator(self.N))
"""




    
