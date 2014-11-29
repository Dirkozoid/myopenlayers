<?php
/**
 * @file
 * Default layers.
 */

/**
 * Implements hook_default_layers().
 */
function openlayers_examples_default_layers() {
  $export = array();

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'openlayers_examples_layer_tile_mapbox_example1';
  $ol_layer->name = 'MapBox example 1';
  $ol_layer->description = 'Layer MapBox example 1';
  $ol_layer->factory_service = 'openlayers.layer.internal.Tile';
  $ol_layer->options = array(
    'source' => 'openlayers_examples_source_mapbox_example1',
  );
  $export['openlayers_examples_layer_tile_mapbox_example1'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'openlayers_examples_layer_tile_mapbox_example2';
  $ol_layer->name = 'MapBox example 2';
  $ol_layer->description = 'Layer MapBox example 2';
  $ol_layer->factory_service = 'openlayers.layer.internal.Tile';
  $ol_layer->options = array(
    'source' => 'openlayers_examples_source_mapbox_example2',
  );
  $export['openlayers_examples_layer_tile_mapbox_example2'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'openlayers_examples_layer_tile_mapbox_example3';
  $ol_layer->name = 'MapBox example 2';
  $ol_layer->description = 'Layer MapBox example 3';
  $ol_layer->factory_service = 'openlayers.layer.internal.Tile';
  $ol_layer->options = array(
    'source' => 'openlayers_examples_source_mapbox_example3',
  );
  $export['openlayers_examples_layer_tile_mapbox_example3'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'openlayers_examples_layer_vector_geojson_cities';
  $ol_layer->name = 'GeoJSON Cities';
  $ol_layer->description = 'GeoJSON Cities';
  $ol_layer->factory_service = 'openlayers.layer.internal.Vector';
  $ol_layer->options = array(
    'source' => 'openlayers_examples_source_geojson_file',
  );
  $export['openlayers_examples_layer_vector_geojson_cities'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'openlayers_examples_layer_vector_geojson_cities_heatmap';
  $ol_layer->name = 'GeoJSON Cities heatmap';
  $ol_layer->description = 'GeoJSON Cities Heatmap';
  $ol_layer->factory_service = 'openlayers.layer.internal.Heatmap';
  $ol_layer->options = array(
    'source' => 'openlayers_examples_source_geojson_file',
  );
  $export['openlayers_examples_layer_vector_geojson_cities_heatmap'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'openlayers_examples_layer_vector_kml_earthquakes';
  $ol_layer->name = 'Earthquakes 2012';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.layer.internal.Vector';
  $ol_layer->options = array(
    'source' => 'openlayers_examples_source_kml_earthquakes',
  );
  $export['openlayers_examples_layer_vector_kml_earthquakes'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'openlayers_examples_layer_vector_kml_earthquakes_heatmap';
  $ol_layer->name = 'Earthquakes 2012 Heatmap';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.layer.internal.Heatmap';
  $ol_layer->options = array(
    'source' => 'openlayers_examples_source_kml_earthquakes',
  );
  $export['openlayers_examples_layer_vector_kml_earthquakes_heatmap'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'openlayers_examples_layer_views_geojson';
  $ol_layer->name = 'Layer with source from Views GeoJSON';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.layer.internal.Vector';
  $ol_layer->options = array(
    'source' => 'views_geojson_openlayers_examples_geojson_feed_1',
  );
  $export['openlayers_examples_layer_views_geojson'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'openlayers_examples_layer_cluster_cities';
  $ol_layer->name = 'Layer cluster cities';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.layer.internal.Vector';
  $ol_layer->options = array(
    'source' => 'openlayers_examples_source_cluster',
  );
  $export['openlayers_examples_layer_cluster_cities'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'openlayers_examples_layer_views_geojson_popup';
  $ol_layer->name = 'Layer with source from Views GeoJSON for popup';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.layer.internal.Vector';
  $ol_layer->options = array(
    'source' => 'views_geojson_openlayers_examples_geojson_feed_2',
    'style' => 'openlayers_examples_style_blue_marker',
  );
  $export['openlayers_examples_layer_views_geojson_popup'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'openlayers_examples_layer_mapquest_sat';
  $ol_layer->name = 'MapQuest Satellite';
  $ol_layer->description = 'Layer MapQuest Satellite description';
  $ol_layer->factory_service = 'openlayers.layer.internal.Tile';
  $ol_layer->options = array(
    'source' => 'openlayers_examples_source_mapquest_sat',
  );
  $export['openlayers_examples_layer_mapquest_sat'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'openlayers_examples_layer_mapquest_hyb';
  $ol_layer->name = 'MapQuest Hybrid';
  $ol_layer->description = 'Layer MapQuest Hybrid description';
  $ol_layer->factory_service = 'openlayers.layer.internal.Tile';
  $ol_layer->options = array(
    'source' => 'openlayers_examples_source_mapquest_hyb',
  );
  $export['openlayers_examples_layer_mapquest_hyb'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'openlayers_examples_layer_mapbox_geography_class';
  $ol_layer->name = 'MapBox Geography Class';
  $ol_layer->description = 'Layer MapBox Geography Class description';
  $ol_layer->factory_service = 'openlayers.layer.internal.Tile';
  $ol_layer->options = array(
    'source' => 'openlayers_examples_source_mapbox_geography_class',
  );
  $export['openlayers_examples_layer_mapbox_geography_class'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'openlayers_examples_layer_mapbox_natural_earth_hypso_bathy';
  $ol_layer->name = 'MapBox Natural Earth Hypso Bathy';
  $ol_layer->description = 'Layer MapBox Natural Earth Hypso Bathy description';
  $ol_layer->factory_service = 'openlayers.layer.internal.Tile';
  $ol_layer->options = array(
    'source' => 'openlayers_examples_source_mapbox_natural_earth_hypso_bathy',
  );
  $export['openlayers_examples_layer_mapbox_natural_earth_hypso_bathy'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'openlayers_examples_layer_image';
  $ol_layer->name = 'Drupal logo layer image';
  $ol_layer->description = 'Layer image description';
  $ol_layer->factory_service = 'openlayers.layer.internal.Image';
  $ol_layer->options = array(
    'source' => 'openlayers_examples_source_imagestatic',
  );
  $export['openlayers_examples_layer_image'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'openlayers_examples_layer_openstreetmap';
  $ol_layer->name = 'OpenStreetMap';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.layer.internal.Tile';
  $ol_layer->options = array(
    'source' => 'openlayers_examples_source_openstreetmap',
  );
  $export['openlayers_examples_layer_openstreetmap'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'openlayers_examples_layer_opencyclemap';
  $ol_layer->name = 'OpenCycleMap';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.layer.internal.Tile';
  $ol_layer->options = array(
    'source' => 'openlayers_examples_source_opencyclemap',
  );
  $export['openlayers_examples_layer_opencyclemap'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'openlayers_examples_layer_tiledebug';
  $ol_layer->name = 'Tile Debug';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.layer.internal.Tile';
  $ol_layer->options = array(
    'source' => 'openlayers_examples_source_tiledebug',
  );
  $export['openlayers_examples_layer_tiledebug'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'openlayers_examples_layer_stamen1';
  $ol_layer->name = 'Stamen terrain labels';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.layer.internal.Tile';
  $ol_layer->options = array(
    'source' => 'openlayers_examples_source_stamen1',
  );
  $export['openlayers_examples_layer_stamen1'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'openlayers_examples_layer_stamen2';
  $ol_layer->name = 'Stamen watercolor';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.layer.internal.Tile';
  $ol_layer->options = array(
    'source' => 'openlayers_examples_source_stamen2',
  );
  $export['openlayers_examples_layer_stamen2'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'openlayers_examples_layer_stamen3';
  $ol_layer->name = 'Stamen toner';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.layer.internal.Tile';
  $ol_layer->options = array(
    'source' => 'openlayers_examples_source_stamen3',
  );
  $export['openlayers_examples_layer_stamen3'] = $ol_layer;

  $ol_layer = new stdClass();
  $ol_layer->disabled = FALSE; /* Edit this to true to make a default layer disabled initially */
  $ol_layer->api_version = 1;
  $ol_layer->machine_name = 'openlayers_examples_layer_esri';
  $ol_layer->name = 'ESRI';
  $ol_layer->description = '';
  $ol_layer->factory_service = 'openlayers.layer.internal.Tile';
  $ol_layer->options = array(
    'source' => 'openlayers_examples_source_esri',
  );
  $export['openlayers_examples_layer_esri'] = $ol_layer;

  return $export;
}