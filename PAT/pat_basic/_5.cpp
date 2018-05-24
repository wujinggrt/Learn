#include <stdio.h>  
#include <vector>
#include <iostream>
using namespace std;

void Conjecture()
{
    int n;
	cin >> n;
    vector<int> ivec;
    ivec.reserve(20);
    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        ivec.push_back(temp);
    }// for
    ivec.shrink_to_fit();
    vector<bool> flag(n, false);
    flag.reserve(n);
    vector<int> buffer;
    buffer.reserve(20);
    for (int i = 0; i < ivec.size(); ++i)
    {
        while ()
    }
}

void Copy()
{
        int n,
        num[100],
        i,
        j,
        array[100],
        tag[100], // 判断array中的数据是否已经推倒过了
        f=1,
        k,
        g,
        temp;//f用来标识输出的是不是第一个数   
    scanf("%d",&n);  
    for(i=0;i<n;i++)
    {  
        scanf("%d",&num[i]);  
        tag[i]=1;  
    }  
    for(i=0;i<n;i++)
    {
        // sort
        for(j=i;j<n;j++)
        {  
            if(num[i]>num[j])
            {  
                temp=num[i];  
                num[i]=num[j];  
                num[j]=temp;  
            }  
        }  
    }// for 
    // 每一次计算一个num中的猜想的数，存到array
    // array计算完成后，在与num比较，是否覆盖，信息存储到tag
    // 如果tag[i]中具有了相等，那么就对这个num[i]不求猜想数，既是被覆盖
    for(i=0;i<n;i++)
    {  
        k=num[i];
        // 验证过了
        if(tag[i]==0) 
            continue;   
        // array中存入推导卡猜想的数据
        for(j=0;k!=1;j++)
        {  
            if(k%2==0)  k/=2;  
            else k=(3*k+1)/2;  
            array[j]=k;  
        }  
        // This is a double for loop
        // to confirm that if array has the same value between num,
        // and then mark it as 0 in tag.
        for(k=0;k<n;k++)
        {  
            // num[k]中的那个数是被覆盖的
            if(tag[k]==0) 
                continue;   
            else
                // 在array中，是否存在和num（输入数据）中相同的数
                // if so, use tag[k] = 0 to denote it.
                for(g=0;g<j;g++)
                {  
                    if(array[g]==num[k])
                        tag[k]=0;  
                    if(tag[k]==0)
                        continue;  
                }// for  
        }// for  
    }// for  
    // f初始值是1
    for(i=n-1;i>-1;i--)
    {  
        if(tag[i] && f)
        {
            printf("%d",num[i]);
            f=0;
        }  
        else if(tag[i] && !f) 
            printf(" %d",num[i]);  
    }  
}

int main()  
{  

    return 0;  
}  