#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace cpa{
    class string{
        private :
           char* p_str;
           size_t N;
        public : 
           string() : p_str(0), N(0){

           }

           string(const char*  init_str){
             N = strlen(init_str);
             p_str = (char*)malloc(N + 1);
             if(p_str == 0){
                // error
             }

             strncpy(p_str, init_str, N);
             p_str[N] = '\0';
           }

           string(size_t _N, char C){
            N = _N;
            p_str = (char*)malloc( N + 1);
            if(p_str == 0){
                //error
            }

            memset(p_str, 'A', N);
            p_str[N] = '\0';
           }

           void show() const{
            if(p_str != 0){
                printf("String = %s\n", p_str);
            }
            else
                printf("string = \n");
           }

           ~string(){
            free(p_str);
           }
    };
}

int main (void){
    cpa::string  s1;
    cpa::string s2("CORECODE PROGRAMMING ACADEMY");
    cpa::string s3(5, 'A');

    s1.show();
    s2.show();
    s3.show();

    return 0;
}