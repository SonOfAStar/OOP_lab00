#include <cstdlib>
#include "Triangle.h"
#include "Pentagon.h"
#include "TContainer.h"
#include "Hexagon.h"
#include "Octagon.h"
#include "TIterator.h"



int main() {


    char command;

    std::cout << "Please, fill in a vector of figures." << std::endl;
    std::cout << "Use p to push a new figure at the back of a vector.\nUse a to add a figure at your desired position." << std::endl;
    std::cout << "Use s to get the size of the vector.\nUse o to print the vector from output stream.\nUse q to quit." << std::endl;
    std::cout << "Use i to call iterative output." << std::endl;
    std::cout << "Use d to delete a figure from the back.\n\nPlease, note, that you must only use indexes that are smaller than the size of the vector!" << std::endl;
    std::cin >> command;

    TContainer<Figure>* my_TContainer;
    std::shared_ptr<Figure> my_figure = nullptr;

    my_TContainer = new TContainer<Figure>();

    while (command != 'q'){

            if (command == 'a') {
                int pos;
                std::cout << "Please, type in the position of your figure!" << std::endl;
                std::cin >> pos;
                if( pos >= my_TContainer->Size()) {
                        std::cout << "You have tried accessing a nonexistent field! Quitting the program." << std::endl;
                        return 1;
                }

                std::cout << "Please type the first letter of the type of your figure." << std::endl;
                std::cin >> command;
                if (command == 'p'){
                    std::cout << "You chose to add a pentagon!" << std::endl;

                    std::cout << "Please, type in five points in std coordinate system. Do not forget the order!!" << std::endl << std::endl;
                    my_figure = std::shared_ptr<Figure>(new Pentagon(std::cin));
                }
                if (command == 'h'){
                    std::cout << "You chose to add a hexagon!" << std::endl;

                    std::cout << "Please, type in six points in std coordinate system. Do not forget the order!!" << std::endl << std::endl;
                    my_figure = std::shared_ptr<Figure>(new Hexagon(std::cin));
                }
                if (command == 'o'){
                    std::cout << "You chose to add a octagon!" << std::endl;

                    std::cout << "Please, type in eight points in std coordinate system. Do not forget the order!!" << std::endl << std::endl;
                    my_figure = std::shared_ptr<Figure>(new Octagon(std::cin));
                }

                my_TContainer->Set(pos, my_figure);
                //break;
            }

            else if (command == 'p'){
                std::cout << "Please type the first letter of the type of your figure." << std::endl;
                std::cin >> command;
                if (command == 'p'){
                    std::cout << "You chose to add a pentagon!" << std::endl;

                    std::cout << "Please, type in five points in std coordinate system. Do not forget the order!!" << std::endl << std::endl;
                    my_figure = std::shared_ptr<Figure>(new Pentagon(std::cin));
                }
                if (command == 'h'){
                    std::cout << "You chose to add a hexagon!" << std::endl;

                    std::cout << "Please, type in six points in std coordinate system. Do not forget the order!!" << std::endl << std::endl;
                    my_figure = std::shared_ptr<Figure>(new Hexagon(std::cin));
                }
                if (command == 'o'){
                    std::cout << "You chose to add a octagon!" << std::endl;

                    std::cout << "Please, type in eight points in std coordinate system. Do not forget the order!!" << std::endl << std::endl;
                    my_figure = std::shared_ptr<Figure>(new Octagon(std::cin));
                }

                if(!(my_TContainer->Push_back(my_figure))){
                    std::cout << "Something went wrong! Quitting the program." << std::endl;
                    return 1;
                }

            }

            else if (command == 's'){
                std::cout << "The size of your vector is " << my_TContainer->Size() << std::endl;
            }

            else if (command == 'o'){
                std::cout << my_TContainer;
            }

            else if (command == 'd'){
                if (!(my_TContainer->empty())){
                    my_TContainer->Pop_back();
                    std::cout << "Deleted the last element from the vector." << std::endl;
                }
                else {
                    std::cout << "Do not try this at home!\nTrying to delete from an empty vector gone wrong!" << std::endl;
                }
            }
            else if (command == 'i'){
                std::cout << "Printing with iterators." << std::endl;
                for (auto i : *my_TContainer){
                    std::cout << "Printing element:" << std::endl;
                    i->Print();
                }
            }
            else {
                    std::cout << "Wrong command!" << std::endl;
            }

            my_figure = nullptr;

            std::cout << "Please, enter your next command: ";
            std::cin >> command;

    }

    delete my_TContainer;

    return 0;
}

/*
0 0
0 1
1 2
2 1
2 0
*/

/*
0 2
1 1
2 0
1 -1
0 -2
-1 -1
-2 0
-1 1
*/
