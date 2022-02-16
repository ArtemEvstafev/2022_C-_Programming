#include <iostream>
#include <memory>

class BankCell {
public:
    
    int Status = 0;

    BankCell() {
        std::cout << "BankCell constructor\n";
    }
    ~BankCell() {
        std::cout << "BankCell destructor\n";
    }
    void status(){
        if (Status > 0)
            std::cout << "Opened\n";
        else
            std::cout << "Closed\n";
    }
};

class Human {
    std::string name;
public:
    Human(std::string n) : name(n) {
        std::cout << name << " constructor\n";
    }
    ~Human() {
        std::cout << name << " destructor\n";
    }
    std::string get_name() {
        return name;
    }
    void share(std::shared_ptr<BankCell> &bank) { //std::unique_ptr<BankCell> BankCell&
        bank->Status++;
        std::cout << name << " started to use BankCell\n";
    }
    void stopusing(std::shared_ptr<BankCell> &bank) {
        bank->Status--;
        std::cout << name << " stoped to use BankCell\n";
    }
};

int main()
{
    
    std::shared_ptr<BankCell> Bank = std::make_shared<BankCell>();
    Human Artem("Artem");
    Human Danil("Danil");

    Bank->status();
    Artem.share(Bank);//std::make_unique<BankCell>(Bank)
    Danil.share(Bank);
    Bank->status();
    Danil.stopusing(Bank);
    Artem.stopusing(Bank);
    Bank->status();

    return 0;
}
