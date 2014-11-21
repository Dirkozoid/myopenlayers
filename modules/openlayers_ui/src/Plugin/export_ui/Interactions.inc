<?php
/**
 * @file
 * CTools Export UI plugin definition for interactions.
 */

/**
 * CTools Export UI plugin definition.
 */
function openlayers_ui_Interactions_ctools_export_ui() {
  return array(
    'schema' => 'openlayers_interactions',
    'access' => 'administer openlayers',
    'menu' => array(
      'menu prefix' => 'admin/structure/openlayers',
      'menu item' => 'interactions',
      'menu title' => 'Interactions',
      'menu description' => 'Administer OpenLayers interactions.',
    ),

    'handler' => array(
      'class' => '\\Drupal\\openlayers\\UI\\Interactions',
    ),

    'export' => array(
      'admin_title' => 'name',
      'admin_description' => 'description',
    ),

    'use wizard' => TRUE,
    'form info' => array(
      'order' => array(
        'start' => t('Administrative settings'),
        'type' => t('Interaction type'),
        'options' => t('Interaction type options'),
      ),
      'forms' => array(
        'start' => array(
          'form id' => 'openlayers_interaction_form_start',
        ),
        'type' => array(
          'form id' => 'openlayers_interaction_form_type',
        ),
        'options' => array(
          'form id' => 'openlayers_interaction_form_options',
        ),
      ),
      'wrapper' => 'openlayers_objects_ui_form_wrapper',
    ),

    'title singular' => t('interaction'),
    'title plural' => t('interactions'),
    'title singular proper' => t('OpenLayers interaction preset'),
    'title plural proper' => t('OpenLayers interaction presets'),

    'strings' => array(
      'confirmation' => array(
        'add' => array(
          'success' => t('Interaction saved.'),
        ),
        'delete' => array(
          'success' => t('Interaction was deleted.'),
        ),
      ),
    ),
  );
}

/**
 * Interaction base config form handler.
 */
function openlayers_interaction_form_start($form, &$form_state) {
  $class = new \Drupal\openlayers\UI\Interactions();
  $class->init($form_state['plugin']);
  $class->edit_form($form, $form_state);

  $maps = ctools_export_crud_load_all('openlayers_maps');
  $options = array('' => 'Dont attach');
  foreach ($maps as $machine_name => $data) {
    $map = openlayers_object_load('map', $machine_name);
    if (property_exists($map, 'disabled') && ($map->disabled == 1 || $map->disabled == TRUE)) {
      continue;
    }
    $options[$machine_name] = $data->name;
  }

  $form['attachToMap'] = array(
    '#type' => 'select',
    '#title' => 'Add this to a map ?',
    '#description' => 'Select the map to add this object to.',
    '#options' => $options,
  );

  return $form;
}

/**
 * Interaction base config form validation handler.
 */
function openlayers_interaction_form_start_validate($form, &$form_state) {
  $class = new \Drupal\openlayers\UI\Interactions();
  $class->init($form_state['plugin']);
  $class->edit_form_validate($form, $form_state);
}

/**
 * Interaction base config form submit handler.
 */
function openlayers_interaction_form_start_submit($form, &$form_state) {
  $class = new \Drupal\openlayers\UI\Interactions();
  $class->init($form_state['plugin']);
  $class->edit_form_submit($form, $form_state);

  if ($form_state['values']['attachToMap']) {
    $map = ctools_export_crud_load('openlayers_maps', $form_state['values']['attachToMap']);
    $map->options['interactions'][] = $form_state['item']->machine_name;
    ctools_export_crud_save('openlayers_maps', $map);
  }
}

/**
 * Interaction type config form handler.
 */
function openlayers_interaction_form_type($form, &$form_state) {
  $interactions = ctools_get_plugins('openlayers', 'Interaction');
  $options = array('' => t('<Choose the interaction type>'));
  foreach ($interactions as $class => $plugin) {
    $options[$plugin['handler']['class']] = $class;
  }

  $form['class'] = array(
    '#type' => 'select',
    '#title' => t('Interaction Type'),
    '#default_value' => isset($form_state['item']->class) ? $form_state['item']->class : '',
    '#description' => t('Select the type of interaction.'),
    '#options' => $options,
    '#required' => TRUE,
  );

  return $form;
}

/**
 * Interaction type config form submit handler.
 */
function openlayers_interaction_form_type_submit($form, &$form_state) {
  $form_state['item']->class = $form_state['values']['class'];
}

/**
 * Interaction options config form handler.
 */
function openlayers_interaction_form_options($form, &$form_state) {
  $interaction = openlayers_object_load('interaction', $form_state['item']);
  $interaction->optionsForm($form, $form_state);
  $form['options']['#tree'] = TRUE;

  return $form;
}

/**
 * Interaction options config form validation handler.
 */
function openlayers_interaction_form_options_validate($form, &$form_state) {
  $interaction = openlayers_object_load('interaction', $form_state['item']);
  $interaction->optionsFormValidate($form, $form_state);
}

/**
 * Interaction options config form submit handler.
 */
function openlayers_interaction_form_options_submit($form, &$form_state) {
  $form_state['item']->options = array_replace_recursive((array) $form_state['item']->options, $form_state['values']['options']);
  $interaction = openlayers_object_load('interaction', $form_state['item']);
  $interaction->optionsFormSubmit($form, $form_state);
}