#include <cstdio>
#include <map>
#include <string>
#include <iostream>
using namespace std;
map<char,int> rtoi;
int getnum(string sa)
{
int i,a = 0;
for(i = 0; i < sa.length(); i++){
if(sa[i]=='I' && i < sa.length()-1){
 if(sa[i+1]=='V'){
  a += 4;
  i += 1;
  continue;
 }
 else if(sa[i+1]=='X'){
  a += 9;
  i += 1;
  continue;
 }
}
else if(sa[i]=='X' && i < sa.length()-1){
 if(sa[i+1] == 'L'){
  a += 40;
  i += 1;
  continue;
 }
 else if(sa[i+1] == 'C'){
  a += 90;
  i += 1;
  continue;
 }
}
else if(sa[i]=='C' && i < sa.length()-1){
 if(sa[i+1] == 'D'){
  a += 400;
  i += 1;
  continue;
 }
 else if(sa[i+1] == 'M'){
  a += 900;
  i += 1;
  continue;
 }
}
a += rtoi[sa[i]];
}
return a;
}
int main()
{
string sa,sb;
char sign;
int t = 5,a,b,i,rsl;
rtoi['I'] = 1;
rtoi['V'] = 5;
rtoi['X'] = 10;
rtoi['L'] = 50;
rtoi['C'] = 100;
rtoi['D'] = 500;
rtoi['M'] = 1000;
while(t--){
string ans;
cin >> sa >> sb >> sign;
a = getnum(sa);
b = getnum(sb);
if(sign == '+') rsl = a+b;
else if( sign == '-') rsl = a-b;
else if( sign == '/') rsl = a/b;
else if( sign == '*') rsl = a*b;
else if (sign == '%') rsl = a%b;
while(rsl){
if(rsl >= 1000) {
 ans += 'M';
 rsl -= 1000;
}
else if (rsl >= 500){
 if(rsl/100 == 9){
 ans += "CM";
 rsl -= 900;
 continue;
 }
 ans += 'D';
 rsl -= 500;
}
else if (rsl >= 100){
 if(rsl/100 == 4){
  ans += "CD";
  rsl -= 400;
  continue;
 }
 ans += 'C';
 rsl -= 100;
}
else if (rsl >= 50){
 if(rsl/10 == 9){
  ans += "XC";
  rsl -= 90;
  continue;
 }
 ans += 'L';
 rsl -= 50;
}
else if (rsl >= 10){
 if(rsl/10 == 4){
  ans += "XL";
  rsl -= 40;
  continue;
 }
 ans += 'X';
 rsl -= 10;
}
else if (rsl >= 5){
 if(rsl == 9){
  ans += "IX";
  rsl -= 9;
  continue;
 }
 ans += 'V';
 rsl -= 5;
}
else{
 if(rsl == 4){
  ans += "IV";
  rsl -= 4;
  continue;
 }
 ans += 'I';
 rsl -= 1;
}
}
cout << ans << endl;
}
return 0;
}