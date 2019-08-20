package sorting_algorithms;

public class InsertionSort {
    public static void sort (int arr[]) {
        int i,j,v;
        for (i = 1;i<arr.length; i++) {
            int key = arr[i];
            j = i -1;
            while (j >=0 && arr[j] > key) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
        System.out.println("After Sorting:");
        for ( i=0;i<arr.length;i++) {
            System.out.print(arr[i]+",");
        }
    }
    public static void main (String args[]) {
        int arr[] = {8,6,1,5,4,3,2};
        InsertionSort.sort(arr);
    }
}
