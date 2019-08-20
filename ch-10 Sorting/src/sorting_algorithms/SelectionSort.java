package sorting_algorithms;

public class SelectionSort {
    public static void sort (int arr[]) {
        int i = 0;
        for (i = 0; i < arr.length-1; i++) {
            int min = i;
            //int j = i;
            for (int j = i + 1; j <arr.length; j++) {
                if (arr[j] < arr[min]) {
                    min = j;
                }
                int temp = arr[i];
                arr[i] = arr[min];
                arr[min] = temp;

            }
        }
        System.out.println("After Sorting:");
        for ( i=0;i<arr.length;i++) {
            System.out.print(arr[i]+",");
        }
    }
    public static void main (String args[]) {
        int arr[] = {8,6,1,5,4,3,2};
        SelectionSort.sort(arr);
    }
}
