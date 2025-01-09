#include <iostream>
#include <memory>

using namespace std;

class ptrClass {
public:
    void showMessage() {
        cout << "  POINTERS  " << endl;
    }
    
};

class SmartPtr {
    ptrClass* ptr; 

public:   
    explicit SmartPtr(ptrClass* p = nullptr) : ptr(p) {}

   
    ~SmartPtr() { delete ptr; }


    ptrClass& operator*() {
        return *ptr;  
    }

    
    ptrClass* operator->() {
        return ptr; 
    }
};

int main() {
    SmartPtr smartPtr(new ptrClass()); 
    (*smartPtr).showMessage();  


/*
//auto ptr

 auto_ptr<int> p (new int);
 *p.get() = 100;
 cout << "p points to " << *p.get() << '\n';
 auto_ptr<ptrClass> ptr1(new ptrClass());

 auto_ptr<ptrClass> ptr2 = move(ptr1);

 if (ptr1 == nullptr) {
 cout << "ptr1 is now nullptr (ownership moved to ptr2)" << endl;
    }

 ptr2->showMessage(); 


std::auto_ptr was deprecated in C++11 and removed in C++17 because it 
had significant issues with move semantics, implicit ownership transfer, 
and unclear ownership rules. 
It was replaced by std::unique_ptr and std::shared_ptr, which provide clearer,
safer, and more predictable ownership semantics in modern C++ code. 
If you're writing code in C++11 or later, it's best to use std::unique_ptr for 
exclusive ownership and std::shared_ptr for shared ownership.
*/


//unique ptr 

    unique_ptr<int> p1(new int);
    *p1.get() = 10;
    cout << p1.get() << endl;

    unique_ptr<int> p2 = move(p1);
    *p2.get();
    cout << p1.get() << endl;
    cout << p2.get() << endl;

//shared ptr

int* p= new int (10);
shared_ptr<int> a (p);

 if (a.get()==p){
    std::cout << "a and p point to the same location\n";

 }
 else{  
    std::cout << "a and p do not point to the same location\n"; 
    }

/*three ways of accessing the same address:
  std::cout << *a.get() << "\n";
  std::cout << *a << "\n";
  std::cout << *p << "\n"; */

   shared_ptr<ptrClass> ptr1 = make_shared<ptrClass>();

    shared_ptr<ptrClass> ptr2 =move(ptr1);

    if (ptr1 == nullptr) {
        cout << "ptr1 is now nullptr (ownership moved to ptr2)" << endl;
    }

else{

}

  cout << "Use count of ptr1 after move: " << ptr1.use_count() << endl; 

  cout << "Use count of ptr2 after move:  " << ptr2.use_count() << endl;

  shared_ptr<ptrClass> ptr3 = ptr2;

  cout << "Use count of ptr3 after move:  " << ptr3.use_count() << endl;


   ptr2.reset();

   cout << "Use count of ptr2 after reset: " << ptr2.use_count() << endl;

   ptr3.reset();

   cout << "Use count of ptr3 after reset: " << ptr3.use_count() << endl;


//weak ptr

 weak_ptr<ptrClass> weakPtr = ptr3;  
   
    shared_ptr<ptrClass> lockedPtr = weakPtr.lock();  

    if (lockedPtr) {
        cout << "Weak pointer has successfully locked the object."
        << endl;
        lockedPtr->showMessage();
    } else {
        cout << "Weak pointer has expired (the object is no longer available)." 
        << endl;
    }

    weak_ptr<ptrClass> weakPtr2 = move(weakPtr);

    shared_ptr<ptrClass> lockedPtr2 = weakPtr2.lock();

    if (lockedPtr2) {
        cout << "Weak pointer 2 has successfully locked the object after move." 
        << endl;
        lockedPtr2->showMessage();
    } else {
        cout << "Weak pointer 2 has expired (the object is no longer available)." 
        << endl;
    }


}