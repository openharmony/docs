# OpenHarmony C&C++ 安全编程指南

本文档基于C&C++ 语言提供一些安全编程建议，用于指导开发实践。

# 函数

## 对所有外部数据进行合法性校验

**【描述】**
外部数据的来源包括但不限于：网络、用户输入、命令行、文件（包括程序的配置文件）、环境变量、用户态数据（对于内核程序）、进程间通信（包括管道、消息、共享内存、socket、RPC等，特别需要注意的是设备内部不同单板间通讯也属于进程间通信）、API参数、全局变量。

来自程序外部的数据通常被认为是不可信的，在使用这些数据之前，需要进行合法性校验。
如果不对这些外部数据进行校验，将可能导致不可预期的安全风险。

注意：不要使用断言检查外部输入数据，断言应该用于防止不正确的程序假设，而不能用在发布版本上检查程序运行过程中发生的错误。

对来自程序外部的数据要校验处理后才能使用。典型场景包括：

**作为数组索引**
将不可信的数据作为数组索引，可能导致超出数组上限，从而造成非法内存访问。
**作为内存偏移地址**
将不可信数据作为指针偏移访问内存，可能造成非法内存访问，并可以造成进一步的危害，如任意地址读/写。
**作为内存分配的尺寸参数**
使用0长度分配内存可能造成非法内存访问；未限制分配内存大小会造成过度资源消耗。
**作为循环条件**
将不可信数据作为循环限定条件，可能会引发缓冲区溢出、内存越界读/写、死循环等问题。
**作为除数**
可能产生除零错误(被零除)。
**作为命令行参数**
可能产生命令注入漏洞。
**作为数据库查询语句的参数**
可能产生SQL注入漏洞。
**作为输入/输出格式化字符串**
可能产生格式化字符串漏洞。
**作为内存复制长度**
可能造成缓冲区溢出问题。
**作为文件路径**
直接打开不可信路径，可能会导致目录遍历攻击，攻击者操作了无权操作的文件，使得系统被攻击者所控制。

输入校验包括但不局限于：

- API接口参数合法性
- 校验数据长度
- 校验数据范围
- 校验数据类型和格式
- 校验输入只包含可接受的字符（“白名单”形式），尤其需要注意一些特殊情况下的特殊字符。

**外部数据校验原则**

**1.信任边界**

由于外部数据不可信，因此系统在运行过程中，如果数据传输与处理跨越不同的信任边界，为了防止攻击蔓延，必须对来自信任边界外的其他模块的数据进行合法性校验。

（a）so（或者dll）之间

so或dll作为独立的第三方模块，用于对外导出公共的api函数，供其他模块进行函数调用。so/dll无法确定上层调用者是否传递了合法参数，因此so/dll的公共函数需要检查调用者提供参数的合法性。so/dll应该设计成低耦合、高复用性，尽管有些软件的so/dll当前设计成只在本软件中使用，但仍然应该将不同的so/dll模块视为不同的信任边界。

（b）进程与进程之间

为防止通过高权限进程提权，进程与进程之间的IPC通信（包括单板之间的IPC通信、不同主机间的网络通信），应视为不同信任边界。

（c）应用层进程与操作系统内核

操作系统内核具有比应用层更高的权限，内核向应用层提供的接口，应该将来自应用层的数据作为不可信数据处理。

（d）可信执行环境内外环境

为防止攻击蔓延至可信执行环境，TEE、SGX等对外提供的接口，应该将来自外部的数据作为不可信数据处理。

**2.外部数据校验**
外部数据进入到本模块后，必须经过合法性校验才能使用。被校验后的合法数据，在本模块内，后续传递到内部其他子函数，不需要重复校验。

**【反例】**
函数Foo处理外部数据，由于buffer不一定是’\0’结尾， strlen 的返回值 nameLen 有可能超过 len，导致越界读取数据。

```cpp
void Foo(const unsigned char* buffer, size_t len)
{
    // buffer可能为空指针，不保证以'\0'结尾
    const char* s = reinterpret_cast<const char*>(buffer);
    size_t nameLen = strlen(s);
    std::string name(s, nameLen);
    Foo2(name);
    ...
}
```

**【正例】**
对外部参数做合法性校验，本例中使用 strnlen 进行字符串长度计算，缓解读越界风险。

```cpp
void Foo(const unsigned char* buffer, size_t len)
{
    // 必须做参数合法性校验
    if (buffer == nullptr || len == 0 || len >= MAX_BUFFER_LEN) {
        ... // 错误处理
    }

    const char* s = reinterpret_cast<const char*>(buffer);
    size_t nameLen = strnlen(s, len); // 使用strnlen缓解读越界风险
    if (nameLen == len) {
        ... // 错误处理
    }
    std::string name(s, nameLen);
    ...
    Foo2(name);
    ...
}
```

```cpp
namespace ModuleA {
// Foo2 为模块内部函数，约定为由调用者保证参数的合法性
static void Foo2(const std::string& name)
{
    ...
    Bar(name.c_str()); // 调用MODULE_B中的函数
}

// Foo 为模块的外部接口，需要校验参数的合法性
void Foo(const unsigned char* buffer, size_t len)
{
    // 检查空指针、参数合法范围等
    if (buffer == nullptr || len <= sizeof(int)) {
        // 错误处理
        ...
    }

    int nameLen = *(reinterpret_cast<const int*>(buffer)); // 从报文中获取name字符串长度
    // nameLen 是不可信数据，必须检查合法性
    if (nameLen <= 0 || static_cast<size_t>(nameLen) > len - sizeof(int)) {
        // 错误处理
        ...
    }

    std::string name(reinterpret_cast<const char*>(buffer), nameLen);
    Foo2(name); // 调用本模块内内部函数
    ...
}
}
```

以下是使用C语言编写的`MODULE_B`模块中的代码：

```cpp
// Bar 为 MODULE_B 模块的公共函数，
// 其约定为，如果参数name不为nullptr，那么必须是一个具有’\0’结尾的合法字符串并且长度大于0
void Bar(const char* name)
{
    // 必须做参数合法性校验
    if (name == nullptr || name[0] == '\0') {
        // 错误处理
        ...
    }
    size_t nameLen = strlen(name);  // 不需要使用strnlen
    ...
}
```

对于模块A来说， buffer 是外部不可信输入，必须做严格的校验，从 buffer 解析出来的 name，在解析过程中进行了合法性校验，在模块A内部属于合法数据，作为参数传递给内部子函数时不需要再做合法性校验（如果要继续对 name 内容进行解析，那么仍然必须对 name 内容进行校验）。
如果模块A中的 name 继续跨越信任面传递给其他模块（在本例中是直接调用模块B的公共函数，也可以是通过文件、管道、网络等方式），那么对于B模块来说， name 属于不可信数据，必须做合法性校验。

# 类

## 类的成员变量必须显式初始化

**【描述】**
如果没有对类成员变量显示初始化，会使对象处于一种不确定状态。如果类的成员变量具有默认构造函数，那么可以不需要显式初始化。

**【反例】**

```cpp
class Message {
public:
    void Process()
    {
        ...
    }

private:
    uint32_t msgId;                    // 不符合：成员变量没有被初始化
    size_t msgLength;                  // 不符合：成员变量没有被初始化
    unsigned char* msgBuffer;          // 不符合：成员变量没有被初始化
    std::string someIdentifier;        // 默认构造函数仅会初始化该成员
};

Message message;                       // message成员变量没有被完全初始化
message.Process();                     // 后续使用存在隐患
```

**【正例】**
一种做法是在类成员变量声明时显示初始化。

```cpp
class Message {
public:
    void Process()
    {
        ...
    }

private:
    uint32_t msgId{0};
    size_t msgLength{0};
    unsigned char* msgBuffer{nullptr};
    std::string someIdentifier;        // 具有默认构造函数，不需要显式初始化
};
```

另一种做法是使用构造函数初始化列表初始化。

```cpp
class Message {
public:
    Message() : msgId(0), msgLength(0), msgBuffer(nullptr) {}
    void Process()
    {
        ...
    }

private:
    uint32_t msgId;
    size_t msgLength;
    unsigned char* msgBuffer;
    std::string someIdentifier;        // 具有默认构造函数，不需要显式初始化
};
```

## 明确需要实现哪些特殊成员函数

**【描述】**
**三之法则（Rule of three）：**
若某个类需要用户定义的析构函数、用户定义的拷贝构造函或拷贝赋值操作符，则它基本三者全部都需要。

```cpp
class Foo {
public:
    Foo(const char* buffer, size_t size) { Init(buffer, size); }
    Foo(const Foo& other) { Init(other.buf, other.size); }

    Foo& operator=(const Foo& other)
    {
        Foo tmp(other);
        Swap(tmp);
        return *this;
    }

    ~Foo() { delete[] buf; }

    void Swap(Foo& other) noexcept
    {
        using std::swap;
        swap(buf, other.buf);
        swap(size, other.size);
    }

private:
    void Init(const char* buffer, size_t size)
    {
        this->buf = new char[size];
        memcpy(this->buf, buffer, size);
        this->size = size;
    }

    char* buf;
    size_t size;
};
```

如果类对某种资源进行管理，而资源句柄是非类类型的对象（裸指针、文件描述符等），则这些隐式定义的成员函数通常都不正确，其析构函数不做任何事，而拷贝构造函数/拷贝赋值操作符则进行“浅拷贝”。

通过可复制句柄来管理不可复制资源的类，可能必须将其拷贝赋值和拷贝构造函数声明为私有的并且不提供其定义，或将它们定义为delete的。

**五之法则（Rule of five）：**
如果定义了析构函数、拷贝构造函数或拷贝赋值操作符，会阻止移动构造函数和移动赋值操作符的隐式定义，所以任何想要移动语义的类必须声明全部五个特殊成员函数。

```cpp
class Foo {
public:
    Foo(const char* buffer, size_t size) { Init(buffer, size); }
    Foo(const Foo& other) { Init(other.buf, other.size); }

    Foo& operator=(const Foo& other)
    {
        Foo tmp(other);
        Swap(tmp);
        return *this;
    }

    Foo(Foo&& other) noexcept : buf(std::move(other.buf)), size(std::move(other.size))
    {
        other.buf = nullptr;
        other.size = 0;
    }

    Foo& operator=(Foo&& other) noexcept
    {
        Foo tmp(std::move(other));
        Swap(tmp);
        return *this;
    }

    ~Foo() { delete[] buf; }

    void Swap(Foo& other) noexcept
    {
        using std::swap;
        swap(buf, other.buf);
        swap(size, other.size);
    }

private:
    void Init(const char* buffer, size_t size)
    {
        this->buf = new char[size];
        memcpy(this->buf, buffer, size);
        this->size = size;
    }

    char* buf;
    size_t size;
};
```

但是如果不提供移动构造函数和移动赋值操作符通常不会发生错误，但会导致失去优化机会。

**零之法则（Rule of zero）：**
如果类不需要专门处理资源的所有权，那么就不应该有自定义的析构函数、拷贝/移动构造函数或拷贝/移动赋值操作符。

```cpp
class Foo {
public:
    Foo(const std::string& text) : text(text) {}

private:
    std::string text;
};
```

只要声明了拷贝构造函数、拷贝赋值操作符或析构函数，编译器将不会隐式生成移动构造函数和移动赋值操作符，导致该类的移动操作都变成了代价更高的复制操作。
只要声明了移动构造函数或移动赋值操作符，编译器会将隐式生成的拷贝构造函数或拷贝赋值操作符定义为delete的，导致改类只能被移动、不能被复制。
因此，只要声明了其中的任何一个函数，就应当声明其他全部函数，避免出现非预期的结果。

类似地，如果基类需要定义public的虚析构函数，那么需要显示定义全部相关的特殊成员函数:

```cpp
class Base {
public:
    ...
    Base(const Base&) = default;
    Base& operator=(const Base&) = default;
    Base(Base&&) = default;
    Base& operator=(Base&&) = default;
    virtual ~Base() = default;
    ...
};
```

但是，如果基类声明了拷贝构造/拷贝赋值操作符，可能会发生切片，所以经常会将基类中的拷贝构造/拷贝赋值操作符显式定义为delete, 并且同时将其他的特殊成员函数也显式定义为delete：

```cpp
class Base {
public:
    ...
    Base(const Base&) = delete;
    Base& operator=(const Base&) = delete;
    Base(Base&&) = delete;
    Base& operator=(Base&&) = delete;
    virtual ~Base() = default;
    ...
};
```

## 基类中的拷贝构造函数、拷贝赋值操作符、移动构造函数、移动赋值操作符必须为非public函数或者为delete函数

**【描述】**
如果把一个派生类对象直接赋值给基类对象，会发生切片，只拷贝或者移动了基类部分，损害了多态行为。

**【反例】**
如下代码中，基类的拷贝构造函数和拷贝赋值操作符为default，如果派生类对象赋值给基类对象时会发生切片。
可以将此例中的拷贝构造函数和拷贝赋值操作符声明为delete，编译器可检查出此类赋值行为。

