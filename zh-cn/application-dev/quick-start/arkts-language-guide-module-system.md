# 模块系统
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

模块系统用于把代码拆分为边界清晰、可复用、可维护的文件。ArkTS使用ES模块的`import`和`export`语法，不支持CommonJS的`require`和命名空间。

## 模块基础

模块是组织代码的基本单位，通过导入导出实现复用。

### 模块的定义

包含顶层`import`或`export`的文件会被视为模块。模块中的变量、函数、类、接口默认只在当前文件可见，只有通过`export`导出的声明才能被其他模块导入。

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

### 模块的导入

使用`import { name } from 'path'`语法引入其他模块导出的绑定，在当前文件中使用。

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

### 空导出标记模块

TypeScript中，一个没有顶层导入或导出的文件通常按脚本处理。需要显式把文件标记为模块时，可以使用空导出：

<!-- @[empty_export](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ModuleSystem.ets) -->

``` TypeScript
export {}
```
ArkTS文件通常按工程模块组织，仍建议通过清晰的导入导出表达模块边界。

## export导出

通过`export`可将模块内的声明标记为公开API，供其他模块按需导入复用，支持命名导出和默认导出两种形式。

### 声明时导出

可以在声明变量、常量、函数、类、接口或类型别名时直接导出。

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

### 统一导出

也可以先声明，再在文件末尾统一导出。统一导出适合让模块的公开API集中可见。

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

### 重命名导出

使用`export { name as newName }`语法在导出时重命名绑定，避免命名冲突或提升API可读性。

<!-- @[export_rename](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ModuleSystem.ets) -->

``` TypeScript
class InternalUserService {
  getName(): string {
    return 'UserService';
  }
}

export { InternalUserService as RenamedUserService };
```

### 默认导出

默认导出使用export default导出主要功能，导入时可使用任意名称。

<!-- @[default_export](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/common/Logger.ets) -->

``` TypeScript
// Logger.ets
export default class Logger {
  info(message: string): void {
    console.info(`${message}`);
  }
}
```

在另一个文件中，可以通过默认导入使用该类。

<!-- @[default_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/DefaultImport.ets) -->

``` TypeScript
import Logger from '../common/Logger';

let logger: Logger = new Logger();
logger.info('module loaded');
```
大型项目中，公共API通常优先使用命名导出，因为命名导出在代码检索、重构维护和接口约束方面具有明显优势。

### 重新导出

重新导出常用于模块入口文件，把同一领域下的多个文件聚合成一个稳定入口。

<!-- @[submodule_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/common/Types.ets) -->

``` TypeScript
export interface User {
  id: number;
  name: string;
}
```

在另一个源文件中定义服务类，对外提供业务方法。

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

随后通过桶文件将这些分散的导出聚合为统一入口。

<!-- @[barrel_file_reexport](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ModuleSystem.ets) -->

``` TypeScript
export { User } from '../common/Types';
export { UserService } from '../common/Service';
```

使用方只需从桶文件导入，无需关心各成员的来源文件。

<!-- @[barrel_file_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/BarrelFileImport.ets) -->

``` TypeScript
import { User, UserService } from '../common/User';

let service: UserService = new UserService();
let user: User | null = service.findById(1);
console.info(`${user ? user.name : 'not found'}`);
```

## 静态导入

通过`import`引入其他模块导出的绑定，在当前文件中使用其类型、函数或类，支持命名导入和整体导入。

### 命名导入

使用`import { name } from 'path'`按名称导入模块的命名导出，大括号内可列出多个绑定。

<!-- @[named_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/NamedImport.ets) -->

``` TypeScript
import { UserService } from '../common/User';

let service: UserService = new UserService();
```

### 重命名导入

当导入名称与当前文件已有名称冲突，或需要提高可读性时，建议重命名。

<!-- @[import_rename](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ImportRename.ets) -->

``` TypeScript
import { UserService as AccountUserService } from '../common/User';

let service: AccountUserService = new AccountUserService();
```

### 默认导入

