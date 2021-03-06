#include "aoc2015.h"

/*
    Solution for Advent of Code 2015 day 6
    https://adventofcode.com/2015/day/6
*/

namespace {
    const char *INPUT_PATH = "2015/inputs/day6.txt";
} // namespace

namespace aoc2015 {
    void day6PartOne(bool doPrint)
    {
        std::ifstream inFile(INPUT_PATH);
        aoc::output(doPrint, 2015, 6, 1, "None");
    }

    void day6PartTwo(bool doPrint)
    {
        std::ifstream inFile(INPUT_PATH);
        aoc::output(doPrint, 2015, 6, 2, "None");
    }
} // namespace aoc2015