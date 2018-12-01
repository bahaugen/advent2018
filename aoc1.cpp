//Advent of Code 2018 - 1

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <stdlib.h>
using namespace std;

vector<int> get_values(string fpath){
    vector<int> vals;
    string line;

    ifstream infile(fpath);
    while( getline(infile, line)){
        vals.push_back(atoi(line.c_str()));
    }
    infile.close();

    return vals;
}

void part1(){
    vector<int> vals = get_values("data/aoc_1a.txt");
    int sum = 0;
    for (const int& v : vals){
        sum += v;
    }
    cout << "Part 1 Final output: " << sum << endl;
}

void part2(){
    vector<int> vals = get_values("data/aoc_1a.txt");
    set<int> seen_freqs;
    int running_sum = 0;
    seen_freqs.insert(running_sum);
    bool found_repeat = false;
    unsigned i = 0;
    while (found_repeat == false){ //Continue while a repeat hasn't been found
        running_sum += vals[i];
        //cout << running_sum << endl;
        if (seen_freqs.find(running_sum) == seen_freqs.end()){ //New sum hasn't been seen
            seen_freqs.insert(running_sum);
            i+=1;
            if (i>=vals.size()){ //Go back to beginning of vector
                i=0;
            }
        }else{ //We have seen this before
            cout << "Part 2 First Repeated Freq: " << running_sum << endl;
            found_repeat = true;
        }
    }
}

int main () {
    part1();
    part2();
}
