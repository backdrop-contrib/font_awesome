Font Awesome
============

This module allows including Font Awesome icons via CSS classes in your website.
It loads the Font Awesome CSS file via a CDN to reduce server load.

You can use Font Awesome icons in your own module/theme with the following code:

``` php
if (module_exists('font_awesome')) {
  // Add Font Awesome CSS classes to your HTML here.
  // See https://fontawesome.com/how-to-use/on-the-web/referencing-icons/basic-use for examples.
}
```

Font Awesome icons are also exposed to the core Backdrop icon API.

Installation
------------

- Install this module using the official Backdrop CMS instructions at
  https://backdropcms.org/guide/modules

- If needed, also enable the included Font Awesome Field sub-module.

- Visit the configuration page under Administration > Configuration > User
  Interface > Font Awesome (admin/config/user-interface/font-awesome) to set
  the source for the Font Awesome CSS file.

Advanced Usage
--------------

On the configuration page, you can select 'Local' to define an alternative
local path for the Font Awesome CSS file. This enables you to load a custom
version of the library, such as a slimmed down version with only the icons
needed for your site.

You can also select 'Other' if the icons will be loaded via the theme or
possibly a custom module, but you still need this module to enable Font Awesome
Field, as a dependency to another module or to enable enhancements within
another module. Loading this way also enables you to customise the library.

You can use 'None' if you only plan to use the locally-provided SVGs through
Backdrop's core icon API and you don't want the Font Awesome CSS to be loaded
automatically. (Backdrop 1.28.0 and higher).

Issues
------

Bugs and Feature requests should be reported in the Issue Queue:
https://github.com/backdrop-contrib/font_awesome/issues

Current Maintainers
-------------------

- [Martin Price](https://github.com/yorkshire-pudding) - [System Horizons Ltd](https://www.systemhorizons.co.uk)
- Collaboration and co-maintainers welcome!

Credits
-------

- Ported to Backdrop CMS by Andy Martha (https://github.com/biolithic)
- Uses Dave Gandy's Font Awesome project (https://fontawesome.com)

License
-------

This project is GPL v2 software. See the LICENSE.txt file in this directory for
complete text.
