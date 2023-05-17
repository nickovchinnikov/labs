#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <filesystem>

using namespace std;

namespace fs = std::filesystem;

class Customer  {
public:
    string id;
    string genre;
    int age;
    int annual_income;
    int spending_score;

    Customer(string id, string genre, int age, int annual_income, int spending_score) :
        id(id), genre(genre), age(age), annual_income(annual_income), spending_score(spending_score) {}
};

void setup() {
    // Получаем путь к текущему каталогу
    fs::path currentDir = fs::current_path();

    // Выводим список всех файлов в текущем каталоге
    for (const auto& entry : fs::directory_iterator(currentDir)) {
        if (fs::is_regular_file(entry)) {
            std::cout << entry.path().filename() << std::endl;
        }
    }

    // Создаем новый каталог
    fs::path newDir = currentDir / "new_directory";
    fs::create_directory(newDir);

    // Копируем файл в новый каталог
    fs::path sourceFile = currentDir / "Mall_Customers.csv";
    fs::path destinationFile = newDir / "Mall_Customers.csv";

    fs::copy_file(sourceFile, destinationFile);

    // Удаляем файл из текущего каталога
    fs::remove(sourceFile);

    std::cout << "Действия выполнены." << std::endl;
}

vector<string> splitString(const string& line, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(line);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    setup();

    ifstream file;
    file.open("./data/Mall_Customers.csv");
    string line;

    getline(file, line);

    vector<Customer> customers;

    while (getline(file, line)) {
        vector<string> columns = splitString(line, ',');

        customers.push_back(Customer(
            columns[0], columns[1], stoi(columns[2]), stoi(columns[3]), stoi(columns[4])
        ));
    }


    // Вывести на экран число пользователей старше 40 лет
    // вывести средний рейтинг трат для мужчин и женщин
    int customers_older_than_40_years = 0;

    int count_men = 0;
    int spending_score_men = 0;

    int count_women = 0;
    int spending_score_women = 0;

    vector<Customer> customers_womans_score_lt_50_and_income_mt_75;

    for (Customer customer : customers) {
        if (customer.age > 40) {
            customers_older_than_40_years++;
        }
        if (customer.genre == "Male") {
            ++count_men;
            spending_score_men += customer.spending_score;
        }
        if (customer.genre == "Female") {
            ++count_women;
            spending_score_women += customer.spending_score;

            if (customer.spending_score < 50 && customer.annual_income > 75) {
                customers_womans_score_lt_50_and_income_mt_75.push_back(customer);
            }
        }
    }

    float average_spending_score_men = (float)spending_score_men / count_men;
    float average_spending_score_women = (float)spending_score_women / count_women;

    cout << "Число пользователей старше 40 лет: " << customers_older_than_40_years << endl;

    printf("Средний рейтинг трат мужчин: %.1f\n", average_spending_score_men);
    printf("Средний рейтинг трат женщин: %.1f\n", average_spending_score_women);
    
    // Вывести выбранных женщин в новый файл
    std::ofstream outputFile("output.csv");

    if (!outputFile) {
        cout << "Error creating file." << std::endl;
        return 1;
    }

    outputFile << "CustomerID,Genre,Age,Annual Income (k$),Spending Score (1-100)" << std::endl;

    string sep = " ";
    for (const auto& row : customers_womans_score_lt_50_and_income_mt_75) {
        outputFile << row.id << sep
            << row.genre << sep
            << row.age << sep
            << row.annual_income << sep
            << row.spending_score << std::endl;
    }

    outputFile.close();
    cout << "Файл с выборкой заказчиков создан! " << std::endl;
    return 0;
}
