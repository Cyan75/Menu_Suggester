#include <iostream>
#include <fstream>
#include <ctime>
class RandomNumberSelector
{
public:
    RandomNumberSelector(short defaultMax = 1) : maximum(defaultMax) {}
    short maximum;
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
    virtual void setMax(short passMax)
    {
        std::ifstream list(fileName);
        /* 
        import a list of strings
        -> # of elements 
        -> getMax(# of elements)
        */
    }

private:
};
int main(void)
{
    /*Instantiation
    RandMenu("string: filename")
    */
    return 0;
}