# Module System

<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=c25b60c237b212cfc232b5aee67d2c42ba90278a translatedAt=2026-08-13T09:04:35.087Z pushedAt=2026-08-13T13:28:07.167Z -->

The module system is used to split code into files with clear boundaries that are reusable and maintainable. ArkTS uses the `import` and `export` syntax of ES modules, and does not support the `require` and namespace of CommonJS.

## Module Basics

A module is the basic unit for organizing code, and it enables reuse through imports and exports.

### Module Definition

A file that contains top-level `import` or `export` is treated as a module. Variables, functions, classes, and interfaces in a module are visible only within the current file by default. Only declarations exported through `export` can be imported by other modules.

<!-- @[module_export](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/common/User.ets) -->

``` TypeScript
// User.ets
export interface User {
  id: number;
  name: string;
}

export function createUser(id: number, name: string): User {
  return {
    id: id,
    name: name
  };
}

export class UserService {
  private users: User[] = [];

  add(user: User): void {
    this.users.push(user);
  }

  getAll(): User[] {
    return this.users;
  }
}
```

### Importing Modules

Use the `import { name } from 'path'` syntax to import bindings exported by other modules and use them in the current file.

<!-- @[module_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ModuleImport.ets) -->

``` TypeScript
import { User, UserService, createUser } from '../common/User';

let user: User = createUser(1, 'Alice');
let service: UserService = new UserService();

service.add(user);
let users: User[] = service.getAll();
let firstUser: User | undefined = users[0];
console.info(`${firstUser ? firstUser.name : ''}`);
```

### Empty Export Marker Module

In TypeScript, a file without any top-level import or export is usually treated as a script. To explicitly mark a file as a module, you can use an empty export:

<!-- @[empty_export](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ModuleSystem.ets) -->

``` TypeScript
export {}
```

ArkTS files are usually organized by project modules, but it is still recommended to express module boundaries through clear imports and exports.

## export

Using `export`, you can mark declarations in a module as public APIs for other modules to import and reuse as needed. It supports two forms: named exports and default exports.

### Export at Declaration

You can export a variable, constant, function, class, interface, or type alias directly when declaring it.

<!-- @[named_export](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ModuleSystem.ets) -->

``` TypeScript
export const MAX_RETRY_COUNT: number = 3;

export let currentUserName: string = '';

export interface RequestConfig {
  url: string;
  timeout: number;
}

export type RequestStatus = 'idle' | 'loading' | 'success' | 'failed';

export function buildUrl(baseUrl: string, path: string): string {
  return baseUrl + path;
}

export class RequestTracker {
  private status: RequestStatus = 'idle';

  setStatus(status: RequestStatus): void {
    this.status = status;
  }

  getStatus(): RequestStatus {
    return this.status;
  }
}
```

### Unified Export

You can also declare first and then export them together at the end of the file. Unified export is suitable for making the public `API`s of a module visible in one place.

<!-- @[export_list](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ModuleSystem.ets) -->

``` TypeScript
const DEFAULT_TIMEOUT: number = 5000;

interface ApiConfig {
  host: string;
  timeout: number;
}

function createApiConfig(host: string): ApiConfig {
  return {
    host: host,
    timeout: DEFAULT_TIMEOUT
  };
}

export { ApiConfig, DEFAULT_TIMEOUT, createApiConfig };
```

### Renamed Export

Use the `export { name as newName }` syntax to rename a binding during export, avoiding naming conflicts or improving API readability.

<!-- @[export_rename](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ModuleSystem.ets) -->

``` TypeScript
class InternalUserService {
  getName(): string {
    return 'UserService';
  }
}

export { InternalUserService as RenamedUserService };
```

### Default Export

A default export uses `export default` to export the primary functionality, and it can be imported under any name.

<!-- @[default_export](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/common/Logger.ets) -->

``` TypeScript
// Logger.ets
export default class Logger {
  info(message: string): void {
    console.info(`${message}`);
  }
}
```

In another file, you can use this class through a default import.

<!-- @[default_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/DefaultImport.ets) -->

