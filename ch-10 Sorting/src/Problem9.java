import java.util.Arrays;

public class Problem9 {
    static boolean areTwoElementsPresent (int arr[], int sum) {
        Arrays.sort(arr);
        int l = 0,h = arr.length - 1;
        while (l < h) {
            if (arr[l] + arr[h] == sum)
                return true;
            if (arr[l]+ arr[h] < sum) {
                l++;
            } else {
                h--;
            }
        }
        return false;
    }
    public static void main (String args[]) {
        // find if array contains two elements whose sum is equal to k; a+b = k
        int arr[] = {5,8,4,3,2,1};
        int k = 12;

        System.out.println("Does array has two elements whose sum is equal to "+k+":"+areTwoElementsPresent( arr,k));
        k = 99;

        System.out.println("Does array has two elements whose sum is equal to "+k+":"+areTwoElementsPresent( arr,k));
    }
}
