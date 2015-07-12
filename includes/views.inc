<?php
/**
 * @file
 * Views-related functions.
 */

/**
 * Implements hook_preprocess_views_view().
 */
function bravery_preprocess_views_view(&$vars) {
  // Modify classes to follow SMACSS naming convention.
  $tmp_classes_array = $vars['classes_array'];
  $vars['classes_array'] = preg_replace('/^view-(?!-)/', 'view--', $vars['classes_array']);

  // We add back the default Views classes
  // to make sure ajaxified views still work.
  $vars['classes_array'] = array_unique(array_merge($vars['classes_array'], $tmp_classes_array));
}