#include <bits/stdc++.h>

using namespace std;
int par(char opening,char closing)
{
    if(opening=='('&& closing==')')
        return true;
     if(opening=='{'&& closing=='}')
        return true;
     if(opening=='['&& closing==']')
        return true;
        return false;
}
int balanced(string exp)
{
  stack<char> s;
  for(int i=0;i<exp.length();i++)
  {
      if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
            s.push(exp[i]);
      if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
      {
          if(s.empty()||!par(s.top(),exp[i]))
            return false;
          else
            s.pop();
      }
  }
  return s.empty()?1:0;
}
int main()
{
   string exp;
   int bal;
   cout<<"enter ur expression";
   cin>>exp;
   bal=balanced(exp);
   if(bal==1)
    cout<<"TRUE";
   else
    cout<<"FALSE";
    return 0;
}
