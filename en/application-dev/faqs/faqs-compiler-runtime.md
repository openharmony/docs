# Compiler Runtime

## What if a crash occurs when I obtain a string in JSON format from rawfile, convert the string into an object, and call the instance method?

Applicable to: OpenHarmony 3.2 Beta (API version 9)  

**Symptom**

"jscrash happened in xxxxxxxxx" is displayed, and the crash log contains "Error message: Unexpected Object in JSON".

**Solution**

The prototype of the object obtained by parsing the string in JSON format is object. The prototype chain does not contain the instance method. Therefore, the object cannot be called.

To solve this problem, use either of the following methods:
1. Add the prototype to the parsed object.
2. Change the instance method to a static method and call it through the class name.
