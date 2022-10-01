def Calculator(fun):
    def exec(a,b):
        print("Executing...")
        fun(a,b)
        print("Executed..")
    return exec

@Calculator
def add(a,b):
    return a+b

add = Calculator(add)

add(5,6)



  
