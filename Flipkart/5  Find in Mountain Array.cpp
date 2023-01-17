
class Solution {
public:
        int binarySearch2(int target,MountainArray &mountainArr,int low,int high) {
         while(low <= high) {
            int mid = low + (high-low)/2;
             if(mountainArr.get(mid) == target) {
                 return mid;
            }
            else if(mountainArr.get(mid) > target) {
                low = mid+1;
            }
            else
            high = mid-1;
        }
        return -1;
    }
    int binarySearch1(int target,MountainArray &mountainArr,int low,int high) {
         while(low <= high) {
            int mid = low + (high-low)/2;
             if(mountainArr.get(mid) == target) {
                 return mid;
            }
            else if(mountainArr.get(mid) > target) {
                high = mid-1;
            }
            else
            low = mid+1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int low = 0 , high = n-1;
        while(low < high) {
            int mid = low + (high-low)/2;
             if(mountainArr.get(mid) > mountainArr.get(mid+1)) {
                high = mid;
            }
            else {
                low = mid+1;
            }
        }
        int peakIdx = high;
        low = 0;
        high = peakIdx;   
        int val1 = binarySearch1(target,mountainArr,0,high);
        low = peakIdx+1 ;
         high = n-1; 
                 if(val1 != -1 ) {
            return val1;
        }
        int val2 = binarySearch2(target,mountainArr,low,high);


        if(val2 != -1) {
            return val2;
        }

        return -1;

    }
};
