<?php
/**
 * @file
 * Node-related functions.
 */

/**
 * Implements hook_preprocess_node().
 */
function bravery_preprocess_node(&$vars) {


  // Remove some default node classes.
  $vars['classes_array'] = array_values(array_diff($vars['classes_array'], array(
    'node-' . $vars['node']->type,
  )));
  $vars['classes_array'] = array_values(array_diff($vars['classes_array'], array(
    'view-mode-' . $vars['view_mode'],
  )));
  $vars['classes_array'] = array_values(array_diff($vars['classes_array'], array(
    'node' . $vars['view_mode'],
  )));


  // Add default node attributes.
  $vars['classes_array'][] = 'node--' . drupal_html_class($vars['node']->type);
  $vars['attributes_array']['role'][] = 'article';

  // Change attributes for view modes.
  if (isset($vars['view_mode'])) {
    $vars['classes_array'][] = 'node--view-mode-' . drupal_html_class($vars['view_mode']);
  }
  

  // Add classes array to attributes array.
  $vars['attributes_array']['class'] = $vars['classes_array'];
}
