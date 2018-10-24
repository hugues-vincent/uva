#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

int main()
{
	int b1, b2, b3, g1, g2, g3, c1, c2, c3;
	char p1, p2, p3;
	std::map<int,string> m;
	
	while(scanf("%d%d%d%d%d%d%d%d%d", &b1, &g1, &c1, &b2, &g2, &c2, &b3, &g3, &c3) != EOF)
	{
		int sum = + b1 + g1 + c1 + b2 + g2 + c2 + b3 + g3 + c3;
		m[- g1 - c2 - b3] = "GCB";
		m[- g1 - b2 - c3] = "GBC";
		m[- c1 - g2 - b3] = "CGB";
		m[- c1 - b2 - g3] = "CBG";
		m[- b1 - g2 - c3] = "BGC";
		m[- b1 - c2 - g3] = "BCG";
		auto it = m.begin();
		cout << it->second << " " << sum + it->first << "\n"; 
 		m.clear();
	}
	return 0;
}