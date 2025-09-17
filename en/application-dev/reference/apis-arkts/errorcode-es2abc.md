# es2abc Compiler Error Codes

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @huyunhui1; @oh-rgx1; @zmw1-->
<!--Designer: @ctw-ian-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @foryourself-->

> **NOTE**
>
> This section describes the error codes of the es2abc compiler module. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 10705000 Syntax Error

**Error Message**

Example
```txt
ERROR: 10705000 Syntax Error
SyntaxError: Concurrent function should only use import variable or local variable, 'a' is not one of them [/path/to/wrong/file.ts:9:4]
```

**Description**

The compiler cannot parse a syntax structure in the source file. The error information contains the file name, line number, and column number.

**Possible Causes**

1. The code contains invalid or incomplete syntax, for example, missing brackets, spelling errors, and incorrect structure nesting.
2. The code uses language features that are not supported by the current version.
3. The keyword or syntax structure cannot be identified due to spelling errors.

**Solution**

1. Locate the error based on the file name and line number in the error message.
2. Fix syntax errors, for example, add missing brackets or keywords.
3. Use the syntax check tool of DevEco Studio to detect syntax errors.
4. If the new syntax feature is used, ensure that the current compiler version supports the feature.

## 10706001 Specification Error

**Error Message**

Example
```txt
ERROR: 10706001 Found unsupported change in file, failed to generate patch abc!
[Patch] Found lexical variable added or removed in .a, not supported!
[Patch] Found unsupported change in file, will not generate patch!
Error:  [base_mod.js:0:0]
```

**Description**

The compiler detects that the source file contains changes that are not supported by incremental compilation (patch mode). As a result, the patch generation is terminated. These changes usually involve code modifications that significantly affect the semantics, such as scope, variable declaration, and import structure.

**Possible Causes**

1. In the patch build process, the lexical variables of the module are modified, for example, declarations are added or deleted.
2. Key functions are deleted or existing variables are redeclared.
3. The import/export structure or module boundary is destructively modified.
4. The file modification is not supported by the es2abc incremental patch mechanism.

**Solution**

1. Check the file and code changes in the error message.
2. Do not add, delete, or rename variables defined in the module.
3. If semantic changes are required, select full compilation instead of incremental compilation.