```cpp
class Base {
public:
    Base() = default;
    Base(const Base&) = default;
    Base& operator=(const Base&) = default;
    ...
    virtual void Fun() { std::cout << "Base" << std::endl; }
};

class Derived : public Base {
    ...
    void Fun() override { std::cout << "Derived" << std::endl; }
};

void Foo(const Base& base)
{
    Base other = base;    // 不符合：发生切片
    other.Fun();          // 调用的是Base类的Fun函数
}
Derived d;
Foo(d);
```

## 在移动构造函数和移动赋值操作符中必须将源对象的资源正确重置

**【描述】**
移动构造函数和移动赋值操作符将资源的所有权从一个对象移动到另外一个资源。一旦资源被移动，则应将源对象的资源正确重置。这样可以防止源对象在析构函数中释放了被移动的资源。

在被移动的对象中允许保留部分非资源相关数据，但必须保证被移动的对象处于可被正常析构的状态。
因此，当一个对象被move以后，除非该对象处于明确指定的状态，否则不要依赖已move对象的值，否则可能产生非预期行为。

**【反例】**

```cpp
class Foo {
public:
    ...
    Foo(Foo&& foo) noexcept : data(foo.data)
    {
    }

    Foo& operator=(Foo&& foo)
    {
        data = foo.data;
        return *this;
    }

    ~Foo()
    {
        delete[] data;
    }

private:
    char* data = nullptr;
};
```

上述Foo的移动构造函数和移动赋值操作符没有正确将源对象的资源重置，源对象析构的时候会将资源释放，导致新创建的对象中接管的资源成为无效资源。

**【正例】**

```cpp
class Foo {
public:
    ...
    Foo(Foo&& foo) noexcept : data(foo.data)
    {
        foo.data = nullptr;
    }

    Foo& operator=(Foo&& foo)
    {
        if (this == &foo) {
            return *this;
        }
        delete[] data;
        data = foo.data;
        foo.data = nullptr;
        return *this;
    }

    ~Foo()
    {
        delete[] data;
    }

private:
    char* data = nullptr;
};
```

此外，不要依赖已经被move对象的值。
某些标准库std::string的实现可能对短字节做优化，在实现移动语义时可能不会修改被移动字符串的内容，导致如下代码输出不一定是预期的b， 有可能输出为ab，存在兼容性问题。

```cpp
std::string str{"a"};
std::string other = std::move(str);

str.append(1, 'b');
std::cout << str << std::endl;
```

## 通过基类指针释放派生类时，必须将基类中析构函数声明为虚函数

**【描述】**
只有基类析构函数是虚函数时，才能保证通过多态调用的时候调用到派生类的析构函数。
如果没有将基类的析构函数声明为虚函数，当通过基类指针释放派生类时，只会调用基类的析构函数，不会调用派生类的析构函数，导致内存泄漏。

**【反例】**
没有将基类的析构函数声明为虚函数，导致了内存泄漏。

```cpp
class Base {
public:
    Base() = default;
    ~Base() { std::cout << "~Base" << std::endl; }
    virtual std::string GetVersion() = 0;
};
class Derived : public Base {
public:
    Derived()
    {
        const size_t numberCount = 100;
        numbers = new int[numberCount];
    }

    ~Derived()
    {
        delete[] numbers;
        std::cout << "~Derived" << std::endl;
    }

    std::string GetVersion()
    {
        return std::string("hello!");
    }

private:
    int* numbers;
};
void Foo()
{
    Base* base = new Derived();
    delete base;                // 调用的是 Base 的析构函数，造成资源泄漏
}
```

## 对象赋值或初始化避免切片操作

**【描述】**

将派生类对象按值赋值给基类对象时会发生切片，损害了多态行为。

如果确实需要将对象切片处理，建议定义一个显式操作完成这个功能，以避免理解错误，增加可维护性。

**【反例】**

```cpp
class Base {
     virtual void Fun();
};

class Derived : public Base {
    ...
};
void Foo(const Base& base)
{
    Base other = base;        // 不符合：发生切片
    other.Fun();              // 调用的是Base类的Fun函数
}
Derived d;
Base b{d};                    // 不符合：仅构造了Base部分
b = d;                        // 不符合：仅赋值Base部分

Foo(d);
```

# 表达式与语句

## 确保对象在使用之前已被初始化

**【描述】**
本条款中的“初始化”指的是通过定义时显示初始化、默认构造初始化、赋值等方式使对象拥有期望的值。
读取一个未初始化的值时，程序可能产生未定义行为，因此需要确保对象在使用之前已被初始化。

**【反例】**

```cpp
void Bar(int data);
...
void Foo()
{
    int data;
    Bar(data); // 不符合：未初始化就使用  
    ...
}
```

如果有不同分支，要确保所有分支都得到初始化后才能使用。

```cpp
void Bar(int data);
...
void Foo(int condition)
{
    int data;
    if (condition > 0) {
        data = CUSTOMIZED_SIZE;
    }
    Bar(data);      // 不符合：部分分支该值未初始化  
    ...
}
```

**【正例】**

```cpp
void Bar(int data);
...
void Foo()
{
    int data{0};    // 符合：显示初始化
    Bar(data);
    ...
}
void InitData(int& data);
...
void Foo()
{
    int data; 
    InitData(data); // 符合：通过函数初始化
    ...
}
std::string data;   // 符合：默认构造函数初始化
...
```

## 避免使用reinterpret_cast

**【描述】**
`reinterpret_cast`用于转换不相关类型。尝试用`reinterpret_cast`将一种类型强制转换另一种类型，这破坏了类型的安全性与可靠性，是一种不安全的转换。不同类型之间尽量避免转换。

## 避免使用const_cast

**【描述】**
`const_cast`用于移除对象的`const`和`volatile`性质。

使用const_cast转换后的指针或者引用来修改const对象或volatile对象，程序会产生未定义行为。

**【反例】**

```cpp
const int i = 1024; 
int* p = const_cast<int*>(&i);
*p = 2048;                              // 未定义行为
class Foo {
public:
    void SetValue(int v) { value = v; }

private:
    int value{0};
};

int main()
{
    const Foo foo;
    Foo* p = const_cast<Foo*>(&foo);
    p->SetValue(2);                     // 未定义行为
    return 0;
}
```

## 确保有符号整数运算不溢出

**【描述】**
在C++标准中，有符号整数溢出会使程序产生未定义行为。
因此，不同的实现可以自由处理有符号整数溢出。例如：在将有符号整数类型定义为模数的实现中，编译器可以不检测整数溢出。

使用溢出后的数值可能导致程序缓冲区读写越界等风险。出于安全考虑，对外部数据中的有符号整数值在如下场景中使用时，需要确保运算不会导致溢出：

- 指针运算的整数操作数(指针偏移值)
- 数组索引
- 变长数组的长度(及长度运算表达式)
- 内存复制长度
- 内存分配函数的参数
- 循环判断条件

在精度低于int的整数类型上进行运算时，需要考虑整数提升。程序员还需要掌握整数转换规则，包括隐式转换规则，以便设计安全的算术运算。

**【反例】**
如下代码示例中，参与减法运算的整数是外部数据，在使用前未做校验，可能出现整数溢出，进而造成后续的内存复制操作出现缓冲区溢出。

```cpp
unsigned char* content = ... // 指向报文头的指针
size_t contentSize = ...     // 缓冲区的总长度
int totalLen = ...           // 报文总长度
int skipLen = ...            // 从消息中解析出来的需要忽略的数据长度

std::vector<unsigned char> dest;

// 用 totalLen - skipLen 计算剩余数据长度，可能出现整数溢出
std::copy_n(&content[skipLen], totalLen - skipLen, std::back_inserter(dest));
...
```

**【正例】**
如下代码示例中，重构为使用`size_t`类型的变量表示数据长度，并校验外部数据长度是否在合法范围内。

```cpp
unsigned char* content = ... //指向报文头的指针
size_t contentSize = ...     // 缓冲区的总长度
size_t totalLen = ...        // 报文总长度
size_t skipLen = ...         // 从消息中解析出来的需要忽略的数据长度

if (skipLen >= totalLen || totalLen > contentSize) {
    ... // 错误处理
}

std::vector<unsigned char> dest;
std::copy_n(&content[skipLen], totalLen - skipLen, std::back_inserter(dest));
...
```

**【反例】**
如下代码示例中，对来自外部数据的数值范围做了校验，但是由于second是`int`类型，而校验条件中错误的使用了`std::numeric_limits<unsigned long>::max()`进行限制，导致整数溢出。

```cpp
int second = ... // 来自外部数据

 // 错误的使用了unsigned long的取值范围做上限校验
if (second < 0 || second > (std::numeric_limits<unsigned long>::max() / 1000)) {
    return -1;
}
int millisecond = second * 1000; // 可能出现整数溢出
...
```

**【正例】**
一种改进方案是将second的类型修改为`unsigned long`类型，这种方案适用于修改了变量类型更符合业务逻辑的场景。

```cpp
unsigned long second = ... // 将类型重构为 unsigned long 类型

if (second > (std::numeric_limits<unsigned long>::max() / 1000)) {
    return -1;
}
int millisecond = second * 1000;
...
```

另一种改进方案是将数值上限修改为`std::numeric_limits<int>::max()`。

```cpp
int second = ... // 来自外部数据

if (second < 0 || second > (std::numeric_limits<int>::max() / 1000)) {
    return -1;
}
int millisecond = second * 1000;
```

**【影响】**
整数溢出可能导致程序缓冲区溢出以及执行任意代码。

## 确保无符号整数运算不回绕

**【描述】**
无符号整数的算术运算结果可能会发生整数回绕，使用回绕后的数值其可能导致程序缓冲区读写越界等风险。
出于安全考虑，对外部数据中的无符号整数值在如下场景中使用时，需要确保运算不会导致回绕：

- 指针偏移值（指针算术运算的整数操作数）
- 数组索引值
- 内存拷贝的长度
- 内存分配函数的参数
- 循环判断条件

**【反例】**
如下代码示例中，校验下一个子报文的长度加上已处理报文的长度是否超过了整体报文的最大长度，在校验条件中的加法运算可能会出现整数回绕，造成绕过该校验的问题。

```cpp
size_t totalLen = ...              // 报文的总长度
size_t readLen = 0;                // 记录已经处理报文的长度
...
size_t pktLen = ParsePktLen();     // 从网络报文中解析出来的下一个子报文的长度
if (readLen + pktLen > totalLen) { // 可能出现整数回绕
  ... // 错误处理
}
...
readLen += pktLen;
...
```

**【正例】**
由于readLen变量记录的是已经处理报文的长度，必然会小于totalLen，因此将代码中的加法运算修改为减法运算，不会导致条件绕过。

```cpp
size_t totalLen = ... // 报文的总长度
size_t readLen = 0;   // 记录已经处理报文的长度
...
size_t pktLen = ParsePktLen(); // 来自网络报文
if (pktLen > totalLen - readLen) {
  ... // 错误处理
}
...
readLen += pktLen;
...
```

**【反例】**
如下代码示例中，校验len合法范围的运算可能会出现整数回绕，导致条件绕过。

```cpp
size_t len = ... // 来自用户态输入

if (SCTP_SIZE_MAX - len < sizeof(SctpAuthBytes)) { // 减法操作可能出现整数回绕
    ... // 错误处理
}
... = kmalloc(sizeof(SctpAuthBytes) + len, gfp);   // 可能出现整数回绕
...
```

**【正例】**
如下代码示例中，调整减法运算的位置（需要确保在编译期间减法表达式的值不回绕），避免整数回绕问题。

```cpp
size_t len = ... // 来自用户态输入

if (len > SCTP_SIZE_MAX - sizeof(SctpAuthBytes)) { // 确保在编译期间减法表达式的值不翻转
    ... // 错误处理
}
... = kmalloc(sizeof(SctpAuthBytes) + len, gfp);
...
```

**【例外】**
为正确执行程序，必要时无符号整数可能表现出模态（回绕）。建议将变量声明明确注释为支持模数行为，并且对该整数的每个操作也应明确注释为支持模数行为。

**【影响】**
整数回绕可能导致程序缓冲区溢出以及执行任意代码。

## 确保除法和余数运算不会导致除零错误(被零除)

**【描述】**
整数的除法运算或取余运算的除数为0会导致程序产生未定义的行为。如果涉及到除法或者取余运算，必须确保除数不为0。

在二进制浮点数算数标准ISO/IEEE Std 754-1985中规定了浮点数被零除的行为及结果，但是仍然取决于程序所运行的软硬件环境是否遵循该标准。
因此，在做浮点数被零除的运算前，应确保软硬件环境已遵循二进制浮点数算数标准，否则仍然存在未定义行为。

**【反例】**

```c
size_t a = ReadSize();  // 来自外部数据
size_t b = 1000 / a;    // 不符合：a可能是0
size_t c = 1000 % a;    // 不符合：a可能是0
...
```

**【正例】**
如下代码示例中，添加a是否为0的校验，防止除零错误。

