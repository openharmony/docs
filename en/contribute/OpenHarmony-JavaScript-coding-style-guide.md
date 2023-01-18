# JavaScript Coding Style Guide

## Goal
Rules are not perfect. Prohibiting features that are useful in specific situations can have an impact on code implementation, but we set the rules for the benefit of most programmers. If we identify a rule cannot be followed in the operations, we should work together to improve the rule. You are supposed to have the basic JavaScript language capabilities to refer to this guide, instead of learning the JavaScript language from it.

## General Principles
The code is required to be **readable, maintainable, secure, reliable, testable, efficient, and portable** on the premise that the functions are correct.

## Convention

**Rule**: Conventions that must be complied with during programming
**Recommendation**: Conventions that must be considered during programming  

It is important to understand why this convention is so stated in both "Rules" or "Recommendations" and make efforts to comply.

## Exceptions

If the General Principle is not violated, the rules can be properly violated after full consideration and sufficient reasons are provided.
Exceptions compromise code consistency so please avoid exceptions. Exceptions to "Rules" should be rare.

The style consistency principle is preferred in the following situations:
**When modifying external open-source code and third-party code, comply with the existing rules of the open-source code and third-party code and keep the style consistent. ** 

## Programming Regulations

### Naming Regulations

#### Rule 1.1 Use correct English spellings to name, no use of pinyin spellings.

**Counterexample:**`xingming`,`zhanghao`

**Example:**`username`,`account`

#### Rule 1.2 Use abbreviations as few as possible, except for common words or professional words. For example, `context` can be shortened to `ctx`, `request` can be shortened to `req`, and `response` can be shortened to `resp`.

**Note:** Complete spelling of words can avoid unnecessary misunderstanding.

**Exceptions:** The variable name of the cyclic condition can be ` i` or ` j` in the cyclic language.

#### Rule 1.3 Class name, enumeration name and namespace name should comply the `upperCamelCase` style.

**Example:**

```javascript
// Class name
class User {
  constructor(username) {
    this.username = username;
  }
  
  sayHi() {
    console.log(`hi, ${this.username}`);
  }
}

// Enumeration name
const UserType = {
  TEACHER: 0,
  STUDENT: 1
};

// Namespace
const Base64Utils = {
  encrypt: function(text) {
    // todo encrypt
  },
  decrypt: function(text) {
    // todo decrypt
  }
};
```

#### Rule 1.4 Variable name, method name, and parameter name should comply the `lowerCamelCase` style.

**Example:**

```javascript
let msg = 'Hello world';

function sendMsg(msg) {
  // todo send message
}

function findUser(userID) {
  // todo find user by user ID
}
```

#### Rule 1.5 The names of static constants and enumeration values must be in upper case, and words are separated by underscores (_).

**Example:**

```javascript
const MAX_USER_SIZE = 10000;

const UserType = {
  TEACHER: 0,
  STUDENT: 1
};
```

#### Recommendation 1.6 Do not use negative Boolean variable names. Local variables or methods of the Boolean type must be prefixed with expressions with the meaning of right or wrong.

**Counterexample:**

```javascript
let isNoError = true;
let isNotFound = false;
function empty() {}
function next() {}
```

**Example:**

```javascript
let isError = false;
let isFound = true;
function isEmpty() {}
function hasNext() {}
```

### Code Format

#### Rule 2.1 Use two spaces to indent, and do not use the `tab` character.    

**Note:** Only spaces are allowed for indentation. Two spaces are allowed at a time. Tab characters are not allowed for indentation.

**Example:**

```javascript
const dataSource = [
  {
    id: 1,
    title: 'Title 1',
    content: 'Content 1'
  },
  {
    id: 2,
    title: 'Title 2',
    content: 'Content 2'
  }
];

function render(container, dataSource) {
  if (!container || !dataSource || !dataSource.length) {
    return void 0;
  }

  const fragment = document.createDocumentFragment();
  for (let data of dataSource) {
    if (!data || !data.id || !data.title || !data.content) {
      continue;
    }
    const element = document.createElement("div");
    const textNode = document.createTextNode(`${data.title}: ${data.content}`);
    element.appendChild(textNode);
    element.setAttribute("id", data.id);
    fragment.appendChild(element);
  }
  container.appendChild(fragment);
}

```

