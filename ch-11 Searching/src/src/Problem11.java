import java.util.*;

public class Problem11 {
    static void firstRepetitiveElement (int arr[]) {
        int min = -1;
        Set<Integer> set = new HashSet<Integer>();
        for (int i = arr.length - 1;i>=0;i--) {
            if (set.contains(arr[i])) {
                min = i;
            } else {
                set.add(arr[i]);
            }
        }
        if (min != -1) {
            System.out.println("First Repetitive number is:"+arr[min]);
        } else {
            System.out.println("No such element exist");
        }
    }
    public static void main (String argsp[]) {
        int arr[] = {3,2,1,2,2,3,};

        firstRepetitiveElement(arr);

    }
}
