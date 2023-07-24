#  ArkUI Subsystem Changelog

### Restrictions on Using Decorators

#### 1. Restrictions on Using Component Decorators

Component decorators @Component, @Entry, @Preview, and @CustomDialog apply only to structs, not classes.

**Example**

```
@Component
  // ERROR:The '@Component' decorator can only be used with 'struct'.
class Index {
  build() {
  }
}
```

**Change Impact**

If @Component, @Entry, @Preview, or @CustomDialog is used to decorate components other than structs, a compile time error will occur.

**Key API/Component Changes**

N/A

**Adaptation Guide**

Use @Component, @Entry, @Preview, and @CustomDialog to decorate only structs.

#### 2. Restrictions on Using Component Member Variable Decorators

Component member variable decorators @State, @Prop, @Link, @Provide, @Consume, @ObjectLink, @StorageLink, @StorageProp, @LocalStorageLink, @LocalStorageProp, @Watch, and @BuilderParam can decorate only the member variables of structs.

**Example**

```
@Component
class Index {
  // ERROR: The '@State' decorator can only be used with 'struct'.
  @State message: string = 'Hello world'

  build() {

  }
}
```

**Change Impact**

If any of the aforementioned component member variable decorators is used to decorate a member variable of components other than structs, a compile time error will occur.

**Key API/Component Changes**

N/A

**Adaptation Guide**

Use the aforementioned component member variable decorators to decorate only the member variables of structs.
