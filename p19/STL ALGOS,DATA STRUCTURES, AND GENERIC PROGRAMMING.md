# What is the STL?
		
* A library of powerful, reusable,adaptable,generic classes, and functions  
* Implemented using C++ templates  
* Implements common data structures and algorithms  
* Huge class library  
* Alexander Stepanov (1994)  
  
# Why use the STL?  
* Assortment of commonly used containers  
* Known time and size complexity  
* Tried and tested - Reusability!!  
* Consistent, fast, and type safe  
* Extensible  
  
# Elements of the STL  
  
## Containers  
- Containers of objects or primitive types  
    (array,vector,deque,stack,set,map,etc.)  
  
## Algorithms  
  - Functions for processing sequences of elements from containers (find,max,count,accumulate,sort)  
  
## Iterators  
   - Generate sequences of elements from containers  
    (forward, reverse, by value, by reference,constant, etc.)  
  
#### Sorting a vector  

	#include <vector>  
	#include <algorithm>  
  
	int main(){  
    	std::vector<integer> list {3,1,5};  
    	std::sort(list.begin(),list.end()); (sorts a container using iterators as parameters)  
	}  
  
#### Accumulating a vector  
  
	#include <vector>  
	#include <algorithm>  
  
	int main(){  
    	std::vector<integer> list {3,1,5};  
    	std::accumulate(list.begin(),list.end(),0); (3rd parameter is the starting count type is important so if you want to accumulate a container of
    	doubles you need to use 0.0)  
	}   

## Types of Containers  

 ### Sequence containers  
 
 * Array
* vector
* llist
* forward_list
* deque  
  
### Associative containers  

 * set
* multi_set
* map
* multi_map  
  
### Container adapters  

 * stack
* queue
* priority queue (DOES NOT SUPPORT ITERATORS CANNOT BE USED WITH STL ALGOS) 
  
## Types of Iterators  

* Input iterators - from the container to the program  
* Output iterators - from the program to the container  
* Forward iterators - navigate one item at a time in one direction  
* Bi-directional iterators - navigate one item at a time in both directions  
* Random access iterators - directly acess a container item  
  
## Types of Algorithms  
* About 60 algorithms in the STL  
* Non-modifying  
* Modifying  
  
## Generic programming  
* Generic programming 
 
   > Writing code that works with a variety of types of arguments, as long as those
   > argument types meet specific syntactic 
   > and semantic requirements
    
   Bjarne Stroustrup  
  
* Macros **Beware**
  
* Function Templates  
  
* Class Templates  
  
### Macros (Inferior method)  
  
* C++ Preprocessor directives  
* No type information  
* Simple substitution  
  
		#define MAX_SIZE 100 (Notice how  the 100 has no type associated with it)  
		#define PI 3.14159 (If we place these in our code the preprocessor will replace them with the values associated)  
		(Constants are a better way of doing this since they are typed and are known to the compilier)
  
#### We can define a generic macro with arguments to take in various data types  
  
	#define MAX(a,b) ((a > b) ? a : b)  
  
	std::cout << MAX(10,20); (20)  
	std::cout << MAX(a,b); (b)  
	std::cout << MAX(2.4,3.5); (20)  
  
This effectively is similar to creating a generic function
  
  
### What is a C++ Template?  
  
* Blueprint  
* Function and class templates  
* Allowing plugging-in any data type  
* Compiler generates the appropriate function/class from the blueprint  
* Generic programming / meta-programming  
  
#### Writing the MAX() function as a generic function  
  
* We need to tell the compiler this is a template function  
* We also need to tell it that T is the template parameter  

```  
template <typename T>  
T MAX(T a, T b){  
	return (a > b) ? a : b;  
	}  
		(class keyword can also be used)  
template <class T>  
T MAX(T a, T b){  
    return (a > b) ? a : b;  
}

  
* Data type can be in <>  
* This happens at compile time!  


int a {10};  
int b {20};  
std::cout << MAX<int>(a,b); (creates a specialized function for int)  
```
  
* Many times the compiler can deduce the type and the template parameter is not needed  
* Depending on the type of a and b, the compilier can figure it out  
* ALMOST any type can be used the type must support the > operator either natively or as an overloaded operator (operator>)  
int a {10};  
int b {20};  
std::cout << MAX(a,b);  
  
