#ifndef TCONTAINER_H_INCLUDED
#define TCONTAINER_H_INCLUDED

#include <memory>
#include <iostream>
#include "TIterator.h"

template <class T>
class TContainer
{

    private:
        std::shared_ptr<T>*  massive_Body;
        unsigned int massive_Size;
        unsigned int massive_Capacity ;

    public:
        TContainer(){
            this->massive_Capacity = 10;
            this->massive_Size = 0;
            this->massive_Body = new std::shared_ptr<T>[10];
        }

        bool Push_back (std::shared_ptr<T> &data){
            if (this->massive_Size == this->massive_Capacity){
                this->massive_Capacity = this->massive_Capacity * 1.5;
                std::shared_ptr<T> new_body [this->massive_Capacity];
                for (int i = 0; i < this->massive_Size; i++){
                    new_body[i] = this->massive_Body[i];
                    //free(this->massive_Body[i]);
                }
                this->massive_Body = new_body;
            }
            if (this->massive_Body == nullptr){
                free(this->massive_Body);
                this->massive_Capacity = 0;
                this->massive_Size = 0;
                return false;
            }
            this->massive_Body[this->massive_Size] = data;
            ++this->massive_Size;
            return true;
        }

        bool empty(){
            return this->Size() == 0;
        }

        std::shared_ptr<T> Pop_back(){
            std::shared_ptr<T> backtrack = this->massive_Body[this->massive_Size-1];
            this->massive_Body[this->massive_Size-1] = nullptr;
            this->massive_Size -= 1;
            //this->massive_Body = (std::shared_ptr<T>)realloc(this->massive_Body, this->massive_Size * sizeof(std::shared_ptr<T>));
            //this->massive_Capacity = this->massive_Size;
            return backtrack;
        }


        int Size() const {
            return this->massive_Size;
        }

        bool Set(int pos, std::shared_ptr<T> &data){
            if(pos >= this->massive_Size){
                return false;
            }
            this->massive_Body[pos-1] = data;;
            return true;
        }

        std::shared_ptr<T> Get(int pos)const {
            return (this->massive_Body[pos]);
        }

        friend std::ostream& operator << (std::ostream& os,const TContainer<T>* massive){
            for (int i = 0; i < massive->Size(); i++){
                std::cout << i << "th element is:\n";
                std::shared_ptr<T> p = massive->Get(i);
                p->Print();
                std::cout << "\n\n";
            }
            return os;
        }

        TIterator <T> begin(){
            return TIterator<T>(massive_Body,0);
        }
        TIterator <T> end(){
            if (this->Size() > 0){
                return TIterator<T>(massive_Body,this->Size());
            }
            return TIterator<T>(nullptr, 0);

        }

        ~TContainer(){
            for (int i = 0; i < this->Size(); i++){
                this->massive_Body[i] = nullptr;
            }
        }
};

#endif // TContainer_H_INCLUDED
