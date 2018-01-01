<?php
/**
 * @file
 * Administration page callbacks for the Font Awesome module.
 */

/**
 * Form constructor for the Font Awesome settings form.
 */
function font_awesome_admin_form($form, &$form_state) {
  $form['fontawesome'] = array(
    '#type' => 'radios',
    '#title' => t('Enable Font Awesome icons'),
    '#description' => t('Load the necessary FontAwesome CSS/JS. See the provided links for examples of how to actualy add icons.'),
    '#options' => array(
      '' => t('Disabled'),
      'v4' => t('v4 (<a href="http://fontawesome.io/examples/" target="_blank">fontawesome.io</a>)'),
      'v5' => t('v5 (<a href="https://fontawesome.com/how-to-use/svg-with-js" target="_blank">fontawesome.com</a>)'),
    ),
    '#default_value' => config_get('font_awesome.settings', 'fontawesome'),
  );

  $form['#config'] = 'font_awesome.settings';
  return system_settings_form($form);
}

