import asyncio

@asyncio.coroutine
def hello():
    print('Hello world!')
    r = yield from asyncio.sleep(1)
    print('hello again!')

# To get EventLoop
loop = asyncio.get_event_loop()
# perform coroutine
loop.run_until_complete(hello())
loop.close()