#### Rule 2.2 The line width cannot exceed 120 characters.

**Note:** It is recommended that each line should contain no more than 120 characters. Use a proper method to break the line if the line contain more than 120 characters.

**Exception:** If a line of comments contains more than 120 characters of commands or URLs, keep it in one line for easy copying, pasting, and searching by running the grep command. The preprocessed error information is easy to read and understand in one line, even if it contains more than 120 characters.

#### Rule 2.3 The use of braces must comply with the following conventions:

1. If the value in the braces is empty, the value can be abbreviated as `{}` without a line feed.
2. Do not use a line feed before the left brace, and use one after it.
3. Use a line feed before the right brace, and use one after it as long as it is not followed by `else` or `catch`.

#### Rule 2.4 Implementations of conditional and loop statements must be enclosed in braces, even if there is only one statement.

**Counterexample:**

```javascript
if (condition)
  console.log('success');

for(let idx = 0; idx < 5; ++idx)
  console.log(idx);
```

**Example:**

```javascript
if (condition) {
  console.log('success');
}

for(let idx = 0; idx < 5; ++idx) {
  console.log(idx);
}
```

#### Rule 2.5 Condition statements and loop statements cannot be written in one line.

**Counterexample:**

```javascript
if (condition) { /* todo something */ } else { /* todo other */ }

let idx = 0;
while(idx < 10) console.log(idx);
```

**Example:**

```javascript
if (condition) {
  /* todo something */
} else {
  /* todo other */
}

let idx = 0;
while(idx < 10) {
  console.log(idx);
}
```

#### Rule 2.6 The `case` and `default` in the `switch` statement must be indented by one layer.

**Example:**

```javascript
switch(condition) {
  case 0:
    doSomething();
    break;
  case 1: { // the braces is not necessary
    doOtherthing();
    break;
  }
  default:
    break;
}
```

#### Rule 2.7 The line feeds of expressions must be consistent, and the operator must be placed at the end of the line.

**Note:** If a long expression does not meet the line width requirement, you need to wrap the line in a proper position. Generally, in the late phrase of the lower-priority operator or connector, the operator or connector should be placed at the end of the line. The operator and separator are placed at the end of the line, indicating that there is not the end.

**Example:**

```javascript
// if the condition statement exceeds the line width.
if (userCount > MAX_USER_COUNT ||
  userCount < MIN_USER_COUNT) {
  doSomething();
}

const sum =
  number1 +
  number2 +
  number3 +
  number4 +
  number5 +
  number6 +
  number7 +
  number8 +
  number9;
```

#### Rule 2.8 Multiple variable definitions and assignment statements cannot be written in one line.

**Counterexample:**

```javascript
let maxCount = 10, isCompleted = false;

let pointX, pointY;
pointX = 10; pointY = 0;
```

**Example:**

```javascript
let maxCount = 10;
let isCompleted = false;

let pointX = 0;
let pointY = 0;
```

#### Rule 2.9 Spaces should highlight keywords and important information. Avoid unnecessary spaces.

**Note:** Spaces reduce code density and increase code readability. The general rules are as follows:

1. Add a spaces after keywords `if`、`elseif`、`else`、`switch`、`while`、`for`.
2. No space is added between the parentheses.
3. Spaces must be added on both sides of the braces, except for simple scenarios such as `{}`.
4. No space is added between multiple parentheses.
5. No space is added after unary operators (`&`, `*`, `+`, `-`, `!`,etc.).
6. Add a space on the left and right side of binary operators `=`、`+`、`-`、`*`、`/`、`%`、`|`、`&`、`||`、`&&`、`<`、`>`、`<=`、`>=`、`==`、`!=`、`===`、`!==`, etc.)
7. Add a space on the left and right side of ternary operator （`?: `）.
8. No space is added between the preceded or post-decrease (`++`, `--`) and variables.
9. Add a space before a comma (`, `).
10. Add a space after `//` in a single line.
11. No space is added at the end of the line.

