#ifndef _RANGE_HPP
#define _RANGE_HPP

class range{
    private :
       int n_start;
       int n_end;

    public :
       class iterator; // Forward
       range(int start, int end); // Default constructor

       // member function :
       iterator begin()const;
       iterator end() const;

    class iterator{
        private :
           int current_n;
        public :
        iterator(int current); // Deafult constructor;
        int& operator*();
        iterator operator++();
        iterator operator++(int);
        iterator operator--();
        iterator operator--(int);
        
        bool operator==(const iterator& rhs);
        bool operator!=(const iterator& rhs);
    };
};

#endif /* _RANGE_HPP */