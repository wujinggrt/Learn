package abstractTest;

public class Student extends Person {
    private String major;

    /**
      @param name the student's name
      @param major the student's major
     */
    public Student(String name, String major) {
        super(name);
        this.major = major;
    }

    public String getDescription() {
        return "a student majoring in " + major;
    }
}