```c
size_t a = ReadSize();  // 来自外部数据
if (a == 0) {
    ... // 错误处理
}
size_t b = 1000 / a;    // 符合：确保a不为0
size_t c = 1000 % a;    // 符合：确保a不为0
...
```

**【影响】**
除零错误可能导致拒绝服务。

## 只能对无符号整数进行位运算

**【描述】**
对有符号整数进行位运算时可能产生未定义行为，本条款要求只能对无符号整数进行位运算，避免出现未定义行为。
此外，对精度低于int类型的无符号整数进行位运算时，编译器会进行整数提升，再对提升后的整数进行位运算，因此要特别注意对于这类无符号整数的位运算，避免出现非预期的结果。
本条款涉及的位操作符包括：

- `~`（求反）
- `&`（与）
- `|`（或）
- `^`（异或）
- `>>`（右移位）
- `<<`（左移位）
- `&=`
- `^=`
- `|=`
- `>>=`
- `<<=`

在C++20中有符号整数的移位操作具有良好的定义，可以对有符号整数进行移位运算。

**【反例】**
在C++20之前，如下代码中的右移操作`data >> 24`可以实现为算术（有符号）移位或逻辑（无符号）移位；在左移操作`value << data`中，如果value为负数或者左移后的结果超出其整数提升后类型的表示范围，会导致程序产生未定义行为。

```cpp
int32_t data = ReadByte();
int32_t value = data >> 24;   // 对有符号整数进行右移运算，其结果是实现定义的

... // 检查 data 的合法范围

int32_t mask = value << data; // 对有符号整数进行左移运算，程序可能产生未定义行为
```

**【正例】**

```cpp
uint32_t data = static_cast<uint32_t>(ReadByte());
uint32_t value = data >> 24;  // 只对无符号整数进行位运算

... // 检查 data 的合法范围

uint32_t mask  = value << data;
```

对于精度低于`int`的无符号整数进行位运算，由于整数提升，其结果可能是非预期的，应将操作结果立即转换为期望的类型, 避免因整数提升而导致非预期结果。

**【反例】**

```cpp
uint8_t mask = 1;
uint8_t value = (~mask) >> 4; // 不符合：~运算的结果会包含高位数据，可能不符合预期
```

**【正例】**

```cpp
uint8_t mask = 1;
uint8_t value = (static_cast<uint8_t>(~mask)) >> 4; // 符合：~运算后立即转换为期望的类型
```

**【例外】**

- 作为位标志使用的有符号整数常量或枚举值，可以作为 & 和 | 操作符的操作数。

```cpp
int fd = open(fileName, O_CREAT | O_EXCL, S_IRWXU | S_IRUSR);
```

- 一个在编译时就可以确定的有符号正整数，可以作为移位操作符的右操作数。

```cpp
constexpr int SHIFT_BITS = 3;
...
uint32_t id = ...;
uint32_t type = id >> SHIFT_BITS;
```

# 资源管理

## 外部数据作为数组索引或者内存操作长度时，需要校验其合法性

**【描述】**
外部数据作为数组索引对内存进行访问时，必须对数据的大小进行严格的校验，确保数组索引在有效范围内，否则会导致严重的错误。
将数据复制到容量不足以容纳该数据的内存中会导致缓冲区溢出。为了防止此类错误，必须根据目标容量的大小限制被复制的数据大小，或者必须确保目标容量足够大以容纳要复制的数据。

**【反例】**
如下代码示例中，SetDevId()函数存在差一错误，当 index 等于 `DEV_NUM` 时，恰好越界写一个元素。

```cpp
struct Dev {
    int id;
    char name[MAX_NAME_LEN];
};

static Dev devs[DEV_NUM];

int SetDevId(size_t index, int id)
{
    if (index > DEV_NUM) {         // 存在差一错误
        ... // 错误处理  
    }

    devs[index].id = id;
    return 0;
}
```

**【正例】**
如下代码示例中，修改校验索引的条件，避免差一错误。

```cpp
struct Dev {
    int id;
    char name[MAX_NAME_LEN];
};

static Dev devs[DEV_NUM];

int SetDevId(size_t index, int id)
{
    if (index >= DEV_NUM) {
        ... // 错误处理  
    }
    devs[index].id = id;
    return 0;
}
```

**【反例】**
外部输入的数据不一定会直接作为内存复制长度使用，还可能会间接参与内存复制操作。
如下代码示例中，inputTable.count来自设备外部报文，虽然没有直接作为内存复制长度使用，而是作为for循环体的上限使用，间接参与了内存复制操作。由于没有校验其大小，可造成缓冲区溢出：

```cpp
struct ValueTable {  
    size_t count;  
    int val[MAX_NUMBERS];  
};

void ValueTableDup(const ValueTable& inputTable)  
{  
    ValueTable outputTable = {0, {0}};
    ...  
    for (size_t i = 0; i < inputTable.count; i++) {  
        outputTable.val[i] = inputTable.val[i];  
    }  
    ...  
}  
```

**【正例】**
如下代码示例中，对inputTable.count做了校验。

```cpp
struct ValueTable {  
    size_t count;  
    int val[MAX_NUMBERS];  
};

void ValueTableDup(const ValueTable& inputTable)  
{  
    ValueTable outputTable = {0, {0}};  
    ...  
    // 根据业务场景，对来自外部报文的循环长度inputTable.count
    // 与outputTable.val数组大小做校验，避免造成缓冲区溢出
    if (inputTable->count >
        sizeof(outputTable.val) / sizeof(outputTable.val[0])) {
        ... // 错误处理
    }
    for (size_t i = 0; i < inputTable.count; i++) {  
        outputTable.val[i] = inputTable.val[i];  
    }  
    ...  
}  
```

**【影响】**
如果复制数据的长度是外部可控的，则复制数据的过程中可能出现缓冲区溢出，在某些情况下可以造成任意代码执行漏洞。

## 内存申请前，必须对申请内存大小进行合法性校验

**【描述】**
当申请内存大小由程序外部输入时，内存申请前，要求对申请内存大小进行合法性校验，防止申请0长度内存，或者过多地、非法地申请内存。
因为内存的资源是有限的，是可以被耗尽的。当申请内存的数值过大（可能一次就申请了非常大的超预期的内存；也可能循环中多次申请内存），很可能会造成非预期的资源耗尽。
大小不正确的参数、不当的范围检查、整数溢出或者截断都可能造成实际分配的缓冲区不符合预期。如果申请内存受攻击者控制，还可能会发生缓冲区溢出等安全问题。

**【反例】**
如下代码示例中，将动态分配size大小的内存。但是未对size做合法性校验。

```c
// 这里的size在传入DoSomething()函数之前还未做过合法性校验  
int DoSomething(size_t size)
{
    ...
    char* buffer = new char[size]; // 本函数内，size使用前未做校验  
    ...
    delete[] buffer;
}
```

**【正例】**
如下代码示例中，动态分配size大小的内存前，进行了符合程序需要的合法性校验。

```c
// 这里的size在传入DoSomething()函数之前还未做过合法性校验  
int DoSomething(size_t size)
{
    // 本函数内，对size做合法性校验，FOO_MAX_LEN被定义为符合程序设计预期的最大内存空间
    if (size == 0 || size > FOO_MAX_LEN) {
        ... // 错误处理  
    }
    char* buffer = new char[size];
    ...
    delete[] buffer;
}
```

**【影响】**
如果申请内存的大小是外部可控的，可能导致资源耗尽，造成拒绝服务。

## 在传递数组参数时，不应单独传递指针

**【描述】**
当函数参数类型为数组（不是数组的引用）或者指针时，若调用者传入数组，则在参数传递时数组会退化为指针，其数组长度信息会丢失，容易引发越界读写等问题。
如果函数只接收固定长度的数组为参数，可以定义参数类型为数组引用或者`std::array`。
如果函数接受的是不带长度的指针，那么应该把长度作为另外一个参数也传递进去。

**【反例】**

```cpp
constexpr int MAX_LEN = 1024;
constexpr int SIZE = 10;

void UseArr(int arr[])
{
    for (int i = 0; i < MAX_LEN; i++) {
        std::cout << arr[i] << std::endl;
    }
}

void Test()
{
    int arr[SIZE] = {0};
    UseArr(arr);
}
```

**【正例】**

可以把指针和长度合起来做成一个类型，方便使用。例如：类似下面的简单封装：

```cpp
template <typename T>
class Slice {
public:
    template <size_t N>
    Slice(T (&arr)[N]) : data(arr), len(N) {}

    template <size_t N>
    Slice(std::array<T, N> arr) : data(arr.data()), len(N) {}

    Slice(T* arr, size_t n) : data(arr), len(n) {}
    ...

private:
    T* data;
    size_t len;
};

void UseArr(Slice<int> arr)
{
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << std::endl;
    }
}

constexpr int SIZE = 10;

void Test()
{ 
    int arr[SIZE] = {0};
    Slice<int> s{arr};
    UseArr(s);
}
```

如果项目允许的话，推荐使用成熟的库来做这个事情，例如C++20中的`std::span`类型。

在不使用这些工具类的情况下，可以把指针和长度作为两个参数传递。

```cpp
void UseArr(int arr[], size_t len)
{
    for (int i = 0; i < len; i++) {
        std::cout << arr[i] << std::endl;
    }
}

constexpr int SIZE = 10;

void Test()
{
    int arr[SIZE] = {0};
    UseArr(arr, sizeof(arr));
}
```

## 当lambda会逃逸出函数外面时，禁止按引用捕获局部变量

**【描述】**
如果一个 lambda 不止在局部范围内使用，禁止按引用捕获局部变量，比如它被传递到了函数的外部，或者被传递给了其他线程的时候。lambda按引用捕获就是把局部对象的引用存储起来。如果 lambda 的生命周期会超过局部变量生命周期，则可能导致内存不安全。

**【反例】**

```cpp
void Foo()
{
    int local = 0;
    // 按引用捕获 local，当函数返回后，local 不再存在，因此 Process() 的行为未定义
    threadPool.QueueWork([&] { Process(local); });
}
```

**【正例】**

```cpp
void Foo()
{
    int local = 0;
    // 按值捕获 local, 在Process() 调用过程中，local 总是有效的
    threadPool.QueueWork([local] { Process(local); });
}
```

## 指向资源句柄或描述符的变量，在资源释放后立即赋予新值

**【描述】**
指向资源句柄或描述符的变量包括指针、文件描述符、socket描述符以及其他指向资源的变量。
以指针为例，当指针成功申请了一段内存之后，在这段内存释放以后，如果其指针未立即设置为nullptr，也未分配一个新的对象，那这个指针就是一个悬空指针。
如果再对悬空指针操作，可能会发生重复释放或访问已释放内存的问题，造成安全漏洞。
消减该漏洞的有效方法是将释放后的指针立即设置为一个确定的新值，例如设置为nullptr。对于全局性的资源句柄或描述符，在资源释放后，应该马上设置新值，以避免使用其已释放的无效值；对于只在单个函数内使用的资源句柄或描述符，应确保资源释放后其无效值不被再次使用。

**【反例】**
如下代码示例中，根据消息类型处理消息，处理完后释放掉body指向的内存，但是释放后未将指针设置为nullptr。如果还有其他函数再次处理该消息结构体时，可能出现重复释放内存或访问已释放内存的问题。

```c
int Fun()
{
    SomeStruct *msg = nullptr;

    ... // 使用new分配msg、msg->body的内存空间并初始化msg

    if (msg->type == MESSAGE_A) {
        ...
        delete msg->body;         // 不符合：释放内存后，未置空
    }

    ...

    // 将msg存入全局队列，后续可能使用已释放的body成员
    if (!InsertMsgToQueue(msg)) {
        delete msg->body;         // 可能再次释放了body的内存
        delete msg;
        return -1;
    }
    return 0;
}
```

**【正例】**
如下代码示例中，立即对释放后的指针设置为nullptr，避免重复释放指针。

```c
int Fun()
{
    SomeStruct *msg = nullptr;

    ... // 使用new分配msg、msg->body的内存空间并初始化msg

    if (msg->type == MESSAGE_A) {
        ...
        delete msg->body;
        msg->body = nullptr;
    }

    ... 

    // 将msg存入全局队列
    if (!InsertMsgToQueue(msg)) {
        delete msg->body;         // 马上离开作用域，不必赋值 nullptr
        delete msg;               // 马上离开作用域，不必赋值 nullptr
        return -1;
    }
    return 0;
}
```

默认的内存释放函数针对空指针不执行任何动作。

**【反例】**
如下代码示例中文件描述符关闭后未赋新值。

```c
SOCKET s = INVALID_SOCKET;
int fd = -1;
...
closesocket(s);
...
close(fd);
...
```

**【正例】**
如下代码示例中，在资源释放后，对应的变量应该立即赋予新值。

```c
SOCKET s = INVALID_SOCKET;
int fd = -1;
...
closesocket(s);
s = INVALID_SOCKET;
...
close(fd);
fd = -1;
...
```

**【影响】**
再次使用已经释放的内存，或者再次释放已经释放的内存，或其他使用已释放资源的行为，可能导致拒绝服务或执行任意代码。

