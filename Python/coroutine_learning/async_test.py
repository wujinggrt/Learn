import threading
import asyncio

@asyncio.coroutine
def hello():
    print('Hello world!(%s) ' % threading.current_thread())
    yield from asyncio.sleep(1)
    print('hello again!(%s' % threading.current_thread())

# To get EventLoop
loop = asyncio.get_event_loop()
tasks = [hello(), hello()]
# perform coroutine
loop.run_until_complete(asyncio.wait(tasks))
loop.close()