<?php
/**
 * @file
 * Style: JS.
 */

/**
 * Plugin definition.
 */
function openlayers_InlineJS_openlayers_style() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Style\\InlineJS',
    ),
  );
}