#### Rule 2.10 Expression statements must end with a semicolon.

**Counterexample:**

```javascript
let username = 'jack'
let birthday = '1997-09-01'

console.log(`${username}'s birthday is ${birthday}`)
```

**Example:**

```javascript
let username = 'jack';
let birthday = '1997-09-01';

console.log(`${username}'s birthday is ${birthday}`);
```

#### Recommendation 2.11 Use single quotation marks to wrap strings first.

**Example:**

```javascript
let message = 'world';
console.log(message);
```

### Code instructions

#### Rule 3.1 When declaring a variable, use the keyword `var`, `let`, or `const` to prevent the variable from being exposed to the global scope.

**Note:** If the keyword `var`, `let`, or `const` is not used to declare a variable, the variable will be exposed to the global scope, which may overwrite the variable with the same name in the global scope. As a result, the GC cannot effectively reclaim the memory. In addition, when a variable contains sensitive information, exposing to the global scope may result in information leakage. ** Use `const` instead of `var` for all references; Use `let` instead of `var` if you need a variable reference.** Because the scope of `const` and `let` is smaller, writing code is easier to control. Const ensures that the reference cannot be re-assigned. The pointer referenced by const is immutable, and an error will be reported during re-assignment, avoiding overwriting.

**Counterexample:**

```javascript
function open() {
  url = 'http://127.0.0.1:8080'; //url will be exposed to the global scope
  //todo something
}
open();
console.log(url); //url can be accessed, output: http://127.0.0.1:8080
```

**Example:**

```javascript
function open() {
  let url = 'http://127.0.0.1:8080';
  // todo something
}
open();
console.log(url); //Report: Uncaught ReferenceError: url is not defined
```

```javascript
function open() {
  const url = 'http://127.0.0.1:8080';
  //todo something
}
open();
console.log(url); //Report: Uncaught ReferenceError: url is not defined
```

#### Rule 3.2 Function expressions must be used to declare functions in function blocks.

**Note:** Although many JS engines support in-block declaration functions, they do not belong to the ECMAScript specification. The poor implementation of browsers is incompatible with each other, and some are contrary to the future ECMAScript draft. In addition, ECMAScript5 does not support block scopes. All control flows are not independent scopes. Variables or functions declared in the control flows are in the scope of their parent functions or scripts. As a result, the declaration of functions or variables in blocks may be overwritten. If you do need to define a function in a block, you should initialize it using a function expression.

**Counterexample:**

```javascript
function bar(name) {
  if (name === "hotel") {
    // 1. Define a foo function. The function scope is not the 'if' code block but the 'bar' function scope.
    function foo() {
      console.log("hotel foo A");
    }
  } else {
    // 2. Define the 'foo' function again to overwrite the 'foo' function definition under the 'if' condition branch.
    function foo() {
      console.log("hotel foo 2");
    }
  }
  foo && foo();
}
bar("hotel"); // output is shown as"hotel foo 2"
```

**Example:**

```javascript
function bar(name) {
  var foo;
  if (name == "hotel") {
    foo = function () {
      console.log("hotel foo 1");
    };
  } else {
    foo = function () {
      console.log("hotel foo 2");
    }
  }
  foo && foo();
}
bar("hotel"); // Correct output"hotel foo 1"
```

#### Rule 3.3 Encapsulation of Basic Types is prohibited

**Note:** JavaScript has five basic data types: Undefined, Null, Boolean, Number, and String. The value of the base data type is unchangeable. The basic data type object used in JavaScript is only a value. It does not contain the methods and attributes of the object encapsulated by the object. When the attributes and methods are not required, the encapsulation type of the object does not need to be used.

**Counterexample:**

```javascript
var isShow = new Boolean(false);
if (isShow) {
  alert('hi'); //It is executed, and the following information is displayed: hi
}
```

**Example:**

```javascript
var isShow = false;
if (isShow) {
  alert('hi');
}
```

#### Rule 3.4 The use of `with` is prohibited

**Note:** Using 'with' makes your code semantically unclear, because objects of 'with' may conflict with local variables, changing the original meaning of the program.

**Counterexample:**

```javascript
var foo = { x: 5 };
with(foo) {
  var x = 3;
  console.log(x); //Output: 5
}
```

#### Rule 3.5 `this` can only be used in object constructors, methods, and closures.

**Note:** In JavaScript, the "this" pointer represents the owner of the object that executes the current code. This has special semantics:

+ Global objects (in most cases)
+ Scope of the caller (when eval is used)
+ Nodes in the DOM tree (when adding event handling functions)
+ Newly created object (using a constructor)
+ Other objects (if the function is called() or apply())

```javascript
var User = function(username) {
  this.username = username;
};
var user = new User('John');
console.log(user.username); // Output: John

