
#include <iostream>
#include <ctime>
#include <math.h>
#include <vector>
using namespace std;

void average_variance(vector<int>& sample, int num) {
	double sum = 0;
	double sp = 0;
	for (int i = 0; i < num; i++) {
		sum += sample[i];
	}
	for (int i = 0; i < num; i++) {
		sp += pow((double)sample[i] - ((double)sum/(double)num),2);
	}	
	cout << "average = " << (double)sum/(double)num << endl;
	cout << "variance = " << (double)sp/(double)num << endl;
}
void max_min(vector<int>& sample, int num) {
	int max = sample[0];
	int min = sample[0];
	for (int i = 0; i < num; i++) {
		if (max < sample[i]) { //min
			max = sample[i];
		}	
		if (min > sample[i]) { //max
			min = sample[i];
		}
	}	
	cout << "max = " << max << endl;
	cout << "min = " << min << endl;	
}
void mode_median(vector<int>& sample, int num) {
	int mode = 0;
	int count[num]; //search　mode 
	for (int i = 0; i < num; i++) {
		count[i] = 0;
	}		
	int max = 0;
	for (int i = 0; i < num; i++) {
	  for (int j = 0; j < num; j++) { 	
	    if (sample[i] == sample[j]) {
				count[i]++;
			}		
   	}
	  if (max < count[i]) {
			max = count[i];
		}
	}
	for (int i = 0; i < num; i++) {	
		if (count[i] == max) {
			mode = sample[i];
		}
	}
		double median = 0; //median
  if (num % 2 == 0) { 
		median = ((double)sample[num/2-1] + (double)sample[num/2]) / 2;
	} else {
		median = sample[num/2];
	}
	cout  << "mode = " << mode << endl;
	cout << "median = " << median << endl;
}

int main () {
	int n = 0;
	cout << "How many random number do you want?" << endl;
	do {
	  cin >> n;
	} while (n < 1);	
  vector<int> random(n);
  srand (time (NULL));
	for (int i = 0; i < random.size(); i++) {
		random[i] = rand () % 101;
		cout << random[i] << endl;
	}
	average_variance(random, random.size());
	max_min(random, random.size());
  mode_median(random, random.size());
	return 0;
}