使用`import Name from 'path'`导入模块的默认导出，名称无需与导出时一致。

<!-- @[default_import_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/DefaultImport.ets) -->

``` TypeScript
import Logger from '../common/Logger';

let logger: Logger = new Logger();
```

### 默认导入与命名导入组合

使用`import defaultName, { namedName } from 'path'`在同一条语句中同时导入默认导出和命名导出。

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

在消费端可以同时导入默认导出和命名导出。

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

### 命名空间导入

命名空间导入会把某个模块的全部命名导出放到一个对象上。它不是TypeScript `namespace`声明，只是ES模块导入语法。

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

使用命名空间导入可以将模块的全部命名导出收拢到一个对象上。

<!-- @[namespace_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/NamespaceImport.ets) -->

``` TypeScript
import * as MathUtil from '../common/Math';

let sum: number = MathUtil.add(1, 2);
let product: number = MathUtil.multiply(3, 4);
console.info(`${sum}, ${product}`);
```

### 副作用导入

副作用导入会执行目标模块，但不导入任何绑定。使用时应谨慎，避免隐藏初始化逻辑。

<!-- @[side_effect_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/SideEffectImport.ets) -->

``` TypeScript
import '../common/Config';
```

## 类型导入与类型导出

TypeScript支持`import type`和`export type`语法标记类型专用导入导出。ArkTS中使用普通`import`引入类型声明。

### TypeScript类型专用导入

TypeScript支持`import type`和`export type`，用于标记只在类型位置使用的导入导出。

<!-- @[ts_type_import_export](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/ModuleSystem.ts) -->

``` TypeScript
// TypeScript支持import type和export type，ArkTS按工具链支持情况使用
import type { User } from '../common/User';
export type { User };
```

### ArkTS中的import语句导入

ArkTS使用普通`import`引入类型声明，不使用`import type`专用语法，类型与值统一通过`import`导入。

<!-- @[type_import_usage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeImportUsage.ets) -->

``` TypeScript
import { User } from '../common/User';

function printUser(user: User): void {
  console.info(`${user.name}`);
}
```

## 动态导入

使用`import()`在运行时按需加载模块，返回Promise，常与async/await搭配实现懒加载。

### 基本写法

动态导入用于按需加载模块。它返回`Promise`，因此通常与`async`/`await`搭配使用。

<!-- @[dynamic_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ModuleSystem.ets) -->

``` TypeScript
async function loadFeatureLabel(): Promise<string> {
  let moduleObject = await import('../common/Feature');
  return moduleObject.getFeatureLabel();
}
```

被动态加载的模块照常导出成员。

<!-- @[dynamic_import_module](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/common/Feature.ets) -->

``` TypeScript
export function getFeatureLabel(): string {
  return 'feature';
}
```

### 使用限制

动态导入的模块路径应保持可静态分析。涉及打包、分包、跨包加载或运行时权限时，需要遵循HarmonyOS工程和运行时约束。

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

## 模块路径

模块路径指定导入导出的源文件位置，ArkTS支持相对路径（`./`或`../`开头）与ohpm包名两种形式，相对路径可省略`.ts`后缀。

### 相对路径

相对路径适合表达当前模块附近的依赖关系。

<!-- @[relative_path_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/RelativePathImport.ets) -->

``` TypeScript
import { User } from '../common/User';
import { AppConfig } from '../config/appConfig';
import { UserRepository } from '../common/Repository';
```

### 路径别名

TypeScript支持通过`baseUrl`、`paths`等配置实现路径别名。ArkTS工程中的支持程度取决于工程配置和构建工具。公共教程中应优先展示标准相对路径或平台推荐路径。

**TypeScript对照**

<!-- @[ts_path_alias_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/ModuleSystem.ts) -->

``` TypeScript
// TypeScript/工程配置对照写法
import { describe } from '@ohos/hypium';
```

## 模块组织

通过目录结构和桶文件（barrel file）管理多个模块的导出。

### 按领域组织

按领域组织模块将相关功能集中，提高代码的可维护性。

