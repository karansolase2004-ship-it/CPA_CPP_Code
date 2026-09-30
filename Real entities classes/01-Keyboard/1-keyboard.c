//Struct for HP Wired Keyboard

#include <stdio.h>
#include <stdlib.h>

struct keyboardProps {
    char* name;
    unsigned int price;
    char* brand;
    char manufacturer[50];
    char* model;
    char* model_name;
    struct dimensions {
        float length;
        float width;
        float height;
    } dimension_of_product;
    unsigned int weight;
    char* item_model_number;
    char* operating_system;
    char* hardware_platform;
    char* hardware_interface;
    char* compatible_devices;
    char* special_feature;
    char* mounting_hardware;
    unsigned short int number_of_items;
    char* batteries_required;
    char* keyboard_description;
    char* connector_type;
    char* hand_orientation;
    char* has_attached_light;
    char* country_of_origin;
};

struct keyboardProps new_keyboard = {
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

int main(){

    puts("Technical Details of HP Wired Keyboard");

    printf("name                            :       %s\n", new_keyboard.name);
    printf("price                           :       %d\n", new_keyboard.price);
    printf("brand                           :       %s\n", new_keyboard.brand);
    printf("manufacturer                    :       %s\n", new_keyboard.manufacturer);
    printf("model                           :       %s\n", new_keyboard.model);
    printf("model_name                      :       %s\n", new_keyboard.model_name);
    printf("dimension_of_product            :       %.1f * %.1f * %.1f\n", new_keyboard.dimension_of_product.height, new_keyboard.dimension_of_product.length, new_keyboard.dimension_of_product.width);
    printf("weight                          :       %d\n", new_keyboard.weight);
    printf("item_model_number               :       %s\n", new_keyboard.item_model_number);
    printf("operating_system                :       %s\n", new_keyboard.operating_system);
    printf("hardware_platform               :       %s\n", new_keyboard.hardware_platform);
    printf("compatible_devices              :       %s\n", new_keyboard.compatible_devices);
    printf("special_feature                 :       %s\n", new_keyboard.hardware_interface);
    printf("hardware_interface              :       %s\n", new_keyboard.special_feature);
    printf("mounting_hardware               :       %s\n", new_keyboard.mounting_hardware);
    printf("number_of_items                 :       %d\n", new_keyboard.number_of_items);
    printf("batteries_required              :       %s\n", new_keyboard.batteries_required);
    printf("keyboard_description            :       %s\n", new_keyboard.keyboard_description);
    printf("connector_type                  :       %s\n", new_keyboard.connector_type);
    printf("hand_orientation                :       %s\n", new_keyboard.hand_orientation);
    printf("has_attached_light              :       %s\n", new_keyboard.has_attached_light);
    printf("country_of_origin               :       %s\n", new_keyboard.country_of_origin);

    return 0;
}
