#include "user_interface.cpp"

// I made it so the only warnings given by -Weverything are those of
// C++98 incompatibility, which I honestly don't give one fuck about

int main(void) {
    UserInterface *userInterface = new UserInterface;
    userInterface->main();
    return 0;
}
