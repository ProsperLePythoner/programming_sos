def load_game(func):
    def wrapper():
        print(f"\nLoading resources {'.' * 28}")
        func()
        print(f"Waiting for user input {'.' * 23}\n")
    return wrapper

@load_game
def start_game():
    print(f"\n\t{'*' * 10} GAME INITIALIZED {'*' * 10}\n")

if __name__ == "__main__":
    start_game()