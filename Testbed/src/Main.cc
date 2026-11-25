#include <Kas.hh>

class TestLayer : public kas::Layer {
public:
    TestLayer()
        : Layer("Test")
    {
    }

    void on_update() override {
        //KAS_INFO("TestLayer::on_update");
    }

    void on_event(kas::Event& event) override {
        KAS_INFO(event);
    }
};

class Testbed : public kas::Application {
public:
    Testbed() {
        push_layer(new TestLayer());
    }

    ~Testbed() {

    }
};

kas::Application* kas::CreateApplication() {
    return new Testbed();
}