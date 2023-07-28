# arkui子系统状态管理ChangeLog


# ArkUI子系统@Prop装饰器支持Object行为变化

## cl.@Prop支持Object api9浅拷贝，api10变更为深拷贝

**变更影响**
@Prop支持Object在api9为浅拷贝，具体行为表现为：
- Object类型：浅拷贝Object.keys(propObj) 返回的所有属性。即只拷贝最外层的Object，Object中property还是指向原来的父组件的数据源。
- 数组类型：浅拷贝所有的数组项，即只拷贝最外层的array，其他行为和Object一致。
- 拷贝Object和数组的prototype。

@Prop支持Object在api10变更为深拷贝，具体行为表现为：
- Object类型：完全拷贝Object.keys(propObj) 返回的所有属性。
- 数组类型：完全拷贝所有的数组项；
- 拷贝Object和数组的prototype。

**适配指导**
@Prop深浅拷贝的变更在UI渲染上的影响主要在@ObjectLink相关的场景，因为@ObjectLink会代理其修饰对象属性。
例子如下：
api9：PropClassAArray组件中@Prop objArray改变ClassA的属性，或者设置新的数组项，都会引起父组件StateClassAArray创建的ObjectLinkClassA中的@ObjectLink obj的改变。
这个更新是因为父组件StateClassAArray中@State stateClassAArray到子组件PropClassAArray中@Prop objArray是浅拷贝引起的，因为浅拷贝只拷贝了数组项的引用，所以数据源也被改变，而@ObjectLink代理了数据源的属性，所以引发了ObjectLinkClassA组件中的@ObjectLink obj的更新（从StateClassAArray组件中构造的）。

api10：在上述场景中，因为父组件StateClassAArray中@State stateClassAArray到子组件PropClassAArray中@Prop objArray是深拷贝，完整拷贝了ClassA的对象，所以不会改变数据源，从而不会引发ObjectLinkClassA组件中的@ObjectLink obj的更新（从StateClassAArray组件中构造的）。


![zh-cn_image_0000001588291546](figures/zh-cn_image_0000001588291546.png)



```ts
let nextId = 0;

@Observed
class ClassA  {
  id : number;
  a : number;
  constructor(a : number = 0) {
    this.id = nextId++;
    this.a = a;
  }
}

@Component
struct ObjectLinkClassA {
  @ObjectLink obj : ClassA;

  build() {
    Row() {
      Text(`ObjectLink: obj: ${this.obj.a}`)
        .height(100)
        .onClick(() => {
          this.obj.a += 1;
          console.info(`ObjectLink onClick ClassA property changed to  ${this.obj.a}`)
        })
    }.border({width: 3, color: Color.Red})
  }
}

@Component
struct PropClassAArray {
  @Prop objArray : Array<ClassA> = [];

  build() {
    Column() {
      Text(`green box: @Prop : Array<ObjectClassA> item [0] + [1]`)
      Row() {
        ObjectLinkClassA({ obj:  this.objArray[0] })
        Text("[0] Assign new ClassA")
          .height(100)
          .onClick(() => {
            this.objArray[0] = new ClassA();
            console.info(`PropClassAArray[0] onClick ClassA object assign ${this.objArray[0].a}`)
          })
        Text("Change ClassA property")
          .height(100)
          .onClick(() => {
            this.objArray[0].a += 1;
            console.info(`PropClassAArray[1] onClick ClassA property change  ${this.objArray[1].a}`)
          })
      }
    }.border({width: 3, color: Color.Green})
  }
}

@Entry
@Component
struct StateClassAArray {
  @State stateClassAArray : Array<ClassA> = [ new ClassA(), new ClassA() ];

  build() {
    Column() {
      Column() {
        Text("Red box: @ObjectLink from @State array item[0]")
        Row() {
          ObjectLinkClassA({obj : this.stateClassAArray[0] })
          Text("Assign new ClassA")
            .height(100)
            .onClick(() => {
              this.stateClassAArray[0] = new ClassA();
              console.info(`StateClassAArray[0] onClick ClassA object assign ${this.stateClassAArray[0].a}`)
            })
          Text("Change ClassA property")
            .height(100)
            .onClick(() => {
              this.stateClassAArray[0].a += 1;
              console.info(`StateClassAArray onClick stateClassAArray[0] changed to  ${this.stateClassAArray[0].a}`)
            })
        }

      }.border({width: 3, color: Color.Blue})

      Divider().height(5)

      // api9浅拷贝：只拷贝指向源数组项的引用，不拷贝数组项ClassA实例自身
      // api10深拷贝：完整拷贝this.stateClassAArray，包括其数组项。
      PropClassAArray({ objArray: this.stateClassAArray })
    }
  }
}
```