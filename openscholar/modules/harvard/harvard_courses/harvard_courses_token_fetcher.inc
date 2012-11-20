<?php
/**
 * @file
 *
 * Provides the Class for Feeds Token Fetcher.
 */

/**
 * Base class for the token fetcher.
 */
class HarwardFetcher extends FeedsFetcher {

  public function fetch(FeedsSource $source) {
    $wrapper = entity_metadata_wrapper('node', $source->feed_nid);
    $nids = haravard_courses_sites_nid_by_import_type($wrapper->field_import_type->value());

    if (empty($nids)) {
      drupal_set_message(t('There were no sites for this import.'));
      return FALSE;
    }

    // Define the query parameter and the field that holds the query values.
    if ($wrapper->field_import_type->value() == 'cat_num') {
      $field = 'field_catalog_number';
      $url_param = 'q=';
    }
    else {
      $field = 'field_department_id';
      $url_param = 'fq_dept_area_category=dept_area_category:';
    }

    // Loop over the nodes and build the query parameter value.
    $param_values = array();
    foreach ($nids as $nid) {
      if ($field == 'field_catalog_number') {
        $import_wrapper = entity_metadata_wrapper('node', $nid);
        foreach ($import_wrapper->{$field}->value() as $import_values) {
          $import_value[] = $import_values;
        }
      }
      else {
        // @TODO: importing by department id.
      }
    }

    // When importing a field catalog number we can use the OR operator.
    if ($field == 'field_catalog_number') {
      $url = $wrapper->field_base_url->value() . '?' . $url_param . '"' . implode(" OR ", $import_value) . '"';
      return $this->importFromUrl($url);
    }
  }

  /**
   * Private function for import from a given URL.
   */
  private function importFromUrl($url) {
    // Build the URL for import and verify for response code 200 from the URL.
    $result = drupal_http_request($url);
    if ($result->code == 200) {
      return new FeedsFetcherResult($result->data);
    }
    else {
      // oops... error!
      drupal_set_message(t('Unable to get feeds from : ' . $url));
      return FALSE;
    }
  }
}