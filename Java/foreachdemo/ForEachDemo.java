package foreachdemo;

import java.util.*;

public class ForEachDemo {
    public static void main(String[] args) {
        Students students = new Students(10);
        for(Student student : students) {
            System.out.println(student);
        }
    }
}

class Students implements Iterable<Student> {
    private Student[]  students;

    public Students(int size) {
        students = new Student[size];
        for (int i = 0; i < size; i++) {
            students[i] = new Student("学生" + String.valueOf(i), String.valueOf(i));
        }
    }

    public Iterator<Student> iterator() {
        return new StudentIterator(); 
    }

    private class StudentIterator implements Iterator<Student> {
            private int index = 0;

            public boolean hasNext() {
                return index != students.length;
            }

            public Student next() {
                return students[index++];
            }
        }
}

class Student {
    private String name;
    private String id;

    public Student(String name, String id) {
        this.name = name;
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public String getId() {
        return id;
    }

    public void setName(String newName) {
        this.name = newName;
    }

    public void setId(String newId) {
        this.id = newId;
    }

    public String toString() {
        return "Student{" + 
            "name=" + name +
            ",id=" + id +
            "}";
    }
}