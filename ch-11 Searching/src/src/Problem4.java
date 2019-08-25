import java.util.HashSet;
import java.util.Set;

public class Problem4 {
    static void checkDuplicates(int a[]) {
        //Set<Integer> unique = new HashSet<Integer>();
        for(int i=0;i<a.length-1;i++){

            if(a[Math.abs(a[i])]<0){
                System.out.println("\nDuplicates found at:"+i);
            }else
                //if (i < a.length-1) {
                //    //System.out.println("a[i]"+a[i] + "a[a[i]]"+a[a[i]]);
                    a[a[i]] = -a[a[i]];
               // }

        }
        System.out.println("Duplicate doesn't exist");
    }



    public static void main (String argsp[]) {
        int arr[] = {3,2,1,2,2,3,};
        //Arrays.sort(arr);
        checkDuplicates(arr);
        //int arr2[] = {1,2,3,4,5,6};
        //Arrays.sort(arr2);
        //checkDuplicates(arr2);
    }
}
