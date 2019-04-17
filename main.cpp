#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>



using namespace std;

template<typename IteratorType>
void bubbleSort(IteratorType first, IteratorType last);

int main()
{
  fstream myfile("pan-tadeusz.txt");

  vector<string> dane;
  vector<string>::iterator it;
  string buf;
  while(!myfile.eof())
  {
     myfile>>buf;
     dane.push_back(buf);

  }
  it=dane.begin();
  string temp;

  for(it; it != dane.end(); it++)
  {
       temp = *it;
       if(temp[0] >= 'A' &&  temp[0] <= 'Z' )
       {temp[0]  += 32;}
       *it = temp;

  }

auto t1 = chrono::high_resolution_clock::now();

 bubbleSort(dane.begin(), dane.begin()+3000);

auto t2 = chrono::high_resolution_clock::now();

auto dt = chrono::duration_cast<chrono::microseconds>(t2-t1);
cout << dt.count() << endl;


t1 = chrono::high_resolution_clock::now();
  sort(dane.begin(), dane.begin() + 3000);
t2 = chrono::high_resolution_clock::now();
dt = chrono::duration_cast<chrono::microseconds>(t2-t1);

cout << dt.count() << endl;




}

template<typename IteratorType>
void bubbleSort(IteratorType first, IteratorType last)
{

  IteratorType it1 = first;


  int lenght = last - first;



  for(int i = 0; i<lenght; i++)
  {
    for(first = it1; first != last-i-1; first++)
    {

         if((*first) > *(first+1))
         {  swap(*first, *(first+1)); }

    }

  }




}




