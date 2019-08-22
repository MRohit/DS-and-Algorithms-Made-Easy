import java.util.Arrays;

public class Problem18 {
    // A utility function to print an array
    void printArr(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
            System.out.print(arr[i]+" ");
    }
    static void maximumOccurringNumber (int arr[]) {
        int count = 1;
        Arrays.sort(arr);
        int maxCount = 0, maxNumber = 0, num = arr[0];
        for (int i=1;i<arr.length;i++) {
            if (arr[i] == num) {
                count++;
            } else {
                num = arr[i];
                count = 1;
            }
            if (count > maxCount) {
                maxCount = count;
                maxNumber = arr[i];
            }
        }
        System.out.println("Max time occurring number:"+maxNumber);
    }
    public static void main(String args[])
    {
        Problem18 ob = new Problem18();

        // Since array size is 7, elements should be from 0 to 48
        int arr[] = {2,2,1,1,2,2,0,0,1,2,0,2,1,0};
        int n = arr.length;
        System.out.println("Given array");
        ob.printArr(arr, n);
        maximumOccurringNumber( (arr));

        //System.out.println("Sorted array");
        //ob.printArr(arr, n);
    }
}
