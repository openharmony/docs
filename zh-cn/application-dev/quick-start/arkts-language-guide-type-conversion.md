# 类型转换
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @oatuwwutao-->
<!--Designer: @oatuwwutao-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

类型转换是ArkTS类型系统中的重要概念。通过类型转换，可以在类型系统中安全地处理不同类型的数据，实现类型的灵活转换。

## 类型转换的基础概念

ArkTS在类型系统中通过以下机制处理类型：类型守卫（typeof、instanceof）通过运行时检查收窄类型，是最安全的类型缩小方式；类型断言（as）告知编译器值的类型，仅在编译时生效，不改变运行时类型；数据转换（如`Number()`、`String()`）在运行时执行实际的数据类型转换。

### 类型转换的定义与作用

类型转换将值从一种类型转换为另一种类型，在ArkTS中主要用于类型收窄（将联合类型缩小到具体类型）、类型断言（告知编译器值的具体类型）和类型推断辅助。

<!-- @[ts_type_conversion_purpose](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/TypeConversion.ts) -->

``` TypeScript
function getTcpValue(): string | number {
  return 'Hello, ArkTS';
}

let tcpValue: string | number = getTcpValue();

// 不使用类型转换，无法访问字符串的方法
tcpValue.toUpperCase(); // 编译错误：string | number类型上不存在toUpperCase

// 使用类型守卫收窄后，可以访问字符串方法
if (typeof tcpValue === 'string') {
  let strLength: number = tcpValue.length;
  console.info(`${strLength}`); // 13
}
```

### 类型转换的分类

类型转换按方向分为向上转型（子类到父类，隐式安全）和向下转型（父类到子类，需显式断言和类型检查）。

