#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
class RandomNumberSelector
{
public:
    short maximum;
    //short *maximum = new short;
    RandomNumberSelector(void) //generate seed as soon as when class is instantiated
    {
        std::srand(std::time(nullptr));
        randSeed = std::rand();
    }
    /* ~RandomNumberSelector(void)
    {
        delete maximum;
    } */
    //most general form of setMax is to assign the passed value
    //setMax can be redefined
    /* 
    how about using pure virtual
    virtual void setMAx = 0; 
    */
    virtual void setMax(short &passMax)
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
    //a constructor of a derived class should also be inherited from the base class constructor
    //RMS needs to take strings from a txt file
    RandomMenuSelector(std::string inputFileName) : RandomNumberSelector::RandomNumberSelector()
    {
        std::ifstream listFile(inputFileName);
        std::string *line = new std::string;
        short *numLines = new short;
        *numLines = 0;
        if (listFile.is_open())
        {
            while (std::getline(listFile, *line))
            {
                list.push_back(*line);
                numLines++;
            }
            maximumMenu = *numLines;
        }
        delete line;
        delete numLines;
    }
    /* ~RandomMenuSelector()
    {
        delete maximumMenu;
    } */
    void setMax(void)
    {
        maximum = maximumMenu;
    }
    //redundant -> just for debugging
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
        return (*(it + getRanNum()));
    }

private:
    std::vector<std::string> list;
    short maximumMenu;
    //short *maximumMenu = new short;
};
int main(void)
{

    //RandomMenuSelector normalRMS("normalRestBistList.txt");
    for (short i = 0; i < 10; ++i)
    {
        RandomMenuSelector *normalRMS = new RandomMenuSelector("normalRestBistList.txt");
        normalRMS->setMax();
        std::cout << normalRMS->getRanMenu();
        delete normalRMS;
    }
    return 0;
}