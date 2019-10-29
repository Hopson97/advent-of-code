#include "aoc2018.h"

/*
    Solution for Advent of Code 2018 day 23
    https://adventofcode.com/2018/day/23
*/

namespace {
    const char* INPUT_PATH = "2018/inputs/day23.txt";
} // namespace

namespace aoc2018 {
    void day23PartOne(bool doPrint)
    {
        std::ifstream inFile(INPUT_PATH);
        aoc::output(doPrint, 2018, 23, 1, "None");
    }

    void day23PartTwo(bool doPrint)
    {
        std::ifstream inFile(INPUT_PATH);
        aoc::output(doPrint, 2018, 23, 2, "None");
    }
} // aoc2018