//Struct for Nivea Face Wash

#include <stdio.h>
#include <stdlib.h>

struct productProps{
    char* name;
    unsigned int price;
    struct Dimensions{
        float length;
        float width;
        float height;
    } dimensions_of_product;
    struct Date{
        unsigned short int day;
        char* month;
        unsigned short year;
    } date_first_available;
    char* manufacturer;
    char* ASIN;
    unsigned long int item_model_number;
    char* country_of_origin;
    char* packer;
    char* importer;
    unsigned int weight;
    unsigned int net_quantity;
    char* included_components;
    char* generic_name;
    unsigned int best_seller_rank;
    float customer_review_rating;
};

struct productProps new_product = {
    "Nivea Face Wash",
    191,
    {
        7.7f,
        5,
        12.7f
    },
    {
        1,
        "January",
        2014
    },
    "Nivea",
    "B006LX9VPU",
    4005808535460,
    "India",
    "Nivea",
    "Nivea India Pvt Ltd",
    100,
    1,
    "Men Face Wash",
    "Face Wash",
    287,
    4.2f
};

struct productProps* new_faceWash = &new_product;

int main(){
    puts("Product Details of Nivea Face Wash");

    printf("name                        :          %s\n", new_faceWash->name);
    printf("price                       :          %d\n", new_faceWash->price);
    printf("dimensions_of_product       :          %.1f x %0.1f x %.1f\n", new_faceWash->dimensions_of_product.height, new_faceWash->dimensions_of_product.length, new_faceWash->dimensions_of_product.width);
    printf("date_first_available        :          %d-%s-%d\n", new_faceWash->date_first_available.day, new_faceWash->date_first_available.month, new_faceWash->date_first_available.year);
    printf("manufacturer                :          %s\n", new_faceWash->manufacturer);
    printf("ASIN                        :          %s\n", new_faceWash->ASIN);
    printf("item_model_number           :          %lu\n", new_faceWash->item_model_number);
    printf("country_of_origin           :          %s\n", new_faceWash->country_of_origin);
    printf("packer                      :          %s\n", new_faceWash->packer);
    printf("importer                    :          %s\n", new_faceWash->importer);
    printf("weight                      :          %u\n", new_faceWash->weight);
    printf("net_quantity                :          %u\n", new_faceWash->net_quantity);
    printf("included_components         :          %s\n", new_faceWash->included_components);
    printf("generic_name                :          %s\n", new_faceWash->generic_name);
    printf("best_seller_rank            :          %u\n", new_faceWash->best_seller_rank);
    printf("customer_review_rating      :          %.1f\n", new_faceWash->customer_review_rating);

    return(0);
}