var ClickCounter = {
  value: 0,
  click: function() {
    ++this.value;
  },
  getValue() {
    return this.value;
  }
};
console.log(Counter.getValue()); //Output: 0
Counter.click();
console.log(Counter.getValue()); //Output: 1
```

#### Rule 3.6 Do not use conditional comments in IE.

**Note:** Conditional compilation can be activated using the `\@cc_on` statement or the `\@if` or `\@set` statement in IE. Although comments can be made to be compatible with browsers other than IE, they hinder the execution of automation tools because they change the JavaScript syntax tree at run time.

**Counterexample:**

```javascript
var f = function () {
  /*@cc_on @*/
  /*@if (@_jscript_version >= 4)
       alert("JavaScript version 4 or better");
    @else @*/
  alert("Conditional compilation not supported by this scripting engine.");
  /*@end @*/
};
```

#### Rule 3.7 Prototypes of built-in objects cannot be modified.

**Note:** As a set of public interfaces, built-in objects have conventional behaviors. Modifying the prototype may damage the interface semantics or cause abnormalities during debugging.

**Counterexample:**

```javascript
Array.prototype.indexOf = function () { return -1 }
var arr = [1, 1, 1, 1, 1, 2, 1, 1, 1];
console.log(aar.indexOf(2)); // Output:-1
```

#### Rule 3.8 Do not directly use the built-in attribute of `Object.prototype`.   

**Note:** ECMAScript 5.1 adds `Object.create`, which creates a new object and uses an existing object to provide the proto of the newly created object. `Object.create(null)` is a common pattern for creating objects used as maps. Unexpected behavior or vulnerability may occur when the object has an attribute with the same name as `Object.prototype`. For example, it is not safe for a web server to parse JSON input from a client and use `hasOwnProperty` to directly invoke the generated object, because a malicious client may send a similar JSON value `' {"hasOwnProperty": 1} '` and cause the server to crash.

**Counterexample:**

```javascript
var hasBarProperty = foo.hasOwnProperty("bar");
var isPrototypeOfBar = foo.isPrototypeOf(bar);
var barIsEnumerable = foo.propertyIsEnumerable("bar");
```

**Example:**

```javascript
var hasBarProperty = Object.prototype.hasOwnProperty.call(foo, "bar");
var isPrototypeOfBar = Object.prototype.isPrototypeOf.call(foo, bar);
var barIsEnumerable = {}.propertyIsEnumerable.call(foo, "bar");
```

#### Rule 3.9 Use the `Object.getPrototypeOf` function instead of `_proto_`

**Note:** ES5 introduces the `Object.getPrototypeOf` function as the standard API for obtaining object prototypes, but a large number of JavaScript engines have long used a special `proto' attribute to achieve the same purpose. However, `proto` is essentially an internal attribute rather than a formal external API. Currently, this attribute must be deployed in browsers, but not in other running environments. Therefore, this attribute is not fully compatible. For example, objects with null prototypes are handled differently in different environments.

```javascript
var empty = Object.create(null);
"_proto_" in empty; //Some environments false is returned, some environments true is returned.
```

