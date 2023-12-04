# Application Navigation Structure Design


Navigation enables users to move between pages of an application to browse content. A good navigation allows users to know where they are now, where they are going, and where they come from.


## Navigation Design Rules

Navigation design must comply with the following rules:

- **Consistent**: The navigation operation results should meet user expectations. Use UI layout and components that users are familiar with, and ensure consistent application architecture and navigation behavior on different devices in the same or similar scenarios. This allows users to know how to navigate on any screen. For example, on any level-2 screen, users can click or touch the back button in the upper left corner to return to the upper-level screen.

- **Clear**: Navigation should provide clear paths with simple logical relationships so that users can easily know where they are and where they will go after an operation. For example, users can use bottom tabs to switch between screens of the same level.

Avoid the following in navigation design:

- **Too many levels**: A maximum of three navigation levels are recommended. Too many levels may lead to low operational efficiency. If in-depth design is required, you are advised to use breadcrumb design or enable one-click to the home page.

- **Complex navigation**: Do not use bottom tabs on a screen where a sidebar is used. This practice makes operations complex.


## Navigation Classification

Common types of application navigation are flat navigation, hierarchical navigation, and hybrid navigation.

**Flat Navigation**

In flat navigation, pages are placed at the same level of hierarchy.

This type of navigation is used to display screens at the same level.

![en-us_image_0000001517612912](figures/en-us_image_0000001517612912.jpg)

For example, a page consisting of tabs is a type of flat navigation. As shown in the figure below, **Photos**, **Albums**, and **Discover** are level-1 screens, and users can access level-2 screens from **Videos**.

![one-to-many-2-2](figures/one-to-many-2-2.png)

During multi-device design, use different types of navigation components. For example, bottom tab navigation is used on the default device, side navigation is used on the tablet and PC, and top tab navigation is used on the large screen.

![one-to-many-2-3](figures/one-to-many-2-3.png)

**Hierarchical Navigation**

Hierarchical navigation consists of parent pages and child pages. A parent page can have one or more child pages. Each child page has a unique parent page.

Hierarchical navigation applies to complex multi-level structures. This navigation creates a long path for users to access deep-structured content and thereby decreases the access efficiency. To resolve this issue, you can adopt cross-hierarchy design. For example, the Bluetooth switch in Control Panel solves the problem of enabling Bluetooth by manipulating **Settings**.

This type of navigation can be used in applications with hierarchical pages.

![en-us_image_0000001568093237](figures/en-us_image_0000001568093237.jpg)

For example, users can click or touch the back button to return to the previous page after accessing the content.

![one-to-many-2-5](figures/one-to-many-2-5.png)

During multi-device design, you may display the upper-level and lower-level pages on the same screen. For example, use hierarchical navigation on the default device and large screen, but use the split-view layout on the tablet and PC.

![one-to-many-2-6](figures/one-to-many-2-6.png)

**Hybrid Navigation**

In actual application design, using only flat or hierarchical navigation may not be able to cope with more complex business structures. If this is the case, you need to distinguish the navigation relationships of different pages. For pages with the same position or level, use flat navigation. For pages with complex relationships, use hierarchical navigation.

Hybrid navigation applies to an application that consists of several modules at the same level, with each module having hierarchical pages.

![en-us_image_0000001568212949](figures/en-us_image_0000001568212949.jpg)

During multi-device design, you can use both flat navigation and hierarchical navigation. Generally, the priority of flat navigation is higher than that of hierarchical navigation.

![hybrid navigation](figures/hybrid-navigation.png)
