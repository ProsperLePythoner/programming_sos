import sys
import time

def spinner(text: str, duration=5):
    # The frames of our spinner
    frames = ["|", "/", "-", "\\"]

    end_time = time.time() + duration
    i = 0

    print(f"{text}", end="", flush=True)

    while time.time() < end_time:
        # Print the current frame, then \r to return to the start of the line
        sys.stdout.write(frames[i % len(frames)])
        sys.stdout.flush()
        
        time.sleep(0.1)
        
        # Erase the spinner character for the next frame
        sys.stdout.write("\b")
        i += 1

    print("Done!")

if __name__ == "__main__":
    spinner("Loading...", 3)