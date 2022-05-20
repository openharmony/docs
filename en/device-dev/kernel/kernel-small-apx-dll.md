# Doubly Linked List



## Basic Concepts

A doubly linked list is a linked data structure that consists of a set of sequentially linked records called nodes. Each node contains a pointer to the previous node and a pointer to the next node in the sequence of nodes. The pointer head is unique. A doubly linked list allows access from a list node to its next node and also the previous node on the list. This data structure facilitates data search, especially traversal of a large amount of data. The symmetry of the doubly linked list also makes operations, such as insertion and deletion, easy. However, pay attention to the pointer direction when performing operations.

## Available APIs

The following table describes APIs available for the doubly linked list. For more details about the APIs, see the API reference.

<a name="table9827162254713"></a>
<table><tbody><tr id="row2089515228470"><td class="cellrowborder" valign="top" width="8.14%"><p id="p4895182214473"><a name="p4895182214473"></a><a name="p4895182214473"></a>Function</p>
</td>
<td class="cellrowborder" valign="top" width="32.09%"><p id="p58951922124713"><a name="p58951922124713"></a><a name="p58951922124713"></a>API</p>
</td>
<td class="cellrowborder" valign="top" width="59.77%"><p id="p5895122134719"><a name="p5895122134719"></a><a name="p5895122134719"></a>Description</p>
</td>
</tr>
<tr id="row20895152284710"><td class="cellrowborder" rowspan="2" valign="top" width="8.14%"><p id="p18951922144714"><a name="p18951922144714"></a><a name="p18951922144714"></a>Initializing a linked list</p>
</td>
<td class="cellrowborder" valign="top" width="32.09%"><p id="p789516220474"><a name="p789516220474"></a><a name="p789516220474"></a><span>LOS_ListInit</span></p>
</td>
<td class="cellrowborder" valign="top" width="59.77%"><p id="p38951422144710"><a name="p38951422144710"></a><a name="p38951422144710"></a>Initializes a specified node as a doubly linked list node.</p>
</td>
</tr>
<tr id="row289552216475"><td class="cellrowborder" valign="top"><p id="p11895222194718"><a name="p11895222194718"></a><a name="p11895222194718"></a><span>LOS_DL_LIST_HEAD</span></p>
</td>
<td class="cellrowborder" valign="top"><p id="p3895222184710"><a name="p3895222184710"></a><a name="p3895222184710"></a>Defines a node and initializes it as a doubly linked list node.</p>
</td>
</tr>
<tr id="row1689522210476"><td class="cellrowborder" rowspan="3" valign="top" width="8.14%"><p id="p12896132294720"><a name="p12896132294720"></a><a name="p12896132294720"></a>Adding a node</p>
</td>
<td class="cellrowborder" valign="top" width="32.09%"><p id="p789611221477"><a name="p789611221477"></a><a name="p789611221477"></a><span>LOS_ListAdd</span></p>
</td>
<td class="cellrowborder" valign="top" width="59.77%"><p id="p9896122134715"><a name="p9896122134715"></a><a name="p9896122134715"></a>Inserts the specified node to the head of a doubly linked list.</p>
</td>
</tr>
<tr id="row191212010315"><td class="cellrowborder" valign="top"><p id="p14135012318"><a name="p14135012318"></a><a name="p14135012318"></a>LOS_ListHeadInsert</p>
</td>
<td class="cellrowborder" valign="top"><p id="p4138202417318"><a name="p4138202417318"></a><a name="p4138202417318"></a>Inserts the specified node to the head of a doubly linked list. It is the same as <strong id="b1391981116212"><a name="b1391981116212"></a><a name="b1391981116212"></a>LOS_ListAdd</strong>.</p>
</td>
</tr>
<tr id="row188961225475"><td class="cellrowborder" valign="top"><p id="p18961122154718"><a name="p18961122154718"></a><a name="p18961122154718"></a><span>LOS_ListTailInsert</span></p>
</td>
<td class="cellrowborder" valign="top"><p id="p188961322144712"><a name="p188961322144712"></a><a name="p188961322144712"></a>Inserts the specified node to the end of a doubly linked list.</p>
</td>
</tr>
<tr id="row15357444193310"><td class="cellrowborder" rowspan="3" valign="top" width="8.14%"><p id="p1692010363413"><a name="p1692010363413"></a><a name="p1692010363413"></a>Adding a linked list</p>
</td>
<td class="cellrowborder" valign="top" width="32.09%"><p id="p1735715449336"><a name="p1735715449336"></a><a name="p1735715449336"></a>LOS_ListAddList</p>
</td>
<td class="cellrowborder" valign="top" width="59.77%"><p id="p6622934203610"><a name="p6622934203610"></a><a name="p6622934203610"></a>Inserts the head of a specified linked list into the head of a doubly linked list.</p>
</td>
</tr>
<tr id="row15195047123311"><td class="cellrowborder" valign="top"><p id="p17195124711336"><a name="p17195124711336"></a><a name="p17195124711336"></a>LOS_ListHeadInsertList</p>
</td>
<td class="cellrowborder" valign="top"><p id="p185641532153916"><a name="p185641532153916"></a><a name="p185641532153916"></a>Inserts the head of a specified linked list into the head of a doubly linked list. It is the same as <strong id="b14274399311"><a name="b14274399311"></a><a name="b14274399311"></a>LOS_ListAddList</strong>.</p>
</td>
</tr>
<tr id="row144801751153310"><td class="cellrowborder" valign="top"><p id="p1048055153313"><a name="p1048055153313"></a><a name="p1048055153313"></a>LOS_ListTailInsertList</p>
</td>
<td class="cellrowborder" valign="top"><p id="p13855544153914"><a name="p13855544153914"></a><a name="p13855544153914"></a>Inserts the end of a specified linked list into the head of a doubly linked list.</p>
</td>
</tr>
<tr id="row5896112264710"><td class="cellrowborder" rowspan="2" valign="top" width="8.14%"><p id="p28961122174717"><a name="p28961122174717"></a><a name="p28961122174717"></a>Deleting a node</p>
</td>
<td class="cellrowborder" valign="top" width="32.09%"><p id="p28961422154710"><a name="p28961422154710"></a><a name="p28961422154710"></a><span>LOS_ListDelete</span></p>
</td>
<td class="cellrowborder" valign="top" width="59.77%"><p id="p289610224473"><a name="p289610224473"></a><a name="p289610224473"></a>Deletes the specified node from a doubly linked list.</p>
</td>
</tr>
<tr id="row3896522124711"><td class="cellrowborder" valign="top"><p id="p0896152213471"><a name="p0896152213471"></a><a name="p0896152213471"></a><span>LOS_ListDelInit</span></p>
</td>
<td class="cellrowborder" valign="top"><p id="p48965226475"><a name="p48965226475"></a><a name="p48965226475"></a>Deletes the specified node from the linked list and uses the node to initialize the linked list.</p>
</td>
</tr>
<tr id="row1689602294714"><td class="cellrowborder" rowspan="3" valign="top" width="8.14%"><p id="p18961222164716"><a name="p18961222164716"></a><a name="p18961222164716"></a>Determining a doubly linked list</p>
</td>
<td class="cellrowborder" valign="top" width="32.09%"><p id="p78961522184715"><a name="p78961522184715"></a><a name="p78961522184715"></a><span>LOS_ListEmpty</span></p>
</td>
<td class="cellrowborder" valign="top" width="59.77%"><p id="p16896172254720"><a name="p16896172254720"></a><a name="p16896172254720"></a>Checks whether a linked list is empty.</p>
</td>
</tr>
<tr id="row18516729174116"><td class="cellrowborder" valign="top"><p id="p17517829184112"><a name="p17517829184112"></a><a name="p17517829184112"></a>LOS_DL_LIST_IS_END</p>
</td>
<td class="cellrowborder" valign="top"><p id="p6517142944113"><a name="p6517142944113"></a><a name="p6517142944113"></a>Checks whether the specified linked list node is at the end of the linked list.</p>
</td>
</tr>
<tr id="row893214104211"><td class="cellrowborder" valign="top"><p id="p149321243429"><a name="p149321243429"></a><a name="p149321243429"></a>LOS_DL_LIST_IS_ON_QUEUE</p>
</td>
<td class="cellrowborder" valign="top"><p id="p393211444212"><a name="p393211444212"></a><a name="p393211444212"></a>Checks whether the linked list node is in a doubly linked list.</p>
</td>
</tr>
<tr id="row128977221474"><td class="cellrowborder" rowspan="5" valign="top" width="8.14%"><p id="p138971322174717"><a name="p138971322174717"></a><a name="p138971322174717"></a>Obtaining structure information</p>
</td>
<td class="cellrowborder" valign="top" width="32.09%"><p id="p138971922194712"><a name="p138971922194712"></a><a name="p138971922194712"></a><span>LOS_OFF_SET_OF</span></p>
</td>
<td class="cellrowborder" valign="top" width="59.77%"><p id="p08971022144720"><a name="p08971022144720"></a><a name="p08971022144720"></a>Obtains the offset of a member in a specified structure relative to the start address of the structure.</p>
</td>
</tr>
<tr id="row17897102264718"><td class="cellrowborder" valign="top"><p id="p222185817011"><a name="p222185817011"></a><a name="p222185817011"></a><span>LOS_DL_LIST_ENTRY</span></p>
</td>
<td class="cellrowborder" valign="top"><p id="p165524542002"><a name="p165524542002"></a><a name="p165524542002"></a>Obtains the address of the structure that contains the first node in the linked list. The first input parameter of the API indicates the head node in the list, the second input parameter indicates the name of the structure to be obtained, and the third input parameter indicates the name of the linked list in the structure.</p>
</td>
</tr>
<tr id="row15461471406"><td class="cellrowborder" valign="top"><p id="p1889792218473"><a name="p1889792218473"></a><a name="p1889792218473"></a>LOS_ListPeekHeadType</p>
</td>
<td class="cellrowborder" valign="top"><p id="p111876351019"><a name="p111876351019"></a><a name="p111876351019"></a>Obtains the address of the structure that contains the first node in the linked list. The first input parameter of the API indicates the head node in the list, the second input parameter indicates the name of the structure to be obtained, and the third input parameter indicates the name of the linked list in the structure. Return Null if the linked list is empty.</p>
</td>
</tr>
<tr id="row203104014114"><td class="cellrowborder" valign="top"><p id="p18321540016"><a name="p18321540016"></a><a name="p18321540016"></a>LOS_ListRemoveHeadType</p>
</td>
<td class="cellrowborder" valign="top"><p id="p913828651"><a name="p913828651"></a><a name="p913828651"></a>Obtains the address of the structure that contains the first node in the linked list, and deletes the first node from the list. The first input parameter of the API indicates the head node in the list, the second input parameter indicates the name of the structure to be obtained, and the third input parameter indicates the name of the linked list in the structure. Return Null if the linked list is empty.</p>
</td>
</tr>
<tr id="row745116416618"><td class="cellrowborder" valign="top"><p id="p1645217411963"><a name="p1645217411963"></a><a name="p1645217411963"></a>LOS_ListNextType</p>
</td>
<td class="cellrowborder" valign="top"><p id="p972412565619"><a name="p972412565619"></a><a name="p972412565619"></a>Obtains the address of the structure that contains the next node of the specified node in the linked list. The first input parameter of the API indicates the head node in the list, the second input parameter indicates the specified node, the third parameter indicates the name of the structure to be obtained, and the fourth input parameter indicates the name of the linked list in the structure. If the next node of the linked list node is the head node and is empty, NULL is returned.</p>
</td>
</tr>
<tr id="row4897192254715"><td class="cellrowborder" rowspan="2" valign="top" width="8.14%"><p id="p3897922164714"><a name="p3897922164714"></a><a name="p3897922164714"></a>Traversing a doubly linked list</p>
</td>
<td class="cellrowborder" valign="top" width="32.09%"><p id="p58971222194713"><a name="p58971222194713"></a><a name="p58971222194713"></a><span>LOS_DL_LIST_FOR_EACH</span></p>
</td>
<td class="cellrowborder" valign="top" width="59.77%"><p id="p28971222194714"><a name="p28971222194714"></a><a name="p28971222194714"></a>Traverses a doubly linked list.</p>
</td>
</tr>
<tr id="row589792254710"><td class="cellrowborder" valign="top"><p id="p689792264718"><a name="p689792264718"></a><a name="p689792264718"></a><span>LOS_DL_LIST_FOR_EACH_SAFE</span></p>
</td>
<td class="cellrowborder" valign="top"><p id="p148975222479"><a name="p148975222479"></a><a name="p148975222479"></a>Traverses a doubly linked list, and stores the next node of the current node for security verification.</p>
</td>
</tr>
<tr id="row208971622174718"><td class="cellrowborder" rowspan="2" valign="top" width="8.14%"><p id="p168977224474"><a name="p168977224474"></a><a name="p168977224474"></a>Traversing the structure that contains the doubly linked list</p>
</td>
<td class="cellrowborder" valign="top" width="32.09%"><p id="p1489752216479"><a name="p1489752216479"></a><a name="p1489752216479"></a><span>LOS_DL_LIST_FOR_EACH_ENTRY</span></p>
</td>
<td class="cellrowborder" valign="top" width="59.77%"><p id="p10897522194717"><a name="p10897522194717"></a><a name="p10897522194717"></a>Traverses the specified doubly linked list and obtains the address of the structure that contains the linked list node.</p>
</td>
</tr>
<tr id="row10897622104713"><td class="cellrowborder" valign="top"><p id="p2897112215478"><a name="p2897112215478"></a><a name="p2897112215478"></a><span>LOS_DL_LIST_FOR_EACH_ENTRY_SAFE</span></p>
</td>
<td class="cellrowborder" valign="top"><p id="p13898102220475"><a name="p13898102220475"></a><a name="p13898102220475"></a>Traverses the specified doubly linked list, obtains the structure address of the node that contains the linked list, and stores the structure address that contains the next node of the current node.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section01781261552"></a>

