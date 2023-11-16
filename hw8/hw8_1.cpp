#include <iostream>
#include <cstring>
#define STR_SIZE 350 // define the largest cin.getline reading length
using namespace std;

// class setting
class Item {
private:
    char* name;
    int material_cost;
public:
    // n: name, mc: material cost
    Item(const char* n, int mc);
    Item(const Item& item);
    ~Item();
    const char* get_name() const;
    const int get_material_cost() const;
};

class Product{
private:
    char* name;
    int value[6]; // 0:Price, 1:Cost, 2:Unit Profit, 3:Sales until now, 4:Total Money, 5:Total Gain
    int item_count;
    // Item** item_list;
public:
    // n: name, p: price, c: cost, sq: sales quantity
    Product(const char* n, int p, int c, int sun, int up, int tm, int tg, int ic); 
    Product(const Product& product);
    ~Product();

    const char* get_name() const;
    void show_all() const;
    const int get_value(int) const;
    void update_item(const Item* item_ptr);
};

//-----------------------------------Item's member function-----------------------------------//

// constructor
Item::Item(const char* n, int mc){
    int len = strlen(n);
    name = new char[len + 1];
    strcpy(name, n);
    
    material_cost = mc;
}

// copy constructor
Item::Item(const Item& item){
    int len = strlen(item.name);
    name = new char[len + 1];
    strcpy(name, item.name);

    material_cost = item.material_cost;
}

// destructor
Item::~Item(){
    delete[] name;
}

// getter for name
const char* Item::get_name() const{
    return name;
}

// getter for material_cost
const int Item::get_material_cost() const{
    // cout << material_cost <<endl;
    return material_cost;
}

//-----------------------------------End of Item's member function-----------------------------------//

//-----------------------------------Product's member function-----------------------------------//

// constructor
Product::Product(const char* n, int p, int c, int sun, int up, int tm, int tg, int ic){
    int len = strlen(n);
    name = new char[len + 1];
    strcpy(name, n);
    
    value[0] = p;
    value[1] = c;
    value[2] = up;
    value[3] = sun;
    value[4] = tm;
    value[5] = tg;
    item_count = ic;
}

// copy constructor
Product::Product(const Product& product){
    int len = strlen(product.name);
    name = new char[len + 1];
    strcpy(name, product.name);
    
    value[0] = product.value[0];
    value[1] = product.value[1];
    value[2] = product.value[2];
    value[3] = product.value[3];
    value[4] = product.value[4];
    value[5] = product.value[5];
    item_count = product.item_count;
}

// destructor
Product::~Product(){
    delete[] name;
}

// getter for name
const char* Product::get_name() const{
    return name;
}

// show all the product's member variable
void Product::show_all() const{
    cout << name << " ";
    for(int i = 0; i < 6; i++){
        cout << value[i] << " ";
    }
    cout << endl;
}

// getter for specific variable except name
const int Product::get_value(int i) const{
    return value[i];
}

// update Cost(value[1]), Unit Profit(value[2]), Total Gain(value[5]) based on corresponding item costs
void Product::update_item(const Item* item_ptr){
    int material_cost = item_ptr->get_material_cost();
    int total_sale_num = value[3];
    value[1] += material_cost; // update Cost
    value[2] -= material_cost; // update Unit Profit
    value[5] = value[2] * total_sale_num; // update Total Gain
}

//-----------------------------------End of Product's member function-----------------------------------//

