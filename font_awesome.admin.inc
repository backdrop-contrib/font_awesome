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
  $form['pseudo'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use CSS pseudo-elements'),
    '#description' => t("Add icons to pseudo-elements using CSS (for when you can't edit the HTML/markup directly). See <a href=\"https://fontawesome.com/how-to-use/svg-with-js#pseudo-elements\" target=\"_blank\">fontawesome.com</a> for details."),
    '#default_value' => config_get('font_awesome.settings', 'pseudo'),
    '#states' => array(
      'visible' => array(
        ':input[name="fontawesome"]' => array('value' => 'v5'),
      ),
    ),
  );

  $form['#config'] = 'font_awesome.settings';
  return system_settings_form($form);
}

