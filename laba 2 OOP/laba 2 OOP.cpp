// laba 2 OOP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <cstdio>
#include <cstdlib>



using namespace std;
//Part 1

class Line {

    int length;

public:
    int brush_size;

    Line() {
        printf("Line()\n");
        length = 0;
        brush_size = 1;
    }
    Line(int length) {
        printf("Line(int length)\n");
        this->length = length;
        brush_size = 1;
    }
    Line(int length, int br) {
        printf("Line(int length, int br)\n");
        this->length = length;
        brush_size = br;
    }
    Line(const Line& l) {
        printf("Line(const Line& l)\n");
        this->length = l.length;
        this->brush_size = l.brush_size;
    }
    ~Line() {
        printf("~Line()\n");
        printf("Length = %d, Brush Size = %d\n", length, brush_size);
    }
    void pull_out() {
        printf("Line::void pull_out()\n");
        printf("Length = %d, Brush Size = %d\n", length, brush_size);
    }
    void set_length(int dl);

   

};
//Part 2
class Car {
private:
    int max_speed;
protected:
    int price;
public:
    Car() {
        printf("Car()\n");
        max_speed = 50;
        price = 100'000;

    }
    Car(int max_speed) {
        printf("Car(int max_speed)\n");
        this->max_speed = max_speed;
    }
    Car(int max_speed, int price) : Car(max_speed) {
        printf("Car(int max_speed, int price)\n");
        this->price = price;
    }
    Car(const Car& c) {
        printf("Car(const Car& c)\n");
        max_speed = c.max_speed;
        price = c.price;
    }
    virtual void demonstrate() {
        printf("Car::void demonstrate()\n");
        printf("Maximum speed: %d, price: %d\n", max_speed, price);

    }
    virtual ~Car() {
        printf("~Car()\n");
        printf("Maximum speed: %d, price: %d\n", max_speed, price);
    }

};
void Line::set_length(int dl) {
    printf("Line::void set_length(int dl)\n");
    length = dl;
    printf("Length = %d\n", length);
}


class Truck : public Car {
    int power_traction;
public:
    Truck() : Car() {
        printf("Truck()\n");
        power_traction = 1;
    }
    Truck(int speed, int price, int power_traction) : Car(speed) {
        printf("Truck(int speed, int price, int power_traction)\n");
        //this->speed = speed - Ошибка. Дочерний класс не может использовать свойства private. Поэтому делегируем в конструктор с параметром базового класса
        this->price = price;
        this->power_traction = power_traction;
    }
    Truck(const Truck& t) :Car(t) {
        printf("Car(const Truck& t)\n");
        this->power_traction = t.power_traction;
    }
    ~Truck() {
        printf("~Truck()\n");
        printf("Power Traction is %d\n", power_traction);
    }
    virtual void demonstrate() {
        printf("Truck::void demonstrate()\n");
        Car::demonstrate();
        printf("Power Traction is %d\n", power_traction);
    };
};



    int main() {
        {
            //part 1
            printf("Static objects: \n");
            {
                Line ls1;
                Line ls2(32);
                Line ls3(21, 4);
                Line ls4(ls3);
                //ls2.length = 77 - Ошибка. Нелья обратиться к length напрямую , так как это поле не public
                ls4.set_length(77);
                ls2.brush_size = 13;
                int ls1_br = ls1.brush_size;
                int ls2_br = ls2.brush_size;
                int ls3_br = ls3.brush_size;
                int ls4_br = ls4.brush_size;

                printf("Brush sizes variables from ls1_br to ls4_br: %d, %d, %d, %d\n", ls1_br, ls2_br, ls3_br, ls4_br);
                printf("\n Method calls:\n");
                ls1.pull_out();
                ls2.pull_out();
                ls3.pull_out();
                ls4.pull_out();
            }

            printf("\n\n\nDynamic objects:\n");
            Line* ld1 = new Line;
            Line* ld2 = new Line(6);
            Line* ld3 = new Line(17, 4);
            Line* ld4 = new Line(*ld3);
            //ld3->length = 43 - Ошибка. Нелья обратиться к length напрямую , так как это поле не public
            ld3->set_length(43);
            ld1->brush_size = 6;
            int ld1_br = ld1->brush_size;
            int ld2_br = ld2->brush_size;
            int ld3_br = ld3->brush_size;
            int ld4_br = ld4->brush_size;

            printf("Brush sizes variables from ls1_br to ls4_br: %d, %d, %d, %d\n", ld1_br, ld2_br, ld3_br, ld4_br);
            printf("\n Method calls:\n");
            ld1->pull_out();
            ld2->pull_out();
            ld3->pull_out();
            ld4->pull_out();
            delete ld1;
            delete ld2;
            delete ld3;
            delete ld4;
        }
        printf("-------------------------------------------------------------------------------------------------\n");


        //  part 2
        Truck* t1 = new Truck;
        t1->demonstrate();
        Car* t2 = new Truck(100, 100'000, 56);
        t2->demonstrate();



    }


