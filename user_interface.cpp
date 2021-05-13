#include "user_interface.h"
#include "forel_search.cpp"
#include "km_search.cpp"
#include "wave_search.cpp"
#include <fstream>

#define DEF_STR_SIZE 256

void UserInterface::showStartupMessage() {
    std::cout << "clusters by notblank00, licensed under GNU GPL v3.0" << std::endl;
}

UserInterface::MainMenuOption UserInterface::showMainMenu() {
    std::cout << "Main Menu: " << std::endl
        << "Choose an option: " << std::endl;
    std::cout << "1) Create new field" << std::endl;
    std::cout << "2) Load field from file" << std::endl;
    if(clusterizer->isValid()) {
        std::cout << "3) Start search engine" << std::endl;
        std::cout << "4) Save field to file" << std::endl;
    }
    std::cout << "5) Quit" << std::endl;
    std::cout << "Selection [1-5]: ";
    size_t query;
    std::cin >> query;
    if(query < 1 || query > 5 || (query != 5 && query > 2 && !clusterizer)) {
        std::cout << "Invalid number!" << std::endl;
        return showMainMenu();
    }
    return static_cast<MainMenuOption>(query - 1);
}

UserInterface::FieldCreationMenuOption UserInterface::showFieldCreationMenu() {
    std::cout << "Field Menu:" << std::endl;
    std::cout << "Choose an option:" << std::endl;
    std::cout << "1) Add cloud to field" << std::endl;
    std::cout << "2) Done" << std::endl;
    std::cout << "3) Discard" << std::endl;
    std::cout << "Selection [1-3]: ";
    size_t query;
    std::cin >> query;
    if(query < 1 || query > 3) {
        std::cout << "Invalid number!" << std::endl;
        return showFieldCreationMenu();
    }
    return static_cast<FieldCreationMenuOption>(query - 1);
}

UserInterface::CloudCreationMenuOption UserInterface::showCloudCreationMenu() {
    std::cout << "Cloud Menu:" << std::endl;
    std::cout << "Choose an option:" << std::endl;
    std::cout << "1) Displace cloud" << std::endl;
    std::cout << "2) Rotate cloud around origin" << std::endl;
    std::cout << "3) Rotate cloud about center" << std::endl;
    std::cout << "4) Done" << std::endl;
    std::cout << "5) Discard" << std::endl;
    std::cout << "Selection [1-5]: ";
    size_t query;
    std::cin >> query;
    if(query < 1 || query > 5) {
        std::cout << "Invalid option!" << std::endl;
        return showCloudCreationMenu();
    }
    return static_cast<CloudCreationMenuOption>(query - 1);
}

UserInterface::SearchAlgorithmMenuOption UserInterface::showSearchAlgorithmMenu() {
    std::cout << "Search Algorithm Menu:" << std::endl;
    std::cout << "Choose an option:" << std::endl;
    std::cout << "1) FOREL" << std::endl;
    std::cout << "2) K Means" << std::endl;
    std::cout << "3) Wave Method" << std::endl;
    std::cout << "Selection [1-3]: ";
    size_t query;
    std::cin >> query;
    if(query < 1 || query > 3) {
        std::cout << "Invalid option!" << std::endl;
    }
    return static_cast<SearchAlgorithmMenuOption>(query - 1);
}

void UserInterface::showQuitMessage() {
    std::cout << "Terminating." << std::endl;
}

