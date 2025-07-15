# Proxy(代理)

在ArkTS1.2中提供Proxy（代理）能力，能够在运行时提供可代理操作，核心类为“std.core.Proxy”和“std.core.ProxyHandler”。

一共提供如下可代理操作

- **invoke** 用于拦截函数调用，在调用代理对象的method函数时触发此调用。
- **get** 用于拦截class的getter方法调用，或者拦截interface的Property访问。
- **set** 用于拦截class的setter方法调用，或者拦截interface的Property访问。

文档中存在泛型的使用，涉及以下泛型标记符：<br>
- T：Type（类）。

> **说明：**
> 
> 本模块首批接口从ArkTS1.2开始支持。

## 导入模块

- 无需导入，内置。
- namespace：proxy

## Proxy

### create

用于创建代理对象。
- 没有默认构造函数的对象不能被代理。
- 标记为"final"的class不能被代理。
- 代理对象不能被代理。

**签名**

重载1
```ts
static create<T extends Object>(target: T, handler: ProxyHandler<T>): T
```
重载2
```ts
static create<T>(target: Array<T>, handler: ArrayProxyHandler<T>): Array<T>
```
重载3
```ts
static create<T>(target: ReadonlyArray<T>, handler: ReadonlyArrayProxyHandler<T>): ReadonlyArray<T>
```

**参数**

重载1
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| target | T | 是 | 被代理对象，T需继承Object。 |
| handler | ProxyHandler<T\> | 是 | handler定义，需实现ProxyHandler<T\>。 |

重载2
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| target | Array<T\> | 是 | 被代理对象。 |
| handler | ArrayProxyHandler<T\> | 是 | handler定义，需实现ArrayProxyHandler<T\>。 |

重载3
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| target | ReadonlyArray<T\> | 是 | 被代理对象。 |
| handler | ReadonlyArrayProxyHandler<T\> | 是 | handler定义，需实现ReadonlyArrayProxyHandler<T\>。 |

**返回值**

| 类型 | 说明 |
| -------- | -------- |
| T | 任意继承Object的类型。 |

**示例**

```ts
class ClassA {
    field_length:number = 0;

    get length(): number {
        return this.field_length;
    }

    set length(a: number) {
        this.field_length = a;
    }

    public fun(): number {
        return 0;
    }
}

class InterfaceProxyHandler<T extends Object> implements proxy.ProxyHandler<T> {
    public get(target: T, name: string): Any {
        const value = Reflect.get(target, name) as Any;
        return value;
    }

    public set(target: T, name: string, newValue: Any): boolean {
        if (Reflect.get(target, name) !== newValue) {
            const result = Reflect.set(target, name, newValue);
            return result;
        }
        return true;
    }

    public invoke(target: T, method: Method, args: FixedArray<Any>): Any {
        return method.invoke(target, args);
    }
}

function testReflectLamdaTest() {
    let obja = new ClassA();
    let p = proxy.Proxy.create(obja, new InterfaceProxyHandler<ClassA>());
    p.fun();
    p.length = 2;
}

testReflectLamdaTest();
```
## ProxyHandler

### invoke

用于拦截method调用操作，且必须为class的method调用。

**签名**

```ts
invoke(target: T, method: Method, args: FixedArray<Any>): Any
```

**参数**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| target | T | 是 | 被代理对象。 |
| method | Method | 是 | 被代理的method。 |
| args | FixedArray<Any\> | 是 | 被代理的method的入参。 |

**返回值**

| 类型 | 说明 |
| -------- | -------- |
| Any | 返回method调用结果。 |

**示例**

```ts
// 函数定义同上。
let obja = new ClassA();
let p = proxy.Proxy.create(obja, new InterfaceProxyHandler<ClassA>());
console.log(p.length);
```

### get

用于拦截getter操作。
- 必须为class的getter调用，或者interface的Property访问，无法拦截field访问。

**签名**

```ts
get(target: T, name: string): Any
```

**参数**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| target | T | 是 | 被代理对象。 |
| name | string | 是 | getter函数名。 |

**返回值**

| 类型 | 说明 |
| -------- | -------- |
| Any | 返回getter结果。 |

**示例**

```ts
// 函数定义同上。
let obja = new ClassA();
let p = proxy.Proxy.create(obja, new InterfaceProxyHandler<ClassA>());
console.log(p.length);
```
### set
用于拦截setter操作。
- 必须为class的setter调用，或者interface的Property访问，无法拦截field访问。

**签名**

```ts
set(target: T, name: string, value: Any): boolean
```

**参数**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| target | T | 是 | 被代理对象。 |
| name | string | 是 | setter函数名。 |
| value | Any | 是 | setter函数入参 。|

**返回值**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 返回setter结果。 |

**示例**

```ts
// 函数定义同上。
let obja = new ClassA();
let p = proxy.Proxy.create(obja, new InterfaceProxyHandler<ClassA>());
p.length = 2;
```

## 相比ArkTS1.1的说明
### 接口差异
需先注意，ArkTS1.2的代理类和ArkTS1.1因语言差异，本质为两种完全不同的类，此处用于展示两者的差异性。
| 接口名 | 差异类型 | 原因 |
| -------- | -------- | -------- |
| apply | 删除。 | 使用invoke替代。 |
| construct | 删除。 | 使用invoke替代。 |
| get | 有限制保留。 | 必须为class的getter调用，或者interface的Property访问。 |
| sey | 有限制保留。 | 必须为class的setter调用，或者interface的Property访问。 |
| has | 删除。 | ArkTS1.2将不再支持Reflect.has。 |
| ownKeys | 删除。 | ArkTS1.2将不再支持Reflect.ownKeys。 |
| defineProperty | 删除。 | ArkTS1.2不支持修改对象定义。 |
| deleteProperty | 删除。 | ArkTS1.2不支持修改对象定义。 |
| getOwnPropertyDescriptor | 删除。 | ArkTS1.2中无描述符。 |
| isExtensible | 删除。 | ArkTS1.2中无可拓展对象。 |
| preventExtensions | 删除。 | ArkTS1.2中无可拓展对象。 |
| getPrototypeOf | 删除。 | ArkTS1.2中无Prototype。 |
| setPrototypeOf | 删除。 | ArkTS1.2中无Prototype。 |