``` TypeScript
import Logger from '../common/Logger';

let logger: Logger = new Logger();
logger.info('module loaded');
```

In large projects, public APIs generally prefer named exports, because named exports offer clear advantages in code search, refactoring and maintenance, and interface constraints.

### Re-export

Re-export is commonly used in module entry files to aggregate multiple files in the same domain into a stable entry point.

<!-- @[submodule_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/common/Types.ets) -->

``` TypeScript
export interface User {
  id: number;
  name: string;
}
```

Define a service class in another source file to provide business methods.

<!-- @[submodule_export_class](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/common/Service.ets) -->

``` TypeScript
export class UserService {
  findById(id: number): User | null {
    if (id <= 0) {
      return null;
    }
    return {
      id: id,
      name: 'Alice'
    };
  }
}
```

Then aggregate these scattered exports into a unified entry point through a barrel file.

<!-- @[barrel_file_reexport](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ModuleSystem.ets) -->

``` TypeScript
export { User } from '../common/Types';
export { UserService } from '../common/Service';
```

Consumers only need to import from the barrel file, without caring about the source file of each member.

<!-- @[barrel_file_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/BarrelFileImport.ets) -->

``` TypeScript
import { User, UserService } from '../common/User';

let service: UserService = new UserService();
let user: User | null = service.findById(1);
console.info(`${user ? user.name : 'not found'}`);
```

## Static Import

Use `import` to bring in bindings exported by other modules and use their types, functions, or classes in the current file. Both named imports and namespace imports are supported.

### Named Import

Use `import { name } from 'path'` to import the named exports of a module by name. You can list multiple bindings within the braces.

<!-- @[named_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/NamedImport.ets) -->

``` TypeScript
import { UserService } from '../common/User';

let service: UserService = new UserService();
```

### Renamed Import

Rename an import when its name conflicts with an existing name in the current file, or when renaming improves readability.

<!-- @[import_rename](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ImportRename.ets) -->

``` TypeScript
import { UserService as AccountUserService } from '../common/User';

let service: AccountUserService = new AccountUserService();
```

### Default Import

Use `import Name from 'path'` to import the default export of a module. The name does not need to match the one used at export time.

<!-- @[default_import_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/DefaultImport.ets) -->

``` TypeScript
import Logger from '../common/Logger';

let logger: Logger = new Logger();
```

### Combining Default and Named Imports

Use `import defaultName, { namedName } from 'path'` to import both the default export and named exports in a single statement.

<!-- @[mixed_export](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/common/Report.ets) -->

``` TypeScript
// Report.ets
export interface ReportOptions {
  title: string;
}

export default class ReportBuilder {
  build(options: ReportOptions): string {
    return options.title;
  }
}
```

On the consumer side, you can import both the default export and named exports at the same time.

<!-- @[mixed_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/MixedImport.ets) -->

``` TypeScript
import ReportBuilder, { ReportOptions } from '../common/Report';

let options: ReportOptions = {
  title: 'Daily'
};
let builder: ReportBuilder = new ReportBuilder();
let title: string = builder.build(options);
console.info(`${title}`);
```

### Namespace Import

A namespace import places all named exports of a module onto a single object. It is not a TypeScript `namespace` declaration; it is merely ES module import syntax.

<!-- @[export_multiple_functions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/common/Math.ets) -->

``` TypeScript
// Math.ets
export function add(left: number, right: number): number {
  return left + right;
}

export function multiply(left: number, right: number): number {
  return left * right;
}
```

You can use a namespace import to collect all named exports of a module onto a single object.

<!-- @[namespace_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/NamespaceImport.ets) -->

``` TypeScript
import * as MathUtil from '../common/Math';

let sum: number = MathUtil.add(1, 2);
let product: number = MathUtil.multiply(3, 4);
console.info(`${sum}, ${product}`);
```

### Side-Effect Import

A side-effect import executes the target module but does not import any bindings. Use it with caution to avoid hiding initialization logic.

<!-- @[side_effect_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/SideEffectImport.ets) -->

