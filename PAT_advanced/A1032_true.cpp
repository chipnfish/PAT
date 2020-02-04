#include <iostream>
#define max 100000
using namespace std;

struct Node{
	char data;
	int next;
	int cnt;
}node[max];

int main()
{
	for(int i=0; i<max; i++)
		node[i].cnt = 0;
	// freopen("input.txt", "r", stdin); //从文件中读取，再重定向到stdin 
	
	int p1, p2, n;
	cin >> p1 >> p2 >> n;
	for(int i=0; i<n; i++){
		int addr, next;
		char data; 
		cin >> addr >> data >> next;
		node[addr].data = data;
		node[addr].next = next;
//		node[addr] = {data,next}; 		//error 
		// node[node[addr].next].cnt++;
	}
	
	bool flag = false;
	int p = p1;
	while(p!=-1){
		// if(node[p].cnt==2){
		// 	flag = true;
		// 	printf("%05d\n", p);
		// 	break;
		// }
        node[p].cnt++;
		p = node[p].next;
	}  
	// if(!flag){
		p = p2; 
    while(p!=-1){
        if(node[p].cnt==1){
            flag = true;
            printf("%05d\n", p);
            break;
        }
        p = node[p].next;
    }
    if(!flag){
        printf("-1\n");
	}
	
	return 0;
}
