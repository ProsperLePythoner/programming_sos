import random
import sys
import time

def matrix_rain():
    width = 70
    height = 20
    # Track the row position of the head of each column drop
    drops = [random.randint(-height, 0) for _ in range(width)]
    
    # Clear screen and hide cursor
    print("\033[2J\033[?25l", end="")
    
    try:
        while True:
            output = ["\033[H"] # Jump to top
            for r in range(height):
                line = ""
                for c in range(width):
                    if r == drops[c]:
                        # Bright white-ish head of the drop
                        line += f"\033[1;37m{chr(random.randint(33, 126))}\033[0m"
                    elif r < drops[c] and r > drops[c] - 5:
                        # Trailing green character
                        line += f"\033[32m{chr(random.randint(33, 126))}\033[0m"
                    else:
                        line += " "
                output.append(line)
            
            sys.stdout.write("\n".join(output))
            sys.stdout.flush()
            
            # Move drops down and reset them when they fall off screen
            for c in range(width):
                drops[c] += 1
                if drops[c] > height + random.randint(0, 10):
                    drops[c] = random.randint(-15, 0)
                    
            time.sleep(0.04)
            
    except KeyboardInterrupt:
        print("\033[?25h\033[0m\nExited.")

if __name__ == "__main__":
    matrix_rain()