Therefore, use `Object.getPrototypeOf()` instead of using the proto attribute in terms of semantics and compatibility. The `Object.getPrototypeOf' function is valid in any environment and is a more standard and portable method for extracting object prototypes.

#### Rule 3.10 Do not create functions with function constructors.

**Note:** There are three methods for defining a function: function declaration, function constructor, and function expression. Regardless of in which method you define a function, they are instances of the Function object and inherit all default or custom methods and properties of the Function object. The method of creating a function using a function constructor is similar to the character string `eval()`. Any character string can be used as the function body, which may cause security vulnerabilities.

**Counterexample:**

```javascript
var func = new Function('a', 'b', 'return a + b');
var func2 = new Function('alert("Hello")');
```

**Example:**

```javascript
function func(a, b) {
  return a + b;
}

var func2 = function(a, b) {
  return a + b;
}
```

#### Suggestion 3.11 When using the prototype `prototype' to implement inheritance, try to use the existing stable library methods instead of self-implementing them.

**Note:** The multi-level prototype structure refers to the inheritance relationship in JavaScript. When you define a class D and use class B as its prototype, you get a multilevel prototype structure. These prototype structures can get complicated. Using existing stable library methods such as `goog.inherits()` of the Closure library or other similar functions can avoid unnecessary coding errors.

#### Suggestion 3.12 When defining a class, you should define the method under the prototype and the attributes within the constructor.

**Note:** There are multiple methods in JavaScript to add methods or members to constructors. However, using a prototype to define methods can reduce memory usage and improve running efficiency.

**Counterexample:**

```javascript
function Animals() {
  this.walk = function() {}; // This causes a walk method to be created on each instance.
}
```

**Example:**

```javascript
function Animals() {}

Animals.prototype.walk = function() {};
```

#### Suggestion 3.13 When using closures, avoid cyclic reference, which may cause memory leakage.

**Note:** 
JavaScript is a garbage collection language in which the memory of an object is allocated to the object based on its creation and is reclaimed by the browser when there is no reference to the object. JavaScript's garbage collection mechanism is fine on its own, but browsers are somewhat different in the way they allocate and recover memory for DOM objects. Both IE and Firefox use reference counting to process memory for DOM objects. In the reference counting system, each referenced object keeps a count to see how many objects are referencing it. If the count is zero, the object is destroyed and the memory it occupies is returned to the heap. While this solution is generally effective, there are some blind spots in circular references. When two objects refer to each other, they form a circular reference, where the reference counting values of the objects are assigned to 1. In pure garbage collection systems, circular references are not a problem: if one of the two objects involved is referenced by any other object, both objects will be garbage collected. In a reference counting system, neither of these objects can be destroyed because reference counting can never be 0. In a hybrid system that uses both garbage collection and reference counting, a leak occurs because the system does not correctly recognize circular references. In this case, neither the DOM object nor the JavaScript object can be destroyed. Circular references are easy to create. Circular references are particularly prominent in closures, one of JavaScript's most convenient programming structures. Closures hold references to their external scopes (including local variables, parameters, and methods). When the closure itself is held by scope members (usually DOM objects), circular references are formed, which further leads to memory leaks.

**Counterexample:**

```javascript
function setClickListener(element, a, b) {
  element.onclick = function() {
    // Use a and b here
  };
};
```

In the above code, the closure retains references to elements, a, and b even if element is not used. Because the element also retains the reference to the closure, a circular reference is generated and cannot be recycled by the GC.

**Example:**

```javascript
function setClickListener(element, a, b) {
  element.onclick = createHandler(a, b);
}

function createHandler(a, b) {
  // By adding another function to avoid the closure itself, you can organize memory leaks.
  return function() {
    // Use a and b here
  }
}
```

#### Suggestion 3.14 Watch out for JavaScript floating point numbers.

**Note:** JavaScript has a single numeric type: `IEEE 754` double-precision floating point number. Having a single numeric type is one of the best features of JavaScript. Multiple number types can be a source of complexity, confusion and error. However, one of the biggest drawbacks of the binary floating-point type is that it does not accurately represent the fractional part, causing unexpected precision problems, as shown in the following examples.

