# @observed and @objectLink<a name="EN-US_TOPIC_0000001131671052"></a>

**@observed**  is a decorator used for classes, indicating that the data changes in the object will be managed by the UI page.  **@objectLink**  is used to decorate the variables that are decorated by  **@observed**.

```
// Object to be observed
@Observed class ClassA {
    static nextID : number = 0;
    public id : number;
    public c: number;

    constructor(c: number) {
        this.id = ClassA.nextID++;
        this.c = c;
    }
}

@Observed class ClassB {
    public a: ClassA;

    constructor(a: ClassA) {
        this.a = a;
    }
}
```

```
@Component
struct ViewA {
  @ObjectLink a : ClassA;
  label : string = "ViewA1";
  build() {
     Row() {
        Button(`ViewA [${this.label}] this.a.c=${this.a.c} +1`)
        .onClick(() => {
            this.a.c += 1;
        })
        Button(`ViewA [${this.label}] reset this.a =new ClassA(0)`)
        .onClick(() => {
            this.a = new ClassA(0); // ERROR, this.a is immutable
        })
     }
  }
}

@Entry
@Component 
struct ViewB {
  @State b : ClassB = new ClassB(new ClassA(0));

  build() {
     Column() {
       ViewA({label: "ViewA #1", a: this.b.a})
       ViewA({label: "ViewA #2", a: this.b.a})

       Button(`ViewB: this.b.a = new ClassA(0)`)
        .onClick(() => {
            this.b.a = new ClassA(0);
        })  
        Button(`ViewB: this.b = new ClassB(ClassA(0))`)
        .onClick(() => {
            this.b = new ClassB(new ClassA(0));
        }) 
    }
  } 
}
```

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>**@ObjectLink**  is used to decorate variables and cannot be initialized.  **@Observed**  is used to decorate a class.