<!-- @[submodule_types](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/common/Types.ets) -->

``` TypeScript
export interface User {
  id: number;
  name: string;
}
```

同一目录下的仓储类导入并使用上述类型。

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

再通过桶文件将各模块的公开API汇总对外暴露。

<!-- @[submodule_barrel_file](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/SubmoduleBarrelFile.ets) -->

``` TypeScript
export { User } from '../common/Types';
export { UserRepository } from '../common/Repository';
```

### 避免循环依赖

循环依赖会让模块初始化顺序变复杂。出现相互导入时，优先把共同类型、常量或接口提取到独立模块。

<!-- @[shared_types_definition](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/common/Types.ets) -->

``` TypeScript
// Types.ets
export interface UserIdentity {
  id: number;
}
```

其他模块导入共享类型后即可使用，无需彼此直接依赖。

<!-- @[shared_types_usage_profile](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/SharedTypesUsage.ets) -->

``` TypeScript
import { UserIdentity } from '../common/Types';

export function getProfileName(identity: UserIdentity): string {
  return 'user-' + identity.id.toString();
}
```

同一共享类型可在多个模块中复用。

<!-- @[shared_types_usage_permission](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/SharedTypesUsage.ets) -->

``` TypeScript
export function canRead(identity: UserIdentity): boolean {
  return identity.id > 0;
}
```

## 顶层语句

顶层语句是指在模块最外层编写的语句，不被任何函数、类或块级作用域包裹。这些语句包括变量声明、函数声明和表达式。

<!-- @[top_level_statements](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ModuleSystem.ets) -->

``` TypeScript
// 模块顶层语句
let appConfig: string = 'production';
const MAX_RETRIES: number = 3;

function logConfig(): void {
  console.info(`Config: ${appConfig}, Retries: ${MAX_RETRIES}`);
}

// 顶层表达式
console.info('Module loaded');
logConfig();
```

顶层语句在模块加载时按从上到下的顺序执行，适合用于模块级别的初始化逻辑。

## TypeScript模块语法边界

TypeScript的CommonJS语法在ArkTS中不支持，使用ES模块替代。

### TypeScript namespace对照

TypeScript的`namespace`是早期组织代码的方式，现代TypeScript和ArkTS都应优先使用ES模块。

**TypeScript对照**

<!-- @[ts_avoid_namespace](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/ModuleSystem.ts) -->

``` TypeScript
// TypeScript对照写法，ArkTS普通业务代码不使用
namespace Validation {
  export function isName(value: string): boolean {
    return value.length > 0;
  }
}
```

### 声明模块对照

`.d.ts`中常见的`declare module`用于描述外部模块类型，不是ArkTS普通业务代码。

**TypeScript对照**

<!-- @[ts_declaration_comparison](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/ModuleDeclaration.ts) -->

``` TypeScript
// TypeScript声明文件对照写法
declare module 'external-library' {
  export function run(): void;
}
```

## ArkTS限制

ArkTS不支持require和namespace，使用ES模块的import/export。

### 不使用require

ArkTS不支持CommonJS的require，使用ES模块的import代替。

**TypeScript对照**

<!-- @[ts_require_syntax](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/ModuleSystem.ts) -->

``` TypeScript
// TypeScript支持CommonJS require语法，ArkTS使用ES模块import
const Service = require('../common/Service');
Service.createProduct('Widget');
```

ArkTS中改用ES模块的import完成同样的导入。

<!-- @[use_esm_not_commonjs](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ModuleSystem.ets) -->

``` TypeScript
// 使用ES模块import代替CommonJS require
import { createProduct } from '../common/Service';
```

### 不使用namespace组织业务代码

namespace用于类型声明，业务代码应使用模块组织。

<!-- @[use_module_not_namespace](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/UseModuleNotNamespace.ets) -->

``` TypeScript
export class UserService {}
```

### 不依赖全局脚本作用域

模块之间通过`import`和`export`建立依赖，不把变量隐式挂到全局作用域。

