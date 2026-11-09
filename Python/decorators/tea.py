from spin import spinner

def announce(func):
    def wrapper(): # Conrols what happens when announce is called
        print("\nTea preparation started.....")
        func() # Execute the original function
        print("\nTea preparation completed!\n")
    return wrapper # The enhanced function is returned

@announce
def make_tea():
    spinner("\n> Boiling water.....", 3)
    spinner("> Adding tea leaves.....", 2)
    spinner("> Steeping tea.....", 4)

if __name__ == '__main__':
    make_tea()