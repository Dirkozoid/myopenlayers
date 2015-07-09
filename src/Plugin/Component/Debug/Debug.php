<?php
/**
 * @file
 * Component: Debug.
 */

namespace Drupal\openlayers\Plugin\Component\Debug;
use Drupal\Component\Annotation\Plugin;
use Drupal\openlayers\Types\Component;
use Drupal\openlayers\Types\ObjectInterface;

/**
 * Class Debug.
 *
 * @Plugin(
 *  id = "Debug"
 * )
 *
 */
class Debug extends Component {
  /**
   * @inheritDoc
   */
  public function attached() {
    $attached = parent::attached();
    $attached['libraries_load']['openlayers3'] = array('openlayers3', 'debug');
    return $attached;
  }

  /**
   * {@inheritdoc}
   */
  public function postBuild(array &$build, ObjectInterface $context = NULL) {
    $build['Debug'] = array(
      '#type' => 'fieldset',
      '#title' => 'Map debug',
      '#description' => 'Here\'s a quick view of all the objects in the map. You can also hit F12 to get information on the Javascript.',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE
    );

    foreach($context->getCollection()->getObjects() as $type => $objects) {
      $build['Debug'][$type] = array(
        '#type' => 'fieldset',
        '#title' => 'Type ' . $type . ':',
        '#collapsible' => TRUE,
        '#collapsed' => FALSE
      );

      foreach($objects as $object) {
        $build['Debug'][$type][$object->machine_name] = array(
          '#type' => 'fieldset',
          '#collapsible' => TRUE,
          '#collapsed' => TRUE,
          '#title' => $object->machine_name,
          'configuration' => $this->getInfo($object)
        );
      }
    }
  }

  /**
   * Return the markup for a table.
   *
   * @param $data
   *   The values of the table.
   * @return string
   */
  protected function toInfoArrayMarkup($data) {
    $rows = array();
    foreach($data as $name => $value) {
      if (is_array($value)) {
        $value = $this->toInfoArrayMarkup($value);
      } else {
        $value = htmlspecialchars($value);
      }

      $rows[] = array(
        'data' => array(
          '<code>' . $name . '</code>',
          '<code>' .  $value. '</code>'
        ),
        'no_striping' => TRUE
      );
    }

    $table = array(
      '#type' => 'table',
      '#rows' => $rows,
    );

    return drupal_render($table);
  }

  /**
   * Array containing basic information about an OL Object.
   *
   * @param \Drupal\openlayers\Types\ObjectInterface $object
   * @return array
   */
  protected function getInfo(ObjectInterface $object) {
    $js = $object->getJS();

    $info = array(
      'mn' => array(
        '#type' => 'item',
        '#title' => 'Machine name:',
        '#markup' => $object->machine_name
      ),
      'fs' => array(
        '#type' => 'item',
        '#title' => 'Factory service:',
        '#markup' => $object->factory_service
      )
    );

    if (isset($js['opt'])) {
      $info['opt'] = array(
        '#type' => 'item',
        '#title' => 'Options:',
        'options' => array(
          '#markup' => $this->toInfoArrayMarkup($js['opt']),
        )
      );
    }

    return $info;
  }
}
