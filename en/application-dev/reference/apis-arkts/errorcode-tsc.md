# TypeScript Compiler Error Codes

Error codes of Typescript Compiler (TSC) start with '105' and serve as error indicators during the TSC compilation process. These error codes and their corresponding descriptions are shown in the editor, console, or log files.

## 10505001 TSC Native Errors

TSC native errors, ending with '001', represent existing native error rules checked by TSC. Common causes of TSC native errors during compilation include: missing keywords or symbols, type mismatches in assignments, and undefined types or variables. These issues typically arise from not adhering to [language specifications](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/introduction-to-arkts) when writing code. Developers can adjust the code based on the error descriptions.

### Missing Keywords Or Symbols

**Error Example Scenario**

```typescript
declare type AAA = 'BBB;
```

**Error Message**

Unterminated string literal.

**Description**

The string literal is not correctly terminated at the expected position.

**Possible Causes**

The closing quote is missing.

**Solution**

Based on the error description, add the missing quotes to the code block. The updated code is as follows:

```typescript
declare type AAA = 'BBB';
```

### Multiple Default Exports

**Error Example Scenario**

```typescript
export default A;
export default B;
```

**Error Message**

A module cannot have multiple default exports.

**Description**

A module cannot have multiple default exports.

**Possible Causes**

Multiple default exports are defined in the module.

**Solution**

Based on the error description, delete unnecessary default exports. The updated code is as follows:

```typescript
export default A;
```

### Type Mismatch in Assignments

**Error Example Scenario**

```typescript
let a: number = 1;
let b: string = '2';
a = b;
```

**Error Message**

Type 'string' is not assignable to type 'number'.

**Description**

Type 'string' cannot be assigned to type 'number'.

**Possible Causes**

Assigning a value of one type to a variable of a different type results in a type mismatch error.

**Solution**

Based on the error description, ensure type consistency by making appropriate type assignment changes. The updated code is as follows:

```typescript
let a: number = 1;
let b: number = 2;
a = b;
```
