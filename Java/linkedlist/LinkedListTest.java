package linkedlist;

import java.util.*;

public class LinkedListTest {
    public static void main(String[] args) {
        List<String> a = new LinkedList<>();
        a.add("Haha");
        a.add("Gou");
        a.add("Li");
        a.add("Guo");

        List<String> b = new LinkedList<>();
        b.add("Jia");
        b.add("Sheng");
        b.add("Si");
        b.add("Yi");

        ListIterator<String> aIter = a.listIterator();
        Iterator<String> bIter = b.iterator();

        while(bIter.hasNext()) {
            if (aIter.hasNext()) {
                aIter.next();
            }
            aIter.add(bIter.next());
        }

        System.out.println(a); // [Haha, Jia, Gou, Sheng, Li, Si, Guo, Yi]

        bIter = b.iterator();
        while(bIter.hasNext()) {
            bIter.next();
            if(bIter.hasNext()) {
                bIter.next();
                bIter.remove();
            }
        }

        System.out.println(b); // [Jia, Si]

        a.removeAll(b);

        System.out.println(a); // [Haha, Gou, Sheng, Li, Guo, Yi]
    }
    
}