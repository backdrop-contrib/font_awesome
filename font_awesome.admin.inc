<?php

/**
 * @file
 * Contains the administration pages for Font Awesome Icons.
 *
 */

function font_awesome_admin_settings($form, &$form_state) {

  $form['font_awesome_1'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use Font Awesome Icons from CDN in your website'),
    '#description' => t('http://fontawesome.io'),
    '#default_value' => config_get('font_awesome.settings', 'font_awesome_1'),
  );

  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );
  return $form;
}

/**
 * Submit handler for module_settings_form().
 */
function font_awesome_admin_settings_submit($form, &$form_state) {
$config = config('font_awesome.settings');
foreach ($form_state['values'] as $key => $value)
{
$config->set($key, $value);
}

$config->save();
backdrop_set_message(t('The configuration options have been saved.'));
}
?>
