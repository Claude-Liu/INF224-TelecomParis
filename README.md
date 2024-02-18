# INF224 project of Telecom Paris

name: Linfeng Liu



## How to start

1. To launch this project, you need to firstly start the server.

   ```
   cd cpp
   make run
   ```

2. Then you can launch the user interface developed by Java Swing.

   ```
   cd ../swing
   make run
   ```

3. Then you can use this interface to play photos or videos.

   Firstly, you should **type the name** of the photo or videos you want to watch and **click submit**:

   **The available sources are:** 

   Photo: poster , dolomites_1 , dolomites_2

   group: all_figures

   Video or film: dolomites , dolomites_film

   Then you can click the button **options** and choose to **play** or **search** the media you have submitted.



## details about the implementation of the server

### Q4 and Q5

1. I make the function ```play``` a pure virtual function  in the base class ```MultiMedia```, which makes it an abstract class. We can not instantiate an abstract class.

2. This question demonstrate the Polymorphism. 

3. In C++, virtual methods and a virtual destructor are necessary to achieve dynamic binding. 

   The array contains pointers of base class pointing to objects of different sub-classes.

   In contrast, Java inherently supports dynamic binding, so this issue does not arise.

### Q7

When performing a shallow copy, the pointers merely point to the same object. Consequently, if one pointer is deleted, the object it points to is destroyed as per the destructor, leaving the other pointer referencing a memory location filled with undefined data. To address this issue, it's essential to overload the assignment operator (`operator=`) to implement deep copying. This means that when copying pointers, a new instance of the pointed-to object should be created, and the pointer should then be directed to this new instance.

### Q8

 It's crucial to use a list of object pointers instead of objects themselves. This approach allows multiple groups to share ownership of the objects without taking responsibility for their lifetime management. When a group being deleted, only the pointers are deleted while the pointed objects are not influenced.

In contrast, Java handles object lifetime and memory management through its garbage collection mechanism. In Java, as long as there are references to an object, the garbage collector will not reclaim its memory. This automatic management of object lifetimes simplifies handling cases where objects belong to multiple collections.

### Q10

We can set the constructor to `private`, preventing creating instantiate using  ```new```.

This can control or restrict the instantiation and usage patterns of a class. 



**Q12, Q13 not treated**