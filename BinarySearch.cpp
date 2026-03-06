#include <iostream>
using namespace std;

int main(){

    bool found = false;
    int n;

    cout << "Enter size of an array" << endl;
    cin >> n;

    int array[n];

    cout << "Enter " << n << " elements (sorted for binary search): ";
    for(int i = 0; i < n; i++)
        cin >> array[i];

    int searchFor;
    cout << "Enter number to search: ";
    cin >> searchFor;

    int lowerIdx = 0;
    int higherIdx = n - 1;

    while(lowerIdx <= higherIdx){

        int mid = lowerIdx + (higherIdx - lowerIdx) / 2;

        if(array[mid] == searchFor){
            found = true;
            cout << "Found at index: " << mid << endl;
            break;
        }
        else if(array[mid] > searchFor){
            higherIdx = mid - 1;
        }
        else{
            lowerIdx = mid + 1;
        }
    }

    if(!found){
        cout << "Value not found";
    }

    return 0;
}
