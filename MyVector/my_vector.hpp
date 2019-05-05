#pragma once
#include <vector>
#include <cstdlib>
#include <exception>
#include <algorithm>

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
        
        // Contructor
        Node(data_type a) : data(a), next(nullptr)
        {

        };

        void set_next(Node<data_type>* new_next) { next = new_next; }

        // Getters for accessing data
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
            while (pos < n and pos + 1 < element_count)
            {
                ptr = ptr->get_next();
                pos += 1;
            }
            return ptr;
        }
    public:
        using iterator = linear_iterator< element_type >;
        friend class iterator;

        // Constructors // Destructors //
        // Base constructor, initialize base pointer to nullptr
        vector() : base(nullptr), element_count(0)
        {

        }

        // Move constructor from same class
        vector(vector<element_type>&& other)
        {
            // Shallow copy, because we're moving data
            base = other.base;
            element_count = other.element_count;

            // Invalidate other class
            other.base = nullptr;
            other.element_count = 0;
        }

        // Copy constructor
        vector(const vector<element_type>& other): base(nullptr), element_count(0)
        {
            auto ptr = other.base;

            while (ptr != nullptr)
            {
                add(element_type(ptr->get_data_access()));
                ptr = ptr->get_next();
            }
        }

        // Move assignment
        vector<element_type> operator=(vector<element_type>&& other)
        {
            if (&other == this) return *this; // Same class detection
            this->~vector();

            // Copy pasta from move constructor ->>
            // Shallow copy, because we're moving data
            base = other.base;
            element_count = other.element_count;

            // Invalidate other class
            other.base = nullptr;
            other.element_count = 0;
            return *this;
        }

        // Copy assignment
        vector<element_type> operator=(const vector<element_type>& other)
        {
            if (&other == this) return *this; // Same class detection
            this->~vector();
            base = nullptr;
            element_count = 0;

            auto ptr = other.base;

            while (ptr != nullptr)
            {
                add(element_type(ptr->get_data_access()));
                ptr = ptr->get_next();
            }
            return *this;
        }

        // Destructor, should erase all elements
        ~vector()
        {
            while (base != nullptr)
            {
                auto current = base;
                base = base->next;
                delete current;
            }
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
            auto last = get_nth_node( std::max(static_cast<unsigned int>(0), element_count-1) );
            // element_count-1 overflows at 0 because it's unsigned

            if (base != nullptr)
                last->set_next( new Node<element_type>(element) );
            else
                base = new Node<element_type>(element);
            element_count += 1;
        }

        // operator[] ?? reference to nth element
        element_type& get(unsigned int position)
        {
            return get_nth_node(position)->get_data_access();
        }
        unsigned int size() const noexcept { return element_count; }
    };
    // -------------------------------------------------------------------
}
