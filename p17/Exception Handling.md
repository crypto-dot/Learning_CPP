# Exception handling

* Dealing with extraordinary situations
* indicates that an extraordinary situation has been detected or has occurred
* Program can deal with the extraordinary situations in a suitable manner

## What causes exceptions?

* Insufficient resources
* Missing resources
* Invalid operations
* Range violations
* Underflows and overflows
* Illegal data and many others

## Exception Safe

* This occurs when your code handles exceptions

## What is an Exception?

* An object or primitive type that signals when an error has occurred

## What is throwing an exception (Raising an Exception)?

* Your code detects that an error has occurred or will occur
* The place where the error has occurred may not know how to handle the error
* Code can throw an exception describing the error to another part of the program that knows how to handle the error

## What is Catching an exception?

* Code that handles the exception
* may or may not cause the program to crash

## Keywords that involve exceptions

### Throw
* Throws an exception
* Followed by an argument

### Try {code that may throw an exception}
* You place code that may throw an exception in the try block
* If an exception occurs then the try block is exited
* The throw exception is handled by the catch handler
* If no catch handler exists the program terminates

### Catch {Exception ex} (code that handles exception ex)
* Code that handles the exception
* Can have multiple catch handlers
* May or may not cause the program to terminate

#### What happens if total is zero?
* Crash, overflow?
* It depends

```double average();
average = sum/total;

try{
    average = sum/total;
    std::cout << "The average is " << average << std::endl;
}
catch {int &ex}{
    std::cerr << "You can't devide by 0!" << std::endl;
}
std::cout << "Bye!" << std::endl;
```

### Stack unwinding

* If an exception is caught but not thrown but not caught in the current scope C++ tries to find a handler for the exception
by unwinding the stack
* Function in which the exception was not caught terminates and is removed from the call stack.
* If no try block was used or the catch block doesn't match stack unwinding occurs again
* If The stack is unwound back to the main and no catch handler was used to handle the exception the program terminates

### User-defined exceptions (We can create our own exception classes and throw instances of those classes)

* Best practice:
    -Throw an object not a primitive data type
    -Throw an object by value
    -Catch an object by reference (or const reference)

#### Creating exception classes
```
class DivideByZeroException {
};

class NegativeValueException {

};
```

#### Class level Exceptions

Exceptions can also be thrown from within a class:
* Method
    -These work the same way as they do for functions as we've seen
* Constructor
    -Constructors may fail
    -Constructors do not return any value
    -Throw an exception in a constructor if you cannot initialize an object
* Destructor
    -Do **NOT** throw exceptions from your destructor