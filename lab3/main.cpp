#include "figures/point.h"
#include "figures/figures.h"

#include <iostream>

using namespace lab3;

class MainRoutine {
private:
    void eraseFigure() {
        size_t n;
        n--;
        std::cin >> n;
        if (n >= data.size()) {
            std::cout << "There's no figure with index " << n + 1 << ".\n";
            return ;
        }
        data.erase(data.begin() + n);
    }

    void pushFigure() {
        std::string type;
        std::cin >> type;
        try {
            if (type == "square") {
                Square *sq = new Square;
                std::cin >> *sq;
                data.push_back((Figure*)sq);
            } else if (type == "triangle") {
                Triangle *tr = new Triangle;
                std::cin >> *tr;
                data.push_back((Figure*)tr);
            } else if (type == "octagon") {
                Octagon *oct = new Octagon;
                std::cin >> *oct;
                data.push_back((Figure*)oct);
            } else {
                std::cout << "Unknown figure name.\n";
                return;
            }
        } catch (std::invalid_argument &e) {
            std::cout << e.what() << std::endl;
            return ;
        }
        std::cout << "Success.\n";
    }

    void wholeArea() {
        double area = 0;
        for (Figure* i : data) {
            area += static_cast<double>(*i); 
        }
        std::cout << area << std::endl;
    }

    void info() {
        std::cout << "Info: \n";
        for (int i = 0; i < data.size(); i++) {
            std::cout << (i + 1) << ":\n";
            std::cout << "  area : " << static_cast<double>(*data[i]) << "\n" <<
                         "  geometric_center : " << data[i]->geometricCenter() << "\n"; 
        }
    }

    std::vector<Figure*> data;
public:
    void start() {
        std::string command;
        std::cout << "> ";
        std::cin >> command;
        while (command != "exit") {
            if (command == "push") {
                pushFigure();
            } else if (command == "info") {
                info();
            } else if (command == "erase") {
                eraseFigure();
            } else if (command == "area") {
                wholeArea();   
            } else {
                std::cout << "Unknown command.\n";
            }
            std::cout << "> ";
            std::cin >> command;
        }
    }

    ~MainRoutine() {
        for (Figure* fig : data) {
            delete fig;
        }
    }
};

int main() {
    MainRoutine r;
    r.start();
}