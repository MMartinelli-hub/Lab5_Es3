#include <iostream>
using namespace std;

class Controller{
    public:
        virtual void on();
        virtual void off();
        virtual void set_level(int);
        virtual void show();
};

class Shape{
    private:
        int n_of_sides;
        int length_of_sides;
        int line_color;

    public:
        Shape(int n = 4, int l = 1){
            n_of_sides = n;
            length_of_sides = l;
        }

        void set_line_color(int n){
            if(n<=0 || n>9)
                n = 1;
            line_color = n;
        }

        int get_n_of_sides(){return n_of_sides;}

        int get_length_of_sides(){return length_of_sides;}

        string get_line_color(){
            if(line_color == 1){
                string tmp = "Rosso";
                return tmp;
            }
            if(line_color == 2){
                string tmp = "Verde";
                return tmp;
            }
            if(line_color == 3){
                string tmp = "Giallo";
                return tmp;
            }
            if(line_color == 4){
                string tmp = "Blu";
                return tmp;
            }
            if(line_color == 5){
                string tmp = "Arancione";
                return tmp;
            }
            if(line_color == 6){
                string tmp = "Rosa";
                return tmp;
            }
            if(line_color == 7){
                string tmp = "Viola";
                return tmp;
            }
            if(line_color == 8){
                string tmp = "Nero";
                return tmp;
            }
            if(line_color == 9){
                string tmp = "Bianco";
                return tmp;
            }
            
            string tmp = "";
            return tmp;
        }

        void color_palette(){
            cout<<"1 : Rosso"<<"\n";
            cout<<"2 : Verde"<<"\n";
            cout<<"3 : Giallo"<<"\n";
            cout<<"4 : Blu"<<"\n";
            cout<<"5 : Arancione"<<"\n";
            cout<<"6 : Rosa"<<"\n";
            cout<<"7 : Viola"<<"\n";
            cout<<"8 : Nero"<<"\n";
            cout<<"9 : Bianco"<<"\n";
        }
};

class Test_show : public Controller {
    public:

        Test_show(){
            level = 0;
            state = false;
        }

        void on(){
            state = true;
        }

        void off(){
            state = false;
        }

        void set_level(int n){
            level = n;
        }

        void show(){
            if (state)
                cout<<"State of controller: ON \n";
            else
                cout<<"State of controller: OFF \n";
            
            cout<<"CURRENT LEVEL: "<<level<<"\n";
        }

    private:
        int level;
        bool state;
};

class Test_setLevel : public Controller {
    public:

        Test_setLevel(int n = 4, int l=1){
            s = Shape(n, l);
        }

        void set_level(int n){
            s.set_line_color(n);
        }

        void show(){
            cout<<"N OF SIDES : "<<s.get_n_of_sides()<<"\n";
            cout<<"LENGTH OF EACH SIDE: "<<s.get_length_of_sides()<<"\n";
            cout<<"LINE COLOR: "<<s.get_line_color()<<"\n";
        }

    private:
        Shape s;
};


int main(){
    Test_show test1;
    Test_setLevel test2;
    test1 = Test_show();
    test2 = Test_setLevel(4, 5);
    test1.set_level(5);
    test2.set_level(4);
    test1.show();
    test2.show();

    return 0;
}
