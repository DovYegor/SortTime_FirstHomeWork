#include <windows.h>
#include <iostream>
#include <fstream>
#define maxTime 100

using namespace std;

void bubbleSort(int data[], int lenD)
{
  int tmp = 0;
  for(int i = 0;i<lenD;i++)
  {
    for(int j = (lenD-1);j>=(i+1);j--)
    {
      if(data[j]<data[j-1])
      {
        tmp = data[j];
        data[j]=data[j-1];
        data[j-1]=tmp;
      }
    }
  }
}

void quickSort(int *mas, int size) {
    //��������� � ������ � � ����� �������
    int i = 0;
    int j = size - 1;
    //����������� ������� �������
    int mid = mas[size / 2];
    //����� ������
    do {
        //��������� ��������, ���� ��, ������� ����� ���������� � ������ �����
        //� ����� ����� ������� ����������(��������� �� �����) ��������, ������� ������ ������������
        while(mas[i] < mid) {
            i++;
        }
        //� ������ ����� ���������� ��������, ������� ������ ������������
        while(mas[j] > mid) {
            j--;
        }
        //������ �������� �������
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);
    //����������� ������, ���� ��������, ��� �����������
    if(j > 0) {
        //"����� �����"
        quickSort(mas, j + 1);
    }
    if (i < size) {
        //"����� �����"
        quickSort(&mas[i], size - i);
    }
}


void selectionSort(int* a, int size) //�������
    {
        for(int i=0;i<size-1;i++)
        {
            int min_ind=i;
            for(int j=i;j<size;j++)
            {
                if(a[j]<a[min_ind])
                    {
                        min_ind=j;
                    }

            }
            if(i!=min_ind)
            {
                int temp=0;
                temp=a[i];
                a[i]=a[min_ind];
                a[min_ind]=temp;
            }
        }
    }

void insertSort(int* a, int size) // ���������
    {
        for(int i=1;i<size;i++)
        {
            int key=a[i];
            int j= i-1;
            while(j>=0 && a[j]>key)
            {
                a[j+1]=a[j];
                a[j]=key;
                j--;
            }
        }
    }


void merge(int[], int[], int, int[], int);
void mergeSort(int data[], int lenD) //��������
{
  if(lenD>1){
    int middle = lenD/2;
    int rem = lenD-middle;
    int* L = new int[middle];
    int* R = new int[rem];
    for(int i=0;i<lenD;i++){
      if(i<middle){
        L[i] = data[i];
      }
      else{
        R[i-middle] = data[i];
      }
    }
    mergeSort(L,middle);
    mergeSort(R,rem);
    merge(data, L, middle, R, rem);
  }
}
void merge(int merged[], int L[], int lenL, int R[], int lenR){
  int i = 0;
  int j = 0;
  while(i<lenL||j<lenR){
    if (i<lenL && j<lenR){
      if(L[i]<=R[j]){
        merged[i+j] = L[i];
        i++;
      }
      else{
        merged[i+j] = R[j];
        j++;
      }
    }
    else if(i<lenL){
      merged[i+j] = L[i];
      i++;
    }
    else if(j<lenR){
      merged[i+j] = R[j];
      j++;
    }
  }
}

void shakerSort(int *arr, int size)
{
    int leftMark = 1;
    int rightMark = size - 1;
    while (leftMark <= rightMark)
    {
    for (int i = rightMark; i >= leftMark; i--)
    if (arr[i - 1] > arr[i]){
        int temp=0;
        temp=arr[i];
        arr[i]=arr[i-1];
        arr[i-1]=temp;
    }
    leftMark++;

    for (int i = leftMark; i <= rightMark; i++)
    if (arr[i - 1] > arr[i]){
        int temp=0;
        temp=arr[i];
        arr[i]=arr[i-1];
        arr[i-1]=temp;
    }
    rightMark--;
    }
}

void gnomeSort(int* A, int N) {
    int i = 0; int tmp = 0;
       while (i < N) {
           if (i == 0 || A[i - 1] <= A[i])
               ++i;
           else {
               tmp = A[i];
               A[i] = A[i - 1];
               A[i - 1] = tmp;
               --i;
           }
       }
}

void randomFill(int* a, int _size) {
    for (int i=0; i<_size; i++)
    {
        a[i]=rand();
    }
}

void durSortToFile(int time1, int time2, int time3, int time4, int time5, int time6, int time7, int _size) {
     FILE *sort1 = fopen ("C:\\����\\2 �������\\������ ���������������� �� C++\\ReleaseSortTime\\SortTime.txt", "a");
     fprintf(sort1, "%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", _size, time1, time2, time3, time4, time5, time6, time7);
     fclose(sort1);
}

void nextSize(int& _size) {
    if (1000<=_size && _size<10000)
        _size+=100;
    if (10000<=_size && _size<100000)
        _size+=1000;
    if (100000<=_size && _size<1000000)
        _size+=10000;
    if (1000000<=_size)
        _size+=100000;
}


int main()
{
    FILE *sort = fopen ("C:\\����\\2 �������\\������ ���������������� �� C++\\ReleaseSortTime\\SortTime.txt", "w");
    fclose(sort);
    int *my_array;
    int time = 0, time1 = 0, time2 = 0, time3 = 0, time4 = 0, time5 = 0, time6 = 0, time7 = 0;
    for (int size = 1000; size <= 8800000;) {
        my_array = new int [size];
        if (time1<maxTime)
        {
            randomFill(my_array, size);
            time = GetTickCount();
            bubbleSort(my_array, size);
            time1 = GetTickCount() - time;
        }

        if (time2<maxTime)
        {
            randomFill(my_array, size);
            time = GetTickCount();
            quickSort(my_array, size);
            time2 = GetTickCount() - time;
        }

        if (time3<maxTime)
        {
            randomFill(my_array, size);
            time = GetTickCount();
            selectionSort(my_array, size);
            time3 = GetTickCount() - time;
        }

        if (time4<maxTime)
        {
            randomFill(my_array, size);
            time = GetTickCount();
            insertSort(my_array, size);
            time4 = GetTickCount() - time;
        }

        if (time5<maxTime)
        {
            randomFill(my_array, size);
            time = GetTickCount();
            mergeSort(my_array, size);
            time5 = GetTickCount() - time;
        }

        if (time6<maxTime)
        {
            randomFill(my_array, size);
            time = GetTickCount();
            shakerSort(my_array, size);
            time6 = GetTickCount() - time;
        }

        if (time7<maxTime)
        {
            randomFill(my_array, size);
            time = GetTickCount();
            gnomeSort(my_array, size);
            time7 = GetTickCount() - time;
        }

        durSortToFile(time1, time2, time3, time4, time5, time6, time7, size);
        nextSize(size);
        delete [] my_array;
    }
    return 0;
}
