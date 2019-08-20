package sorting_algorithms;

public class MergeSort {
    public static void merge (int arr[],int temp[] ,int left, int right, int mid) {


        int i,leftEnd = mid - 1, temp_pos = 0;
        //int []temp = new int[arr.length];
        int size = right-left + 1;
        while (left <= leftEnd && mid <= right) {
            if (arr[left] <= arr[mid]) {
                temp[temp_pos] = arr[left];
                left++;
            } else {
                temp[temp_pos] = arr[mid];
                mid++;
            }
            temp_pos++;
        }

        while (left <= leftEnd) {
            temp[temp_pos] = arr[left];
            left++;
            temp_pos++;
        }

        while (mid <= right) {
            temp[temp_pos] = arr[mid];
            mid++;
            temp_pos++;
        }
        for(i=0;i<=size;++i){
            arr[right]=temp[right];
            right--;
        }
        System.out.println("After Sorting:");
        for ( i=0;i<arr.length;i++) {
            System.out.print(arr[i]+",");
        }
    }
    public static void sort (int arr[],int temp[], int left, int right) {
        int mid = 0;
        if (left < right) {
            mid = (right + left) /2;
            sort (arr,temp,left,mid);
            sort (arr,temp,mid+1, right);
            merge (arr, temp,left, right, mid+1);
        }

    }
    public static void main (String args[]) {
        int arr[] = {8,6,1,5,4,3,2};
        int [] temp = new int[arr.length];
        MergeSort.sort(arr, temp,0 ,arr.length - 1);
    }
}
