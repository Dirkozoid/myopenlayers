/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * Compass Behavior
 */
Drupal.openlayers.addBehavior('openlayers_behavior_compass', function (data, options) {
  var map = data.openlayers;

  var layer = new OpenLayers.Layer.Vector('Compass', {
    displayInLayerSwitcher:false,
    styleMap: new OpenLayers.StyleMap({
      "default": options.style
    })
  });

  layer.events.register('moveend', layer, function(event) {
    layer.removeAllFeatures();
    // TODO: Find a way to calculate the pixel automatically.
    var coords1 = map.getLonLatFromPixel(new OpenLayers.Pixel(map.size.w-90, 90));
    var coords2 = new OpenLayers.LonLat(0, 90.0).transform(
      new OpenLayers.Projection('EPSG:4326'),
      map.getProjectionObject()
    );
    var azimuth = 0;
    // TODO: Is this really necessary ?
    if (map.zoom > 0) {
      var x = coords2.lon - coords1.lon;
      var y = coords2.lat - coords1.lat;
      var rad = Math.acos( y / Math.sqrt(x*x+y*y) );
      var factor = x > 0 ? 1:-1;
      azimuth = Math.round(factor*rad*180/Math.PI);
    }
    var feature = new OpenLayers.Feature.Vector(
      new OpenLayers.Geometry.Point(coords.lon, coords.lat), {angle: azimuth}
    );
    layer.addFeatures(feature);
  });

  map.addLayer(layer);
});
