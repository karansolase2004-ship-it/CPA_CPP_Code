class Date{
    private: 
       int day;
       int month;
       int year;
    public:
       Date() : day(1), month(1), year(1970)}{

       }

       Date(int init_day, int init_month, int init_year){
            this ->day = init_day;
            this ->month = init_month;
            this ->year = init_year;      
}
};