package sorting_algorithms;

public class BubbleSort {
    public static void sort(int  arr[]) {
        int i,j,pass;
        for (pass = arr.length-1; pass >=0; pass--) {
            for (i = 0; i <= pass-1;i++) {
                if (arr[i] > arr[i+1]) {
                    int temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                }
            }
        }
        System.out.println("After Sorting:");
        for ( i=0;i<arr.length;i++) {
            System.out.print(arr[i]+",");
        }

    }
    public static  void main (String args[]) {
        int arr[] = {6,8,1,5,4,3,2};
        BubbleSort.sort(arr);
    }
}
