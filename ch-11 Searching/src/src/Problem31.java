import java.util.Arrays;

public class Problem31 {

    static void findPairsWhoseSumClosestToZero (int arr[]) {
        Arrays.sort(arr);
        int l=0,r=arr.length-1,x=0,y=0,min = Integer.MAX_VALUE;
        while (l < r) {
            int sum = arr[l] + arr[r];

            if (Math.abs(sum) < Math.abs(min)) {
                min = sum;
                x = arr[l];
                y = arr[r];
            }
            if (sum < 0) {
                l++;
            } else {
                r--;
            }
        }
        System.out.println ("Numbers whose sum is closest to zero are:"+x+" & "+y+ " and their sum is:"+min);
    }
    public static void main (String argsp[]) {
        int arr[] = {1, 60, -10, 70, -80, 85};
        findPairsWhoseSumClosestToZero(arr);

    }
}
