# Migration for Data Object State Variables

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=5cbda8a742fe4c75db3800c28ccfc8ffcd9cebc0 translatedAt=2026-06-30T03:37:54.432Z pushedAt=2026-06-30T04:41:52.257Z -->

This document explains how to migrate data object state variables from V1 to V2.

| V1 Decorator               | V2 Decorator                 |
|------------------------|--------------------------|
|[\@ObjectLink](./arkts-observed-and-objectlink.md)/[\@Observed](./arkts-observed-and-objectlink.md) /[\@Track](./arkts-track.md)|[\@ObservedV2](./arkts-new-observedV2-and-trace.md)/[\@Trace](./arkts-new-observedV2-and-trace.md)|

## Migration Examples

### \@ObjectLink/\@Observed/\@Track -> \@ObservedV2/\@Trace

**Migration Rules**

In V1, \@Observed and \@ObjectLink enable observation of objects and their first-level properties. Observing nested properties requires wrapping them in custom components with \@ObjectLink. \@Track provides property-level change tracking for precise updates.

In V2, \@ObservedV2 and \@Trace simplify the observation model. Observation capabilities are embedded directly into class objects and their nested properties. \@Trace combines observation with precise update control, replacing the functionality of \@Track. Key improvements are as follows:

- Nested object observation: \@ObservedV2 and \@Trace enable direct observation of nested properties without wrapper components.

- Precise updates: \@Trace ensures efficient UI updates at the property level.

**Example**

**Observing Nested Object Properties**

In V1, changes to nested object properties are not directly observable; only top-level property changes can be detected. Observation of nested object properties require a custom component with \@ObjectLink. V2 introduces \@ObservedV2 and \@Trace to enable direct observation of nested properties, significantly reducing complexity.

V1:

<!-- @[Migration_Nested_Object_Properties_V1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/migrationDataObjectVariables/MigrationNestedObjectPropertiesV1.ets) -->

``` TypeScript
@Observed
class Address {
  public city: string;

  constructor(city: string) {
    this.city = city;
  }
}

@Observed
class User {
  public name: string;
  public address: Address;

  constructor(name: string, address: Address) {
    this.name = name;
    this.address = address;
  }
}

@Component
struct AddressView {
  // The @ObjectLink decorated address in the child component is initialized from the parent component and receives the @Observed decorated address instance.
  @ObjectLink address: Address;

  build() {
    Column() {
      Text(`City: ${this.address.city}`)
      Button('city +a')
        .onClick(() => {
          this.address.city += 'a';
        })
    }
  }
}

@Entry
@Component
struct UserProfile {
  @State user: User = new User('Alice', new Address('New York'));

  build() {
    Column() {
      Text(`Name: ${this.user.name}`)
      // Changes to nested object properties, such as this.user.address.city, cannot be observed directly.
      // Only top-level object property changes are observable. Therefore, the nested Address object must be extracted into the custom AddressView component.
      AddressView({ address: this.user.address })
    }
  }
}
```

V2 migration policy: Use \@ObservedV2 and \@Trace.

<!-- @[Migration_Nested_Object_Properties_V2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/migrationDataObjectVariables/MigrationNestedObjectPropertiesV2.ets) -->

``` TypeScript
@ObservedV2
class Address {
  @Trace public city: string;

  constructor(city: string) {
    this.city = city;
  }
}

@ObservedV2
class User {
  @Trace public name: string;
  @Trace public address: Address;

  constructor(name: string, address: Address) {
    this.name = name;
    this.address = address;
  }
}

@Entry
@ComponentV2
struct UserProfile {
  @Local user: User = new User('Alice', new Address('New York'));

  build() {
    Column() {
      Text(`Name: ${this.user.name}`)
      // Use @ObservedV2 and @Trace to directly observe nested object properties.
      Text(`City: ${this.user.address.city}`)
      Button('city +a')
        .onClick(() => {
          this.user.address.city += 'a';
        })
    }
  }
}
```

**Observing Class Properties**

In V1, \@Observed decorates a class to enable observation at the object level, while @Track is used for specific property-level observation within that class. V2 simplifies this model: \@Trace handles property-level observation, and \@ObservedV2 is optimized for efficient UI updates at the object level.

V1:

<!-- @[Migration_Class_Attribute_V1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/migrationDataObjectVariables/MigrationClassAttributeV1.ets) --> 

``` TypeScript
@Observed
class User {
  @Track public name: string;
  @Track public age: number;

  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }
}

@Entry
@Component
struct UserProfile {
  @State user: User = new User('Alice', 30);

  build() {
    Column() {
      Text(`Name: ${this.user.name}`)
      Text(`Age: ${this.user.age}`)
      // Tap the Button to update user.age, triggering a UI refresh.
      Button('increase age')
        .onClick(() => {
          this.user.age++;
        })
    }
  }
}
```

V2 migration policy: Use \@ObservedV2 and \@Trace.

<!-- @[Migration_Class_Attribute_V2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ParadigmStateManagement/entry/src/main/ets/pages/migrationDataObjectVariables/MigrationClassAttributeV2.ets) --> 

``` TypeScript
// V2 uses @ObservedV2 to replace V1's @Observed.
@ObservedV2
class User {
  // V2 uses @Trace to replace V1's @Track.
  @Trace public name: string;
  @Trace public age: number;

  constructor(name: string, age: number) {
    this.name = name;
    this.age = age;
  }
}

@Entry
@ComponentV2
struct UserProfile {
  @Local user: User = new User('Alice', 30);

  build() {
    Column() {
      Text(`Name: ${this.user.name}`)
      Text(`Age: ${this.user.age}`)
      Button('Increase age')
        .onClick(() => {
          this.user.age++;
        })
    }
  }
}
```