#include <iostream>
#include <cstring>
#define STR_SIZE 150
using namespace std;

// class setting
class Product{
private:
    char* name;
    int price;
    int cost;
    int sales_last_years;
    int unit_profit;
    int total_money;
    int total_gain;
public:
    // n: name, p: price, c: cost, sq: sales quantity
    Product(char* n, int p, int c, int sl, int up, int tm, int tg); 
    ~Product();
    char* get_name() {return name;}
    int get_total_gain() {return total_gain;}
    void show_all();
    int is_in_front_of(const Product& produscts, int sort_condition);
};

// default constructor
Product::Product(char* n, int p, int c, int sl, int up, int tm, int tg){
  int len = strlen(n);
  name = new char[len + 1];
  strcpy(name, n);
  price = p;
  cost = c;
  sales_last_years = sl;
  unit_profit = up;
  total_money = tm;
  total_gain = tg;
}

// destructor
Product::~Product(){
    delete [] name;
}

void Product::show_all(){
    cout << name << " " << price << " " << cost << " " << sales_last_years << " " << unit_profit << " " << total_money << " " << total_gain;
    cout << endl;
}

int Product::is_in_front_of(const Product& products, int sort_condition){
    if(sort_condition == 1){
        if(price > products.price)
            return 1;
        else if(price == products.price)
            return 0;
        else
            return -1;
    }
    else if(sort_condition == 2){
        if(cost > products.cost)
            return 1;
        else if(cost == products.cost)
            return 0;
        else
            return -1;
    }
    else if(sort_condition == 3){
        if(unit_profit > products.unit_profit)
            return 1;
        else if(unit_profit == products.unit_profit)
            return 0;        
        else
            return -1;
    }
    else if(sort_condition == 4){
        if(sales_last_years > products.sales_last_years)
            return 1;
        else if(sales_last_years == products.sales_last_years)
            return 0;   
        else
            return -1;
    }
    else if(sort_condition == 5){
        if(total_money > products.total_money)
            return 1;
        else if(total_money == products.total_money){
            return 0;}   
        else
            return -1;
    }
    else{
        if(total_gain > products.total_gain)
            return 1;
        else if(total_gain == products.total_gain)
            return 0;  
        else
            return -1;
    }
}

// Define a swap function to swap two integers
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to sort the product IDs based on the given sort_condition
void sort_product_ids(Product** products, int* id_list, int product_num, int sort_condition) {
    for (int i = 0; i < product_num - 1; i++) {
        for (int j = 0; j < product_num - i - 1; j++) {
            // if (!(products[id_list[j]]->is_in_front_of(*products[id_list[j + 1]], sort_condition))) {
            //     swap(id_list[j], id_list[j + 1]);
            // }
            // else if((products[id_list[j]]->is_in_front_of(*products[id_list[j + 1]], sort_condition)) == 0){
            //     if(strcmp(products[id_list[j]]->get_name(),products[id_list[j + 1]]->get_name()) < 0){
            //         swap(id_list[j], id_list[j + 1]);
            //     }
            // }
            int comparison = products[id_list[j]]->is_in_front_of(*products[id_list[j + 1]], sort_condition);
            // cout << products[id_list[j]]->get_name() << " " << products[id_list[j+1]]->get_name() << " " <<comparison << endl;

            if (comparison < 0) {
                swap(id_list[j], id_list[j + 1]);
            }
            else if (comparison == 0) {
                if (strcmp(products[id_list[j]]->get_name(), products[id_list[j + 1]]->get_name()) > 0) {
                    cout << products[id_list[j]]->get_name() << " " << products[id_list[j + 1]]->get_name() << endl;
                    swap(id_list[j], id_list[j + 1]);
                }
            }
        }
    }
}

int main(){
    int product_num;
    cin >> product_num;
    cin.ignore(); // clear input buffer

    // create the Product object pointer
    Product** products = new Product*[product_num];
    int* id_list = new int[product_num];

    // get the input and create each object element
    for (int i = 0; i < product_num; i++) {
        char str[STR_SIZE] = {0};
        cin.getline(str, STR_SIZE);
        // cout << str << endl;

        char* name = strtok(str, ",");
        char* price_str = strtok(nullptr, " ");
        char* cost_str = strtok(nullptr, " ");
        char* sales_last_years_str = strtok(nullptr, " ");
        // str to int
        int price = atoi(price_str);
        int cost = atoi(cost_str);
        int sales_last_years = atoi(sales_last_years_str);
        int unit_profit = price - cost;
        int total_money = price * sales_last_years;
        int total_gain = unit_profit * sales_last_years;

        products[i] = new Product(name, price, cost, sales_last_years, unit_profit, total_money, total_gain);
        id_list[i] = i;
    }
    // cout << products[0]->get_name() << endl;
    // for (int i = 0; i < product_num; i++) {
    //     products[i]->show_all();
    // }   

    // get sortting condition and how many product money should we cout
    int sort_condition, choose_num;
    cin >> sort_condition >> choose_num;

    // Sort the product IDs based on the given sort_condition
    sort_product_ids(products, id_list, product_num, sort_condition);

    // Output the sorted product IDs
    // for (int i = 0; i < product_num; i++) {
    //     cout << id_list[i] << " ";
    // }
    // cout << endl;

    // Output the result
    int sum = 0;
    for (int i = 0; i < choose_num; i++) {
        sum += products[id_list[i]]->get_total_gain();
    } 
    cout << sum << endl;   

    // clean dynamically allocated memory
    for (int i = 0; i < product_num; i++) {
        delete products[i];
    }
    delete[] products;

    return 0;
}