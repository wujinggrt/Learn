package enums;

public class EnumTest {
    public static void main(String[] args) {
        System.out.println(Size.SMALL.toString()); // SMALL
        Size s = Enum.valueOf(Size.class, "SMALL");
    }
}

enum Size {
    SMALL("S")
    , MEDIUM("M")
    , LARGE("L")
    , EXTRA_LARGE("XL");

    private String abbreviation;

    private Size(String abbreviation) {
        this.abbreviation = abbreviation;
    }

    public String getAbbreviation() {
        return abbreviation;
    }
}