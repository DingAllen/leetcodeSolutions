// 这道题对于我而言，目前来说第二种解法是最优的，以后如果在这方面有灵感我会再来补写

// 这是我的第一反应，但使用排序算法无论是空间还是时间上的效率都不高
// 我第一遍审题的时候并没有注意到有序数组这样一个条件，这一点以后需要注意
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        int n = nums1.size();
        int temp[n];
        for(int i = 0; i < n; i++) {
            temp[i] = nums1[i];
        }
        mergeSort(temp, n);
        if(n % 2 == 0) {
            return (double(temp[n/2]) + double(temp[n/2 - 1])) / 2;
        } else {
            return temp[n/2];
        }
    }

private:

    template<typename  T>
    void __merge(T arr[], int l, int mid, int r){

        T aux[r-l+1];

        for( int i = l ; i <= r; i ++ )
            aux[i-l] = arr[i];

        int i = l, j = mid+1;
        for( int k = l ; k <= r; k ++ ){

            if( i > mid ){  
                arr[k] = aux[j-l]; j ++;
            }
            else if( j > r ){  
                arr[k] = aux[i-l]; i ++;
            }
            else if( aux[i-l] < aux[j-l] ) { 
                arr[k] = aux[i-l]; i ++;
            }
            else{  
                arr[k] = aux[j-l]; j ++;
            }
        }

    }

    template<typename T>
    void __mergeSort(T arr[], int l, int r){

        if( l >= r )
            return;

        int mid = (l+r)/2;
        __mergeSort(arr, l, mid);
        __mergeSort(arr, mid+1, r);
        __merge(arr, l, mid, r);
    }

    template<typename T>
    void mergeSort(T arr[], int n){

        __mergeSort( arr , 0 , n-1);
    }
};

// 当场完成归并排序最后一层，效率还可以
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;
        int sorted[n / 2 + 1];
        int l = 0, r = n1;

        for(int i = 0; i <= n / 2; i++) {

            if(l >= n1) {
                sorted[i] = nums2[r - n1];
                r++;
            } else if(r >= n) {
                sorted[i] = nums1[l];
                l++;
            } else if(nums1[l] <= nums2[r - n1]) {
                sorted[i] = nums1[l];
                l++;
            } else {
                sorted[i] = nums2[r - n1];
                r++;
            }
        }

        return (n % 2 == 0) ? (sorted[n / 2] + sorted[n / 2 - 1]) / 2.0 : sorted[n / 2];
    }

};

// 标准答案，执行起来效率略高，但和上面那个差不多
class Solution {
public:
        double MedNum(vector<int>& num)
        {
            double ret;
            size_t size = num.size();
            if(size == 1)
                return num[0];
            int med = size / 2;
            if (size% 2 == 0)
            {
                ret =  ((double)(num[med] + num[med - 1]) / 2);
            }
            else
                ret = num[med];
            
            return ret;
        }
   
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
     {
        double ret = -1;
        
        //定义最小数和最大数
        const int BDL_MIN_ = 0x80000000;
        const int BDL_MAX_ = 0x7fffffff;
    
    	//情况一：
        //如果这两个数组中有一个是空的，直接返回另一个的中位数即可
        if (nums1.empty())
            return MedNum(nums2);
        else if (nums2.empty())
            return MedNum(nums1);
        //情况二：
        //如果两个数组分别的中位数相等，那么这两个数的中位数就是这个中位数

        if(MedNum(nums1) == MedNum(nums2))
        	return MedNum(nums1);
        
        
        //情况三：
        //使用分治思想，二分查找方法
        int size1 = nums1.size();	//数组一的长度
        int size2 = nums2.size();	//数组二的长度
        int size0 = size1 + size2;	//两个数组的总长度
    
        //为了效率，要选择最短的数组做二分查找，使数组一为最短
        //如果第一个数组比第二个数组长，就要使两个数组交换
        //但是swap的时间复杂度使O(N+M),所以将两个数组交换位置再调一次函数即可
        if (size1 > size2)
            return findMedianSortedArrays(nums2, nums1);
        
        //设置二分查找的范围
        int cutL = 0;
        int cutR = size1;
    
        //这里将cut1初始为数组1的中位数
        int cut1 = size1 / 2 ;
        while (cut1 <= size1)
        { 
            cut1 = (cutR - cutL) / 2 + cutL;
			int cut2 = (size0 / 2) - cut1;
            double L1 = (cut1 == 0) ? BDL_MIN_ : nums1[cut1-1];
            double R1 = (cut1 == size1) ? BDL_MAX_ : nums1[cut1];
            double L2 = (cut2 == 0) ? BDL_MIN_ : nums2[cut2-1];
            double R2 = (cut2 == size2) ? BDL_MAX_ : nums2[cut2];
            
            //如果L1>R2，则cut1应该向左移，才能使数组1较多的数被分配到右边。
            if (L1 > R2)
                cutR = cut1-1;
            //如果L2 > R1，则cut1应该向右移，才能使数组1较多的数被分配到左边。
            else if (L2 > R1)
                cutL = cut1+1;
            //其他情况就是L1<=R2 L2<=R1，说明当前cut1和cut2的位置就是中位数了
            else
            {
            	//如果两个数组中元素的数量是偶数，那么中位数就应该是两个中位数的平均值
                if (size0 % 2 == 0)
                {
                    L1 = max(L1, L2);
                    R1 = min(R1, R2);
                    ret = (L1 + R1) / 2;
                    return ret;
                }
                //如果两个数组中元素的数量是奇数，中位数就是当前位置的右值
                else
                {
                    ret = min(R1, R2);
                    return ret;
                }
            }
        }
    
        return ret;
    }
};