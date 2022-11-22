#include <iostream>

class Character
{
public:
    Character(double xp, double x, double y, double speedx,
    double speedy)
    {
        xp = xp;
        x = x;
        y = y;
        speedx = speedx;
        speedy = speedy;
    }
    virtual ~Character()
    {
        std::cout << "удаление персонажа" << std::endl;
    }
    virtual void print()
    {
        std::cout << "вывод персонажа на экран" << std::endl;
    }
    virtual void move()
    {
        std::cout << "движение" << std::endl;
    }
    
protected:
    double xp;
    double x;
    double y;
    double speedx;
    double speedy;
};

class Player : protected Character
{
public:
    Player(double xp, double x, double y, double speedx,
    double speedy, double IsJump, double JumpPower, std::string attacks[10], std::string weapons[100], std::string friends[100]) : Character(xp, x, y, speedx, speedy)
    {
        IsJump = IsJump;
        JumpPower = JumpPower;
        attacks = attacks;
        weapons = weapons;
        friends = friends;
    }
    
    virtual ~Player()
    {
        std::cout << "удаление player'а" << std::endl;
    }
    virtual void print()
    {
        std::cout << "вывод player'а на экран" << std::endl;
    }
    void Jump()
    {
        this->y += this->JumpPower;
    }
    virtual void move()
    {
        std::cout << "движение player'а" << std::endl;
    }
    void attack()
    {
        std::cout << "атака player'а" << std::endl;
    }
    void MakeFriend()
    {
        std::cout << "player нашел друга" << std::endl;
    }
    void LoseFriend()
    {
        std::cout << "player потерял друга" << std::endl;
    }
    
protected:
    double IsJump;
    double JumpPower;
    std::string attacks[10];
    std::string weapons[100];
    std::string friends[100];
};

class Monster : protected Character
{
public:
    Monster(double xp, double x, double y, double speedx,
    double speedy, std::string attacks[10]) : Character(xp, x, y, speedx, speedy)
    {
        attacks = attacks;
    }
    
    virtual ~Monster()
    {
        std::cout << "удаление монстра" << std::endl;
    }
    virtual void print()
    {
        std::cout << "вывод монстра на экран" << std::endl;
    }
    virtual void move()
    {
        
    }
    virtual void attack()
    {
        
    }
    
protected:
    std::string attacks[10];
};

class Gul : protected Monster
{
public:
    Gul(double xp, double x, double y, double speedx,
        double speedy, std::string attacks[10]) : Monster(xp, x, y, speedx, speedy, attacks){};
    
    virtual ~Gul()
    {
        std::cout << "удаление Гуля" << std::endl;
    }
    virtual void print()
    {
        std::cout << "вывод Гуля на экран" << std::endl;
    }
    virtual void move()
    {
        std::cout << "Гуль двигается" << std::endl;
    }
    virtual void attack()
    {
        std::cout << "Гуль атакует одной из своих атак" << std::endl;
    }
};

class Vampire : protected Monster
{
public:
    Vampire(double xp, double x, double y, double speedx,
    double speedy, std::string attacks[10], std::string frases[10], std::string weapons[100]) : Monster(xp, x, y, speedx, speedy, attacks)
    {
        frases = frases;
        weapons = weapons;
    }
    
    virtual ~Vampire()
    {
        std::cout << "удаление вампира" << std::endl;
    }
    virtual void print()
    {
        std::cout << "вывод вампира на экран" << std::endl;
    }
    virtual void move()
    {
        std::cout << "вампир двигается" << std::endl;
    }
    virtual void attack()
    {
        std::cout << "вампир атакует одной из своих атак" << std::endl;
    }
    void talk()
    {
        std::cout << "вампир говорит" << std::endl;
    }
protected:
    std::string frases[100];
    std::string weapons[100];
};

class Boss : protected Monster
{
public:
    Boss(double xp, double x, double y, double speedx,
    double speedy, std::string attacks[10], std::string fases[3]) : Monster(xp, x, y, speedx, speedy, attacks)
    {
        fases = fases;
    }
    
    virtual ~Boss()
    {
        std::cout << "удаление босса" << std::endl;
    }
    virtual void print()
    {
        std::cout << "вывод босса на экран" << std::endl;
    }
    virtual void move()
    {
        std::cout << "босс двигается" << std::endl;
    }
    virtual void attack()
    {
        std::cout << "босс атакует одной из своих атак" << std::endl;
    }
    virtual void fase()
    {
        std::cout << "смена фазы босса" << std::endl;
    }
    
protected:
    std::string fases[3];
};


class Wolf : protected Boss
{
public:
    Wolf(double xp, double x, double y, double speedx,
    double speedy, std::string attacks[10], std::string fases[3]) : Boss(xp, x, y, speedx, speedy, attacks, fases)
    {
    }
    
    virtual ~Wolf()
    {
        std::cout << "удаление босса волка" << std::endl;
    }
    virtual void print()
    {
        std::cout << "вывод босса волка на экран" << std::endl;
    }
    virtual void move()
    {
        std::cout << "босс волк двигается" << std::endl;
    }
    virtual void attack()
    {
        std::cout << "босс волк атакует одной из своих атак" << std::endl;
    }
    virtual void fase()
    {
        std::cout << "смена фазы босса волка" << std::endl;
    }
    
protected:
    std::string fases[3];
};

int main(int argc, const char * argv[])
{
    std::string s[10] = {"12"};
    std::string s2[3] = {"12"};
    Wolf wolf(1, 2, 3, 4, 5, s, s2);
    wolf.print();
    return 0;
}