* We can have multiple template parameters (no limit)  
* They can also be of different types  

```  
template <typename T1, typename t2>  
void func(T1 a,T2 b){  
    std::cout << a << " " << b;  
}  
```
  
### What is a Class Template?  
  
* Similar to function templates but at the class level  
* Allows plugging in any data type  
* Compiler generates the appropriate class from the blueprint  
  
* Lets say we want a class to hold items where the item has a name and an integer :
  
 ```
class Item{  
public:  
Item(const string &name,int num) : name{name},num{num} {}  
std::string getName() const{return name;}  
int64_t getNum() const{  
return num;  
}  
  
private:  
std::string name;  
int64_t num;  
  
};  
  
//To allow this class to hold any value IN ADDITION to the string name we can do the following:  
template <typename T>  
class Item{  
public:  
Item(const string &name,T value) : name{name},value{value} {}  
std::string getName() const{  
return name;  
}  
T getValue() const{  
return value;  
}  
private:  
T value;  
std::string name;  
  
};  

  
//Just like function templates we can have multiple template parameters  
  
//Template classes are typically contained in header files, think of them as  
// a blueprint there is no need for the compiler to compile the class therefore no need for .cpp files  

```  

## The Standard Template Library  
  
### Containers  
  
* Data structures that can store almost any type  
    -Template based classes  
  
* Each container has member functions  
   -Some are specific to the container  
   -Others are available to all  
  
* Each container has an associated header file  
    -#include <container_type>  
  
#### Containers Common Methods  
  
| Function                    | Description                                            
|-----------------------------|-------------------------------------------------------
| Default Constructor         | Initializes an empty container                         
| Overloaded constructors     | Initializes containers with many options               
| Copy constructor            | Initializes a container as a copy of another container 
| Move constructor            | Moves existing container to another                    
| Destructor                  | Destroys a container                                   
| Copy assignment (operator=) | Copy one container to another                          
| Move assignment (operator=) | Move one container to another                          
| size                        | Returns the number of elements in an container         
| empty                       | Returns whether a container is empty or not (bool)     
| insert                      | Allows you to insert an element in to a container      
| operator< and operator<=    | Returns boolean (compare contents of 2 containers )    
| operator> and operator>=    | Returns boolean (compare contents of 2 containers)     
| operator== and operator!=   | Returns boolean (compare contents of 2 containers )    
| swap                        | Swap the elements of 2 containers                      
| erase             | Remove element(s) from container                  |
| clear             | Remove all elements from a container              |
| begin and end     | Returns iterators to first element or end         |
| rbegin and rend   | Returns reverse iterators to first element or end |
| cbegin and cend | Returns constant iterators to first element or end |
| crbegin and crend | Returns reverse constant iterators to first element or end |

  
#### Container elements  
  
##### What types of elements can we store in containers?  
* All primitives can be stored.  
  
##### What about objects?  
* A copy of the object will be stored in the containers  
* Object should be copyable and assignable (copy constructor and copy assignment)  
moveable for efficency (move constructor and move assignement)  
  
* For ordered associative containers objects must be comparable  
-operator<,operator==  
  
### Iterators  
  
* Iterators are template classes so we must create an iterator object and use it on containers  
* Allows abstracting an arbitrary container as a sequence of elements  
* They are objects that work like pointers by design  
* Most container class can be traversed with iterators  
  
#### Declaring Iterators  
  
* Iterators must be declared based on the container type they will iterate over  
container_type::iterator_type iterator_name;  

```  
std::vector<int>::iterator it1;  
std::list<std::string>::iterator it1;  
std::map<std::string, std::string>::iterator it1;  
std::set<char>::iterator it1;  
```

Iterator begin and end methods  
  
*The begin() method defines the first element of the container  
*The end() method defines the LOCATION after the last element of the container  
  
#### Initializing Iterators  

```
std::vector<int> vector {1,2,3};  
std::vector<int>::iterator it1 {vector.begin()}; //If the vector had been empty it would point to vector.end()  
// or alternatively  
 
auto it1 {vector.begin()};  
```

