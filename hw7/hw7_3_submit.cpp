#include <iostream>
#include <cstring>
#define STR_SIZE 150 // define the largest cin.getline reading length
using namespace std;

// class setting
class Product{
private:
    char* name;
    int value[6]; // 0:Price, 1:Cost, 2:Unit Profit, 3:Sales until now, 4:Total Money, 5:Total Gain
public:
    // n: name, p: price, c: cost, sq: sales quantity
    Product(char* n, int p, int c, int sun, int up, int tm, int tg); 
    ~Product();

    char* get_name();
    void show_all();
    int get_value(int);
    void update_sells(int);
};

// default constructor
Product::Product(char* n, int p, int c, int sun, int up, int tm, int tg){
    int len = strlen(n);
    name = new char[len + 1];
    strcpy(name, n);
    
    value[0] = p;
    value[1] = c;
    value[2] = up;
    value[3] = sun;
    value[4] = tm;
    value[5] = tg;
}

// destructor
Product::~Product(){
    delete[] name;
}

// getter for name
char* Product::get_name(){
    return name;
}

// show all the product's member variable
void Product::show_all(){
    cout << name << " ";
    for(int i = 0; i < 6; i++){
        cout << value[i] << " ";
    }
    cout << endl;
}

// getter for specific variable except name
int Product::get_value(int i){
    return value[i];
}

// update the sales_until_now, total_money and total_gain, according to update_num
void Product::update_sells(int update_num){
    int price = value[0];
    int unit_profit = value[2];
    value[3] += update_num; // update the sales_until_now
    value[4] += update_num * price; // update the total_money
    value[5] += update_num * unit_profit; // update the total_gain
}

// sorting the id_list according to sort_condition, and sum the top N (N = choose_num) total gain and return the sum
int compute_result(Product** products, int product_num, int sort_condition, int choose_num){
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
    for(int i = 0;i < choose_num; i++){
        sum += products[id_list[i]]->get_value(5);
    }
    delete[] id_list;
    return sum;
}

int main(){
    // get total product number, how many times sales have been updated in the new year, how many times we want to search
    int product_num, new_sell_num, how_many_search;
    cin >> product_num >> new_sell_num >> how_many_search;
    // clear input buffer
    cin.ignore();

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

    // get every sales updated in the new year (start with S), if start with T, that mean search the results so far
    int total_line = new_sell_num + how_many_search;
    int search_count = 0;
    int* search_result = new int[how_many_search];

    // loop and cin.getline based on there have how many line waited to be read
    for (int i = 0; i < total_line; i++){
        char str[STR_SIZE] = {0};
        cin.getline(str, STR_SIZE);

        // if str start with "S", update new sales in the new year
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

            products[search_id]->update_sells(add_sell_num);
        }

        // if str start with "T", compute the result until now and record the search_count
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

        // if str doesn't start with both "S" and "T", for safety -> break
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
    delete[] search_result;

    return 0;
}
