<?php

/**
 * Returns HTML for status and/or error messages, grouped by type.
 */
function bravery_status_messages($variables) {
  $display = $variables['display'];
  $output = '';

  $status_heading = array(
    'status' => t('Status'),
    'error' => t('Error'),
    'warning' => t('Warning'),
  );
  foreach (drupal_get_messages($display) as $type => $messages) {
    $output .= "<div class=\"messages--$type messages $type\">\n";
    if (!empty($status_heading[$type])) {
      $output .= '<h2 class="message__title">' . $status_heading[$type] . "</h2>\n";
    }
    $output .= '<div class="message__content">';
    if (count($messages) > 1) {
      $output .= " <ul class=\"messages__list\">\n";
      foreach ($messages as $message) {
        $output .= '  <li class=\"messages__item\">' . $message . "</li>\n";
      }
      $output .= " </ul>\n";
    }
    else {
      $output .= $messages[0];
    }

    $output .= "</div>";

    $output .= "</div>\n";
  }
  return $output;
}