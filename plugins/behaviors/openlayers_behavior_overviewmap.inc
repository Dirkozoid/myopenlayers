<?php
/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Overview Map Behavior.
 */
class openlayers_behavior_overviewmap extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'projection' => array(),
      'maxExtent' => array(),
      'maximized' => 'true',
      'minRectSize' => 0,
      'minRatio' => 16,
      'maxRatio' => 64,
      'mapOptions' => array(
        'numZoomLevels' => 1,
        'zoom' => 3,
      ),
      'size' => array(
        'h' => 100,
        'w' => 150,
      ),
    );
  }

  function js_dependency() {
    return array('OpenLayers.Control.OverviewMap');
  }

  function options_form($defaults = array()) {
    $form = array();

    // Projections select.
    $projections = openlayers_ui_get_projection_options();
    $options = array_keys($projections);
    $options = array_combine($options, $options);
    $form['projection'] = array(
      '#title' => t('Projections'),
      '#type' => 'select',
      '#options' => $options,
      '#description' => t('Select the projection of the overview map.'),
      '#default_value' => isset($defaults['projection']) ? $defaults['projection'] : array(),
    );

    // @TODO: add numeric option form elements.
    return $form;
  }


  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers_overviewmap') . '/plugins/behaviors/openlayers_behavior_overviewmap.js');
    return $this->options;
  }
}
