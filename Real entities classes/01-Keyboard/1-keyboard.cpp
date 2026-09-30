//Class & Struct for HP Wired Keyboard

#include <iostream>

#define ENDL <<std::endl

class Keyboard{
    private:
    struct keyboardProps {
        const char* name;
        int price;
        const char* brand;
        char manufacturer[30];
        const char* model;
        const char* model_name;
        struct dimensions {
            float length;
            float width;
            float height;
        } dimension_of_product;
        unsigned int weight;
        const char* item_model_number;
        const char* operating_system;
        const char* hardware_platform;
        const char* hardware_interface;
        const char* compatible_devices;
        const char* special_feature;
        const char* mounting_hardware;
        unsigned short int number_of_items;
        const char* batteries_required;
        const char* keyboard_description;
        const char* connector_type;
        const char* hand_orientation;
        const char* has_attached_light;
        const char* country_of_origin;
    };

    struct keyboardProps new_keyboard;
    
    public:
    Keyboard(){
        new_keyboard = {
            "HP 150 Wired Keyboard",
            549,
            "HP",
            "HP, HP India Sales Pvt Ltd.",
            "664R5AA",
            "HP 150 Wired Keyboard",
            {
                42.6,
                14.6,
                2.7
            },
            440,
            "664R5AA",
            "Windows 10",
            "Laptop",
            "USB",
            "Laptop",
            "Ergonomic",
            "USB Cable",
            1,
            "No",
            "Wired",
            "Wired",
            "Ambidextrous",
            "No",
            "China"
        };
    }

    void show_product_details();
};


int main(){
    std::cout << "Technical Details of HP Wired Keyboard" << std::endl;

    Keyboard Keyboard1;

    Keyboard1.show_product_details();

    return 0;
}

void Keyboard::show_product_details(){
    std::cout << "Inside show_product_details" << std::endl;
    std::cout << "name                      :   " << this->new_keyboard.name ENDL;
    std::cout << "price                     :   " << this->new_keyboard.price ENDL;
    std::cout << "brand                     :   " << new_keyboard.brand ENDL;
    std::cout << "manufacturer              :   " << new_keyboard.manufacturer ENDL;
    std::cout << "model                     :   " << new_keyboard.model ENDL;
    std::cout << "model_name                :   " << new_keyboard.model_name ENDL;
    std::cout << "dimension_of_product      :   " << new_keyboard.dimension_of_product.height << "x" 
                                                  << new_keyboard.dimension_of_product.length << "x"
                                                  << new_keyboard.dimension_of_product.width ENDL;
    std::cout << "weight                    :   " << new_keyboard.weight ENDL;
    std::cout << "item_model_number         :   " << new_keyboard.item_model_number ENDL;
    std::cout << "operating_system          :   " << new_keyboard.operating_system ENDL;
    std::cout << "hardware_platform         :   " << new_keyboard.hardware_platform ENDL;
    std::cout << "compatible_devices        :   " << new_keyboard.compatible_devices ENDL;
    std::cout << "hardware_interface        :   " << new_keyboard.hardware_interface ENDL;
    std::cout << "special_feature           :   " << new_keyboard.special_feature ENDL;
    std::cout << "mounting_hardware         :   " << new_keyboard.mounting_hardware ENDL;
    std::cout << "number_of_items           :   " << new_keyboard.number_of_items ENDL;
    std::cout << "batteries_required        :   " << new_keyboard.batteries_required ENDL;
    std::cout << "keyboard_description      :   " << new_keyboard.keyboard_description ENDL;
    std::cout << "connector_type            :   " << new_keyboard.connector_type ENDL;
    std::cout << "hand_orientation          :   " << new_keyboard.hand_orientation ENDL;
    std::cout << "has_attached_light        :   " << new_keyboard.has_attached_light ENDL;
    std::cout << "country_of_origin         :   " << new_keyboard.country_of_origin ENDL;
}
