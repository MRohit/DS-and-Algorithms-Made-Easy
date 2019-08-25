public class Problem5 {
    static void numberOccurringMaxTimes(int a[]) {
        int count = 0,maxCount = 0,candidate,maxCandidate = 0;
        for (int i=0;i<a.length;i++) {
            count = 1;
            candidate = a[i];
            for (int j = i+1;j < a.length;j++) {
                if (a[i] == a[j]) {
                    count++;

                }
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
