# C++ Support

## Basic Concepts

As one of the most widely used programming languages, C++ supports features, such as classes, encapsulation, and overloading. It is an object-oriented programming language developed based on the C language.

## Working Principles

The compiler supports C++ code identification. The system calls the constructors of global objects to perform initialization operations.

## Development Guidelines

### Available APIs

**Table  1**  APIs supported by C++

<a name="table14277123518139"></a>
<table><thead align="left"><tr id="row152771935131315"><th class="cellrowborder" valign="top" width="23.792379237923793%" id="mcps1.2.4.1.1"><p id="p1127733591316"><a name="p1127733591316"></a><a name="p1127733591316"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="33.02330233023302%" id="mcps1.2.4.1.2"><p id="p22771357138"><a name="p22771357138"></a><a name="p22771357138"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="43.18431843184319%" id="mcps1.2.4.1.3"><p id="p327714358130"><a name="p327714358130"></a><a name="p327714358130"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row119525513581"><td class="cellrowborder" valign="top" width="23.792379237923793%" headers="mcps1.2.4.1.1 "><p id="p2099535514346"><a name="p2099535514346"></a><a name="p2099535514346"></a>Prerequisites for using C++ features</p>
</td>
<td class="cellrowborder" valign="top" width="33.02330233023302%" headers="mcps1.2.4.1.2 "><p id="p3155620345"><a name="p3155620345"></a><a name="p3155620345"></a>LOS_CppSystemInit</p>
</td>
<td class="cellrowborder" valign="top" width="43.18431843184319%" headers="mcps1.2.4.1.3 "><p id="p4616566343"><a name="p4616566343"></a><a name="p4616566343"></a>Initializes C++ constructors.</p>
</td>
</tr>
</tbody>
</table>

### How to Develop

Before using C++ features, you need to call  **LOS\_CppSystemInit**  to initialize C++ constructors. The initialized constructors are stored in the  **init\_array**  section, and the section range is passed by the variables  **\_\_init\_array\_start\_\_**  and  **\_\_init\_array\_end\_\_**.

**Table  2**  Parameter description

<a name="table71191652173718"></a>
<table><thead align="left"><tr id="row1512085253715"><th class="cellrowborder" valign="top" width="42.77%" id="mcps1.2.3.1.1"><p id="p16120175233720"><a name="p16120175233720"></a><a name="p16120175233720"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="57.230000000000004%" id="mcps1.2.3.1.2"><p id="p61205526372"><a name="p61205526372"></a><a name="p61205526372"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row11120135213714"><td class="cellrowborder" valign="top" width="42.77%" headers="mcps1.2.3.1.1 "><p id="p1053212673917"><a name="p1053212673917"></a><a name="p1053212673917"></a>__init_array_start__</p>
</td>
<td class="cellrowborder" valign="top" width="57.230000000000004%" headers="mcps1.2.3.1.2 "><p id="p2208154219392"><a name="p2208154219392"></a><a name="p2208154219392"></a>Start of the <strong id="b13329113893818"><a name="b13329113893818"></a><a name="b13329113893818"></a>init_array</strong> section</p>
</td>
</tr>
<tr id="row1591908143918"><td class="cellrowborder" valign="top" width="42.77%" headers="mcps1.2.3.1.1 "><p id="p491968193914"><a name="p491968193914"></a><a name="p491968193914"></a>__init_array_end__</p>
</td>
<td class="cellrowborder" valign="top" width="57.230000000000004%" headers="mcps1.2.3.1.2 "><p id="p6919189393"><a name="p6919189393"></a><a name="p6919189393"></a>End of the <strong id="b48960753912"><a name="b48960753912"></a><a name="b48960753912"></a>init_array</strong> section</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>The  **LOS\_CppSystemInit**  function must be called before a C++ service. When the C library used by the third-party compiler is not musl libc, some classes or APIs \(such as  **std::thread**  and  **std::mutex**\) that are closely related to system resources have compatibility issues and are not recommended to use.

### Development Example

```
void app_init(void)
{
......
/* Initialize C++ in the startup phase. */
LOS_CppSystemInit((UINTPTR)&__init_array_start__, (UINTPTR)&__init_array_end__);
/* C++ service */
......
}
```

