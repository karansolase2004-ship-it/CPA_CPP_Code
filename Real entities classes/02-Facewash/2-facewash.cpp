//Class for Nivea Face Wash

#include <iostream>

class Dimensions{
    friend class productProps;

    private:
    float length;
    float width;
    float height;

    public:
    //default constructor
    Dimensions(float l = 0.5f, float w = 0.5f, float h = 0.5f)
    : length(l), width(w), height(h)
    {

    }
};

class Date{
    friend class productProps;

    private:
    unsigned short day;
    const char* month;
    unsigned short year;

    public:
    //parameterized default constructor
    Date(unsigned short d, const char* m, unsigned short y) 
    : day(d), month(m), year(y)
    {
        
    }
};

class productProps{
    private:
    const char* name;
    unsigned int price;
    Dimensions dimensions_of_product;
    Date date_first_available;
    const char* manufacturer;
    const char* ASIN;
    unsigned long int item_model_number;
    const char* country_of_origin;
    const char* packer;
    const char* importer;
    unsigned int weight;
    unsigned int net_quantity;
    const char* included_components;
    const char* generic_name;
    unsigned int best_seller_rank;
    float customer_review_rating;

    public:
    //default constructor
    productProps()
    :   name{"empty_product"},
        price{00},
        dimensions_of_product{0,0,0},
        date_first_available{29, "Feb", 1001},
        manufacturer{"empty_manufacturer"},
        ASIN{"empty_ASIN"},
        item_model_number{0},
        country_of_origin{"empty_origin_country"},
        packer{"empty_packer"},
        importer{"empty_importer"},
        weight{0},
        net_quantity{0},
        included_components{"empty_components"},
        generic_name{"empty_name"},
        best_seller_rank{0},
        customer_review_rating{0}
    {

    }

    //member function
    void set_product_details
    (
        const char* _name,
        unsigned int _price,
        Dimensions _dimensions_of_product,
        Date _date_first_available,
        const char* _manufacturer,
        const char* _ASIN,
        unsigned long int _item_model_number,
        const char* _country_of_origin,
        const char* _packer,
        const char* _importer,
        unsigned int _weight,
        unsigned int _net_quantity,
        const char* _included_components,
        const char* _generic_name,
        unsigned int _best_seller_rank,
        float _customer_review_rating
    );

    void show_product_details();
};

int main(){
    productProps* new_faceWash = new productProps;

    std::cout << ("Product Details of Nivea Face Wash") << std::endl;

    new_faceWash->set_product_details
    (
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
    );

    new_faceWash->show_product_details();

    return 0;
}

void productProps::set_product_details
(
    const char* _name,
    unsigned int _price,
    Dimensions _dimensions_of_product,
    Date _date_first_available,
    const char* _manufacturer,
    const char* _ASIN,
    unsigned long int _item_model_number,
    const char* _country_of_origin,
    const char* _packer,
    const char* _importer,
    unsigned int _weight,
    unsigned int _net_quantity,
    const char* _included_components,
    const char* _generic_name,
    unsigned int _best_seller_rank,
    float _customer_review_rating
)
{
    this->name = _name,
    price = _price,
    dimensions_of_product = _dimensions_of_product,
    date_first_available = _date_first_available,
    manufacturer = _manufacturer,
    ASIN = _ASIN,
    item_model_number = _item_model_number,
    country_of_origin = _country_of_origin,
    packer = _packer,
    importer = _importer,
    weight = _weight,
    net_quantity = _net_quantity,
    included_components = _included_components,
    generic_name = _generic_name,
    best_seller_rank = _best_seller_rank,
    customer_review_rating = _customer_review_rating;
}

void productProps::show_product_details(){
    printf("name                        :          %s\n", this->name);
    printf("price                       :          %d\n", this->price);
    printf("dimensions_of_product       :          %.1f x %0.1f x %.1f\n", dimensions_of_product.height, dimensions_of_product.length, dimensions_of_product.width);
    printf("date_first_available        :          %d-%s-%d\n", this->date_first_available.day, date_first_available.month, date_first_available.year);
    printf("manufacturer                :          %s\n", manufacturer);
    printf("ASIN                        :          %s\n", ASIN);
    printf("item_model_number           :          %lu\n", item_model_number);
    printf("country_of_origin           :          %s\n", country_of_origin);
    printf("packer                      :          %s\n", packer);
    printf("importer                    :          %s\n", importer);
    printf("weight                      :          %u\n", weight);
    printf("net_quantity                :          %u\n", net_quantity);
    printf("included_components         :          %s\n", included_components);
    printf("generic_name                :          %s\n", generic_name);
    printf("best_seller_rank            :          %u\n", best_seller_rank);
    printf("customer_review_rating      :          %.1f\n", customer_review_rating);
}
