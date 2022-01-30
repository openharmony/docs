# 自定义组件成员变量初始化<a name="ZH-CN_TOPIC_0000001110948904"></a>

组件的成员变量可以通过两种方式初始化：

-   本地初始化，例如：

    ```
    @State counter: Counter = new Counter()
    ```

-   在构造组件时通过构造参数初始化，例如：

    ```
    MyComponent(counter: $myCounter)
    ```


具体允许哪种方式取决于状态变量的装饰器：

<a name="table1130mcpsimp"></a>
<table><thead align="left"><tr id="row1136mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.4.1.1"><p id="p1138mcpsimp"><a name="p1138mcpsimp"></a><a name="p1138mcpsimp"></a>装饰器类型</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.4.1.2"><p id="p1140mcpsimp"><a name="p1140mcpsimp"></a><a name="p1140mcpsimp"></a>本地初始化</p>
</th>
<th class="cellrowborder" valign="top" width="53%" id="mcps1.1.4.1.3"><p id="p1142mcpsimp"><a name="p1142mcpsimp"></a><a name="p1142mcpsimp"></a>通过构造函数参数初始化</p>
</th>
</tr>
</thead>
<tbody><tr id="row1143mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.4.1.1 "><p id="p1145mcpsimp"><a name="p1145mcpsimp"></a><a name="p1145mcpsimp"></a>@State</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.4.1.2 "><p id="p1147mcpsimp"><a name="p1147mcpsimp"></a><a name="p1147mcpsimp"></a>必须</p>
</td>
<td class="cellrowborder" valign="top" width="53%" headers="mcps1.1.4.1.3 "><p id="p1149mcpsimp"><a name="p1149mcpsimp"></a><a name="p1149mcpsimp"></a>可选</p>
</td>
</tr>
<tr id="row1150mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.4.1.1 "><p id="p1152mcpsimp"><a name="p1152mcpsimp"></a><a name="p1152mcpsimp"></a>@Prop</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.4.1.2 "><p id="p1154mcpsimp"><a name="p1154mcpsimp"></a><a name="p1154mcpsimp"></a>禁止</p>
</td>
<td class="cellrowborder" valign="top" width="53%" headers="mcps1.1.4.1.3 "><p id="p1156mcpsimp"><a name="p1156mcpsimp"></a><a name="p1156mcpsimp"></a>必须</p>
</td>
</tr>
<tr id="row1157mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.4.1.1 "><p id="p1159mcpsimp"><a name="p1159mcpsimp"></a><a name="p1159mcpsimp"></a>@Link</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.4.1.2 "><p id="p1161mcpsimp"><a name="p1161mcpsimp"></a><a name="p1161mcpsimp"></a>禁止</p>
</td>
<td class="cellrowborder" valign="top" width="53%" headers="mcps1.1.4.1.3 "><p id="p1163mcpsimp"><a name="p1163mcpsimp"></a><a name="p1163mcpsimp"></a>必须</p>
</td>
</tr>
<tr id="row1368143713213"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.4.1.1 "><p id="p668183713214"><a name="p668183713214"></a><a name="p668183713214"></a>@StorageLink</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.4.1.2 "><p id="p13685378329"><a name="p13685378329"></a><a name="p13685378329"></a>必须</p>
</td>
<td class="cellrowborder" valign="top" width="53%" headers="mcps1.1.4.1.3 "><p id="p4681437173219"><a name="p4681437173219"></a><a name="p4681437173219"></a>禁止</p>
</td>
</tr>
<tr id="row147015402328"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.4.1.1 "><p id="p8471134011327"><a name="p8471134011327"></a><a name="p8471134011327"></a>@StorageProp</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.4.1.2 "><p id="p164711040143213"><a name="p164711040143213"></a><a name="p164711040143213"></a>必须</p>
</td>
<td class="cellrowborder" valign="top" width="53%" headers="mcps1.1.4.1.3 "><p id="p11471740133216"><a name="p11471740133216"></a><a name="p11471740133216"></a>禁止</p>
</td>
</tr>
<tr id="row134917432323"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.4.1.1 "><p id="p8349843183215"><a name="p8349843183215"></a><a name="p8349843183215"></a>@Provide</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.4.1.2 "><p id="p4349114315324"><a name="p4349114315324"></a><a name="p4349114315324"></a>必须</p>
</td>
<td class="cellrowborder" valign="top" width="53%" headers="mcps1.1.4.1.3 "><p id="p19349743143218"><a name="p19349743143218"></a><a name="p19349743143218"></a>可选</p>
</td>
</tr>
<tr id="row121451446173219"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.4.1.1 "><p id="p141451046113211"><a name="p141451046113211"></a><a name="p141451046113211"></a>@Consume</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.4.1.2 "><p id="p1514564683212"><a name="p1514564683212"></a><a name="p1514564683212"></a>禁止</p>
</td>
<td class="cellrowborder" valign="top" width="53%" headers="mcps1.1.4.1.3 "><p id="p1145346183214"><a name="p1145346183214"></a><a name="p1145346183214"></a>禁止</p>
</td>
</tr>
<tr id="row1489554183914"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.4.1.1 "><p id="p1789513415395"><a name="p1789513415395"></a><a name="p1789513415395"></a>@ObjectLink</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.4.1.2 "><p id="p489594133916"><a name="p489594133916"></a><a name="p489594133916"></a>禁止</p>
</td>
<td class="cellrowborder" valign="top" width="53%" headers="mcps1.1.4.1.3 "><p id="p1389504123918"><a name="p1389504123918"></a><a name="p1389504123918"></a>必须</p>
</td>
</tr>
<tr id="row1164mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.4.1.1 "><p id="p1166mcpsimp"><a name="p1166mcpsimp"></a><a name="p1166mcpsimp"></a>常规成员变量</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.4.1.2 "><p id="p1168mcpsimp"><a name="p1168mcpsimp"></a><a name="p1168mcpsimp"></a>推荐</p>
</td>
<td class="cellrowborder" valign="top" width="53%" headers="mcps1.1.4.1.3 "><p id="p1170mcpsimp"><a name="p1170mcpsimp"></a><a name="p1170mcpsimp"></a>可选</p>
</td>
</tr>
</tbody>
</table>

