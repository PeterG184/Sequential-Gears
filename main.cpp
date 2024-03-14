#include <iostream>
#include <string>
using namespace std;

const int FRONT_GEARS = 3;
const int REAR_GEARS = 8;

struct gear_t {
    int front_gear;
    int rear_gear;
    double ratio;
};

class Hub {
    int * gears;
    int current_gear;
    int max_gear;

    public:
        void init(int [], int);
        int shift_up();
        int shift_up(int);
        int shift_down();
        int shift_down(int);
        int get_current_gear();
        int * get_gears();
        int get_max_gear();
};

void Hub::init(int gears_p[], int gear_count) {
    gears = gears_p;
    current_gear = 1;
    max_gear = gear_count;
}

int Hub::shift_up() {
    if (current_gear != max_gear) {
        current_gear += 1;
    }
    return current_gear;
}

int Hub::shift_up(int gears) {
    while (gears > 0) {
        if (current_gear != max_gear) {
            current_gear += 1;
        }
        gears -= 1;
    }
    return current_gear;
}

int Hub::shift_down() {
    if (current_gear != 1) {
        current_gear -= 1;
    }
    return current_gear;
}

int Hub::shift_down(int gears) {
    while (gears < 0) {
        if (current_gear != 1) {
        current_gear -= 1;
        }
        gears -= 1;
    }
    return current_gear;
}

int Hub::get_current_gear() {
    return current_gear;
}

int Hub::get_max_gear() {
    return max_gear;
}

int * Hub::get_gears() {
    return gears;
}

class Drivetrain {
    Hub * front, * rear;
    int total_gears;
    double gear_step;
    double gear_ratio;
    double gear_ratio_targets[];

    public:
        void init(Hub * pFront, Hub * pRear);
        double calculate_gear_ratio();
        Hub * get_front_hub();
        Hub * get_rear_hub();
        double get_gear_ratio();
        void print_stats();
        void shift_up();
        void shift_down();
        void set_gear_step(double);
};

void Drivetrain::init(Hub* pFront, Hub * pRear) {
    front = pFront;
    rear = pRear;
}

double Drivetrain::calculate_gear_ratio() {
    gear_ratio = (double) front->get_gears()[front->get_current_gear() - 1]/(double) rear->get_gears()[rear->get_current_gear() - 1];
    return gear_ratio;
}

Hub * Drivetrain::get_front_hub() {
    return front;
}

Hub * Drivetrain::get_rear_hub() {
    return rear;
}

double Drivetrain::get_gear_ratio() {
    return gear_ratio;
}

void Drivetrain::print_stats() {
    cout << endl;
    cout << "Front Gear: " << front->get_current_gear() << endl;
    cout << "Front Gear Teeth: " << front->get_gears()[front->get_current_gear() - 1] << endl;
    cout << "Rear Gear: " << rear->get_current_gear() << endl;
    cout << "Rear Gear Teeth: " << rear->get_gears()[rear->get_current_gear() - 1] << endl;
    cout << "Gear Ratio: " << calculate_gear_ratio() << endl;
    cout << endl;
}

void Drivetrain::shift_up() {

}

void Drivetrain::shift_down() {

}

void Drivetrain::set_gear_step(double step) {
    gear_step = step;
}

int main()
{
    // Init
    int front_gears[FRONT_GEARS] = {22, 32, 44};
    int rear_gears[REAR_GEARS] = {32, 28, 24, 21, 18, 15, 13, 11};
    int * pFrontGears = front_gears;
    int * pRearGears = rear_gears;

    Hub front, rear, * pFront, * pRear;
    front.init(pFrontGears, FRONT_GEARS);
    rear.init(pRearGears, REAR_GEARS);
    pFront = &front;
    pRear = &rear;

    Drivetrain drv;
    drv.init(pFront, pRear);

    // Testing
    drv.print_stats();
}

/* TODO:
*   Add functionality to calculate the next gear to increase to based on a percentage increase in gear ratio
*   Create overload functions for shift_up and shift_down to accept a number of gears to increase/decrease by DONE
*   Add some sort of waiting period between shifting gears up and down to account for the chain moving
*   Add a statistic output function to print all statistics about the bike DONE
*   Create function to control shifting from the drivetrain class to interact with the hubs. DONE
*/
