#include <cstdlib>
#include <algorithm>
#include "Triangle.h"
#include <thread>
#include "Pentagon.h"
#include "TContainer.h"
#include "Hexagon.h"
#include "Octagon.h"
#include "TIterator.h"
#include "MyStack.h"



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
    MyStack* my_stack = new MyStack();


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

            else if (command == 't'){
                my_TContainer->t_sorte();
            }

            else if (command == 'm'){
                my_TContainer->sorte();
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
            else if (command == '*'){
                std::cout << "Write the special operation: " ;
                std::cin >> command;
                my_stack->Push(command);
            }
            else if (command == '!'){
                while (my_stack->Empty()){
                    char t = my_stack->Pop();
                    if (t == 'r'){
                    std::for_each(my_TContainer->begin(),my_TContainer->end(),[](std::shared_ptr<Figure> _n){
                                _n = nullptr;
                                int var = rand()%3;
                                int modif = rand() % 25;
                                if(var == 0){
                                    _n = std::shared_ptr<Figure>(new Pentagon(0+modif, 0+modif, 1+modif, 2+modif, 2+modif,0+modif,1+modif,2+modif,1+modif,0+modif));
                                }
                                else if (var == 1){
                                    _n = std::shared_ptr<Figure>(new Hexagon(0+modif, 0+modif, 1+modif, 2+modif, 2+modif, 1+modif,0+modif,1+modif,2+modif,1+modif,0+modif,modif-1));
                                }
                                else if (var == 2){
                                    _n = std::shared_ptr<Figure>(new Octagon(0+modif, 1+modif, 2+modif, 1+modif, 0+modif, modif-1, modif-2, modif-1,2+modif,1+modif,modif,modif-1,modif-2,modif-1,modif,1+modif));
                                }
                             });
                    }else if(t == 'p'){
                        std::for_each(my_TContainer->begin(),my_TContainer->end(),[](std::shared_ptr<Figure> _n){
                                        _n->Print();
                                        std::cout << "\n";
                                      });

                    }else if (t == 'd'){
                        double sq;
                        std::cin >> sq;
                        std::for_each(my_TContainer->begin(),my_TContainer->end(),[](std::shared_ptr<Figure> _n){
                                        double sq;
                                        std::cin >> sq;
                                        if (_n->Square() < sq){
                                        _n = std::shared_ptr<Figure>(new Pentagon());
                                      }
                                      });
                    }
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

/* 1
0 0
0 1
1 2
2 1
2 0
*/

/* 3,4
1 1
1 3
2 4
3 3
3 1
*/

/* 2
-2 2
2 2
4 0
2 -2
-2 -2
*/

/* 4
-2 2
2 2
3 0
2 -2
-2 -2
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
