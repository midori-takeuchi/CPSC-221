#include <iostream>
#include <ctime>
#include <cstdlib>

int * x;
int comps;
int compsqc;

void swap(int & a, int & b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int randint(int a, int b) {
	return a + (rand() % (b - a + 1));
}

void quicksort(int a, int b) {
	if (a >= b) return;
	int p = randint(a,b); // pivot
	swap(x[a], x[p]);
	int m = a;
	int i;
	// in-place partition:
	for (i = a+1; i <= b; i++) {
		if (x[i] < x[a]) {
			swap(x[++m], x[i]);
		}
		comps++;
	}
	swap(x[a],x[m]);
	quicksort(a, m-1);
	quicksort(m+1, b);
}

void qc (int n) {
   if (n <= 1) {
	return;
  }
   int m = randint (1, n);
   for (int i = 0; i<n; i++) {
	compsqc++; 
   }
   qc(n-m);
   qc(m-1);
}

#define NN 1000

int main(int argc, char *argv[]) {
	srand(time(0));
	int sum;

	// change the following code
	x = new int[NN];
	for (int i=0; i<NN; ++i) {
		x[i] = rand() % NN;
	}

	for (int j = 0; j<100; j++) {
	comps = 0;
	
	quicksort(0, NN-1);
	for (int i=0; i<NN; ++i) {
		std::cout << x[i] << " ";
	}
	std::cout << std::endl;

	sum = sum + comps;

	}

	qc(NN);
	std::cout << " qc comparisons: " << compsqc << std::endl;	

	delete[] x;
	std::cout << "took " << sum/100 << " comparisons on average" << std::endl;
	return 0;
}