## new和delete配对使用，new[]和delete[]配对使用

**【描述】**
使用 new 操作符创造的对象，只能使用 delete 操作符来销毁。
使用 new[] 创造的对象数组只能由 delete[] 操作符来销毁。

**【反例】**

```cpp
class C {
public:
    C(size_t len) : arr(new int[len]) {}
    ~C()
    {
        delete arr; // 此处应该是 delete[] arr;
    }

private:
    int* arr;
};
```

**【正例】**

```cpp
class C {
public:
    C(size_t len) : arr(new int[len]) {}
    ~C() { delete[] arr; }

private:
    int* arr;
};
```

## 自定义new/delete操作符需要配对定义，且行为与被替换的操作符一致

**【描述】**
自定义操作符的时候，new 和 delete 要配对定义，new[] 和 delete[] 要配对定义。
自定义 new/delete 操作符的行为要与被替换的 new/delete 的行为一致。

**【反例】**

```cpp
// 如果自定义了 operator new，必须同时自定义对应的 operator delete
struct S {
    static void* operator new(size_t sz)
    {
        ... // 自定义操作
        return ::operator new(sz);
    }
};
```

**【正例】**

```cpp
struct S {
    static void* operator new(size_t sz)
    {
        ... // 自定义操作
        return ::operator new(sz);
    }
    static void operator delete(void* ptr, size_t sz)
    {
        ... // 自定义操作
        ::operator delete(ptr);
    }
};
```

默认的 new 操作符在内存分配失败时，会抛出`std::bad_alloc`异常，而使用了`std::nothrow`参数的 new 操作符在内存分配失败时，会返回 nullptr。
自定义的 new/delete 操作符要和内置的操作符行为保持一致。

**【反例】**

```cpp
// 在内存管理模块头文件中声明的函数
extern void* AllocMemory(size_t size);   // 分配失败返回 nullptr
void* operator new(size_t size)
{
    return AllocMemory(size);
}
```

**【正例】**

```cpp
// 在内存管理模块头文件中声明的函数
extern void* AllocMemory(size_t size);   // 分配失败返回 nullptr
void* operator new(size_t size)
{
    void* ret = AllocMemory(size);
    if (ret != nullptr) {
        return ret;
    }
    throw std::bad_alloc();              // 分配失败抛出异常
}

void* operator new(size_t size, const std::nothrow_t& tag)
{
    return AllocMemory(size);
}
```

# 错误处理

## 抛异常时，抛对象本身，而不是指向对象的指针

**【描述】**
C++中推荐的抛异常方式是抛对象本身，而不是指向对象的指针。

用throw语句抛出异常的时候，会构造一个临时对象，称为“异常对象（exception object）”。这个异常对象的生命周期在C++语言中很明确：异常对象在throw时被构造；在某个捕获它的catch语句以`throw`以外的方式结束（即没有重新抛出）时，或者指向这个异常的`std::exception_ptr`对象被析构时析构。

抛出指针，会使回收被抛出对象的责任不明确。捕获异常的地方是否有义务对该指针进行`delete`操作，取决于该对象是如何分配的（例如静态变量，或者用`new`分配），以及这个对象是否被共享了。但是指针类型本身并不能表明这个对象的生命周期以及所有权，也就无法判断是否应该`delete`。如果应该`delete`却没有做，会造成内存泄露；如果不该`delete`却做了，会造成重复释放。

**【反例】**

不要抛指针。

```cpp
static SomeException exc1("reason 1");

try {
    if (SomeFunction()) {
        throw &exc1;                         // 不符合：这是静态对象的指针，不应该delete
    } else {
        throw new SomeException("reason 2"); // 不符合：这是动态分配的，应该delete
    }
} catch (const SomeException* e) {
    delete e;                                // 不符合：这里不能确定是否需要delete
}
```

**【正例】**

永远抛异常对象本身。

```cpp
try {
    if (SomeFunction()) {
        throw SomeException("reason 1");
    } else {
        throw SomeException("reason 2");
    }
} catch (const SomeException& e) {
    ...                                      // 符合：这里可以确定不需要delete
}
```

## 禁止从析构函数中抛出异常

**【描述】**

析构函数默认自带`noexcept`属性，如果析构函数抛出异常，会直接导致`std::terminate`。自C++11起，允许析构函数被标记为`noexcept(false)`，但即便如此，如果析构函数在stack unwinding的过程中被调用（例如另一个异常抛出，导致栈上的局部变量被析构），结果也是`std::terminate`，而析构函数最大的作用就是在不论正常返回还是抛出异常的情况下都能清理局部变量。因此，让析构函数抛出异常一般都是不好的。

# 标准库

## 禁止从空指针创建std::string

**【描述】**
将空指针传递给std::string构造函数，会解引用空指针，从而导致程序产生未定义行为。

**【反例】**

```cpp
void Foo()
{
    const char* path = std::getenv("PATH");
    std::string str(path);                  // 错误：这里没有判断getenv的返回值是否为nullptr
    std::cout << str << std::endl;
}
```

**【正例】**

```cpp
void Foo()
{
    const char* path = std::getenv("PATH");
    if (path == nullptr) {
        ... // 报告错误
        return;
    }
    std::string str(path);
    ...
    std::cout << str << std::endl;
}
void Foo()
{
    const char* path = std::getenv("PATH");
    std::string str(path == nullptr ? path : "");
    ... // 判断空字符串
    std::cout << str << std::endl;                // 必要时判断空字符串
}
```

## 不要保存std::string类型的c_str和data成员函数返回的指针

**【描述】**
为保证调用std::string对象的c_str()和data()成员函数返回的引用值结果的有效性，不应保存std::string类型的c_str()和data()的结果，而是在每次需要时直接调用（调用的开销会被编译器内联优化）。否则，当调用此std::string对象的修改方法修改对象后，或超出std::string对象作用域时，之前存储的指针将会失效。使用失效的指针将导致未定义行为。

**【反例】**

```cpp
void Bar(const char*  data)
{
    ...
}

void Foo1()
{
    std::string name{"demo"};
    const char* text = name.c_str();          // 表达式结束以后，name的生命周期还在，指针有效

    // 如果中间调用了std::string的非const成员函数，导致name被修改，例如operator[], begin()等，
    // 可能会导致text的内容不可用，或者不是原来的字符串
    name = "test";
    name[1] = '2';
    ...
    Bar(text);                                // 此处text已不再指向合法内存空间
}

void Foo2()
{
    std::string name{"demo"};
    std::string test{"test"};
    const char* text = (name + test).c_str(); // 表达式结束以后，+号产生的临时对象被销毁
    ...
    Bar(text);                                // 此处text已不再指向合法内存空间
}

void Foo3(std::string& s)
{
    const char* data = s.data();
    ...
    s.replace(0, 3, "***");
    ...
    Bar(data);                                // 此处text已不再指向合法内存空间
}
```

**【正例】**

```cpp
void Foo1()
{
    std::string name{"demo"};

    name = "test";
    name[1] = '2';
    ...
    Bar(name.c_str());
}

void Foo2()
{
    std::string name{"demo"};
    std::string test{"test"};
    name += test;
    ...
    Bar(name.c_str());
}

void Foo3(std::string& s)
{
    ...
    s.replace(0, 3, "***");
    ...
    Bar(s.data());
}
```

**【例外】**
在少数对性能要求非常高的代码中，为了适配已有的只接受`const char*`类型入参的函数，可以临时保存std::string对象的c_str()方法返回的指针。但是必须严格保证std::string对象的生命周期长于所保存指针的生命周期，并且保证在所保存指针的生命周期内，std::string对象不会被修改。

## 确保用于字符串操作的缓冲区有足够的空间容纳字符数据和结束符，并且字符串以null结束符结束

**【描述】**
C风格字符串是一个连续的字符序列，由字符序列中的第一个出现的null字符终止并包含该null字符。

复制或存储C风格字符串时，必须确保缓冲区有足够的空间容纳字符序列包括null结束符，并且字符串以null结束符结束，否则可能会导致缓冲区溢出问题：

- 优先使用std::string表示字符串，std::string表示字符串操作更简便，更容易被正确的使用，避免由于C风格字符串使用不当而导致溢出、没有null结束符的问题。
- 使用C/C++标准库提供的C风格字符串操作函数时，需要确保输入的字符串以null结束符结束、不能超出字符串缓冲区的范围读写字符串、确保进存储操作后的字符串以null结束符结束。

**【反例】**

```cpp
char buf[BUFFER_SIZE];
std::cin >> buf;
void Foo(std::istream& in)
{
    char buffer[BUFFER_SIZE];
    if (!in.read(buffer, sizeof(buffer))) { // 注意：in.read()不能保证'\0'结尾
        ... // 错误处理
        return;
    }

    std::string str(buffer);                // 不符合：字符串没有结尾的'\0'
    ...
}
void Foo(std::istream& in)
{
    std::string s;
    in >> s;                    // 不符合：没有限制待读取的长度，可能导致资源消耗或攻击
    ...
}
```

**【正例】**

```cpp
char buf[BUFFER_SIZE] = {0};
std::cin.width(sizeof(buf) - 1); // 注意需要缓冲区长度-1，以留出字符串末尾'\0'的空间
std::cin >> buf;
void Foo(std::istream& in)
{
    char buffer[BUFFER_SIZE];

    if (!in.read(buffer, sizeof(buffer)) { // 注意in.read()不能保证'\0'结尾
        ... // 错误处理
        return;
    }

    std::string str(buffer, in.gcount()); // 让std::string构造函数，只读取指定长度的字符内容
    ...
}
void Foo(std::istream& in)
{
    std::string s;
    in.width(MAX_NEED_SIZE);
    in >> s;                             // 符合：已经限制读取的最大长度
    ...
}
```

**【影响】**
未对外部数据中的整数值进行限制可能导致拒绝服务，缓冲区溢出，信息泄露，或执行任意代码。

## 禁止使用std::string存储敏感信息

**【描述】**
std::string类是C++内部定义的字符串管理类，如果口令等敏感信息通过std::string进行操作，在程序运行过程中，敏感信息可能会散落到内存的各个地方，并且无法清除。

**【反例】**
如下代码中，Foo函数中获取密码，保存到std::string变量password中，随后传递给VerifyPassword函数，在这个过程中，password实际上在内存中出现了两份。

```cpp
bool VerifyPassword(std::string password)
{
    ...
}

void Foo()
{
    std::string password = GetPassword();
    VerifyPassword(password);
}
```

**【影响】**
未及时清理敏感信息，可能导致信息泄露。

## 外部数据用于容器索引或迭代器时必须确保在有效范围内

**【描述】**
外部数据是不可信数据，当将外部数据用于容器或数组的索引时，应确保其值在容器或数组可被访问元素的有效范围内；当将外部数据用于迭代器偏移时，应确保偏移后的迭代器值在与迭代器关联容器（从容器对象c的begin()方法创建）的[begin(), end())之间（即大于等于c.begin()，小于等于c.end()）。

对于具有at()方法的容器（如std::vector, std::set, std::map），对应索引越界或键值内容不存在时，方法将抛出异常；而其对应的operator[]出现索引越界时，将导致未定义行为；或者因键值内容不存在而构造对应键值的默认值不成功时，也将导致未定义行为。

**【反例】**

```cpp
int main()
{
    // 得到一个来自外部输入的整数 (index)
    int index;
    if (!(std::cin >> index)) {
        ... // 错误处理
        return -1;
    }

    std::vector<char> c{'A', 'B', 'C', 'D'};

    // 不符合：没有正确校验index的范围，溢出读取：需要确保index在容器元素的位置范围
    std::cout << c[index] << std::endl;

    // 不符合：需要确保index在容器/数组元素的位置范围
    for (auto pos = std::cbegin(c) + index; pos < std::cend(c); ++pos) {
        std::cout << *pos << std::endl;
    }
    return 0;
}
void Foo(size_t n)
{
    std::vector<int> v{0, 1, 2, 3};

    // n为外部的API传入的索引，可能导致越界访问
    for_each_n(v.cbegin(), n, [](int x) { std::cout << x; });
}
```

**【正例】**

```cpp
int main()
{
    // 得到一个来自外部输入的整数 (index)
    int index;
    if (!(std::cin >> index)) {
        ... // 错误处理
        return -1;
    }

    // 这里仅以std::vector来举例，std::cbegin(c)等代码也适用于std::string字符串、
    // 和C数组（但不适应于char*变量以及char*表示的静态字符串）
    std::vector<char> c{'A', 'B', 'C', 'D'};

    try {
        std::cout << c.at(index) << std::endl; // 符合：索引越界时，at函数将抛出异常
    } catch (const std::out_of_range& e) {
        ... // 越界异常处理
    }

    // 后续代码必须使用检验合法的 index 进行容器元素索引或迭代器偏移
    // 正确校验index的范围：已确保index在容器元素的位置范围
    if (index < 0 || index >= c.size()) {
        ... // 错误处理
        return -1;
    }

    std::cout << c[index] << std::endl;        // 符合：已检验index的范围

    // 符合：已检验index
    for (auto pos = std::cbegin(c) + index; pos < std::cend(c); ++pos) {
        std::cout << *pos << std::endl;
    }
    return 0;
}
void Foo(size_t n)
{
    std::vector<int> v{0, 1, 2, 3};

    // 必须确保for_each_n的迭代范围[first, first + count)有效
    if (n > v.size()) {
        ... // 错误处理
        return;
    }
    for_each_n(v.cbegin(), n, [](int x) { std::cout << x; });
}
```

