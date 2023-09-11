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
      'v6.4' => t('<a href="https://fontawesome.com/how-to-use/on-the-web/referencing-icons/basic-use" target="_blank">v6.4</a>'),
      'local' => t('Local - add the location below.'),
      'theme' => t('Theme - add as part of the theme.'),
    ),
    '#default_value' => $config->get('fontawesome'),
  );

  $form['local_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Local path'),
    '#description' => t('Add the file path relative to the root of your Backdrop installation. You must ensure that the paths to font files referenced in the CSS are valid; these are normally at the end of the file.'),
    '#default_value' => config_get('font_awesome.settings', 'local_path'),
    '#size' => 60,
    '#maxlength' => 255,
    '#element_validate' => array('font_awesome_local_path_validate'),
    '#states' => array(
      'visible' => array(':input[name="fontawesome"]' => array('value' => 'local')),
      'required' => array(':input[name="fontawesome"]' => array('value' => 'local')),
    ),
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
        array(':input[name="fontawesome"]' => array('value' => 'v6.4')),
      ),
    ),
  );

  return system_settings_form($form);
}

/**
 * Helper function to validate that local path exists and is CSS file.
 */
function font_awesome_local_path_validate($element, &$form_state) {
  // We only apply validation to this field if the method is set to local so
  // check the value first.
  if ($form_state['values']['fontawesome'] == 'local') {
    // First check for a value and set an error if empty.
    if (empty($element['#value'])) {
      form_error($element, t("If 'Local' is selected, then 'Local path' is required."));
    }
    else {
      // Next check that the file exists and set an error if it doesn't.
      $local_path = BACKDROP_ROOT . '/' . $element['#value'];
      if (!file_exists($local_path)) {
        form_error($element, t("The entered path does not exist in the file system. Remember that the path should be relative to the Backdrop root."));
      }
      else {
        // Finally, check that the file is CSS and set an error if it isn't.
        $ext = pathinfo($local_path, PATHINFO_EXTENSION);
        if ($ext != 'css') {
          form_error($element, t("The path exists but is not a CSS file. Please enter a path to a CSS file."));
        }
      }
    }
  }
}
