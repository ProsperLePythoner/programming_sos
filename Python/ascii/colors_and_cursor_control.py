import time

# ANSI color codes
RESET = "\033[0m"
RED = "\033[31m"
GREEN = "\033[32m"
YELLOW = "\033[33m"
BLUE = "\033[34m"

print(f"{RED}This is red!{RESET}")
print(f"{GREEN}This is green!{RESET}")

# Moving the cursor: \033[<row>;<col>H
# You can clear the screen using: \033[2J
print("\033[2J", end="") # Clears screen

for color in [RED, YELLOW, GREEN, BLUE]:
    print(f"{color}Moving text around with ANSI codes!{RESET}")
    time.sleep(0.5)