## 调用格式化输入/输出函数时，使用有效的格式字符串

**【描述】**
使用C风格的格式化输入/输出函数时，需要确保格式串是合法有效的，并且格式串与相应的实参类型是严格匹配的，否则会使程序产生非预期行为。

除C风格的格式化输入/输出函数以外，C++中类似的函数也需要确保使用有效的格式串，如C++20的std::format()函数。

对于自定义C风格的格式化函数，可以使用编译器支持的属性自动检查使用自定义格式化函数的正确性。
例如：GCC支持自动检测类似printf, scanf, strftime, strfmon的自定义格式化函数，参考GCC手册的Common Function Attributes：

```c
extern int CustomPrintf(void* obj, const char* format, ...)
    __attribute__ ((format (printf, 2, 3)));
```

**【反例】**
如下代码示例中，格式化输入一个整数到macAddr变量中，但是macAddr为unsigned char类型，而%x对应的是int类型参数，函数执行完成后会发生写越界。

```c
unsigned char macAddr[6];
...
// macStr中的数据格式为 e2:42:a4:52:1e:33
int ret = sscanf(macStr, "%x:%x:%x:%x:%x:%x\n",
                  &macAddr[0], &macAddr[1],
                  &macAddr[2], &macAddr[3],
                  &macAddr[4], &macAddr[5]);
...
```

**【正例】**
如下代码中，使用%hhx确保格式串与相应的实参类型严格匹配。

```c
unsigned char macAddr[6];
...
// macStr中的数据格式为 e2:42:a4:52:1e:33
int ret = sscanf(macStr, "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx\n",
                  &macAddr[0], &macAddr[1],
                  &macAddr[2], &macAddr[3],
                  &macAddr[4], &macAddr[5]);
...
```

注：在C++中不推荐使用sscanf, sprintf等C库函数，可以替换为：std::istringstream, std::ostringstream, std::stringstream等。

**【影响】**
错误的格式串可能造成内存破坏或者程序异常终止。

## 调用格式化输入/输出函数时，禁止format参数受外部数据控制

**【描述】**
调用格式化函数时，如果format参数由外部数据提供，或由外部数据拼接而来，会造成字符串格式化漏洞。
以C标准库的格式化输出函数为例，当其format参数外部可控时，攻击者可以使用%n转换符向指定地址写入一个整数值、使用%x或%d转换符查看栈或寄存器内容、使用%s转换符造成进程崩溃等。

常见格式化函数有：

- 格式化输出函数: sprintf, vsprintf, snprintf, vsnprintf等等
- 格式化输入函数: sscanf, vsscanf, fscanf, vscanf等等
- 格式化错误消息函数: err(), verr(), errx(), verrx(), warn(), vwarn(), warnx(), vwarnx(), error(), error_at_line()
- 格式化日志函数: syslog(), vsyslog()
- C++20提供的std::format()

调用格式化函数时，应使用常量字符串作为格式串，禁止格式串外部可控：

```cpp
Box<int> v{MAX_COUNT};
std::cout << std::format("{:#x}", v);
```

**【反例】**
如下代码示例中，使用Log()函数直接打印外部数据，可能出现格式化字符串漏洞。

```c
void Foo()
{
    std::string msg = GetMsg();
    ...
    syslog(priority, msg.c_str());       // 不符合：存在格式化字符串漏洞  
}
```

**【正例】**
下面是推荐做法，使用%s转换符打印外部数据，避免格式化字符串漏洞。

```c
void Foo()
{
    std::string msg = GetMsg();
    ...
    syslog(priority, "%s", msg.c_str()); // 符合：这里没有格式化字符串漏洞  
}
```

**【影响】**
如果格式串被外部可控，攻击者可以使进程崩溃、查看栈内容、查看内存内容或者在任意内存位置写入数据，进而以被攻击进程的权限执行任意代码。

## 禁止外部可控数据作为进程启动函数的参数或者作为dlopen/LoadLibrary等模块加载函数的参数

**【描述】**
本条款中进程启动函数包括system、popen、execl、execlp、execle、execv、execvp等。
system()、popen()等函数会创建一个新的进程，如果外部可控数据作为这些函数的参数，会导致注入漏洞。
使用execl()等函数执行新进程时，如果使用shell启动新进程，则同样存在命令注入风险。
使用execlp()、execvp()、execvpe()函数依赖于系统的环境变量PATH来搜索程序路径，使用它们时应充分考虑外部环境变量的风险，或避免使用这些函数。

因此，总是优先考虑使用C标准函数实现需要的功能。如果确实需要使用这些函数，应使用白名单机制确保这些函数的参数不受任何外来数据的影响。

dlopen、LoadLibrary函数会加载外部模块，如果外部可控数据作为这些函数的参数，有可能会加载攻击者事先预制的模块。如果要使用这些函数，可以采用如下措施之一：

- 使用白名单机制，确保这些函数的参数不受任何外来数据的影响。
- 使用数字签名机制保护要加载的模块，充分保证其完整性。
- 在设备本地加载的动态库通过权限与访问控制措施保证了本身安全性后，通过特定目录自动被程序加载。
- 在设备本地的配置文件通过权限与访问控制措施保证了本身安全性后，自动加载配置文件中指定的动态库。

**【反例】**
如下代码从外部获取数据后直接作为LoadLibrary函数的参数，有可能导致程序被植入木马。

```c
char* msg = GetMsgFromRemote();
LoadLibrary(msg);
```

如下代码示例中，使用 system() 函数执行 cmd 命令串来自外部，攻击者可以执行任意命令：

```c
std::string cmd = GetCmdFromRemote();
system(cmd.c_str());
```

如下代码示例中，使用 system() 函数执行 cmd 命令串的一部分来自外部，攻击者可能输入 `some dir;reboot`字符串，创造成系统重启：

```cpp
std::string name = GetDirNameFromRemote();
std::string cmd{"ls " + name};
system(cmd.c_str());
```

使用exec系列函数来避免命令注入时，注意exec系列函数中的path、file参数禁止使用命令解析器(如/bin/sh)。

```c
int execl(const char* path, const char* arg, ...);
int execlp(const char* file, const char* arg, ...);
int execle(const char* path, const char* arg, ...);
int execv(const char* path, char* const argv[]);
int execvp(const char* file, char* const argv[]);
int execvpe(const char* file, char* const argv[], char* const envp[]);
```

例如，禁止如下使用方式：

```c
std::string cmd = GetDirNameFromRemote();
execl("/bin/sh", "sh", "-c", cmd.c_str(), nullptr);
```

可以使用库函数，或者可以通过编写少量的代码来避免使用system函数调用命令，如`mkdir()`函数可以实现`mkdir`命令的功能。
如下代码中，应该避免使用`cat`命令实现文件内容复制的功能。

```c
int WriteDataToFile(const char* dstFile, const char* srcFile)
{
    ...  // 入参的合法性校验
    std::ostringstream oss;
    oss << "cat " << srcFile << " > " << dstFile;

    std::string cmd{oss.str()};
    system(cmd.c_str());
    ...
}
```

**【正例】**

如下代码中，通过少量的代码来实现。如下代码实现了文件复制的功能，避免了对`cat`或`cp`命令的调用。需要注意的是，为简化描述，下面代码未考虑信号中断的影响。

```cpp
bool WriteDataToFile(const std::string& dstFilePath, const std::string& srcFilePath)
{
    const int bufferSize = 1024;
    std::vector<char> buffer (bufferSize + 1, 0);

    std::ifstream srcFile(srcFilePath, std::ios::binary);
    std::ofstream dstFile(dstFilePath, std::ios::binary);

    if (!dstFile || !dstFile) {
        ... // 错误处理
        return false;
    }

    while (true) {
        // 从srcFile读取内容分块
        srcFile.read(buffer.data(), bufferSize);
        std::streamsize size = srcFile ? bufferSize : srcFile.gcount();

        // 写入分块内容到dstFile
        if (size > 0 && !dstFile.write(buffer.data(), size)) {
            ... // 错误处理
            break;
        }

        if (!srcFile) {
            ... // 检查错误：当不是eof()时记录错误
            break;
        }
    }
    // srcFile 和 dstFile 在退出作用域时会自动被关闭
    return true;
}
```

可以通过库函数简单实现的功能（如上例），需要避免调用命令处理器来执行外部命令。
如果确实需要调用单个命令，应使用exec*函数来实现参数化调用，并对调用的命令实施白名单管理。同时应避免使用execlp、execvp、execvpe函数，因为这几个函数依赖外部的PATH环境变量。
此时，外部输入的fileName仅作为some_tool命令的参数，没有命令注入的风险。

```cpp
pid_t pid;
char* const envp[] = {nullptr};
...
std::string fileName = GetDirNameFromRemote();
...
pid = fork();
if (pid < 0) {
    ...
} else if (pid == 0) {
    // 使用some_tool对指定文件进行加工
    execle("/bin/some_tool", "some_tool", fileName.c_str(), nullptr, envp);
    _Exit(-1);
}
...
int status;
waitpid(pid, &status, 0);
std::ofstream ofs(fileName, std::ios::in);
...
```

在必须使用system等命令解析器执行命令时，应对输入的命令字符串基于合理的白名单检查，避免命令注入。

```cpp
std::string cmd = GetCmdFromRemote();

// 使用白名单检查命令是否合法，仅允许"some_tool_a", "some_tool_b"命令，外部无法随意控制
if (!IsValidCmd(cmd.c_str())) {
    ... // 错误处理
}
system(cmd.c_str());
...
```

**【影响】**

- 如果传递给system()、popen()或其他命令处理函数的命令字符串是外部可控的，则攻击者可能会以被攻击进程的权限执行系统上存在的任意命令。
- 如果动态库文件是外部可控的，则攻击者可替换该库文件，在某些情况下可以造成任意代码执行漏洞。

# 其他C语言编程规范

## 禁止通过对数组类型的函数参数变量进行sizeof来获取数组大小

**【描述】**

使用sizeof操作符求其操作数的大小（以字节为单位），其操作数可以是一个表达式或者加上括号的类型名称，例如：`sizeof(int)`或`sizeof(int *)`。
参考C11标准6.5.3.4中的脚注103：

> 当将sizeof应用于具有数组或函数类型的参数时，sizeof操作符将得出调整后的（指针）类型的大小。

函数参数列表中声明为数组的参数会被调整为相应类型的指针。例如：`void Func(int inArray[LEN])`函数参数列表中的inArray虽然被声明为数组，但是实际上会被调整为指向int类型的指针，即调整为`void Func(int *inArray)`。
在这个函数内使用`sizeof(inArray)`等同于`sizeof(int *)`，得到的结果通常与预期不相符。例如：在IA-32架构上，`sizeof(inArray)` 的值是 4，并不是inArray数组的大小。

**【反例】**
如下代码示例中，函数ArrayInit的功能是初始化数组元素。该函数有一个声明为`int inArray[]`的参数，被调用时传递了一个长度为256的int类型数组data。
ArrayInit函数实现中使用`sizeof(inArray) / sizeof(inArray[0])`方法来计算入参数组中元素的数量。
但由于inArray是函数参数，所以具有指针类型，结果，`sizeof(inArray)`等同于`sizeof(int *)`。
无论传递给ArrayInit函数的数组实际长度如何，表达式的`sizeof(inArray) / sizeof(inArray[0])`计算结果均为1，与预期不符。

```c
#define DATA_LEN 256
void ArrayInit(int inArray[])
{
    // 不符合：这里使用sizeof(inArray)计算数组大小
    for (size_t i = 0; i < sizeof(inArray) / sizeof(inArray[0]); i++) {
        ...
    }
}

void FunctionData(void)
{
    int data[DATA_LEN];

    ...
    ArrayInit(data); // 调用ArrayInit函数初始化数组data数据
    ...
}
```

**【正例】**
如下代码示例中，修改函数定义，添加数组长度参数，并在调用处正确传入数组长度。

```c
#define DATA_LEN 256
// 函数说明：入参len是入参inArray数组的长度
void ArrayInit(int inArray[], size_t len)
{
    for (size_t i = 0; i < len; i++) {
        ...
    }
}

void FunctionData(void)
{
    int data[DATA_LEN];

    ArrayInit(data, sizeof(data) / sizeof(data[0]));
    ...
}
```

**【反例】**
如下代码示例中，`sizeof(inArray)`不等于`ARRAY_MAX_LEN * sizeof(int)`，因为将sizeof操作符应用于声明为具有数组类型的参数时，即使参数声明指定了长度，也会被调整为指针，`sizeof(inArray)`等同于 `sizeof(int *)`：

