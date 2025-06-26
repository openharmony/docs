# Universal Styles


You can set universal styles for components in the **style** attribute or **.css** files.


| Name                                | Type                                      | Default Value  | Mandatory  | Description                                      |
| ---------------------------------- | ---------------------------------------- | ----- | ---- | ---------------------------------------- |
| width                              | &lt;length&gt; \| &lt;percentage&gt;<sup>5+</sup> | -     | No   | Component width.<br><br>If this attribute is not set, the default value **0** is used.       |
| height                             | &lt;length&gt; \| &lt;percentage&gt;<sup>5+</sup> | -     | No   | Component height.<br><br>If this attribute is not set, the default value **0** is used.       |
| padding                            | &lt;length&gt;                           | 0     | No   | Shorthand attribute to set the padding for all sides in a declaration.<br>The attribute can have one to four values:<br>- If you set only one value, it specifies the padding for all the four sides.<br>- If you set two values, the first value specifies the top and bottom padding, and the second value specifies the left and right padding.<br>- If you set three values, the first value specifies the top padding, the second value specifies the left and right padding, and the third value specifies the bottom padding.<br>- If you set four values, they respectively specify the padding for top, right, bottom, and left sides (in clockwise order).|
| padding-[left\|top\|right\|bottom] | &lt;length&gt;                           | 0     | No   | Left, top, right, and bottom padding.                         |
| margin                             | &lt;length&gt; \| &lt;percentage&gt;<sup>5+</sup> | 0     | No   | Shorthand attribute to set the margin for all sides in a declaration. The attribute can have one to four values:<br>- If you set only one value, it specifies the margin for all the four sides.<br>- If you set two values, the first value specifies the top and bottom margins, and the second value specifies the left and right margins.<br>- If you set three values, the first value specifies the top margin, the second value specifies the left and right margins, and the third value specifies the bottom margin.<br>- If you set four values, they respectively specify the margin for top, right, bottom, and left sides (in clockwise order).|
| margin-[left\|top\|right\|bottom]  | &lt;length&gt; \| &lt;percentage&gt;<sup>5+</sup> | 0     | No   | Left, top, right, and bottom margins.                         |
| border-width                       | &lt;length&gt;                           | 0     | No   | Shorthand attribute to set the border width for all sides.                      |
| border-color                       | &lt;color&gt;                            | black | No   | Shorthand attribute to set the color for all borders.                      |
| border-radius                      | &lt;length&gt;                           | -     | No   | Radius of round-corner borders.           |
| background-color                   | &lt;color&gt;                            | -     | No   | Background color.                                 |
| opacity<sup>5+</sup>               | number                                   | 1     | No   | Opacity of an element. The value ranges from **0** to **1**. The value **1** means opaque, and **0** means completely transparent.       |
| display                            | string                                   | flex  | No   | Type of the box containing an element. Available values are as follows:<br>- **flex**: flexible layout<br>- **none**: not rendered|
| [left\|top]                        | &lt;length&gt; \| &lt;percentage&gt;<sup>6+</sup> | -     | No   | Edge of the element.<br>- **left**: left edge position of the element. This attribute defines the offset between the left edge of the margin area of a positioned element and left edge of its containing block.<br>- **top**: top edge position of the element. This attribute defines the offset between the top edge of a positioned element and that of a block included in the element.|


> **NOTE**
>
> The aforementioned universal styles are not mandatory.
>
> Currently, the following color formats are supported:
> - rgb(255, 255, 255)
>
> - rgba(255, 255, 255, 1.0)
>
> - HEX formats: \#rrggbb and \#aarrggbb
>
> - Enumeration format: as listed in Table 1. The enumeration format is not supported in the script.


  **Table 1** Color enums

