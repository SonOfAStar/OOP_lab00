#ifndef TCONTAINER_H_INCLUDED
#define TCONTAINER_H_INCLUDED

#include <memory>
#include <iostream>
#include <exception>
#include <cstdlib>
#include <future>
//#include <thread>
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

        TContainer(int t){
            this->massive_Capacity = t;
            this->massive_Size = t;
            this->massive_Body = new std::shared_ptr<T>[t];
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

        bool Set(int pos, std::shared_ptr<T> data){
            if(pos >= this->massive_Size){
                return false;
            }
            this->massive_Body[pos-1] = data;;
            return true;
        }

        std::shared_ptr<T> Get(int pos)const {
            return (this->massive_Body[pos]);
        }

        //std::future<void> sort_in_background();

        std::future<void> sort_in_background() {
            std::packaged_task<void(void) > task(std::bind(std::mem_fn(&TContainer<T>::t_sorte), this));
            std::future<void> res(task.get_future());
            std::thread th(std::move(task));
            th.detach();
            return res;
        }


        void t_sorte(){
            if(massive_Size > 1){
            std::cout << "Sorting with merge_paral, size = " << massive_Size << '\n';
            TContainer* left = new TContainer<Figure>(), *right = new TContainer<Figure>();
            std::shared_ptr<Figure> mid = massive_Body[massive_Size/2];
            for (int i = 0; i < massive_Size; i++){
                    if (i != massive_Size/2){
                        if (massive_Body[i]->Square() > mid->Square()){
                            right->Push_back(massive_Body[i]);
                        }
                        else left->Push_back(massive_Body[i]);
                    }
            }
            std::cout << "filled\n";

            std::future<void> left_res = left->sort_in_background();
            std::future<void> right_res = right->sort_in_background();

            left_res.get();
            int i;
            for(i = 0; i < left->Size(); i++){
                massive_Body[i] = left->Get(i);
            }
            massive_Body[i] = mid;
            i++;

            right_res.get();
            for (int j = 0; j < right->Size(); i++){
                massive_Body[i+j] = right->Get(j);
            }
            std::cout << "copied\n";
            delete(left);
            delete(right);
            }
        return;
        }

        void sorte(){
            if (massive_Size > 1){
                std::cout << "Sorting with merge_non_paral, size = " << massive_Size << '\n';
                TContainer* left = new TContainer<Figure>(), *right = new TContainer<Figure>();
                std::shared_ptr<Figure> mid = massive_Body[massive_Size/2];

                for (int i = 0; i < massive_Size; i++){
                    if (i != massive_Size/2){
                        if (massive_Body[i]->Square() > mid->Square()){
                            right->Push_back(massive_Body[i]);
                        }
                        else left->Push_back(massive_Body[i]);
                    }
                }
                std::cout << "filled\n";
                left->sorte();
                right->sorte();

                int i;
                for(i = 0; i < left->Size(); i++){
                    massive_Body[i] = left->Get(i);
                }
                massive_Body[i] = mid;
                i++;
                for (int j = 0; j < right->Size(); i++){
                    massive_Body[i+j] = right->Get(j);
                }
                std::cout << "copied\n";
                delete(left);
                delete(right);
                return;
            }
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
