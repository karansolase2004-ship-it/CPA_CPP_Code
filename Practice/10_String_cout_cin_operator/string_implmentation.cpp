#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>

/* namespace cpa{
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
 */

int main(void){
    test_string(); 
    return 0; 
}

void test_string(void){
    std::string s1; // empty string 
    std::string s2("Hello,World"); 
    std::string s3(s2); 
    std::string s4(5, 'A'); 

    std::cout   << "s1:" << s1 << std::endl 
                << "s2:" << s2 << std::endl
                << "s3:" << s3 << std::endl 
                << "s4:" << s4 << std::endl; 

    const char* p_str_1 = s1.c_str(); 
    const char* p_str_2 = s2.c_str(); 
    const char* p_str_3 = s3.c_str(); 
    const char* p_str_4 = s4.c_str(); 

    printf("str1 = %s, str2 = %s, str3 = %s, str4 = %s\n", 
        p_str_1, p_str_2, p_str_3, p_str_4); 
}
