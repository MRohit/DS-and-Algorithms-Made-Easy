public class Problem1 {
    public static  void main (String argsp[] ){
        int arr[] = {5,3,8,7,6,5};
        boolean bool = false;
        for (int i=0;i<arr.length -1;i++) {
            for(int j = i+1;j<arr.length;j++) {
                if (arr[i] == arr[j]) {
                    System.out.println("Duplicate exists");
                }
            }
        }
    }
}
