#include <iostream>

class MyClass {
public:
  void abc() {
    doSomething();
    doAnother(1);
    doAnother(2);
    doAnother3();
    doDifferent();
  }
  void doSomething() {
    std::cout << "Doing something." << std::endl;
  }
  void doAnother(int n) {
    std::cout << "Doing another with " << n << "." << std::endl;
  }
  virtual void doAnother3() {} // virtual hook method
  void doDifferent() {
    std::cout << "Doing something different." << std::endl;
  }
};

class MySubClass : public MyClass {
public:
  void doAnother3() override {
    doAnother(3);
  }
};

int main() {
  MyClass obj1;
  obj1.abc();

  MySubClass obj2;
  obj2.abc();

  return 0;
}
