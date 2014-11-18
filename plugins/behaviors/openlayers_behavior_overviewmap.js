/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * Overview Map Behavior. Implements the Overview Control Map.
 */
Drupal.openlayers.addBehavior('openlayers_behavior_overviewmap', function (data, options) {
    Drupal.openlayers.addControl(data.openlayers, 'OverviewMap', options);
});
