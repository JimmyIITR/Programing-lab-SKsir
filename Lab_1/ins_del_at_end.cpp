
#include"singly_list.cpp"
#include"dynamic_array.cpp"
#include<iostream>

int main()
{
	long int n;
	//cout << "Enter Test Cases"<<endl;
	cin >> n;
	int it = 0;
	float prob_ins = 0.1;
	float prob_del = 0.9;

	// Arrays to store time duration
	double time_1[10], time_2[10];

	printf("A_size, Dynamic_Array, Singly_List\n");

	// Performs 10 iterations
	while (it++ < 10) {
		long int a[n], b[n];
		DynamicArray<int> vec;
		SinglyList<int> list;
		// generating n random numbers
		// storing them in arrays a, b
		int i,j;
		int size_ins ;
		int size_del ;
		for (i = 0; i < n; i++) {
			long int no = rand() % n + 1;
			a[i] = no;
			b[i] = no;
		}
		
		for(j = 0;j < n;j++){
			vec.push_back(a[j]);	
			list.push_back(b[j]); 
		}
			
		
		size_ins += prob_ins * n;
		size_del = prob_del * n;
		
		// using clock_t to store time
		clock_t start, end;

		// Dynamic Array
		start = clock();
		
		for(int i = j;i < size_ins;i++)
			vec.push_back(rand() % size_ins + 1);
		
		for(int i = 0;i< size_del;i++){
			int idx = vec.size - 1;
			vec.delete_at_loc(idx);
		}
			
		
		end = clock();
		time_1[it] = ((double)(end - start));

		// Singly List
		start = clock();
		
		for(int i = j;i < size_ins;i++)
                        list.push_back(rand() % size_ins + 1);
                for(int i = 0;i < prob_del;i++)
                	list.delete_end();
                        
		end = clock();
		time_2[it] = ((double)(end - start));

		// type conversion to long int
		// for plotting graph with integer values
		cout << prob_ins*100 <<"%\t"<<(long int)time_1[it]<<"\t\t"<<(long int)time_2[it]<<endl;

		// increases the size by prob_ins and decrease the size by prob_del
		prob_ins += 0.1;
		prob_del -= 0.1;
	}

	return 0;
}

