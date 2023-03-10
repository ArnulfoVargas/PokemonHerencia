// Pokemon.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>

class Pokemon
{
public:
    //Constructor generico
    Pokemon()
    {
        this->name = "Eevee";
        this->type = "Normal";
        this->color = "Brown";
        this->attack = 30.f;
        this->health = 120;
    }
    //Constructor Especifico
    Pokemon(std::string name, std::string type, std::string color, float attack, int health)
    {
        this->name = name;
        this->type = type;
        this->color = color;
        this->attack = attack;
        this->health = health;
    }
protected:
    //Atributos
    std::string name = "";
    std::string type = "";
    std::string color = "";
    float attack{0.f};
    int health{0};
public:
    //Getters
    std::string GetName()
    {
        return this->name;
    }
    std::string GetType()
    {
        return this->type;
    }
    std::string GetColor()
    {
        return this->color;
    }
    int GetHealth()
    {
        return this->health;
    }
    float GetAttack()
    {
        return this->attack;
    }
    //setters
    void SetName(std::string name)
    {
        this->name = name;
    }
    void SetType(std::string type)
    {
        this->type = type;
    }
    void SetColor(std::string color)
    {
        this->color = color;
    }
    void SetAttack(float attack)
    {
        this->attack = attack;
    }
    void SetHealth(int health)
    {
        this->health = health;
    }
    //Metodos
    void ShowStats()
    {
        std::cout << "Pokemon Name: " << this->name << std::endl <<
            "Type: " << this->type << std::endl <<
            "Color: " << this->color << std::endl <<
            "Health: " << this->health << std::endl <<
            "Attack: " << this->attack << std::endl;
    }
    void Evolve(std::string newName, std::string newColor, bool changeType = false, std::string typeToChange = "")
    {
        this->name = newName;
        this->color = newColor;
        this->attack = this->attack * 1.3f;

        if (!changeType) return;

        this->type = typeToChange;
    }
    void Heal(float healPoints = 50.f)
    {
        std::cout << "Your " << this->name << " went from " << this->health << " health points to: "
            << this->health + healPoints << " health points" << std::endl;

        this->health += healPoints;
    }
    //Destructor
    ~Pokemon()
    {
        std::cout << "The Pokemon " << name << " of type " << type << " has been deleted" << std::endl;
    }
};

class Fire : public Pokemon {
public:
    //Contructores
    Fire() : Pokemon() {
        this->name = "Charmander";
        this->type = "Fire";
        this->color = "Orange";
        this->attack = 45.f;
        this->health = 110;
        this->fuel = 100;
        this->temperature = 234;
    }

    Fire(std::string name, std::string color, float attack, int health, int temperature, int fuel, std::string type = "") : Pokemon(name, type, color, attack, health) {

        this->type = "Fire";
        this->name = name;
        this->color = color;
        this->attack = attack;
        this->health = health;
        this->temperature = temperature;
        this->fuel = fuel;
    }
private:
    //Propiedades
    int temperature{0};
    int fuel{0};

public:
    //Getters
    int GetTemperature() {
        return this->temperature;
    }
    int GetFuel() {
        return this->fuel;
    }
    //Setters
    void SetTemperature(int temperature) {
        this->temperature = temperature;
    }
    void SetFuel(int fuel) {
        this->fuel = fuel;
    }
    //Metodos
    void HeatTheSoup() {
        std::cout << name << " heated the soup" << std::endl;
        temperature += 5;
        fuel -= 5;
    }
    void ShowStats() {
        Pokemon::ShowStats();
        std::cout << "Temperature: " << temperature << std::endl <<
            "Fuel: " << fuel << std::endl;
    }
};

class Water : public Pokemon{
public:
    //Constructores
    Water() : Pokemon(){
        this->name = "Squirtle";
        this->type = "Water";
        this->color = "Blue";
        this->attack = 35.f;
        this->health = 100.f;
        this->oxygen = 100;
        this->swimSpeed = 50;
    }
    Water(std::string name, std::string color, float attack, int health, int oxygen, int swimSpeed, std::string type = "") : Pokemon(name, type, color, attack, health) {
        this->type = "Water";
        this->name = name;
        this->color = color;
        this->attack = attack;
        this->health = health;
        this->oxygen = oxygen;
        this->swimSpeed = swimSpeed;
    }
private:
    //Propiedades
    int oxygen = 0;
    int swimSpeed = 0;
public:
    //Getters
    int GetOxygen() {
        return this->oxygen;
    }
    int GetSwimSpeed() {
        return this->swimSpeed;
    }
    //Setters
    void SetOxygen(float oxygen) {
        this->oxygen = oxygen;
    }
    void SetSwimSpeed(int swimSpeed) {
        this->swimSpeed = swimSpeed;
    }
    //Metodos
    void Swim() {
        std::cout << name << " is swiming" << std::endl;
        oxygen -= 5;
        swimSpeed += 5;
    }
    void ShowStats() {
        Pokemon::ShowStats();
        std::cout << "Oxygen: " << oxygen << std::endl <<
            "Swim Speed: " << swimSpeed << std::endl;
    }
};

