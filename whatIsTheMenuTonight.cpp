#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
class RandomNumberSelector
{
public:
    short maximum;
    RandomNumberSelector(short defaultMax = 1) : maximum(defaultMax) {}
    virtual void setMax(short passMax)
    {
        maximum = passMax;
    }
    short getRandomNum(void)
    {
        short generateRandNum = randomNumberGenerator();
        return generateRandNum;
    }

private:
    short randomNumberGenerator(void)
    {
        /* RNG code */
        std::srand(std::time(nullptr)); //seed
        short randomNumber = (std::rand() % maximum);
        return randomNumber;
    }
};
class RandomMenuSelector : public RandomNumberSelector
{
public:
    RandomMenuSelector(std::string inputFileName)
    {
        std::ifstream listFile(inputFileName);
        std::string line;
        if (listFile.is_open())
        {
            while (std::getline(listFile, line))
            {
                list.push_back(line);
            }
        }
    }
    virtual void setMax(short numElements = 0)
    {
        for (std::vector<std::string>::iterator it = list.begin(); it != list.end(); ++it)
        {
            ++numElements;
        }
        maximum = numElements;
    }
    void printList(void)
    {
        for (std::vector<std::string>::iterator it = list.begin(); it != list.end(); ++it)
        {
            std::cout << *it << std::endl;
        }
    }
private:
    std::vector<std::string> list;
};
int main(void)
{
    RandomMenuSelector rm1("betterRestBistList.txt");
    rm1.printList();
    //RandomNumberSelector r1(rm1.getLengthPrintList());
    return 0;
}