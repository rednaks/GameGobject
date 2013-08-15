#include "object.h"
#include "supervisor.h"

Object::Object(Supervisor *aSupervisor, Object *aParent) {

    mParent = aParent;
    mSupervisor = aSupervisor;
    mSupervisor->add(this);

}

Object::~Object(){
  mSupervisor->erase(this);
}

Object * Object::getParent(){
  return mParent;
}
