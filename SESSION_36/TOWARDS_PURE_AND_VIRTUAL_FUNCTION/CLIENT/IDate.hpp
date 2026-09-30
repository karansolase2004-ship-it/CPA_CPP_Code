#ifndef _IDATE_HPP 
#define _IDATE_HPP 

class IDate{
    public: 
        virtual int get_day(); 
        virtual int get_month();
        virtual int get_year();
        virtual void set_day(int new_day); 
        virtual void set_month(int new_month);
        virtual void set_year(int new_year);
        virtual void show(); 
        static IDate* get_instance(int init_day, int init_month, int init_year); 
        static void release_instance(IDate* pIDate); 
}; 

#endif 