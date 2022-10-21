public class HalfPyramid {
    public static void main(String[] args) {
        int n=5;
        for(int i=1;i<=n;i++)
        {
            for(int j=n-i;j>=1;j--)
            {
                System.out.print(" ");
            }
            for(int k=1;k<=i;k++)
            {
                //for(int m=1;m<=i;m++)
                System.out.print(k+" ");
                
            }
            System.out.println();
        }
        
    }
}
