<?php
/**
 * @file
 * Source: TileJson.
 */

/**
 * Plugin definition.
 */
function openlayers_tilejson_openlayers_source() {
  return array(
    'handler' => array(
      'class' => '\\Drupal\\openlayers\\source\\tilejson',
    ),
  );
}