<!-- @[export_constant](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/common/Config.ets) -->

``` TypeScript
// Config.ets
export const APP_NAME: string = 'DemoApp';
export const version: string = '1.0';
```

导入方获取常量后即可在自己的模块中使用。

<!-- @[import_constant](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ImportConstant.ets) -->

``` TypeScript
import { APP_NAME } from '../common/Config';

console.info(`${APP_NAME}`);
```

## export =与import =

TypeScript支持`export =`语法将整个模块导出为单个对象，配合`import = require()`导入，用于CommonJS互操作。**ArkTS不支持此语法**，使用ES模块的`export default`和`import`替代。

**TypeScript对照**

<!-- @[ts_export_equals_import_equals](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/ModuleSystem.ts) -->

``` TypeScript
// TypeScript/CommonJS对照写法，ArkTS不支持
class TsCalculator {
  add(a: number, b: number): number {
    return a + b;
  }
}

export = TsCalculator;
// 导入方（另一文件）：
// import Calculator = require('calculator');
// let calc = new Calculator();
// console.info(calc.add(1, 2)); // 3
```

ArkTS替代方式：

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

## 三斜线指令

TypeScript支持三斜线指令（`/// <reference ... />`）在`.d.ts`文件中声明文件间依赖关系。**ArkTS不支持三斜线指令**，模块间依赖通过`import`/`export`建立。

**TypeScript对照**

<!-- @[ts_triple_slash_directives](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/ModuleSystem.ts) -->

``` TypeScript
// TypeScript声明文件写法，ArkTS不支持
/// <reference path="myModule.d.ts" />
/// <reference types="node" />
/// <reference lib="es2015" />

// 上述指令在.d.ts文件中声明文件间依赖关系
// ArkTS中模块依赖通过import/export建立
```

ArkTS中所有模块依赖通过ES模块的`import`语句显式声明，编译器自动解析依赖关系，无需手动引用声明文件。

## isolatedModules

TypeScript的`isolatedModules`选项确保每个文件可独立编译，防止跨文件类型推断依赖。在此模式下，`import type`用于仅类型导入，`const enum`需特殊处理。ArkTS的编译器天然保证每个文件可独立编译，类型导入使用普通`import`，不涉及`isolatedModules`配置。

> **说明：**
> 
> ArkTS中所有导入语句既能导入值也能导入类型，编译器自动处理类型擦除，开发者无需区分类型导入和值导入。

## 命名空间详解

TypeScript的命名空间（`namespace`）是早期的代码组织方式，支持嵌套、别名和多文件协作。ArkTS不使用命名空间组织业务代码，使用ES模块替代。以下为TypeScript命名空间特性对照。

### 命名空间别名

TypeScript支持`import name = Say.Hello`创建命名空间成员的别名，简化深层嵌套引用。ArkTS中使用ES模块的重命名导入替代。

**TypeScript对照**

<!-- @[ts_namespace_alias](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/ModuleSystem.ts) -->

``` TypeScript
// TypeScript对照写法，ArkTS不支持
namespace App {
  export namespace Config {
    export const version: string = '1.0';
  }
}

import ver = App.Config.version;
console.info(`${ver}`); // 1.0
```

ArkTS替代：

<!-- @[rename_import_alternative](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/ModuleSystem.ets) -->

``` TypeScript
import { version as riaVer } from '../common/Config';

console.info(`${riaVer}`); // 1.0
```

### 多文件协作

TypeScript命名空间可通过`/// <reference path="..." />`跨文件拆分合并。ArkTS中跨文件共享代码使用ES模块的`import`/`export`，每个文件是独立模块，通过导入导出建立依赖。

### 命名空间陷阱

TypeScript中命名空间存在以下陷阱，ArkTS通过使用ES模块天然避免：

- 不应使用命名空间组织代码（用模块替代）——ArkTS强制使用模块。
- 命名空间与模块不应混用——ArkTS只支持模块。
- `isolatedModules`与命名空间的兼容问题——ArkTS不涉及此配置。
