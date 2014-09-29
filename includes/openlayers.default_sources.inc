<?php

function openlayers_default_sources() {
  $export = array();

  $source = new stdClass;
  $source->api_version = 1;
  $source->machine_name = 'source_osm';
  $source->name = 'OpenStreetMap';
  $source->description = 'Source OpenStreetMap description';
  $source->class = 'openlayers_source_osm';
  $source->options = array();
  $export['source_osm'] = $source;

  $source = new stdClass();
  $source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $source->api_version = 1;
  $source->machine_name = 'source_osm_opencyclemap';
  $source->name = 'OpenCycleMap';
  $source->description = 'Source OpenCycleMap description';
  $source->class = 'openlayers_source_osm';
  $source->options = array(
    'url' => 'http://{a-c}.tile.opencyclemap.org/cycle/{z}/{x}/{y}.png',
  );
  $export['source_osm_opencyclemap'] = $source;

  $source = new stdClass;
  $source->api_version = 1;
  $source->machine_name = 'source_bingmaps';
  $source->name = 'Bing Maps';
  $source->description = 'Source Bingmaps description';
  $source->class = 'openlayers_source_bingmaps';
  $source->options = array();
  $export['source_bingmaps'] = $source;

  $source = new stdClass();
  $source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $source->api_version = 1;
  $source->machine_name = 'source_mapquest_sat';
  $source->name = 'MapQuest Satellite';
  $source->description = 'Source MapQuest Satellite description';
  $source->class = 'openlayers_source_mapquest';
  $source->options = array(
    'layer' => 'sat',
  );
  $export['source_mapquest_sat'] = $source;

  $source = new stdClass();
  $source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $source->api_version = 1;
  $source->machine_name = 'source_mapquest_osm';
  $source->name = 'MapQuest OpenStreetMap';
  $source->description = 'Source MapQuest OpenStreetMap description';
  $source->class = 'openlayers_source_mapquest';
  $source->options = array(
    'layer' => 'osm',
  );
  $export['source_mapquest_osm'] = $source;

  $source = new stdClass();
  $source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $source->api_version = 1;
  $source->machine_name = 'source_mapquest_hyb';
  $source->name = 'MapQuest Hybrid';
  $source->description = 'Source MapQuest Hybrid';
  $source->class = 'openlayers_source_mapquest';
  $source->options = array(
    'layer' => 'hyb',
  );
  $export['source_mapquest_hyb'] = $source;

  $source = new stdClass();
  $source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $source->api_version = 1;
  $source->machine_name = 'source_mapbox_geography_class';
  $source->name = 'MapBox Geography Class';
  $source->description = 'Source MapBox Geography Class description';
  $source->class = 'openlayers_source_tilejson';
  $source->options = array(
    'url' => 'http://api.tiles.mapbox.com/v3/mapbox.geography-class.jsonp',
  );
  $export['source_mapbox_geography_class'] = $source;

  $source = new stdClass();
  $source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $source->api_version = 1;
  $source->machine_name = 'source_mapbox_natural_earth_hypso_bathy';
  $source->name = 'MapBox Natural Earth Hypso Bathy';
  $source->description = 'Source MapBox Natural Hearth Hypso Bathy description';
  $source->class = 'openlayers_source_tilejson';
  $source->options = array(
    'url' => 'http://api.tiles.mapbox.com/v3/mapbox.natural-earth-hypso-bathy.jsonp',
  );
  $export['source_mapbox_natural_earth_hypso_bathy'] = $source;

  $source = new stdClass();
  $source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $source->api_version = 1;
  $source->machine_name = 'source_imagestatic';
  $source->name = 'Image Static';
  $source->description = 'Source Image Static description';
  $source->class = 'openlayers_source_imagestatic';
  $source->options = array(
    'url' => url(drupal_get_path('module', 'openlayers') . '/images/druplicon.png', array('absolute' => TRUE)),
  );
  $export['source_imagestatic'] = $source;

  $source = new stdClass();
  $source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $source->api_version = 1;
  $source->machine_name = 'source_tiledebug';
  $source->name = 'Tile debug';
  $source->description = 'A pseudo tile source, which does not fetch tiles from a server, but renders a grid outline for the tile grid/projection along with the coordinates for each tile.';
  $source->class = 'openlayers_source_tiledebug';
  $source->options = array(
    'maxZoom' => 22
  );
  $export['source_tiledebug'] = $source;

  $source = new stdClass();
  $source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $source->api_version = 1;
  $source->machine_name = 'source_stamen1';
  $source->name = 'Stamen terrain labels';
  $source->description = '';
  $source->class = 'openlayers_source_stamen';
  $source->options = array(
    'layer' => 'terrain-labels'
  );
  $export['source_stamen1'] = $source;

  $source = new stdClass();
  $source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $source->api_version = 1;
  $source->machine_name = 'source_stamen2';
  $source->name = 'Stamen watercolor';
  $source->description = '';
  $source->class = 'openlayers_source_stamen';
  $source->options = array(
    'layer' => 'watercolor'
  );
  $export['source_stamen2'] = $source;

  $source = new stdClass();
  $source->disabled = FALSE; /* Edit this to true to make a default source disabled initially */
  $source->api_version = 1;
  $source->machine_name = 'source_esri';
  $source->name = 'ESRI';
  $source->description = '';
  $source->class = 'openlayers_source_xyz';
  $source->options = array(
    'url' => 'http://server.arcgisonline.com/ArcGIS/rest/services/World_Topo_Map/MapServer/tile/{z}/{y}/{x}'
  );
  $export['source_esri'] = $source;

  return $export;
}