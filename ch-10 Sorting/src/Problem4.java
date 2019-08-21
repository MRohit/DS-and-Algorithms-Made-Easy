import java.util.Arrays;

public class Problem4 {
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
    public static  void main (String argsp[] ){
        int arr[] = {5,5,5,5,8,8,8,8,8,8,8,8,7,7,7,7,6,6,6,5};
        checkWhoWinsElection(arr);

    }
}
