public class Problem39 {
    static int findFirstOne (int arr[],int low, int high) {
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (arr[mid] == 1 && (mid ==0 || arr[mid-1] == 0))
                return mid;
            else if (arr[mid] == 1)
                high = mid-1;
            else
                low = mid+1;
        }
        return -1;

    }
    static int posOfFirstOne (int arr[]) {
        int l = 0,h = 1;
        while (arr[h] == 0) {
            l = h;
            h = 2*h;
        }
        return findFirstOne(arr,l,h);
    }
    static int findFirstZero (int arr[],int low, int high) {
        while (low <= high) {
            int mid = low + (high-low)/2;

            if (arr[mid] == 0 && (mid == 0 || arr[mid-1] == 1))
                return mid;
            else if (arr[mid] == 0)
                high = mid-1;
            else
                low = mid+1;
        }
        return -1;

    }
    static int posOfFirstZero (int arr[]) {
        int l = 0,h = 1;
        while (arr[h] == 1) {
            l = h;
            h = 2*h;
        }
        return findFirstZero(arr,l,h);
    }
    public static void main (String argsp[]) {
        int arr[] = {0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1};
        System.out.println("Position of first one in infinite sorted array is:"+posOfFirstOne(arr));
        int arr2[] = {1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0};
        System.out.println("Position of first zero in infinite sorted array is:"+posOfFirstZero(arr2));
    }
}
