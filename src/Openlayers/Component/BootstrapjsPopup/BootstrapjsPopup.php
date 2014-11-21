<?php
/**
 * @file
 * Component: Bootstap JS Popup.
 */

namespace Drupal\openlayers\Component;
use Drupal\openlayers\Types\Component;

/**
 * Class BootstrapjsPopup.
 */
class BootstrapjsPopup extends Component {

  /**
   * {@inheritdoc}
   */
  public function attached(\Drupal\openlayers\Types\ObjectInterface $context) {
    $attached = parent::attached($context);
    $attached['libraries_load'][] = array('bootstrapjs');
    return $attached;
  }

  /**
   * {@inheritdoc}
   */
  public function dependencies() {
    return array(
      'bootstrapjs',
    );
  }

}