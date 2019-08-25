import java.util.Arrays;
import java.util.*;

public class Problem3 {
    static void checkDuplicates(int arr[]) {
        Set<Integer> unique = new HashSet<Integer>();
        for (int i = 0; i < arr.length - 1; i++) {
            if (unique.contains(arr[i])) {
                System.out.println("Duplicate exist");
                return;
            } else {
                unique.add(arr[i]);
            }

        }
        System.out.println("Duplicate doesn't exist");
    }



    public static void main (String argsp[]) {
        int arr[] = {7,6,5,4,3,2,1};
        //Arrays.sort(arr);
        checkDuplicates(arr);
        int arr2[] = {7,6,5,4,3,2,1,5,7};
        //Arrays.sort(arr2);
        checkDuplicates(arr2);
    }
}
