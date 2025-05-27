#include <iostream>
#include <vector>
#include <memory>
#include <string>

class LightBulb {
public:
    LightBulb(std::string location) 
        : location(location), isOn(false) {
        std::cout << "💡 " << location << " bulb installed\n";
    }

    ~LightBulb() {
        std::cout << "💡 " << location << " bulb removed\n";
    }

    void toggle() {
        isOn = !isOn;
        std::cout << location << " bulb " 
                  << (isOn ? "ON" : "OFF") << "\n";
    }

private:
    std::string location;
    bool isOn;
};

// TODO: Convert raw pointers to smart pointers
class LightSwitch {
public:
    void connectBulb(LightBulb* bulb) {
        bulbs.push_back(bulb);
    }

    void toggleAll() {
        for (auto bulb : bulbs) {
            bulb->toggle();
        }
    }

private:
    std::vector<LightBulb*> bulbs; // Should hold smart pointers
};

class SmartHome {
public:
    // TODO: Add proper memory management
    void installSwitch(LightSwitch* sw) {
        switches.push_back(sw);
    }

    void demo() {
        for (auto sw : switches) {
            sw->toggleAll();
        }
    }

private:
    std::vector<LightSwitch*> switches; // Should hold smart pointers
};

int main() {
    // TODO: Rewrite using smart pointers
    SmartHome home;

    LightSwitch* kitchenSwitch = new LightSwitch();
    kitchenSwitch->connectBulb(new LightBulb("Ceiling"));
    kitchenSwitch->connectBulb(new LightBulb("Counter"));

    LightSwitch* bedroomSwitch = new LightSwitch();
    bedroomSwitch->connectBulb(new LightBulb("Bedside"));
    bedroomSwitch->connectBulb(new LightBulb("Dresser"));

    home.installSwitch(kitchenSwitch);
    home.installSwitch(bedroomSwitch);

    home.demo();

    // Currently leaks all devices - fix this!
    return 0;
}
