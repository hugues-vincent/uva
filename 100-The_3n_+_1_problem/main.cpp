#include <iostream>
#include <fstream>
#include <math.h>
#include <map>

using namespace std;
int f(int n) {
	return n % 2 == 1 ? 3 * n + 1 : n / 2;
}

int f_k(int n, int k, int c[] ,int d[]) {
	int a = floor(n/pow(2, k));
	int b = n % int(pow(2, k));
	cout << a << " " << b <<endl;
	return a * pow(3, c[b]) + d[b];
}

void cycle_graph(int n, map<int, int> &foo) {
	bool loop = true;
	int cycle_length = 0;
	int tmp_n = n;
	while(loop){
		foo[n] =  foo.find(n) == foo.end() ? 0 : foo[n] + 1;
		if (n==1)
		 	loop = false;
		n = f(n);
	 	cycle_length++;
	}	
}
void cycle(int n, map<int, int> &cycle_lengths) {
	bool loop = true;
	int cycle_length = 0;
	int tmp_n = n;
	while(loop){
		// cout << n << " ";
	auto cur = cycle_lengths.find(n);
	if (cur == cycle_lengths.end())
	{
	 	cycle_lengths[n] = -cycle_length;
			if (n==1)
			 	loop = false;
		 	tmp_n = n;
			n = f(n);
		 	cycle_length++;
		}
		else {
			loop = false;
			cycle_length += cur->second;
		}
	}
	for(auto &it : cycle_lengths) {
		if (it.second <=0 ) 
			it.second += cycle_length;
	}
	// cout << endl;
}
int main(int argc, char *argv[]) {
	int k = 6;
	
	int i, j;
	int max_cycle;
	map<int, int> cycle_lengths, occurence;
	
	for(int l = 1; l <= 10000 ; l++){
		cycle_graph(l, occurence);
		cycle(l, cycle_lengths);
	}
	ofstream myfile;
	myfile.open ("cache");
	myfile << "{";
	for(auto kv : occurence) {
		if ((kv.second > 11 && kv.first > 4000 )|| (kv.second > 5 && kv.first > 30000))
		myfile << "{" << kv.first << ", " << cycle_lengths[kv.first] << "},";
		
	}
	myfile << "}\n";
	myfile.close();

	// while(scanf("%d%d", &i, &j) != EOF)
	// {	max_cycle = 0;
	// 	for(int l=i; l <= j; l ++){
	// 		cycle(l, cycle_lengths);
	// 		max_cycle = max_cycle > cycle_lengths[l] ? max_cycle : cycle_lengths[l];
	// 	}
	// 	cout << i << " " << j << " " << max_cycle << "\n"; 
	// }
	return 0;
}