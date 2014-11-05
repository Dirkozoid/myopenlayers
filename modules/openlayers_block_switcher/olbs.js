(function ($) {
  Drupal.behaviors.olebs =  {
    attach: function(context, settings) {

      $(".form-item-overlays input[type='checkbox']").change(function(e) {
        var machine_name = $(this).closest('form').find("input[name='map']").val();
        var data = $('body').data('openlayers');
        for (map in data.objects.maps) {
          if (data.objects.maps[map].machine_name == machine_name) {
            var map = data.objects.maps[map];
            var layers = map.getLayers();
            layers.forEach(function(layer){
              if (layer.machine_name == $(e.srcElement).val()) {
                if ($(e.srcElement).prop('checked') == true) {
                  layer.setVisible(true);
                } else {
                  layer.setVisible(false);
                }
              }
            });
          }
        }
      });

    }
  };
})(jQuery);

