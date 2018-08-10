const int SIZE = 40;
InventoryItem inventory[SIZE]; 
// This will initialize 40 inventory objects with the default constructors.

InventoryItem inventory[] = {"Hammer", InventoryItem("Wrench", 8.7, 5.9), "Pliers"}; 
// This will initialize the first object (inventory[0]) with the constructor that takes one argument, then initialize object 2 (inventory[1]) with a constructor that has 3 parameters, then object 3 (inventory[2]) will call the constructor with one argument.

/* If you want to call a constructor with multiple parameters, you need to write it as a member function.
From the book (page 767): If a constructor requires more than one argument, the initializer must take the form of a
function call. */

// ACCESSING OBJECTS AND MEMBERS OF OBJECTS IN AN ARRAY

inventory[1]; // accesses the 2nd object of the array inventory.
inventory[i].getDesc(); // Accesses the member function getDesc passing no arguments of the i'th object.