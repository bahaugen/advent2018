//Advent of Code 2018 - 2

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
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

void part1(){
    auto patches = get_values("data/aoc_3a.txt");
    unsigned id, left, top, width, height;
    string square;
    unordered_map<string,int> square_counts;
    for (auto const& patch: patches){
        sscanf(patch.c_str(), "#%i @ %i,%i: %ix%i", &id, &left, &top, &width, &height);
        /*sscanf("#123 @ 3,2: 5x4", "#%i @ %i,%i: %ix%i", &id, &left, &top, &width, &height);
        cout << patches[0] << endl;
        cout << id << endl;
        cout << left << endl;
        cout << top << endl;
        cout << width << endl;
        cout << height << endl;*/
        for (unsigned w=0; w<width; w++){
            for (unsigned h=0; h<height; h++){
                square = to_string(left+w) + "," + to_string(top+h);
                if (square_counts.find(square) == square_counts.end()){
                    square_counts.insert(make_pair<string&,int>(square,1));
                }else{
                    square_counts[square]+=1;
                }
                //cout << square << " " << square_counts[square]<< endl;
            }
        }
    }

    int overlaps=0;
    for(auto const& pair: square_counts){
        if(pair.second>1){
            overlaps+=1;
        }
    }
    cout << "Part 1 Overlapping Square Inches: " << overlaps << endl; 
}

struct Patch{
    unsigned id;
    unsigned left;
    unsigned top;
    unsigned width;
    unsigned height;
};

bool overlap(Patch p1, Patch p2){
    unordered_set<string> p1_squares;
    string square;
    for (unsigned w=0; w<p1.width; w++){
        for (unsigned h=0; h<p1.height; h++){
            square = to_string(p1.left+w) + "," + to_string(p1.top+h);
            p1_squares.insert(square);
        }
    }

    for (unsigned w=0; w<p2.width; w++){
        for (unsigned h=0; h<p2.height; h++){
            square = to_string(p2.left+w) + "," + to_string(p2.top+h);
            if(p1_squares.find(square)!=p1_squares.end()){
                return true;
            }
        }
    }
    return false;
}

void part2(){
    auto patches = get_values("data/aoc_3a.txt");
    vector<Patch> parsed_patches;
    unsigned id, left, top, width, height;
    for(auto const& patch: patches){
        sscanf(patch.c_str(), "#%i @ %i,%i: %ix%i", &id, &left, &top, &width, &height);
        parsed_patches.push_back({id, left, top, width, height});
    }
    /*cout << parsed_patches[0].id << endl;
    cout << parsed_patches[0].left << endl;
    cout << parsed_patches[0].top << endl;
    cout << parsed_patches[0].width << endl;
    cout << parsed_patches[0].height << endl;*/
    for(auto const& p1: parsed_patches){
        bool good_patch=true;
        for(auto const& p2: parsed_patches){
            if (p1.id!=p2.id){
                good_patch = good_patch && !overlap(p1,p2);
            }
        }
        if(good_patch){
            cout << "Part 2 Good Patch ID: " << p1.id << endl;
            break;
        }
    }
}

int main(){
    part1();
    part2();
    return 0;
}
