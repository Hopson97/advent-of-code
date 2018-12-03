#include <fstream>
#include <cstdio>
#include <iostream>
#include <thread>
#include <cmath>
#include <regex>
#include "../Benchmark.h"

struct Claim {
    Claim(int x, int y, int w, int h) 
    :   x(x)
    ,   y(y)
    ,   width(w)
    ,   height(h)
    {
        claimId = id++;
    }
    int x, y, width, height, claimId;
    static int id;
};

int Claim::id = 1;

Claim parseLine(const char* line, int id) {
   // std::cout << "Begin parseline for id: " << id << '\n';
    const char* data = line + 5 + (int)std::log10(id);
    size_t comma, colonSpaceEnd, xloc;
    for (int i = 0; i < strlen(data); i++) {
        char x = data[i];
        switch (x) {
            case ',':
                comma = i;
                break;
            case ':':
                colonSpaceEnd = i + 1;
                break;
            case 'x':
                xloc = i;
                break;
            default:
                break;
        }
    }
    std::string_view xs(data,                       comma);
    std::string_view ys(data + comma + 1,           colonSpaceEnd - comma - 2);
    std::string_view hs(data + colonSpaceEnd + 1,   xloc - colonSpaceEnd - 1);
    std::string_view ws(data + xloc + 1,            strlen(data) - xloc);
    return {
        std::stoi(xs.data()),
        std::stoi(ys.data()),
        std::stoi(hs.data()),
        std::stoi(ws.data()),
    };
}



const int size = 1000;
void day3() {
    Claim::id = 1;
    std::array<int, size * size> grid;
    grid.fill(0);
    std::ifstream inFile ("input.txt");
    std::string line;
    std::vector<Claim> claims;
    int id = 0;
    while (std::getline(inFile, line)) {
        id++;
        auto& claim = claims.emplace_back(parseLine(line.c_str(), id));
        //if (id >= 5) return;
        for (int y = claim.y; y < claim.y + claim.height; y++) {
            for (int x = claim.x; x < claim.x + claim.width; x++) {
                size_t idx = y * size + x;
                grid[idx]++;
            }
        }
    }

    int count = 0;
    for (auto square : grid) {
        if (square > 1) {
            count++;
        }
    }
    std::cout << count << '\n';

    bool found = false;
    for (auto& claim : claims) {
        [&]{
            for (int y = claim.y; y < claim.y + claim.height; y++) {
                for (int x = claim.x; x < claim.x + claim.width; x++) {
                    if (grid[y * size + x] != 1) {
                        return;
                    }
                }
            }
            std::cout << "ID: " << claim.claimId << '\n';
            found = true;
        }();
    }
    if (found) return;
}


int main() {
    std::vector<Benchmark<1000>> benchmarks = {
        {"Part 1", &day3},
    };

    for (auto& bm : benchmarks) {
        bm.outputTimes();
    }
}