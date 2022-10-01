import java.util.Scanner;

public class TrappingRainWater {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter length of array:");
        int len = sc.nextInt();

        int[] bars = new int[len];
        for (int i = 0; i < bars.length; i++) {
            bars[i] = sc.nextInt();
        }
        sc.close();
        
        int quantity = method1(bars);
        System.out.println(quantity);
    }

    private static int method1(int[] arr) {
        int left = 0, right = arr.length - 1; // 'left' pointer points to first index initially and 'right' pointer
                                              // points to the last element in the array initially

        int maxLeft = 0, maxRight = 0, ans = 0;// maxLeft stores height of longest bar on the left of a certain bar
                                               // maxRight stores the height of longest bar on the right of a certain
                                               // bar
        while (left < right) { // run the loop as long as left pointer doesn't cross right pointer

            if (arr[left] < arr[right]) { // if arr[left] < arr[right], update maxLeft and ans and increment the left
                                          // pointer
                maxLeft = Math.max(maxLeft, arr[left]);
                ans += maxLeft - arr[left];
                left++;
            }

            else { // else, perform the same steps but in this case, decrement right pointer
                maxRight = Math.max(maxRight, arr[right]);
                ans += maxRight - arr[right];
                right--;
            }
        }

        return ans;
    }
}
