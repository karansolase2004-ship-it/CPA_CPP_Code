#include "list.hpp"
#include "gl_framework.hpp"

int main(void){
    cpa::gl::vertex_shader vs(std::string(
        // vertex shader
    )); 

    vs.compile();
    vs.link_to_program_object(); 

    cpa::dsa::list<cpa::gl_framework::vertex_shader> vs_list; 

    vs_list.insert_end(cpa::gl_framework::vertex_shader("

    ") ); 

}
