# Files Stream and I/O  
* C++ uses streams as an interface between the program and input and output devices  
* Independent of the actual device  
* Sequence of bits  
* Input stream provides data to the program  
* Output stream receives data from the program  
  
## Common header files  

| Header File     | Purpose                                                               |
|-----------------|-----------------------------------------------------------------------|
| iostream        | Provides Definitions for formatted input and output from/to streams   |
| fstream         | Provides definitions for formatted input and out from/to file streams |
| iomanip         | Provides definitions for manipulators used to format stream I/O       |

## Commonly used stream classes  
  
| Stream Class | Purpose                                                                                                                |
|--------------|------------------------------------------------------------------------------------------------------------------------|
| ios          | Provides basic support for formatted and unformatted I/O operations. Base class for most other classes                 |
| ifstream     | Provides for high level input operations on file based streams.                                                        |
| ofstream     | Provides for high level output operations on file based streams.                                                       |
| fstream      | Provides for high level output/input operations on file based streams.                                                 |
| stringstream | Provides for high level input/output operations on string based streams. Derived from istringstream and ostringstream. |
  
## Global stream Objects  
  
| Stream Object | Purpose                                                                                                                 |
|---------------|-------------------------------------------------------------------------------------------------------------------------|
| cin           | Standard input stream - by default "connected" to the standard input device (keyboard) instance of istream.             |
| cout          | Standard output stream - by default "connected" to the standard output device (console) instance of ostream.            |
| cerr          | Standard error stream - by default "connected" to the standard error device (console) instance of ostream (unbuffered). |
| clog          | Standard log stream - by default "connected" to the standard log device (console) instance of ostream (unbuffered).     |
                                                                                                              
  
## Stream Manipulators  
* Streams have useful member functions to control formatting  
* Can be used on input and output streams  
* The time of the effect on the stream varies  
* Can be used as a member method or as a stream manip  

 ``` 
std::cout.width(10); //Member function  
std::cout << setw(10); //Manipulator  
```

* We will focus on the manipulators  
  
### Common stream manipulators  
  
* Boolean  
-Boolalpha, noboolalpha  
* Integer  
-dec, hex, oct, showbase, noshowbase, showpos, noshowpos, uppercase, nouppercase  
* Floating point  
-fixed, scientific, setprecision, showpoint, noshowpoint, showpos, noshowpos  
* Field width,justification, and fill  
-setw, left, right, setfill  
* Others  
-endl, flush, skipws, noskipws, ws  
  
#### Formatting boolean types  

```std::cout << (10 == 10) << std::endl; //output 1  
std::cout << (10 == 0) << std::endl; //output 0  
std::cout << std::boolalpha;  
std::cout << (10 == 10) << std::endl; //output true  
std::cout << (10 == 0) << std::endl; //output false  
  ```
  
** All further boolean output will be affected (with noboolalpha and boolalpha)  **
  
##### Method version  
```std::cout.setf(std::ios::boolalpha);  
std::cout.setf(std::ios::noboolalpha);
```
  
* Reset flags to default  
```std::cout << std::resetiosflags(std::ios::boolalpha);  ```
  
#### Formatting Integer types

##### Default when displaying integer values is:  
* dec (base 10)  
* noshowbase - prefix used to show hexadecimal or octal  
* nouppercase - when displaying a prefix and hex values it will be lower case  
* noshowpos - no "+" is displayed for positive numbers  
  
** These manipulators affect all futher output to the stream  **
 ``` 
int num {255};  
std::cout << std::dec << num << std::endl; //255  
std::cout << std::oct << num << std::endl; //377  
std::cout << std::hex << num << std::endl; //FF  
  
  
int num {255};  
std::cout << std::showbase;  
std::cout << std::dec << num << std::endl; //255  
std::cout << std::oct << num << std::endl; //0377  
std::cout << std::hex << num << std::endl; //0xFF  
  
  
int num {255};  
std::cout << std::showbase << std::uppercase;  
std::cout << std::hex << num << std::endl; //0XFF  
  
int num {255};  
int num2 {-255};  
  
std::cout << std::showpos;  
std::cout << num1 << std::endl;  
std::cout << num2 << std::endl;  
  ```
  
#### Formatting Floating Point values  
  
##### Default when displaying floating point values is:  

* Setprecision - number of digits displayed (6 default)  
* fixed - not fixed to a specific number of digits after the decimal point  
* noshowpoint - trailing zeros are not displayed  
* nouppercase - When displaying in scientific notation  
* noshowpos - no '+' is displayed for positive numbers (Default)  
  
*These manipulators persist  
  
**ex.1**

