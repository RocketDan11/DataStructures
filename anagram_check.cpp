//Daniel Jolin
/* function that takes two arguments, s and t
return true if they are anagrams
returns false otherwise
implemented w an unordered map*/
#include <iostream>
#include <unordered_map>
using namespace std;
bool isAnagram(string s, string t);


int main() {
    string s = "anagram";
    string t = "nagaram";
    if (isAnagram(s, t))
     cout << "True" << endl;
    else{
     cout << "False" << endl; 
    }
s = "rat";
t = "car";
if (isAnagram(s, t)) cout << "True" << endl;
    else {
        cout << "False" << endl;
    }
}
bool isAnagram(string s, string t) {
    //freq = # of times a letter appears
    unordered_map<char, int>freq;

    if (s.length() != t.length())
        return false;
        for(int i = 0; i < s.length();i++){
        freq[s[i]]++;
        }   

        for(int i =0; i < t.length(); i++){
            if(freq.find(t[i]) == freq.end()){
            return false;
            }else{
                freq[t[i]]--;
                if(freq[t[i]] = 0){
                    freq.erase(t[i]);
                }
            }
    }
    return freq.empty();
}