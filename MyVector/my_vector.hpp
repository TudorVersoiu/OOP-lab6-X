#pragma once

#ifndef VEC_DEFAULT_SIZE
#define VEC_DEFAULT_SIZE 4
#endif

namespace my {

    template<typename element_type>
    class vector
    {
    private:
        element_type* mem_raw_pointer;
        unsigned int memory_count;
        unsigned int element_count;
        // Base types

        class iterator {

        };
        // vector::iterator class

    public:
        vector()
        {
            mem_raw_pointer = new element_type[DEFAULT_SIZE];
            memory_count = DEFAULT_SIZE;
        }
    };
}