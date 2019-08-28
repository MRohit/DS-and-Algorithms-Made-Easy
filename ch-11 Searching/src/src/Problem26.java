import java.util.Arrays;

public class Problem26 {
    static void findTwoNumbers (int arr[] ,int k) {
        Arrays.sort(arr);
        int i,j;
        for (i=0,j=arr.length-1;i<j;) {
            int temp = arr[i] + arr[j];
            if (temp == k) {
                System.out.println("\nTwo numbers whose sum is equal to:"+k+" are " +arr[i]+" & "+arr[j]);
                return;
            }
            if (temp < k) {
                i++;
            } else {
                j--;
            }
        }
        System.out.println("No such number exist");
    }
    public static void main (String argsp[]) {
        int arr[] = {8,3,4,2,1,7,6,8,3,4,2,1,7};
        int k = 13;
        findTwoNumbers(arr, k);

    }
}
