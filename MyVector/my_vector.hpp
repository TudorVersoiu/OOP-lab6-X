#pragma once
#include <vector>
#include <cstdlib>
#include <exception>

// Temporary implementation, may go nuts in 'special' cases
// Eg: threads :D

// Linked list implementation?!?

namespace my {
    // -------------------------------------------------------------------
    // Data type for vector node -----------------------------------------
    // -------------------------------------------------------------------
    template<typename data_type>
    class Node {
    private:
        data_type data;
    public:
        Node<data_type>* next; //hehe
        Node(data_type a) : data(a)
        {

        };

        Node<data_type>* get_next() noexcept { return next; }
        data_type& get_data_access() noexcept { return data; }
    };


    // Default size for vector
    static constexpr int VEC_DEFAULT_SIZE = 2;

    // ---------------------------------------------------------------------
    // Data type for vector iterator ---------------------------------------
    // ---------------------------------------------------------------------
    template<typename type> class linear_iterator {
    private:
        Node<type>* p_element;
    public:
        linear_iterator() = delete;
        linear_iterator(Node<type>* element_address) : p_element(element_address) {}

        

        void operator++() { p_element = p_element->get_next(); }
        type operator* () { return p_element->get_data_access(); }
        bool operator!=(const linear_iterator<type>& other) { return this->p_element != other.p_element; }
    };

    // ---------------------------------------------------------------------
    // Vector type ---------------------------------------------------------
    // ---------------------------------------------------------------------
    template<typename element_type> class vector {
    private:
        Node<element_type>* base;
        unsigned int element_count;


        // Private function to get around the list internally
        Node<element_type>* get_nth_node(unsigned int n)
        {
            auto ptr = base; unsigned int pos = 0;
            while (pos < n and pos < element_count)
                ptr = ptr->get_next();
            return ptr;
        }
    public:
        using iterator = linear_iterator< element_type >;
        friend class iterator;

        // Constructors // Destructors //
        // Base constructor, initialize base pointer to nullptr
        vector() : base(nullptr)
        {

        }

        // Destructor, should erase all elements
        ~vector()
        {

        }

        // Gets iterator containing address to first node
        iterator begin()
        {
            return iterator(base);
        }

        // Should return element following 'last'
        // Wel'll try null
        iterator end()
        {
            return iterator(nullptr);
        }

        // Equivalent to push_back, should add element to the end of the vector
        void add(element_type element)
        {
            auto last = get_nth_node(element_count - 1);
            if (last != nullptr)
                last->next = new Node<element_type>(element);
            else
                base = new Node<element_type>(element);
            element_count += 1;
        }
        element_type& get(unsigned int position)
        {
            return get_nth_node(position)->get_data_access();
        }
        unsigned int size() const noexcept { return element_count; }
    };
    // -------------------------------------------------------------------
}
