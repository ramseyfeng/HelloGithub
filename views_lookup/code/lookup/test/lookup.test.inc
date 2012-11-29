<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

function lookup_test_form($form, &$form_state) {
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
    '#type' => 'textfield',
    '#title' => t('Continent'),
    '#size' => 12,
    '#default_value' => isset($form_state['values']['continent']) ? $form_state['values']['continent']
          : NULL,
  );
  return $form;
}

