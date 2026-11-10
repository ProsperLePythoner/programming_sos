import math
import sys
import time

text = "LOADING SYSTEM ASSETS..."

try:
    step = 0
    while True:
        sys.stdout.write("\r")
        for i, char in enumerate(text):
            # Use a sine wave to create a smooth brightness/color pulse
            red = int(127 + 127 * math.sin(step + i * 0.3))
            green = int(127 + 127 * math.sin(step + i * 0.3 + 2))
            blue = int(127 + 127 * math.sin(step + i * 0.3 + 4))
            
            # Print with TrueColor (24-bit) ANSI code
            sys.stdout.write(f"\033[38;2;{red};{green};{blue}m{char}")
            
        sys.stdout.flush()
        step += 0.1
        time.sleep(0.05)
except KeyboardInterrupt:
    print("\033[0m\nExited.")