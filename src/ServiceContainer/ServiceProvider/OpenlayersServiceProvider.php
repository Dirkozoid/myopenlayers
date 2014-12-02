<?php
/**
 * @file
 * Contains \Drupal\openlayers\RenderCache\ServiceProvider\RenderCacheServiceProvider
 */

namespace Drupal\openlayers\ServiceContainer\ServiceProvider;

use Drupal\service_container\ServiceContainer\ServiceProvider\ServiceContainerServiceProvider;

/**
 * Provides openlayers service definitions.
 */
class OpenlayersServiceProvider extends ServiceContainerServiceProvider {

  /**
   * {@inheritdoc}
   */
  public function getContainerDefinition() {
    $services = array();
    $parameters = array();

    $services['service_container'] = array(
      'class' => '\Drupal\service_container\DependencyInjection\Container',
    );

    $services['openlayers.manager'] = array(
      'class' => '\Drupal\service_container\Plugin\ContainerAwarePluginManager',
      'arguments' => array(
        'openlayers.manager.internal.'
      ),
      'calls' => array(
        array(
          'setContainer',
          array(
            '@service_container'
          )
        )
      )
    );

    $services['openlayers.manager.internal.error'] = array(
      'class' => '\Drupal\openlayers\Types\Error',
    );

    $services['openlayers.manager.internal.collection'] = array(
      'class' => '\Drupal\openlayers\Types\Collection'
    );


    foreach(openlayers_ctools_plugin_type() as $plugin => $data) {
      $plugin = drupal_strtolower($plugin);
      $services['openlayers.' . $plugin] = array();
      $parameters['service_container.plugin_managers']['ctools']['openlayers.' . $plugin] = array(
        'owner' => 'openlayers',
        'type' => drupal_ucfirst($plugin)
      );
    }

    return array(
      'parameters' => $parameters,
      'services' => $services,
    );
  }
}
