#include <iostream>
#include <cstdlib>

class range
{
    private :
    int n_start;
    int n_end;

    public : 
    range(int _start, int _end): n_start(_start), n_end(_end)
    {
        if(n_start >= n_end)
        {
            std::cout << "Start Must Be Less Than end" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    class iterator;

    iterator begin()const{
        iterator iter(n_start);
        return iter;
    }

    iterator end() const{
        iterator iter(n_end);
        return iter;
    }

    class iterator 
    {
        private :
        int current_n;
        public :
        iterator(int _n) : current_n(_n){

        }

        int operator*()
        {
            return current_n;
        }

        iterator operator++()
        {
            current_n += 1;
            return *this;
        }

        iterator operator++(int)
        {
            iterator iter(current_n);
            current_n += 1;
            return iter;
        }

        iterator operator--()
        {
            current_n -= 1;
            return *this;
        }

        iterator operator--(int)
        {
            iterator iter(current_n);
            current_n -= 1;;
            return iter;
        }

        bool operator==(const iterator& rhs)
        {
            return current_n == rhs.current_n;
        }

        bool operator!=(const iterator& rhs)
        {
            return current_n != rhs.current_n;
        }
    };
};

int main (void)
{
    range R(10, 20);

    std::cout << "Using While Loop : " << std::endl;

    range::iterator Iter_1 = R.begin();

    while(Iter_1 != R.end())
    {
        std::cout << "*Iter_1 : " << *Iter_1 << std::endl;
        ++Iter_1;
    }

    std::cout << "Using For Loop" << std::endl;

    for(
        range::iterator Iter_1 = R.begin();
        Iter_1 != R.end();
        ++Iter_1
    )
    {
        std::cout << "*Iter_1 : " << *Iter_1 << std::endl;
    }
}