#include <iostream> 
#include <vector> 

void test_lambdas(void); 

int main(void)
{
    test_lambdas(); 
    return 0; 
}

void test_lambdas(void)
{
    // max between two ints 
    int max_number = [](int x, int y) -> int {
                        return x > y ? (x) : (y); 
                     }(100, 200); 
    std::cout << "Max Number:" << max_number << std::endl; 

    int arr[] = {10, 20, 30, 40, 50}; 
    // max in array of integers 
    max_number = [](int* a, int N) -> int{
                    int i; 
                    int m; 
                    m = a[0];
                    for(i = 1; i < N; ++i)
                        if(a[i] > m)
                            m = a[i];
                    return m; 
                }(arr, 5); 
    std::cout << "Max Number:" << max_number << std::endl; 

    // quadratic 
    std::vector<double> roots = [](double a, double b, double c) -> std::vector<double> {
                        std::vector<double> d_vec{nan(0), nan(0)}; 
     
                        if(a != 0 && b*b >= 4*a*c)
                        {
                            d_vec[0] = (-b + sqrt(b*b-4*a*c))/(2*a); 
                            d_vec[1] = (-b - sqrt(b*b-4*a*c))/(2*a);  
                        }
        
                        return d_vec; 
                    }(-3.4, 4.5, 8.0); 
    
    if(roots[0] != nan(0) && roots[1] != nan(0))
        std::cout << "root1:" << roots[0] << ", root2:" << roots[1] << std::endl; 
}

// Newton's gravitational force compute -> lambda 
// Columbs force compute -> lambda 
// quadratic eqn roots -> lambda 