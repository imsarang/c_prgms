#include<stdio.h>
#include<stdlib.h>
void bot_heap(int *h, int n);
// void top_heap(int *h,int n);
void main()
{
	int h[100];
	int n,i;
	printf("Enter the no of elements\n");
	scanf("%d",&n);
	printf("enter the elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&h[i]);
	bot_heap(h,n-1);
    // top_heap(h,n-1);
	printf("Elements are ..........\n");
	for(i=0;i<n;i++)
	printf("%d ", h[i]);
}
void bot_heap(int *h, int n)
{
	int i,j,k,key;
	for(k=(n-1)/2;k>=0;k--)
	{
		j=k;
		key=h[j];
		i=2*j+1;
		while(i<=n)
		{
			if((i+1)<=n)
			{
				if(h[i+1]>h[i])
				i++;		
			}
			if(key<h[i])
			{
				h[j]=h[i];
				j=i;
				i=2*j+1;

			}
			else
				break;
		}
		h[j]=key;
	}
}

// void top_heap(int *h, int n)
// {
// 	int k,i,key,j;
// 	for(k=1;k<=n;k++)
// 	{
// 		i=k;
// 		key=h[i];
// 		j=(i-1)/2;
// 		while(i>0 && key > h[j])
// 		{
// 			h[i]=h[j];
// 			i=j;
			
// 			j=(i-1)/2;
// 		}
// 		h[i]=key;	
// 	}
// 	}




