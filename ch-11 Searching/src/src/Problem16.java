import java.util.*;

public class Problem16 {
    static void findMissingNumber (int arr[]) {
        int n = 8;
        int totalSum = n * (n+1)/2, sum = 0;
        for (int i=0;i<arr.length;i++) {
            sum+=arr[i];
        }
        System.out.println("Missing number is:"+(totalSum-sum));
    }
    public static void main (String argsp[]) {
        int arr[] = {8,3,4,2,1,7,6};

        findMissingNumber(arr);

    }
}
