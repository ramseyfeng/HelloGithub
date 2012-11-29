<?php

/**
 * @file lookup.views.inc
 * Views for the lookup module
 */

/**
 * Implements hook_views_data()
 */
function lookup_views_data() {

  $data = array();

  lookup_views_data_load_city_list($data);
  return $data;
}

function lookup_views_pre_execute(&$view) {

// Please make sure this is place in the bottom
//  lookup_views_data_load_pre_execute($view);
}

/**
 * Implements hook_views_pre_render()
 * @param view $view
 */
function lookup_views_pre_render(&$view) {

}

/**
 *
 */
function lookup_views_post_render(&$view, &$output, &$cache) {

}

function lookup_views_data_load_city_list(&$data) {
  $data['city_list']['table']['group'] = t('City List');

  $data['city_list']['table']['base'] = array(
    'field' => 'id',
    'title' => t('City List'),
    'help' => t("City List"),
    'weight' => -10,
  );

// ID field.
  $data['city_list']['id'] = array(
    'title' => t('id'),
    'help' => t('Primary key of the table'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );

  $data['city_list']['name'] = array(
    'title' => t('Name'),
    'help' => t('Name'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['city_list']['country'] = array(
    'title' => t('Country'),
    'help' => t('Country'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['city_list']['code'] = array(
    'title' => t('City Code'),
    'help' => t('City Code'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['city_list']['continent'] = array(
    'title' => t('Continent'),
    'help' => t('Continent'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['city_list']['country_code'] = array(
    'title' => t('Country Code'),
    'help' => t('Country Code'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

}
