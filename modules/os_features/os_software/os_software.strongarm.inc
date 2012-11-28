<?php
// $Id$

/**
 * @file
 * os_software.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function os_software_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  /* Edit this to true to make a default strongarm disabled initially */

  $strongarm->disabled = FALSE;
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_software_project';
  $strongarm->value = 0;
  $export['comment_anonymous_software_project'] = $strongarm;

  $strongarm = new stdClass();
  /* Edit this to true to make a default strongarm disabled initially */

  $strongarm->disabled = FALSE;
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_software_release';
  $strongarm->value = 0;
  $export['comment_anonymous_software_release'] = $strongarm;

  $strongarm = new stdClass();
  /* Edit this to true to make a default strongarm disabled initially */

  $strongarm->disabled = FALSE;
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_software_project';
  $strongarm->value = 1;
  $export['comment_default_mode_software_project'] = $strongarm;

  $strongarm = new stdClass();
  /* Edit this to true to make a default strongarm disabled initially */

  $strongarm->disabled = FALSE;
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_software_release';
  $strongarm->value = 1;
  $export['comment_default_mode_software_release'] = $strongarm;

  $strongarm = new stdClass();
  /* Edit this to true to make a default strongarm disabled initially */

  $strongarm->disabled = FALSE;
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_software_project';
  $strongarm->value = '50';
  $export['comment_default_per_page_software_project'] = $strongarm;

  $strongarm = new stdClass();
  /* Edit this to true to make a default strongarm disabled initially */

  $strongarm->disabled = FALSE;
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_software_release';
  $strongarm->value = '50';
  $export['comment_default_per_page_software_release'] = $strongarm;

  $strongarm = new stdClass();
  /* Edit this to true to make a default strongarm disabled initially */

  $strongarm->disabled = FALSE;
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_software_project';
  $strongarm->value = 1;
  $export['comment_form_location_software_project'] = $strongarm;

  $strongarm = new stdClass();
  /* Edit this to true to make a default strongarm disabled initially */

  $strongarm->disabled = FALSE;
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_software_release';
  $strongarm->value = 1;
  $export['comment_form_location_software_release'] = $strongarm;

  $strongarm = new stdClass();
  /* Edit this to true to make a default strongarm disabled initially */

  $strongarm->disabled = FALSE;
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_software_project';
  $strongarm->value = '1';
  $export['comment_preview_software_project'] = $strongarm;

  $strongarm = new stdClass();
  /* Edit this to true to make a default strongarm disabled initially */

  $strongarm->disabled = FALSE;
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_software_release';
  $strongarm->value = '1';
  $export['comment_preview_software_release'] = $strongarm;

  $strongarm = new stdClass();
  /* Edit this to true to make a default strongarm disabled initially */

  $strongarm->disabled = FALSE;
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_software_project';
  $strongarm->value = 0;
  $export['comment_software_project'] = $strongarm;

  $strongarm = new stdClass();
  /* Edit this to true to make a default strongarm disabled initially */

  $strongarm->disabled = FALSE;
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_software_release';
  $strongarm->value = 0;
  $export['comment_software_release'] = $strongarm;

  $strongarm = new stdClass();
  /* Edit this to true to make a default strongarm disabled initially */

  $strongarm->disabled = FALSE;
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_software_project';
  $strongarm->value = 1;
  $export['comment_subject_field_software_project'] = $strongarm;

  $strongarm = new stdClass();
  /* Edit this to true to make a default strongarm disabled initially */

  $strongarm->disabled = FALSE;
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_software_release';
  $strongarm->value = 1;
  $export['comment_subject_field_software_release'] = $strongarm;

  $strongarm = new stdClass();
  /* Edit this to true to make a default strongarm disabled initially */

  $strongarm->disabled = FALSE;
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_software_project';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_software_project'] = $strongarm;

  $strongarm = new stdClass();
  /* Edit this to true to make a default strongarm disabled initially */

  $strongarm->disabled = FALSE;
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_software_release';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_software_release'] = $strongarm;

  $strongarm = new stdClass();
  /* Edit this to true to make a default strongarm disabled initially */

  $strongarm->disabled = FALSE;
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_software_project';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_software_project'] = $strongarm;

  $strongarm = new stdClass();
  /* Edit this to true to make a default strongarm disabled initially */

  $strongarm->disabled = FALSE;
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_software_release';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_software_release'] = $strongarm;

  $strongarm = new stdClass();
  /* Edit this to true to make a default strongarm disabled initially */

  $strongarm->disabled = FALSE;
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_software_project';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_software_project'] = $strongarm;

  $strongarm = new stdClass();
  /* Edit this to true to make a default strongarm disabled initially */

  $strongarm->disabled = FALSE;
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_software_release';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_software_release'] = $strongarm;

  $strongarm = new stdClass();
  /* Edit this to true to make a default strongarm disabled initially */

  $strongarm->disabled = FALSE;
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_software_project';
  $strongarm->value = '0';
  $export['node_preview_software_project'] = $strongarm;

  $strongarm = new stdClass();
  /* Edit this to true to make a default strongarm disabled initially */

  $strongarm->disabled = FALSE;
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_software_release';
  $strongarm->value = '0';
  $export['node_preview_software_release'] = $strongarm;

  $strongarm = new stdClass();
  /* Edit this to true to make a default strongarm disabled initially */

  $strongarm->disabled = FALSE;
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_software_project';
  $strongarm->value = 0;
  $export['node_submitted_software_project'] = $strongarm;

  $strongarm = new stdClass();
  /* Edit this to true to make a default strongarm disabled initially */

  $strongarm->disabled = FALSE;
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_software_release';
  $strongarm->value = 0;
  $export['node_submitted_software_release'] = $strongarm;

  $strongarm = new stdClass();
  /* Edit this to true to make a default strongarm disabled initially */

  $strongarm->disabled = FALSE;
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_software_project_pattern';
  $strongarm->value = 'software/[node:title]';
  $export['pathauto_node_software_project_pattern'] = $strongarm;

  $strongarm = new stdClass();
  /* Edit this to true to make a default strongarm disabled initially */

  $strongarm->disabled = FALSE;
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_software_release_pattern';
  $strongarm->value = 'software/[node:field_software_project]/[node:field_software_version]';
  $export['pathauto_node_software_release_pattern'] = $strongarm;

  return $export;
}
