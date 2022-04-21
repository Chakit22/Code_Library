void quickSort(int arr[], int low, int high)
{
    // code heref
    if(low < high){
        
        int par = partition(arr,low,high);
        quickSort(arr,low,par-1);  //don't pass the element which is alreayd partioned;
        quickSort(arr,par+1,high);
    }
}
public:  
int partition (int arr[], int low, int high)
{
   // Your code here
   int size = high - low + 1;
   int i=low;
   int pivot = arr[low];
   int j=high;
  
  while(i<j)
  { 
   do{
       i++;
   }while(i<=high and arr[i]<=pivot);
   
   while(j>=0 and arr[j]>pivot) j--;
   
   if(i<j)
   swap(arr[i],arr[j]);
  }
   swap(arr[low],arr[j]);
   return j;
}
