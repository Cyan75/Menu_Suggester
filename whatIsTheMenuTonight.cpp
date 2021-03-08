#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
class RandomNumberSelector
{
public:
    short maximum;
    RandomNumberSelector(void) //generate seed as soon as when class is instantiated
    {
        std::srand(std::time(nullptr));
        randSeed = std::rand();
    }
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
    short getRanNum(void) //RNG
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
    //RandomMenuSelector(std::string inputFileName) : RandomNumberSelector::RandomNumberSelector()
    RandomMenuSelector(void) : RandomNumberSelector::RandomNumberSelector()
    {
        // what is it to use dynamic allocation in the constructor?
        // dynamic: what for?
        // is it always good to allocate dynamically?
        std::string inputFileName = selectMenuType();
        std::ifstream listFile(inputFileName);
        //std::ifstream listFile(selectMenuType());
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
    std::string selectMenuType(void)
    {
        bool isNormal;
        char menutype;
        std::cout << "type B to choose the better menu, press other to choose normal" << std::endl;
        switch (menutype)
        {
        case 'B':
            isNormal = false;
            break;
        case 'b':
            isNormal = false;
            break;
        default:
            isNormal = true;
            break;
        }
        if (isNormal == true)
        {
            return "normalRestBistList.txt";
        }
        else
            return "betterRestBistList.txt";
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
    void emptyList(void)
    {
        list.empty();
    }

private:
    std::vector<std::string> list;
    short maximumMenu;
};
int main(void)
{

    RandomMenuSelector normalRMS;
    normalRMS.setMax();
    std::cout << normalRMS.getRanMenu() << std::endl;
    normalRMS.emptyList();
 //   normalRMS.printList();
    /* for (short i = 0; i < 10; ++i)
    {
        RandomMenuSelector *normalRMS = new RandomMenuSelector();
        normalRMS->setMax();
        std::cout << normalRMS->getRanMenu();
        delete normalRMS;
    } */
    return 0;
}