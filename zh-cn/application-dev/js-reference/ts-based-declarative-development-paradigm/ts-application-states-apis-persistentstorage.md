# 持久化数据管理<a name="ZH-CN_TOPIC_0000001175152427"></a>

**PersistentStorage**用于管理应用持久化数据。此对象可以将特定标记的持久化数据链接到AppStorage中，并由AppStorage接口访问对应持久化数据，或者通过@StorageLink修饰器来访问对应key的变量。

## PersistentStorage接口<a name="section959123213514"></a>

<a name="table311mcpsimp"></a>
<table><thead align="left"><tr id="row317mcpsimp"><th class="cellrowborder" valign="top" width="15.02%" id="mcps1.1.5.1.1"><p id="p319mcpsimp"><a name="p319mcpsimp"></a><a name="p319mcpsimp"></a>方法</p>
</th>
<th class="cellrowborder" valign="top" width="23.07%" id="mcps1.1.5.1.2"><p id="p321mcpsimp"><a name="p321mcpsimp"></a><a name="p321mcpsimp"></a>参数说明</p>
</th>
<th class="cellrowborder" valign="top" width="14.63%" id="mcps1.1.5.1.3"><p id="p136621139145019"><a name="p136621139145019"></a><a name="p136621139145019"></a>返回值</p>
</th>
<th class="cellrowborder" valign="top" width="47.28%" id="mcps1.1.5.1.4"><p id="p323mcpsimp"><a name="p323mcpsimp"></a><a name="p323mcpsimp"></a>定义</p>
</th>
</tr>
</thead>
<tbody><tr id="row324mcpsimp"><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.1 "><p id="p326mcpsimp"><a name="p326mcpsimp"></a><a name="p326mcpsimp"></a>PersistProp</p>
</td>
<td class="cellrowborder" valign="top" width="23.07%" headers="mcps1.1.5.1.2 "><p id="p328mcpsimp"><a name="p328mcpsimp"></a><a name="p328mcpsimp"></a>key : string</p>
<p id="p269635419439"><a name="p269635419439"></a><a name="p269635419439"></a>defaultValue: T</p>
</td>
<td class="cellrowborder" valign="top" width="14.63%" headers="mcps1.1.5.1.3 "><p id="p266216399501"><a name="p266216399501"></a><a name="p266216399501"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="47.28%" headers="mcps1.1.5.1.4 "><p id="p115337540440"><a name="p115337540440"></a><a name="p115337540440"></a>关联命名的属性在AppStorage变为持久化数据。赋值覆盖顺序</p>
<p id="p1097811294611"><a name="p1097811294611"></a><a name="p1097811294611"></a>首先 如果此属性在AppStorage中存在，并且将Persistent中的数据复写为AppStorage中的属性值。</p>
<p id="p29609684715"><a name="p29609684715"></a><a name="p29609684715"></a>其次Persistent中有此命名的属性，使用Persistent中的属性值。</p>
<p id="p1738263104810"><a name="p1738263104810"></a><a name="p1738263104810"></a>最后 以上条件不满足使用defaultValue，不支持null和undefined。</p>
</td>
</tr>
<tr id="row331mcpsimp"><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.1 "><p id="p333mcpsimp"><a name="p333mcpsimp"></a><a name="p333mcpsimp"></a>DeleteProp</p>
</td>
<td class="cellrowborder" valign="top" width="23.07%" headers="mcps1.1.5.1.2 "><p id="p335mcpsimp"><a name="p335mcpsimp"></a><a name="p335mcpsimp"></a>key: string</p>
</td>
<td class="cellrowborder" valign="top" width="14.63%" headers="mcps1.1.5.1.3 "><p id="p866233965012"><a name="p866233965012"></a><a name="p866233965012"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="47.28%" headers="mcps1.1.5.1.4 "><p id="p337mcpsimp"><a name="p337mcpsimp"></a><a name="p337mcpsimp"></a>取消双向数据绑定，该属性值将从持久存储中删除。</p>
</td>
</tr>
<tr id="row94321195117"><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.1 "><p id="p651421105116"><a name="p651421105116"></a><a name="p651421105116"></a>PersistProps</p>
</td>
<td class="cellrowborder" valign="top" width="23.07%" headers="mcps1.1.5.1.2 "><p id="p69911746282"><a name="p69911746282"></a><a name="p69911746282"></a>keys: {</p>
<p id="p52741115112813"><a name="p52741115112813"></a><a name="p52741115112813"></a>key: string,</p>
<p id="p1414372092813"><a name="p1414372092813"></a><a name="p1414372092813"></a>defaultValue: any</p>
<p id="p11542175114"><a name="p11542175114"></a><a name="p11542175114"></a>}[]</p>
</td>
<td class="cellrowborder" valign="top" width="14.63%" headers="mcps1.1.5.1.3 "><p id="p1451721115111"><a name="p1451721115111"></a><a name="p1451721115111"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="47.28%" headers="mcps1.1.5.1.4 "><p id="p8512119518"><a name="p8512119518"></a><a name="p8512119518"></a>关联多个命名的属性绑定。</p>
</td>
</tr>
<tr id="row338mcpsimp"><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.1 "><p id="p340mcpsimp"><a name="p340mcpsimp"></a><a name="p340mcpsimp"></a>Keys</p>
</td>
<td class="cellrowborder" valign="top" width="23.07%" headers="mcps1.1.5.1.2 "><p id="p342mcpsimp"><a name="p342mcpsimp"></a><a name="p342mcpsimp"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="14.63%" headers="mcps1.1.5.1.3 "><p id="p16662163915015"><a name="p16662163915015"></a><a name="p16662163915015"></a>Array&lt;string&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="47.28%" headers="mcps1.1.5.1.4 "><p id="p344mcpsimp"><a name="p344mcpsimp"></a><a name="p344mcpsimp"></a>返回所有持久化属性的标记。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   PersistProp接口使用时，需要保证输入对应的key应当在Appstorage存在。
>-   DeleteProp接口使用时，只能对本次启动已经link过的数据生效。

```
PersistentStorage.PersistProp("highScore", "0");

@Entry
@Component
struct PersistentComponent {
    @StorageLink('highScore') highScore: string = '0'
    @State currentScore: number = 0
    build() {
        Column() {
            if (this.currentScore === Number(this.highScore)) {
                Text(`new highScore : ${this.highScore}`)
            }
            Button() {
                Text(`goal!, currentScore : ${this.currentScore}`)
                    .fontSize(10)
            }.onClick(() => {
                this.currentScore++
                if (this.currentScore > Number(this.highScore)) {
                    this.highScore = this.currentScore.toString()
                }
            })
        }
    }
}
```

