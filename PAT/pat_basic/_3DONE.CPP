#include<cstdio> 
#include<cstring>
int main()
{
    int n;          
    scanf("%d",&n);             
    while(n--){
        char str[110];
        int np=0,nt=0,other=0,lp,lt; // LOCATION
        scanf("%s",str);
        int len=strlen(str);
        for(int i=0;i<len;i++){                     //记录P,T和其他字母的个数以及P和T的位置 
            if(str[i]=='P'){
                np++;
                lp=i;
            }else if(str[i]=='T'){
                nt++;
                lt=i;
            }else if(str[i]!='A') 
                other++;
        }
        if((np!=1)||(nt!=1)||(other!=0)||(lt-lp<=1)){//P和T的个数必须为一，没有其他字母，P和T中间至少有一个A 
            printf("NO\n");
            continue;
        }
        int x=lp,y=lt-lp-1,z=len-lt-1;              
        if(x*y==z)
        printf("YES\n");
        else printf("NO\n");
    }
    return 0;

} 