#include <iostream>
#include <fstream>
#include <string>

class Reader{

};

class Writer{

};

class Point{
    public:
        Point() {
            std::cout << "Point constructor called." << std::endl;
            x = 10;
            y = 20;
        }
        double x;
        double y;
};

class Edge{
    public:
        Edge() {
            std::cout << "Edge constructor called." << std::endl;
        }
        Edge(const Edge& other) {
            std::cout << "Edge copy constructor called." << std::endl;
            this->start = other.start;
            this->end = other.end;
        }
        Edge& operator=(const Edge& other) {
            if (this == &other) {
                std::cout << "Edge self-assignment ignored." << std::endl;
                return *this;
            }
            std::cout << "Edge copy assignment operator called." << std::endl;
            this->start = other.start;
            this->end = other.end;
            return *this;
        }
        ~Edge()=default;
        Point start;
        Point end;
};

class Topograph{
    public:
        Topograph(double s_x, double s_y, double e_x, double e_y) {
            std::cout << "Topograph constructor called." << std::endl;
            edge.start.x = s_x;
            edge.start.y = s_y;
            edge.end.x = e_x;
            edge.end.y = e_y;
        }
        Topograph(const Topograph& other) {
            std::cout << "Topograph copy constructor called." << std::endl;
            this->edge = other.edge;
        }
        ~Topograph()=default;
        Edge edge;
};

class RouteComponent {
    public:
        RouteComponent() {
            std::cout << "RouteComponent constructor called." << std::endl;
        }
        std::string name_;
        Reader reader_;
        Writer writer_;
        bool process(){
            std::cout << "Processing " << this->name_ << "..." << std::endl;
            return true;
        }

};


int main() {
    Topograph *t = new Topograph(1.0, 2, 3, 4.0);
    Topograph *t2 = new Topograph(*t);
    
    t->edge.start.x = 100;
    t->edge.end.y = 200;

    std::cout << t->edge.start.x << std::endl;
    std::cout << t->edge.end.y << std::endl;

    std::cout << t2->edge.start.x << std::endl;
    std::cout << t2->edge.end.y << std::endl;

    t2->edge = t2->edge;
    return 0;
}