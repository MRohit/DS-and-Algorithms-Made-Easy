import java.util.Arrays;

public class Problem1 {
    static void checkDuplicates (int arr[]) {
        for (int i=0;i<arr.length;i++) {
            for (int j = i+1;j<arr.length;j++) {
                if (arr[i] == arr[j]) {
                    System.out.println("Duplicate exist");
                    return;
                }
            }
        }
        System.out.println("Duplicate doesn't exist");
    }
    public static void main (String argsp[]) {
        int arr[] = {7,6,5,4,3,2,1};

        checkDuplicates(arr);
        int arr2[] = {7,6,5,4,3,2,1,5,7};
        checkDuplicates(arr2);
    }
}
