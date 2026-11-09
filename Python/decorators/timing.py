import time

def timer(func):
    """
    Decorator function that measures the execution time of a function.
    """
    def wrapper():
        start = time.time() # Start time
        func() # Call the original function
        end = time.time() # End time
        print(f"\nExecution time: {end - start:.4f} seconds\n")
    return wrapper

@timer # pass the long_running_function to the timer decorator
def long_running_function():
    """
    Simulates a long-running function by sleeping for 5 seconds.
    """
    time.sleep(5)
    print("Long running function completed.")

if __name__ == '__main__':
    long_running_function()