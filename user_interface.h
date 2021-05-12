#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "clusterizer.h"

class UserInterface {
private:
    Clusterizer *clusterizer;
    void showStartupMessage();
    enum class MainMenuOption 
        {createNewField, loadFieldFromFile, search, saveFieldToFile, quit};
    MainMenuOption showMainMenu();
    enum class FieldCreationMenuOption
        {addCloud, done, discard};
    FieldCreationMenuOption showFieldCreationMenu();
    enum class CloudCreationMenuOption
        {displace, rotateAboutOrigin, rotateAboutCenter, done, discard};
    CloudCreationMenuOption showCloudCreationMenu();
    enum class SearchAlgorithmMenuOption
        {FOREL, KMeans, Wave};
    SearchAlgorithmMenuOption showSearchAlgorithmMenu();
    void fileLoadRequest();
    void fileSaveRequest();
    void showTerminationMessage();
public:
    UserInterface() { clusterizer = nullptr; }
    void main();
    ~UserInterface() { delete clusterizer; }
};

#endif
