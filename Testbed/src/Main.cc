#include <Kas.hh>

class Testbed : public kas::Application {
public:
    Testbed() {

    }

    ~Testbed() {

    }
};

kas::Application* kas::CreateApplication() {
    return new Testbed();
}