| Name                | Hexadecimal Code    | Color                                      |
| -------------------- | -------- | ---------------------------------------- |
| aliceblue            | \#f0f8ff | ![aliceblue](figures/aliceblue.png)      |
| antiquewhite         | \#faebd7 | ![antiquewhite](figures/antiquewhite.png) |
| aqua                 | \#00ffff | ![aqua](figures/aqua.png)                |
| aquamarine           | \#7fffd4 | ![aquamarine](figures/aquamarine.png)    |
| azure                | \#f0ffff | ![azure](figures/azure.png)              |
| beige                | \#f5f5dc | ![beige](figures/beige.png)              |
| bisque               | \#ffe4c4 | ![bisque](figures/bisque.png)            |
| black                | \#000000 | ![000000](figures/000000.png)            |
| blanchedalmond       | \#ffebcd | ![blanchedalmond](figures/blanchedalmond.png) |
| blue                 | \#0000ff | ![blue](figures/blue.png)                |
| blueviolet           | \#8a2be2 | ![blueviolet](figures/blueviolet.png)    |
| brown                | \#a52a2a | ![brown](figures/brown.png)              |
| burlywood            | \#deB887 | ![burlywood](figures/burlywood.png)      |
| cadetblue            | \#5f9ea0 | ![cadetblue](figures/cadetblue.png)      |
| chartreuse           | \#7fff00 | ![chartreuse](figures/chartreuse.png)    |
| chocolate            | \#d2691e | ![chocolate](figures/chocolate.png)      |
| coral                | \#ff7f50 | ![coral](figures/coral.png)              |
| cornflowerblue       | \#6495ed | ![cornflowerblue](figures/cornflowerblue.png) |
| cornsilk             | \#fff8dc | ![cornsilk](figures/cornsilk.png)        |
| crimson              | \#dc143c | ![crimson](figures/crimson.png)          |
| cyan                 | \#00ffff | ![cyan](figures/cyan.png)                |
| darkblue             | \#00008b | ![darkblue](figures/darkblue.png)        |
| darkcyan             | \#008b8b | ![darkcyan](figures/darkcyan.png)        |
| darkgoldenrod        | \#b8860b | ![darkgoldenrod](figures/darkgoldenrod.png) |
| darkgray             | \#a9a9a9 | ![darkgray](figures/darkgray.png)        |
| darkgreen            | \#006400 | ![darkgreen](figures/darkgreen.png)      |
| darkgrey             | \#a9a9a9 | ![darkgrey](figures/darkgrey.png)        |
| darkkhaki            | \#bdb76b | ![darkkhaki](figures/darkkhaki.png)      |
| darkmagenta          | \#8b008b | ![darkmagenta](figures/darkmagenta.png)  |
| darkolivegreen       | \#556b2f | ![darkolivegreen](figures/darkolivegreen.png) |
| darkorange           | \#ff8c00 | ![darkorange](figures/darkorange.png)    |
| darkorchid           | \#9932cc | ![darkorchid](figures/darkorchid.png)    |
| darkred              | \#8b0000 | ![darkred](figures/darkred.png)          |
| darksalmon           | \#e9967a | ![darksalmon](figures/darksalmon.png)    |
| darkseagreen         | \#8fbc8f | ![darkseagreen](figures/darkseagreen.png) |
| darkslateblue        | \#483d8b | ![darkslateblue](figures/darkslateblue.png) |
| darkslategray        | \#2f4f4f | ![darkslategray](figures/darkslategray.png) |
| darkslategrey        | \#2f4f4f | ![darkslategrey](figures/darkslategrey.png) |
| darkturquoise        | \#00ced1 | ![darkturquoise](figures/darkturquoise.png) |
| darkviolet           | \#9400d3 | ![darkviolet](figures/darkviolet.png)    |
| deeppink             | \#ff1493 | ![deeppink](figures/deeppink.png)        |
| deepskyblue          | \#00bfff | ![deepskyblue](figures/deepskyblue.png)  |
| dimgray              | \#696969 | ![dimgray](figures/dimgray.png)          |
| dimgrey              | \#696969 | ![dimgrey](figures/dimgrey.png)          |
| dodgerblue           | \#1e90ff | ![dodgerblue](figures/dodgerblue.png)    |
| firebrick            | \#b22222 | ![firebrick](figures/firebrick.png)      |
| floralwhite          | \#fffaf0 | ![floralwhite](figures/floralwhite.png)  |
| forestgreen          | \#228b22 | ![forestgreen](figures/forestgreen.png)  |
| fuchsia              | \#ff00ff | ![fuchsia](figures/fuchsia.png)          |
| gainsboro            | \#dcdcdc | ![gainsboro](figures/gainsboro.png)      |
| ghostwhite           | \#f8f8ff | ![ghostwhite](figures/ghostwhite.png)    |
| gold                 | \#ffd700 | ![gold](figures/gold.png)                |
| goldenrod            | \#daa520 | ![goldenrod](figures/goldenrod.png)      |
| gray                 | \#808080 | ![gray](figures/gray.png)                |
| green                | \#008000 | ![green](figures/green.png)              |
| greenyellow          | \#adff2f | ![greenyellow](figures/greenyellow.png)  |
| grey                 | \#808080 | ![grey](figures/grey.png)                |
| honeydew             | \#f0fff0 | ![honeydew](figures/honeydew.png)        |
| hotpink              | \#ff69b4 | ![hotpink](figures/hotpink.png)          |
| indianred            | \#cd5c5c | ![indianred](figures/indianred.png)      |
| indigo               | \#4b0082 | ![indigo](figures/indigo.png)            |
| ivory                | \#fffff0 | ![ivory](figures/ivory.png)              |
| khaki                | \#f0e68c | ![khaki](figures/khaki.png)              |
| lavender             | \#e6e6fa | ![lavender](figures/lavender.png)        |
| lavenderblush        | \#fff0f5 | ![lavenderblush](figures/lavenderblush.png) |
| lawngreen            | \#7cfc00 | ![lawngreen](figures/lawngreen.png)      |
| lemonchiffon         | \#fffacd | ![lemonchiffon](figures/lemonchiffon.png) |
| lightblue            | \#add8e6 | ![lightblue](figures/lightblue.png)      |
| lightcoral           | \#f08080 | ![lightcoral](figures/lightcoral.png)    |
| lightcyan            | \#e0ffff | ![lightcyan](figures/lightcyan.png)      |
| lightgoldenrodyellow | \#fafad2 | ![lightgoldenrodyellow](figures/lightgoldenrodyellow.png) |
| lightgray            | \#d3d3d3 | ![lightgray](figures/lightgray.png)      |
| lightgreen           | \#90ee90 | ![lightgreen](figures/lightgreen.png)    |
| lightpink            | \#ffb6c1 | ![lightpink](figures/lightpink.png)      |
| lightsalmon          | \#ffa07a | ![lightsalmon](figures/lightsalmon.png)  |
| lightseagreen        | \#20b2aa | ![lightseagreen](figures/lightseagreen.png) |
| lightskyblue         | \#87cefa | ![lightskyblue](figures/lightskyblue.png) |
| lightslategray       | \#778899 | ![lightslategray](figures/lightslategray.png) |
| lightslategrey       | \#778899 | ![lightslategrey](figures/lightslategrey.png) |
| lightsteelblue       | \#b0c4de | ![lightsteelblue](figures/lightsteelblue.png) |
| lightyellow          | \#ffffe0 | ![lightyellow](figures/lightyellow.png)  |
| lime                 | \#00ff00 | ![lime](figures/lime.png)                |
| limegreen            | \#32cd32 | ![limegreen](figures/limegreen.png)      |
| linen                | \#faf0e6 | ![linen](figures/linen.png)              |
| magenta              | \#ff00ff | ![magenta](figures/magenta.png)          |
| maroon               | \#800000 | ![maroon](figures/maroon.png)            |
| mediumaquamarine     | \#66cdaa | ![mediumaquamarine](figures/mediumaquamarine.png) |
| mediumblue           | \#0000cd | ![mediumblue](figures/mediumblue.png)    |
| mediumorchid         | \#ba55d3 | ![mediumorchid](figures/mediumorchid.png) |
| mediumpurple         | \#9370db | ![mediumpurple](figures/mediumpurple.png) |
| mediumseagreen       | \#3cb371 | ![mediumseagreen](figures/mediumseagreen.png) |
| mediumslateblue      | \#7b68ee | ![mediumslateblue](figures/mediumslateblue.png) |
| mediumspringgreen    | \#00fa9a | ![mediumspringgreen](figures/mediumspringgreen.png) |
| mediumturquoise      | \#48d1cc | ![mediumturquoise](figures/mediumturquoise.png) |
| mediumvioletred      | \#c71585 | ![mediumvioletred](figures/mediumvioletred.png) |
| midnightblue         | \#191970 | ![midnightblue](figures/midnightblue.png) |
| mintcream            | \#f5fffa | ![mintcream](figures/mintcream.png)      |
| mistyrose            | \#ffe4e1 | ![mistyrose](figures/mistyrose.png)      |
| moccasin             | \#ffe4b5 | ![moccasin](figures/moccasin.png)        |
| navajowhite          | \#ffdead | ![navajowhite](figures/navajowhite.png)  |
| navy                 | \#000080 | ![navy](figures/navy.png)                |
| oldlace              | \#fdf5e6 | ![oldlace](figures/oldlace.png)          |
| olive                | \#808000 | ![olive](figures/olive.png)              |
| olivedrab            | \#6b8e23 | ![olivedrab](figures/olivedrab.png)      |
| orange               | \#ffa500 | ![orange](figures/orange.png)            |
| orangered            | \#ff4500 | ![orangered](figures/orangered.png)      |
| orchid               | \#da70d6 | ![orchid](figures/orchid.png)            |
| palegoldenrod        | \#eee8aa | ![palegoldenrod](figures/palegoldenrod.png) |
| palegreen            | \#98fb98 | ![palegreen](figures/palegreen.png)      |
| paleturquoise        | \#afeeee | ![paleturquoise](figures/paleturquoise.png) |
| palevioletred        | \#db7093 | ![palevioletred](figures/palevioletred.png) |
| papayawhip           | \#ffefd5 | ![papayawhip](figures/papayawhip.png)    |
| peachpuff            | \#ffdab9 | ![peachpuff](figures/peachpuff.png)      |
| peru                 | \#cd853f | ![peru](figures/peru.png)                |
| pink                 | \#ffc0cb | ![pink](figures/pink.png)                |
| plum                 | \#dda0dd | ![plum](figures/plum.png)                |
| powderblue           | \#b0e0e6 | ![powderblue](figures/powderblue.png)    |
| purple               | \#800080 | ![purple](figures/purple.png)            |
| rebeccapurple        | \#663399 | ![rebeccapurple](figures/rebeccapurple.png) |
| red                  | \#ff0000 | ![red](figures/red.png)                  |
| rosybrown            | \#bc8f8f | ![rosybrown](figures/rosybrown.png)      |
| royalblue            | \#4169e1 | ![royalblue](figures/royalblue.png)      |
| saddlebrown          | \#8b4513 | ![saddlebrown](figures/saddlebrown.png)  |
| salmon               | \#fa8072 | ![salmon](figures/salmon.png)            |
| sandybrown           | \#f4a460 | ![sandybrown](figures/sandybrown.png)    |
| seagreen             | \#2e8b57 | ![seagreen](figures/seagreen.png)        |
| seashell             | \#fff5ee | ![seashell](figures/seashell.png)        |
| sienna               | \#a0522d | ![sienna](figures/sienna.png)            |
| silver               | \#c0c0c0 | ![silver](figures/silver.png)            |
| skyblue              | \#87ceeb | ![skyblue](figures/skyblue.png)          |
| slateblue            | \#6a5acd | ![slateblue](figures/slateblue.png)      |
| slategray            | \#708090 | ![slategray](figures/slategray.png)      |
| slategrey            | \#708090 | ![slategray](figures/slategray.png)      |
| snow                 | \#fffafa | ![snow](figures/snow.png)                |
| springgreen          | \#00ff7f | ![springgreen](figures/springgreen.png)  |
| steelblue            | \#4682b4 | ![steelblue](figures/steelblue.png)      |
| tan                  | \#d2b48c | ![tan](figures/tan.png)                  |
| teal                 | \#008080 | ![teal](figures/teal.png)                |
| thistle              | \#d8Bfd8 | ![thistle](figures/thistle.png)          |
| tomato               | \#ff6347 | ![tomato](figures/tomato.png)            |
| turquoise            | \#40e0d0 | ![turquoise](figures/turquoise.png)      |
| violet               | \#ee82ee | ![violet](figures/violet.png)            |
| wheat                | \#f5deb3 | ![wheat](figures/wheat.png)              |
| white                | \#ffffff | ![white](figures/white.png)              |
| whitesmoke           | \#f5f5f5 | ![whitesmoke](figures/whitesmoke.png)    |
| yellow               | \#ffff00 | ![yellow](figures/yellow.png)            |
| yellowgreen          | \#9acd32 | ![yellowgreen](figures/yellowgreen.png)  |
