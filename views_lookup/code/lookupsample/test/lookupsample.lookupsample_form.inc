<?php

/*
 * Lookup Sample Form
 */
function lookup_sample_form($form, &$form_state) {

  $js_options = array(
    'scope' => 'footer',
    'preprocess' => TRUE,
  );

  $lookupsample_path = drupal_get_path('module', 'lookupsample');
  drupal_add_js($lookupsample_path . '/test/test.js', $js_options);

  $form['city'] = array(
    '#lookup' => TRUE,
    '#type' => 'textfield',
    '#title' => t('City'),
    '#size' => 12,
    '#default_value' => isset($form_state['values']['city']) ? $form_state['values']['city']
          : NULL,
  );

  $form['country'] = array(
    '#type' => 'textfield',
    '#title' => t('Country'),
    '#size' => 12,
    '#default_value' => isset($form_state['values']['country']) ? $form_state['values']['country']
          : NULL,
  );

  $form['continent'] = array(
    '#lookup' => TRUE,
    '#type' => 'textfield',
    '#title' => t('Continent'),
    '#size' => 12,
    '#default_value' => isset($form_state['values']['continent']) ? $form_state['values']['continent']
          : NULL,
  );
  return $form;
}
