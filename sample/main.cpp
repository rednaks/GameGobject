 /**
 * This file is under MIT Licence
 * Copyright (C) 2013 Alexandre BM <s@rednaks.tn>
 *   
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *   
 * The above copyright notice and this permission notice shall be included in all copies
 * or substantial portions of the Software.
 *   
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
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
