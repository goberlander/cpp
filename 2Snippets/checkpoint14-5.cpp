// 14.14 Assume there is a class named Pet . Write the prototype for a member function of
// Pet that overloads the = operator.
Pet operator=(const Pet &); // I think
// 14.15 Assume that dog and cat are instances of the Pet class, which has overloaded
// the = operator. Rewrite the following statement so it appears in function call
// notation instead of operator notation:
// dog = cat;
dog = dog.operator=(cat);
// 14.16 What is the disadvantage of an overloaded = operator returning void ?

// 14.17 Describe the purpose of the this pointer.
It points to the object that is performing the function call, returning the value to that function.
// 14.18 The this pointer is automatically passed to what type of functions?
It is passed as a hidden argument to all nonstatic member functions 
// 14.19 Assume there is a class named Animal that overloads the = and + operators. In
// the following statement, assume cat , tiger , and wildcat are all instances of the
// Animal class:
// wildcat = cat + tiger;
// Of the three objects, wildcat , cat , or tiger , which is calling the operator +
// function? 
wildcat = cat.operator+(tiger);
It is the cat object that is calling the operator+ function.

// Which object is passed as an argument into the function?
tiger is passed as an argument.
// 14.20 What does the use of a dummy parameter in a unary operator function indicate
// to the compiler?
It indicates that the function is designed to be used in postfix mode.


