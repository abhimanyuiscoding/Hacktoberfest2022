import java.util.*;

public class MergeSort {
    static int count=0;
    public static void Merge(ArrayList<Integer> arr,int l,int mid,int r){
        int i,j,k=l,n1=mid-l+1,n2=r-mid;
        ArrayList<Integer> b_arr=new ArrayList<>();
        ArrayList<Integer> c_arr=new ArrayList<>();
        for(i=0;i<n1;i++)
            b_arr.add(arr.get(k++));
        for(j=0;j<n2;j++)
            c_arr.add(arr.get(k++));
        k=l;j=0;i=0;
        while(i<n1&&j<n2){
            if(b_arr.get(i) < c_arr.get(j)) arr.set(k++, b_arr.get(i++));
            else arr.set(k++, c_arr.get(j++));
            count++;
        }
        while(i<n1){
            arr.set(k++, b_arr.get(i++));
            count++;
        }
        while(j<n2){
            arr.set(k++, c_arr.get(j++));
            count++;
        }
    }
    public static void Merge_Sort(ArrayList<Integer> arr, int l,int r){
        if(l>=r)return;
        int mid=(l+r)/2;
        Merge_Sort(arr,l,mid);
        Merge_Sort(arr,mid+1,r);
        Merge(arr,l,mid,r);
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
            Merge_Sort(sort_copy,0,i-1);
            t_sorted.add(count);
            count=0;
            rand_copy=new ArrayList<>(random_arr);
            Merge_Sort(rand_copy,0,i-1);
            t_random.add(count);
            count=0;
            rev_sort_copy=new ArrayList<>(reverse_sorted_arr);
            Merge_Sort(rev_sort_copy,0,i-1);
            t_descending.add(count);
            i=i*2;
        }
        i=n;
        int j=0;
        int log_n,n_log_n;
        System.out.println("Array Size   Ascending     Descending       Random");
        System.out.println("   n          Ac   cal       Ac   cal       Ac  cal");
        while(i<100){
            log_n= (int) (Math.log(i)/Math.log(2));
            n_log_n = i * log_n;
            System.out.printf("   %-2d         %-4d %-4d      %-4d %-4d      %-4d %-4d\n",i,t_sorted.get(j),n_log_n,t_descending.get(j),n_log_n,t_random.get(j),n_log_n);
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
        for(i=0;i<n;i++) {
            arr.add(scan.nextInt());
        }
        System.out.println("Part1");
        Merge_Sort(arr,0,n-1);
        System.out.println("The Sorted Array is");
        for(i=0;i<n;i++)
            System.out.print(arr.get(i) +" ");
        System.out.println("\n The time complexity is "+ count);
        System.out.println("Part2");
        Time_Complexity(n);
    }
}
