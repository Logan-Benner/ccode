#include <iostream>
#include <fstream>
#include <array>
#include <string>


using namespace std;
//const int arraylength = 26;
const int  arraylength = 1000;
array<string,arraylength> selectSort(array<string,arraylength>list);
void printArray(array<string,arraylength>list);

int main(){

	// load array from file 						
	int i;
	string p;
	array<string,arraylength> wordlist;
    ifstream filename("1000.txt");
    if(filename.is_open())
    {   for(i = 0; i < arraylength; ++i)
        {
            filename >> wordlist[i];
        }
    }
							
	// sorting
	array<string,arraylength>arraysorted;
	cout<<"Array unsorted"<<endl;
	//printArray(wordlist);
	cout<<"\n\nSelection Sort"<<endl;
	arraysorted = selectSort(wordlist);
	//printArray(arraysorted);
	printArray(arraysorted);
	cout<<"\n\n selection sort - arrayLength "<<arraylength<<endl;
    return 0;
}


array<string,arraylength> selectSort(array<string,arraylength>list){
	int n = list.size();
		//pos_min is short for position of min
		int swap = 0;
	int compare = 0;
		string temp;
        int pos_min,i,j;
        for (i=0; i < n-1; i++){
			pos_min = i;//set pos_min to the current index of array
                for (j=i+1; j < n; j++){
					if (list[j] < list[pos_min]){
						pos_min=j;
						compare++;
					}
					//pos_min will keep track of the index that min is in, this is needed when a swap happens
                }  
								//if pos_min no longer equals i than a smaller value must have been found, so a swap must occur
				if (pos_min != i){
					compare++;
					temp = list[i];
					list[i] = list[pos_min];
					list[pos_min] = temp;
					swap++;
				}
        }
		cout<<"compare "<<compare<<endl;
		cout<<"swap "<<swap<<endl;
        return list;
}


void printArray(array<string,arraylength>list){
	for (int i = 0;i < arraylength ;i++){
		cout<<list[i]<<endl;

	}
}
