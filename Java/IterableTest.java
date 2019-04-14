import java.util.Iterator;
import java.util.ArrayList;

public class IterableTest implements Iterable<Integer>  {
    
    private ArrayList<Integer> list = new ArrayList<>();
    
    private int accumulation;
    
    public int accumulate(int initial) {
        accumulation = initial;
        list.forEach(e -> accumulation += e);
        return accumulation;
    }

    public IterableTest() {
        list.add(1);
        list.add(2);
        list.add(3);
        list.add(4);
    }

    private class InnerIterator implements Iterator<Integer> {
        private int i = 0;

        @Override
        public boolean hasNext() {
            return i < list.size();
        }

        @Override
        public Integer next() {
            return list.get(i++);
        }

        @Override
        public void remove() {}
    }

    @Override
    public Iterator<Integer> iterator() {
        return new InnerIterator();
    }

    public static void main(String[] args) {
        IterableTest iterTest = new IterableTest();
        for (var e: iterTest) {
            System.out.println(e);
        }
        System.out.println(iterTest.accumulate(0));
    }
}