# ArkTS Migration Background

This chapter explains why it makes sense to migrate from the standard TypeScript to
ArkTS. In general, there are two reasons for doing this:

- Program stability. Dynamically typed languages like JavaScript are very good at
  allowing programs to write code fast. At the same time, these languages are
  notorious for unexpected runtime errors. For example, a developer may forget
  to check some value for `undefined`, and as a result of this, the program
  may crash, which causes inconvenience to the users. Detecting such issues
  during development time would be much more beneficial. TypeScript helps greatly
  here: It allows to annotate the code with types, and many errors will be
  detected by the compiler, prior to deployment and usage of the code.
  However, even TypeScript has limitations and sometimes permits to annotate the code
  with types “loosely”, which still leaves a gap for runtime errors. ArkTS
  tries to overcome this drawback: It enforces static typing for even stricter
  type checking and less runtime errors.
- Program performance. To ensure correctness of the program, dynamically
  languages have to check actual types of objects when the program actually
  runs. Back to our example, JavaScript does not allow to read a property from
  `undefined`. But the only way to check if some value is `undefined` is to
  perform a runtime check, that all JavaScript engines do: if the value is not
  `undefined`, the property is read, otherwise an exception is thrown. Modern
  engines can optimize such checks greatly, but these checks cannot be
  eliminated completely, which leads to code slowdown. Since the standard TypeScript
  compiles to JavaScript, the code written in TypeScript has exactly the same issues as
  described above. ArkTS addresses this problem. Since static typing is
  enforced, ArkTS compiles the program not to JavaScript, but to some special
  execution format called bytecode, which is faster to execute and easier to
  optimize even further.

Below there are a couple of examples that try to explain how ArkTS can help
improve program stability and performance.

**Explicit Initialization of Fields for Better Stability**

ArkTS requires that all fields are explicitly initialized with some values
either when the field is declared or in the `constructor`. This is similar
to `strictPropertyInitialization` mode of the standard TypeScript.

Let’s take a look at the following TypeScript code:

```typescript
class Person {
    name: string // Automatically is set to undefined

    setName(n:string): void {
        this.name = n
    }

    getName(): string {
    // Return type "string" hides from the developers the fact
    // that name can be undefined. The most correct would be
    // to write the return type as "string | undefined". By doing so
    // we tell the users of our API about all possible return values.
        return this.name
    }
}

let buddy = new Person()
// Let's assume that the developer forgets to call setName:
// buddy.setName("John")
console.log(buddy.getName().length); // runtime exception: name is undefined
```

Since ArkTS requires explicit initialization, the code looks like this:

```typescript
class Person {
    name: string = "" // The field always is defined

    setName(n:string): void {
        this.name = n
    }

    // The type is string in all cases, null and undefined are impossible.
    getName(): string {
        return this.name
    }
}

let buddy = new Person()
// Let's assume that the developer forgets to call setName:
// buddys.setName("John")
console.log(buddy.getName().length); // 0, no runtime error
```

If `name` can be `undefined`, this is also should be specified explicitly:

```typescript
class Person {
    name ?: string // The field may be undefined

    setName(n:string): void {
        this.name = n
    }

    // Compile-time error:
    // name can be "undefined", so we cannot say to those who use this API
    // that it returns only strings:
    getNameWrong(): string {
        return this.name
    }

    getName(): string | undefined { // Return type matches the type of name
        return this.name
    }
}

let buddy = new Person()
// Let's assume that the developer forgets to call setName:
// buddy.setName("John")

// Compile-time(!) error: Compiler suspects that we
// may possibly access something undefined and won't build the code:
console.log(buddy.getName().length); // The code won't build and run

console.log(buddy.getName()?.length); // Builds ok, no runtime error
```

This case demonstrates how we can improve stability and correctness of our
code by enforcing stricter type checking in ArkTS.

**Null Safety for Better Performance**

Let’s take a look at the following code:

```typescript
function notify(who: string, what: string) {
    console.log(`Dear ${who}, a message for you: ${what}`)
}

notify("Jack", "You look great today")
```

In most cases, the `notify` function will take two string variables as
an input and produces a new string. However, what if we pass some “special”
values to the function, for example `notify(null, undefined)`? The program
will continue to work, the output will be as expected
(`Dear undefined, a message for you: null`), so from the first glance
everything is fine. But please note that the engine that runs our code
should always check for such special cases to ensure correct behavior. In
pseudocode, something like this happens:

```typescript
function __internal_tostring(s: any): string {
    if (typeof s === "string")
        return s
    if (s === undefined)
        return "undefined"
    if (s === null)
        return "null"
    // ...
}
```

Now imagine that our `notify` function is a part of some complex heavy-loaded
system which sends real notifications instead of just writing to the log. In
this scenario, executing all these checks from our `__internal_tostring`
function may turn into a performance problem.

But what if we could somehow guarantee to our exectuion engine that the only
values that are passed to the `notify` function are “real” strings, but not
some “special” values like `null` or `undefined`? In this case, checks like
`__internal_tostring` become redundant because when we execute the program
we are 100% sure that there will be no corner cases. For this particular case
this mechanism would be called “null-safety”, i.e. guarantee that `null` is
not a valid value of the `string` type. If we had such feature, the code
would not simply build:

```typescript
function notify(who: string, what: string) {
    console.log(`Dear ${who}, a message for you: ${what}`)
}

notify("Jack", "You look great today")
notify(null, undefined) // Compile-time error
```

In TypeScript such behavior can be turned on by a special compiler flag called
`strictNullChecks`. But since the standard TypeScript is compiled to JavaScript, which
does not have such feature, “strict null checks” work only in compile-time,
for better type checking. However, ArkTS considers null-safety a very
important feature from both stability and performance points of view. That’s
why it is enforced in the language and the example above always produces
compile-time errors. In exchange, we give our running engine much more
information and guarantees about possible type values, which helps better
optimize performance.
