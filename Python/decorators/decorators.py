def load_game(func):
    """
    This is a decorator function that takes another function
    as an argument and returns a new function that wraps the original
    one with additional functionality.
    """
    def wrapper():
        print(f"\nLoading resources {'.' * 28}")
        func()
        print(f"Waiting for user input {'.' * 23}\n")
    return wrapper

@load_game
def start_game():
    """
    Python translates this function into a function call as follows:
    
    start_game = load_game(start_game)
    """
    print(f"\n\t{'*' * 10} GAME INITIALIZED {'*' * 10}\n")

@load_game
def load_menu():
    print(f"\n\t{'*' * 10} MENU LOADED {'*' * 10}\n")

if __name__ == "__main__":
    load_menu()
    start_game()