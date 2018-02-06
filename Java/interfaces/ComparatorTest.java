package interfaces;

import java.util.*;

public class ComparatorTest {
    public static void main(String[] args) {
        String[] friends = {"Zhangsan", "LiSi", "Wang"};
        Arrays.sort(friends, new LengthComparator());
        for(String s : friends) {
            System.out.println(s);
        }
        // Lisi
        // Wang
        // Zhangsan
    }
}

class LengthComparator implements Comparator<String> {
    public int compare(String first, String second) {
        return first.length() - second.length();
    }
}