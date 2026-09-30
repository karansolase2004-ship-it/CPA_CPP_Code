while(there is next line in the current section){
    switch(section_type){
        case DATA_SECTION: 
            break; 
        case BSS_SECTION: 
            break; 
        case TEXT_SECTION: 
            parse_instruction(line);
    }

}

void parse_instruction(const char* next_line){
    char* sep = ' '; 
    char* word = NULL;

    char* line = (char*)next_line;

    word = strtok(line, sep) ; 

    bool status = is_word_suffix(word); 
    
    if(!status)
        status = is_word_opcode(word); 
    
    if(status)
        while((word = strtok(NULL, line))){
            OPERAND_TYPE op_type = get_operand_type(word); 
        }
}

OPERAND_TYPE get_operand_type(const char* word){
    operand type of word is invalid 
    
}