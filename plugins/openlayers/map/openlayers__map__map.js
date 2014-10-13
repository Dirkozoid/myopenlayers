Drupal.openlayers.openlayers__map__map = function(data) {
  var projection = ol.proj.get('EPSG:3857');

  var options = data.map.options;

  options.view = new ol.View({
    center: [options.view.center.lat, options.view.center.lon],
    rotation: options.view.rotation * (Math.PI / 180),
    zoom: options.view.zoom,
    // Todo: Find why these following options makes problems
    //minZoom: options.view.minZoom,
    //maxZoom: options.view.maxZoom,
    projection: projection,
    extent: projection.getExtent()
  });

  return new ol.Map(options);
};
