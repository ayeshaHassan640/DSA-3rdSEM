#include <iostream>
using namespace std;
#define MAX 100
int heap[MAX];
int size = 0;

// MAX HEAP INSERT
void insertMax(int val) {
    int index = size;
    if (size >= MAX) {  
        cout << "Heap is full!" << endl;
        return;
    }
    
    heap[index] = val;
    size++;
	//upheapify
    while (index >0) {
        int parent = (index - 1) / 2;

        if (heap[parent] < heap[index]) {
            swap(heap[parent], heap[index]);
            index = parent;
        } else 
			break; 
    }
}

// MIN HEAP INSERT
void insertMin(int val) {
    int index = size;
    if (size >= MAX) {  // ? ?? check ????? ??
        cout << "Heap is full!" << endl;
        return;
    }
    heap[index] = val;
    size++;

	//UPHEAPIFY
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap[parent] > heap[index]) {
            swap(heap[parent], heap[index]);
            index = parent;
        } else break;
    }
}
//UPHEAPIFY				BOTTOM TO TOP
//void upHeapify(int i,int n){
//	if (i == 0) return;  // root par pahunch gaye, rukko
//	int parent=(i-1)/2;
//	if (heap[i] > heap[parent])
//		swap(heap[i],heap[parent]);
//	}
//	upHeapify(parent,n);
//

//DOWNHEAPIFY		(MAX HEAP)  	//TOP TO BOTTOM
void heapifyDownMax(int i, int n) {		// n = size (global variable jo aapne banaya hai)
    while (2 * i + 1 < n) {		//jb tk left chlid exist krta hay
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;		//stores index instead of an exact value

        if (heap[left] > heap[largest])
            largest = left;

        if (right < n && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            i = largest;
        } else 
			break;
    }
}
//DOW`NHEAPIFY		(MIN HEAP)  	//TOP TO BOTTOM
void heapifyDown(int i, int n) {		// n = size (global variable jo aapne banaya hai)
    while (2 * i + 1 < n) {		//jb tk left chlid exist krta hay
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;		//stores index instead of an exact value

        if (heap[left] < heap[smallest])
            smallest = left;

        if (right < n && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            i = smallest;
        } else break;
    }
}

// DELETE ROOT 
void deleteRoot() {
    if (size == 0) {
        cout << "Heap empty\n";
        return;
    }

    heap[0] = heap[size - 1];
    size--;

    heapifyDownMax(0, size);
}

//HEAP SORT (ASCENDING)	//Phase 1: Array ko Max Heap banao
				//Phase 2: Ek ek karke max nikalo aur end mein rakho
void heapSort() {
	
    //Build Max Heap......
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapifyDownMax(i, size);
    }

    // sorting
    for (int i = size - 1; i > 0; i--) {
        swap(heap[0], heap[i]);		//sbse max ko last me bhjo, then downheapify
        heapifyDownMax(0, i);
    }
}
void Heapsort(){
	//build min heap	
	for (int i = size / 2 - 1; i >= 0; i--) {
    heapifyDown(i, size);
}
	//sorting
	for (int i = size - 1; i > 0; i--) {
    swap(heap[0], heap[i]);   // min goes to end
    heapifyDown(0, i);
}
}

// DISPLAY
void display() {
    if (size == 0) {
        cout << "Heap empty\n";
        return;
    }

    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}
//level by level display
void LevelByLevel(){
    int count = 1;
    int printed = 0;
    
    for(int i=0; i<size; i++){
        cout<< heap[i]<<" ";
        printed++;   //1

        if(printed==count){
            cout<< endl;
            count=count*2;
            printed = 0;
        }
    }
}

//  MAIN
int main() {

    insertMax(50);
    insertMax(70);
    insertMax(4);
    insertMax(100);
    insertMax(200);

    cout << "Max Heap: ";
    display();

//    deleteRoot();
//    cout << "After delete: ";
//    display();
//
//    heapSort();
//    cout << "After Heap Sort: ";
//    display();
    cout << "Display level by level: ";
    LevelByLevel();

    return 0;
}