```
double num {1234.5678};  
std::cout << num << std::endl;  
//Will display  
1234.57 (6 significant digits are displayed and rounded)  
 ``` 
**ex. 2**

```double num {123456789.987654321};  
std::cout << num << std::endl;  
//will display  
1.23457e+008 {note 6 significant digits}  
  ```
**ex.3**

```double num {123456789.987654321};  
std::cout << std::setprecision(9) << num << std::endl;  
//will display  
123456790 (note that rounding occurs)  
  ```
**ex. 4**

```double num {123456789.987654321};  
std::cout << std::fixed << num << std::endl;  
//will display 6 precision from the decimal  
123456789.987654 (will round if necessary and zeros will be added if necessary);  
  ```
**ex. 5**

```double num {123456789.987654321};  
std::cout << std::setprecision(3) << std::scientific << num << std::endl;  
//will display precision 3 in scientific notation  
1.23e+008  
  ```
**ex.6**

```double num {12.34};  
std::cout << std::showpoint << std::endl;  
std::cout << num << std::endl;  
//will display trailing zeroes up to the significance  
12.3400
```
  
##### Field width,align, and fill  
  
###### Default when displaying floating point values is:  

* setw-not set by default  
* left -when no field width, right when using field width  
* fill - not set by default - blank space is used  
  
**ex.1**

```
int num {1234.5678};  
std::string hello{"Hello"};  
  
std::cout << std::setw(10) << num << hello << std::endl;  
//will display  
12345678901234567890  
1234.57Hello  
```
  
**ex.2**

```  
int num {1234.5678};  
std::string hello{"Hello"};  
  
std::cout << std::setw(10) << num << setw(10)<< hello <<setw(10) << hello << std::endl;  
//will display  
123456789012345678901234567890  
   1234.57     Hello     Hello  
```
  
**ex.3**  
  
```
int num {1234.5678};  
std::string hello{"Hello"};  
  
std::cout << std::setw(10) << left << num << hello <<std::endl;  
//will display  
123456789012345678901234567890  
1234.57   Hello  
//Left justification only affects num  
```
  
**ex.4**  

```
int num {1234.5678};  
std::string hello{"Hello"};  
  
std::cout << setfill('-') << std::setw(10) << num << hello <<std::endl;  
//will display  
123456789012345678901234567890  
---1234.57Hello  
```
  
## Input Files (fstream and ifstream)  
  
1. #include <fstream>  
2. Declare an fstream or ifstream object  
3. Connect it to a file on your file system (opens it for reading)  
4. Read data from the file via the stream  
5. Close the stream  
  
### Fstream Object  
```  
std::fstream in_file{"../myfile.txt",std::ios::in};  
```
	
*Since fstreams can be input or output files when need to specify.It is more common to use the ifstream class for the purpose of input files (Writing to files).We can actually use fstream files as both input and output files, and the default parameter mode for  
it is std::ios::in | std::ios::out.
  
```
std::fstream in_file{"../myfile.txt",std::ios::in | std::ios::binary}; //Second arg means binary```
  
### Ifstream Object  
  
```std::ifstream in_file {"../myfile.txt",std::ios::in};  
std::ifstream in_file {"../myfile.txt";  
//Both of the above files have the same settings  
  
std::ifstream in_file{"../myfile.txt",std::ios::binary} //binary mode  
  
std::ifstream in_file;  
std::string fileName;  
std::cout << "Input file name: "; std::cin >> fileName;  
  
in_file.open(fileName);  
//binary mode  
in_file.open(fileName,std::ios::binary);  
  
// to check if the file was opened successfully  
  ```
	
**ex.1**
	
```
if(file.is_open()){  
    //read from it  
}  
else {  
    //do something  
}  
file.close();  
//Very important to close files (esp. output files)  
  ```
	
**ex.2 **
	
```
int num{};  
double total{};  
std::string name{};  
  
in_file>>num >> total >> name;  
in_file.close();  
  
*We can use getline() to get entire lines from files  
  ```
	
**ex.3 ** 
	
```
std::string line{};  
  
getline(in_file,line);  
  
std::ifstream in_file{"../myfile.txt"};//open file  
std::string line;  
  
if(!in_file){  
    std::cerr<< "ERROR file cannot be opened";  
    return 1;  
}  
    while(getline(line,in_file)){  
        std::cout << line << "\n";  
    }  
    in_file.close();  
    return 0;  
  ```
**ex.4 ** 
	
```
char c;  
ifstream in_file{"../file.txt"};  
if(!in_file){  
    std::cerr << "ERROR file not found \n";  
    return 1;  
}  
while(in_file.get(c)){  
    std::cout << c;  
}  
in_file.close();  
return 0;
```