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
    }
};
class RandomMenuSelector : public RandomNumberSelector
{
public:
    RandomMenuSelector(std::string inputFileName)
    {
        fileName = inputFileName;
    }
    std::string fileName;
    std::vector<std::string> makeList(void)
    {
        std::vector<std::string> elements;
        std::ifstream list(fileName);
        std::string line;
        if (list.is_open())
        {
            while (std::getline(list, line))
            {
                elements.push_back(line);
            }
        }
    }
    virtual void setMax(short numElements = 0)
    {
        //std::string line;
        /*while (std::getline(list, line))
        {
            numElements++;
        }
        maximum = numElements;
        */
    }
    /* 
    store the elements in a vector
    -> Extract the number
    -> access the wished member with getRandomNumber()

    if the all contents of the file are going to be stored, no need to get the number of the elements
    */

private:
};
int main(void)
{
    /*Instantiation
    RandMenu("string: filename")
    */
    RandomMenuSelector r1("normalRestBist");
    return 0;
}