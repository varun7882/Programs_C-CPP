#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_dec_float.hpp> 
#include <boost/math/constants/constants.hpp> 
#include <boost/multiprecision/cpp_int.hpp> 
using namespace boost::multiprecision; 
using namespace std;
using boost::multiprecision::cpp_dec_float_50; 
#define dd cpp_dec_float_50
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
void printPersonDetails(vector<string> &personString, vector<int> &personCharCount, vector<int> &personStringCharCount, double personScore)
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
    cout << "personScore " << personScore << "\n";
    cout << "\n";
}
bool checkIfAlice(string x)
{
    vector<int> sumVowel(x.size() + 1, 0);
    vector<int> sumConsonants(x.size() + 1, 0);
    for (int i = 0; i < x.size(); i++)
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
    int n = x.size();
    if (sumVowel[n] < sumConsonants[n])
    {
        //cout<<x<<"ij\n";
        return false;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int vowels = sumVowel[j + 1] - sumVowel[i];
            int cons = sumConsonants[j + 1] - sumVowel[i];
            if (cons > vowels)
            {
                //cout<<"i j"<<i<<" "<<j<<"\n";
                return false;
            }
        }
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
            int vowelCount = 0, consonantsCount = 0;
            for (int i = 0; i < x.size() - 1; i++)
            {
                int c = x[i] - 'a';
                tempCharCount[c]++;
                tempChar[c] = true;
                if (!isVowel(x[i]))
                {
                    consonantsCount++;
                    if (!isVowel(x[i + 1]))
                    {
                        isAlice = false;
                    }
                }
                else
                {
                    vowelCount++;
                }
            }
            int c = x[x.size() - 1] - 'a';
            tempCharCount[c]++;
            tempChar[c] = true;
            if (isVowel(x[x.size() - 1]))
            {
                vowelCount++;
            }
            else
            {
                consonantsCount++;
            }

            if (consonantsCount > vowelCount)
            {
                isAlice = false;
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
        cpp_int ans = 1, aliceScore = 1, bobScore = 1, anns, tmpa, tmpb;
        bool inf = false;
        for (int i = 0; i < 26; i++)
        {
            dd aliceNumerator=1,aliceDenominatior=1;
            dd bobNumerator=1,bobDenominatior=1;
            tmpa = 1, tmpb = 1;
            if (aliceCharCount[i] != 0)
            {
                
                aliceNumerator = aliceStringCharCount[i];
                aliceDenominatior=pow(aliceCharCount[i], aliceStrings.size());
            }
            if (bobCharCount[i] != 0)
            {
                 bobNumerator = bobStringCharCount[i];
                bobDenominatior=pow(bobCharCount[i], bobStrings.size());
            }
            // if(aliceNumerator>10000000||bobDenominatior>10000000)
            // {
            //     inf=true;
            //     break;
            // }
            tmpa=aliceNumerator*bobDenominatior;
            tmpb=bobNumerator*aliceDenominatior;
            aliceScore*=tmpa;
            bobScore*=tmpb;
            ans *= (tmpa / tmpb);
            // if (ans > 10000000)
            // {
            //     inf = true;
            //     break;
            // }
        }
        // cout<<"alice details\n";
        // printPersonDetails(aliceStrings,aliceCharCount,aliceStringCharCount,aliceScore);
        // cout<<"bob details\n";
        // printPersonDetails(bobStrings,bobCharCount,bobStringCharCount,bobScore);
        // anns=aliceScore/bobScore;
        //  cout<<"ye si answer "<<anns<<"\n";

        if (ans > 10000000)
        {
            cout << "Infinity\n";
        }
        else
        {
            cout << ans << "\n";
        }
    }
}
