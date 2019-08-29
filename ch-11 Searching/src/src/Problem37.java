import java.util.Arrays;

public class Problem37 {
    static int findMaximum (int arr[],int first, int last) {

        while (first <= last) {
            if (first == last)
                return arr[first];
            else if (first == last-1) {
                return Math.max(arr[first],arr[last]);
            } else {
                int mid = first + (last-first)/2;
                if (arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]) {
                    return arr[mid];
                } else if (arr[mid] > arr[mid+1] && arr[mid] < arr[mid-1]) {
                    last = mid-1;
                } else if (arr[mid] > arr[mid-1] && arr[mid] < arr[mid+1]) {
                    first = mid+1;
                } else {
                    return Integer.MIN_VALUE;
                }
            }
        }
        return -1;
    }
    public static void main (String argsp[]) {
        int arr[] = {8,10,20,80,100,200,400,500,3,2,1};
        System.out.println("MaximumNumber is:"+findMaximum(arr, 0, arr.length - 1));

    }
}
