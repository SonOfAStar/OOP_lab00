#ifndef TCONTAINER_H_INCLUDED
#define TCONTAINER_H_INCLUDED

#include <memory>
#include <iostream>
#include "TIterator.h"
#include "MyStack.h"
#include "TFigure.h"

class TContainer
{

    private:
        MyStack <std::shared_ptr<Figure>>*  massive_Body;
        unsigned int massive_Size;
        unsigned int massive_Capacity ;

    public:
        TContainer(){
            this->massive_Capacity = 10;
            this->massive_Size = 0;
            this->massive_Body = new MyStack <std::shared_ptr<Figure>>[10];
        }

        bool Push_back (std::shared_ptr<Figure> data){
            if (this->massive_Size == this->massive_Capacity){
                massive_Capacity *= 1.5;
                //std::cout << "?";
                MyStack<std::shared_ptr<Figure>>* newbody = new MyStack<std::shared_ptr<Figure>>[massive_Capacity];
                if (!newbody){
                    return false;
                }
                for(int i = 0; i < massive_Size; i++){
                    newbody[i] = massive_Body[i];
                }

                delete massive_Body;
                massive_Body = newbody;
            }
            //std::cout << "|" << std::endl;
            //massive_Body[massive_Size] = new MyStack<std::shared_ptr <Figure> >();
            massive_Body[massive_Size].Push(data);
            ++massive_Size;
            return true;
        }

        bool empty(){
            return this->Size() == 0;
        }

        void del(char t){
            for (int i = 0; i < massive_Size; i++){
                std::cout << "Checking " << i << "th stack.\n";
                massive_Body[i].del(t);
                std::cout << "Checking " << i << "th stack is finished.\n";
                if (massive_Body[i].size() == 0){
                    for (int j = i+1; j < massive_Size; j++){
                        massive_Body[j-1] = massive_Body[j];
                    }
                    --this->massive_Size;
                }
            }
        }

        void del(double sq){
            for (int i = 0; i < massive_Size; i++){
                std::cout << "Checking " << i << "th stack.\n";
                massive_Body[i].del(sq);
                if (massive_Body[i].size() == 0){
                    for (int j = i+1; j < massive_Size; j++){
                        massive_Body[j-1] = massive_Body[j];
                    }
                    --this->massive_Size;
                }
            }
        }

        std::shared_ptr<Figure> Pop_back(){
            return massive_Body[massive_Size - 1].Pop();
        }


        int Size() const {
            return this->massive_Size;
        }

        bool Set(int pos, std::shared_ptr<Figure> &data){
            if(this->massive_Body[pos].size() < 5) {
                    std::cout << "Pushing at " << pos << ".\n";
                    massive_Body[pos].Push(data);

            }
            else {
                std::cout << "The stack you requested is already full!\n Type c to continue with adding anyway, type anything else to stop." << std::endl;
                char c;
                std::cin >> c;
                if (c != 'c'){
                    return true;
                }
                else{
                    int cp = pos;
                    while (cp < massive_Size){
                        if(this->massive_Body[cp].size() < 5) {
                            massive_Body[cp].Push(data);
                            return true;
                        }
                        ++cp;
                    }
                    std::cout << "The massive is full, pushing a new element." << std::endl;
                    this->Push_back(data);
                }
            }
            return true;
        }

        MyStack <std::shared_ptr<Figure>>* Get(int pos)const {
            return &(this->massive_Body[pos]);
        }

        friend std::ostream& operator << (std::ostream& os,const TContainer* massive){
            std::cout << "Printing massive." << std::endl;

            for (int i = 0; i < massive->Size(); i++){
                std::cout << i << "th stack is:\n";
                MyStack <std::shared_ptr<Figure>>* p = massive->Get(i);
                p->Print();
                std::cout << "\n\n";
            }
            return os;
        }

        TIterator <std::shared_ptr<Figure>> begin(){
            return TIterator<std::shared_ptr<Figure>>(massive_Body,0);
        }
        TIterator <std::shared_ptr<Figure>> end(){
            if (this->Size() > 0){
                return TIterator<std::shared_ptr<Figure>>(massive_Body,this->Size());
            }
            return TIterator <std::shared_ptr<Figure>>(nullptr, 0);

        }

        ~TContainer(){
            for (int i = 0; i < this->Size(); i++){
                while (massive_Body[i].size() > 0){
                    massive_Body[i].Pop();
                }
            }
            delete this->massive_Body;
        }
};

#endif // TContainer_H_INCLUDED