从上表中可以看出：

-   **@State**变量需要本地初始化，初始化的值可以被构造参数覆盖；
-   **@Prop**和**@Link**变量必须且仅通过构造函数参数进行初始化。

通过构造函数方法初始化成员变量，需要遵循如下规则：

<a name="table1176mcpsimp"></a>
<table><thead align="left"><tr id="row1184mcpsimp"><th class="cellrowborder" valign="top" width="38.33383338333833%" id="mcps1.1.6.1.1"><p id="p1186mcpsimp"><a name="p1186mcpsimp"></a><a name="p1186mcpsimp"></a>从父组件中的变量（下）到子组件中的变量（右）</p>
</th>
<th class="cellrowborder" valign="top" width="13.35133513351335%" id="mcps1.1.6.1.2"><p id="p1188mcpsimp"><a name="p1188mcpsimp"></a><a name="p1188mcpsimp"></a>@State</p>
</th>
<th class="cellrowborder" valign="top" width="12.701270127012702%" id="mcps1.1.6.1.3"><p id="p1190mcpsimp"><a name="p1190mcpsimp"></a><a name="p1190mcpsimp"></a>@Link</p>
</th>
<th class="cellrowborder" valign="top" width="14.281428142814281%" id="mcps1.1.6.1.4"><p id="p1192mcpsimp"><a name="p1192mcpsimp"></a><a name="p1192mcpsimp"></a>@Prop</p>
</th>
<th class="cellrowborder" valign="top" width="21.33213321332133%" id="mcps1.1.6.1.5"><p id="p1194mcpsimp"><a name="p1194mcpsimp"></a><a name="p1194mcpsimp"></a>常规变量</p>
</th>
</tr>
</thead>
<tbody><tr id="row1195mcpsimp"><td class="cellrowborder" valign="top" width="38.33383338333833%" headers="mcps1.1.6.1.1 "><p id="p1197mcpsimp"><a name="p1197mcpsimp"></a><a name="p1197mcpsimp"></a>@State</p>
</td>
<td class="cellrowborder" valign="top" width="13.35133513351335%" headers="mcps1.1.6.1.2 "><p id="p1199mcpsimp"><a name="p1199mcpsimp"></a><a name="p1199mcpsimp"></a>不允许</p>
</td>
<td class="cellrowborder" valign="top" width="12.701270127012702%" headers="mcps1.1.6.1.3 "><p id="p1201mcpsimp"><a name="p1201mcpsimp"></a><a name="p1201mcpsimp"></a>允许</p>
</td>
<td class="cellrowborder" valign="top" width="14.281428142814281%" headers="mcps1.1.6.1.4 "><p id="p1203mcpsimp"><a name="p1203mcpsimp"></a><a name="p1203mcpsimp"></a>允许</p>
</td>
<td class="cellrowborder" valign="top" width="21.33213321332133%" headers="mcps1.1.6.1.5 "><p id="p1205mcpsimp"><a name="p1205mcpsimp"></a><a name="p1205mcpsimp"></a>允许</p>
</td>
</tr>
<tr id="row1206mcpsimp"><td class="cellrowborder" valign="top" width="38.33383338333833%" headers="mcps1.1.6.1.1 "><p id="p1208mcpsimp"><a name="p1208mcpsimp"></a><a name="p1208mcpsimp"></a>@Link</p>
</td>
<td class="cellrowborder" valign="top" width="13.35133513351335%" headers="mcps1.1.6.1.2 "><p id="p1210mcpsimp"><a name="p1210mcpsimp"></a><a name="p1210mcpsimp"></a>不允许</p>
</td>
<td class="cellrowborder" valign="top" width="12.701270127012702%" headers="mcps1.1.6.1.3 "><p id="p1212mcpsimp"><a name="p1212mcpsimp"></a><a name="p1212mcpsimp"></a>允许</p>
</td>
<td class="cellrowborder" valign="top" width="14.281428142814281%" headers="mcps1.1.6.1.4 "><p id="p1214mcpsimp"><a name="p1214mcpsimp"></a><a name="p1214mcpsimp"></a>不推荐</p>
</td>
<td class="cellrowborder" valign="top" width="21.33213321332133%" headers="mcps1.1.6.1.5 "><p id="p1216mcpsimp"><a name="p1216mcpsimp"></a><a name="p1216mcpsimp"></a>允许</p>
</td>
</tr>
<tr id="row1217mcpsimp"><td class="cellrowborder" valign="top" width="38.33383338333833%" headers="mcps1.1.6.1.1 "><p id="p1219mcpsimp"><a name="p1219mcpsimp"></a><a name="p1219mcpsimp"></a>@Prop</p>
</td>
<td class="cellrowborder" valign="top" width="13.35133513351335%" headers="mcps1.1.6.1.2 "><p id="p1221mcpsimp"><a name="p1221mcpsimp"></a><a name="p1221mcpsimp"></a>不允许</p>
</td>
<td class="cellrowborder" valign="top" width="12.701270127012702%" headers="mcps1.1.6.1.3 "><p id="p1223mcpsimp"><a name="p1223mcpsimp"></a><a name="p1223mcpsimp"></a>不允许</p>
</td>
<td class="cellrowborder" valign="top" width="14.281428142814281%" headers="mcps1.1.6.1.4 "><p id="p1225mcpsimp"><a name="p1225mcpsimp"></a><a name="p1225mcpsimp"></a>允许</p>
</td>
<td class="cellrowborder" valign="top" width="21.33213321332133%" headers="mcps1.1.6.1.5 "><p id="p1227mcpsimp"><a name="p1227mcpsimp"></a><a name="p1227mcpsimp"></a>允许</p>
</td>
</tr>
<tr id="row240501152412"><td class="cellrowborder" valign="top" width="38.33383338333833%" headers="mcps1.1.6.1.1 "><p id="p54063122418"><a name="p54063122418"></a><a name="p54063122418"></a>@StorageLink</p>
</td>
<td class="cellrowborder" valign="top" width="13.35133513351335%" headers="mcps1.1.6.1.2 "><p id="p8406161132415"><a name="p8406161132415"></a><a name="p8406161132415"></a>不允许</p>
</td>
<td class="cellrowborder" valign="top" width="12.701270127012702%" headers="mcps1.1.6.1.3 "><p id="p440651122418"><a name="p440651122418"></a><a name="p440651122418"></a>允许</p>
</td>
<td class="cellrowborder" valign="top" width="14.281428142814281%" headers="mcps1.1.6.1.4 "><p id="p13406111162416"><a name="p13406111162416"></a><a name="p13406111162416"></a>不允许</p>
</td>
<td class="cellrowborder" valign="top" width="21.33213321332133%" headers="mcps1.1.6.1.5 "><p id="p124067118242"><a name="p124067118242"></a><a name="p124067118242"></a>允许</p>
</td>
</tr>
<tr id="row88861156245"><td class="cellrowborder" valign="top" width="38.33383338333833%" headers="mcps1.1.6.1.1 "><p id="p98861853246"><a name="p98861853246"></a><a name="p98861853246"></a>@StorageProp</p>
</td>
<td class="cellrowborder" valign="top" width="13.35133513351335%" headers="mcps1.1.6.1.2 "><p id="p588635122419"><a name="p588635122419"></a><a name="p588635122419"></a>不允许</p>
</td>
<td class="cellrowborder" valign="top" width="12.701270127012702%" headers="mcps1.1.6.1.3 "><p id="p18886353244"><a name="p18886353244"></a><a name="p18886353244"></a>不允许</p>
</td>
<td class="cellrowborder" valign="top" width="14.281428142814281%" headers="mcps1.1.6.1.4 "><p id="p15887557248"><a name="p15887557248"></a><a name="p15887557248"></a>不允许</p>
</td>
<td class="cellrowborder" valign="top" width="21.33213321332133%" headers="mcps1.1.6.1.5 "><p id="p5887185182418"><a name="p5887185182418"></a><a name="p5887185182418"></a>允许</p>
</td>
</tr>
<tr id="row1228mcpsimp"><td class="cellrowborder" valign="top" width="38.33383338333833%" headers="mcps1.1.6.1.1 "><p id="p1230mcpsimp"><a name="p1230mcpsimp"></a><a name="p1230mcpsimp"></a>常规变量</p>
</td>
<td class="cellrowborder" valign="top" width="13.35133513351335%" headers="mcps1.1.6.1.2 "><p id="p1232mcpsimp"><a name="p1232mcpsimp"></a><a name="p1232mcpsimp"></a>允许</p>
</td>
<td class="cellrowborder" valign="top" width="12.701270127012702%" headers="mcps1.1.6.1.3 "><p id="p1234mcpsimp"><a name="p1234mcpsimp"></a><a name="p1234mcpsimp"></a>不允许</p>
</td>
<td class="cellrowborder" valign="top" width="14.281428142814281%" headers="mcps1.1.6.1.4 "><p id="p1236mcpsimp"><a name="p1236mcpsimp"></a><a name="p1236mcpsimp"></a>不允许</p>
</td>
<td class="cellrowborder" valign="top" width="21.33213321332133%" headers="mcps1.1.6.1.5 "><p id="p1238mcpsimp"><a name="p1238mcpsimp"></a><a name="p1238mcpsimp"></a>允许</p>
</td>
</tr>
</tbody>
</table>

