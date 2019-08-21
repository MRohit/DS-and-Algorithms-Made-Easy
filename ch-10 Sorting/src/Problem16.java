public class Problem16 {

    void countSort (int arr[], int n) {
        int k = 3;
        int []output = new int[n];
        int[] count = new int[k];
        for (int i=0;i<k;i++){
            count[i] = 0;
        }

        for(int i=0;i<n;i++) {
            count[arr[i]]++;
        }
        for (int i=1;i<k;i++) {
            count[i] = count[i] + count[i-1];
        }

        for (int i=n-1;i>=0;i--) {
            output[count[arr[i]] - 1] = arr[i];
            count[arr[i]]--;
        }
        System.out.println("\nSorted array");
        printArr(output,n);
    }
    // A utility function to print an array
    void printArr(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
            System.out.print(arr[i]+" ");
    }

    public static void main(String args[])
    {
        Problem16 ob = new Problem16();

        // Since array size is 7, elements should be from 0 to 48
        int arr[] = {2,2,1,1,2,2,0,0,1,2,0,2,1,0};
        int n = arr.length;
        System.out.println("Given array");
        ob.printArr(arr, n);

        ob.countSort(arr, n);

        //System.out.println("Sorted array");
        //ob.printArr(arr, n);
    }
}
