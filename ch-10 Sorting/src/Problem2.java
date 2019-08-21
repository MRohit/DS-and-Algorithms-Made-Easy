import java.util.Arrays;

public class Problem2 {
    public static  void main (String argsp[] ){
        int arr[] = {5,3,8,7,6,5};
        boolean bool = false;
        Arrays.sort(arr);
        for (int i=0;i<arr.length-1;i++) {
            if (arr[i] == arr[i+1]) {
                System.out.println("Duplicate exists");
            }
        }
    }
}
