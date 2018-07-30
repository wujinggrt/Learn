class test(object):
    
    def __init__(self):
        self.func = None
    
    def wrapper(self, info):
        def decorator(func):
            self.func = func
            self.info = info
            def inner_wrapper(*args, **kw):
                return func(*args, **kw)
            return inner_wrapper
        return decorator

t = test()
@t.wrapper('hdasjk')
def f():
    print('hehe')

print(t.func)
print(t.info)
f()