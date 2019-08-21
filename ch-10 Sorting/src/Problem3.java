import java.util.Arrays;

public class Problem3 {

    static void checkWhoWinsElection (int arr[]) {
        int counter = 0,candidate = 0,maxCandidate = 0, maxVotes = 0;
        for (int i=0;i<arr.length;i++) {
            candidate = arr[i];
            counter = 0;
            for (int j = i+1;j<arr.length;j++) {
                if (arr[i] == arr[j]) {
                    counter ++;

                }
            }
            if (counter > maxVotes) {
                maxVotes = counter;
                maxCandidate = candidate;
            }
        }
        System.out.println("Candidate who won the election is:"+maxCandidate);
    }
    public static  void main (String argsp[] ){
        int arr[] = {5,5,5,5,8,8,8,8,8,8,8,8,7,7,7,7,6,6,6,5};
        checkWhoWinsElection(arr);

    }
}
