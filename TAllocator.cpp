
#include "TAllocator.h"
#include "TStack.h"
#include <iostream>



TAllocator::TAllocator(size_t size,size_t count): _size(size),_count(count)  {
    _used_blocks = (char*)malloc(_size*_count);


    //_free_blocks = (void**)malloc(sizeof(void*)*_count);
    _free_blocks = new TStack<void>();
    for (size_t i = 0; i < count; i++){
        _free_blocks->Push(_used_blocks + i*_size);
    }

    //for(size_t i=0;i<_count;i++) _free_blocks[i] = _used_blocks+i*_size;
    _free_count = _count;
      std::cout << "TAllocator: Memory init" << std::endl;
}

void *TAllocator::allocate() {
    void *result = nullptr;

    if(_free_count>0)
    {
        result = _free_blocks->Pop();
        _free_count--;
        std::cout << "TAllocator: Allocate " << (_count-_free_count) << " of " << _count << std::endl;
    } else
    {
        std::cout << "TAllocator: No memory exception" << std::endl;
    }

    return result;
}

void TAllocator::deallocate(void *pointer) {
  std::cout << "TAllocator: Deallocate block "<< std::endl;

  _free_blocks->Push(pointer);
  _free_count ++;

}

bool TAllocator::has_free_blocks() {
    return _free_count>0;
}

TAllocator::~TAllocator() {

    if(_free_count<_count) std::cout << "TAllocator: Memory leak?" << std::endl;
                    else  std::cout << "TAllocator: Memory freed" << std::endl;
    delete _free_blocks;
    delete _used_blocks;
}


