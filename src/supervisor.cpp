#include "supervisor.h"

Supervisor::Supervisor(){

}

Supervisor::~Supervisor(){

}

void Supervisor::update(){
 for(auto iter = mGameObjects.begin(); iter != mGameObjects.end(); iter++){
   for(auto iter2 = iter+1; iter2 != mGameObjects.end(); ++iter2)
   {
     /* Check Collision 
      * Objects must implement isColliding method
      */
     (*iter)->isColliding(*(*iter2));
   }
 }

}


void Supervisor::add(Object *o){

  mGameObjects.push_back(o);

}

void Supervisor::erase(Object *o){
  for(auto iter = mGameObjects.begin(); iter != mGameObjects.end(); ++iter){
    if((*iter) == o){
      mGameObjects.erase(iter);
      return;
    }
  }
}
  
