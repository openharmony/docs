# 渲染控制优秀实践


为了帮助应用程序开发人员提高其应用程序质量，本章节面向开发者提供了多个在开发ArkUI应用中常见场景和易错问题，并给出了对应的解决方案。此外，还提供了同一场景下，推荐用法和不推荐用法的对比和解释说明，更直观地展示两者区别，从而帮助开发者学习如果正确地在应用开发中使用渲染控制，进行高性能开发。


## 在ForEach数据源中添加元素

在ForEach数据源中添加元素导致数组项ID重复。


### 不推荐用法

  下面示例使用ForEach方法迭代数组this.arr的每个元素，在Text组件进行显示，并在单击Text('Add arr element')时添加新的数组元素。
  
```ts
@Entry
@Component
struct Index {
  @State arr: number[] = [1,2,3];

  build() {
      Column() {
       ForEach(this.arr,
         (item: void) => {
           Text(`Item ${item}`)
         },
         (item: string) => item.toString())
       Text('Add arr element')
         .fontSize(20)
         .onClick(()=>{
           this.arr.push(4);  // arr新增的元素，其在ForEach内的键值均为'4'
           console.log("Arr elements: ", this.arr);
         })
      }
    }
}
```

点击两次Text（'Add arr element'）时，数组this.arr每次都会添加新元素 4。但是在ForEach循环渲染中，第三个参数(item)=&gt; item.toString()需要生成Array每一个item对应的id值。该Array Id被要求是唯一的和稳定的。

- 唯一性：键值生成函数生成的每个数组项的id是不同的。

- 稳定性：当数组项ID发生变化时，ArkUI框架认为该数组项被替换或更改。

- ArkUI框架会对重复的ID告警，这种情况下框架的行为是未知的，特别是UI的更新在该场景下可能不起作用。

因此上述示例中，框架不会显示第二次及以后新添加的文本元素。因为这个元素不再是唯一的，他们都含有相同的id4。 但是如果删除ForEach第三个键值生成函数(item) =&gt; item.toString()，则触发onClick事件后每一个新添加的Text元素都会得到更新。这是因为框架使用了默认的Array id生成函数，即(item: any, index : number) =&gt; '${index}__${JSON.stringify(item)}'。它的兼容性更好但可能会导致不必要的UI更新，因此仍建议应用定义自己的键值生成函数。


## ForEach数据源更新

ForEach数据源更新时，数组项ID与原数组项ID重复不会重新创建该数组项。


### 不推荐用法

下面的示例定义了Index和Child两个组件。父组件Index有arr数组成员变量，初始值包含数字1、2、3。Child定义\@Prop value，接收父组件中arr数组中的一个元素。

  
```ts
@Component
struct Child {
  @Prop value: number = 0;
  build() {
    Text(`${this.value}`)
      .fontSize(50)
      .onClick(() => {
        this.value++  // 点击改变@Prop的值
      })
  }
}
@Entry
@Component
struct Index {
  @State arr: number[] = [1, 2, 3];
  build() {
    Row() {
      Column() {
        // 对照组
        Child({ value: this.arr[0] })
        Child({ value: this.arr[1] })
        Child({ value: this.arr[2] })
        Divider().height(5)
        ForEach(this.arr,
          (item: number) => {
            Child({ value: item })
          },
          (item: string) => item.toString()  // 键值，标识id
        )
        Text('Parent: replace entire arr')
          .fontSize(50)
          .onClick(() => {
            // 两个数组项内均含有'3'，ForEach内的id没有发生变化
            // 意味着ForEach不会更新该Child实例，@Prop也不会在父组件处被更新
            this.arr = (this.arr[0] == 1) ? [3, 4, 5] : [1, 2, 3];
          })
      }
    }
  }
}
```

当触发文本组件Parent: replace entire arr的onClick事件时，状态变量数组arr根据自身第一个元素的值将被[3, 4, 5]或[1, 2, 3]替换，但是ForEach里初始被创建的\@Prop传入值为3的Child组件并不会更新。

因为，老数组和新数组初始均含有同一个值的元素（数字3），而且该元素生成的标识id在父组件里没有变化。因此ForEach没有识别出对应的Child实例需要被新的输入值更新，对应的子组件内\@Prop也没有更新。

![zh-cn_image_0000001604900446](figures/zh-cn_image_0000001604900446.png)

可以在arr中用一个唯一的元素代替重复的元素3来观察本事件的行为表现。当恰当的替换掉数组时，接下来应用的表现才是符合预期的。