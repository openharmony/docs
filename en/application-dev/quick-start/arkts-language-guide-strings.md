# Strings

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=c25b60c237b212cfc232b5aee67d2c42ba90278a translatedAt=2026-08-13T09:03:47.765Z pushedAt=2026-08-13T14:12:28.192Z -->

A string is a basic type that represents text data. ArkTS provides a rich set of string operation methods and supports features such as template strings and Unicode handling.

## String Literals

A string literal is the basic way to represent text data. ArkTS supports three forms of string literals: single quotes, double quotes, and template strings. They are used to represent text content (such as user input, messages, and configuration values), define identifiers and names (such as file paths and API endpoints), construct output information (such as logs and error messages), and store and pass text data.

### String Declaration

A string can be declared with single quotes, double quotes, or backticks. Single quotes are recommended for style consistency.

<!-- @[string_literal_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let single: string = 'Hello';
let double: string = "World";
let template: string = `ArkTS`;
```

Single quotes are the most common form. Double quotes are functionally identical to single quotes (single quotes are recommended) and are mainly used for JSON data or strings that contain single quotes. Template strings (backticks) support more features such as interpolation and multiline text.

### Multiline String Literals

Template strings (backticks) natively support multiline text without escape characters, making them suitable for storing long text (such as email content and HTML fragments), writing code fragments (such as SQL queries), and formatting reports and document output.

<!-- @[multiline_string](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let multiLine: string = `Line 1
Line 2
Line 3`;

let paragraph: string = `This is a paragraph
that spans multiple lines
of text`;
```

Line breaks, indentation, and spaces within backticks are all preserved, so the format matches the displayed result, which facilitates reading and maintenance.

### Special Characters in String Literals

Special characters must be represented using escape characters, including the newline character `\n`, the tab character `\t`, quotation marks, and so on.

<!-- @[escape_characters](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let newline: string = 'Line1\nLine2';
let tab: string = 'Column1\tColumn2';
let quote: string = 'It\'s a test';
let backslash: string = 'Path: C:\\Users';
let mixed: string = 'Hello\n\tWorld';
```

### Template Strings

Template strings (backticks) preserve the original format (line breaks and spaces), making it easy to embed multi-line code in a string while keeping it readable.

<!-- @[template_string_escape](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
// Template strings preserve line breaks and spaces.
let code: string = `
function hello() {
  console.info('Hello');
}
`;

// Escape backticks and $.
let escaped: string = `Price: \$100`;
let backtick: string = `Use \`backticks\``;
```

In a template string, `${}` triggers an interpolation expression. Escape `$` or wrap it in backticks to avoid unintended interpolation; escape backticks to avoid terminating the string prematurely.

## String Mutability

Strings are immutable; all modification operations return a new string.

### Declaring Mutable Strings

Use `let` to declare a string variable that can be reassigned. This is suitable for scenarios such as dynamically building content, updating state at runtime, processing messages, and receiving user input.

<!-- @[string_reassignment](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let message: string = 'Hello';
message = 'Hello, World';  // Reassign

let text: string = '';
text += 'Part 1';
text += ' Part 2';
```

Both reassignment and `+=` concatenation create a new string object; the string object itself is immutable.

### Declaring Immutable Strings

Use `const` to declare a string constant and ensure that its value is not reassigned. This applies to immutable information such as configuration constants (for example, the app name and version number), fixed messages, and API endpoints. Uppercase naming (for example, `const APP_NAME`) is recommended, with centralized definitions and type annotations for easier management.

<!-- @[ts_string_constant](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Strings.ts) -->

``` TypeScript
const APP_NAME: string = 'MyApp';
const VERSION: string = '1.0.0';

APP_NAME = 'NewApp';  // Compilation error: cannot reassign
```

### String Immutability

A string cannot be modified after it is created. All operations return a new string, which is a core characteristic of strings.

<!-- @[ts_string_immutability](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Strings.ts) -->

``` TypeScript
let original: string = 'Hello';

// The method returns a new string.
let modified: string = original.toUpperCase();
console.info(`${original}`);  // "Hello" (the original string remains unchanged)
console.info(`${modified}`);  // "HELLO"

// The string content cannot be modified directly.
original[0] = 'J';  // Invalid operation.
```

## Characters

ArkTS does not have a dedicated character type. A single character is represented by a string.

### Iterating over Characters in a String

You can access each character in a string one by one through indexing or a for-of loop.

<!-- @[string_iteration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let iterText: string = 'Hello';

// Use for...of to iterate over characters.
for (let char of iterText) {
  console.info(`${char}`);
}

// Use a for loop to iterate.
for (let i: number = 0; i < iterText.length; i++) {
  let char: string = iterText[i];
  console.info(`${char}`);
}

// Use split to convert to an array.
let chars: string[] = iterText.split('');
for (let char of chars) {
  console.info(`${char}`);
}
```

### Representing and Using a Single Character

A character can be represented using a Unicode escape or directly as a single-character string.

<!-- @[character_access](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let accessText: string = 'Hello';

// Obtain a single character.
let firstChar: string = accessText.charAt(0);   // 'H'
let secondChar: string = accessText.charAt(1);   // 'e'

// Character encoding.
let accessCode: number = accessText.charCodeAt(0);     // 72 (Unicode of 'H')
let codePoint: number = accessText.codePointAt(0) ?? 0; // 72

// Create a character from a code.
let charFromCode: string = String.fromCharCode(72);  // 'H'
```

## String Concatenation

String concatenation is implemented through the `+` operator or template literals (`...${}...`).

### String and String Concatenation

Strings can be combined into a new string using the + operator or concatenation methods.

<!-- @[string_concatenation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let firstName: string = 'John';
let lastName: string = 'Doe';

// Use the + operator.
let fullName: string = firstName + ' ' + lastName;  // "John Doe"

// Use the concat method.
let combined: string = firstName.concat(' ', lastName);  // "John Doe"

// Use the join method.
let parts: string[] = [firstName, lastName];
let joined: string = parts.join(' ');  // "John Doe"
```

### Concatenating Strings and Characters

When a string is concatenated with a character, the character is automatically converted to its string form.

<!-- @[string_append](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let appendText: string = 'Hello';
let char: string = '!';

let result: string = appendText + char;  // "Hello!"

// Concatenate multiple characters.
let appendChars: string[] = ['a', 'b', 'c'];
let combinedChars: string = appendChars.join('');  // "abc"
```

### Concatenation Assignment

The concatenation assignment operator `+=` appends the string on the right to the variable on the left, simplifying concatenation code.

<!-- @[compound_assignment_concat](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let compoundMessage: string = '';

// Use += to concatenate by assignment.
compoundMessage += 'Hello';
compoundMessage += ' ';
compoundMessage += 'World';
console.info(`${compoundMessage}`);  // "Hello World"

// Use compound assignment.
let compoundText: string = 'Part 1';
compoundText += ' Part 2';  // "Part 1 Part 2"
```

## String Interpolation

Template strings use `${}` to insert variables and expressions.

### Basic Interpolation Usage

A template string uses `${}` to embed expressions, and the expression results are automatically converted to strings.

<!-- @[template_interpolation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let name: string = 'Alice';
let age: number = 25;

// Variable interpolation
let interpMessage: string = `Hello, ${name}`;
console.info(`${interpMessage}`);  // "Hello, Alice"

// Expression interpolation
let info: string = `Name: ${name}, Age: ${age}`;
let nextAge: string = `Next year: ${age + 1}`;

// Object property interpolation
interface User {
  name: string;
  email: string;
}

let user: User = { name: 'Bob', email: 'bob@example.com' };
let profile: string = `User: ${user.name} (${user.email})`;
```

### Limitations of Interpolation Expressions

An interpolation expression must be a valid expression and cannot contain unescaped backticks or dollar signs ($).

<!-- @[ts_template_expressions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Strings.ts) -->

``` TypeScript
// Supported expression types
let a: number = 10;
let b: number = 20;

let arithmetic: string = `${a + b}`;         // "30"
let comparison: string = `${a > b}`;         // "false"
let logical: string = `${a > 0 && b > 0}`;   // "true"
let functionCall: string = `${Math.max(a, b)}`; // "20"

// Supports the ternary operator
let result: string = `${a > b ? 'greater' : 'less'}`;  // "less"

// Does not support complex statements
let invalid: string = `${if (a > b) { 'yes' }}`;  // Compilation error.

// Nested template string.
let outer: string = `Outer: ${`Inner: ${a}`}`;  // "Outer: Inner: 10"
```

## Unicode Representation of Strings

Unicode encoding represents international characters and supports multiple encoding forms.

### Unicode Scalar Values

A Unicode scalar value is a valid range of Unicode code points, excluding surrogate code points.

<!-- @[unicode_representation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
// Unicode character representation
let unicode1: string = 'A';               // Direct character
let unicode2: string = '\u0041';          // Unicode escape ('A')
let unicode3: string = '\x41';            // ASCII escape ('A')

// Unicode code point
let emoji: string = '\u{1F600}';          // 😀 (emoji)
let chinese: string = '\u{4E2D}';         // the Chinese character for 'middle'

// Obtain the Unicode code point of the character.
let unicodeReprCodePoint: number = 'A'.codePointAt(0) ?? 0;  // 65
let emojiCode: number = '😀'.codePointAt(0) ?? 0; // 128512

// Create a character from a code point.
let fromCode: string = String.fromCodePoint(65);      // 'A'
let fromEmoji: string = String.fromCodePoint(128512); // '😀'
```

### Converting Between Unicode Representations

To convert among the three representations - string, array of Unicode code points, and Unicode escape sequence - use the codePointAt and fromCodePoint methods.

<!-- @[unicode_codepoint_conversion](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let unicodeText: string = 'Hello';

// Convert the string to an array of Unicode code points.
let codePoints: number[] = [];
for (let char of unicodeText) {
  codePoints.push(char.codePointAt(0) ?? 0);
}
console.info(`${codePoints.join(', ')}`);  // 72, 101, 108, 108, 111

// Convert Unicode code points to a string.
let reconstructed: string = '';
for (let code of codePoints) {
  reconstructed += String.fromCodePoint(code);
}
console.info(`${reconstructed}`);  // "Hello"

// Unicode escape form
let unicodeEscaped: string = '';
for (let char of unicodeText) {
  let code: number = char.codePointAt(0) ?? 0;
  unicodeEscaped += `\\u${code.toString(16).padStart(4, '0')}`;
}
console.info(`${unicodeEscaped}`);  // "\u0048\u0065\u006c\u006c\u006f"
```

## String Length

The `length` property of a string returns the number of UTF-16 code units. Note the impact of surrogate pairs.

### Calculating the Length of a String

The `length` property of a string returns the number of UTF-16 code units. A surrogate pair occupies two units.

<!-- @[string_length](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let lengthText: string = 'Hello';
let length: number = lengthText.length;  // 5

let empty: string = '';
let emptyLength: number = empty.length;  // 0

let space: string = '   ';
let spaceLength: number = space.length;  // 3

// The length of a multiline string includes the newline character.
let lengthMultiLine: string = `Line1
Line2`;
let multiLength: number = lengthMultiLine.length;  // 11 (including \n)
```

### Considerations for Length Calculation

When calculating the length of a string that contains complex Unicode characters, consider the impact of surrogate pairs.

<!-- @[multibyte_length](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
// Ordinary ASCII characters
let ascii: string = 'Hello';
console.info(`${ascii.length.toString()}`);  // 5

// Chinese characters (each character has a length of 1)
let multibyteChinese: string = 'Hello world';
console.info(`${multibyteChinese.length.toString()}`);  // 4

// Emoji character (the length of some multibyteEmoji may be 2).
let multibyteEmoji: string = '😀';
console.info(`${multibyteEmoji.length.toString()}`);  // 2 (surrogate pair)

// Combined character.
let multibyteCombined: string = 'é';  // e + combining accent
console.info(`${multibyteCombined.length.toString()}`);  // May be 2.

// Correctly count characters (using iteration).
function countCharacters(text: string): number {
  let count: number = 0;
  for (let char of text) {
    count++;
  }
  return count;
}

console.info(`${countCharacters('😀').toString()}`);  // 1 (correct count).
```

## String Indexing

A string allows you to access the character at a specified position by index or through `charAt`, and to locate the position of a substring through `indexOf`/`lastIndexOf`.

### Accessing a Single Character in a String

Use `charAt` and index access to obtain a single character, and use `charCodeAt` to obtain the character code.

<!-- @[string_indexing](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let indexText: string = 'Hello World';

// Access by index.
let first: string = indexText[0];           // 'H'
let fifth: string = indexText[4];           // 'o'
let last: string = indexText[indexText.length - 1];  // 'd'

// Use the charAt method.
let second: string = indexText.charAt(1);   // 'e'

// Access out of bounds.
let outOfBounds: string | undefined = indexText[100];  // undefined
let outOfBounds2: string = indexText.charAt(100);      // '' (empty string)
```

### Obtaining and Offsetting Indexes

`indexOf` finds the position of a substring, and `lastIndexOf` searches from the end.

<!-- @[string_search](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let searchText: string = 'Hello World';

// Find the character position.
let indexOfO: number = searchText.indexOf('o');      // 4
let indexOfWorld: number = searchText.indexOf('World'); // 6
let lastIndexOfO: number = searchText.lastIndexOf('o'); // 7

// Search from the specified position.
let indexOfO2: number = searchText.indexOf('o', 5);   // 7 (starting from index 5)

// Search for a nonexistent string.
let notFound: number = searchText.indexOf('xyz');    // -1

// Calculate the index offset.
let nextIndex: number = indexOfO + 1;          // 5
let prevIndex: number = indexOfO - 1;          // 3
```

## Substring

Substring operations extract, find, and replace text fragments.

### Obtaining Substrings

The `substring` and `slice` methods extract string fragments, and `split` splits a string into an array. **The key difference between the two**: `substring` automatically adjusts the argument order (for example, `substring(5, 0)` is equivalent to `substring(0, 5)`), and negative arguments are treated as 0; `slice` does not adjust the argument order and supports negative indexes (counting from the end).

<!-- @[substring_extraction](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let extractText: string = 'Hello World';

// substring method
let sub1: string = extractText.substring(0, 5);    // "Hello"
let sub2: string = extractText.substring(6);       // "World"
let sub3: string = extractText.substring(6, 11);   // "World"

// slice method
let slice1: string = extractText.slice(0, 5);      // "Hello"
let slice2: string = extractText.slice(-5);        // "World" (negative index)
let slice3: string = extractText.slice(6, -1);     // "Worl"

// substring vs slice
// substring automatically adjusts the parameter order and treats negative numbers as 0; slice does not adjust the parameter order and supports negative indexes.
let subNeg: string = extractText.substring(-2, 3);  // "Hel" (-2 is treated as 0)
let reversed: string = extractText.substring(5, 0);  // "Hello" (automatically adjusted)
let reversedSlice: string = extractText.slice(5, 0);  // "" (not adjusted)
```

### Lifecycle and Conversion of Substrings

A substring is a new string that exists independently of the original string. Modifying the substring does not affect the original string.

<!-- @[substring_operations](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let original: string = 'Hello World';

// A substring is a new string that exists independently.
let sub: string = original.substring(0, 5);
sub = sub.toUpperCase();  // Modifying the substring does not affect the original string.
console.info(`${original}`);  // "Hello World"

// Convert the substring to an array.
let substrParts: string[] = sub.split('');
console.info(`[${substrParts.join(', ')}]`);  // H, e, l, l, o

// Concatenate the substring.
let newString: string = sub + ' ArkTS';  // "Hello ArkTS"

// Replace the substring.
let replaced: string = original.replace(sub, 'Hi');  // "Hi World"
```

## String Comparison

String comparison determines equality and ordering relationships, and supports locale-aware comparison.

### String Equality Comparison

Use `===` to compare both the value and type of strings, and avoid the implicit conversion of `==`.

<!-- @[string_comparison](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let str1: string = 'Hello';
let str2: string = 'Hello';
let str3: string = 'World';

// Strict equality comparison.
console.info(`${str1 === str2}`);  // true
console.info(`${str1 === str3}`);  // false
console.info(`${str1 !== str3}`);  // true

// Case-sensitive comparison.
let upper: string = 'HELLO';
console.info(`${str1 === upper}`);  // false (different case)

// Compare ignoring case.
let equalIgnoreCase: boolean = 
  str1.toLowerCase() === upper.toLowerCase();  // true
```

### Prefix Comparison

The startsWith method checks whether a string starts with the specified text, and is used for format validation.

<!-- @[starts_with_check](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let startsWithText: string = 'Hello World';

// startsWith method
let startsWithHello: boolean = startsWithText.startsWith('Hello');  // true
let startsWithWorld: boolean = startsWithText.startsWith('World');  // false

// Check from the specified position.
let startsWithWorld2: boolean = startsWithText.startsWith('World', 6);  // true

// Manual prefix check.
function hasPrefix(text: string, prefix: string): boolean {
  return text.indexOf(prefix) === 0;
}
```

### Suffix Comparison

endsWith() determines whether a string ends with the specified substring.

<!-- @[ends_with_check](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let endsWithText: string = 'Hello World';

// endsWith method
let endsWithWorld: boolean = endsWithText.endsWith('World');  // true
let endsWithHello: boolean = endsWithText.endsWith('Hello');  // false

// Check the suffix within the specified length.
let endsWithOrld: boolean = endsWithText.endsWith('orld', 11);  // true

// Manually check the suffix.
function hasSuffix(text: string, suffix: string): boolean {
  let startPos: number = text.length - suffix.length;
  return startPos >= 0 && text.indexOf(suffix, startPos) === startPos;
}
```

## String Case Conversion

Use `toUpperCase()` and `toLowerCase()` to convert the case of a string. Note: Accessing a character by index (for example, `text[0]`) returns the `string` type, so you can call string methods directly.

### Converting to Uppercase

The toUpperCase method converts all characters in a string to uppercase.

<!-- @[to_uppercase](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let upperText: string = 'Hello World';

let upperUpper: string = upperText.toUpperCase();  // "HELLO WORLD"

// Partially uppercase.
let firstUpper: string = upperText[0].toUpperCase() + upperText.substring(1);  // "Hello World"

// Capitalize the first letter of each word.
function capitalizeWords(upperText: string): string {
  let words: string[] = upperText.split(' ');
  let capitalized: string[] = words.map((word: string): string => {
    return word[0].toUpperCase() + word.substring(1).toLowerCase();
  });
  return capitalized.join(' ');
}

let upperResult: string = capitalizeWords('hello world');  // "Hello World"
```

### Converting to All Lowercase

`toLowerCase()` converts uppercase letters in a string to lowercase.

<!-- @[to_lowercase](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let lowerText: string = 'Hello World';

let lower: string = lowerText.toLowerCase();  // "hello world"

// Partially lowercase
let lowerMixed: string = lowerText[0] + lowerText.substring(1).toLowerCase();  // "Hello world"

// Check whether it is lowercase
function isLowerCase(lowerText: string): boolean {
  return lowerText === lowerText.toLowerCase();
}

console.info(`${isLowerCase('hello')}`);  // true
console.info(`${isLowerCase('Hello')}`);  // false
```

## Commonly Used String Methods

String methods include operations such as search, extraction, replacement, and splitting.

### Search Methods

Search methods are used to locate the position of a substring or character in a string.

<!-- @[string_search_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let searchText2: string = 'Hello World';

// indexOf: Find the position.
let pos: number = searchText2.indexOf('World');      // 6
let lastPos: number = searchText2.lastIndexOf('o');  // 7

// includes: Check whether the string contains the substring.
let hasWorld: boolean = searchText2.includes('World'); // true

// startsWith: Check whether the string starts with the specified string.
let startsHello: boolean = searchText2.startsWith('Hello'); // true

// endsWith: checks whether the string ends with the specified string.
let endsWorld: boolean = searchText2.endsWith('World'); // true
```

### Extraction Methods

Extraction methods are used to obtain a substring within a specified range from a string.

<!-- @[string_slice_split](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let sliceText: string = 'Hello World';

// slice: Extract a substring.
let slice: string = sliceText.slice(0, 5);        // "Hello"

// substring: Extract a substring.
let substring: string = sliceText.substring(7);    // "World"

// split: Split into an array.
let split: string[] = sliceText.split(' ');
console.info(`[${split.join(', ')}]`);  // Hello, World
let splitAll: string[] = sliceText.split('');
console.info(`[${splitAll.join(', ')}]`);  // H, e, l, l, o,  , W, o, r, l, d
```

### Modification Methods

Modification methods are used to change the content of a string, such as replacing, splitting, and concatenating.

<!-- @[string_common_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let commonMethodsText: string = 'Hello World';

// replace: Replace.
let commonMethodsReplaced: string = commonMethodsText.replace('World', 'ArkTS');  // "Hello ArkTS"

// replaceAll: Replace all (ES2021, supported by ArkTS).
let multiple: string = 'aa bb aa';
let allReplaced: string = multiple.replaceAll('aa', 'xx');  // "xx bb xx"

// trim: Remove leading and trailing spaces.
let trimmed: string = '  Hello ArkTS  '.trim();  // "Hello ArkTS"

// trimStart: Remove leading spaces.
let trimStart: string = '  Hello ArkTS  '.trimStart();  // "Hello ArkTS  "

// trimEnd: Remove trailing spaces.
let trimEnd: string = '  Hello ArkTS  '.trimEnd();  // "  Hello ArkTS"

// padStart: Pad on the left.
let padded: string = '5'.padStart(3, '0');  // "005"

// padEnd: Pad on the right.
let paddedEnd: string = '5'.padEnd(3, '0'); // "500"

// repeat: Repeat.
let repeated: string = 'ab'.repeat(3);      // "ababab"
```

### Other Methods

The string type also provides practical methods such as charAt, charCodeAt, concat, localeCompare, toString, and valueOf.

<!-- @[string_utility_methods](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let utilityText: string = 'Hello';

// charAt: Obtain the character at the specified position.
let utilityChar: string = utilityText.charAt(0);  // 'H'

// charCodeAt: Obtain the character code.
let utilityCode: number = utilityText.charCodeAt(0);  // 72

// concat: Concatenate strings.
let concatenated: string = 'Hello'.concat(' ', 'World');  // "Hello World"

// localeCompare: Performs locale-aware comparison.
let comparison: number = 'a'.localeCompare('b');  // -1(a < b)

// toString: Converts to a string.
let numStr: string = (42).toString();  // "42"
let boolStr: string = (true).toString();  // "true"

// valueOf: Obtains the primitive value.
let value: string = 'test'.valueOf();  // "test"
```

## Strings and Regular Expressions

Regular expressions are used for matching, searching, and replacing strings, and are created through the RegExp object.

<!-- @[string_regex](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
// match: Match a regular expression.
let regexText: string = 'The quick brown fox';
let matches: RegExpMatchArray | null = regexText.match(/quick/);

// search: Find the match position.
let regexPos: number = regexText.search(/brown/);  // 10

// replace: Replace using a regular expression.
let regexReplaced: string = regexText.replace(/fox/, 'cat');  // "The quick brown cat"

// split: split by regular expression
let regexParts: string[] = 'a1b2c3'.split(/\d/);
console.info(`[${regexParts.join(', ')}]`);  // a, b, c, 

// matchAll: global matching (ES2020, supported by ArkTS)
let allMatches: IterableIterator<RegExpMatchArray> = regexText.matchAll(/\w+/g);
```

## Unicode Character Handling

A character in a string may consist of multiple UTF-16 code units (for example, an emoji). Use `codePointAt` and `fromCodePoint` to handle complete Unicode code points.

<!-- @[unicode_handling](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let unicodeEmoji: string = '🎉';
let unicodeCode: number | undefined = unicodeEmoji.codePointAt(0);
if (unicodeCode !== undefined) {
  console.info(`${unicodeCode.toString()}`);  // 129395
}

let unicodeChar: string = String.fromCodePoint(128516);
console.info(`${unicodeChar}`);  // 😄

// Iterate by Unicode code points (instead of UTF-16 code units).
let unicodeText2: string = 'a🎉b';
for (let uc of unicodeText2) {
  console.info(`${uc}`);  // Output in sequence: a, 🎉, b.
}
```

## String Padding and Repetition

`padStart` and `padEnd` are used to pad a string to a specified length at the beginning or end, and `repeat` is used to repeat a string.

<!-- @[string_pad_repeat](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
// padStart: pad at the beginning
let prS1: string = '5'.padStart(3, '0');
console.info(`${prS1}`);  // 005

let prS2: string = 'hi'.padStart(5, '-');
console.info(`${prS2}`);  // ---hi

// padEnd: pad at the end
let prS3: string = 'hi'.padEnd(5, '-');
console.info(`${prS3}`);  // hi---

// repeat: repeat the string
let prS4: string = 'ab'.repeat(3);
console.info(`${prS4}`);  // ababab
```

## at Method and Negative Index Access

The `at` method supports negative index access to string characters, which is more flexible than the bracket notation `[]`.

**TypeScript Comparison**

<!-- @[ts_string_at](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Strings.ts) -->

``` TypeScript
// TypeScript comparison (ES2022); in ArkTS, use charAt instead
let tsAtWord: string = 'hello';
console.info(`${tsAtWord.at(0)}`);   // 'h'
console.info(`${tsAtWord.at(-1)}`);  // 'o' (the last character)
```

ArkTS does not support the `at` method. Use `charAt` with manual index calculation instead.

<!-- @[at_method_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
let atWord: string = 'hello';
console.info(`${atWord.charAt(0)}`);              // h
console.info(`${atWord.charAt(atWord.length - 1)}`);  // o
console.info(`${atWord.charAt(10)}`);             // (empty string, out of range)
```

## Template Literal Types

Template literal types are used in TypeScript to concatenate string literals at the type level. ArkTS does not support this feature.

**TypeScript Comparison**

<!-- @[ts_template_literal_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/Strings.ts) -->

``` TypeScript
// TypeScript equivalent, not supported in ArkTS.
type TltWorld = 'world';
type TltGreeting = `hello ${TltWorld}`;  // 'hello world'

// Union expansion.
type TltLocale = `${'en' | 'ja'}_${'welcome' | 'bye'}`;
// 'en_welcome' | 'en_bye' | 'ja_welcome' | 'ja_bye'

// Built-in string operation types.
type TltUpper = Uppercase<'hello'>;      // 'HELLO'
type TltLower = Lowercase<'HELLO'>;      // 'hello'
type TltCap = Capitalize<'hello'>;       // 'Hello'
type TltUncap = Uncapitalize<'Hello'>;   // 'hello'
```

ArkTS does not support template literal types. Use ordinary string constants, enums, or union types instead, and implement dynamic strings through runtime string concatenation.

<!-- @[template_literal_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/Strings.ets) -->

``` TypeScript
enum TltEventType {
  Click = 'click',
  Hover = 'hover',
  Focus = 'focus'
}

function tltHandleEvent(type: TltEventType, callback: () => void): void {
  console.info(`Handling ${type}`);
  callback();
}

tltHandleEvent(TltEventType.Click, (): void => {
  console.info('Clicked!');
});
```