#ifndef _IDATE_HPP 
#define _IDATE_HPP 

class IDate{
    public: 
        virtual int get_day() = 0; 
        virtual int get_month() = 0; 
        virtual int get_year() = 0; 
        virtual void set_day(int new_day) = 0; 
        virtual void set_month(int new_month) = 0; 
        virtual void set_year(int new_year) = 0; 
        virtual void show() = 0; 
        static IDate* get_instance(int init_day, int init_month, int init_year); 
        static void release_instance(IDate* pIDate); 
}; 

#endif 
