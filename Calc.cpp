/*
 * Calc.cpp
 *
 *  Created on: 18 Oct 2020
 *      Author: yeu0202
 */

#include <iostream>
using namespace std;


// finds how multiples of 3 numbers can add up to a sum
// only works for integers. So if you have decimals then find an LCM or something
void find3NumbersToSum( int target_sum, int number_1, int number_2, int number_3){
	int sum = 0;
	int target = target_sum; // target number; the number you want to add up to
	int numbers [3] = {number_1,number_2,number_3}; // the three numbers you want to use to add
	int num_first_number = floor(target/numbers[0]);
	int max = 0;
	int min = 10000;
	int found_count = 0;

	while (num_first_number >= 0){
		sum = num_first_number * numbers[0];
		int num_second_number = floor((target - sum)/numbers[1]);
		while (num_second_number >= 0){
			sum = num_second_number*numbers[1] + num_first_number*numbers[0];
			int num_third_number = 0;
			while(sum <= target){
				sum += numbers[2];
				num_third_number++;
			}
			num_third_number--;
			sum -= numbers[2];
			//cout << num_first_number << "*" << numbers[0] << " + " << num_second_number << "*" << numbers[1] << " + " << num_third_number << "*" << numbers[2] << " = ";
			//cout << sum << endl;
			if(sum == target){
				//cout << "FOUND ONE" << endl << endl;
				found_count++;
			}
			if(sum > max) max = sum;
			if(sum < min) min = sum;
			num_second_number--;
		}
		num_first_number--;
	}

	if(found_count == 0){
		cout << "max is " << max << endl;
		cout << "min is " << min << endl;
	}
	cout << "We found " << found_count  << " results!" << endl;



	// basically repeated the code because i had to use found_count for dynamic array size creation
	// I think this can be avoided if you use a dynamically sized array but I don't know if c++ has that
	// if it does then I don't know about it or I forgot and I'm not bothered to look it up

	cout << endl << endl;

	sum = 0;
	num_first_number = floor(target/numbers[0]);
	int results [found_count][3];
	int results_index = 0;

	while (num_first_number >= 0){
		sum = num_first_number * numbers[0];
		int num_second_number = floor((target - sum)/numbers[1]);
		while (num_second_number >= 0){
			sum = num_second_number*numbers[1] + num_first_number*numbers[0];
			int num_third_number = 0;
			while(sum <= target){
				sum += numbers[2];
				num_third_number++;
			}
			num_third_number--;
			sum -= numbers[2];
			if(sum == target){
				results[results_index][0] = num_first_number;
				results[results_index][1] = num_second_number;
				results[results_index][2] = num_third_number;
				results_index++;
			}
			num_second_number--;
		}
		num_first_number--;
	}

	for(int i=0; i<found_count; i++){
		for(int j=0; j<3; j++){
			if(j<2) cout << numbers[j] << "*" << results[i][j] << " + ";
			else cout << numbers[j] << "*" << results[i][j];
		}
		cout << " = " << target << endl;
	}
}


int main(){
	find3NumbersToSum(616, 38, 53, 78);
}