#### Operations with iterators (it)  
  

| Operation        | Description                | Type of iterator        
|---------------|-----------------------|-------------
| ++it                | Pre-increment         | ALL                    
| it++                | Post-increment        | ALL                          
| it = it1            | Assignment            | ALL (Types must be the same) 
| *it                 | Dereference           | INPUT AND OUTPUT           
| it->                | Arrow operator        | INPUT AND OUTPUT        
| it == it1           | Equality comparison   | INPUT                    
| it != it1           | Inequality comparison | INPUT                
| --it                | Pre-decrement         | Bidirectional       
| it--                | Post-decrement        | Bidirectional              
| it + i, it+=i       | Increment             | Random Access             
| it - i, it-=i       | Decrement             | Random Access                
| it < it1, it <=i t1 | Comparison            | Random Access       
| it > it1, it >=i t1 | Comparison            | Random Access                

#### Using Iterators -std::vector  
  
```
std::vector<int> vector {1,2,3};  
std::vector<int>::iterator it{vector.begin()};  
//Alternatively auto it = vector.begin();  
  
while(it != vec.end){  
    std::cout << *it << std::endl;  
    ++it;  
}  
//prints:  
//1  
//2  
//3  
  
//Important to note that behind the scenes the compiler changes loops to loops using iterators  
//Below is the for loop version  
for(auto it = vector.begin(); it != vec.end(); it++){  
    std::cout << *it << std::endl;  
}  
//The above loop is exactly how range-based for loops work  
```

#### Reverse Iterators  
  
* Works in reverse  
* Last element is the first and first element is the last  
* ++Moves the iterator backwards, -- moves it forward  
  
```
std::vector<int> vector {1,2,3};  
std::vector<int>::reverse_iterator it {vector.rbegin()};  
  
while(it != vector.rend()){  
    std::cout << *it++ << " ";  
}  
// 3 2 1  
  
ex.end  
  
Example using begin() and end() iterators and traverse backwards.  
  
ex.2  
  
//auto automatically deduces the type of iterator to be used  
//std::vector<int>::iterator  
  
auto itera = vec.end()-1;  
while(itera != vec.begin()-1 )  
{  
   std::cout << *itera-- << " ";  
}  
std::cout << std::endl;  
  
ex.end  
  
ex.3  
  
//Using reverse iterator objects on regular iterators (begin() and end())  
  
std::vector <int>  vec {1, 2, 3};  
  
std::vector <int>::reverse_iterator it(vec.begin());  
std::vector <int>::reverse_iterator iter(vec.end());  
  
while (iter != it)  
{  
std::cout << *iter++ << " ";  
}  
std::cout << std::endl;  
```

#### Other iterators  
  
* begin() and end()  -Iterator  
  
* cbegin() and cend()  -Constant iterator  
  
* rbegin and rend()  -Reverse iterator  
  
*  crbegin() and crend()  - Constant Reverse iterator
  
