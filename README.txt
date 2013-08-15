This a game object manager, called GameGobject, this code tend to be a C++ library that you can use to manage all objects in your game.
At this time, the object manager handles collisions, so you have to override the "isColliding" method.

How to use: 

To use the GameGobject, you have to create a new object or entity class that inherits from Object.
don't forget to call Supervisor::update() to update the world after logic oprerations.


Licence: 
This code is under MIT Licence. More information in the code source's headers.
