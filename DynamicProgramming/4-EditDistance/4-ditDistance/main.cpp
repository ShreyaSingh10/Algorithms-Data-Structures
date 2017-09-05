#include <bits/stdc++.h>
int max(int a,int b){
    if(a>b)
    return a;
    else return b;
}
int min(int a,int b){
    if(a>b)
    return b;
    else return a;
}
int main() {
	//code
    int t;
    cin>>t;
	while(t--){
	    int l1,l2,i=0;
	    cin>>l1>>l2;
	    int sum1=0,sum2=0;
	    char a[104],b[104];
	    int x[26]={0},y[26]={0};
	    for(i=0;i<l1;i++){
	        cin>>a[i];
	        x[a[i]-'a']++;
	        sum1++;
	    }
	    for( i=0;i<l2;i++){
	       cin>>b[i];
	        y[b[i]-'a']++;
	        sum2++;
	    }
	     cout<<sum1<<" "<<sum2<<endl;
	    for(i=0;i<26;i++){
	        if(x[i]!=0 && y[i]!=0){
	            printf("i=%d\n",i);
	            printf("x[i]=%d y[i]=%d\n",x[i],y[i]);
	            int m=min(x[i],y[i]);
	            printf("m=%d\n",m);
	            x[i]-=m;y[i]-=m;
	            sum1-=m;sum2-=m;
	             printf("%d %d\n",sum1,sum2);
	        }
	    }
	    int f=max(sum1,sum2);
	    printf("%d\n",f);
	}
	return 0;
}
