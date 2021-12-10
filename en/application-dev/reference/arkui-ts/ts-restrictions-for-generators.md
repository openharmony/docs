# Restrictions on Using the TS Language for Generators<a name="EN-US_TOPIC_0000001110789000"></a>

The TypeScript programming language has the following restrictions on generators:

-   Expressions can be used only in character strings \($\{expression\}\),  **if**  conditions,  **ForEach**  parameters, and component parameters.
-   None of these expressions can cause any application state variables \(**@State**,  **@Link**, and  **@Prop**\) to change. Otherwise, undefined and potentially unstable framework behavior may occur.
-   You can use  **console.log**  in the first line of the generator function body so that you can more easily track component re-rendering. Expressions in the log character strings also comply with the preceding restrictions.
-   The generator function cannot contain local variables.

None of the above restrictions apply to anonymous function implementations of event-handling functions \(such as  **onClick**\) and to the rest of the UI component description.

Incorrect:

```
build() {
    let a: number = 1 // invalid: variable declaration not allowed
    console.log(`a: ${a}`) // invalid: console.log only allowed in first line of build
    Column() {
        Text('Hello ${this.myName.toUpperCase()}') // ok.
        ForEach(this.arr.reverse(), ..., ...) // invalid: Array.reverse modifies the @State array varible in place
    }
    buildSpecial()  // invalid: no function calls
    Text(this.calcTextValue()) // this function call is ok.
}
```

