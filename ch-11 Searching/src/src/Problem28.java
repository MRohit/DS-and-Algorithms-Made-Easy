import java.util.Arrays;
import java.util.*;

public class Problem28 {
    static void findTwoNumbers (int arr[] ,int k) {
        Set<Integer> set = new HashSet<Integer>();
        for (int i=0;i<arr.length;i++) {
            if (set.contains(k-arr[i])) {
                System.out.println("\nTwo numbers whose sum is equal to:"+k+" are " +arr[i]+" & "+(k-arr[i]));
            }
            set.add(arr[i]);
        }

    }
    static void findPairsFromTwoArrays(int arr1[], int arr2[], int k) {
        Set<Integer> set = new HashSet<Integer>();
        for (int num:arr1)
            set.add(num);

        for (int num:arr2) {
            if (set.contains(k-num)) {
                System.out.println("\nTwo numbers whose sum is equal to:"+k+" are " +num+" & "+(k-num));

            }
        }
    }
    static void findDistinctPairsWithDifferenceK (int arr[], int k) {
        Arrays.sort(arr);
        int l=0,r=0,count=0;
        while (r < arr.length) {
            if (arr[r] - arr[l] == k) {
                count++;
                l++;
                r++;
            }
            else if (arr[r] - arr[l] > k) {
                l++;
            } else {
                r++;
            }
        }
        System.out.println("Distinct pairs with difference "+k+" is:"+count);
    }
    public static void main (String argsp[]) {
        int arr[] = {8,3,4,2,1,7,6,8,3,4,2,1,7};
        int k = 13;
        findTwoNumbers(arr, k);

        int arr1[] = { 1, 0, -4, 7, 6, 4 };
        int arr2[] = { 0, 2, 4, -3, 2, 1 };
        int x = 8;
        findPairsFromTwoArrays (arr1,arr2,x);

        int arr3 [] = {4,5,3,2,1};
        k = 3;
        findDistinctPairsWithDifferenceK(arr3, k);

    }
}