Sample Code1:

```javascript
console.log(0.1 + 0.2 === 0.3); // Output: false. Therefore, do not use == or === to compare floating-point numbers.
```

Sample Code2:

```javascript
var sum1 = (0.1 + 0.2) + 0.3;
console.log(sum1); // Output: 0.6000000000000001

var sum2 = 0.1 + (0.2 + 0.3);
console.log(sum2); // Output: 0.6. Therefore, for binary floating-point numbers, (a + b) + c cannot be guaranteed to produce the same result as a + (b + c).
```

The effective solutions are as follows:

1. Use integers as much as possible because integers do not need to be rounded.

2. The native JavaScript method `Number.prototype.toFixed(digits)`,`digits` is used to indicate the number of digits after the decimal point. The exponential method is not used. If necessary, the number is rounded off. This method is used to reduce the precision of the calculation result before determining the floating-point number calculation result. The sample code is as follows:

   ```javascript
   parseFloat(0.1 + 0.2).toFixed(1); //0.3
   ```

3. A very small constant `Number.EPSILON =.220446049250313e-16 ` is added to ES6, which is about 0.00000000000000022204. `Number.EPSILON` is used to determine the calculation error of floating-point numbers. If the calculation error of floating-point numbers is less than or equal to the value of `Number.EPSILON`, such an error is acceptable. The sample code is as follows:

   ```javascript
   function isNumberEquals(one, other) {
     return Math.abs(one - other) < Number.EPSILON;
   }
   var one = 0.1 + 0.2;
   var other = 0.3;
   console.log(isNumberEquals(one, other)); // Output: true
   ```

4.  Use some class library methods that support precise calculation, such as `math.js`.

   ```html
   <!DOCTYPE html>
   <html>
     <head>
       <script src="https://cdnjs.cloudflare.com/ajax/libs/mathjs/5.0.0/math.js"></script>
       <script type="text/javascript">
         function fn_click() {
           math.config({
             number: "BigNumber",
           });
           var result = math.add(math.bignumber(0.1), math.bignumber(0.2));
           alert(result);
         }
       </script>
     </head>
     <body>
       <input type="button" value="mathjs(0.1+0.2)" onclick="fn_click();" />
     </body>
   </html>
   
   ```

#### Suggestion 3.15 Do not use the array constructor with variable arguments.

**Note:** The method of constructor `new Array` is not recommended to construct a new array. If the constructor has only one parameter, exceptions may occur. In addition, the global definition of the array may be modified. Therefore, it is recommended to use the array literal notation, that is, `[]` notation, to create an array.

**Counterexample:**

```javascript
const arr1 = new Array(x1, x2, x3);
const arr2 = new Array(x1, x2);
const arr3 = new Array(x1);
const arr4 = new Array();
```

Except for the third case, all other functions can work properly. If `x1` is an integer, `arr3` is an array whose length is `x1` and values are `undefined`. If `x1` is any other number, an exception is thrown, and if it is anything else, it is an array of cells.

**Example:**

```javascript
const arr1 = [x1, x2, x3];
const arr2 = [x1, x2];
const arr3 = [x1];
const arr4 = [];
```

This way, you'll save a lot of trouble.

Similarly, use `{}` instead of `new Object()` to create objects.

#### Rule 3.16 String templates are preferred over string links when constructing strings.

**Note:** The template character strings are more concise and readable.

**Counterexample:**

```javascript
function sayHi(name) {
  console.log('hi, ' + name);
}
```

**Example:**

```javascript
function sayHi(name) {
  console.log(`hi, ${name}`);
}
```

#### Rule 3.17 Use `for...of` for array traversal and `for...in` for object traversal.

**Counterexample:**

```javascript
let numbers = [1, 2, 3, 4];
let sum = 0;
for (let number in numbers) {
  sum += number;
}
// sum === 00123;
```

**Example:**

```javascript
let numbers = [1, 2, 3, 4];
let sum = 0;
for (let number of numbers) {
  sum += number;
}
// sum === 10
```

