#ifndef _DATE_HPP
#define _DATE_HPP

class Date{
    private:
         //Data Layout 
         int day;
         int month;
         int year;

    public:
        //Default constructor
        Date();

        //Parameterized constrcutor 
        Date(int init_day, int init_month, int init_year);

        //Getters 
        int get_day() const;
        int get_month() const;
        int get_year() const;

        //Setters
        void set_day(int new_day);
        void set_month(int new_month);
        void set_year(int new_year);
        
        //Representation on standard output device
        void show() const;
};

#endif /* _DATE_HPP */