``` TypeScript
import '../common/Config';
```

## Type Imports and Type Exports

TypeScript supports `import type` and `export type` to mark type-only imports and exports. In ArkTS, use a regular `import` to import type declarations.

### TypeScript Type-Specific Import

TypeScript supports `import type` and `export type` to mark imports and exports that are used only in type positions.

<!-- @[ts_type_import_export](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/ModuleSystem.ts) -->

``` TypeScript
// TypeScript supports import type and export type. ArkTS uses them based on toolchain support.
import type { User } from '../common/User';
export type { User };
```

### Importing with the import Statement in ArkTS

ArkTS uses the regular `import` to bring in type declarations, and does not use the dedicated `import type` syntax. Types and values are imported uniformly through `import`.

<!-- @[type_import_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeImportUsage.ets) -->

``` TypeScript
import { User } from '../common/User';

function printUser(user: User): void {
  console.info(`${user.name}`);
}
```

## Dynamic Import

Use `import()` to load modules on demand at runtime. It returns a Promise and is often used with async/await to implement lazy loading.

### Basic Syntax

Dynamic import is used to load modules on demand. It returns a `Promise`, so it is usually used together with `async`/`await`.

<!-- @[dynamic_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ModuleSystem.ets) -->

``` TypeScript
async function loadFeatureLabel(): Promise<string> {
  let moduleObject = await import('../common/Feature');
  return moduleObject.getFeatureLabel();
}
```

The dynamically loaded module exports its members as usual.

<!-- @[dynamic_import_module](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/common/Feature.ets) -->

``` TypeScript
export function getFeatureLabel(): string {
  return 'feature';
}
```

### Constraints

The module path of a dynamic import should remain statically analyzable. When packaging, subpackaging, cross-package loading, or runtime permissions are involved, follow the HarmonyOS project and runtime constraints.

<!-- @[conditional_dynamic_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ModuleSystem.ets) -->

``` TypeScript
async function loadByName(name: string): Promise<string> {
  if (name === 'profile') {
    let profileModule = await import('../common/ProfileFeature');
    return profileModule.getProfileLabel();
  }

  if (name === 'settings') {
    let settingsModule = await import('../common/SettingsFeature');
    return settingsModule.getSettingsLabel();
  }

  return 'unknown';
}
```

## Module Path

A module path specifies the location of the source file for imports and exports. ArkTS supports two forms: relative paths (starting with `./` or `../`) and ohpm package names. The `.ts` suffix can be omitted from relative paths.

### Relative Path

A relative path is suitable for expressing dependencies near the current module.

<!-- @[relative_path_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/RelativePathImport.ets) -->

``` TypeScript
import { User } from '../common/User';
import { AppConfig } from '../config/appConfig';
import { UserRepository } from '../common/Repository';
```

### Path Alias

TypeScript supports path aliases through configurations such as `baseUrl` and `paths`. The degree of support in an ArkTS project depends on the project configuration and build tools. In public tutorials, prefer standard relative paths or platform-recommended paths.

**TypeScript Comparison**

<!-- @[ts_path_alias_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/ModuleSystem.ts) -->

``` TypeScript
// TypeScript/project configuration comparison
import { describe } from '@ohos/hypium';
```

## Module Organization

Manage the exports of multiple modules through the directory structure and barrel files.

### Organize by Domain

Organizing modules by domain groups related functionality together, improving code maintainability.

<!-- @[submodule_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/common/Types.ets) -->

``` TypeScript
export interface User {
  id: number;
  name: string;
}
```

Repository classes in the same directory import and use the types described above.

<!-- @[submodule_repository](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/common/Repository.ets) -->

``` TypeScript
import { User } from './Types';

export class UserRepository {
  private users: User[] = [];

  save(user: User): void {
    this.users.push(user);
  }

  list(): User[] {
    return this.users;
  }
}
```

Then, a barrel file aggregates and exposes the public APIs of each module.

<!-- @[submodule_barrel_file](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/SubmoduleBarrelFile.ets) -->

