#include <iostream>
#include <string>

void sayHi();
int add(int i, int j);

struct Pet {
  Pet(const std::string &name) : name(name) {}
  void setName(const std::string &name_) { name = name_; }
  const std::string &getName() const { return name; }

  std::string name;
};
