def consume():
    r = ''
    while True:
        n = yield r
        if not n:
            return
        print('[CONSUME] Consume %s...' % n)
        r = '200 OK'

def produce(c):
    c.send(None)
    n = 0
    while n < 5:
        n = n + 1
        print('[PRODUCT] Producting %s...' % n)
        r = c.send( n)
        print('[PRODUCT] Cunsumer return: %s' % r)
    c.close()

c = consume()
produce(c)