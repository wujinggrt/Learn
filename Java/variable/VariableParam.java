package variable;

public class VariableParam {
    public static void main(String[] args) {
        System.out.println(max(1, 3.3, 12, -1)); //12.0
        System.out.println(max(1, 3.3, 12, -1)); //12.0
    }

    public static double max(double... values) {
        double largest = Double.NEGATIVE_INFINITY;
        for(double v : values) {
            if(v > largest) {
                largest = v;
            }
        }
        return largest;
    }

    public static double valueOf(int index, double... values) {
        return values[index];
    }
}