从上表中可以看出：

-   父组件的常规变量可以用于初始化子组件的**@State**变量，但不能用于初始化**@Link**或**@Prop**变量；
-   父组件的**@State**变量可以初始化子组件的**@Prop**、**@Link（通过$）**或常规变量，但不能初始化子组件的**@State**变量；
-   父组件的**@Link**变量可以初始化子组件的@Link或常规变量。但是初始化子组件的**@State**成员是语法错误，此外不建议初始化**@prop；**
-   父组件的**@Prop**变量可以初始化子组件的常规变量或**@Prop**变量，但不能初始化子组件的**@State**或**@Link**变量。
-   @StorageLink和@StorageProp不允许由父组件中传递到子组件。
-   除了上述规则外，还需要遵循TS的强类型规则。

## 示例<a name="section1184926392"></a>

```
@Entry
@Component
struct Parent {
    @State parentState: ClassA = new ClassA()
    build() {
        Row() {
            CompA({aState: new ClassA, aLink: $parentState}) // valid
            CompA({aLink: $parentState})   // valid
            CompA()                 // invalid, @Link aLink remains uninitialized
            CompA({aLink: new ClassA}) // invalid, @Link aLink must be a reference ($) to either @State or @Link variable
        }
    }
}

@Component
struct CompA {
    @State aState: boolean = false   // must initialize locally
    @Link aLink: ClassA              // must not initialize locally

    build() {
        Row() {
            CompB({bLink: $aLink,         // valid init a @Link with reference of another @Link,
                bProp: this.aState})    // valid init a @Prop with value of a @State
            CompB({aLink: $aState,  // invalid: type missmatch expected ref to ClassA, provided reference to boolean
                bProp: false})           // valid init a @Prop by constants value
        }
    }
}

@Component
struct CompB {
    @Link bLink: ClassA = new ClassA()       // invalid, must not initialize locally
    @Prop bProp: boolean = false      // invalid must not initialize locally

    build() {
        ...
    }
}
```