void UserInterface::main() {
    showStartupMessage();
    clusterizer = new Clusterizer;
    bool mainMenuQuitFlag = false;
    while(!mainMenuQuitFlag) {
        switch(showMainMenu()) {
            case MainMenuOption::createNewField : {
                bool fieldCreationMenuQuitFlag = false;
                Field *newField = new Field;
                while(!fieldCreationMenuQuitFlag) {
                    switch(showFieldCreationMenu()) {
                        case FieldCreationMenuOption::addCloud : {
                            bool cloudCreationMenuQuitFlag = false;
                            Point newCenterPoint;
                            double dx, dy, dphi;
                            long quantity;
                            std::cout << "Specify values:" << std::endl;
                            std::cout << "Center point x: ";
                            std::cin >> newCenterPoint.x;
                            std::cout << "Center point y: ";
                            std::cin >> newCenterPoint.y;
                            std::cout << "Normal dx: ";
                            std::cin >> dx;
                            std::cout << "Normal dy: ";
                            std::cin >> dy;
                            std::cout << "Quantity: ";
                            std::cin >> quantity;
                            if(quantity <= 0) {
                                std::cout << "Invalid value!" << std::endl;
                                break;
                            }
                            Cloud *newCloud = new Cloud(newCenterPoint, dx, dy, static_cast<size_t>(quantity));
                            while(!cloudCreationMenuQuitFlag) {
                                switch(showCloudCreationMenu()) {
                                    case CloudCreationMenuOption::displace : {
                                        std::cout << "Specify values:" << std::endl;
                                        std::cout << "Displacement dx: ";
                                        std::cin >> dx;
                                        std::cout << "Displacement dy: ";
                                        std::cin >> dy;
                                        newCloud->displace(dx, dy);
                                        break;
                                    }
                                    case CloudCreationMenuOption::rotateAboutOrigin : {
                                        std::cout << "Specify angle dphi (radinans): ";
                                        std::cin >> dphi;
                                        newCloud->rotateAboutOrigin(dphi);
                                        break;
                                    }
                                    case CloudCreationMenuOption::rotateAboutCenter : {
                                        std::cout << "Specify angle dphi (radians): ";
                                        std::cin >> dphi;
                                        newCloud->rotateAboutCenterPoint(dphi);
                                        break;
                                    }
                                    case CloudCreationMenuOption::done : {
                                        newField->addCloud(newCloud);
                                        cloudCreationMenuQuitFlag = true;
                                        break;
                                    }
                                    case CloudCreationMenuOption::discard : {
                                        cloudCreationMenuQuitFlag = true;
                                    }
                                }
                            }
                            delete newCloud;
                            break;
                        }
                        case FieldCreationMenuOption::done : {
                            clusterizer->updateField(newField);
                            fieldCreationMenuQuitFlag = true;
                            break;
                        }
                        case FieldCreationMenuOption::discard : {
                            delete newField;
                            fieldCreationMenuQuitFlag = true;
                        }
                    }
                }
                break;
            }
            case MainMenuOption::loadFieldFromFile : {
                char filename[DEF_STR_SIZE];
                std::cout << "Specify file name: ";
                std::cin >> filename;
                std::ifstream input(filename);
                if(input.good()) {
                    clusterizer->updateField(new Field(input));
                    input.close();
                }
                else
                    std::cout << "File IO Error!" << std::endl;
                break;
            }
            case MainMenuOption::search : {
                switch(showSearchAlgorithmMenu()) {
                    case SearchAlgorithmMenuOption::FOREL : {
                        clusterizer->updateSearchAlgorithm(new FOREL);
                        std::cout << "Specify search radius R: ";
                        break;
                    }
                    case SearchAlgorithmMenuOption::KMeans : {
                        clusterizer->updateSearchAlgorithm(new KMeans);
                        std::cout << "Specify cluster count K: ";
                        break;
                    }
                    case SearchAlgorithmMenuOption::Wave : {
                        clusterizer->updateSearchAlgorithm(new Wave);
                        std::cout << "Specify search radius delta: ";
                    }
                }
                double floatingParameter;
                std::cin >> floatingParameter;
                std::cout << "Found " << clusterizer->search(floatingParameter) << " clusters." << std::endl;
                std::ofstream output("out.json");
                if(output.good()) {
                    clusterizer->write(output);
                    output.close();
                    if(system("python3 visualizer.py"))
                        std::cout << "Visualizer module crashed!" << std::endl;
                }
                else
                    std::cout << "File IO Error!" << std::endl;
                break;
            }
            case MainMenuOption::saveFieldToFile : {
                char filename[DEF_STR_SIZE];
                std::cout << "Specify file name: ";
                std::cin >> filename;
                std::ofstream output(filename);
                if(output.good()) {
                    clusterizer->write(output);
                    output.close();
                }
                else
                    std::cout << "File IO Error!" << std::endl;
                break;
            }
            case MainMenuOption::quit : {
                mainMenuQuitFlag = true;
            }
        }
    }
    showQuitMessage();
}
