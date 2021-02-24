#include <iostream>
#include <fstream>
/* 
class MenuGenerator
{
public:
    short getARandNum() private:
    //random number generator
};
class ReadList : public MenuGenerator
{
    std::string getFileName(void)
    {
        return fileName;
    }
    void setFileName(std::string str)
    {
        fileName.append(str);
    }
    std::string fileName;
    std::ifstream readList("filename");

short setElementNumber(void)
    {
        short elementNumberOfList = 0;
        std::string line;
        if(readList.isopen())
        {
           while(std::getline(readList, line)) elementNumberOfList++;
        }
        return elementNumberOfList;
        }
};
 Consider ways to encapsulate the class with right functionality split the components 
 NEED to DRAW CONCEPTUAL DIAGRAM
 public or private?*/
int main(void)
{
    char menuSwitch;
    //std::ifstream normalList("normalRestBistList.txt");
    //td::ifstream betterList("betterRestBistList.txt");
    std::cout << " Choose menu in NORMAL or BETTER [ N   B ] : ";
    std::cin >> menuSwitch;
    switch (menuSwitch)
    {
    case 'N':
        std::cout << "Normal List Selected" << std::endl;
        /* code */
        break;
    case 'B':
        std::cout << "Better List Selected" << std::endl;
        /* code */
        break;
    default:
        std::cout << "unknow menu type" << std::endl;
        break;
    }
    return 0;
}