<?php
/**
 * @file
 * Block-related functions.
 */

/**
 * Implements hook_preprocess_block().
 */
function bravery_preprocess_block(&$vars) {
  $module = $vars['block']->module;
  $module_class = drupal_html_class($module);
  $delta = $vars['block']->delta;
  $delta_class = drupal_html_class($delta);

  // Remove some default block classes.
  $vars['classes_array'] = array_values(array_diff($vars['classes_array'], array(
    'block-' . $module_class,
    'block-menu',
  )));

  // Add new default block classes.
  $vars['classes_array'][] = 'block--' . drupal_html_class($module_class);
  $vars['classes_array'][] = 'block--' . drupal_html_class($module_class) . '-' . drupal_html_class($delta_class);

  // Add default title & content classes.
  $vars['title_attributes_array']['class'][] = 'block__title';
  $vars['content_attributes_array']['class'][] = 'block__content';


}
