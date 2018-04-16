def log(func):
	def new_func(*args, **kwargs):
		print("running function:", func.__name__)
		print('args:', args)
		print('kwargs:', kwargs)
		result = func(*args, **kwargs)
		print(result)
		return result
	return new_func
	
@log
def sum(a, b):
	return a + b
	
sum(1, 2) 
# running function: sum
# args: (1, 2)
# kwargs: {}
# 3