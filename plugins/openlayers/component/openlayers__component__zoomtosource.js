Drupal.openlayers.openlayers__component__zoomtosource = function(data) {
  var map = data.map;

  map.getLayers().forEach(function(layer) {
    var source = layer.getSource();
    if (source.name === data.options.source) {
      source.on('change', function() {
        if (data.options.enableAnimations == 1) {
          var pan = ol.animation.pan({duration: data.options.animations.pan, source: map.getView().getCenter()});
          var zoom = ol.animation.zoom({duration: data.options.animations.zoom, resolution: map.getView().getResolution()});
          map.beforeRender(pan, zoom);
        }
        var dataExtent = source.getExtent();
        map.getView().fitExtent(dataExtent, map.getSize());
      }, source);
    }
  });
};
