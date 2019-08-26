import java.util.Arrays;

public class Problem6 {
    static void numberOccurringMaxTimes(int a[]) {
        int count = 1,maxCount = 0,candidate =a[0],maxCandidate = 0;
        Arrays.sort(a);
        for (int i=1;i<a.length;i++) {
            if (a[i] == candidate) {
                count ++;
            } else {
                candidate = a[i];
                count = 1;
            }
            if (count > maxCount) {
                maxCandidate = candidate;
                maxCount = count;
            }
        }
        System.out.println("Number occurring maximum number of times is:"+maxCandidate);
    }



    public static void main (String argsp[]) {
        int arr[] = {3,2,1,2,2,3,};

        numberOccurringMaxTimes(arr);

    }
}
