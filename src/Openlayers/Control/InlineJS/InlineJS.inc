<?php
/**
 * @file
 * Control: Attribution.
 */

/**
 * Plugin definition.
 */
function openlayers_InlineJS_openlayers_control() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\Control\\InlineJS',
    ),
  );
}