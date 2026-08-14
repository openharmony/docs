# Analyzing Web Page Memory Using DevTools

<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=d520c126c4207370617e595d71649ce8b1cf22f9 translatedAt=2026-08-12T11:19:51.201Z pushedAt=2026-08-12T11:25:10.319Z -->

## Enabling DevTools

DevTools is a built-in tool of the Chrome browser. After you [download](https://www.google.com.hk/intl/en_uk/chrome/) and launch Chrome, press **F12** or **Shift+Ctrl+I** on the page where memory analysis is needed to start DevTools.

## Obtaining JS Heap Memory Snapshots

On the **Memory** panel, select **Heap snapshot** and click **Take snapshot** to capture a memory snapshot of the current page.

![Obtaining heap snapshots](figures/js-memory-analysis-u-0.png)

![Heap snapshot results](figures/js-memory-analysis-u-1.png)

## Analyzing Heap Snapshots

### Summary

The **Summary** tab displays the overview of the current memory snapshot. Key details include:

- **Constructor**: the constructor of an object.

- **Distance**: distance from the reference chain of the GC root to the object. If the distances of objects of the same type are different, the code logic may be incorrect.

- **Object Count**: total number of objects constructed by the current constructor, which is a gray number next to the constructor.

- **Shallow Size**: memory size occupied by an object.

- **Retained Size**: total memory that the system VM can release after an object is released.

![](figures/js-memory-analysis-u-2.png)

A filter panel on the right side of the **Summary** tab allows you to focus on specific objects. For example, selecting "Objects allocated between Snapshot 2 and Snapshot 3" (as shown below) helps locate where memory issues occur.

![Right-side filter panel](figures/js-memory-analysis-u-3.png)

### Comparison

In **Comparison**, you can compare the current snapshot with another snapshot to track the changes of object properties and memory usage. Key details include:

- **Constructor**: constructor of an object.

- **New**: number of new objects created under the object constructor.

- **Deleted**: number of new objects deleted under the object constructor.

- **Delta**: difference between new objects and deleted objects.

- **Alloc Size**: size of the memory allocated for two snapshots.

- **Freed Size**: size of the memory released for two snapshots.

- **Size Delta**: difference between **Alloc Size** and **Freed Size**.

You can analyze memory issues by comparing the differences between snapshots on the **Comparison** tab.

![](figures/js-memory-analysis-u-4.png)

### Containment

**Containment** provides a top-down tree view that allows you to browse and explore the contents of heap memory. You can use it to analyze the reference relationships of any variable.

![Containment](figures/js-memory-analysis-u-5.png)

### Statistics

**Statistics** displays the memory usage ratio of different object types in a pie chart.

![Statistics](figures/js-memory-analysis-u-6.png)

## Memory Leak Analysis Process

1. Open a page where memory leaks may occur and enable DevTools. The following figure shows a page from the [memory-leak-simulation](https://github.com/Buchatech/JavaScript-Memory-Leak-Simulation) project on GitHub. This page simulates a memory leak scenario by setting a global array and continuously pushing the 'memory leak' string into it.

   ![Overview](figures/js-memory-analysis-u-7.png)

2. Record user operations that may cause memory leaks on the **Performance** tab to identify the specific operations or components triggering leaks. As shown in the following figure, the web page has been loaded, but the memory keeps increasing, indicating that a memory leak may occur. For web pages that contain a large number of dynamic components and frequently perform DOM operations, the memory curve may fluctuate. Observe the minimum memory value. If the minimum memory value increases gradually, the web page may have a memory leak.

   ![](figures/js-memory-analysis-u-9.png)

3. Take the first heap snapshot of the web page. It is found that the **Array** object occupies 24 MB memory, which is significantly higher than the normal value (usually within several MB). Therefore, a memory leak may occur on this object.

   ![Snapshot1](figures/js-memory-analysis-u-10.png)

4. Perform operations that may trigger memory leaks on the page. Take a second heap snapshot after completing the operations, then select "Objects allocated between Snapshot 2 and Snapshot 3". It shows the **Array** constructor newly occupies approximately 20 MB of memory.

   ![Snapshot2](figures/js-memory-analysis-u-11.png)

5. Open the **Comparison** tab, select snapshot 3, and use snapshot 2 as the reference. The results show the **Array** constructor created 5,010 new objects, occupying 20.1 MB but releasing only 184 B. Therefore, the memory leak occurred in **Array**.

   ![](figures/js-memory-analysis-u-12.png)

6. Record a heap snapshot for 1 to 2 minutes to obtain a **Summary** view with a timeline, which is similar to the view on the **Performance** page. This helps identify which actions caused memory usage changes. Select **Allocations on timeline**, and click the recording button. After the test action is complete, stop the recording to generate the memory heap timeline view.

   ![](figures/js-memory-analysis-u-13.png)

7. On the result timeline, you can drag the left mouse button to select the target time range and view memory allocations during that period. The highlighted area in the image below shows the **Array** constructor created 2,000 new objects in the selected time frame. This feature clarifies the impact of different operations on memory.

   ![](figures/js-memory-analysis-u-14.png)