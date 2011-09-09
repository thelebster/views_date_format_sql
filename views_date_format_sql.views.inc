<?php
/**
 * @file
 * This file contains the hook to assign this handler as default to node 'created' and 'changed' date fields.
 */

/**
 * Implements hook_views_data_alter().
 */
function views_date_format_sql_views_data_alter(&$data) {
//dpm($data);
  $data['node']['created']['field']['handler'] = 'views_date_format_sql_handler_field_date';
  $data['node']['changed']['field']['handler'] = 'views_date_format_sql_handler_field_date';
}
