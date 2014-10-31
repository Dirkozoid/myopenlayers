Drupal.openlayers.openlayers__component__popup = function(data) {
  var map = data.map;

  var container = jQuery('<div/>', {
    id: 'popup',
    'class': 'ol-popup'
  }).appendTo('body');
  var content = jQuery('<div/>', {
    id: 'popup-content'
  }).appendTo('#popup');
  var closer = jQuery('<a/>', {
    href: '#',
    id: 'popup-closer',
    'class': 'ol-popup-closer'
  }).appendTo('#popup');

  var container = document.getElementById('popup');
  var content = document.getElementById('popup-content');
  var closer = document.getElementById('popup-closer');

  /**
   * Add a click handler to hide the popup.
   * @return {boolean} Don't follow the href.
   */
  closer.onclick = function() {
    container.style.display = 'none';
    closer.blur();
    return false;
  };

  /**
   * Create an overlay to anchor the popup to the map.
   */
  var overlay = new ol.Overlay({
    element: container
  });

  map.addOverlay(overlay);

  map.on('click', function(evt) {
    var feature = map.forEachFeatureAtPixel(evt.pixel, function(feature, layer) {
      if (layer.machine_name == data.options.layer) {
        return feature;
      }
    });
    if (feature) {
      var hdms = ol.coordinate.toStringHDMS(ol.proj.transform(
        evt.coordinate, 'EPSG:3857', 'EPSG:4326'));

      overlay.setPosition(evt.coordinate);
      content.innerHTML = '<div class="ol-popup-name">' + feature.get('name') + '</div><div class="ol-popup-description">' + feature.get('description') + '</div>';
      container.style.display = 'block';
    }
  });
};