// sorting the id_list according to sort_condition, and sum the top N (N = choose_num) total gain and return the sum
int compute_result(Product** products, int product_num, int sort_condition, int choose_num){
    // if choose_num = choose_num, no need for sorting
    if (choose_num >= product_num){
        int sum = 0;
        for (int i = 0; i < product_num; i++) {
            sum += products[i]->get_value(5);
        }
        return sum;
    }

    // create id list
    int* id_list = new int[product_num];
    for(int i = 0; i < product_num; i++){
        id_list[i] = i;
    }

    // start sorting the id_list according to sort_condition
    int tmp;
    for(int i = 0;i < product_num - 1; i++){
        int max_num = 0;
        int max_id = product_num - 1;
        for(int j = product_num - 1; j >= i; j--){
            // if the compute result based on sort_condition are equal, compute by strcmp function
            if(products[id_list[j]]->get_value(sort_condition-1) == max_num){
                if(strcmp(products[id_list[j]]->get_name(),products[id_list[max_id]]->get_name()) < 0){
                    max_num = products[id_list[j]]->get_value(sort_condition - 1);
                    max_id = j;
                }
            }
            // if the compute result based on sort_condition are > max_num, recorded
            else if(products[id_list[j]]->get_value(sort_condition-1) > max_num){
                max_num = products[id_list[j]]->get_value(sort_condition - 1);
                max_id = j;
            }
        }
        // swap the id_list id based on the computed result above
        tmp = id_list[i];
        id_list[i] = id_list[max_id];
        id_list[max_id] = tmp;
    }

    // the sorting is complete, then return sum of the top N (N = choose_num) total gain
    int sum = 0;
    for(int i = 0; i < choose_num; i++){
        sum += products[id_list[i]]->get_value(5);
    }
    delete[] id_list;
    return sum;
}

int main(){
    // get total product number, how many times sales have been updated in the new year, how many times we want to search
    int total_product_num, total_item_num, relationships;
    cin >> total_product_num >> total_item_num >> relationships;
    // clear input buffer
    cin.ignore();

    // create the Product and Item object pointer
    Product** products = new Product*[total_product_num];
    Item** item = new Item*[total_item_num];

    // get the Product input and create each product element
    for (int i = 0; i < total_product_num; i++) {
        char str[STR_SIZE] = {0};
        cin.getline(str, STR_SIZE);

        char* name = strtok(str, ",");
        char* price_str = strtok(nullptr, " ");
        char* cost_str = strtok(nullptr, " ");
        char* sales_last_years_str = strtok(nullptr, " ");
        char* item_num_str = strtok(nullptr, " ");
        // str to int
        int price = atoi(price_str);
        int cost = atoi(cost_str);
        int sales_last_years = atoi(sales_last_years_str);
        int item_num = atoi(item_num_str);
        int unit_profit = price - cost;
        int total_money = price * sales_last_years;
        int total_gain = unit_profit * sales_last_years;
        
        products[i] = new Product(name, price, cost, sales_last_years, unit_profit, total_money, total_gain,
                                  item_num);
    }

    // get the Item input and create each item element
    for (int i = 0; i < total_item_num; i++) {
        char str[STR_SIZE] = {0};
        cin.getline(str, STR_SIZE);

        char* name = strtok(str, ",");
        char* material_cost_str = strtok(nullptr, " ");
        // str to int
        int material_cost = atoi(material_cost_str);

        item[i] = new Item(name, material_cost);
    }    

    // search for one item each times and update and element in product based on corresponding item costs
    for (int i = 0; i < relationships; i++) {
        char str[STR_SIZE] = {0};
        cin.getline(str, STR_SIZE);

        char* product_name = strtok(str, ",");
        char* item_name = strtok(nullptr, ",");

        for (int j = 0; j < total_product_num; j++){
            if(strcmp(products[j]->get_name(), product_name) == 0){
                for (int k = 0; k < total_item_num; k++){
                    if(strcmp(item[k]->get_name(), item_name) == 0){
                        products[j]->update_item(item[k]);
                        break;
                    }
                }
            }
        }        
    }    

    // read the condition and compute
    int sort_condition, choose_num;
    cin >> sort_condition >> choose_num;
    int result = compute_result(products, total_product_num, sort_condition, choose_num);

    // output the result
    cout << result << endl;
    
    // clean dynamically allocated memory
    for (int i = 0; i < total_product_num; i++) {
        delete products[i];
    }
    delete[] products;

    for (int i = 0; i < total_item_num; i++) {
        delete item[i];
    }
    delete[] item;

    return 0;
}
