<?php
/**
 * @file
 * Administration page callbacks for the Font Awesome module.
 */

/**
 * Form constructor for the Font Awesome settings form.
 */
function font_awesome_admin_form($form, &$form_state) {
  $form['enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use Font Awesome icons in your website'),
    '#description' => t('This will load the necessary CSS for you to start adding icons to your site. See <a href="http://fontawesome.io/examples/">http://fontawesome.io/examples/</a> for examples.'),
    '#default_value' => config_get('font_awesome.settings', 'enabled'),
  );

  $form['#config'] = 'font_awesome.settings';
  return system_settings_form($form);
}