``` TypeScript
export { User } from '../common/Types';
export { UserRepository } from '../common/Repository';
```

### Avoiding Circular Dependencies

Circular dependencies complicate the module initialization order. When modules import each other, extract the shared types, constants, or interfaces into a separate module first.

<!-- @[shared_types_definition](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/common/Types.ets) -->

``` TypeScript
// Types.ets
export interface UserIdentity {
  id: number;
}
```

After importing the shared types, other modules can use them without depending on each other directly.

<!-- @[shared_types_usage_profile](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/SharedTypesUsage.ets) -->

``` TypeScript
import { UserIdentity } from '../common/Types';

export function getProfileName(identity: UserIdentity): string {
  return 'user-' + identity.id.toString();
}
```

The same shared type can be reused across multiple modules.

<!-- @[shared_types_usage_permission](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/SharedTypesUsage.ets) -->

``` TypeScript
export function canRead(identity: UserIdentity): boolean {
  return identity.id > 0;
}
```

## Top-Level Statements

Top-level statements are statements written at the outermost level of a module, not wrapped by any function, class, or block scope. These statements include variable declarations, function declarations, and expressions.

<!-- @[top_level_statements](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ModuleSystem.ets) -->

``` TypeScript
// Top-level statement of the module
let appConfig: string = 'production';
const MAX_RETRIES: number = 3;

function logConfig(): void {
  console.info(`Config: ${appConfig}, Retries: ${MAX_RETRIES}`);
}

// Top-level expression
console.info('Module loaded');
logConfig();
```

Top-level statements are executed from top to bottom when the module is loaded, making them suitable for module-level initialization logic.

## TypeScript Module Syntax Boundaries

TypeScript's CommonJS syntax is not supported in ArkTS. Use ES modules as the alternative.

### TypeScript namespace Comparison

The `namespace` in TypeScript is an early way of organizing code. Both modern TypeScript and ArkTS should prefer ES modules.

**TypeScript Comparison**

<!-- @[ts_avoid_namespace](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/ModuleSystem.ts) -->

``` TypeScript
// TypeScript comparison syntax; not used in regular ArkTS business code.
namespace Validation {
  export function isName(value: string): boolean {
    return value.length > 0;
  }
}
```

### Declare Module Comparison

The `declare module` commonly used in `.d.ts` files describes external module types and is not ordinary ArkTS business code.

**TypeScript Comparison**

<!-- @[ts_declaration_comparison](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/ModuleDeclaration.ts) -->

``` TypeScript
// TypeScript declaration file comparison
declare module 'external-library' {
  export function run(): void;
}
```

## ArkTS Constraints

ArkTS does not support `require` and `namespace`; use the ES module `import`/`export` instead.

### Not Using require

ArkTS does not support CommonJS `require`; use ES module `import` instead.

**TypeScript Comparison**

<!-- @[ts_require_syntax](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/ModuleSystem.ts) -->

``` TypeScript
// TypeScript supports CommonJS require syntax, while ArkTS uses ES module import.
const Service = require('../common/Service');
Service.createProduct('Widget');
```

In ArkTS, use ES module `import` to achieve the same import.

<!-- @[use_esm_not_commonjs](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ModuleSystem.ets) -->

``` TypeScript
// Use ES module import instead of CommonJS require.
import { createProduct } from '../common/Service';
```

### Do Not Use namespace to Organize Business Code

namespace is used for type declarations, and business code should be organized using modules.

<!-- @[use_module_not_namespace](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/UseModuleNotNamespace.ets) -->

``` TypeScript
export class UserService {}
```

### No Dependency on the Global Script Scope

Modules establish dependencies through `import` and `export`, without implicitly attaching variables to the global scope.

<!-- @[export_constant](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/common/Config.ets) -->

``` TypeScript
// Config.ets
export const APP_NAME: string = 'DemoApp';
export const version: string = '1.0';
```

After obtaining the constant, the importing party can use it in its own module.

<!-- @[import_constant](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ImportConstant.ets) -->

``` TypeScript
import { APP_NAME } from '../common/Config';

console.info(`${APP_NAME}`);
```

