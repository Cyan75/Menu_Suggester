#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
class RandomNumberSelector
{
public:
    short maximum;
    RandomNumberSelector(void) //generate seed
    {
        std::srand(std::time(nullptr));
        randSeed = std::rand();
    }
    virtual void setMax(short passMax)
    {
        maximum = passMax;
    }
    short getRanNum(void) //random generate
    {
        return (randSeed % maximum);
    }

private:
    short randSeed;
};
class RandomMenuSelector : public RandomNumberSelector
{
public:
    RandomMenuSelector(std::string inputFileName) : RandomNumberSelector::RandomNumberSelector()
    {
        std::ifstream listFile(inputFileName);
        std::string line;
        short numLines = 0;
        if (listFile.is_open())
        {
            while (std::getline(listFile, line))
            {
                list.push_back(line);
                numLines++;
            }
            maximumMenu = numLines;
        }
    }
    virtual void setMax(void)
    {
        maximum = maximumMenu;
    }
    void printList(void)
    {
        for (std::vector<std::string>::iterator it = list.begin(); it != list.end(); ++it)
        {
            std::cout << *it << std::endl;
        }
    }
    std::string getRanMenu(void)
    {
        std::vector<std::string>::iterator it = list.begin();
        return (*(it+getRanNum()));
    }
private:
    std::vector<std::string> list;
    short maximumMenu;
};
int main(void)
{
    RandomMenuSelector rms1("normalRestBistList.txt");
    rms1.setMax();
    std::cout<<rms1.getRanMenu();
    return 0;
}