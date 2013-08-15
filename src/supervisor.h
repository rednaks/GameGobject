#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include "object.h"
#include <vector>

class Object;

class Supervisor {

public:
  Supervisor();
  ~Supervisor();
  void update();
  void add(Object *);
  void erase(Object *);
  

private:
  std::vector<Object *> mGameObjects;

};

#endif //SUPERVISOR_H
