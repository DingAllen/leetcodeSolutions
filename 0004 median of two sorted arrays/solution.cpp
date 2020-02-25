// ���������Ҷ��ԣ�Ŀǰ��˵�ڶ��ֽⷨ�����ŵģ��Ժ�������ⷽ��������һ�������д

// �����ҵĵ�һ��Ӧ����ʹ�������㷨�����ǿռ仹��ʱ���ϵ�Ч�ʶ�����
// �ҵ�һ�������ʱ��û��ע�⵽������������һ����������һ���Ժ���Ҫע��
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

// ������ɹ鲢�������һ�㣬Ч�ʻ�����
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

// ��׼�𰸣�ִ������Ч���Ըߣ����������Ǹ����
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
        
        //������С���������
        const int BDL_MIN_ = 0x80000000;
        const int BDL_MAX_ = 0x7fffffff;
    
    	//���һ��
        //�����������������һ���ǿյģ�ֱ�ӷ�����һ������λ������
        if (nums1.empty())
            return MedNum(nums2);
        else if (nums2.empty())
            return MedNum(nums1);
        //�������
        //�����������ֱ����λ����ȣ���ô������������λ�����������λ��

        if(MedNum(nums1) == MedNum(nums2))
        	return MedNum(nums1);
        
        
        //�������
        //ʹ�÷���˼�룬���ֲ��ҷ���
        int size1 = nums1.size();	//����һ�ĳ���
        int size2 = nums2.size();	//������ĳ���
        int size0 = size1 + size2;	//����������ܳ���
    
        //Ϊ��Ч�ʣ�Ҫѡ����̵����������ֲ��ң�ʹ����һΪ���
        //�����һ������ȵڶ������鳤����Ҫʹ�������齻��
        //����swap��ʱ�临�Ӷ�ʹO(N+M),���Խ��������齻��λ���ٵ�һ�κ�������
        if (size1 > size2)
            return findMedianSortedArrays(nums2, nums1);
        
        //���ö��ֲ��ҵķ�Χ
        int cutL = 0;
        int cutR = size1;
    
        //���ｫcut1��ʼΪ����1����λ��
        int cut1 = size1 / 2 ;
        while (cut1 <= size1)
        { 
            cut1 = (cutR - cutL) / 2 + cutL;
			int cut2 = (size0 / 2) - cut1;
            double L1 = (cut1 == 0) ? BDL_MIN_ : nums1[cut1-1];
            double R1 = (cut1 == size1) ? BDL_MAX_ : nums1[cut1];
            double L2 = (cut2 == 0) ? BDL_MIN_ : nums2[cut2-1];
            double R2 = (cut2 == size2) ? BDL_MAX_ : nums2[cut2];
            
            //���L1>R2����cut1Ӧ�������ƣ�����ʹ����1�϶���������䵽�ұߡ�
            if (L1 > R2)
                cutR = cut1-1;
            //���L2 > R1����cut1Ӧ�������ƣ�����ʹ����1�϶���������䵽��ߡ�
            else if (L2 > R1)
                cutL = cut1+1;
            //�����������L1<=R2 L2<=R1��˵����ǰcut1��cut2��λ�þ�����λ����
            else
            {
            	//�������������Ԫ�ص�������ż������ô��λ����Ӧ����������λ����ƽ��ֵ
                if (size0 % 2 == 0)
                {
                    L1 = max(L1, L2);
                    R1 = min(R1, R2);
                    ret = (L1 + R1) / 2;
                    return ret;
                }
                //�������������Ԫ�ص���������������λ�����ǵ�ǰλ�õ���ֵ
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