/* class list {
    private :
       node* head_node;

       static void generic_insert(node* p_start, node* p_new, node* p_end){

       }

       public : 
          void insert_start(int data);
          void insert_end(int data);
          void insert_after(int e_data, int data);
          void insert_before(int e_data, int data);
}; */

////////////////////////////////////

class Date{
    private: 
        int day; 
        int month; 
        int year; 

    static int is_date_valid(int dd, int mm, int yy){

        }
    public: 
        Date(){

        }

        Date(int _d, int _m, int _y){

        }

        int get_day(){
            return day; 
        }

        int get_month(){
            return month; 
        }

        int get_year(){
            return year; 
        }

        void set_day(int new_day){
            day = new_day; 
        }   

        void set_month(int new_month){
            month = new_month; 
        }

        void set_year(int new_year){
            year = new_year; 
        }
}; 

int main(void){
    int Date::is_date_valid(1, 1, 1970); 
}