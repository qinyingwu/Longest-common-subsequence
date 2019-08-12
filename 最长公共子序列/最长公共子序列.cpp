// �����������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"iostream"
#include "string"
using namespace std;
void LCSLength(int m,int n,char* x,char* y,int **c,int **b)
{
	int i,j;
	for(i=1;i<=m;i++)
		c[i][0]=0;
	for(i=1;i<=m;i++)
		c[0][i]=0;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(x[i]==y[j]){c[i][j]=c[i-1][j-1]+1;b[i][j]=1;}
			else if(c[i-1][j]>=c[i][j-1]){c[i][j]=c[i-1][j];b[i][j]=2;}
			else{c[i][j]=c[i][j-1];b[i][j]=3;}
		}
	}
}

void LCS(int i,int j,char *x,int **b)
{
	if(i==0||j==0)return;
	if(b[i][j]==1){LCS(i-1,j-1,x,b);cout<<x[i];}
	else if(b[i][j]==2)LCS(i-1,j,x,b);
	else LCS(i,j-1,x,b);
}

template <typename T>
T** malloc_Array2D(int row, int col)
{
	int size = sizeof(T);
	int point_size = sizeof(T*);
	T **arr = (T **) malloc(point_size * row + size * row * col);
	if (arr != NULL)
	{	
		memset(arr, 0, point_size * row + size * row * col);
		T *head = (T*)((int)arr + point_size * row);
		while (row--)
			arr[row] = (T*)((int)head + row * col * size);
	}
	return (T**)arr;
}

void free_Aarray2D(void **arr)
{
	if (arr != NULL)
		free(arr);
}
int _tmain(int argc, _TCHAR* argv[])
{
	cout<<"����������1��";
	string a;
	cin>>a;
	char *a1=new char;
	for(int i=1;i<=a.length();i++)
	{
		a1[i]=a[i-1];
	}
	
	cout<<"����������2��";
	string b;
	cin>>b;
	char *b1=new char;
	for(int i=1;i<=b.length();i++)
	{
		b1[i]=b[i-1];
	}
	int nRow=a.length(), nCol=a.length();
	int **p = malloc_Array2D<int>(nRow+1, nCol+1);
	int nRow1=a.length(), nCol1=a.length();
	int **q = malloc_Array2D<int>(nRow1+1, nCol1+1);
	p[0][0]=0;
	q[0][0]=0;
	LCSLength(a.length(),b.length(),a1,b1,p,q);
	cout<<"����������Ľ⣺"<<endl;
	for(int i=0;i<=b.length();i++)
	{
		for(int j=0;j<=a.length();j++)
		{
			string u=" 0";
			if(q[j][i]==1)u="�I";
			if(q[j][i]==2)u="��";
			if(q[j][i]==3)u="��";
			cout<<"("<<p[j][i]<<","<<u<<")"<<"  ";
		}
		cout<<endl;
	}
	cout<<"�����������Ϊ��";
	LCS(a.length(),b.length(),a1,q);
	free_Aarray2D((void**)p);
	int z;
	cin>>z;
	return 0;
}

