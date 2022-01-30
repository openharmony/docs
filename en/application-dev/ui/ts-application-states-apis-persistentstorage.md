# PersistentStorage<a name="EN-US_TOPIC_0000001175152427"></a>

**PersistentStorage**  is used to manage persistent data of applications. This object can link the persistent data of a specific flag to the  **AppStorage**  and access the persistent data through the  **AppStorage**  APIs or access the variable of the corresponding key through the  **@StorageLink**  decorator.

## PersistentStorage APIs<a name="section959123213514"></a>

<a name="table311mcpsimp"></a>
<table><thead align="left"><tr id="row317mcpsimp"><th class="cellrowborder" valign="top" width="15.02%" id="mcps1.1.5.1.1"><p id="p319mcpsimp"><a name="p319mcpsimp"></a><a name="p319mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="11.540000000000001%" id="mcps1.1.5.1.2"><p id="p321mcpsimp"><a name="p321mcpsimp"></a><a name="p321mcpsimp"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.5%" id="mcps1.1.5.1.3"><p id="p136621139145019"><a name="p136621139145019"></a><a name="p136621139145019"></a>Return Value</p>
</th>
<th class="cellrowborder" valign="top" width="63.94%" id="mcps1.1.5.1.4"><p id="p323mcpsimp"><a name="p323mcpsimp"></a><a name="p323mcpsimp"></a>Definition</p>
</th>
</tr>
</thead>
<tbody><tr id="row324mcpsimp"><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.1 "><p id="p326mcpsimp"><a name="p326mcpsimp"></a><a name="p326mcpsimp"></a>PersistProp</p>
</td>
<td class="cellrowborder" valign="top" width="11.540000000000001%" headers="mcps1.1.5.1.2 "><p id="p328mcpsimp"><a name="p328mcpsimp"></a><a name="p328mcpsimp"></a>key : string</p>
<p id="p269635419439"><a name="p269635419439"></a><a name="p269635419439"></a>defaultValue: T</p>
</td>
<td class="cellrowborder" valign="top" width="9.5%" headers="mcps1.1.5.1.3 "><p id="p266216399501"><a name="p266216399501"></a><a name="p266216399501"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="63.94%" headers="mcps1.1.5.1.4 "><p id="p115337540440"><a name="p115337540440"></a><a name="p115337540440"></a>Changes associated named attribute to persistent data in the <strong id="b798274517339"><a name="b798274517339"></a><a name="b798274517339"></a>AppStorage</strong>. Value overwriting sequence:</p>
<p id="p1097811294611"><a name="p1097811294611"></a><a name="p1097811294611"></a>If the attribute exists in the <strong id="b15266175917330"><a name="b15266175917330"></a><a name="b15266175917330"></a>AppStorage</strong>, overwrite its value with the attribute value in <strong id="b344612783413"><a name="b344612783413"></a><a name="b344612783413"></a>Persistent</strong>.</p>
<p id="p29609684715"><a name="p29609684715"></a><a name="p29609684715"></a>If <strong id="b12915121853416"><a name="b12915121853416"></a><a name="b12915121853416"></a>Persistent</strong> contains the specified attribute, use the attribute value in <strong id="b1578284213414"><a name="b1578284213414"></a><a name="b1578284213414"></a>Persistent</strong>.</p>
<p id="p1738263104810"><a name="p1738263104810"></a><a name="p1738263104810"></a>If the preceding conditions are not met, use <strong id="b6526155416348"><a name="b6526155416348"></a><a name="b6526155416348"></a>defaultValue</strong>. The <strong id="b993917517358"><a name="b993917517358"></a><a name="b993917517358"></a>null</strong> and <strong id="b252811983513"><a name="b252811983513"></a><a name="b252811983513"></a>undefined</strong> values are not supported.</p>
</td>
</tr>
<tr id="row331mcpsimp"><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.1 "><p id="p333mcpsimp"><a name="p333mcpsimp"></a><a name="p333mcpsimp"></a>DeleteProp</p>
</td>
<td class="cellrowborder" valign="top" width="11.540000000000001%" headers="mcps1.1.5.1.2 "><p id="p335mcpsimp"><a name="p335mcpsimp"></a><a name="p335mcpsimp"></a>key: string</p>
</td>
<td class="cellrowborder" valign="top" width="9.5%" headers="mcps1.1.5.1.3 "><p id="p866233965012"><a name="p866233965012"></a><a name="p866233965012"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="63.94%" headers="mcps1.1.5.1.4 "><p id="p337mcpsimp"><a name="p337mcpsimp"></a><a name="p337mcpsimp"></a>Cancels two-way binding. The value of this attribute will be deleted from the persistent storage.</p>
</td>
</tr>
<tr id="row94321195117"><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.1 "><p id="p651421105116"><a name="p651421105116"></a><a name="p651421105116"></a>PersistProps</p>
</td>
<td class="cellrowborder" valign="top" width="11.540000000000001%" headers="mcps1.1.5.1.2 "><p id="p69911746282"><a name="p69911746282"></a><a name="p69911746282"></a>keys: {</p>
<p id="p52741115112813"><a name="p52741115112813"></a><a name="p52741115112813"></a>key: string,</p>
<p id="p1414372092813"><a name="p1414372092813"></a><a name="p1414372092813"></a>defaultValue: any</p>
<p id="p11542175114"><a name="p11542175114"></a><a name="p11542175114"></a>}[]</p>
</td>
<td class="cellrowborder" valign="top" width="9.5%" headers="mcps1.1.5.1.3 "><p id="p1451721115111"><a name="p1451721115111"></a><a name="p1451721115111"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="63.94%" headers="mcps1.1.5.1.4 "><p id="p8512119518"><a name="p8512119518"></a><a name="p8512119518"></a>Associates multiple named attribute bindings.</p>
</td>
</tr>
<tr id="row338mcpsimp"><td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.1 "><p id="p340mcpsimp"><a name="p340mcpsimp"></a><a name="p340mcpsimp"></a>Keys</p>
</td>
<td class="cellrowborder" valign="top" width="11.540000000000001%" headers="mcps1.1.5.1.2 "><p id="p342mcpsimp"><a name="p342mcpsimp"></a><a name="p342mcpsimp"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="9.5%" headers="mcps1.1.5.1.3 "><p id="p16662163915015"><a name="p16662163915015"></a><a name="p16662163915015"></a>Array&lt;string&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="63.94%" headers="mcps1.1.5.1.4 "><p id="p344mcpsimp"><a name="p344mcpsimp"></a><a name="p344mcpsimp"></a>Returns the flags of all persistent attributes.</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>-   When using  **PersistProp**, ensure that the input key exists in the  **Appstorage**.
>-   **DeleteProp**  takes effect only for the data that has been linked during the current startup.

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

