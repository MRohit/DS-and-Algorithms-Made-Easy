public class Problem17 {
    static void findMissingNumber (int nums[], int n) {
        int x1 = nums[0],x2 = 1;
        for (int i=1;i<nums.length;i++) {
            x1 ^= nums[i];
        }
        for (int i=2;i<=n;i++) {
            x2 ^= i;
        }
        //return m;
        System.out.println("Missing number is:"+(x1^x2));
    }
    public static void main (String argsp[]) {
        int arr[] = {8,3,4,2,1,7,6};

        findMissingNumber(arr,8);

    }
}
