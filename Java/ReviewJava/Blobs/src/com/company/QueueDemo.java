package com.company;

import java.util.AbstractQueue;
import java.util.Iterator;

public class QueueDemo {
    public static void main(String[] args) {
        var q = new CircularArrayQueue<String>(20);
        q.add("Hello");
        q.add(" ");
        q.add("world!");
        for (var e :
                q) {
            System.out.println(e);
        }
    }
}

class CircularArrayQueue<E> extends AbstractQueue<E> {

    private Object[] elements;
    private int head;
    private int tail;
    private int count;
    private int modCount;

    public CircularArrayQueue(int capacity) {
        elements = new Object[capacity];
        count = 0;
        head = 0;
        tail = 0;
    }

    @Override
    public int size() {
        return count;
    }

    @Override
    public boolean offer(E e) {
        if (e == null) {
            return false;
        }
        if (count >= elements.length) {
            return false;
        }

        elements[tail] = e;
        tail = (tail + 1) % elements.length;
        count++;
        modCount++;
        return true;
    }

    @Override
    public E poll() {
        if (count == 0) {
            return null;
        }
        E ret = peek();
        head = (head + 1) % elements.length;
        modCount ++;
        count++;
        return ret;
    }

    @SuppressWarnings("unchecked")
    @Override
    public E peek() {
        if (count == 0) {
            return null;
        }
        return (E) elements[head];
    }

    public Iterator<E> iterator() {
        return new QueueIterator();
    }

    private class QueueIterator implements Iterator<E> {
        private int offset;
        private int modCountAtCounstruction;

        public QueueIterator() {
            modCountAtCounstruction = modCount;
        }

        @Override
        public void remove() {

        }

        @Override
        public boolean hasNext() {
            return offset < count;
        }

        @Override
        public E next() {
            E ret = (E) elements[(head + offset) % elements.length];
            offset++;
            return ret;
        }
    }
}
