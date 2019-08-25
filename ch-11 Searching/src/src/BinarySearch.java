import java.util.Arrays;

public class BinarySearch {

    static boolean binarySearch (int arr[], int k) {
        int mid, low = 0, high =arr.length - 1;
        while (low <= high) {
            mid = low + (high-low)/2;
            if (arr[mid] == k)
                return true;
            else if (arr[mid] < k) {
                low = mid + 1;
            } else  {
                high = mid - 1;
            }
        }
        return false;
    }
    static boolean recursiveBinarySearch (int arr[], int low, int high, int k) {
        int mid = low + (high-low)/2;
        if (high >= 1) {
            if (arr[mid] == k)
                return true;
            else if (arr[mid] < k) {
                return recursiveBinarySearch(arr, mid + 1, high, k);
            } else {
                return recursiveBinarySearch(arr, low, mid - 1, k);
            }
        }
        return false;
    }
    public static void main (String argsp[]) {
        int arr[] = {7,6,5,4,3,2,1};
        Arrays.sort(arr);
        int k = 4;
        System.out.println("Does element exist:"+binarySearch(arr,k));
        k = -1;
        System.out.println("Does element exist:"+binarySearch(arr,k));
        k = 4;
        System.out.println("Recursion Does element exist:"+recursiveBinarySearch(arr,0,arr.length-1,k));
        k = -1;
        System.out.println("Recursion Does element exist:"+recursiveBinarySearch(arr,0,arr.length-1,k));
    }
}
