import java.util.Arrays;

public class Problem5 {
    static void checkWhoWinsElection (int nums[]) {
        int count = 1;
        Arrays.sort(nums);
        int maxCandidate = nums[0], candidate = nums[0],maxVotes = 0;
        for (int i = 1;i<nums.length;i++) {
            if (nums[i] == candidate) {
                count ++;
            } else {
                candidate = nums[i];
                count = 1;
            }

            if (count > maxVotes) {
                maxCandidate = candidate;
                maxVotes = count;
            }
        }
        System.out.println("Candidate who won the election is:"+candidate);
    }
    static void countingSort (int nums[], int arr[]) {
        int []c = new int[11];
        int k = 10;

        // initialize the count of each candidate to 0
        for (int i = 0;i<k;i++) {
            c[i] = 0;
        }
        // increment the count of its index based on candidate's value
        for (int j = 0; j < nums.length;j++) {
            c[nums[j]] = c[nums[j]] + 1;
        }

        for (int i = 1; i < k; i++) {
            c[i] = c[i] + c[i-1];
        }

        for (int i = 0; nums[i] != 0; ++i) {
            arr[c[nums[i]] - 1] = nums[i];
            c[nums[i]] = c[arr[i]] - 1;
        }

    }
    public static  void main (String argsp[] ){
        int arr[] = {5,5,5,5,8,8,8,8,8,8,8,8,7,7,7,7,6,6,6,5};
        int[] nums =new int[arr.length];
        // countingSort(arr, nums);
        Arrays.sort(arr);
        System.out.println("After Sorting:");
        for (int i=0;i<arr.length;i++) {
            System.out.print(arr[i]+",");
        }
        checkWhoWinsElection(arr);

    }
}
