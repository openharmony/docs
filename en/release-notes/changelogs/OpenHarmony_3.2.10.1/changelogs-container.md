# Common Library Subsystem Changelog

Compared with OpenHarmony 3.2 Beta4, OpenHarmony 3.2.10.1 (MR) has the following API changes in the common library subsystem.

## cl.utils.1 Error Code and Information Change

The error codes and information returned by APIs of the **ArrayList**, **List**, **LinkedList**, **Stack**, **Queue**, **Deque**, **PlainArray**, **LightWeightMap**, **LightWeightSet**, **HashMap**, **HashSet**, **TreeMap**, and **TreeSet** classes are changed.

For details about the changed error codes, see [Utils Error Codes](../../../application-dev/reference/errorcodes/errorcode-utils.md).

No adaptation is required for applications developed using these APIs.

**Key API/Component Changes**

Error code information is redefined for APIs in these classes and marked using **'@throws'** in the *.d.ts file of the corresponding module.

The sample code is as follows:

**ArrayList** class before the change:

constructor();

**ArrayList** class after the change:

@throws { BusinessError } 10200012 - The ArrayList's constructor cannot be directly invoked.
constructor();

**Change Impact**

None