```c
#define ARRAY_MAX_LEN 256

void ArrayInit(int inArray[ARRAY_MAX_LEN])
{
    // 不符合：sizeof(inArray)，得到的长度是指针的大小，不是数组的长度，和预期不符。
    for (size_t i = 0; i < sizeof(inArray) / sizeof(inArray[0]); i++) {
        ...
    }
}

int main(void)
{
    int masterArray[ARRAY_MAX_LEN];

    ...
    ArrayInit(masterArray);

    return 0;
}
```

**【正例】**
如下代码示例中，使用入参len表示指定数组的长度：

```c
#define ARRAY_MAX_LEN 256

// 函数说明：入参len是入参数组的长度
void ArrayInit(int inArray[], size_t len)
{
    for (size_t i = 0; i < len; i++) {
        ...
    }
}

int main(void)
{
    int masterArray[ARRAY_MAX_LEN];

    ArrayInit(masterArray, ARRAY_MAX_LEN);
    ...

    return 0;
}
```

## 禁止通过对指针变量进行sizeof操作来获取数组大小

**描述】**
将指针当做数组进行sizeof操作时，会导致实际的执行结果与预期不符。例如：变量定义 `char *p = array`，其中array的定义为`char array[LEN]`，表达式`sizeof(p)`得到的结果与 `sizeof(char *)`相同，并非array的长度。

**【反例】**
如下代码示例中，buffer和path分别是指针和数组，程序员想对这2个内存进行清0操作，但由于程序员的疏忽，将内存大小误写成了`sizeof(buffer)`，与预期不符。

```c
char path[MAX_PATH];
char *buffer = (char *)malloc(SIZE);
...

...
memset(path, 0, sizeof(path));

// sizeof与预期不符，其结果为指针本身的大小而不是缓冲区大小
memset(buffer, 0, sizeof(buffer));
```

**【正例】**
如下代码示例中，将`sizeof(buffer)`修改为申请的缓冲区大小：

```c
char path[MAX_PATH];
char *buffer = (char *)malloc(SIZE);
...

...
memset(path, 0, sizeof(path));
memset(buffer, 0, SIZE); // 使用申请的缓冲区大小
```

## 禁止直接使用外部数据拼接SQL命令

**【描述】**
SQL注入是指SQL查询被恶意更改成一个与程序预期完全不同的查询。执行更改后的查询可能会导致信息泄露或者数据被篡改。而SQL注入的根源就是使用外部数据来拼接SQL语句。C/C++语言中常见的使用外部数据拼接SQL语句的场景有（包括但不局限于）：

- 连接MySQL时调用mysql_query()，Execute()时的入参
- 连接SQL Server时调用db-library驱动的dbsqlexec()的入参
- 调用ODBC驱动的SQLprepare()连接数据库时的SQL语句的参数
- C++程序调用OTL类库中的otl_stream()，otl_column_desc()时的入参
- C++程序连接Oracle数据库时调用ExecuteWithResSQL()的入参

防止SQL注入的方法主要有以下几种：

- 参数化查询（通常也叫作预处理语句）：参数化查询是一种简单有效的防止SQL注入的查询方式，应该被优先考虑使用。支持的数据库有MySQL，Oracle（OCI）。
- 参数化查询（通过ODBC驱动）：支持ODBC驱动参数化查询的数据库有Oracle、SQLServer、PostgreSQL和GaussDB。
- 对外部数据进行校验（对于每个引入的外部数据推荐“白名单”校验）。
- 对外部数据中的SQL特殊字符进行转义。

**【反例】**
下列代码拼接用户输入，没有进行输入检查，存在SQL注入风险：

```c
char name[NAME_MAX];
char sqlStatements[SQL_CMD_MAX];
int ret = GetUserInput(name, NAME_MAX);
...
ret = sprintf(sqlStatements,
                "SELECT childinfo FROM children WHERE name= ‘%s’",
                name);
...
ret = mysql_query(&myConnection, sqlStatements);
...
```

**【正例】**
使用预处理语句进行参数化查询可以防御SQL注入攻击：

```c
char name[NAME_MAX];
...
MYSQL_STMT *stmt = mysql_stmt_init(myConnection);
char *query = "SELECT childinfo FROM children WHERE name= ?";
if (mysql_stmt_prepare(stmt, query, strlen(query))) {
    ...
}
int ret = GetUserInput(name, NAME_MAX);
...
MYSQL_BIND params[1];
(void)memset(params, 0, sizeof(params));
...
params[0].bufferType = MYSQL_TYPE_STRING;
params[0].buffer = (char *)name;
params[0].bufferLength = strlen(name);
params[0].isNull = 0;

bool isCompleted = mysql_stmt_bind_param(stmt, params);
...
ret = mysql_stmt_execute(stmt);
...
```

**【影响】**

如果拼接SQL语句的字符串是外部可控的，则攻击者可以通过注入特定的字符串欺骗程序执行恶意的SQL命令，造成信息泄露、权限绕过、数据被篡改等问题。

## 内存中的敏感信息使用完毕后立即清0

**【描述】**
内存中的口令、密钥等敏感信息使用完毕后立即清0，避免被攻击者获取或者无意间泄露给低权限用户。这里所说的内存包括但不限于：

- 动态分配的内存
- 静态分配的内存
- 自动分配（堆栈）内存
- 内存缓存
- 磁盘缓存

**【反例】**
通常内存在释放前不需要清除内存数据，因为这样在运行时会增加额外开销，所以在这段内存被释放之后，之前的数据还是会保留在其中。如果这段内存中的数据包含敏感信息，则可能会意外泄露敏感信息。为了防止敏感信息泄露，必须先清除内存中的敏感信息，然后再释放。
在如下代码示例中，存储在所引用的动态内存中的敏感信息secret被复制到新动态分配的缓冲区newSecret，最终通过free()释放。因为释放前未清除这块内存数据，这块内存可能被重新分配到程序的另一部分，之前存储在newSecret中的敏感信息可能会无意中被泄露。

```c
char *secret = NULL;
/*
 * 假设 secret 指向敏感信息，敏感信息的内容是长度小于SIZE_MAX个字符，
 * 并且以null终止的字节字符串
 */

size_t size = strlen(secret);
char *newSecret = NULL;
newSecret = (char *)malloc(size + 1);
if (newSecret == NULL) {
    ... // 错误处理
} else {
    errno_t ret = strcpy(newSecret, secret);
    ... // 处理 ret

    ... // 处理 newSecret...

    free(newSecret);
    newSecret = NULL;
}
...
```

**【正例】**
如下代码示例中，为了防止信息泄露，应先清除包含敏感信息的动态内存（用’\0’字符填充空间），然后再释放它。

```c
char *secret = NULL;
/*
 * 假设 secret 指向敏感信息，敏感信息的内容是长度小于SIZE_MAX个字符，
 * 并且以null终止的字节字符串
 */
size_t size = strlen(secret);
char *newSecret = NULL;
newSecret = (char *)malloc(size + 1);
if (newSecret == NULL) {
    ... // 错误处理
} else {
    errno_t ret = strcpy(newSecret,  secret);
    ... // 处理 ret

    ... // 处理 newSecret...

    (void)memset(newSecret,  0, size + 1);
    free(newSecret);
    newSecret = NULL;
}
...
```

**【正例】**
下面是另外一个涉及敏感信息清理的场景，在代码获取到密码后，将密码保存到password中，进行密码验证，使用完毕后，通过`memset()`函数对password清0。

```c
int Foo(void)
{
    char password[MAX_PWD_LEN];
    if (!GetPassword(password, sizeof(password))) {
        ...
    }
    if (!VerifyPassword(password)) {
        ...
    }
    ...
    (void)memset(password,  0, sizeof(password));
    ...
}
```

要特别**注意**：对敏感信息清理的时候要同时防止因编译器优化而使清理代码无效。

例如，下列代码使用了可能被编译器优化掉的语句。

```c
int SecureLogin(void)
{
    char pwd[PWD_SIZE];
    if (RetrievePassword(pwd, sizeof(pwd))) {
        ... // 口令检查及其他处理
    }
    memset(pwd, 0, sizeof(pwd)); // 编译器优化有可能会使该语句失效
    ...
}
```

某些编译器在优化时候不会执行它认为不会改变程序执行结果的代码，因此memset()操作会被优化掉。

如果编译器支持#pragma指令，那么可以使用该指令指示编译器不作优化。

```c
void SecureLogin(void)
{
    char pwd[PWD_SIZE];
    if (RetrievePassword(pwd, sizeof(pwd))) {
        ... // 口令检查及其他处理
    }
    #pragma optimize("", off)
    // 清除内存
    ...
    #pragma optimize("", on)
    ...
}
```

**【影响】**

未及时清理敏感信息，可能导致信息泄露。

## 创建文件时必须显式指定合适的文件访问权限

**【描述】**
创建文件时，如果不显式指定合适访问权限，可能会让未经授权的用户访问该文件，造成信息泄露，文件数据被篡改，文件中被注入恶意代码等风险。

虽然文件的访问权限也依赖于文件系统，但是当前许多文件创建函数（例如POSIX open函数）都具有设置（或影响）文件访问权限的功能，所以当使用这些函数创建文件时，必须显式指定合适的文件访问权限，以防止意外访问。

**【反例】**
使用POSIX open()函数创建文件但未显示指定该文件的访问权限，可能会导致文件创建时具有过高的访问权限。这可能会导致漏洞（例如CVE-2006-1174）。

```c
void Foo(void)
{
    int fd = -1;
    char *filename = NULL;

    ... // 初始化 filename

    fd = open(filename, O_CREAT | O_WRONLY); // 没有显式指定访问权限
    if (fd == -1) {
        ... // 错误处理
    }
    ...
}
```

**【正例】**
应该在open的第三个参数中显式指定新创建文件的访问权限。可以根据文件实际的应用情况设置何种访问权限。

```c
void Foo(void)
{
    int fd = -1;
    char *filename = NULL;

    ... // 初始化 filename 和指定其访问权限

    // 此处根据文件实际需要，显式指定其访问权限
    int fd = open(filename, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        ... // 错误处理
    }
    ...
}
```

**【影响】**

创建访问权限弱的文件，可能会导致对这些文件的非法访问。

## 使用文件路径前必须进行规范化并校验

**【描述】**
当文件路径来自外部数据时，必须对其做合法性校验，如果不校验，可能造成系统文件的被任意访问。但是禁止直接对其进行校验，正确做法是在校验之前必须对其进行路径规范化处理。这是因为同一个文件可以通过多种形式的路径来描述和引用，例如既可以是绝对路径，也可以是相对路径；而且路径名、目录名和文件名可能包含使校验变得困难和不准确的字符（如：“.”、“..”）。此外，文件还可以是符号链接，这进一步模糊了文件的实际位置或标识，增加了校验的难度和校验准确性。所以必须先将文件路径规范化，从而更容易校验其路径、目录或文件名，增加校验准确性。

因为规范化机制在不同的操作系统和文件系统之间可能有所不同，所以最好使用符合当前系统特性的规范化机制。

一个简单的案例说明如下：

```c
当文件路径来自外部数据时，需要先将文件路径规范化，如果没有作规范化处理，攻击者就有机会通过恶意构造文件路径进行文件的越权访问。
例如，攻击者可以构造“../../../etc/passwd”的方式进行任意文件访问。
```

**【反例】**
在此错误的示例中，inputFilename包含一个源于受污染源的文件名，并且该文件名已打开以进行写入。在使用此文件名操作之前，应该对其进行验证，以确保它引用的是预期的有效文件。
不幸的是，inputFilename引用的文件名可能包含特殊字符，例如目录字符，这使验证变得困难，甚至不可能。而且，inputFilename中可能包含可以指向任意文件路径的符号链接，即使该文件名通过了验证，也会导致该文件名是无效的。
这种场景下，对文件名的直接验证即使被执行也是得不到预期的结果，对fopen()的调用可能会导致访问一个意外的文件。

```c
...

if (!verify_file(inputFilename) {    // 没有对inputFilename做规范化，直接做校验
    ... // 错误处理
}

if (fopen(inputFilename, "w") == NULL) {
    ... // 错误处理
}

...
```

**【正例】**
规范化文件名是具有一定难度的，因为这需要了解底层文件系统。
POSIX realpath()函数可以帮助将路径名转换为规范形式。参考信息技术标准-POSIX®，基本规范第7期[IEEE std 1003.1：2013]：

- 该realpath()函数应从所指向的路径名派生一个filename的绝对路径名，两者指向同一文件，绝对路径其文件名不涉及“ .”，“ ..”或符号链接。
  在规范化路径之后，还必须执行进一步的验证，例如确保两个连续的斜杠或特殊文件不会出现在文件名中。有关如何执行路径名解析的更多详细信息，请参见[IEEE Std 1003.1: 2013]第4.12节“路径名解析”。
  使用realpath()函数有许多需要注意的地方。
  在了解了以上原理之后，对上面的错误代码示例，我们采用如下解决方案：

