#include <iostream>

class Teste {
  public:
  Teste() {}
  static void method() {
    std::cout << "estatico";
  };
};

int main() {
  Teste::method();
  Teste teste;
  teste.method();
}