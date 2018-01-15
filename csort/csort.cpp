// csort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<time.h>
#include<stdlib.h>
#define MAXLEN 5000

int nNum[MAXLEN];
void sort_mp(int nCount)
{
	for (int i = 1; i < nCount; i++)
	{
		for (int j = 0; j < nCount - i; j++)
		{
			if (nNum[j] > nNum[j + 1])
			{
				int tmp = nNum[j + 1];
				nNum[j + 1] = nNum[j];
				nNum[j] = tmp;
			}
		}
	}

	
}

void sort_kq(int nLeft,int nRight)
{
	if (nLeft >= nRight) return;

	int nTarget = nNum[nLeft];
	int nIndexL = nLeft;
	int nIndexR = nRight;

	while (nIndexL < nIndexR)
	{

		while (nIndexR > nIndexL && nNum[nIndexR] >= nTarget)
		{
			nIndexR--;
		}
		nNum[nIndexL] = nNum[nIndexR];

		while (nIndexL < nIndexR && nNum[nIndexL] <= nTarget)
		{
			nIndexL++;
		}
		nNum[nIndexR] = nNum[nIndexL];
	}
	nNum[nIndexL] = nTarget;
	sort_kq(nLeft, nIndexL);
	sort_kq(nIndexL + 1, nRight);
}

void out(char sss[],int nCount)
{
	printf("%s\n", sss);
	for (int i = 0; i < nCount; i++)
		printf("%d ", nNum[i]);
	printf("\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	srand((unsigned)time(NULL));
	int nCount = 15;
	for (int i = 0; i < nCount; i++)
	{
		nNum[i] = rand() % nCount;
	}
	out("\n原始数据\n", nCount);


	sort_mp(nCount);
	out("\n冒泡排序结果\n", nCount);

	sort_kq(0,nCount-1);
	out("\n快速排序结果\n", nCount);

	int nn;
	scanf_s("%d", &nn);
	return 0;
}