The typical development process of the doubly linked list is as follows:

1.  Call  **LOS\_ListInit/LOS\_DL\_LIST\_HEAD**  to initialize a doubly linked list.
2.  Call  **LOS\_ListAdd**  to insert a node to the list.
3.  Call  **LOS\_ListTailInsert**  to insert a node to the end of the list.
4.  Call  **LOS\_ListDelete**  to delete the specified node.
5.  Call  **LOS\_ListEmpty**  to check whether a linked list is empty.
6.  Call  **LOS\_ListDelInit**  to delete a specified node, and initialize the linked list based on this node.

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>-   Pay attention to the operations of the front and back pointer of the node.
>-   The linked list operation APIs are underlying APIs and do not check whether the input parameters are empty. You must ensure that the input parameters are valid.
>-   If the memory of a linked list node is dynamically requested, release the memory after deleting the node.

### Development Example<a name="section8354175218128"></a>

**Example Description**

This example implements the following:

1.  Initialize a doubly linked list.
2.  Add nodes.
3.  Delete nodes.
4.  Check the operation result.

```
#include "stdio.h"
#include "los_list.h"

static UINT32 ListSample(VOID)
{
    LOS_DL_LIST listHead = {NULL,NULL};
    LOS_DL_LIST listNode1 = {NULL,NULL};
    LOS_DL_LIST listNode2 = {NULL,NULL};

    // Initialize the linked list.
    PRINTK("Initial head\n");
    LOS_ListInit(&listHead);

    // Add node 1 and node 2 and verify their relationship.
    LOS_ListAdd(&listHead, &listNode1);
    if (listNode1.pstNext == &listHead && listNode1.pstPrev == &listHead) {
        PRINTK("Add listNode1 success\n");
    }

    LOS_ListTailInsert(&listHead, &listNode2);
    if (listNode2.pstNext == &listHead && listNode2.pstPrev == &listNode1) {
        PRINTK("Tail insert listNode2 success\n");
    }

    // Delete the two nodes.
    LOS_ListDelete(&listNode1);
    LOS_ListDelete(&listNode2);

    // Check that the linked list is empty.
    if (LOS_ListEmpty(&listHead)) {
        PRINTK("Delete success\n");
    }

    return LOS_OK;
}
```

**Verification**

The development is successful if the return result is as follows:

```
Initial head 
Add listNode1 success 
Tail insert listNode2 success
Delete success
```

