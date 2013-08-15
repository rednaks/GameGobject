#include "../src/supervisor.h"
#include "../src/object.h"
#include <iostream>

class Wizard: public Object
{
  private:
    int mXPos;
    int mYPos;
  public:
    Wizard(Supervisor* aSupervisor = 0, Object* aParent = 0):
      Object(aSupervisor, aParent){ }

    bool isColliding(Object &aObject){
      Wizard w = static_cast<Wizard&>(aObject);
      std::cout << "Other X : " << w.getXPos() << std::endl;
      std::cout << "Other Y : " << w.getYPos() << std::endl;
      if(w.getXPos() == this->mXPos && w.getYPos() == mYPos){
        std::cout << "Objects are in collision !" << std::endl;
        return true;
      }
        std::cout << "Objects are not colliding" << std::endl;
      return false;
    }

    void setXPos(int aXPos) { mXPos = aXPos;}
    void setYPos(int aYPos) { mYPos = aYPos;}
    int getXPos(){ return mXPos;}
    int getYPos(){ return mYPos;}
};
int main(int argc, char **argv){
  
  Supervisor super;

  Wizard aWizard(&super);
  aWizard.setXPos(1);
  aWizard.setYPos(2);

  Wizard bWizard(&super);
  bWizard.setXPos(15);
  bWizard.setYPos(3);

  super.update();
  bWizard.setXPos(1);
  bWizard.setYPos(2);
  super.update();

}
