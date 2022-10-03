public class BubbleSort
{
    private int[] array;
    private int size;
    private int max;
    private int min;
    
    public BubbleSort(int size, int max, int min)
    {
        array = new int[size];
        this.size = size;
        this.max = max;
        this.min = min;

        generateArray();
    }
    public void printArray()
    {
        for(int num : array)
        {
            System.out.println(num);
        }
        System.out.println();
    }
    public void sort()
    {
        System.out.println("Sorting");

        for(int i = 1; i < size; i++)
        {
            for(int j = 0; j < size-i; j++)
            {
                if(array[j] > array[j+1])
                {
                    swap(j, j+1);
                }
            }
        }
    }
    private void swap(int x, int y)
    {
        int temp = array[x];
        array[x] = array[y];
        array[y] = temp;
    }
    private void generateArray()
    {
        for(int i = 0; i < size; i++)
        {
            array[i] = getRandom();
        }
    }
    private int getRandom()
    {
        return (int)((Math.random() * (max-min+1)) + min);
    }
}
