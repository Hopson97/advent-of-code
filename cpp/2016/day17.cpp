#include "aoc2016.h"

/*
    Solution for Advent of Code 2016 day 17
    https://adventofcode.com/2016/day/17
*/

namespace {
    const char *INPUT_PATH = "2016/inputs/day17.txt";
} // namespace

namespace aoc2016 {
    void day17PartOne(bool doPrint)
    {
        std::ifstream inFile(INPUT_PATH);
        aoc::output(doPrint, 2016, 17, 1, "None");
    }

    void day17PartTwo(bool doPrint)
    {
        std::ifstream inFile(INPUT_PATH);
        aoc::output(doPrint, 2016, 17, 2, "None");
    }
} // namespace aoc2016