### Algorithms  
[Algos](https://en.cppreference.com/w/cpp/algorithm)
  
* STL algorithms work on sequences of container elements  
provided to them by an iterator  
* STL has many common and useful algorithms  
* Many algorithms require extra information to do their work  
-Functors (function objects)  
-Function pointers  
-Lambda expressions (C++11)  
  
* Different containers support different types of iterators  
-Determines the type of algorithms supported (Algorithms work on certain iterators)  
  
* All STL algorithms expect iterators as arguments  
-Determines the sequence obtained from the container  
  
### Iterator invalidation  
  
* Iterators point to container element  
  
* It's possible for iterators to become invalid during processing  
  
#### Suppose we are iterating over a vector with 10 elements  and we clear() the vector while iterating? What happens ? 

(The iterator is invalidated since the element that it would be pointing to is gone)  
  
### Example Algo - find with primitive types  
  
* The find algo tries to locate the first occurrence of an element in a container  
* Lots of variations  
* Returns an iterator pointing to the element or end()  
```  
std::vector<int> vec {1,2,3};  
  
auto loc = std::find(vec.begin(),vec.end(),3);  
  
if(loc != vec.end()){  
    std::cout << *loc << "\n";  
}  
 ```
 
### Example Algo - find with user provided data types  
  
* Find needs to be able to compare objects  
* operator== is used to make the comparison and must be provided by your class  

```  
std::vector<Player> team { // assume initialized };  
  
Example Algo - for_each  
  
* for_each algo applies a function to each element in the iterator sequence  
* Function must be provided to the algo as:  
    -functor (function object)  
    -function pointer  
    -Lambda expression (C++11)  
  
*Let's square each element (see Functor_FunctionPointer_LambdaSTL.cpp)  
  
std::array (C++11)  
  
#include <array>  
  
*Fixed size  
-Size must be known at compile time  
*Does not decay to a pointer unlike raw arrays when passed as args  
*Direct element access  
*Provides access to the underlying raw array  
*All iterators are available and do not invalidate  
  
std::array- Initialization and assignment  
  
Initialization:  
std::array<int,5> array{1,2,3,4,5}; (C++14 and up)  
std::array<int,5> array{{1,2,3,4,5}}; (C++11 and below)  
  
std::array<std::string,3> stooges{  
    std::string{"Larry"},  
    "Moe" (We can provide Cstyle string literals),  
    std::string{"Curly"};  
};  
  
array = {1,2,3,4}; (We can assign multiple values to an existing array )  
  
std::cout << array.size(); //Outputs 5  
std::cout << array.at(0); //1  
std::cout << array.front(); //first element (reference)  
std::cout << array.back(); //last element (reference)  
std::cout << array.empty(); //false  
std::cout << array.max_size(); //5  
std::cout << array.swap(another_array); //swaps the 2 arrays  
int *data = array.data(); //get the raw array address  
```

## std::vector  
  
* Dynamic size  
    -Handled automatically  
    -Can expand and contract as needed  
    -Elements are stored in contiguous memory as an array  
  
* Direct element access (constant time)  
  
* Rapid insertion and deletion at the back (constant time)  
  
* Insertion or removal of elements in linear time  
  
* All iterators available and may invalidate  
 
 ```
std::vector<int> vec {1,2,3,4,5};  
std::vector<int> vec2 (10,100); //Uses the constructor to make a vector with 10 100s  
  
vec.pop_back(); //Removes the last element  
  
std::vector<Person> vec3 {};  
Person p1 ("Larry",100);  
vec3.push_back(p1); //Since all container classes make copies of the elements they store a copy of p1 is made  
vec3.push_back(Person("Larry",18)); //Adds to the vector using move semantics since it is an xvalue (expiring object)  
  
vec3.emplace_back("Moe",50) //Efficient! Expects parameters for a person object and constructs the object right in the container  
//No move or copying necessary  
  
vec.swap(vec2); //This works! unlike arrays since vectors are dynamic in space they can be swapped with 2 different sizes  
```

### Common Method - Vectors  

```
std::vector<int> vector1 {1,2,9,10,4,17);  
std::vector<int> vector2 {22,55,100,99};  
  
auto it  { std::find(vector1.begin(),vector2.end(),9) };  
vector.insert(it,10); //Inserts 10 at the address (place) of the iterator  
// 1,2,10,9,10,4,17  
  
it = std::find(vector1.begin(),vector1.end(),4);  
vector1.insert(it,vector2.begin(),vector2.end()); //Inserts the entire sequence of elements in vector 2 before  
//the number 4  
```

## std::deque (double ended deque)  

```
#include <deque>  
 ``` 
* Dynamic size  
* Handed automatically  
* Not stored in contiguous memory  
* Can expand and contract as needed    
* Direct element access (constant time)   
* Rapid insertion and deletion at the front and back only (constant time)  
//Unlike vectors which only have efficient insertion and deletion at the back of the container  
* Insertion and removal of elements (linear time)  
* All iterators are available and may invalidate  
  
### std::deque - initialization and assignment  
 
 ```
std::deque<uint64_t> d{1,2,3,4,5};  
std::deque<uint64_t d2{77,33,23,56};  
  
std::deque<std::string> stooges {  
    std::string("Moe"),  
    "Larry",  
    std::string("Curly")  
};  
d = {1,99,100};  
```

* front() and back() methods are available for deque  
they return the first or back elements  
* push_back() - Allows you to place one element in the back of the deque  
* push_front() -Allows you to place an element in the front of the deque  
  
* Usually deques are stored as multiple contiguous blocks that are not contiguous to each other  (Like a linked list of vectors)  

```
std::cout << d.size() //3  
std::cout << d.max_size //very large number  
std::cout << d.at(0) //1 -bounds checking  
std::cout << d[1] //99 -no bounds checking  
std::cout << d.front() //1  
std::cout << d.back() //100  
  
d.push_back(101) //adds 101 to the back of d  
d.pop_back() //removes 101 from the back of d  
  
Person p1 {"Larry",15};  
std::deque<Person> stooges {{"Moe",10}};  
  
stooges.push_front(p1); //Adds larry to the front  
stooges.pop_front(); //Removes larry from the front  
  
stooges.emplace_back("Larry",15}; //Efficiently adds an object to the back  
stooges.emplace_front("Curly",20}; //Efficiently adds an object to the front  
```

## std::list and std::forward_list  
  
* Sequence containers  
* Not in contigious memory  
* No direct access to the elements  
* Very efficient for inserting and deleting elements once an element is found  

### std::list

 ```
#include <list> (aka doubly-linked list)  
```
	
* Dynamic size  
* List of elements  
* List is bidirectional(doubly-linked)  
* Direct element access is NOT provided  
* Rapid insertion and deletion of elements anywhere in the container (constant time)  
* All iterators are available may invalidate when a corresponding element is deleted  
  
```
std::list<int> li{1,2,3,4,5};  
std::list<int> li2(10,100); //10 100s    
li = {1,2,3};  
  
std::cout << li.size();  
std::cout << li.max_size();  
std::cout << li.capacity();  
std::cout << li.front(); //returns reference to front  
std::cout << li.back(); //returns reference to back  
  
Person p1 {"Larry",15};  
std::list<Person> stooges;  
  
stooges.push_back(p1); //Pushes back l value to the list  
stooges.pop_back(); //Removes p1 from list  
  
stooges.push_front(Person("Larry",15)) //Pushes back r value to the front of list (inefficient better to use emplace_front)  
stooges.pop_front();//Removes the object in the front  
  
stooges.emplace_back("Larry",15);  
stooges.emplace_front("Curly",20);  
  
std::list<int> li{1,2,3,4,5,6};  
auto it = std::find(li.begin(),li.end(),3);//Returns an iterator to the location of the 3  
li.insert(it,10); //Insert 10 at the location of 3 (1,2,10,3,4,5,6)  
//IMPORTANT notice that the insert method works a little bit differently than the insert method  
//for vectors since it places 10 at the position of 3 and "pushes" 3 and the other elements  
//forward instead of deleting 3 and taking its location  
  
li.erase(it); //Erase the element at the location of the iterator  
//This does not invalidate any iterators or references after or before the erased element  
//Only the erased element is invalidated  
  
li.resize(2); //{1,2};  
li.resize(5); // {1,2,0,0,0};  
//If the resize is greater than the current size the default initializer initializes the elements  
  
std::list<int> list1{1,2,3,4,5,6};  
  
auto it {std::find(list1.begin(),list1.end(),3)};  
  
cout << *it; //3  
  
cout << *(++it); //4  
  
cout << *(--it);//3  
```

### std::forward_list
```
#include <forward_list> 
```

* Dynamic size  
* list of elements  
* list uni-directional(singly-linked)  
* Less overhead than a std::list  
*Direct element access is NOT provided  
*Rapid insertion and deletion of any element in the list  
*Reverse iterators are not available. Iterators may invalidate when corresponding element is deleted  (back() is not supported)  
 
```
std::forward_list<int> list {1,2,3};  
```
 ~~std::cout << list.size();~~ (not avaliable)
 ```
std::cout << list.max_size(); //SOME REALLY LARGE NUMBER  
std::cout << list.front(); //1 
```
~~std::cout << list.back();~~ (NOT AVAILABLE )

#### The rationale for no size() method:

##### TLDR

The reason is that it is not possible to store or  
compute the current number of elements in constant time.  

##### Longer reason

The rationale the designers used was this:   
>Maintaining a count doubles the size of a forward_list object  
>(one word for the list head and one for the count), and  
>it slows down every operation that changes the number of nodes.  
>In most cases this isn't a change in asymptotic complexity  
>(the one change in asymptotic complexity is in one of the forms of splice),  
>but it is nonzero overhead. It's a cost that all users would have to pay for,  
>whether they need this feature or not, and, for users who care about maintaining a count,  
>it's just as easy to maintain it outside the list,  
>by incrementing the count with every insert and decrementing it with every erase,  
>as it is to maintain the count within the list.
  
### Std::forward_list cont.

* pop_front(),push_front(), and emplace_front are all available  
 ```
std::forward_list<int> list1{1,2,3,4,5,6,7,8,9,10};  
auto it {std::find(list1.begin(),list1.end(),5};  
  
list1.insert_after(it,10); {1,2,3,4,5,10,6,7,8,9,10}  
list.emplace_after(it,100); {1,2,3,4,5,100,10,6,7,8,9,10};  
  
//No insert,emplace methods all are called insert after and emplace after  
 ```
  
## The STL Set containers  
  
* Associative containers  
* Collection of stored objects that allow fast retrieval using a key  
* STL provides Sets and Maps [Stackoverflow-Differences between Map and set](https://stackoverflow.com/questions/22088607/what-is-the-difference-between-set-vs-map-in-c)  
* Usually implemented as a balanced binary tree or hashsets  
* Most operations are very efficient  
  
### Set

- std::set  
- std::unordered_set  
- std::multiset  
- std::unordered_multiset  
  
#### std::set  
 ``` 
#include <set>  
 ```
 
* Similar to mathematical set  
* Ordered by key  
* No duplicate elements  
* All iterators available and invalidate when corresponding element is deleted  

```  
std::set<int> s {1,2,3,4,5};  
  
std::set<std::string> stooges {  
    std::string{"Larry"},  
    "Moe",  
    std::string{"Curly"}  
}  
  
s = {2,4,6,8,10};  
  
std::set<int> s{4,1,1,3,3,2,5}; //Automatically deletes all duplicates and orders the elements //1 2 3 4 5  
std::cout << s.size(); //5  
std::cout << s.max_size(); //Some very large number  
 ```
 
* No concept of front and back  
 ```
s.insert(7);  
s.emplace(7);  
//1,2,3,4,5,6,7  
```

##### std::set - common methods  
 ``` 
Person p1 {"Larry",18};  
Person p2 {"Moe",25};  
  
std::set<Person> stooges;  
  
stooges.insert(p1);// Adds p1 to the set  
  
std::pair<iterator, bool> = stooges.insert(p2)  
*uses operator< for ordering !  
// adds p2 to the set but will return a pair<iterator,bool>:  
//first is an iterator to the inserted element or the duplicate in the set  
//second is an boolean indicating success or failure  
  
std::set<int> s{1,2,3,4,5};  
s.erase(3); //erases the 3 : 1 2 4 5  
  
*Note when using find it is best to use the set's find method rather than the stl algo find function since the set's  
find method understands the underlying implementation of the set container and uses a much quicker search than the generic STL find.  
  
auto it = s.find(5);  
if( it != s.end())  
    s.erase(it); erase the 5 : 1 2 4  
  
std::set<int> s{1,2,3,4,5};  
int num {s.count(1)}; //0 or 1  
s.clear(); //remove all the elements  
  
s.empty() //true or false depending on where the container is empty  
``` 

### std::multi_set  
```
#include <set>  
```

* Sorted by key  
* Allows duplicate elements  
* All iterators are available  
  
### std::unordered_set  
```
#include <unordered_set>  
```

* Elements are unordered  
* No duplicate elements allowed  
* Elements cannot be modified  
 	-Must be erased and new element inserted  
* No reverse iterators are allowed  
  
### std::unordered_multiset  
 ```
#include <unordered_set>
```

* Elements are unordered  
* Allows duplicate elements  
* No reverse iterators are allowed  
  
## The STL Map containers  
  
* Associative containers  
* Collection of stored objects that allow fast retrieval using a key  
* STL provides Sets and Maps  
* Usually implemented using as a balanced binary tree or hashsets  
* Most operations are very efficient  
  
#### Maps  
- std::map  
- std::multimap  
- std::unordered_multimap  
- std::unordered_map  
  
### std::map  
 ```
#include <Map>  
```

* Similar to a dictionary  
* Elements are stored as Key, Value pairs (std::pair)  
* Ordered by key  
* No duplicate keys are allowed (keys are unique)  
* Does not allow duplicate elements  
* Direct element access using the key  
* All iterators are available and invalidate when corresponding element is deleted  
```
std::map<std::string,int> m1 {  
    {"Larry",18},  
    {"Moe",25}  
}  
std::map<std::string,std::string> m {  
    {"Bob","Brand"},  
    {"Daniel","Hartle"},  
    {"Sal","Jallot"}  
}  
  
std::cout << m.size();  
std::cout << m.max_size();  
  
std::pair<std::string,std::string> p1 {"James","Holder"};  
  
m.insert(p1);  
  
m.insert(std::make_pair("Roger","Daniel"));  
  
//Another way to insert using the subscript operator  
  
m["Frank"] = "Teacher";  
m["Frank"] = "Instructor"; //update  
m.at("Frank")  = "Teacher";//Does the same except throws an exception if no key was found  
  
m.erase("Sal");  
  
if(m.find("Bob") != m.end()){  
    std::cout << "Found bob! ";  
}  
  
auto it = m.find("George");  
if(it != m.end()){  
    m.erase(it);  
}  
  
int num = m.count("Bob");//returns 1 or 0 if the element exists or not  
```

### std::multi_map  
 ``` 
#include <map>  
```

* Ordered by key  
* Allows duplicate elements  
* All iterators available  
  
### std::unordered_map  
```  
#include<unordered_map>  
``` 

* Elements are unordered  
* No duplicate elements are allowed  
* No reverse iterators are allowed  
  
## STL Adaptor Containers  
  
### std::stack  
  
* Last-in First-out (LIFO) data structure  
* Implemented as an adapter over other STL container  
* Can be implemented as a vector,list, or deque  
* All operations occur on one end of the stack(top)  
* No iterators are supported (Can't be used with STL algos)  
 ```
#include <stack> 
```

* push - insert an element on top of the stack  
* pop - remove an element from the top of the stack  
* top - access an element from the top of the stack  
* empty - is the stack empty ?  
* size - number of elements in the stack  
  
(STL uses deque by default for stack)  

```
std::stack<int> s; //Deque  
std::stack<int,std::list<int>> s1; //List  
std::stack<int,std::vector<int>> s2; //Vector  
std::stack<int,std::deque<int>> s3; //Deque  
``` 

### std::queue  
  
* First-in First-out (FIFO) data structure  
* Implemented as an adaptar over other STL containers  
* Can be implemented as a list or deque;  
* Elements are pushed at the front and popped from the front  
* No iterators are supported  
 ```
#include <queue>  
```

* push-inserts an element at the back of the queue.  
* pop- remove an element from the front of the queue.  
* front - access the element at the front  
* back - access the element at the back  
* empty - is the queue empty?  
* size - how many elements are in the element  
```
std::queue<int> q; //deque by default  
  
std::queue<int,std::list<int>> q; //list  
std::queue<int,std::deque<int>> q; //deque  
  
std::cout << q.front(); //output the front  
std::cout << q.back(); //output the back (both are references)  
q.pop(); //removes from the front  
```  
### std::priority_queue  

* Allows insertions and removal of elements in order from the front of the container  
* Elements are stored internally as a vector by default. (Stored using a heap data structure NOT the same heap where dynamically allocated memory is stored)  
* Elements are inserted in priority order (largest value will always be at the front)  
* No iterators are supported  
 
 ```
#include <queue>  
```

* push-inserts an element at the back of the queue.  
* pop- remove an element from the front of the queue.  
* top - access the element at the front (highest priority element (element with the greatest value))  
* back - access the element at the back  
* empty - is the queue empty?  
* size - how many elements are in the element  
```  
std::priority_queue<int> pq; //vector  
pq.push(10);  
pq.push(20);  
pq.push(3);  
pq.push(4);  
  
std::cout << pq.top(); //20  
pq.pop(); //20 removed  
pq.pop(); //10 removed
```
