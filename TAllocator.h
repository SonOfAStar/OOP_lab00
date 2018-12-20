
#ifndef TALLOCATOR_H_INCLUDED
#define TALLOCATOR_H_INCLUDED

#include <cstdlib>
#include "TStack.h"


class TAllocator {
public:
    TAllocator(size_t size,size_t count);
    void *allocate();
    void deallocate(void *pointer);
    bool has_free_blocks();

    virtual ~TAllocator();
private:
    size_t _size;
    size_t _count;

    char  *_used_blocks;
    TStack<void>* _free_blocks;

    size_t _free_count;


};


#endif // TALLOCATOR_H_INCLUDED

