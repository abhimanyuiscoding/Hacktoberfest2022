public class Recursion {
    public Recursion() {
    }

    public int fib(int n) {
        if (n == 0) {
            return 0;
        } else {
            return n <= 2 ? 1 : this.fib(n - 1) + this.fib(n - 2);
        }
    }

    public int factorial(int n) {
        return n <= 1 ? 1 : n * this.factorial(n - 1);
    }

    void hanoi(int n, char source, char auxilary, char destination) {
        if (n > 0) {
            this.hanoi(n - 1, source, destination, auxilary);
            System.out.println("Disk " + n + " moved from rod " + source + " to rod " + destination);
            this.hanoi(n - 1, auxilary, source, destination);
        }

    }

    public static void main(String[] args) {
        Recursion recursion = new Recursion();
        System.out.println(recursion.fib(7));
        System.out.println(recursion.factorial(7));
        recursion.hanoi(8, 'M', 'L', 'P');
    }
}
