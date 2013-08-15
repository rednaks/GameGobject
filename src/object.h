#ifndef OBJECT_H
#define OBJECT_H

class Supervisor;

class Object {

protected:
  Object *mParent;
  Supervisor *mSupervisor;

public:
  Object(Supervisor* = 0, Object * = 0);
  virtual ~Object();
  virtual bool isColliding(Object &) = 0;
  Object *getParent();

};

#endif
