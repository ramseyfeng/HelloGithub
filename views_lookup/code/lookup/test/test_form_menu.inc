<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
function lookup_test_form_menu(&$items) {
  $items['lookup/test/testDrupal'] = array(
    'title' => t('Test Form'),
    'page callback' => 'drupal_get_form',
    'page arguments' => array('lookup_test_form'),
    'access callback' => TRUE,
    'menu_name' => 'main-menu',
    'file' => 'test/lookup.test.inc',
  );
}