class Plant : public Pokemon {
public:
    //Constructores
    Plant() : Pokemon() {
        this->name = "Bulbasaur";
        this->type = "Plant";
        this->color = "Green";
        this->attack = 48.f;
        this->health = 130;
    }
    Plant(std::string name, std::string color, float attack, int health, int stamina, int walkSpeed, std::string type = "") : Pokemon(name, type, color, attack, health) {
        this->type = "Plant";
        this->name = name;
        this->color = color;
        this->attack = attack;
        this->health = health;
        this->stamina = stamina;
        this->walkSpeed = walkSpeed;
    }
private:
    //Propiedades
    int stamina = 0;
    int walkSpeed = 0;
public:
    //Getters
    int GetStamina() {
        return stamina;
    }
    int GetWalkSpeed() {
        return walkSpeed;
    }
    //Setters
    void SetStamina(int stamina) {
        this->stamina = stamina;
    }
    void SetWalkSpeed(int walkSpeed) {
        this->walkSpeed = walkSpeed;
    }
    //Metodos
    void Walk() {
        std::cout << name << " is walking" << std::endl;
        walkSpeed += 5;
        stamina -= 5;
    }
    void ShowStats() {
        Pokemon::ShowStats();
        std::cout << "Walk Speed: " << walkSpeed << std::endl <<
            "Stamina: " << stamina << std::endl;
    }
};

class Electric : public Pokemon{
public:
    //Constructores
    Electric() : Pokemon() {
        this->name = "Pikachu";
        this->type = "Electric";
        this->color = "Yellow";
        this->attack = 30.f;
        this->health = 120;
        this->electricResistance = 5;
        this->voltage = 100;
    }
    Electric(std::string name, std::string color, float attack, int health, int voltage, int electricResistance, std::string type = "") : Pokemon(name, type, color, attack, health) {
        this->type = "Electric";
        this->name = name;
        this->color = color;
        this->attack = attack;
        this->health = health;
        this->voltage = voltage;
        this->electricResistance = electricResistance;
    }
private:
    //Propiedades
    int electricResistance = 0;
    int voltage = 0;
public:
    //Getters
    int GetVoltage() {
        return voltage;
    }
    int GetElectricResistance() {
        return electricResistance;
    }
    //Setters
    void SetVoltage(int voltage) {
        this->voltage = voltage;
    }
    void SetElectricResistance(int electricResistance) {
        this->electricResistance = electricResistance;
    }
    //Metodos
    void TurnOnTheLight() {
        std::cout << name << " turned on the lights" << std::endl;
        voltage -= 5;
        electricResistance += 5;
    }
    void TurnOffTheLight() {
        std::cout << name << " turned off the lights" << std::endl;
        voltage += 5;
        electricResistance -= 5;
    }
    void ShowStats() {
        Pokemon::ShowStats();
        std::cout << "Voltage: " << voltage << std::endl <<
            "Electric Resistance: " << electricResistance << std::endl;
    }
};

int main()
{
    Electric pikachu("Pikachu", "Yellow", 25, 135, 90, 4);
    pikachu.ShowStats();
    std::cout << std::endl;

    pikachu.Heal();
    std::cout << std::endl;

    pikachu.TurnOnTheLight();
    pikachu.ShowStats();
    std::cout << std::endl;

    Fire chamander("Charmander", "Orange", 45, 110, 200, 100);
    chamander.ShowStats();
    std::cout << std::endl;

    chamander.HeatTheSoup();
    chamander.ShowStats();
    std::cout << std::endl;

    chamander.Evolve("Charmeleon", "Red");
    chamander.ShowStats();
    std::cout << std::endl;

    Water squirtle("Squirtle", "Blue", 55, 150, 100, 40);
    squirtle.ShowStats();
    std::cout << std::endl;

    squirtle.Swim();
    squirtle.ShowStats();
    std::cout << std::endl;

    Plant* bulbasaur = new Plant("Bulbasaur", "Green", 25, 125, 60, 10);
    bulbasaur->ShowStats();
    std::cout << std::endl;

    bulbasaur->Walk();
    bulbasaur->ShowStats();
    std::cout << std::endl;

    bulbasaur->Evolve("Ivysaur", "Green", true, "Plant/Poison");
    bulbasaur->ShowStats();
    std::cout << std::endl;

    bulbasaur->Heal(25);
    std::cout << std::endl;

    bulbasaur->ShowStats();
    std::cout << std::endl;

    getchar();

    delete(bulbasaur);
}