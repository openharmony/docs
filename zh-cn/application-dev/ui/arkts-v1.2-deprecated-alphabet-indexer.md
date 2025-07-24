# AlphabetIndexer

以下接口在ArkTS1.1中已标记为废弃，并在ArkTS1.2中不再支持。

## onSelected

ArkTS1.1接口声明：[onSelected(callback: (index: number) => void)](../reference/apis-arkui/arkui-ts/ts-container-alphabet-indexer.md#onselecteddeprecated)

替代的ArkTS1.2接口声明：[onSelect(callback: (index: number) => void)](../reference/apis-arkui/arkui-ts/ts-container-alphabet-indexer.md#onselect8)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
AlphabetIndexer({ arrayValue: ['A', 'B'], selected: 0 })
    .onSelected((index: number) => {
        console.info(index + 'Selected!');
    })
```

ArkTS1.2
<!--code_no_check-->
```ts
AlphabetIndexer({ arrayValue: ['A', 'B'], selected: 0 })
    .onSelect((index: number) => {
        console.info(index + 'Selected!');
    })
```