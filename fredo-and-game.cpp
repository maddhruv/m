#include <iostream>
using namespace std;
/*April Circuits 2017*/
int main() {
	// your code goes here
	int T, Arr[10][100000], i(0), temp;
	long A[10], N[10];
  cin>>T;
	while(!(T>=1 && T<=10)){
		cin>>T;
	}
  temp = T;
	while(temp>0){
		cin>>A[i];
		cin>>N[i];
    for(int j=0; j<N[i]; j++){
        cin>>Arr[i][j];
				while(!(Arr[i][j]==0 || Arr[i][j]==1)){
					cin>>Arr[i][j];
				}
    }
		i++;
		temp--;
	}
  i = 0;
  for(temp=0; temp<T; temp++){
    for(int j=0; j<N[temp]; j++){
      if(A[temp]==0){
        cout<<"No "<<j<<endl;
        break;
      }
      if(Arr[temp][j]){
        A[temp] += 2;
      } else{
        A[temp] -= 1;
      }
    }
    if(A[temp]!=0){
      cout<<"Yes "<<A[temp]<<endl;
    }
  }
	return 0;
}
