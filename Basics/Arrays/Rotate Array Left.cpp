class Solution{    
private:
    
    void reverse(int arr[],int low,int high)
    {
        while(low<high)
        {
            swap(arr[low++],arr[high--]);
        }
    }
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n)
    {
        // code here
        d=d%n;
        reverse(arr,0,d-1);
        reverse(arr,d,n-1);// minus 1 because index starts from 0
        reverse(arr,0,n-1);
    }
};    

