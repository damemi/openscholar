<?php
/**
 * @file
 * os_booklets.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function os_booklets_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'booklets_booklets';
  $context->description = '';
  $context->tag = 'OS features';
  $context->conditions = array(
    'menu' => array(
      'values' => array(
        'documents' => 'documents',
      ),
    ),
    'node' => array(
      'values' => array(
        'book' => 'book',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'documents' => 'documents',
        'book/*' => 'book/*',
      ),
    ),
    'views' => array(
      'values' => array(
        'os_booklets' => 'os_booklets',
        'os_booklets:page' => 'os_booklets:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'book-navigation' => array(
          'module' => 'book',
          'delta' => 'navigation',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-os_booklets-block' => array(
          'module' => 'views',
          'delta' => 'os_booklets-block',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'boxes-os_addthis' => array(
          'module' => 'boxes',
          'delta' => 'os_addthis',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
      ),
    ),
    'menu' => 'documents',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('OS features');
  $export['booklets_booklets'] = $context;

  return $export;
}