#include <iostream>
#include <string> //????
using namespace std;
int main()
{
   //????????????
   string a;
   string b;
   int a1[1000 + 5] = {0}; //??
   int b1[1000 + 5] = {0}; //?????
   int c1[1000 + 5] = {0};
   cin >> a >> b;
   int lena = a.length();
   int lenb = b.length();
   for (int i = 0; i < lena; i++)
   {
      a1[lena - i - 1] = a[i] - '0'; //(int)????????
   }

   for (int i = 0; i < lenb; i++)
   {
      b1[lenb - i - 1] = b[i] - '0'; //(int)????????
   }
   int lenc = max(lena, lenb); //?lena?lenb???????

   for (int i = 0; i < lenc; i++)
   {
      c1[i] = a1[i] + b1[i] + c1[i];
      if (c1[i] >= 10)
      {
         c1[i + 1] = 1;
         c1[i] = c1[i] - 10;
      }
   }
   if (c1[lenc] > 0) //????
   {
      lenc++;
   }
   for (int i = lenc - 1; i >= 0; i--)
   {
      cout << c1[i];
   }
   return 0;
}