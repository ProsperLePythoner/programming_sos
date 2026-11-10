import functools

def log_call(func):
    @functools.wraps(func) # Preserve og function's metadata
    def wrapper(*args, **kwargs):
        print(f"Calling function '{func.__name__}'")
        return func(*args, **kwargs)
    return wrapper

@log_call
def add(a, b, c=100): # add = log_call(add)
    """Add three numbers"""
    return a + b + c

if __name__ == "__main__":
    print(add(1, 2, c=200), flush=True)
    print(f"\nFunction name: {add.__name__}")
    print(f"Function docstring: {add.__doc__}\n")