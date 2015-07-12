<?php
/**
 * @file
 * Panels-related functions.
 */

/**
 * Implements hook_preprocess_panels_pane().
 */


function bravery_preprocess_panels_pane(&$vars) {

  $type = $vars['pane']->type;
  $type_class = drupal_html_class($type);
  $subtype = $vars['pane']->subtype;
  $subtype_class = drupal_html_class($subtype);
  $layout = $vars['display']->layout;

  // Add theme hook suggestions based on pane type and layout.
  $vars['theme_hook_suggestions'][] = 'panels_pane__' . $layout;
  $vars['theme_hook_suggestions'][] = 'panels_pane__' . $subtype;
  $vars['theme_hook_suggestions'][] = 'panels_pane__' . $layout . '__' . $subtype;

  // Remove default pane classes.
  $vars['classes_array'] = array_values(array_diff($vars['classes_array'], array(
    'panel-pane',
    'pane-' . $type_class,
    'pane-' . $subtype_class,
  )));

  // Add new default pane classes.
  $vars['classes_array'][] = 'pane';
  $vars['classes_array'][] = 'pane--' . $subtype_class;

  // Remove default title class.
  $vars['title_attributes_array']['class'] = array_values(array_diff($vars['title_attributes_array']['class'], array(
    'pane-title',
  )));

  // Add title and content classes.
  $vars['title_attributes_array']['class'][] = 'pane__title';
  $vars['content_attributes_array']['class'][] = 'pane__content';

  // Add default pane content class if wanted.
  //$vars['content_attributes_array']['class'][] = 'pane-content';

  // Add classes to the attributes array.
  if ($vars['classes_array']) {
    $vars['attributes_array']['class'] = $vars['classes_array'];
  }

  // Add id to the attributes array.
  if (isset($vars['pane']->css['css_id'])) {
    $vars['attributes_array']['id'] = $vars['pane']->css['css_id'];
  }
}