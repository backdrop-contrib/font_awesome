<?php
/**
 * @file
 * Administration page callbacks for the Font Awesome module.
 */

/**
 * Form constructor for the Font Awesome settings form.
 */
function font_awesome_admin_form($form, &$form_state) {
  $form['#config'] = 'font_awesome.settings';
  $config = config('font_awesome.settings');

  $form['fontawesome'] = array(
    '#type' => 'radios',
    '#title' => t('Enable Font Awesome icons'),
    '#description' => t('Load the necessary FontAwesome CSS. See the provided links for examples of how to actually add icons.'),
    '#options' => array(
      '' => t('Disabled'),
      'v4' => t('<a href="https://fontawesome.com/v4.7.0/examples/" target="_blank">v4</a>'),
      'v5' => t('<a href="https://fontawesome.com/how-to-use/on-the-web/referencing-icons/basic-use" target="_blank">v5.2</a>'),
      'v5.15' => t('<a href="https://fontawesome.com/how-to-use/on-the-web/referencing-icons/basic-use" target="_blank">v5.15</a>'),
    ),
    '#default_value' => $config->get('fontawesome'),
  );

  $form['v4_shims'] = array(
    '#type' => 'checkbox',
    '#title' => t('Include v4 shims'),
    '#description' => t('Checking this box will allow you to use FontAwesome v4 icon names with FontAwesome v5. <a href="https://fontawesome.com/v5.15/how-to-use/graphql-api/objects/shim" target="_blank">Details here.</a>'),
    '#default_value' => $config->get('v4_shims'),
    '#states' => array(
      'visible' => array(
        array(':input[name="fontawesome"]' => array('value' => 'v5')),
        array(':input[name="fontawesome"]' => array('value' => 'v5.15')),
      ),
    ),
  );

  return system_settings_form($form);
}
