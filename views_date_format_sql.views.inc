<?php

/**
 * @file
 * This file contains the hook to assign this handler as default to date fields.
 */

/**
 * Implements hook_views_data_alter().
 */
function views_date_format_sql_views_data_alter(&$data) {
  // Loops through fields definitions looking for timestamp fields
  // and change the standard date handler with our own.
  foreach ($data as $module => &$table) {
    // Skip files because they have very specific fields.
    if ($table['table']['provider'] === 'file') {
      continue;
    }

    foreach ($table as $id => &$field) {
      if (empty($field['field']['id']) || empty($field['argument']['id'])) {
        continue;
      }
      if ($field['field']['id'] === 'field' && $field['argument']['id'] === 'date') {
        $field['field']['id'] = 'views_date_format_sql_field';
      }
    }
  }
}
