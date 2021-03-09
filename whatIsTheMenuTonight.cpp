#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
class RandomNumberSelector
{
public:
    short maximum;
    RandomNumberSelector(void)
    {
        std::srand(std::time(nullptr));
        randSeed = std::rand();
    }
    virtual void setMax(short &passMax)
    {
        maximum = passMax;
    }
    short getRanNum(void)
    {
        return (randSeed % maximum);
    }
private:
    short randSeed;
};
class RandomMenuSelector : public RandomNumberSelector
{
public:
    RandomMenuSelector(void) : RandomNumberSelector::RandomNumberSelector()
    {
        std::string inputFileName = selectMenuType();
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
    std::string selectMenuType(void)
    {
        char menutype;
        bool isValid = false;
        std::string menuListName;
        do
        {
            std::cout << " NORMAL MENU OR BETTER MENU [ N / B ] : " ;
            std::cin >> menutype;
            switch (menutype)
            {
            case 'B':
                isValid = true;
                menuListName = "betterRestBistList.txt";
                break;
            case 'b':
                isValid = true;
                menuListName = "betterRestBistList.txt";
                break;
            case 'N':
                isValid = true;
                menuListName = "normalRestBistList.txt";
                break;
            case 'n':
                isValid = true;
                menuListName = "normalRestBistList.txt";
                break;
            default:
                std::cout << "          ¡INVALID INPUT!          " << std::endl;
                break;
            }
        } while (isValid == false);
        return menuListName;
    }
    void setMax(void)
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
    RandomMenuSelector *rms = new RandomMenuSelector;
    rms->setMax();
    std::cout << rms->getRanMenu() << std::endl;
    delete rms;
    return 0;
}