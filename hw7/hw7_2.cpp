#include <iostream>
#include <cstring>
#define STR_SIZE 150
using namespace std;

// class setting
class Product{
private:
    char* name;
    // int price;
    // int cost;
    // int sales_last_years;
    // int unit_profit;
    // int total_money;
    // int total_gain;
    int value[6];
public:
    // n: name, p: price, c: cost, sq: sales quantity
    Product(char* n, int p, int c, int sl, int up, int tm, int tg); 
    ~Product();
    char* get_name();
    void show_all();
    int get_value(int);
    // bool isInFrontOf(const Product& prod, int criterion);
};

// default constructor
Product::Product(char* n, int p, int c, int sl, int up, int tm, int tg){
  int len = strlen(n);
  name = new char[len + 1];
  strcpy(name, n);
//   price = p;
//   cost = c;
//   sales_last_years = sl;
//   unit_profit = up;
//   total_money = tm;
//   total_gain = tg;
    
    value[0] = p;
    value[1] = c;
    value[2] = up;
    value[3] = sl;
    value[4] = tm;
    value[5] = tg;
    
}

// destructor
Product::~Product(){
    delete [] name;
}

char* Product::get_name(){
    return name;
}

void Product::show_all(){
    cout << name << " ";
    for (int i = 0; i < 6; i++) {
        cout << value[i] << " ";
    }
    cout << endl;
}
int Product::get_value(int i){
    return value[i];
}


void compute_result(Product **products, int product_num, int sort_condition, int choose_num){
    int id_list[product_num];
    for(int i = 0; i < product_num; i++){
        id_list[i] = i;
    }
    int max_num;
    int max_id;
    int tmp;
    // for(int i=0;i<product_num;i++){
    //     cout<<id_list[i]<<" ";
    // }
    // cout<<endl;
    for(int i = 0;i < product_num - 1; i++){
        max_num = 0;
        max_id = product_num - 1;
        // cout<<"value"<<products[id_list[i]]->get_value(sort_condition-1)<<endl;
        for(int j = product_num - 1; j >= i; j--){
            if(products[id_list[j]]->get_value(sort_condition-1) == max_num){
                if(strcmp(products[id_list[j]]->get_name(),products[id_list[max_id]]->get_name()) < 0){
                    max_num = products[id_list[j]]->get_value(sort_condition - 1);
                    max_id = j;
                }
            }
            else if(products[id_list[j]]->get_value(sort_condition-1) > max_num){
                max_num = products[id_list[j]]->get_value(sort_condition - 1);
                max_id = j;
                // cout<<"greater"<<max_num<<endl;

            }
        }
        // cout<<"swap"<<id_list[i]<<id_list[max_id]<<endl;

        tmp = id_list[i];
        id_list[i] = id_list[max_id];
        id_list[max_id] = tmp;
    }
    // for(int i=0;i<product_num;i++){
    //     cout<<id_list[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<product_num;i++){
    //     cout<<products[id_list[i]]->get_name()<<" ";
    // }
    // cout<<endl;
    int sum = 0;
    for(int i = 0;i < choose_num; i++){
        sum += products[id_list[i]]->get_value(5);
    }
    // for(int i=product_num-1;i>product_num-1-choose_num;i--){
    //     sum += products[id_list[i]]->get_value(5);
    // }
    cout << sum << endl;

}

int main(){
    // int sort_condition, choose_num;
    int product_num = 0;
    Product** products = nullptr;
    char str[STR_SIZE] = {0};

    while (cin.getline(str, STR_SIZE)) {
        if (str[0] == '\0' || strchr(str, ',') == nullptr) {
            // If the line is empty or doesn't contain a comma, stop reading input lines.
            break;
        }

        char* name = strtok(str, ",");
        char* price_str = strtok(nullptr, " ");
        char* cost_str = strtok(nullptr, " ");
        char* sales_last_years_str = strtok(nullptr, " ");

        int price = atoi(price_str);
        int cost = atoi(cost_str);
        int sales_last_years = atoi(sales_last_years_str);
        int unit_profit = price - cost;
        int total_money = price * sales_last_years;
        int total_gain = unit_profit * sales_last_years;
        Product* product = new Product(name, price, cost, sales_last_years, unit_profit, total_money, total_gain);
        
        if (product_num == 0) {
            products = new Product*[1];
        } 
        else {
            Product** temp = new Product*[product_num + 1];
            for (int i = 0; i < product_num; i++) {
                temp[i] = products[i];
            }
            delete[] products;
            products = temp;
        }

        products[product_num] = product;
        product_num++;
    }
    // for (int i = 0; i < product_num; i++) {
    //     products[i]->show_all();
    // }
    // cout << "test" << endl;

    // cout<<strcmp(products[0]->get_name(),products[1]->get_name())<<endl;
    // get sortting condition and how many product money should we cout

    char* sort_condition_char = strtok(str, " ");
    char* choose_num_char = strtok(nullptr, " ");
    // cout << sort_condition_char << " " << choose_num_char << endl;
    int sort_condition = atoi(sort_condition_char);
    int choose_num = atoi(choose_num_char);
    // cout << product_num << endl;
    compute_result(products, product_num, sort_condition, choose_num);

    // clean dynamically allocated memory
    for (int i = 0; i < product_num; i++) {
        delete products[i];
    }
    delete[] products;

    return 0;
}