<!-- @[class_upcast_downcast_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
class Animal {
  public name: string;
  
  constructor(name: string) {
    this.name = name;
  }
  
  public speak(): void {
    console.info(`${this.name} makes a sound`);
  }
}

class Dog extends Animal {
  public breed: string;
  
  constructor(name: string, breed: string) {
    super(name);
    this.breed = breed;
  }
  
  public bark(): void {
    console.info(`${this.name} barks: Woof! Woof!`);
  }
}

// 向上转型（隐式）
let dog: Dog = new Dog('Buddy', 'Golden Retriever');
let animal: Animal = dog; // 自动转换

// 向下转型（显式，需要类型检查）
let pet: Animal = new Dog('Max', 'Labrador');
if (pet instanceof Dog) {
  let myDog: Dog = pet; // 类型安全
  myDog.bark();
}
```

### 类型转换的核心原则

类型转换应优先使用明确联合类型配合类型守卫，避免对宽泛类型（如Object）直接断言，以保证运行时类型安全。

<!-- @[union_type_guard_vs_assertion](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
// 反例：使用宽泛类型后直接断言
let broadTypeValue: Object = 'Hello';
let broadTypeLength: number = (broadTypeValue as string).length; // 缺少运行时检查

// 推荐：使用明确联合类型 + 类型守卫
let unionTypeValue: string | number = 'Hello';

// 类型安全的转换
if (typeof unionTypeValue === 'string') {
  let unionTypeLength: number = unionTypeValue.length; // 编译器知道unionTypeValue是string类型
  console.info(`${unionTypeLength}`);
}
```

## 类型断言（Type Assertion）

类型断言是一种告诉编译器"我知道这个值是什么类型"的方式。它在编译时提供类型信息，但不会在运行时进行类型检查。类型断言是ArkTS类型系统的灵活特性。

`as`关键字是ArkTS中推荐的类型断言语法，用于将一个值的类型断言为另一个类型。

### 尖括号语法

尖括号语法（`<T>`value）进行类型断言，告知编译器值的类型。

**TypeScript对照**

<!-- @[ts_typescript_angle_bracket_assertion_not_used](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/TypeConversion.ts) -->

``` TypeScript
// TypeScript对照写法，ArkTS不使用：
let value: Object = 'hello';
let length: number = (<string>value).length;
```

### as关键字语法

`as`关键字（`value as Type`）进行类型断言，告知编译器将值视为指定类型。

<!-- @[as_keyword_type_assertion](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
let assertValueObj: Object = 'Hello, ArkTS';

// 使用as关键字进行类型断言
if (typeof assertValueObj === 'string') {
  let assertLength: number = (assertValueObj as string).length;
  console.info(`${assertLength}`); // 13
}

// 断言为联合类型
let mixedValue: Object = 42;
let numValue: number | string = mixedValue as number | string;

// 断言为自定义类型
interface AssertUser {
  id: number;
  name: string;
  email: string;
}

let userData: AssertUser = {
  id: 1,
  name: 'Alice',
  email: 'alice@example.com'
};

let assertUser: AssertUser = userData as AssertUser;
console.info(`${assertUser.name}`); // Alice
```

### 类型断言的使用限制

类型断言仅在编译时生效，不改变运行时类型；不能在不相关的类型间直接断言，需要先经过unknown或运行时转换。

<!-- @[ts_assertion_runtime_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/TypeConversion.ts) -->

``` TypeScript
let runtimeTypeValue: Object = 123;

// 类型断言不会将数字转换为字符串
let assertedString: string = runtimeTypeValue as string;

console.info(`${typeof assertedString}`); // "number"（运行时类型仍然是number）
assertedString.toUpperCase(); // 运行时错误：toUpperCase is not a function
```

类型断言在不相关类型间无法直接使用，需区分合理与不合理的断言场景：

<!-- @[ts_reasonable_vs_unreasonable_assertion](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/TypeConversion.ts) -->

``` TypeScript
// 不合理：将string断言为number
let unreasonableStr: string = '123';
let unreasonableNum: number = unreasonableStr as number; // 编译错误

// 合理方式：先转换，再断言
let num: number = Number(unreasonableStr);

// 双重断言（TypeScript对照写法，ArkTS不使用）
let unreasonableValue: string = 'Hello';
let unreasonableUnsafeNum: number = unreasonableValue as unknown as number;
```

类型断言与类型转换有本质区别：断言仅作用于编译期，转换则在运行时执行。注意以下示例中`as number`仅告知编译器类型，运行时`assertedNum`仍为string，若直接当number使用会产生运行时错误：

<!-- @[type_assertion_vs_type_conversion](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
// 类型断言：仅编译时生效
let value1: Object = '123';
let assertedNum: number = value1 as number;
console.info(`${typeof assertedNum}`); // "string"（运行时类型未改变）

// 类型转换：运行时执行转换
let value2: string = '123';
let convertedNum: number = Number(value2);
console.info(`${typeof convertedNum}`); // "number"（运行时类型已改变）
```

### 类型断言的合理使用场景

类型断言适用于类型检查后的安全收窄、外部数据结构的断言（如DOM元素、API响应解析）等需要告知编译器具体类型的场景。注意：在`typeof`等类型守卫已收窄类型后，`as`断言是多余的，可省略。

<!-- @[type_assertion_with_type_check](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
function processValue(value: string | number | boolean): void {
  // 使用类型断言前，应进行类型检查
  if (typeof value === 'string') {
    let strValue: string = value as string; // 此时断言是安全的
    console.info(`${strValue.toUpperCase()}`);
  } else if (typeof value === 'number') {
    let numValue: number = value as number;
    console.info(`${numValue.toFixed(2)}`);
  }
}
```

对DOM元素等外部对象，可在类型检查后用`as`断言为具体结构。

<!-- @[ts_dom_element_type_assertion](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/TypeConversion.ts) -->

``` TypeScript
// 获取DOM元素（浏览器环境）
interface HTMLInputElement {
  value: string;
}

interface MockDocument {
  getElementById: (id: string) => HTMLInputElement;
}

let mockDoc: MockDocument = {
  getElementById: (id: string): HTMLInputElement => {
    let element: HTMLInputElement = { value: '' };
    return element;
  }
};
let inputElement = mockDoc.getElementById('username') as HTMLInputElement;
inputElement.value = 'Alice';

// 或者使用可选链
let element = mockDoc.getElementById('password') as HTMLInputElement | null;
if (element) {
  console.info(`${element.value}`);
}
```

解析API响应JSON时，可用`as`将解析结果断言为预定义的响应接口类型。

<!-- @[ts_api_response_type_assertion](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/TypeConversion.ts) -->

``` TypeScript
interface ApiResponse {
  code: number;
  message: string;
  data: UserData;
}

interface UserData {
  id: number;
  name: string;
}

function parseApiResponse(jsonStr: string): ApiResponse {
  return JSON.parse(jsonStr) as ApiResponse;
}

let jsonResponse = '{"code":200,"message":"success","data":{"id":1,"name":"Alice"}}';
let response: ApiResponse = parseApiResponse(jsonResponse);
console.info(`${response.message}`); // success
```

## 类型守卫（Type Guard）

类型守卫是一种在运行时检查类型，并在编译时收窄类型范围的表达式。相比类型断言，类型守卫更安全，因为它在运行时进行实际检查。

typeof类型守卫使用`typeof`运算符检查基础类型，是最常用的类型守卫方式。

### typeof类型守卫

用于判断基础类型：`string`、`number`、`boolean`、`symbol`、`undefined`、`function`、`object`。

<!-- @[typeof_type_guard](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
function typeGuardProcessValue(value: string | number | boolean): void {
  if (typeof value === 'string') {
    // 编译器知道value是string类型
    console.info(`字符串长度: ${value.length}`);
    console.info(`大写: ${value.toUpperCase()}`);
  } else if (typeof value === 'number') {
    // 编译器知道value是number类型
    console.info(`数值: ${value.toFixed(2)}`);
    console.info(`平方: ${value * value}`);
  } else if (typeof value === 'boolean') {
    // 编译器知道value是boolean类型
    console.info(`布尔值: ${value ? '真' : '假'}`);
  }
}

typeGuardProcessValue('Hello');  // 字符串长度: 5, 大写: HELLO
typeGuardProcessValue(42);       // 数值: 42.00, 平方: 1764
typeGuardProcessValue(true);     // 布尔值: 真
```

### instanceof类型守卫

`instanceof`检查对象是否是某个类的实例（沿原型链逐级匹配），在`if`分支中实现类型收窄——TypeScript在该分支内将对象类型缩小到目标类类型，从而安全访问该类特有的成员。

<!-- @[instanceof_type_guard](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
class TypeGuardDog {
  public name: string;
  
  constructor(name: string) {
    this.name = name;
  }
  
  public bark(): void {
    console.info(`${this.name} barks: Woof!`);
  }
}

class Cat {
  public name: string;
  
  constructor(name: string) {
    this.name = name;
  }
  
  public meow(): void {
    console.info(`${this.name} meows: Meow!`);
  }
}

function makeSound(pet: TypeGuardDog | Cat): void {
  console.info(`Pet name: ${pet.name}`);
  
  if (pet instanceof TypeGuardDog) {
    // 编译器知道pet是TypeGuardDog类型
    pet.bark();
  } else if (pet instanceof Cat) {
    // 编译器知道pet是Cat类型
    pet.meow();
  }
}

let myDog = new TypeGuardDog('Buddy');
let myCat = new Cat('Whiskers');

makeSound(myDog); // Pet name: Buddy, Buddy barks: Woof!
makeSound(myCat); // Pet name: Whiskers, Whiskers meows: Meow!
```

### in类型守卫

TypeScript支持通过`'prop' in obj`判断对象是否包含指定属性并完成类型收窄。ArkTS不支持`in`操作符进行类型收窄（`arkts-no-in`），详见[从TypeScript到ArkTS的适配规则](typescript-to-arkts-migration-guide.md#不支持in运算符)，推荐为联合类型添加稳定的判别字段。

**TypeScript对照**

<!-- @[ts_discriminated_union_instead_of_in_operator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/TypeConversion.ts) -->

``` TypeScript
interface Bird {
  kind: 'bird';
  fly: () => void;
  layEggs: () => void;
}

interface Fish {
  kind: 'fish';
  swim: () => void;
  layEggs: () => void;
}

let birdOrFish: Bird | Fish = {
  kind: 'bird',
  fly: () => console.info(`Flying`),
  layEggs: () => console.info(`Laying eggs`)
};

// TypeScript对照写法，ArkTS不使用：
if ('fly' in birdOrFish) {
    birdOrFish.fly();
}

function move(animal: Bird | Fish): void {
  switch (animal.kind) {
    case 'bird':
      animal.fly();
      break;
    case 'fish':
      animal.swim();
      break;
  }

  // layEggs在两个接口中都存在
  animal.layEggs();
}

let bird: Bird = {
  kind: 'bird',
  fly: () => console.info(`Flying high`),
  layEggs: () => console.info(`Laying eggs in nest`)
};

let fish: Fish = {
  kind: 'fish',
  swim: () => console.info(`Swimming deep`),
  layEggs: () => console.info(`Laying eggs in water`)
};

move(bird); // Flying high, Laying eggs in nest
move(fish); // Swimming deep, Laying eggs in water
```

### 类型收窄的概念与方式

类型收窄是指在类型守卫（typeof、instanceof等）的作用域内，编译器自动将联合类型收窄为具体类型。

其过程是：先定义联合类型或宽泛类型，再用类型守卫检查类型，在守卫分支内即可访问类型特定成员，编译器会自动收窄类型范围。

<!-- @[type_narrowing_concept](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
type StringOrNumber = string | number;

function narrowProcessValue(value: StringOrNumber): string {
  // typeof收窄：在分支内value被收窄为具体类型
  if (typeof value === 'string') {
    return value.toUpperCase();  // value: string
  } else {
    return value.toFixed(2);     // value: number
  }
}
```

### 自定义判断函数与判别联合

TypeScript可使用`value is Type`格式声明类型谓词。ArkTS不使用`is`类型谓词；需要封装判断逻辑时，辅助函数返回`boolean`，类型专有成员访问仍通过类型判别条件所在分支完成。

<!-- @[discriminated_union_vehicle_example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
interface Car {
  type: 'car';
  drive: () => void;
}

interface Boat {
  type: 'boat';
  sail: () => void;
}

interface Plane {
  type: 'plane';
  fly: () => void;
}

type Vehicle = Car | Boat | Plane;

function isCarKind(vehicle: Vehicle): boolean {
  return vehicle.type === 'car';
}

function isBoatKind(vehicle: Vehicle): boolean {
  return vehicle.type === 'boat';
}

function isPlaneKind(vehicle: Vehicle): boolean {
  return vehicle.type === 'plane';
}

function operateVehicle(vehicle: Vehicle): void {
  switch (vehicle.type) {
    case 'car':
      vehicle.drive();
      break;
    case 'boat':
      vehicle.sail();
      break;
    case 'plane':
      vehicle.fly();
      break;
  }
}

let car: Car = { type: 'car', drive: () => console.info('Driving on road') };
let boat: Boat = { type: 'boat', sail: () => console.info('Sailing on water') };
let plane: Plane = { type: 'plane', fly: () => console.info('Flying in sky') };

operateVehicle(car);   // Driving on road
operateVehicle(boat);  // Sailing on water
operateVehicle(plane); // Flying in sky

console.info(`${isCarKind(car)}`);
console.info(`${isBoatKind(boat)}`);
console.info(`${isPlaneKind(plane)}`);
```

同样的判别联合模式也适用于用户角色等业务领域模型的类型区分：

<!-- @[discriminated_union_user_role](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
interface RegularUser {
  role: 'regular';
  id: number;
  name: string;
  email: string;
}

interface AdminUser {
  role: 'admin';
  id: number;
  name: string;
  email: string;
  adminLevel: number;
  permissions: string[];
}

type RoleUser = RegularUser | AdminUser;

function processUser(user: RoleUser): void {
  console.info(`RoleUser: ${user.name} (${user.email})`);

  switch (user.role) {
    case 'admin':
      console.info(`Admin Level: ${user.adminLevel}`);
      console.info(`Permissions: ${user.permissions.join(', ')}`);
      break;
    case 'regular':
      console.info('Regular user');
      break;
  }
}

let regularUser: RegularUser = {
  role: 'regular',
  id: 1,
  name: 'Alice',
  email: 'alice@example.com'
};

let adminUser: AdminUser = {
  role: 'admin',
  id: 2,
  name: 'Bob',
  email: 'bob@example.com',
  adminLevel: 5,
  permissions: ['read', 'write', 'delete']
};

processUser(regularUser);
// RoleUser: Alice (alice@example.com)
// Regular user

processUser(adminUser);
// RoleUser: Bob (bob@example.com)
// Admin Level: 5
// Permissions: read, write, delete
```

### 真值收窄

在条件表达式中，假值（`0`、`NaN`、`""`、`null`、`undefined`）会被排除，变量收窄为非假值类型。

<!-- @[truthiness_narrowing](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
function processTruthyValue(value: string | null | undefined): void {
  if (value) {
    console.info(`${value.toUpperCase()}`);
  } else {
    console.info('空值');
  }
}

processTruthyValue('hello');
processTruthyValue(null);
```

`Boolean(x)`或`!!x`可将任意值转换为布尔值，用于真值判断。

### 相等性收窄

使用`===`或`!==`比较后，编译器在对应分支中收窄类型。`== null`可同时排除`null`和`undefined`。

<!-- @[equality_narrowing](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
function compareNarrowing(value: string | number | null | undefined): void {
  if (value === 'hello') {
    console.info(`${value.toUpperCase()}`);
  } else if (value === null) {
    console.info('null');
  } else if (value === undefined) {
    console.info('undefined');
  } else {
    console.info(`${value}`);
  }
}

function checkNull(value: string | null | undefined): void {
  if (value == null) {
    console.info('空');
  } else {
    console.info(`${value.toUpperCase()}`);
  }
}
```

### 赋值收窄

变量赋值后，编译器根据右侧值的类型收窄左侧变量的类型。收窄基于声明类型，不会扩展到更宽的类型。

<!-- @[assignment_narrowing](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
let anAssignedValue: string | number = 'hello';
console.info(`${anAssignedValue.toUpperCase()}`); // 编译器知道此时为string
anAssignedValue = 42;
console.info(`${anAssignedValue}`); // 编译器知道此时为number
```

### 控制流分析

编译器沿`if`/`else`、`switch`、循环、三元表达式等控制流追踪类型变化。不可达分支的类型被排除，分支合并后取联合类型。

<!-- @[control_flow_analysis](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
function flowAnalysis(value: string | number): void {
  if (typeof value === 'string') {
    console.info(`${value.length}`);
  } else {
    console.info(`${value}`);
  }
}
```

在循环和条件赋值中，控制流分析也能正确追踪类型变化：

<!-- @[type_inference_union](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
let tiuResult: string | number;
if (Math.random() > 0.5) {
  tiuResult = 'success';
} else {
  tiuResult = 0;
}
console.info(`${tiuResult}`); // string | number
```

### 类型谓词

TypeScript支持`parameterName is Type`语法声明类型谓词函数，在`if`分支中自动收窄类型。**ArkTS不支持`is`类型谓词语法**。

<!-- @[ts_type_predicate](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/TypeConversion.ts) -->

``` TypeScript
// TypeScript写法，ArkTS不支持is类型谓词
function isString(value: unknown): value is string {
  return typeof value === 'string';
}

let tsVal: unknown = 'hello';
if (isString(tsVal)) {
  console.info(`${tsVal.toUpperCase()}`); // HELLO
}
```

ArkTS替代方式：使用`typeof`或`instanceof`在调用处直接收窄，或使用判别联合。

<!-- @[typeof_narrowing_process](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
function processWithTypeof(value: string | number): void {
  if (typeof value === 'string') {
    console.info(`${value.toUpperCase()}`);
  } else {
    console.info(`${value.toFixed(2)}`);
  }
}
```

## 向上转型（隐式转换）

向上转型是指子类实例赋值给父类类型变量，这是类型安全的隐式转换。

### 子类实例赋值给父类类型变量

子类实例可以直接赋值给父类类型变量（隐式向上转型），转型后只能调用父类定义的成员，不能访问子类特有成员。

<!-- @[ts_upcast_subclass_to_parent](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/TypeConversion.ts) -->

``` TypeScript
class Animal {
  public name: string;

  constructor(name: string) {
    this.name = name;
  }

  public speak(): void {
    console.info(`${this.name} makes a sound`);
  }
}

class Dog extends Animal {
  public breed: string;

  constructor(name: string, breed: string) {
    super(name);
    this.breed = breed;
  }

  public bark(): void {
    console.info(`${this.name} barks: Woof! Woof!`);
  }
}

class Cat extends Animal {
  public color: string;

  constructor(name: string, color: string) {
    super(name);
    this.color = color;
  }

  public meow(): void {
    console.info(`${this.name} meows: Meow!`);
  }
}

// 向上转型：子类实例赋值给父类类型变量
let dog: Dog = new Dog('Buddy', 'Golden Retriever');
let animal: Animal = dog; // 隐式转换，类型安全

// 可以调用父类的方法
animal.speak(); // Buddy makes a sound

// 不能调用子类特有的方法
animal.bark(); // 编译错误
```

### 接口实现类赋值给接口类型变量

接口实现类实例可以赋值给接口类型变量（隐式向上转型），转型后只能调用接口定义的成员，不能访问实现类特有方法。

<!-- @[ts_upcast_to_interface](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/TypeConversion.ts) -->

``` TypeScript
interface IShape {
  getArea(): number;
  getPerimeter(): number;
}

class Rectangle implements IShape {
  private width: number;
  private height: number;

  constructor(width: number, height: number) {
    this.width = width;
    this.height = height;
  }

  public getArea(): number {
    return this.width * this.height;
  }

  public getPerimeter(): number {
    return 2 * (this.width + this.height);
  }

  // Rectangle特有的方法
  public getDiagonal(): number {
    return Math.sqrt(this.width ** 2 + this.height ** 2);
  }
}

class Circle implements IShape {
  private radius: number;

  constructor(radius: number) {
    this.radius = radius;
  }

  public getArea(): number {
    return Math.PI * this.radius ** 2;
  }

  public getPerimeter(): number {
    return 2 * Math.PI * this.radius;
  }

  // Circle特有的方法
  public getDiameter(): number {
    return 2 * this.radius;
  }
}

// 向上转型：实现类赋值给接口类型变量
let rectangle: Rectangle = new Rectangle(3, 4);
let shape: IShape = rectangle; // 隐式转换

console.info(`面积: ${shape.getArea()}`);         // 12
console.info(`周长: ${shape.getPerimeter()}`);    // 14

// 不能调用实现类特有的方法
shape.getDiagonal(); // 编译错误
```

### 向上转型的自动性与安全性

子类转换为父类类型时自动完成且类型安全，子类对象包含父类的所有成员。

<!-- @[upcast_automatic_implicit_safe](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
class SafeVehicle {
  public brand: string;
  
  constructor(brand: string) {
    this.brand = brand;
  }
  
  public move(): void {
    console.info(`${this.brand} vehicle is moving`);
  }
}

class SafeCar extends SafeVehicle {
  public model: string;
  
  constructor(brand: string, model: string) {
    super(brand);
    this.model = model;
  }
  
  public drive(): void {
    console.info(`${this.brand} ${this.model} is driving`);
  }
}

// 向上转型是自动的、隐式的
let safeCar: SafeCar = new SafeCar('Toyota', 'Camry');
let vehicle: SafeVehicle = safeCar; // 自动转换

// 向上转型是类型安全的
// 子类对象必定包含父类的所有成员
vehicle.move(); // Toyota vehicle is moving
console.info(`${vehicle.brand}`); // Toyota

// 函数参数的向上转型
function startVehicle(vehicle: SafeVehicle): void {
  vehicle.move();
}

let myCar: SafeCar = new SafeCar('Honda', 'Civic');
startVehicle(myCar); // 自动向上转型
```

### 向上转型后对成员访问的限制

向上转型后，父类类型变量只能调用父类中声明的成员，子类特有成员需向下转型后方可访问。

<!-- @[ts_upcast_access_parent_members_only](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/TypeConversion.ts) -->

``` TypeScript
class Parent {
  public parentMethod(): void {
    console.info(`Parent method`);
  }
}

class Child extends Parent {
  public childMethod(): void {
    console.info(`Child method`);
  }
}

let child: Child = new Child();
let parent: Parent = child; // 向上转型

// 只能访问父类成员
parent.parentMethod(); // 正确
parent.childMethod(); // 编译错误

// 如果需要访问子类成员，需要进行向下转型（类型断言）
if (parent instanceof Child) {
  let childAgain: Child = parent as Child;
  childAgain.childMethod(); // 正确
}
```

## 向下转型（显式转换）

向下转型是指父类类型变量转换为子类类型，需要显式转换并进行类型检查。

### 父类类型变量转换为子类类型

父类类型变量转换为子类类型需要使用as显式断言，应先用instanceof检查实际类型，避免运行时转换失败。

<!-- @[downcast_with_instanceof_check](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
class Animal2 {
  public name: string;

  constructor(name: string) {
    this.name = name;
  }

  public speak(): void {
    console.info(`${this.name} makes a sound`);
  }
}

class Dog2 extends Animal2 {
  public breed: string;

  constructor(name: string, breed: string) {
    super(name);
    this.breed = breed;
  }

  public bark(): void {
    console.info(`${this.name} barks: Woof!`);
  }
}

class Cat2 extends Animal2 {
  public color: string;

  constructor(name: string, color: string) {
    super(name);
    this.color = color;
  }

  public meow(): void {
    console.info(`${this.name} meows: Meow!`);
  }
}

// 向下转型
let downcastAnimal: Animal2 = new Dog2('Buddy', 'Golden Retriever');

// 不安全的向下转型（可能导致运行时错误）
let downcastDog: Dog2 = downcastAnimal as Dog2; // 编译通过，但应该先检查类型

// 安全的向下转型：使用instanceof检查
if (downcastAnimal instanceof Dog2) {
  let dcDog: Dog2 = downcastAnimal; // 类型守卫后自动推断
  dcDog.bark();
}

// 错误示例：向下转型失败
let catAnimal: Animal2 = new Cat2('Whiskers', 'White');
if (catAnimal instanceof Dog2) {
  let dcCatDog: Dog2 = catAnimal;
  dcCatDog.bark();
} else {
  console.info(`This animal is not a dog`);
}
```

### 结合类型守卫的安全向下转型

先用`instanceof`判断对象实际类型，在守卫分支内赋值给子类变量，避免运行时转换失败。

<!-- @[safe_downcast_with_type_guard](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
interface CastShape {
  type: string;
  getArea(): number;
}

class CastRectangle implements CastShape {
  public type: string = 'rectangle';
  private width: number;
  private height: number;
  
  constructor(width: number, height: number) {
    this.width = width;
    this.height = height;
  }
  
  public getArea(): number {
    return this.width * this.height;
  }
  
  public getDiagonal(): number {
    return Math.sqrt(this.width ** 2 + this.height ** 2);
  }
}

class CastCircle implements CastShape {
  public type: string = 'circle';
  private radius: number;
  
  constructor(radius: number) {
    this.radius = radius;
  }
  
  public getArea(): number {
    return Math.PI * this.radius ** 2;
  }
  
  public getDiameter(): number {
    return 2 * this.radius;
  }
}

function processShape(shape: CastShape): void {
  console.info(`Shape type: ${shape.type}`);
  console.info(`Area: ${shape.getArea()}`);
  
  // 使用类型守卫进行安全的向下转型
  if (shape instanceof CastRectangle) {
    let rect: CastRectangle = shape;
    console.info(`Diagonal: ${rect.getDiagonal()}`);
  } else if (shape instanceof CastCircle) {
    let circle: CastCircle = shape;
    console.info(`Diameter: ${circle.getDiameter()}`);
  }
}

let rectangle: CastShape = new CastRectangle(3, 4);
let circle: CastShape = new CastCircle(5);

processShape(rectangle);
// Shape type: rectangle
// Area: 12
// Diagonal: 5

processShape(circle);
// Shape type: circle
// Area: 78.53981633974483
// Diameter: 10
```

### 向下转型失败的处理

向下转型可能失败：使用`as`断言时，编译通过但运行时类型不匹配不会抛异常，而是产生不安全的行为；使用`instanceof`检查后再`as`转换，可在`else`分支中优雅处理转型失败的情况。推荐始终用`instanceof`守卫后再转型。

<!-- @[safe_downcast_function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
class Base {
  public baseMethod(): void {
    console.info('Base method');
  }
}

class Derived extends Base {
  public derivedMethod(): void {
    console.info('Derived method');
  }
}

function safeDowncast(obj: Base): void {
  // 使用instanceof检查，避免运行时错误
  if (obj instanceof Derived) {
    let derived: Derived = obj;
    derived.derivedMethod();
  } else {
    console.info('Downcast failed: object is not an instance of Derived');
  }
}

let base: Base = new Base();
let derived: Base = new Derived();

safeDowncast(base);    // Downcast failed
safeDowncast(derived); // Derived method
```

### 联合类型的向下转型（缩小类型范围）

通过typeof类型守卫将联合类型收窄为具体子类型。

<!-- @[typeof_type_guard_narrowing](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
type StringOrNumberNarrow = string | number;

function typeGuardProcessValue2(value: StringOrNumberNarrow): void {
  // 使用typeof类型守卫缩小类型范围
  if (typeof value === 'string') {
    // 此时value的类型被收窄为string
    console.info(`String value: ${value}`);
    console.info(`Length: ${value.length}`);
    console.info(`Uppercase: ${value.toUpperCase()}`);
  } else {
    // 此时value的类型被收窄为number
    console.info(`Number value: ${value}`);
    console.info(`Fixed: ${value.toFixed(2)}`);
    console.info(`Square: ${value * value}`);
  }
}

typeGuardProcessValue2('Hello'); // String value: Hello, Length: 5, Uppercase: HELLO
typeGuardProcessValue2(42);      // Number value: 42, Fixed: 42.00, Square: 1764
```

## 类型转换与联合类型

联合类型支持多种类型转换，需要类型守卫确保安全。

### 联合类型的类型收窄

通过判别属性将联合类型收窄为具体成员类型。

<!-- @[discriminated_union_animal_speed](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
interface Bird {
  type: 'bird';
  flyingSpeed: number;
}

interface Horse {
  type: 'horse';
  runningSpeed: number;
}

type SpeedAnimal = Bird | Horse;

function getAnimalSpeed(animal: SpeedAnimal): number {
  switch (animal.type) {
    case 'bird':
      return animal.flyingSpeed;
    case 'horse':
      return animal.runningSpeed;
  }
  return 0;
}

// 使用可辨识联合（Discriminated Union）
function getAnimalSpeedV2(animal: SpeedAnimal): number {
  switch (animal.type) {
    case 'bird':
      return animal.flyingSpeed;
    case 'horse':
      return animal.runningSpeed;
  }
  return 0;
}

let bird: Bird = { type: 'bird', flyingSpeed: 100 };
let horse: Horse = { type: 'horse', runningSpeed: 50 };

console.info(`${getAnimalSpeed(bird)}`);   // 100
console.info(`${getAnimalSpeed(horse)}`);  // 50
console.info(`${getAnimalSpeedV2(bird)}`); // 100
console.info(`${getAnimalSpeedV2(horse)}`); // 50
```

### 结合switch语句的联合类型转换

通过switch语句匹配联合类型的判别属性（如`kind`），在每个分支中编译器自动将类型收窄为对应的成员类型，安全访问其专有属性。

<!-- @[discriminated_union_shape_area](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
interface SwitchCircle {
  kind: 'areaCircle';
  radius: number;
}

interface SwitchSquare {
  kind: 'square';
  sideLength: number;
}

interface SwitchRectangle {
  kind: 'areaRectangle';
  width: number;
  height: number;
}

type SwitchShape = SwitchCircle | SwitchSquare | SwitchRectangle;

function getArea(shape: SwitchShape): number {
  switch (shape.kind) {
    case 'areaCircle':
      // 编译器知道shape是Circle类型
      return Math.PI * shape.radius ** 2;
    case 'square':
      // 编译器知道shape是Square类型
      return shape.sideLength ** 2;
    case 'areaRectangle':
      // 编译器知道shape是Rectangle类型
      return shape.width * shape.height;
  }
  return 0;
}

let areaCircle: SwitchCircle = { kind: 'areaCircle', radius: 5 };
let square: SwitchSquare = { kind: 'square', sideLength: 4 };
let areaRectangle: SwitchRectangle = { kind: 'areaRectangle', width: 3, height: 6 };

console.info(`area：${getArea(areaCircle)}`);     // area：78.53981633974483
console.info(`area：${getArea(square)}`);     // area：16
console.info(`area：${getArea(areaRectangle)}`);  // area：18
```

### 可选类型（T | undefined）的转换处理

可选类型（T | undefined）通过条件判断、可选链（?.）或空值合并（??）收窄为具体类型，避免直接访问undefined值。

<!-- @[optional_property_type_guard](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
interface OptUser {
  id: number;
  name: string;
  email?: string; // 可选属性
}

function getUserEmail(user: OptUser): string {
  // 方式1：使用可选链和空值合并
  return user.email ?? '未设置邮箱';
}

function processUserEmail(user: OptUser): void {
  // 方式2：使用条件判断进行类型收窄
  if (user.email !== undefined) {
    // 此时user.email是string类型
    console.info(`Email: ${user.email}`);
    console.info(`Email length: ${user.email.length}`);
  } else {
    console.info(`Email not provided`);
  }
}

// 使用非空断言（!）- 确定值存在时使用
// 反例：如果email不存在会运行时错误
function getEmailLength(user: OptUser): number {
  return user.email!.length;
}

// 推荐：先检查再使用
function getEmailLength2(user: OptUser): number {
  if (user.email) {
    return user.email.length;
  }
  return 0;
}

let optUser1: OptUser = { id: 1, name: 'Alice', email: 'alice@example.com' };
let optUser2: OptUser = { id: 2, name: 'Bob' };

console.info(`${getUserEmail(optUser1)}`); // alice@example.com
console.info(`${getUserEmail(optUser2)}`); // 未设置邮箱

processUserEmail(optUser1);
processUserEmail(optUser2);
```

### 类型转换的综合示例

结合判别联合、类型守卫和switch语句，综合演示API响应处理中类型收窄和安全访问数据的完整流程。

<!-- @[union_type_api_response_handling](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
// 定义联合类型
type Result<T> = Success<T> | Failure;

interface Success<T> {
  status: 'success';
  data: T;
}

interface Failure {
  status: 'failure';
  error: string;
}

// 处理联合类型的函数
function handleResult<T>(result: Result<T>): void {
  switch (result.status) {
    case 'success':
      // 编译器知道result是Success<T> 类型
      console.info(`Success: ${result.data}`);
      break;
    case 'failure':
      // 编译器知道result是Failure类型
      console.error(`Error: ${result.error}`);
      break;
  }
}

// 另一个示例：处理API响应
interface UserData {
  id: number;
  name: string;
}
interface UnionTypeApiResponse {
  code: number;
  data?: UserData;
  message?: string;
}

function processApiResponse(response: UnionTypeApiResponse): void {
  if (response.code === 200) {
    // 使用类型守卫确保data存在
    if (response.data !== undefined) {
      console.info(`Data received: ${response.data.name}`);
    } else {
      console.info('Success but no data');
    }
  } else {
    // 使用空值合并处理可选的message
    const errorMsg = response.message ?? 'Unknown error';
    console.error(`Error ${response.code}: ${errorMsg}`);
  }
}

// 使用示例
let successResult: Result<string> = {
  status: 'success',
  data: 'Hello, ArkTS!'
};

let failureResult: Result<string> = {
  status: 'failure',
  error: 'Network error'
};

handleResult<string>(successResult); // Success: Hello, ArkTS!
handleResult<string>(failureResult); // Error: Network error

let apiSuccess: UnionTypeApiResponse = {
  code: 200,
  data: { id: 1, name: 'Alice' }
};

let apiError: UnionTypeApiResponse = {
  code: 404,
  message: 'Not found'
};

processApiResponse(apiSuccess); // Data received: { id: 1, name: 'Alice' }
processApiResponse(apiError);   // Error 404: Not found
```

## 穷尽性检查

穷尽性检查确保联合类型或枚举的所有可能值都被处理。利用`never`类型，在`switch`的`default`分支中检测遗漏的情况。

<!-- @[exhaustiveness_check](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
interface EcCircle {
  kind: 'circle';
  radius: number;
}

interface EcSquare {
  kind: 'square';
  sideLength: number;
}

type EcShape = EcCircle | EcSquare;

function getEcArea(shape: EcShape): number {
  switch (shape.kind) {
    case 'circle':
      return Math.PI * shape.radius * shape.radius;
    case 'square':
      return shape.sideLength * shape.sideLength;
    default:
      // 如果新增Triangle但忘记处理，这里会编译错误
      const _exhaustiveCheck: never = shape;
      return _exhaustiveCheck;
  }
}

let ecCircle: EcCircle = { kind: 'circle', radius: 5 };
let ecSquare: EcSquare = { kind: 'square', sideLength: 4 };

console.info(`${getEcArea(ecCircle).toString()}`);
console.info(`${getEcArea(ecSquare).toString()}`);
```

`never`类型只能被赋值为`never`本身。当`shape`的类型包含未处理的成员时，赋值给`never`会触发编译错误，从而在编译期发现遗漏。

`never`类型表示永不存在的值。在类型收窄中，当所有可能都被排除后，剩余类型变为`never`。

<!-- @[never_narrowing](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
function processNvValue(value: string | number): void {
  if (typeof value === 'string') {
    console.info(`${value.toUpperCase()}`);
  } else if (typeof value === 'number') {
    console.info(`${value.toFixed(2)}`);
  } else {
    // value类型为never（所有可能已排除）
    const _check: never = value;
    console.info(`Unexpected: ${_check}`);
  }
}

processNvValue('hello');  // HELLO
processNvValue(42);       // 42.00
```

## 类型兼容性

类型兼容性决定一个类型的值能否赋给另一个类型的变量。ArkTS不支持结构类型（鸭子类型），类型兼容基于显式继承和`implements`关系——只有存在显式父子继承或接口实现关系时，类型之间才可互相赋值。

### 结构类型

两个类型只要结构（属性和方法）兼容，即可互相赋值，无需显式继承关系。**ArkTS不支持结构类型（鸭子类型）**，类型兼容基于显式继承和`implements`关系。

<!-- @[ts_structural_typing](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/TypeConversion.ts) -->

``` TypeScript
// TypeScript结构类型，ArkTS不支持
interface TsNamed {
  name: string;
}

class TsPerson {
  public name: string = '';
  public age: number = 0;
}

// TsPerson未声明implements TsNamed，但结构兼容，可直接赋值
let tsNamedItem: TsNamed = new TsPerson();
console.info(`${tsNamedItem.name}`);
```

ArkTS中需要显式`implements`才能实现接口兼容：

<!-- @[structural_typing_explicit](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
interface StNamed {
  name: string;
}

class StPerson implements StNamed {
  public name: string;
  public age: number;

  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }
}

let stNamedItem: StNamed = new StPerson('Alice', 25);
console.info(`${stNamedItem.name}`); // Alice
```

### 函数兼容性

函数兼容性检查参数数量和类型、返回值类型。目标函数参数数量≤源函数参数数量（可少不可多），参数类型需兼容，返回值类型需兼容（协变）。

<!-- @[function_compatibility](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
// 少参数函数可赋给多参数函数类型
type FcGreeter = (name: string) => string;
let fcGreeter: FcGreeter = (name: string): string => `Hello, ${name}`;

type FcBinaryOp = (a: number, b: number) => number;
let fcUnary: FcBinaryOp = (a: number): number => a * 2; // 少一个参数，兼容赋值
```

### 枚举兼容性

不同枚举之间互不兼容，不能互相赋值。数值枚举与`number`兼容，字符串枚举与`string`不兼容。

**TypeScript对照**

<!-- @[ts_enum_compatibility](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/TypeConversion.ts) -->

``` TypeScript
// 不同枚举之间互不兼容
enum EcColor { Red, Green, Blue }
enum EcStatus { Active, Inactive }

let ecC: EcColor = EcColor.Red;
let ecS: EcStatus = ecC; // 编译错误：不同枚举不兼容

let ecN: number = ecC; // 数值枚举可与number兼容
console.info(`${ecN}`); // 0
```

### 类兼容性

类之间的兼容性基于实例成员结构比较，忽略`static`成员。`private`和`protected`成员需来自同一声明。**ArkTS不支持结构类型比较**，不同类之间必须有显式继承关系才能互相赋值。

<!-- @[ts_class_compatibility](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/tsPages/TypeConversion.ts) -->

``` TypeScript
// TypeScript类兼容性（结构比较），ArkTS不支持
class TsAnimalClass {
  public name: string = '';
}

class TsDeviceClass {
  public name: string = '';
}

// 结构相同即可互相赋值，无需继承关系
let tsA: TsAnimalClass = new TsDeviceClass();
console.info(`${tsA.name}`);
```

### 泛型兼容性

泛型类型参数仅在参与成员结构时影响兼容性。如果泛型参数未在成员中使用，则不影响兼容性。

<!-- @[generic_type_compatibility](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/Start/LearningArkTs/ArkTSFullLanguageGuide/entry/src/main/ets/pages/TypeConversion.ets) -->

``` TypeScript
interface Empty<T> {
  value: T;
}

let strContainer: Empty<string> = { value: 'hello' };
let numContainer: Empty<number> = { value: 42 };
// strContainer和numContainer不兼容，因为T参与了成员结构
```
