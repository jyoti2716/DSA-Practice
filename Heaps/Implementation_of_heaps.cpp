//This is Implementation of Heaps using Array
#include<iostream>
#include<queue>
using namespace std;

//Creating a Class Name Heap
class heap{
    public:
    int arr[100];//random size
    int size;

    //constructor
    heap(){
        this->size = 0;
        arr[0] = -1;
    }


    void insert(int val){
        size = size+1;
        arr[size] = val;
        int index = size;

        while(index > 1){
            int parent = index/2;

            if(arr[index] > arr[parent]){
                swap(arr[index] , arr[parent]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    //deletion code 
    void deletefromHeap(){
        if(size == 0){
            cout<<"Heap is empty"<<endl;
            return;
        }

        //step 1: put root node at last index of array
        arr[1] = arr[size];
        size--; //so that we can access it

        int i = 1;
        while(i < size){
            int leftindex = 2*i;
            int rightindex = 2*i + 1;

            //compare and swap
            if(leftindex < size && arr[leftindex] > arr[i]){
                swap(arr[leftindex] , arr[i]);
                i = leftindex;
            }
            else if(rightindex < size && arr[rightindex] > arr[i]){
                swap(arr[rightindex] , arr[i]);
                i = rightindex;
            }
            else{
                return;
            }
        }

    }
};

void heapify(int arr[] , int n , int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i +1 ;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest] , arr[i]);
        heapify(arr , n , largest);
    }
} 

void heapSort(int arr[] , int n){
    int size = n;

    while(size > 1) {
        swap(arr[size] ,arr[1]);
        size--;

        heapify(arr , size , 1);
    }
}

int main(){
    heap h ;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deletefromHeap();
    h.print();


    return 0;
}