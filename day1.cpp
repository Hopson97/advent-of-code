//https://adventofcode.com/2018/day/1

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>

void part1() {
    int freq = 0;
    std::fstream inFile("day1inp.txt");
    int in;
    while(inFile >> in) {
        freq += in;
    }
    std::cout << freq << '\n';
}

void part2() {
    int freq = 0;
    std::fstream inFile("day1inp.txt");
    std::vector<int> changes;
    changes.reserve(1024);
    int in;
    while(inFile >> in) {
        changes.push_back(in);
    }
    std::unordered_set<int> newFreqs;
    newFreqs.reserve(1024 * 64); //reverse the heck out of my memory

    while (true) {
        for (auto c : changes) {
            freq += c;
            if (newFreqs.find(freq) != newFreqs.end()) {
                std::cout << freq << '\n';
                return;
            }
            newFreqs.insert(freq);
        }
    }
}

int main() {
    part2();
}

