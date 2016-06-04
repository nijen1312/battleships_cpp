#ifndef MENU_HPP
#define MENU_HPP

class Menu
{
  public:
    void displayMenu(char title[]);
    Menu(int numOfOpt,int menuWidth,int menuHeigth,char **mainMenuOptions,void(**mainMenuFunctions)(void));
    ~Menu();
  private:
    int m_numOfOpt;
    char **m_mainMenuOptions;
    void(**m_mainMenuFunctions)(void);
    int m_menuWidth;
    int m_menuHeigth;
    int m_optionsPosX;
    int m_optionsPosY;
};
#endif
