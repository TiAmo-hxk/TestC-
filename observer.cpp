#include <iostream>
#include <vector>
using namespace std;

// Subject
/*
这是一个抽象类 Subject，它定义了主题接口。主题接口包括三个方法：Attach()、Detach() 和 Notify()。
Attach() 方法用于将观察者附加到主题上，Detach() 方法用于将观察者从主题上分离，Notify() 方法用于通知所有附加的观察者。
*/
class Subject {
public:
    virtual void Attach(class Observer* observer) = 0;
    virtual void Detach(class Observer* observer) = 0;
    virtual void Notify() = 0;
};

// ConcreteSubject
class ConcreteSubject : public Subject {
private:
    vector<class Observer*> observers;
    int state;

public:
    void Attach(Observer* observer) override {
        observers.push_back(observer);
    }

    void Detach(Observer* observer) override {
        for (auto it = observers.begin(); it != observers.end(); ++it) {
            if (*it == observer) {
                observers.erase(it);
                break;
            }
        }
    }

    void Notify() override {
        for (auto observer : observers) {
            observer->Update(state);
        }
    }

    int GetState() const { return state; }
    void SetState(int value) { state = value; }
};

// Observer
class Observer {
public:
    virtual void Update(int value) = 0;
};

// ConcreteObserverA
class ConcreteObserverA : public Observer {
private:
    int state;

public:
    void Update(int value) override {
        state = value;
        cout << "ConcreteObserverA: " << state << endl;
    }
};

// ConcreteObserverB
class ConcreteObserverB : public Observer {
private:
    int state;

public:
    void Update(int value) override {
            state = value;
            cout << "ConcreteObserverB: " << state << endl;
        }
};

int main() {
    ConcreteSubject subject;

    ConcreteObserverA observerA;
    ConcreteObserverB observerB;

    subject.Attach(&observerA);
    subject.Attach(&observerB);

    subject.SetState(1);
    subject.Notify();

    subject.Detach(&observerA);

    subject.SetState(2);
    subject.Notify();

    return 0;
}

/*
在这个例子中，ConcreteSubject 是具体主题，它维护了一个观察者列表，并在状态发生改变时通知所有观察者。ConcreteObserverA 和 ConcreteObserverB 是具体观察者，它们实现了 Update() 方法来更新自己的状态。

在 main() 函数中，我们创建了一个主题和两个观察者，并将观察者附加到主题上。当主题的状态发生改变时，它会通知所有附加的观察者。

希望这个例子能够帮助您理解观察者模式。



*/