```c
char *realpathRes = NULL;

...

// 在校验之前，先对inputFilename做规范化处理
realpathRes = realpath(inputFilename, NULL);
if (realpathRes == NULL) {
    ... // 规范化的错误处理
}

// 规范化以后对路径进行校验
if (!verify_file(realpathRes) {
    ... // 校验的错误处理
}

// 使用
if (fopen(realpathRes, "w") == NULL) {
    ... // 实际操作的错误处理
}

...

free(realpathRes);
realpathRes = NULL;
...
```

**【正例】**
根据我们的实际场景，我们还可以采用的第二套解决方案，说明如下：
如果`PATH_MAX`被定义为 limits.h 中的一个常量，那么使用非空的`resolved_path`调用realpath()也是安全的。
在本例中realpath()函数期望`resolved_path`引用一个字符数组，该字符数组足够大，可以容纳规范化的路径。
如果定义了PATH_MAX，则分配一个大小为`PATH_MAX`的缓冲区来保存realpath()的结果。正确代码示例如下：

```c
char *realpathRes = NULL;
char *canonicalFilename = NULL;
size_t pathSize = 0;

...

pathSize = (size_t)PATH_MAX;

if (VerifyPathSize(pathSize)) {
    canonicalFilename = (char *)malloc(pathSize);

    if (canonicalFilename == NULL) {
        ... // 错误处理
    }

    realpathRes = realpath(inputFilename, canonicalFilename);
}

if (realpathRes == NULL) {
    ... // 错误处理
}

if (VerifyFile(realpathRes)) {
    ... // 错误处理
}

if (fopen(realpathRes, "w") == NULL ) {
    ... // 错误处理
}

...

free(canonicalFilename);
canonicalFilename = NULL;
...
```

**【反例】**
下面的代码场景是从外部获取到文件名称，拼接成文件路径后，直接对文件内容进行读取，导致攻击者可以读取到任意文件的内容：

```c
char *filename = GetMsgFromRemote();
...
int ret = sprintf(untrustPath,  "/tmp/%s", filename);
...
char *text = ReadFileContent(untrustPath);
```

**【正例】**
正确的做法是，对路径进行规范化后，再判断路径是否是本程序所认为的合法的路径：

```c
char *filename = GetMsgFromRemote();
...
sprintf(untrustPath,  "/tmp/%s", filename);
char path[PATH_MAX];
if (realpath(untrustPath, path) == NULL) {
    ... // 处理错误
}
if (!IsValidPath(path)) {    // 检查文件的位置是否正确
    ... // 处理错误
}
char *text = ReadFileContent(path);
```

**【例外】**

运行于控制台的命令行程序，通过控制台手工输入文件路径，可以作为本条款例外。

```c
int main(int argc, char **argv)
{
    int fd = -1;

    if (argc == 2) {
        fd = open(argv[1], O_RDONLY);
        ...
    }

    ...
    return 0;
}
```

**【影响】**

未对不可信的文件路径进行规范化和校验，可能造成对任意文件的访问。

## 不要在共享目录中创建临时文件

**【描述】**
共享目录是指其它非特权用户可以访问的目录。程序的临时文件应当是程序自身独享的，任何将自身临时文件置于共享目录的做法，将导致其他共享用户获得该程序的额外信息，产生信息泄露。因此，不要在任何共享目录创建仅由程序自身使用的临时文件。

临时文件通常用于辅助保存不能驻留在内存中的数据或存储临时的数据，也可用作进程间通信的一种手段（通过文件系统传输数据）。例如，一个进程在共享目录中创建一个临时文件，该文件名可能使用了众所周知的名称或者一个临时的名称，然后就可以通过该文件在进程间共享信息。这种通过在共享目录中创建临时文件的方法实现进程间共享的做法很危险，因为共享目录中的这些文件很容易被攻击者劫持或操纵。这里有几种缓解策略：

1. 使用其他低级IPC（进程间通信）机制，例如套接字或共享内存。
2. 使用更高级别的IPC机制，例如远程过程调用。
3. 使用仅能由程序本身访问的安全目录(多线程/进程下注意防止条件竞争)。

同时，下面列出了几项临时文件创建使用的方法，产品根据具体场景执行以下一项或者几项，同时产品也可以自定义合适的方法。

1. 文件必须具有合适的权限，只有符合权限的用户才能访问
2. 创建的文件名是唯一的、或不可预测的
3. 仅当文件不存在时才创建打开(原子创建打开)
4. 使用独占访问打开，避免竞争条件
5. 在程序退出之前移除

同时也需要注意到，当某个目录被开放读/写权限给多个用户或者一组用户时，该共享目录潜在的安全风险远远大于访问该目录中临时文件这个功能的本身。

在共享目录中创建临时文件很容易受到威胁。例如，用于本地挂载的文件系统的代码在与远程挂载的文件系统一起共享使用时可能会受到攻击。安全的解决方案是不要在共享目录中创建临时文件。

**【反例】**
如下代码示例，程序在系统的共享目录/tmp下创建临时文件来保存临时数据，且文件名是硬编码的。
由于文件名是硬编码的，因此是可预测的，攻击者只需用符号链接替换文件，然后链接所引用的目标文件就会被打开并写入新内容。

```c
void ProcData(const char *filename)
{
    FILE *fp = fopen(filename, "wb+");
    if (fp == NULL) {
        ... // 错误处理
    }

    ... // 写文件

    fclose(fp);
}

int main(void)
{
    // 不符合：1.在系统共享目录中创建临时文件；2.临时文件名硬编码
    char *pFile = "/tmp/data";
    ...

    ProcData(pFile);

    ...
    return 0;
}
```

**【正确案例】**

```c
不应在该目录下创建仅由程序自身使用的临时文件。
```

**【影响】**

不安全的创建临时文件，可能导致文件非法访问，并造成本地系统上的权限提升。

## 不要在信号处理函数中访问共享对象

**【描述】**
如果在信号处理程序中访问和修改共享对象，可能会造成竞争条件，使数据处于不确定的状态。
这条规则有两个不适用的场景（参考C11标准5.1.2.3第5段）：

- 读写不需要加锁的原子对象;
- 读写volatile sig_atomic_t类型的对象，因为具有volatile sig_atomic_t类型的对象即使在出现异步中断的时候也可以作为一个原子实体访问，是异步安全的。

**【反例】**
在这个信号处理过程中，程序打算将`g_msg`作为共享对象，当产生SIGINT信号时更新共享对象的内容，但是该`g_msg`变量类型不是`volatile sig_atomic_t`，所以不是异步安全的。

```c
#define MAX_MSG_SIZE 32
static char g_msgBuf[MAX_MSG_SIZE] = {0};
static char *g_msg = g_msgBuf;

void SignalHandler(int signum)
{
    // 下面代码操作g_msg不合规，因为不是异步安全的
    (void)memset(g_msg,0, MAX_MSG_SIZE);
    errno_t ret = strcpy(g_msg,  "signal SIGINT received.");
    ... // 处理 ret
}

int main(void)
{
    errno_t ret = strcpy(g_msg,  "No msg yet."); // 初始化消息内容
    ... // 处理 ret

    signal(SIGINT, SignalHandler); // 设置SIGINT信号对应的处理函数

    ... // 程序主循环代码

    return 0;
}
```

**【正例】**
如下代码示例中，在信号处理函数中仅将`volatile sig_atomic_t`类型作为共享对象使用。

```c
#define MAX_MSG_SIZE 32
volatile sig_atomic_t g_sigFlag = 0;

void SignalHandler(int signum)
{
    g_sigFlag = 1; // 符合
}

int main(void)
{
    signal(SIGINT, SignalHandler);
    char msgBuf[MAX_MSG_SIZE];
    errno_t ret = strcpy(msgBuf, "No msg yet."); // 初始化消息内容
    ... // 处理 ret

    ... // 程序主循环代码

    if (g_sigFlag == 1) {  // 在退出主循环之后，根据g_sigFlag状态再刷新消息内容
        ret = strcpy(msgBuf,  "signal SIGINT received.");
        ... // 处理 ret
    }

    return 0;
}
```

**【影响】**

在信号处理程序中访问或修改共享对象，可能造成以不一致的状态访问数据。

## 禁用rand函数产生用于安全用途的伪随机数

**【描述】**
C语言标准库rand()函数生成的是伪随机数，所以不能保证其产生的随机数序列质量。根据C11标准，rand()函数产生的随机数范围是`[0, RAND_MAX(0x7FFF)]`，因为范围相对较短，所以这些数字可以被预测。
所以禁止使用rand()函数产生的随机数用于安全用途，必须使用安全的随机数产生方式。

典型的安全用途场景包括(但不限于)以下几种：

- 会话标识SessionID的生成；
- 挑战算法中的随机数生成；
- 验证码的随机数生成；
- 用于密码算法用途（例如用于生成IV、盐值、密钥等）的随机数生成。

**【反例】**
程序员期望生成一个唯一的不可被猜测的HTTP会话ID，但该ID是通过调用rand()函数产生的数字随机数，它的ID是可猜测的，并且随机性有限。

**【影响】**

使用rand()函数可能造成可预测的随机数。

## 禁止在发布版本中输出对象或函数的地址

**【描述】**
禁止在发布版本中输出对象或函数的地址，如：将变量或函数的地址输出到客户端、日志、串口中。

当攻击者实施高级攻击时，通常需要先获取目标程序中的内存地址（如变量地址、函数地址等），再通过修改指定内存的内容，达到攻击目的。
如果程序中主动输出对象或函数的地址，则为攻击者提供了便利条件，可以根据这些地址以及偏移量计算出其他对象或函数的地址，并实施攻击。
另外，由于内存地址泄露，也会造成地址空间随机化的保护功能失效。

**【反例】**
如下代码中，使用%p格式将指针指向的地址记录到日志中。

```c
int Encode(unsigned char *in, size_t inSize, unsigned char *out, size_t maxSize)
{
    ...
    Log("in=%p, in size=%zu, out=%p, max size=%zu\n", in, inSize, out, maxSize);
    ...
}
```

备注：这里仅用%p打印指针作为示例，代码中将指针转换为整数再打印也存在同样的风险。

**【正例】**
如下代码中，删除打印地址的代码。

```c
int Encode(unsigned char *in, size_t inSize, unsigned char *out, size_t maxSize)
{
    ...
    Log("in size=%zu, max size=%zu\n", inSize, maxSize);
    ...
}
```

**【例外】**
当程序崩溃退出时，在记录崩溃的异常信息中可以输出内存地址等信息。

**【影响】**

内存地址信息泄露，为攻击者实施攻击提供有利信息，可能造成地址空间随机化防护失效。

## 禁止代码中包含公网地址

**【描述】**

代码或脚本中包含用户不可见，不可知的公网地址，可能会引起客户质疑。

对产品发布的软件（包含软件包/补丁包）中包含的公网地址（包括公网IP地址、公网URL地址/域名、邮箱地址）要求如下：
1、禁止包含用户界面不可见、或产品资料未描述的未公开的公网地址。
2、已公开的公网地址禁止写在代码或者脚本中，可以存储在配置文件或数据库中。

对于开源/第三方软件自带的公网地址必须至少满足上述第1条公开性要求。

**【例外】**

- 对于标准协议中必须指定公网地址的场景可例外，如soap协议中函数的命名空间必须指定的一个组装的公网URL、http页面中包含w3.org网址等。

# 内核安全编程

## 内核mmap接口实现中，确保对映射起始地址和大小进行合法性校验

**【描述】**

**说明**：内核 mmap接口中，经常使用remap_pfn_range()函数将设备物理内存映射到用户进程空间。如果映射起始地址等参数由用户态控制并缺少合法性校验，将导致用户态可通过映射读写任意内核地址。如果攻击者精心构造传入参数，甚至可在内核中执行任意代码。

**【错误代码示例】**

如下代码在使用remap_pfn_range()进行内存映射时，未对用户可控的映射起始地址和空间大小进行合法性校验，可导致内核崩溃或任意代码执行。

```c
static int incorrect_mmap(struct file *file, struct vm_area_struct *vma)
{
	unsigned long size;
	size = vma->vm_end - vma->vm_start;
	vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
	//错误：未对映射起始地址、空间大小做合法性校验
	if (remap_pfn_range(vma, vma->vm_start, vma->vm_pgoff, size, vma->vm_page_prot)) { 
		err_log("%s, remap_pfn_range fail", __func__);
		return EFAULT;
	} else {
		vma->vm_flags &=  ~VM_IO;
	}

	return EOK;
}
```

**【正确代码示例】**

增加对映射起始地址等参数的合法性校验。

```c
static int correct_mmap(struct file *file, struct vm_area_struct *vma)
{
	unsigned long size;
	size = vma->vm_end - vma->vm_start;
	//修改：添加校验函数，验证映射起始地址、空间大小是否合法
	if (!valid_mmap_phys_addr_range(vma->vm_pgoff, size)) { 
		return EINVAL;
	}

	vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
	if (remap_pfn_range(vma, vma->vm_start, vma->vm_pgoff, size, vma->vm_page_prot)) {
		err_log( "%s, remap_pfn_range fail ", __func__);
		return EFAULT;
	} else {
		vma->vm_flags &=  ~VM_IO;
	}

	return EOK;
}
```

