import java.util.*;

public class QuickSort {
    static int count=0;
    public static int Partition(ArrayList<Integer> arr, int l, int r){
        int  pivot= arr.get(l),i=l+1,j=r;
        while(true){
            while(i<r+1&&pivot>=arr.get(i)){
                i++;
                count++;
            }
            while(j>l-1&&pivot< arr.get(j)){
                j--;
                count++;
            }
            count++;
            if(i<j)Collections.swap(arr,i,j);
            else {
                Collections.swap(arr,l,j);
                return j;
            }
        }
    }
    public static void Quick_Sort(ArrayList<Integer> arr, int l, int r){
        if(l>=r)return;
        int pivot=Partition(arr,l,r);
        Quick_Sort(arr,l,pivot-1);
        Quick_Sort(arr,pivot+1,r);
    }
    public static void Time_Complexity(int n){
        Random random= new Random();
        ArrayList<Integer> sorted_arr=new ArrayList<>();
        ArrayList<Integer> random_arr=new ArrayList<>();
        ArrayList<Integer> reverse_sorted_arr;
        for(int i=0;i<100;i++)sorted_arr.add(i);
        reverse_sorted_arr=new ArrayList<>(sorted_arr);
        Collections.reverse(reverse_sorted_arr);
        ArrayList<Integer> sort_copy,rand_copy,rev_sort_copy;
        for(int i=0;i<100;i++)random_arr.add(random.nextInt()%1000);
        ArrayList<Integer> t_sorted=new ArrayList<>(),t_random=new ArrayList<>(),t_descending=new ArrayList<>();
        int i=n;
        while(i<100){
            sort_copy=new ArrayList<>(sorted_arr);
            count=0;
            Quick_Sort(sort_copy,0,i-1);
            t_sorted.add(count);
            count=0;
            rand_copy=new ArrayList<>(random_arr);
            Quick_Sort(rand_copy,0,i-1);
            t_random.add(count);
            count=0;
            rev_sort_copy=new ArrayList<>(reverse_sorted_arr);
            Quick_Sort(rev_sort_copy,0,i-1);
            t_descending.add(count);
            i=i*2;
        }
        i=n;
        int j=0;
        int log_n,n_log_n,n_worst;
        System.out.println("Array Size   Ascending     Descending       Random");
        System.out.println("   n          Ac   cal       Ac   cal       Ac  cal");
        while(i<100){
            log_n= (int) (Math.log(i)/Math.log(2));
            n_log_n = i * log_n;
            n_worst=i*(i+1)/2-1;
            System.out.printf("   %-2d         %-4d %-4d      %-4d %-4d      %-4d %-4d\n",i,t_sorted.get(j),n_worst,t_descending.get(j),n_worst,t_random.get(j),n_log_n);
            j++;
            i*=2;
        }
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n,i;
        ArrayList<Integer> arr=new ArrayList<>();
        System.out.println("Enter the size of the array");
        n = scan.nextInt();
        System.out.println("Enter the elements of the array");
        for(i=0;i<n;i++)
            arr.add(scan.nextInt());
        Quick_Sort(arr,0,n-1);
        System.out.println("Part 1");
        System.out.println("The Sorted Array is");
        for(i=0;i<n;i++)
            System.out.print(arr.get(i) +" ");
        System.out.println("\n The Time Complexity is "+count);
        System.out.println("Part 2");
        Time_Complexity(n);
    }
}
