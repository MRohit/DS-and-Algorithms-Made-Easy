public class Problem22 {

    // A utility function to print an array
    void printArr(int arr[])
    {
        for (int i = 0; i < arr.length; i++)
            System.out.print(arr[i]+" ");
    }

    void sortArray (int arr[]) {
        int v =0;
        for (int i = 1;i<arr.length;i++) {
            v = arr[i];
            int j = i-1;
            while (j >= 0 && v < arr[j]) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = v;
        }
    }
    public static void main (String args[]) {
        int a[]={6,5,2,3,8,10,9};
        Problem22 ob = new Problem22();
        ob.printArr(a);
        ob.sortArray(a);
        System.out.println("\nAfter sorting the array:");
        ob.printArr(a);
    }


}
