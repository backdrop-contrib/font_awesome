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
    '#description' => t('Load the necessary FontAwesome CSS. See the provided links for examples of how to actually add icons.'),
    '#options' => array(
      '' => t('Disabled'),
      'v4' => t('<a href="https://fontawesome.com/v4.7.0/examples/" target="_blank">v4</a>'),
      'v5' => t('<a href="https://fontawesome.com/how-to-use/on-the-web/referencing-icons/basic-use" target="_blank">v5</a>'),
    ),
    '#default_value' => config_get('font_awesome.settings', 'fontawesome'),
  );

  $form['#config'] = 'font_awesome.settings';
  return system_settings_form($form);
}

