//Advent of Code 2018 - 2

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> get_values(string fpath){
    vector<string> vals;
    string line;

    ifstream infile(fpath);
    while( getline(infile, line)){
        vals.push_back(line);
    }
    infile.close();

    return vals;
}

unordered_map<char,int> get_char_counts(string str){
    unordered_map<char,int> counts;
    for(char& c : str) {
        if (counts.find(c) == counts.end()){
            counts.insert(make_pair<char&,int>(c,1));
        }else{
            counts[c]+=1;
        }
        //cout << c << " " << counts[c] << endl;
    }
    return counts;
}

bool contains_count(unordered_map<char,int> counts, int check_count){
    for(auto const& x: counts){
        if(x.second==check_count){
            return true;
        }
        //cout << c << " " << counts[c] << endl;
    }
    return false;
}

void part1(){
    vector<string> ids = get_values("data/aoc_2a.txt");
    int two_count=0, three_count=0;
    for (auto id: ids){
        auto counts = get_char_counts(id);
        if (contains_count(counts,2)){
            two_count+=1;
        }
        if (contains_count(counts,3)){
            three_count+=1;
        }
    }
    cout << "Part 1 Checksum: " << two_count*three_count << endl;
}

bool string_diff(string str1, string str2){
    string output;
    int diff_count=0;
    for (unsigned i = 0; i<str1.length(); i++){
        if(str1[i]==str2[i]){
            output+=str1[i];
        }else{
            diff_count+=1;
        }
    }
    if (diff_count==1){
        cout << "Part 2 Characters: " << output << endl;
        return true;
    }
    return false;
}

bool part2(){
    vector<string> ids = get_values("data/aoc_2a.txt");
    for(auto const& str1: ids){
        for(auto const& str2: ids){
            if(string_diff(str1,str2)){
                return true;
            };
        }
    }
    return false;
}

int main(){
    part1();
    part2();
}