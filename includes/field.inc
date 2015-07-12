<?php
/**
 * @file
 * Field-related functions.
 */

/**
 * Implements hook_preprocess_field().
 */
function bravery_preprocess_field(&$vars) {

  $vars['classes_array'] = array_values(array_diff($vars['classes_array'], array(
    'field-name-' . $vars['field_name_css'],
    'field-type-' . $vars['field_type_css'],
    //'field-label-above',
    //'field-label-hidden',
    //'field-label-inline',
  )));

  // Add new default field classes.
  $vars['classes_array'][] = 'field--' . str_replace('field-', '', $vars['field_name_css']);

  // Uncomment the following if you want a class for the field type.
  //$vars['classes_array'][] = 'field--' . $vars['field_type_css'];
}


/**
 * Returns HTML for the Display Suite minimal field style.
 */
function bravery_field__minimal($vars) {
  $output = '';
  $config = $vars['ds-config'];
  $classes = isset($config['classes']) ? ' ' . $config['classes'] : '';
  $field_name_class = drupal_html_class($vars['element']['#field_name']);
  $field_label_class = '';

  // Add field label class.
  if ($vars['element']['#label_display'] == 'inline') {
    $field_label_class = ' field__label--inline';
  }
  else {
    $field_label_class .= ' field__label--above';
  }

  // Add a simple wrapper.
  $output .= '<div class="field field--' . str_replace('field-', '', $field_name_class) . $classes . '">';

  // Render the label.
  if (!$vars['label_hidden']) {
    $output .= '<div class="field__label' . $field_label_class . '">' . $vars['label'];
    if (!isset($config['lb-col'])) {
      $output .= ':&nbsp;';
    }
    $output .= '</div>';
  }

  // Render the items.
  foreach ($vars['items'] as $delta => $item) {
    $output .= drupal_render($item);
  }
  $output .="</div>";

  return $output;
}