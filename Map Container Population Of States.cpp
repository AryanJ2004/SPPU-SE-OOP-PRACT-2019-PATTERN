#include<iostream>
#include<map>
#include<string>
#include<utility>
using namespace std;
int main()
{
typedef map<string,int>mapType;
mapType populationMap;
populationMap.insert(pair<string,int>("China",1339));
populationMap.insert(pair<string,int>("India",1187));
populationMap.insert(mapType::value_type("US",310));
populationMap.insert(mapType::value_type("Idonesia",234));
populationMap.insert(make_pair("Pakistan",170));
populationMap.insert(make_pair("Brasil",193));
mapType::iterator iter=--populationMap.end();
populationMap.erase(iter);
cout<<"Size Of PopulationMap:"<<populationMap.size()<<'\n';
for(iter=populationMap.begin();iter!=populationMap.end();++iter)
{
cout<<iter->first<<":"
<<iter->second<<" Million\n";
}
string country;
cin>>country;
iter=populationMap.find(country);
if(iter!=populationMap.end())
cout<<country<<"s populations is"<<iter->second<<"million\n";
else
cout<<"Key Is Not In PopulationMap"<<'\n';
populationMap.clear();
}
