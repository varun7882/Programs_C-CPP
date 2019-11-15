#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/math/constants/constants.hpp>
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using namespace std;
using boost::multiprecision::cpp_dec_float_50;
#define dd long double
#define ii cpp_int
#define M 1000000007
#define fastIO ios::sync_with_stdio(0), cout.tie(0), cin.tie(0)
bool isVowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
        return true;
    }
    return false;
}

void printPersonDetails(vector<string> &personString, vector<int> &personCharCount, vector<int> &personStringCharCount, dd personScore)
{
    cout << "Person string count " << personString.size() << "\n";
    for (int i = 0; i < personString.size(); i++)
    {
        cout << personString[i] << "\n";
    }
    cout << "char count\n";
    for (int i = 0; i < 26; i++)
    {
        if (personCharCount[i] != 0)
            cout << (char)(i + 'a') << " count " << personCharCount[i] << " present in " << personStringCharCount[i] << "\n";
    }
    cout << "personScore " << exp(personScore) << "\n";
    cout << "\n";
} 
void print(vector<int>& vs)
{
    for(int i=0;i<vs.size();i++)
    {
        cout<<vs[i]<<" ";
    }
    cout<<"\n";
}
bool checkIfAlice(string x)
{
    // cout<<"string is "<<x<<"\n";
    vector<int> sumVowel(x.size() + 1, 0);
    vector<int> sumConsonants(x.size() + 1, 0);
    for (int i = 0; i <x.size(); i++)
    {
        if (isVowel(x[i]))
        {
            sumVowel[i + 1] = sumVowel[i] + 1;
            sumConsonants[i + 1] = sumConsonants[i];
        }
        else
        {
            sumConsonants[i + 1] = sumConsonants[i] + 1;
            sumVowel[i + 1] = sumVowel[i];
        }
    }
    // cout<<"vowels\n";
    // print(sumVowel);
    // cout<<"consonants\n";
    // print(sumConsonants);
    int n = x.size();
    if (sumVowel[n] < sumConsonants[n])
    {
       // cout<<x<<"ij\n";
        return false;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int vowels = sumVowel[j + 1] - sumVowel[i];
            int cons = sumConsonants[j + 1] - sumConsonants[i];
            //  cout<<"i j"<<i<<" "<<j<<"\n";
            //  cout << vowels << " <--- v c--> " << cons << "\n";
             if (cons > vowels)
            {
                return false;
            }
        }
    }
    return true;
}
bool check(string x)
{
    int i, j, v = 0, c = 0;
    for (i = 0; i < x.size() - 1; i++)
    {
        if ((!isVowel(x[i])) && (!isVowel(x[i + 1])))
            return false;
    }

    for (i = 0; i < x.size() - 2; i++)
    {
        if ((!isVowel(x[i])) && (isVowel(x[i + 1])) && (!isVowel(x[i + 2])))
            return false;
    }

    return true;
}
int main()
{
    fastIO;
    cout << setprecision(12);
    cin >> setprecision(12);
    int t;
    cin >> t;
    while (t--)
    {
        int L;
        cin >> L;
        vector<int> aliceCharCount(26, 0);
        vector<int> aliceStringCharCount(26, 0);
        vector<string> aliceStrings;
        vector<int> bobCharCount(26, 0);
        vector<int> bobStringCharCount(26, 0);
        vector<string> bobStrings;
        for (int i = 0; i < L; i++)
        {
            string x;
            cin >> x;
            vector<int> tempCharCount(26, 0);
            vector<bool> tempChar(26, false);
            bool isAlice = true;
            for(int i=0;i<x.size();i++)
            {
                tempCharCount[x[i]-'a']++;
                tempChar[x[i]-'a']=true;
            }
             isAlice = checkIfAlice(x);
            if (isAlice)
            {
                aliceStrings.push_back(x);
                for (int i = 0; i < 26; i++)
                {
                    aliceCharCount[i] += tempCharCount[i];
                    if (tempChar[i])
                    {
                        aliceStringCharCount[i]++;
                    }
                }
            }
            else
            {
                bobStrings.push_back(x);
                for (int i = 0; i < 26; i++)
                {
                    bobCharCount[i] += tempCharCount[i];
                    if (tempChar[i])
                    {
                        bobStringCharCount[i]++;
                    }
                }
            }
        }
        dd ans = 0, aliceScore = 0, bobScore = 0, anns, tmpa, tmpb;
        dd aliceNumerator = 0, aliceDenominatior = 0;
        dd bobNumerator = 0, bobDenominatior = 0;
        bool inf = false;
        for (int i = 0; i < 26; i++)
        {

            tmpa = 0, tmpb = 0;
            if (aliceCharCount[i] != 0)
            {
                aliceNumerator += log(aliceStringCharCount[i]);
                aliceDenominatior += log(aliceCharCount[i]);
            }
            if (bobCharCount[i] != 0)
            {
                bobNumerator += log(bobStringCharCount[i]);
                bobDenominatior += log(bobCharCount[i]);
            }
            // if(aliceNumerator>10000000||bobDenominatior>10000000)
            // {
            //     inf=true;
            //     break;
            // }

            // if (ans > 10000000)
            // {
            //     inf = true;
            //     break;
            // }
        }
        aliceDenominatior = 1.0 * aliceStrings.size() * aliceDenominatior;
        bobDenominatior = 1.0 * bobStrings.size() * bobDenominatior;
        aliceScore = aliceNumerator - aliceDenominatior;
        bobScore = bobNumerator - bobDenominatior;
        ans = (aliceScore - bobScore);
        // cout << "alice details\n";
        // printPersonDetails(aliceStrings, aliceCharCount, aliceStringCharCount, aliceScore);
        // cout << "bob details\n";
        // printPersonDetails(bobStrings, bobCharCount, bobStringCharCount, bobScore);
        // anns = aliceScore - bobScore;
        // cout << "ye si answer " << pow(10, anns) << "\n";

        dd ant = exp(ans);
        if (ant > 10000000)
        {
            cout << "Infinity\n";
        }
        else
        {
            cout << ant << "\n";
        }
    }
}
