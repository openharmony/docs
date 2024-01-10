# Design Checklists

The design checklist lists the rules that should be paid attention to during application design in all scenarios. Complying with these rules helps you deliver consistent user experience.


The rules are either **Mandatory** or **Optional**. Mandatory rules are proven solutions or effects that must be observed in your design. Optional rules are subject to application brand style or service-specific requirements, and can be adjusted as required.


Check your application against the following checklist:


  | **Type**| **Item**| **Description**|**Category**| 
| -------- | -------- | -------- | -------- |
| Application architecture| Navigation| Ensure the same page navigation structure on different forms of devices. (You must provide UX design for all these devices, if supported.)| Optional| 
| Layout| Streamlined design| Streamline the layout design for each device form. Ensure that the display of content is consistent across devices of different sizes and resolutions without misplacement, truncation, deformation, excess blank space (> 50%), overcrowding (spacing < 16 vp), or extremely large fonts or images.| Mandatory| 
| | Responsive design| Design the grid layout within the area that occupies *N* columns and the gutters inside these columns, excluding the margins on both the right and left sides.| Mandatory| 
| | Responsive design| Specify the type of the grid to use and provide the values of the three grid elements at different breakpoints.| Optional| 
| | Responsive design| Align grids by container instead of internal sub-elements.| Mandatory| 
| | Responsive design| In addition to the page layout design, mark grids in obvious ways, such as colors, to avoid confusion during partial grid design.| Optional| 
| | Responsive design| It is prohibited that you do not design the layout based on grids while grids are marked.| Mandatory| 
| | Adaptive design| In non-grid design scenarios, clearly mark the adaptive layout capability, which includes stretching, equalization, proportion, scaling, extension, hiding, and wrapping.| Optional| 
| Human-computer interaction| Input modes| Ensure that the interaction modes, such as touchscreen, mouse, keyboard, remote control, and joystick, are all supported in a way that complies with industry standards.| Optional| 
| | Unified interaction events| Use OpenHarmony components to achieve consistent interaction experience. If customization is required, ensure that the operations on different input devices are the same as those specified in the guide in each scenario. Special attention must be paid to the use of a mouse.| Optional| 
| Visual style| Units| Use vp as the unit for UI layout. Use px only in scenarios where the element size is strictly controlled.| Mandatory| 
| | Colors| Use layered parameters for color assignment. The dark color mode is recommended. Ensure that no recognition problem occurs when the color mode changes.| Optional| 
| | Fonts| Use fp as the font unit. Ensure that your application changes the font size according to the system font setting, while maintaining a consistent UI layout.| Mandatory| 
| Polymorphic components| Common component states| Ensure that the visual effects of components in different states are available. The common component states are as follows: normal, disabled, pressed, focused, activated, and hover.| Optional| 
