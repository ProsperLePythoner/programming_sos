import math
import sys
import time

def draw_braille_wave():
    width = 60
    height = 4  # 4 rows of characters = 16 vertical pixels
    
    # Clear screen once at start and hide cursor (\033[?25l)
    print("\033[2J\033[?25l", end="")
    
    try:
        offset = 0.0
        while True:
            # Move cursor back to top-left corner instead of clearing entire screen (prevents flickering)
            sys.stdout.write("\033[H")
            
            pixel_cols = width * 2
            pixel_rows = height * 4
            
            # Initialize empty pixel grid (False = off, True = on)
            grid = [[False for _ in range(pixel_cols)] for _ in range(pixel_rows)]
            
            # Populate sine wave pixels
            for x in range(pixel_cols):
                angle = (x + offset) * 0.1
                y_val = math.sin(angle) # Range: -1.0 to 1.0
                
                # Map to pixel rows
                y_pixel = int((y_val + 1) / 2 * (pixel_rows - 1))
                y_pixel = pixel_rows - 1 - y_pixel # Invert because row 0 is at top
                
                if 0 <= y_pixel < pixel_rows:
                    grid[y_pixel][x] = True
                    
            # Convert grid into Braille characters (Base unicode: 0x2800)
            output = []
            for r in range(0, pixel_rows, 4):
                row_str = ""
                for c in range(0, pixel_cols, 2):
                    val = 0
                    if grid[r][c]:     val |= 0x1
                    if grid[r+1][c]:   val |= 0x2
                    if grid[r+2][c]:   val |= 0x4
                    if grid[r+3][c]:   val |= 0x40
                    if grid[r][c+1]:   val |= 0x8
                    if grid[r+1][c+1]: val |= 0x10
                    if grid[r+2][c+1]: val |= 0x20
                    if grid[r+3][c+1]: val |= 0x80
                    
                    row_str += chr(0x2800 + val)
                output.append(row_str)
                
            # Print with a sleek cyan color
            sys.stdout.write("\033[36m" + "\n".join(output) + "\033[0m\n")
            sys.stdout.flush()
            
            offset += 0.8
            time.sleep(0.03)
            
    except KeyboardInterrupt:
        # Restore cursor (\033[?25h) and reset formatting
        print("\033[?25h\033[0m\nExited.")

if __name__ == "__main__":
    draw_braille_wave()