## export = and import =

TypeScript supports the `export =` syntax to export the entire module as a single object, used together with `import = require()` for CommonJS interoperability. **ArkTS does not support this syntax**; use the ES module `export default` and `import` as an alternative.

**TypeScript comparison**

<!-- @[ts_export_equals_import_equals](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/ModuleSystem.ts) -->

``` TypeScript
// TypeScript/CommonJS comparison syntax, not supported by ArkTS
class TsCalculator {
  add(a: number, b: number): number {
    return a + b;
  }
}

export = TsCalculator;
// Importer (another file):
// import Calculator = require('calculator');
// let calc = new Calculator();
// console.info(calc.add(1, 2)); // 3
```

ArkTS alternative:

<!-- @[export_import_default_class](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ModuleSystem.ets) -->

``` TypeScript
export default class EidcCalculator {
  add(a: number, b: number): number {
    return a + b;
  }
}

let eidcCalc: EidcCalculator = new EidcCalculator();
console.info(`${eidcCalc.add(1, 2)}`); // 3
```

## Triple-Slash Directives

TypeScript supports triple-slash directives (`/// <reference ... />`) to declare dependencies between files in `.d.ts` files. **ArkTS does not support triple-slash directives**, and dependencies between modules are established through `import`/`export`.

**TypeScript Comparison**

<!-- @[ts_triple_slash_directives](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/ModuleSystem.ts) -->

``` TypeScript
// TypeScript declaration file syntax; not supported in ArkTS.
/// <reference path="myModule.d.ts" />
/// <reference types="node" />
/// <reference lib="es2015" />

// The directive above declares dependencies between files in a .d.ts file.
// In ArkTS, module dependencies are established through import/export.
```

In ArkTS, all module dependencies are explicitly declared through the ES module `import` statement. The compiler automatically resolves the dependencies, eliminating the need to manually reference declaration files.

## isolatedModules

The `isolatedModules` option in TypeScript ensures that each file can be compiled independently, preventing cross-file type inference dependencies. In this mode, `import type` is used for type-only imports, and `const enum` requires special handling. The ArkTS compiler inherently guarantees that each file can be compiled independently. Type imports use the ordinary `import`, and the `isolatedModules` configuration is not involved.

> **NOTE**
>
> In ArkTS, all import statements can import both values and types. The compiler automatically handles type erasure, so you do not need to distinguish between type imports and value imports.

## Namespace in Detail

The TypeScript `namespace` is an early code organization mechanism that supports nesting, aliases, and multi-file collaboration. ArkTS does not use namespaces to organize business code; it uses ES modules as the alternative. The following compares the TypeScript namespace features.

### Namespace Alias

TypeScript supports `import name = Say.Hello` to create an alias for a namespace member, simplifying deeply nested references. In ArkTS, use the renamed import of ES modules as an alternative.

**TypeScript Comparison**

<!-- @[ts_namespace_alias](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/ModuleSystem.ts) -->

``` TypeScript
// TypeScript comparison syntax, not supported in ArkTS.
namespace App {
  export namespace Config {
    export const version: string = '1.0';
  }
}

import ver = App.Config.version;
console.info(`${ver}`); // 1.0
```

ArkTS alternative:

<!-- @[rename_import_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ModuleSystem.ets) -->

``` TypeScript
import { version as riaVer } from '../common/Config';

console.info(`${riaVer}`); // 1.0
```

### Multi-File Collaboration

TypeScript namespaces can be split and merged across files through `/// <reference path="..." />`. In ArkTS, cross-file code sharing uses the ES module `import`/`export`; each file is an independent module, and dependencies are established through imports and exports.

### Namespace Pitfalls

TypeScript namespaces have the following pitfalls, which ArkTS naturally avoids by using ES modules:

- Do not use namespaces to organize code (use modules as the alternative) — ArkTS enforces the use of modules.

- Do not mix namespaces with modules — ArkTS supports only modules.

- Compatibility issues between `isolatedModules` and namespaces — ArkTS does not involve this configuration.