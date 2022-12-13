#include <iostream>
#include <vector>
using namespace std;

struct data
{
public:
    int year;
    int month;
    int day;
    data()
    {
        this->year = 2000;
        this->month = 12;
        this->day = 1;
    }
    data(int y, int m, int d)
    {
        this->year = y;
        this->month = m;
        this->day = d;
    }
    bool operator==(data d)
    {
        return (this->year == d.year && this->month == d.month && this->day == d.day);
    }
    friend istream& operator>>(istream& stream, data& dat)
    {
        int y, m, d;
        char c;
        cin >> y >> c >> m >> c >> d;
        dat.year = y;
        dat.month = m;
        dat.day = d;
        return stream;
    }
};

struct person
{
public:
    data birth;
    string first_name;
    string second_name;
    string email;
    bool operator==(person d)
    {
        return (this->birth == d.birth && this->first_name == d.first_name && this->second_name == d.second_name && this->email == d.email);
    }
    friend istream& operator>>(istream& stream, person& p)
    {
        data birth;
        string first_name;
        string second_name;
        string email;

        cin >> birth >> first_name >> second_name >> email;
        p.birth = birth;
        p.first_name = first_name;
        p.second_name = second_name;
        p.email = email;
        return stream;
    }
    friend ostream& operator<<(ostream& stream, const person& p)
    {
        cout << p.birth.year << " " << p.birth.month << " " << p.birth.day << " " << p.first_name << " " << p.second_name << " " << p.email << endl;
        return stream;
    }
};

//количество людей с днями рождениями в каждом месяце
int main(int argc, const char * argv[])
{
    vector <vector<person>> base_month(13);
    int k = 0;
    cout << "сколько полей хотите добавить?" << endl;
    cin >> k;
    cout << "Введите дату рождения, имя, фамилию и почту" << endl;
    
    //вот здесь написать обработку исключений(месяц от 1 до 12)
    
        for (int i = 0; i < k; ++i)
        {
            person p;
            cin >> p;
            try
            {
                if (p.birth.month < 1 || p.birth.month > 12)
                {
                    throw p;
                }
                else
                {
                    base_month[p.birth.month].push_back(p);
                }
                
            }
            catch (person pers)
            {
                cout << pers;
                cout << "Bad month. Month must be from 1 to 12" << endl;
            }
        }
    
    
    
        for (int i = 0; i < 13; ++i)
        {
            cout << "Месяц " << i << endl;
            for (int j = 0; j < base_month[i].size(); ++j)
            {
                cout << base_month[i][j];
            }
        }
        
    
    
    return 0;
}
