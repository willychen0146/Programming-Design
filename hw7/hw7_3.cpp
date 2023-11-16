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
    void update_sell(int);
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

void Product::update_sell(int update_num){
    int price = value[0];
    int unit_profit = value[2];
    int sales_last_years = value[3];
    int total_money = value[4];
    int total_gain = value[5];
    value[3] += update_num;
    value[4] += update_num * price;
    value[5] += update_num * unit_profit;
}

int compute_result(Product **products, int product_num, int sort_condition, int choose_num){
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
    // cout << sum << endl;
    return sum;

}

int main(){
    // get total product number, how many times sales have been updated in the new year, divide the search into how many times
    int product_num, new_sell_num, how_many_search;
    cin >> product_num >> new_sell_num >> how_many_search;
    cin.ignore(); // clear input buffer

    // create the Product object pointer
    Product** products = new Product*[product_num];

    // get the input and create each object element
    for (int i = 0; i < product_num; i++) {
        char str[STR_SIZE] = {0};
        cin.getline(str, STR_SIZE);

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
    }

    // get every sales updated in the new year (start with S), if start with T, that mean search update results so far
    int reads_line = new_sell_num + how_many_search;
    int search_count = 0;
    int* search_result = new int[how_many_search];

    for (int i = 0; i < reads_line; i++){
        char str[STR_SIZE] = {0};
        cin.getline(str, STR_SIZE);

        // if contain ",", update new sales in the new year
        if(str[0] == 'S'){
            char* S = strtok(str, ",");
            char* add_product_name = strtok(nullptr, ",");
            char* add_sell_num_char = strtok(nullptr, ",");
            int add_sell_num = atoi(add_sell_num_char);

            // search the product name I want to modify
            int search_id = -1;
            for(int i = 0; i < product_num; i++){
                if(strcmp(products[i]->get_name(), add_product_name) == 0){
                    search_id = i;
                    break;
                }
            } 

            products[search_id]->update_sell(add_sell_num);
        }

        // if contain ",", update new sales in the new year
        else if(str[0] == 'T'){
            char* T = strtok(str, " ");
            char* sort_condition_char = strtok(nullptr, " ");
            char* choose_num_char = strtok(nullptr, " ");
            int sort_condition = atoi(sort_condition_char);
            int choose_num = atoi(choose_num_char);

            int result = compute_result(products, product_num, sort_condition, choose_num);
            search_result[search_count] = result;
            search_count++;
        }

        // if not both S and T, for safety -> break
        else{
            break;
        }
    }

    // output the result
    for (int i = 0; i < how_many_search; i++){
        if(i == (how_many_search - 1)){
            cout << search_result[i];
        }
        else{
            cout << search_result[i] << ",";
        }
    }
    cout << endl;
    
    // clean dynamically allocated memory
    for (int i = 0; i < product_num; i++) {
        delete products[i];
    }
    delete[] products;

    return 0;
}