## 内核程序中必须使用内核专用函数读写用户态缓冲区

**【描述】**

用户态与内核态之间进行数据交换时，如果在内核中不加任何校验（如校验地址范围、空指针）而直接引用用户态传入指针，当用户态传入非法指针时，可导致内核崩溃、任意地址读写等问题。因此，应当禁止使用memcpy()、sprintf()等危险函数，而是使用内核提供的专用函数：copy_from_user()、copy_to_user()、put_user()和get_user()来读写用户态缓冲区，这些函数内部添加了入参校验功能。

所有禁用函数列表为：memcpy()、bcopy()、memmove()、strcpy()、strncpy()、strcat()、strncat()、sprintf()、vsprintf()、snprintf()、vsnprintf()、sscanf()、vsscanf()。

**【错误代码示例】**

内核态直接使用用户态传入的buf指针作为snprintf()的参数，当buf为NULL时，可导致内核崩溃。

```c
ssize_t incorrect_show(struct file *file, char__user *buf, size_t size, loff_t *data)
{
	// 错误：直接引用用户态传入指针，如果buf为NULL，则空指针异常导致内核崩溃
	return snprintf(buf, size, "%ld\n", debug_level); 
}
```

**【正确代码示例】**

使用copy_to_user()函数代替snprintf()。

```c
ssize_t correct_show(struct file *file, char __user *buf, size_t size, loff_t *data)
{
	int ret = 0;
	char level_str[MAX_STR_LEN] = {0};
	snprintf(level_str, MAX_STR_LEN, "%ld \n", debug_level);
	if(strlen(level_str) >= size) {
		return EFAULT;
	}
	
	// 修改：使用专用函数copy_to_user()将数据写入到用户态buf，并注意防止缓冲区溢出
	ret = copy_to_user(buf, level_str, strlen(level_str)+1); 
	return ret;
}
```

**【错误代码示例】**

内核态直接使用用户态传入的指针user_buf作为数据源进行memcpy()操作，当user_buf为NULL时，可导致内核崩溃。

```c
size_t incorrect_write(struct file  *file, const char __user  *user_buf, size_t count, loff_t  *ppos)
{
	...
	char buf [128] = {0};
	int buf_size = 0;
	buf_size = min(count, (sizeof(buf)-1));
	// 错误：直接引用用户态传入指针，如果user_buf为NULL，则可导致内核崩溃
	(void)memcpy(buf, user_buf, buf_size); 
	...
}
```

**【正确代码示例】**

使用copy_from_user()函数代替memcpy()。

```c
ssize_t correct_write(struct file *file, const char __user *user_buf, size_t count, loff_t *ppos)
{
	...
	char buf[128] = {0};
	int buf_size = 0;

	buf_size = min(count, (sizeof(buf)-1));
	// 修改：使用专用函数copy_from_user()将数据写入到内核态buf，并注意防止缓冲区溢出
	if (copy_from_user(buf, user_buf, buf_size)) { 
		return EFAULT;
	}

	...
}
```

## 必须对copy_from_user()拷贝长度进行校验，防止缓冲区溢出

**说明**：内核态从用户态拷贝数据时通常使用copy_from_user()函数，如果未对拷贝长度做校验或者校验不当，会造成内核缓冲区溢出，导致内核panic或提权。

**【错误代码示例】**

未校验拷贝长度。

```c
static long gser_ioctl(struct file  *fp, unsigned cmd, unsigned long arg)
{
	char smd_write_buf[GSERIAL_BUF_LEN];
	switch (cmd)
	{
		case GSERIAL_SMD_WRITE:
			if (copy_from_user(&smd_write_arg, argp, sizeof(smd_write_arg))) {...}
			// 错误：拷贝长度参数smd_write_arg.size由用户输入，未校验
			copy_from_user(smd_write_buf, smd_write_arg.buf, smd_write_arg.size); 
			...
	}
}
```

**【正确代码示例】**

添加长度校验。

```c
static long gser_ioctl(struct file *fp, unsigned cmd, unsigned long arg)
{
	char smd_write_buf[GSERIAL_BUF_LEN];
	switch (cmd)
	{
		case GSERIAL_SMD_WRITE:
			if (copy_from_user(&smd_write_arg, argp, sizeof(smd_write_arg))){...}
			// 修改：添加校验
			if (smd_write_arg.size  >= GSERIAL_BUF_LEN) {......} 
			copy_from_user(smd_write_buf, smd_write_arg.buf, smd_write_arg.size);
 			...
	}
}
```

## 必须对copy_to_user()拷贝的数据进行初始化，防止信息泄漏

**【描述】**

**说明**：内核态使用copy_to_user()向用户态拷贝数据时，当数据未完全初始化（如结构体成员未赋值、字节对齐引起的内存空洞等），会导致栈上指针等敏感信息泄漏。攻击者可利用绕过kaslr等安全机制。

**【错误代码示例】**

未完全初始化数据结构成员。

```c
static long rmnet_ctrl_ioctl(struct file *fp, unsigned cmd, unsigned long arg)
{
	struct ep_info info;
	switch (cmd) {
		case FRMNET_CTRL_EP_LOOKUP:
			info.ph_ep_info.ep_type = DATA_EP_TYPE_HSUSB;
			info.ipa_ep_pair.cons_pipe_num = port->ipa_cons_idx;
			info.ipa_ep_pair.prod_pipe_num = port->ipa_prod_idx;
			// 错误: info结构体有4个成员，未全部赋值
			ret = copy_to_user((void __user *)arg, &info, sizeof(info)); 
			...
	}
}
```

**【正确代码示例】**

全部进行初始化。

```c
static long rmnet_ctrl_ioctl(struct file *fp, unsigned cmd, unsigned long arg)
{
	struct ep_info info;
	// 修改：使用memset初始化缓冲区，保证不存在因字节对齐或未赋值导致的内存空洞
	(void)memset(&info, '0', sizeof(ep_info)); 
	switch (cmd) {
		case FRMNET_CTRL_EP_LOOKUP:
			info.ph_ep_info.ep_type = DATA_EP_TYPE_HSUSB;
			info.ipa_ep_pair.cons_pipe_num = port->ipa_cons_idx;
			info.ipa_ep_pair.prod_pipe_num = port->ipa_prod_idx;
			ret = copy_to_user((void __user *)arg, &info, sizeof(info));
			...
	}
}
```

## 禁止在异常处理中使用BUG_ON宏，避免造成内核panic

**【描述】**

BUG_ON宏会调用内核的panic()函数，打印错误信息并主动崩溃系统，在正常逻辑处理中（如ioctl接口的cmd参数不识别）不应当使系统崩溃，禁止在此类异常处理场景中使用BUG_ON宏，推荐使用WARN_ON宏。

**【错误代码示例】**

正常流程中使用了BUG_ON宏

```c
/ * 判断Q6侧设置定时器是否繁忙，1-忙，0-不忙 */
static unsigned int is_modem_set_timer_busy(special_timer *smem_ptr)
{
	int i = 0;
	if (smem_ptr == NULL) {
		printk(KERN_EMERG"%s:smem_ptr NULL!\n", __FUNCTION__);
		// 错误：系统BUG_ON宏打印调用栈后调用panic()，导致内核拒绝服务，不应在正常流程中使用
		BUG_ON(1); 
		return 1;
	}

	...
}
```

**【正确代码示例】**

去掉BUG_ON宏。

```c
/ * 判断Q6侧设置定时器是否繁忙，1-忙，0-不忙  */
static unsigned int is_modem_set_timer_busy(special_timer *smem_ptr)
{
	int i = 0;
	if (smem_ptr == NULL) {
		printk(KERN_EMERG"%s:smem_ptr NULL!\n",  __FUNCTION__);
		// 修改：去掉BUG_ON调用，或使用WARN_ON
		return 1;
	}

	...
}
```

## 在中断处理程序或持有自旋锁的进程上下文代码中，禁止使用会引起进程休眠的函数

**【描述】**

系统以进程为调度单位，在中断上下文中，只有更高优先级的中断才能将其打断，系统在中断处理的时候不能进行进程调度。如果中断处理程序处于休眠状态，就会导致内核无法唤醒，从而使得内核处于瘫痪。

自旋锁在使用时，抢占是失效的。若自旋锁在锁住以后进入睡眠，由于不能进行处理器抢占，其它进程都将因为不能获得CPU（单核CPU）而停止运行，对外表现为系统将不作任何响应，出现挂死。

因此，在中断处理程序或持有自旋锁的进程上下文代码中，应该禁止使用可能会引起休眠（如vmalloc()、msleep()等）、阻塞（如copy_from_user(),copy_to_user()等）或者耗费大量时间（如printk()等）的函数。

## 合理使用内核栈，防止内核栈溢出

**【描述】**

内核栈大小是固定的（一般32位系统为8K，64位系统为16K，因此资源非常宝贵。不合理的使用内核栈，可能会导致栈溢出，造成系统挂死。因此需要做到以下几点：

- 在栈上申请内存空间不要超过内核栈大小；
- 注意函数的嵌套使用次数；
- 不要定义过多的变量。

**【错误代码示例】**

以下代码中定义的变量过大，导致栈溢出。

```c
...
struct result
{
	char name[4];
	unsigned int a;
	unsigned int b;
	unsigned int c;
	unsigned int d;
}; // 结构体result的大小为20字节

int foo()
{
	struct result temp[512];
	// 错误: temp数组含有512个元素，总大小为10K，远超内核栈大小
	(void)memset(temp, 0, sizeof(result) * 512); 
	... // use temp do something
	return 0;
}

...
```

代码中数组temp有512个元素，总共10K大小，远超内核的8K，明显的栈溢出。

**【正确代码示例】**

使用kmalloc()代替之。

```c
...
struct result
{
	char name[4];
	unsigned int a;
	unsigned int b;
	unsigned int c;
	unsigned int d;
}; // 结构体result的大小为20字节

int foo()
{
	struct result  *temp = NULL;
	temp = (result *)kmalloc(sizeof(result) * 512, GFP_KERNEL); //修改：使用kmalloc()申请内存
	... // check temp is not NULL
	(void)memset(temp, 0, sizeof(result)  * 512);
	... // use temp do something
	... // free temp
	return 0;
}
...
```

## 临时关闭地址校验机制后，在操作完成后必须及时恢复

**【描述】**

SMEP安全机制是指禁止内核执行用户空间的代码（PXN是ARM版本的SMEP）。系统调用（如open()，write()等）本来是提供给用户空间程序访问的。默认情况下，这些函数会对传入的参数地址进行校验，如果入参是非用户空间地址则报错。因此，要在内核程序中使用这些系统调用，就必须使参数地址校验功能失效。set_fs()/get_fs()就用来解决该问题。详细说明见如下代码：

```c
...
mmegment_t old_fs;
printk("Hello, I'm the module that intends to write message to file.\n");
if (file == NULL) {
	file = filp_open(MY_FILE, O_RDWR | O_APPEND | O_CREAT, 0664);
}

if (IS_ERR(file)) {
	printk("Error occurred while opening file %s, exiting ...\n", MY_FILE);
	return 0;
}

sprintf(buf, "%s", "The Message.");
old_fs = get_fs(); // get_fs()的作用是获取用户空间地址上限值  
                   // #define get_fs() (current->addr_limit
set_fs(KERNEL_DS); // set_fs的作用是将地址空间上限扩大到KERNEL_DS，这样内核代码可以调用系统函数
file->f_op->write(file, (char *)buf, sizeof(buf), &file->f_pos); // 内核代码可以调用write()函数
set_fs(old_fs); // 使用完后及时恢复原来用户空间地址限制值
...
```

通过上述代码，可以了解到最为关键的就是操作完成后，要及时恢复地址校验功能。否则SMEP/PXN安全机制就会失效，使得许多漏洞的利用变得很容易。

**【错误代码示例】**

在程序错误处理分支，未通过set_fs()恢复地址校验功能。

```c
...
oldfs = get_fs();
set_fs(KERNEL_DS);
/* 在时间戳目录下面创建done文件 */
fd = sys_open(path, O_CREAT | O_WRONLY, FILE_LIMIT);
if (fd < 0) {
	BB_PRINT_ERR("sys_mkdir[%s] error, fd is[%d]\n", path, fd);
	return; // 错误：在错误处理程序分支未恢复地址校验机制
}

sys_close(fd);
set_fs(oldfs);
...
```

**【正确代码示例】**

在错误处理程序中恢复地址校验功能。

```c
...
oldfs = get_fs();
set_fs(KERNEL_DS);

/* 在时间戳目录下面创建done文件 */
fd = sys_open(path, O_CREAT | O_WRONLY, FILE_LIMIT);
if (fd < 0) {
	BB_PRINT_ERR("sys_mkdir[%s] error, fd is[%d] \n", path, fd);
	set_fs(oldfs); // 修改：在错误处理程序分支中恢复地址校验机制
	return;
}

sys_close(fd);
set_fs(oldfs);
...
```

