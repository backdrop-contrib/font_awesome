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

Installation
------------

- Install this module using the official Backdrop CMS instructions at
  https://backdropcms.org/guide/modules

- Visit the configuration page under Administration > Configuration > User
  Interface > Font Awesome (admin/config/user-interface/font-awesome) to enable
  the functionality for your site.

Issues
------

Bugs and Feature requests should be reported in the Issue Queue:
https://github.com/backdrop-contrib/font_awesome/issues

Current Maintainers
-------------------

- Peter Anderson (https://github.com/BWPanda)

Credits
-------

- Ported to Backdrop CMS by Andy Martha (https://github.com/biolithic)
- Uses Dave Gandy's Font Awesome project (https://fontawesome.com)

License
-------

This project is GPL v2 software. See the LICENSE.txt file in this directory for
complete text.

