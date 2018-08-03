package com.company;

import java.time.LocalDate;
import java.util.PriorityQueue;

public class PriorityQueueDemo {
    public static void main(String[] args) {
        PriorityQueue<LocalDate> pq = new PriorityQueue<>();
        pq.add(LocalDate.of(1906, 12, 9));
        pq.add(LocalDate.of(2000, 2, 5));
        pq.add(LocalDate.of(1799, 12, 6));

        System.out.println("Iterating over elements...");
        for (var e :
                pq) {
            System.out.println(e);
        }
        System.out.println("Removing...");
        while (!pq.isEmpty()) {
            System.out.println(pq.remove());
        }
    }
}
