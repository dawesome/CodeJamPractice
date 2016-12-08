#include <iostream>
#include <fstream>

struct TestCase {
    int credit;
    int numItems;
    int *prices = nullptr;

    ~TestCase() {
        delete prices;
    }
};

int readNumber(std::ifstream& file) {
    int c;
    file >> c;
    return c;
}

TestCase* ReadTestCase(std::ifstream& file) {
    TestCase* testCase = new TestCase();
    file >> testCase->credit;
    file >> testCase->numItems;
    testCase->prices = new int [testCase->numItems];
    for (int i = 0; i < testCase->numItems; ++i) {
        file >> testCase->prices[i];
    }
    return testCase;
}

void SolveTestCase(TestCase* testCase, int num)
{
    int first, second = 0;
    for (int i = 0; i < testCase->numItems - 1; ++i) {
        for (int j = i+1; j < testCase->numItems; ++j) {
            if (testCase->prices[i] + testCase->prices[j] == testCase->credit) {
                first = i + 1;
                second = j + 1;
            }
        }
    }
    std::cout << "Case #" << num << ": " << first << " " << second << std::endl;
}

int main(int argc, char** argv) {
    std::ifstream infile;
    infile.open(argv[1]);

    int testCases = readNumber(infile);
    for (int test = 1; test < testCases + 1; ++test) {
        TestCase* testCase = ReadTestCase(infile);
        SolveTestCase(testCase, test);
        delete testCase;
    }


    return 0;
}