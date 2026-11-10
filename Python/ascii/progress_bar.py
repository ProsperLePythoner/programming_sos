import sys
import time

def progress_bar(total=100, length=40):
    for i in range(total + 1):
        # Calculate filled and empty portions
        filled_len = int(length * i // total)
        bar = "█" * filled_len + "-" * (length - filled_len)
        percent = f"{i}%"
        
        # \r returns cursor to start of line, end="" prevents newlines
        sys.stdout.write(f"\r[{bar}] {percent}")
        sys.stdout.flush()
        
        time.sleep(0.04)
    print() # Move to next line when finished

if __name__ == "__main__":
    progress_bar()