#  arkui子系统ChangeLog

### UI范式装饰器使用限制

#### 1.组件装饰器使用限制

组件装饰器@Component、@Entry、 @Preview和@CustomDialog 不允许装饰除了struct组件之外其他组件。

**示例：**

```
@Component
  // ERROR:The '@Component' decorator can only be used with 'struct'.
class Index {
  build() {
  }
}
```

**变更影响**

如果组件装饰器@Component、@Entry、 @Preview和@CustomDialog 没有装饰struct组件，编译报错。

**关键的接口/组件变更**

不涉及。

**适配指导**

组件装饰器@Component、@Entry、 @Preview和@CustomDialog修饰的其他的组件变成修饰struct组件。

#### 2.组件成员变量装饰器使用限制

组件成员变量装饰器@State、@Prop、@Link、@Provide、@Consume、@ObjectLink、@StorageLink、@StorageProp、@LocalStorageLink、@LocalStorageProp、@Watch、@BuilderParam只能装饰struct组件的成员变量。

**示例：**

```
@Component
class Index {
  // ERROR: The '@State' decorator can only be used with 'struct'.
  @State message: string = 'Hello world'

  build() {

  }
}
```

**变更影响**

如果上述提到的组件成员变量装饰器没有装饰struct组件的成员变量，编译报错。

**关键的接口/组件变更**

不涉及

**适配指导**

组件成员变量装饰器如果装饰了非struct组件成员变量，请将装饰组件成员变量组件变成'struct'组件。