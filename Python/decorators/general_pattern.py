from functools import wraps

def decorator(func):

    @wraps(func)
    def wrapper(*args, **kwargs):

        # Additional functionality BEFORE

        result = func(*args, **kwargs)

        # Additional functionality AFTER

        return result

    return wrapper