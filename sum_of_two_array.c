
//Programme to sum two array and display into third array


#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[20]={0},b[20]={0},c[20]={0};
        int i,add,n,n1;
        printf("Enter No of element to store in array: \n");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                printf("Enter %d element to store",i+1);
                scanf("%1d",&a[i]);
		
        }
        printf("Enter no of elements in second array: ");
        scanf("%d",&n1);

        for(i=0;i<n1;i++)
        {
                printf("Enter %d element to store\n",i+1);

                scanf("%1d",&b[i]);
		
        }
        if(n>=n1){
        i=0;
        while(a[i]!='\0')
        {
                add=a[n-i-1]+b[n1-i-1];
                if(add>=10)
                        {
  			add=add%10;
                        a[n-i-2]=a[n-i-2]+1;

                        }
                c[i]=add;
                i++;
                }
        }

        for(i=0;i<n;i++)
        {
        printf("sum is %d\n",c[n-1-i]);
        }

}
