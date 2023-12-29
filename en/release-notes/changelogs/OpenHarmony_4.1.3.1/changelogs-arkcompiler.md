# ArkCompiler Subsystem Changelog

## cl.ArkCompiler.1 TypeScript Syntax Check Change

**Access Level** 
Other

**Reason for Change** 
The TypeScript version in the OpenHarmony SDK is upgraded from 4.2.3 to 4.9.5. The new version supports more syntax features and provides higher type check capabilities. However, there are a few syntax features that are incompatible with earlier versions.

**Change Occurrence Version** 
OpenHarmony SDK 4.1.3.1

**Change Impact** 
Compared with earlier versions, the syntax check in the new TypeScript version is stricter. It has 10 types of syntax features that are incompatible with the existing syntax. The following describes these syntax features and provides simple examples.

**Changed Syntax Features and Adaptation Guide**

1. Union enums cannot be compared to arbitrary numbers. 
Enums are considered union enums when their members are either automatically filled in, or trivially written. An enum of this type can recall each value that it potentially represents.
The following is an incorrect example:

    ```
    enum E {
      A = 0,
      B = 1,
    }
    function doSomething(x: E) {
      // Error! This condition will always return 'false' since the types 'E' and '-1' have no overlap.
      if (x === -1) {
        // ...
      }
    }
    ```
    Adaptation suggestion: Use the **toString()** method to convert a number into a string for comparison.

2. More compliant indirect calls to imported functions. 
   When an import from a non-ES module (such as the commonjs module in the FA model) is called, the **this** value is discarded, just as when an import from an ES module is called. 
   The following example shows the change:
   ```
    // Assume that this is the imported module, which has a 'foo' and 'feature' export.
    let fooModule = {
      foo() {
        console.log(this);
      },
      feature: 'oh'
    };

    // Behavior before the change:
    fooModule.foo(); // Output: {"feature": "oh"}
    
    // Behavior after the change (in effect, '(0, fooModule.foo) is called, which is slightly different from the preceding behavior):
    (0, fooModule.foo)(); // Output: undefined
   ```
3. Abstract properties do not allow initializers. 
The following code will report an error because abstract properties are not allowed have initializers:
    ```
    abstract class C {
      abstract prop = 1;
      //       ~~~~
      // Property 'prop' cannot have an initializer because it is marked abstract.
    }
    ```
    Adaptation suggestion: Delete the initializer.
4. The rest parameter syntax deletes unexpandable members from generic objects. 
When being deconstructed from generic objects, properties are regarded as all deconstructible in earlier versions. In the new version, they are strictly analyzed to find out whether they can be deconstructed. Properties that should not be deconstructed include private properties, private methods, and static properties. The following code will report an error:
    ```
    class Thing {
      someProperty = 42;
      someMethod() {
        // ...
      }
    }
    function foo<T extends Thing>(x: T) {
      let { someProperty, ...rest } = x;
      // Used to work, is now an error!
      // Property 'someMethod' does not exist on type 'Omit<T, "someProperty" | "someMethod">'.
      rest.someMethod();
    }
    ```
    Adaptation suggestion: When deconstructing a property from a generic object, make sure it can be deconstructed.
5. There are stricter checks with template string expressions. 
If a symbol value is used in JavaScript, both JavaScript and TypeScript will throw an error. However, TypeScript now checks whether a generic value contained in a symbol is used in the template string. 
    ```
    function logKey<S extends string | symbol>(key: S): S {
        // Implicit conversion of a 'symbol' to a 'string' will fail at runtime. Consider wrapping this expression in 'String(...)'.
        console.log(`${key} is the key`);
        return key;
    }
    ```
    Adaptation suggestion: Wrap the expression in **'String(...)'**.
6. Read-only tuples have a read-only length property. 
    The read-only tuple now treats the length property as read-only. This can be seen for tuples with optional trailing and rest element types.
    ```
    function overwriteLength(tuple: readonly [string, string, string]) {
        // Now errors.
        tuple.length = 7;
    }
    ```
7. Objects cannot be compared with array literals. 
Value-comparison operations '==' and '===' between objects (and arrays) in JavaScript check whether two references point to the same value. Now the following code will report an error:
    ```
    if (peopleAtHome === []) {
    //  ~~~~~~~~~~~~~~~~~~~
    // This condition will always return 'false' since JavaScript compares objects by reference, not value.
        console.log("here's where I lie, broken inside. </3")
        adoptAnimals();
    }
    ```
8. Unused renames are not allowed in type signatures. 
In the following example, you might think that **makePerson** takes an object with a **name** property of the string type and an **age** property of the number type. However, the destructuring syntax is actually taking precedence here. **makePerson** renames **name** and **age** to **string** and **number** respectively.
    ```
    declare function makePerson({ name: string, age: number }): Person;
    ```
    The correct way to write the above signature is as follows: 
    ```
    declare function makePerson(options: { name: string, age: number }): Person;
    // or
    declare function makePerson({ name, age }: { name: string, age: number }): Person;
    ```
9. Checks for equality on NaN. 
An error will be reported on direct comparisons against NaN.
    ```
    function validate(someValue: number) {
        return someValue !== NaN;
        //     ~~~~~~~~~~~~~~~~~
        // error: This condition will always return 'true'. Did you mean '!Number.isNaN(someValue)'?
    }
    ```
    Adaptation suggestion: Use **Number.isNaN** instead.
10. Errors caused by enhanced type inference and check capabilities 
After TypeScript is upgraded to 4.9.5, its type inference and check capabilities are enhanced, and syntax errors other than those described above may be detected. Correcting these syntax errors help improve run-time performance.
